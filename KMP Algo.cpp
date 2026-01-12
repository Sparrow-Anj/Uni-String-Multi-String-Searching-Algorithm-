#include <iostream>
#include <vector>
#include<algorithm>
#include<chrono> 

/* Application of all these algorithm is the problems including string search */

using namespace std;

auto generate_array(const string &pattern, vector<int> &kmp_array) -> void {

    int i = 1;
    int j = 0;

    kmp_array[0] = 0; // First value is always initialized with 0

    size_t n = pattern.length();

    while (i < n) {

        // if matches

        if (pattern[i] == pattern[j]) { // moving forward

            kmp_array[i] = j + 1;
            ++i;
            ++j;
        }

        // if not
        else {
            
            if (j != 0) { // falling back if possible
                j = kmp_array[j - 1];
            } else { // otherwise move forward and set 0 no match
                kmp_array[i] = 0;
                i++;
            }
        }
    }
}

int KMP(const string &text, const string &pattern) {
    
    if (pattern.length() > text.length()){
        return -1;
    }
    
    vector<int> kmp_array(pattern.length());
    generate_array(pattern, kmp_array);
    
    int i = 0 ; // for text
    int j = 0 ; // for pattern
    size_t n = text.length() ;
    size_t m = pattern.length() ;
    
    while(i < n ){ // Iterating over text to get the match 
        
        // if matches
        
        if(text[i] == pattern[j]){
            i ++ ;
            j ++ ;
            
            if(j == m ){
                return i - m ;
            }
        }
        
        // if not
        else{
            
            if(j!=0){
                j = kmp_array[j-1];
            }
            else{
                i++;
            }
        }
    }

    return -1 ; 
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


int main(int argc, char *arg[]) {
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

    vector<string> str = get_clean_vector();
   
    for(const auto& w : str){
        KMP(input, w);
    }
    auto end = chrono::high_resolution_clock::now();
 
    chrono::duration<double , milli>duration = end - start ;
    
    cout<<duration<<endl;
}
// 2.2 second 
