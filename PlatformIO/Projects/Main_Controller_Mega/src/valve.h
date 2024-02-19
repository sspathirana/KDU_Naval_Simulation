int LO_sump_level_valve = 0, LO_sump_level_valve_en = 0;

void valve(){

    if(neo[93] == 'G' && neo[92] == 'G' && neo[82] == 'G' && neo[79] == 'G' && neo[71] == 'G' && LO_sump_level_valve_en == 0){
        LO_sump_level_valve_en = 4;
        Serial2.println("STAR1");
    }
    else{
        LO_sump_level_valve_en = 0;
        Serial2.println("STOP");
    }
}

