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


// v2
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if (timeSeries == NULL || duration == 0 || timeSeriesSize == 0) {
        return 0;
    }
    int attack = 0;
    int second = *timeSeries + duration -1;
    attack += duration;
    int i = 0; 
    int* next = timeSeries + 1;
    int* end = timeSeries + timeSeriesSize -1;
    while (i < timeSeriesSize-1 && next < end){
        while (*timeSeries < second){
            timeSeries++;
            i++;
            next++;
        }
        second = second + duration -1;
        if (second < *timeSeries){
            attack += duration;
        }else{
            attack = attack + *next - *timeSeries;
        }
        timeSeries++;
        i++;
        next++;
    }
    return attack;
}
