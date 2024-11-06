%Lettura del best case
best_case_CS= 'average_case_QS.csv';
B=csvread(best_case_CS);

worst_case_CS= 'worst_case_CS.csv';
W=csvread(worst_case_CS);

%Dimensione righe e colonne
R=size(B);

%Funzione che passa per i punti
w=spline(100:100:100000,B(1:R(1),2),100:100:100000);
%Definizione del polinomio(Regressione Lineare)
time=B(1:R(1),2)';
t=100:100:100000;
p=polyfit(t,time,1);
pol=polyval(p,t);

%Dimensione righe e colonne
R2=size(W);

%Funzione che passa per i punti
w2=spline(100:100:100000,W(1:R2(1),2),100:100:100000);
%Definizione del polinomio(Regressione Lineare)
time2=W(1:R2(1),2)';
t=100:100:100000;
p2=polyfit(t,time2,1);
pol2=polyval(p2,t);

figure(1);
plot(100:100:100000,w,'-b',t,pol,'r');
title('Averagecase');
xlabel('Dimensione Array');
ylabel('Tempo in nanosecondi ');
%axis([0 99900 0 500000]);

figure(2); 
plot(100:100:100000,w2,'-b',t,pol2,'r');
title('Worstcase');
xlabel('Dimensione Array');
ylabel('Tempo in nanosecondi ');

%axis([0 99900 0 500000]);
figure(3);
plot(100:100:100000,w,'-b',t,pol,'k',100:100:100000,w2,'-m',t,pol2,'g');
title('Confronto tra QS e CS'); 
xlabel('Dimensione Array'); 
ylabel('Tempo in nanosecondi');
legend({'T(n) QS','Spline QS','T(n) CS','Spline CS'},'Location','northwest','Orientation','vertical')

%Definizione dei limiti
x=linspace(0,100000);
y1=10*x.^2;
y2=0.5*x.^2;
y3=8*x.^2;
figure(4);
plot(x,y1,'b',x,y2,'g',x,y3,'r');
%plot(x,y1,'b',x,y2,'g',100:100:100000,w2,'r');
title('Tempo di esecuzione di QuickSort');
xlabel('Dimensione Array');
ylabel('Tempo in nanosecondi');
legend({'T(n)=10n^2','T(n)=0.5n^2','T(n)'},'Location','northwest','Orientation','vertical')
