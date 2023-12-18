// 495. Teemo Attacking
// 14 December 2023

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

    while (i < timeSeriesSize && next <= end){
        if(*next - *timeSeries <= duration - 1){
            attack += (*next - *timeSeries);
        } else {
            attack += duration;
        }
        timeSeries++;
        i++;
        if (next + 1 <= end){
            next++;
        }
    }
    return attack;
}
