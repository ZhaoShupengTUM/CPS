%Design the low pass filter
% For data sampled at 1000 Hz, design a low-pass filter with less
% than 3 dB of ripple in the passband, defined from 0 to 40 Hz, and
% at least 40 dB of attenuation in the stopband, defined from 200 Hz
% to the Nyquist frequency. The filter order should be less than 6.
Wp = 40/500;
Ws = 200/500;
[n,Wn] = buttord(Wp,Ws,3,40)
[b,a] = butter(n,Wn);
figure(1);
freqz(b,a,512,1000)
title('n=3 Butterworth Lowpass Filter')

%Sample t at f_s = 1000Hz for 0.3sec
f_s = 1000;
t = 0:1/f_s:0.3;

%Generation of sample sin wave
phase_sin = 0;
amplitude_sin = 5;
f_sin = 20; %20Hz base signal
omega_sin = 2*pi*f_sin;
signal_sin = amplitude_sin*sin(omega_sin*t + phase_sin);

%Generation of sin wave noise signal
phase_noise = 0;
amplitude_noise = 5;
f_noise = 400;  %400Hz noise signal
omega_noise = 2*pi*f_noise;
signal_noise = amplitude_noise*sin(omega_noise*t + phase_noise);

%Combination sin signal with noise
signal_combined = signal_sin + signal_noise;

%Draw the signal
figure(2);
subplot(3,1,1);
plot(t,signal_combined);
title('Combined Signal');

%check the filter
f_signal_matlab = filter(b,a,(signal_combined));
subplot(3,1,2);
plot(t,f_signal_matlab);
title('The filtered signal using matlab')

%Write the combined signal in a file
csvwrite("noisy signal.csv", signal_combined.'); 

%read the C program filtered signal 
f_signal_c = csvread("filtered signal.csv").';
subplot(3,1,3);
plot(t,f_signal_c(1:length(t)));
title('the filtered signal using c program')









