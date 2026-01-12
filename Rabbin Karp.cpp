#include<iostream>
#include<string>
#include<cmath>
#include<chrono>
#include<vector>


using namespace std ;


class RABIN_KARP{
  
    private :
    
    long PRIME = 101 ;
    
    double calculateHash(string str){ // calculating hash formula : hash + str[i]*(prime number , i) 
        
        double hash = 0 ;
        
        for(int i = 0 ; i<str.length() ; i++){
            
            hash = hash + str.at(i)* pow(PRIME , i );
        }
        
        return hash ;
    }
    
    
    double updateHash(double prevHash , char oldchar , char newchar , long patternlenght){
        
        double newHash = (prevHash - oldchar) / PRIME ;
        
        newHash = newHash + newchar * pow(PRIME , patternlenght - 1);
        
        return newHash ;
    }
    
    public :
    
    int search(string text , string pattern){
        
        long patternLength = pattern.length() ;
        
        double paternHash = calculateHash(pattern) ;
        double textHash = calculateHash(text.substr(0,patternLength));
        
    
        for(int i = 0 ; i<=text.length() - patternLength ; i++){ // Running it till where we can find right length
            
            if(textHash == paternHash){ // If hashes are equal hash("nakul") == hash("kunal")
                
                if(text.substr(i , patternLength) == pattern){ // checking the pattern matching
                    
                    return i ;
                }
            }
            
            if(i < text.length() - patternLength){ // This is called rolling hash removing the prevchar and adding newchar.
                textHash = updateHash(textHash, text.at(i), text.at(i + patternLength), patternLength);
                
            }
            
        }
        return -1 ;
    }
    
};

int bruteForceSearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();

    // loop over every possible starting index in the text
    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        // compare characters as long as they match
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }

        // if j reached pattern length, we found a match
        if (j == m) {
            return i;  // return the first index where pattern is found
        }
    }

    return -1;  // not found
}
std::vector<std::string> get_clean_vector() {
    // 1. The forbidden input text
    const std::string source =
        "thepathledthroughalleyswhereoldsignswhisperedforgottennamesandtinyligh"
        "tsblinkedlikepatientstarstheylearnedtolistentothesubtlelogiiddeninever"
        "ydaythingstreatingeachsoundasacluethecoderwokebeforedawnwithasmallidea"
        "thatfeltlikeasparktheywalkedtothewindowandwatchedlightcreepoverquietst"
        "reetswhilethecityexhaledasinglethoughtunfoldedintoplansthenintosketche"
        "sonanapkinandcoffeewarmedtheirhandseachtinysuccessinvitedanotherexperi"
        "mentanotherlineofcodethathummedlikegentlemachinerytheneighborbroughtpa"
        "permapsandstoriesofdoorsthatopenedonlyforthosewhoaskedpolitelytogether"
        "theytracedpossibilitiesfollowinghintswritteninfadedinkandmarginalnotes"
        "thatsmelledfaintlyofrainthegroupbecamearaggedcollectionofcuriouspeople"
        "eachaddingasmalltalentonesangpatternsaloudanotherdrewcircuitswithacare"
        "fulhandmistaketaughtpatiencepatiencebecameasteadyfuelforprogressasthey"
        "iteratedthroughversionsandpromisesmiddaylightrevealedtheprototypeblink"
        "ingincornerafragilethingstitchedfromhopeandlatenightspromisinghowsmall"
        "inventionscanchangehowpeoplemeeteveningsoftenedtheedgesofthedayandeigh"
        "borsgatheredaroundtowatchthedeviceperformitsfirsthonesttrickitemitteda"
        "warmpulsethatmatchedheartbeatsandsangtinyharmonieswhentwondstouchedash"
        "aredhandlechildrenclappedelderssmiledandstrangerspausedlongenoughtoexc"
        "hangenamesthecoderadjustedparameterstunedresponssanddiscoverednewharmo"
        "nieshiddeninfeedbackconversationsgrewweavingplansthatreachedbeyondtheb"
        "lockintonearbystreetstheprojectturnedinoanexperimentinkindnessacommuna"
        "lmachinethataskedfornothinggrandandreturnedsmallusefulcomfortsthecityf"
        "eltalittlemorereadablebecausesmeonebotheredtolistenatnighttheprototype"
        "restedlikeapetharmlessandproudandtheteamrecordednotesandsketchesbylant"
        "ernlighttheycatalogedfailureswithgentlehumormarkingwhathadbeentriedand"
        "whyeachfailurebecamealessonlabeledintidyhandwritingandthestackofnotesf"
        "ormedamapofimaginationthecoderdreamedofbridgesbetweensystemsandofsimpl"
        "eprotocolsthatmadeneighboreelseendawnarrivedagainandwithitnewcaffeinea"
        "ndnewhypothesesthepatternrepeatedbuildbreaklearnandharemomentumaccumul"
        "atedlikepebblesforminapathprogresswasslowyetunmistakeablemadeofmanysma"
        "llhandsavisitingstudentfromanotherquarterofferedafreshalgorithmandaque"
        "stionthatchangedthirperspectivewhatifthedevicelistenedaswellasitspoket"
        "heyrewiredabranchofthecircuitaddingasubtlefilterthatallowedquietvoices"
        "tobeheardabovethebustlethechangewastinybutmeaningfulsuddenlythedevicer"
        "ecognizedhesitationandsofteneditsreplytheteamcelebratedbycookingalarge"
        "mealandsharingstoriesunderstringsoflightlaughterbecamearegularinputint"
        "heirlogsandeveryrecipefeltlikecodewithspicesforvariablethiscommunalrit"
        "ualcementedtheirbondandseededmoreambitiousideasforsharedspacessoonloca"
        "lartistsaskedtocollaborateaddingvisualsthatturneddataintomovingmuralsa"
        "crossshuttersandwallsthesystemlearnedtotranslatemoodintocolorandrhythm"
        "intoslowbloomingshapesmorningcommuterspausedtowatchgentlepatternsrippl"
        "eacosspaintedbricksandsomedaysthemuralsmatchedtheweathersmoodexactlyto"
        "uriststookpictureswhichbroughtsmalldonationsthatfundedsparepartsandmor"
        "ebatteriesthecoderfoundthatbeautyandutilitycantraveltogetherandthatcre"
        "ativitywidenedthecircleofsupportworkshopswerescheduledchildrendrewcrcu"
        "itswithcrayonsandtheprojectgrewlegsthatcarrieditbeyondtheoriginalalley"
        "intoaneighboringplazawithgrowthcamecompatibilityquestionsuserpreerence"
        "sanddebatesaboutwhattoprioritizetheyheldcommunitymeetingswhereeveryone"
        "couldspeakanddecisionswereadeoutloudwithstickynotesandvotesthprocessta"
        "ughtthemgovernancebysmallactslisteningtoleratingmistakesandmakingroomf"
        "orcorrectionupdateswererolledoutslowlytoavoidbreakingdelictebalancesan"
        "drollbackplanswerekeptreadylikespareumbrellasthroughiterationsthesyste"
        "mbecamemoreresilientaccommodatingnewlanguagesandunexpectedusessometime"
        "sitmisinterpretedjokesandofferedliteralsolutionspromptinggentlecorrect"
        "ionsandlaughterthesemisstepswereusefulbecausetheyrevealedassumptionsan"
        "dgaverisetomorethoughtfuldesignonerainyafternoonthedevicedetectedanunu"
        "sualpatternalullinactivitymatchedtoatoneofworryvolunteerscheckedonaloc"
        "alelderwhohadgrownquietandfoundtheyneededasimplerepairandconversationt"
        "hedevicehadbecomeanearlywarningofhumanslowdownsandtheteamaddedasmallpr"
        "otocoltoflagsoftdeclinesneighborsorganizedrotatingvisitsandbroughtsoup"
        "toolsandcompanythispracticaloutreachtransformedtheinventionfromnovelty"
        "intonecessityitwasnowaneighborthatnoticedthecoderfeltquietpriderealizi"
        "ngthattechnologycouldnudgecareintobeingthreadbythreadineverydaylifeasm"
        "onthspassedtheprojectinspiredotherblockstostarttheirownversionseachwit"
        "hlocalflavorsandlanguagesacrossstreetcollaborationproducedaportableuni"
        "tthatfoldedintoabenchanothergrupembedsensorsintogardenstomarkwateringn"
        "eedswithgentlechimesthenetworkswereinformalbutrobustexchangingpatchesa"
        "ndblueprintsinopennotebooksconferencesweresmallandearnestfullofhanddra"
        "wndiagramsandwarmcoffeethecodertraveledtoteachreturningwithnewstoriesa"
        "ndtoolsbythentheprototypehadbecomeanecosystemafamilyofpracticescentere"
        "donattentivenessplayfulexperimentsandpracticalempathythatscaledwithout"
        "losingitshumantoneoneclearmorningtheygatheredtocelebrateayearoftinkeri"
        "ngandsmallvictorieslayingoutaquiltofnotesphotosandsparepartchildrenper"
        "formedashortplayaboutatalkinglanternandelderstoldhowneighborshadhelped"
        "duringquietemergenciesthecoderreflectedonbeginningsthatsinglesparkbefo"
        "redawnandfeltgratitudeforeveryonewhohadshownupwithcuriositytheyplanned"
        "nextstepstrainingmorevolunteerssimplifyingassemblyanddocumentingstorie"
        "sootherscouldreproducewhattheyhadlearnedthecelebrationendedwithpromis"
        "estokeeplisteningtobuildlightlyandtokeepinvitingpeopleintothedelightfu"
        "lpracticeofsharedinvention";

    std::vector<std::string> v;
    v.reserve(10000);
    
    // Deterministic generation logic
    // We use a simple custom LCG (Linear Congruential Generator) to ensure
    // you get the exact same "random" words every time you run this code.
    unsigned long seed = 12345;
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    
    while(v.size() < 10000) {
        std::string s = "";
        for(int i=0; i<5; ++i) { // Fixed size 5 satisfies "average size 5"
            seed = (seed * 1103515245 + 12345) & 0x7FFFFFFF;
            s += charset[seed % 26];
        }
        
        // Only add if it doesn't exist in source
        if (source.find(s) == std::string::npos) {
            v.push_back(s);
        }
    }
    return v;
}

int main(){
    
   // RABIN_KARP  RK ;
    auto start = chrono::high_resolution_clock::now() ;
    string input =
        "thepathledthroughalleyswhereoldsignswhisperedforgottennamesandtinyligh"
        "tsblinkedlikepatientstarstheylearnedtolistentothesubtlelogiiddeninever"
        "ydaythingstreatingeachsoundasacluethecoderwokebeforedawnwithasmallidea"
        "thatfeltlikeasparktheywalkedtothewindowandwatchedlightcreepoverquietst"
        "reetswhilethecityexhaledasinglethoughtunfoldedintoplansthenintosketche"
        "sonanapkinandcoffeewarmedtheirhandseachtinysuccessinvitedanotherexperi"
        "mentanotherlineofcodethathummedlikegentlemachinerytheneighborbroughtpa"
        "permapsandstoriesofdoorsthatopenedonlyforthosewhoaskedpolitelytogether"
        "theytracedpossibilitiesfollowinghintswritteninfadedinkandmarginalnotes"
        "thatsmelledfaintlyofrainthegroupbecamearaggedcollectionofcuriouspeople"
        "eachaddingasmalltalentonesangpatternsaloudanotherdrewcircuitswithacare"
        "fulhandmistaketaughtpatiencepatiencebecameasteadyfuelforprogressasthey"
        "iteratedthroughversionsandpromisesmiddaylightrevealedtheprototypeblink"
        "ingincornerafragilethingstitchedfromhopeandlatenightspromisinghowsmall"
        "inventionscanchangehowpeoplemeeteveningsoftenedtheedgesofthedayandeigh"
        "borsgatheredaroundtowatchthedeviceperformitsfirsthonesttrickitemitteda"
        "warmpulsethatmatchedheartbeatsandsangtinyharmonieswhentwondstouchedash"
        "aredhandlechildrenclappedelderssmiledandstrangerspausedlongenoughtoexc"
        "hangenamesthecoderadjustedparameterstunedresponssanddiscoverednewharmo"
        "nieshiddeninfeedbackconversationsgrewweavingplansthatreachedbeyondtheb"
        "lockintonearbystreetstheprojectturnedinoanexperimentinkindnessacommuna"
        "lmachinethataskedfornothinggrandandreturnedsmallusefulcomfortsthecityf"
        "eltalittlemorereadablebecausesmeonebotheredtolistenatnighttheprototype"
        "restedlikeapetharmlessandproudandtheteamrecordednotesandsketchesbylant"
        "ernlighttheycatalogedfailureswithgentlehumormarkingwhathadbeentriedand"
        "whyeachfailurebecamealessonlabeledintidyhandwritingandthestackofnotesf"
        "ormedamapofimaginationthecoderdreamedofbridgesbetweensystemsandofsimpl"
        "eprotocolsthatmadeneighboreelseendawnarrivedagainandwithitnewcaffeinea"
        "ndnewhypothesesthepatternrepeatedbuildbreaklearnandharemomentumaccumul"
        "atedlikepebblesforminapathprogresswasslowyetunmistakeablemadeofmanysma"
        "llhandsavisitingstudentfromanotherquarterofferedafreshalgorithmandaque"
        "stionthatchangedthirperspectivewhatifthedevicelistenedaswellasitspoket"
        "heyrewiredabranchofthecircuitaddingasubtlefilterthatallowedquietvoices"
        "tobeheardabovethebustlethechangewastinybutmeaningfulsuddenlythedevicer"
        "ecognizedhesitationandsofteneditsreplytheteamcelebratedbycookingalarge"
        "mealandsharingstoriesunderstringsoflightlaughterbecamearegularinputint"
        "heirlogsandeveryrecipefeltlikecodewithspicesforvariablethiscommunalrit"
        "ualcementedtheirbondandseededmoreambitiousideasforsharedspacessoonloca"
        "lartistsaskedtocollaborateaddingvisualsthatturneddataintomovingmuralsa"
        "crossshuttersandwallsthesystemlearnedtotranslatemoodintocolorandrhythm"
        "intoslowbloomingshapesmorningcommuterspausedtowatchgentlepatternsrippl"
        "eacosspaintedbricksandsomedaysthemuralsmatchedtheweathersmoodexactlyto"
        "uriststookpictureswhichbroughtsmalldonationsthatfundedsparepartsandmor"
        "ebatteriesthecoderfoundthatbeautyandutilitycantraveltogetherandthatcre"
        "ativitywidenedthecircleofsupportworkshopswerescheduledchildrendrewcrcu"
        "itswithcrayonsandtheprojectgrewlegsthatcarrieditbeyondtheoriginalalley"
        "intoaneighboringplazawithgrowthcamecompatibilityquestionsuserpreerence"
        "sanddebatesaboutwhattoprioritizetheyheldcommunitymeetingswhereeveryone"
        "couldspeakanddecisionswereadeoutloudwithstickynotesandvotesthprocessta"
        "ughtthemgovernancebysmallactslisteningtoleratingmistakesandmakingroomf"
        "orcorrectionupdateswererolledoutslowlytoavoidbreakingdelictebalancesan"
        "drollbackplanswerekeptreadylikespareumbrellasthroughiterationsthesyste"
        "mbecamemoreresilientaccommodatingnewlanguagesandunexpectedusessometime"
        "sitmisinterpretedjokesandofferedliteralsolutionspromptinggentlecorrect"
        "ionsandlaughterthesemisstepswereusefulbecausetheyrevealedassumptionsan"
        "dgaverisetomorethoughtfuldesignonerainyafternoonthedevicedetectedanunu"
        "sualpatternalullinactivitymatchedtoatoneofworryvolunteerscheckedonaloc"
        "alelderwhohadgrownquietandfoundtheyneededasimplerepairandconversationt"
        "hedevicehadbecomeanearlywarningofhumanslowdownsandtheteamaddedasmallpr"
        "otocoltoflagsoftdeclinesneighborsorganizedrotatingvisitsandbroughtsoup"
        "toolsandcompanythispracticaloutreachtransformedtheinventionfromnovelty"
        "intonecessityitwasnowaneighborthatnoticedthecoderfeltquietpriderealizi"
        "ngthattechnologycouldnudgecareintobeingthreadbythreadineverydaylifeasm"
        "onthspassedtheprojectinspiredotherblockstostarttheirownversionseachwit"
        "hlocalflavorsandlanguagesacrossstreetcollaborationproducedaportableuni"
        "tthatfoldedintoabenchanothergrupembedsensorsintogardenstomarkwateringn"
        "eedswithgentlechimesthenetworkswereinformalbutrobustexchangingpatchesa"
        "ndblueprintsinopennotebooksconferencesweresmallandearnestfullofhanddra"
        "wndiagramsandwarmcoffeethecodertraveledtoteachreturningwithnewstoriesa"
        "ndtoolsbythentheprototypehadbecomeanecosystemafamilyofpracticescentere"
        "donattentivenessplayfulexperimentsandpracticalempathythatscaledwithout"
        "losingitshumantoneoneclearmorningtheygatheredtocelebrateayearoftinkeri"
        "ngandsmallvictorieslayingoutaquiltofnotesphotosandsparepartchildrenper"
        "formedashortplayaboutatalkinglanternandelderstoldhowneighborshadhelped"
        "duringquietemergenciesthecoderreflectedonbeginningsthatsinglesparkbefo"
        "redawnandfeltgratitudeforeveryonewhohadshownupwithcuriositytheyplanned"
        "nextstepstrainingmorevolunteerssimplifyingassemblyanddocumentingstorie"
        "ssootherscouldreproducewhattheyhadlearnedthecelebrationendedwithpromis"
        "estokeeplisteningtobuildlightlyandtokeepinvitingpeopleintothedelightfu"
        "lpracticeofsharedinvention";

    vector<string> str = get_clean_vector() ;
    RABIN_KARP RK ;
    for(const auto& w : str){
       RK.search(input, w);
   }
    auto end = chrono::high_resolution_clock::now();
 
    chrono::duration<double , milli>duration = end - start  ;
    
    cout<<duration<<endl;
    //2.245 sec , 2.373 .

}
