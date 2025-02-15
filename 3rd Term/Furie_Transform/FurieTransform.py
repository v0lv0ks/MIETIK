import numpy as np
import librosa
import librosa.display
import matplotlib.pyplot as plt
import sounddevice as sd

# Константы
NOTE_NAMES = ["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"]

# Преобразование частоты в музыкальную ноту
def frequency_to_note(frequency):
    if frequency == 0:
        return "N/A"
    A4 = 440  # Частота ноты Ля 4
    semitones_from_A4 = 12 * np.log2(frequency / A4)
    note_index = int(round(semitones_from_A4)) % 12
    octave = int(np.floor((np.log2(frequency / A4) + 4)))
    return f"{NOTE_NAMES[note_index]}{octave}"

import os

# Функция для сохранения графиков в указанную папку
def save_plot(fig, filename):
    # Указываем путь для сохранения
    save_path = os.path.join("C:/Users/вольвокс/Downloads", filename)
    fig.savefig(save_path)
    print(f"Сохранено: {save_path}")


# Основной анализ аудио
def analyze_audio(file_path):
    signal, sr = librosa.load(file_path, sr=None)

    # График исходного сигнала
    fig_signal = plt.figure(figsize=(12, 6))
    time_axis = np.linspace(0, len(signal) / sr, len(signal))
    plt.plot(time_axis, signal, label="Аудиосигнал")
    plt.title("Исходный сигнал")
    plt.xlabel("Время (секунды)")
    plt.ylabel("Амплитуда")
    plt.grid()
    plt.legend()
    save_plot(fig_signal, "audio_signal.png")
    plt.show()

    # Преобразование Фурье
    fft_values = np.fft.fft(signal)
    frequencies = np.fft.fftfreq(len(signal), d=1 / sr)
    amplitudes = np.abs(fft_values)

    # Доминирующие частоты
    peak_indices = np.argsort(amplitudes[:len(amplitudes)//2])[-5:]
    dominant_frequencies = frequencies[peak_indices]

    print("Доминирующие частоты и ноты:")
    for freq in dominant_frequencies:
        note = frequency_to_note(freq)
        print(f"{freq:.2f} Гц — {note}")

    # Визуализация спектра
    fig1 = plt.figure(figsize=(12, 6))
    plt.plot(frequencies[:len(frequencies)//2], amplitudes[:len(amplitudes)//2])
    plt.title("Амплитудный спектр")
    plt.xlabel("Частота (Гц)")
    plt.ylabel("Амплитуда")
    plt.grid()
    save_plot(fig1, "spectrum.png")
    plt.show()

    # Построение спектрограммы
    fig2 = plt.figure(figsize=(12, 6))
    S = librosa.feature.melspectrogram(y=signal, sr=sr, n_mels=128, fmax=sr / 2)
    S_dB = librosa.power_to_db(S, ref=np.max)
    librosa.display.specshow(S_dB, sr=sr, x_axis='time', y_axis='mel', fmax=sr / 2)
    plt.colorbar(format='%+2.0f dB')
    plt.title("Спектрограмма")
    save_plot(fig2, "spectrogram.png")
    plt.show()

# Реальный анализ звука через микрофон
def analyze_real_time(duration=5, sr=44100):
    print("Запись аудио через микрофон...")
    audio = sd.rec(int(duration * sr), samplerate=sr, channels=1, dtype='float32')
    sd.wait()  # Ожидание завершения записи
    signal = audio.flatten()

    # Построение графика исходного сигнала
    fig_signal = plt.figure(figsize=(12, 6))
    time_axis = np.linspace(0, duration, len(signal))
    plt.plot(time_axis, signal, label="Аудиосигнал")
    plt.title("Исходный сигнал (микрофон)")
    plt.xlabel("Время (секунды)")
    plt.ylabel("Амплитуда")
    plt.grid()
    plt.legend()
    save_plot(fig_signal, "microphone_signal.png")
    plt.show()

    # Преобразование Фурье
    fft_values = np.fft.fft(signal)
    frequencies = np.fft.fftfreq(len(signal), d=1 / sr)
    amplitudes = np.abs(fft_values)

    # Доминирующие частоты
    peak_indices = np.argsort(amplitudes[:len(amplitudes)//2])[-5:]
    dominant_frequencies = frequencies[peak_indices]

    print("Доминирующие частоты и ноты:")
    for freq in dominant_frequencies:
        note = frequency_to_note(freq)
        print(f"{freq:.2f} Гц — {note}")

    # Визуализация спектра
    fig1 = plt.figure(figsize=(12, 6))
    plt.plot(frequencies[:len(frequencies)//2], amplitudes[:len(amplitudes)//2])
    plt.title("Амплитудный спектр (микрофон)")
    plt.xlabel("Частота (Гц)")
    plt.ylabel("Амплитуда")
    plt.grid()
    save_plot(fig1, "microphone_spectrum.png")
    plt.show()

    # Построение спектрограммы
    fig2 = plt.figure(figsize=(12, 6))
    S = librosa.feature.melspectrogram(y=signal, sr=sr, n_mels=128, fmax=sr / 2)
    S_dB = librosa.power_to_db(S, ref=np.max)
    librosa.display.specshow(S_dB, sr=sr, x_axis='time', y_axis='mel', fmax=sr / 2)
    plt.colorbar(format='%+2.0f dB')
    plt.title("Спектрограмма (микрофон)")
    save_plot(fig2, "microphone_spectrogram.png")
    plt.show()

# Главная функция
if __name__ == "__main__":
    print("Выберите режим работы:")
    print("1. Анализ аудиофайла")
    print("2. Анализ реального времени через микрофон")
    choice = input("Ваш выбор (1/2): ")

    if choice == "1":
        file_path = input("Введите путь к аудиофайлу (.wav): ")
        if file_path and file_path.endswith(".wav"):
            analyze_audio(file_path)
        else:
            print("Неверный формат файла. Укажите путь к .wav файлу.")
    elif choice == "2":
        duration = int(input("Введите длительность записи (в секундах): "))
        analyze_real_time(duration=duration)
    else:
        print("Неверный выбор.")
