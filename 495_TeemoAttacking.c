// 495. Teemo Attacking

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if (duration == 0) {
        return 0;
    }
    int attack = 0;
    int second = *timeSeries + duration -1;
    attack += duration;
    int i = 0; 
    while (i < timeSeriesSize-1){
        while (*timeSeries < second){
            timeSeries++;
            i++;
        }
        second = *timeSeries + duration -1;
        attack += duration;
        i++;
    }
    return attack;
}
