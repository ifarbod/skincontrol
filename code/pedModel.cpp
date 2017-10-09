/*
Skin Control pedModels.cpp
By Neutrinobeam, "Legible" names from Enhanced Native Trainer
*/

#pragma once
#include "pedModel.h"
#include "script.h"

bool isSinglePlayer(Hash model)
{
    int id = hashLookup(model);
    return (id == 0 || id == 1 || id == 2);
}

bool isFreemode(Hash model)
{
    int id = hashLookup(model);
    return (id == 3 || id == 4);
}

bool isFreemode(int id)
{
    return (id == 3 || id == 4);
}

bool isPlayer(Hash model)
{
    int id = hashLookup(model);
    return (id == 0 || id == 1 || id == 2 || id == 3 || id == 4);
}
bool isPlayer(int id)
{
    return (id == 0 || id == 1 || id == 2 || id == 3 || id == 4);
}

bool isAnimal(int id)
{
    return (700 <= id && id < 726);
}

Hash getModelHash(int index)
{
    return GAMEPLAY::GET_HASH_KEY((char*)getModel(index));
}

// Padding is used to separate different pages of the model selection menu
LPCSTR pedModelData[740][2] = {{"player_zero", "Michael"}, {"player_one", "Franklin"}, {"player_two", "Trevor"},
    {"mp_f_freemode_01", "Freemode Female"}, {"mp_m_freemode_01", "Freemode Male"},
    // 5
    {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""},
    {"", ""}, {"", ""}, {"", ""}, {"", ""},
    // 20
    {"csb_abigail", "Abigail Mathers(CS)"}, {"ig_abigail", "Abigail Mathers"}, {"u_m_y_abner", "Abner"},
    {"u_m_m_aldinapoli", "Al Di Napoli"}, {"cs_amandatownley", "Amanda De Santa(CS)"},
    {"ig_amandatownley", "Amanda De Santa"}, {"cs_andreas", "Andreas Sanchez(CS)"}, {"ig_andreas", "Andreas Sanchez"},
    {"csb_anita", "Anita Mendoza(CS?)"}, {"csb_anton", "Anton Beaudelaire"}, {"u_m_y_antonb", "Anton Beaudelaire"},
    {"cs_ashley", "Ashley Butler(CS)"}, {"ig_ashley", "Ashley Butler"}, {"g_m_y_azteca_01", "Azteca"},
    {"u_m_y_babyd", "Baby D"}, {"cs_barry", "Barry(CS)"}, {"ig_barry", "Barry"}, {"cs_beverly", "Beverly Felton(CS)"},
    {"ig_beverly", "Beverly Felton"}, {"cs_brad", "Brad(CS)"}, {"ig_brad", "Brad"},
    {"cs_bradcadaver", "Brad's Cadaver (CS)"}, {"cs_casey", "Casey(CS)"}, {"ig_casey", "Casey"},
    {"s_m_y_chef_01", "Chef"}, {"csb_chef", "Chef(CS)"}, {"csb_chef2", "Chef  2 (CS)"}, {"ig_chef", "Chef"},
    {"ig_chef2", "Chef 2"}, {"u_m_y_chip", "Chip"}, {"mp_m_claude_01", "Claude Speed"}, {"ig_claypain", "Clay Jackson"},
    {"cs_clay", "Clay Simons(CS)"}, {"ig_clay", "Clay Simons)"}, {"csb_cletus", "Cletus(CS?)"}, {"ig_cletus", "Cletus"},
    {"cs_dale", "Dale(CS)"}, {"ig_dale", "Dale"}, {"cs_davenorton", "Dave Norton(CS)"},
    {"ig_davenorton", "Dave Norton"}, {"cs_debra", "Debra(CS)"}, {"cs_denise", "Denise(CS)"}, {"ig_denise", "Denise"},
    {"csb_denise_friend", "Denise's Friend"}, {"cs_devin", "Devin (CS)"}, {"ig_devin", "Devin"},
    {"s_m_y_devinsec_01", "Devin's Security"}, {"csb_popov", "Dima Popov(CS)"}, {"ig_popov", "Dima Popov"},
    {"cs_dom", "Dom Beasley(CS)"}, {"ig_dom", "Dom Beasley"}, {"cs_drfriedlander", "Dr.Friedlander(CS)"},
    {"ig_drfriedlander", "Dr.Friedlander"}, {"u_m_m_edtoh", "Eddie Toh"}, {"cs_tomepsilon", "Epsilon Tom(CS)"},
    {"ig_tomepsilon", "Epsilon Tom"}, {"cs_fabien", "Fabien(CS)"}, {"ig_fabien", "Fabien"},
    {"cs_mrk", "Ferdinand Kerimov(CS)"}, {"ig_mrk", "Ferdinand Kerimov"}, {"cs_floyd", "Floyd Hebert(CS)"},
    {"ig_floyd", "Floyd Hebert"}, {"csb_g", "Gerald"}, {"cs_guadalope", "Guadalope(CS)"}, {"csb_hao", "Hao(CS?)"},
    {"ig_hao", "Hao"}, {"csb_hugh", "Hugh Welsh"}, {"csb_imran", "Imran Shinowa"}, {"u_f_y_comjane", "Jane"},
    {"cs_janet", "Janet(CS)"}, {"ig_janet", "Janet"}, {"ig_jay_norris", "Jay Norris"},
    {"cs_jimmyboston", "Jimmy Boston(CS)"}, {"ig_jimmyboston", "Jimmy Boston"},
    {"cs_jimmydisanto", "Jimmy De Santa(CS)"}, {"ig_jimmydisanto", "Jimmy De Santa"},
    {"mp_m_marston_01", "John Marston"}, {"cs_johnnyklebitz", "Johnny Klebitz(CS)"},
    {"ig_johnnyklebitz", "Johnny Klebitz"}, {"cs_joeminuteman", "Joe(CS)"}, {"ig_joeminuteman", "Joe"},
    {"cs_josef", "Josef(CS)"}, {"ig_josef", "Josef"}, {"cs_josh", "Josh(CS)"}, {"ig_josh", "Josh"},
    {"u_m_y_justin", "Justin"}, {"cs_karen_daniels", "Karen Daniels(CS)"}, {"ig_karen_daniels", "Karen Daniels"},
    {"ig_kerrymcintosh", "Kerry McIntosh"}, {"cs_lamardavis", "Lamar Davis(CS)"}, {"ig_lamardavis", "Lamar Davis"},
    {"cs_lazlow", "Lazlow(CS)"}, {"ig_lazlow", "Lazlow"}, {"cs_lestercrest", "Lester Crest(CS)"},
    {"ig_lestercrest", "Lester Crest"}, {"cs_magenta", "Magenta(CS)"}, {"ig_magenta", "Magenta"},
    {"cs_manuel", "Manuel(CS)"}, {"ig_manuel", "Manuel"}, {"u_m_m_markfost", "Mark Fostenburg"},
    {"cs_marnie", "Marnie Allen(CS)"}, {"ig_marnie", "Marnie Allen"}, {"cs_martinmadrazo", "Martin Madrazo(CS)"},
    {"cs_maryann", "Mary-Ann Quinn(CS)"}, {"ig_maryann", "Mary-Ann Quinn"}, {"csb_maude", "Maude"},
    {"ig_maude", "Maude"}, {"cs_michelle", "Michelle(CS)"}, {"ig_michelle", "Michelle"},
    {"cs_milton", "Milton McIlroy(CS)"}, {"ig_milton", "Milton McIlroy"}, {"u_f_m_miranda", "Miranda"},
    {"mp_f_misty_01", "Misty"}, {"cs_molly", "Molly(CS)"}, {"ig_molly", "Molly"},
    {"cs_mrsphillips", "Mrs.Phillips(CS)"}, {"ig_mrsphillips", "Mrs.Phillips"},
    {"cs_mrs_thornhill", "Mrs.Thornhill(CS)"}, {"ig_mrs_thornhill", "Mrs.Thornhill"}, {"cs_natalia", "Natalia(CS)"},
    {"ig_natalia", "Natalia"}, {"cs_nervousron", "Nervous Ron(CS)"}, {"ig_nervousron", "Nervous Ron"},
    {"cs_nigel", "Nigel(CS)"}, {"ig_nigel", "Nigel"}, {"mp_m_niko_01", "Niko Bellic"}, {"cs_omega", "Omega(CS)"},
    {"ig_omega", "Omega"}, {"ig_oneil", "O'Neil Brothers"}, {"csb_ortega", "Ortega"}, {"ig_ortega", "Ortega"},
    {"csb_oscar", "Oscar"}, {"csb_paige", "Paige Harris(CS)"}, {"ig_paige", "Paige Harris"},
    {"cs_patricia", "Patricia(CS)"}, {"ig_patricia", "Patricia"}, {"cs_dreyfuss", "Peter Dreyfuss(CS)"},
    {"ig_dreyfuss", "Peter Dreyfuss"}, {"u_m_y_pogo_01", "Pogo the Monkey"}, {"u_f_y_poppymich", "Poppy Mitchell"},
    {"csb_rashcosvki", "Rashkovsky(CS)"}, {"ig_rashcosvki", "Rashkovsky"}, {"csb_roccopelosi", "Rocco Pelosi"},
    {"ig_roccopelosi", "Rocco Pelosi"}, {"cs_siemonyetarian", "Simeon Yetarian(CS)"},
    {"ig_siemonyetarian", "Simeon Yetarian"}, {"cs_solomon", "Solomon Richards(CS)"},
    {"ig_solomon", "Solomon Richards"}, {"cs_stevehains", "Steve Haines(CS)"}, {"ig_stevehains", "Steve Haines"},
    {"cs_stretch", "Stretch(CS)"}, {"ig_stretch", "Stretch"}, {"ig_talina", "Talina"}, {"cs_tanisha", "Tanisha(CS)"},
    {"ig_tanisha", "Tanisha"}, {"cs_taocheng", "Tao Cheng(CS)"}, {"ig_taocheng", "Tao Cheng"},
    {"cs_taostranslator", "Tao's Translator (CS)"}, {"ig_taostranslator", "Tao's Translator"},
    {"cs_terry", "Terry(CS)"}, {"ig_terry", "Terry"}, {"cs_tom", "Tom(CS)"}, {"csb_tonya", "Tonya"},
    {"ig_tonya", "Tonya"}, {"cs_tracydisanto", "Tracey De Santa(CS)"}, {"ig_tracydisanto", "Tracey De Santa"},
    {"ig_tylerdix", "Tyler Dixon"}, {"cs_wade", "Wade(CS)"}, {"ig_wade", "Wade"}, {"cs_chengsr", "Wei Cheng(CS)"},
    {"ig_chengsr", "Wei Cheng"}, {"cs_zimbor", "Zimbor(CS)"}, {"ig_zimbor", "Zimbor"}, {"csb_agent", "Agent(CS)"},
    {"ig_agent", "Agent"}, {"csb_mp_agent14", "Agent 14(CS)"}, {"ig_mp_agent14", "Agent 14"},
    {"a_m_m_afriamer_01", "African American Male"}, {"s_f_y_airhostess_01", "Air Hostess"},
    {"s_m_y_airworker", "Air Worker Male"}, {"s_m_m_movalien_01", "Alien"},
    {"a_m_m_acult_01", "Altruist Cult Mid-Age Male"}, {"a_m_o_acult_01", "Altruist Cult Old Male"},
    {"a_m_o_acult_02", "Altruist Cult Old Male 2"}, {"a_m_y_acult_01", "Altruist Cult Young Male"},
    {"a_m_y_acult_02", "Altruist Cult Young Male 2"}, {"s_m_y_ammucity_01", "Ammu-Nation City Clerk"},
    {"s_m_m_ammucountry", "Ammu-Nation Rural Clerk"}, {"g_m_m_armboss_01", "Armenian Boss"},
    {"g_m_m_armgoon_01", "Armenian Goon"}, {"g_m_y_armgoon_02", "Armenian Goon 2"},
    {"g_m_m_armlieut_01", "Armenian Lieutenant"}, {"mp_s_m_armoured_01", "Armored Van Security(MP)"},
    {"s_m_m_armoured_01", "Armored Van Security"}, {"s_m_m_armoured_02", "Armored Van Security 2"},
    {"s_m_y_armymech_01", "Army Mechanic"}, {"s_m_y_autopsy_01", "Autopsy Tech"},
    {"s_m_m_autoshop_01", "Autoshop Worker"}, {"s_m_m_autoshop_02", "Autoshop Worker 2"},
    {"g_m_y_ballaeast_01", "Ballas East Male"}, {"g_f_y_ballas_01", "Ballas Female"},
    {"csb_ballasog", "Ballas OG(CS?)"}, {"ig_ballasog", "Ballas OG"}, {"g_m_y_ballaorig_01", "Ballas Original Male"},
    {"g_m_y_ballasout_01", "Ballas South Male"}, {"cs_bankman", "Bank Manager(CS)"}, {"ig_bankman", "Bank Manager"},
    {"u_m_m_bankman", "Bank Manager Male"}, {"s_f_m_fembarber", "Barber Female"}, {"s_m_y_barman_01", "Barman"},
    {"s_f_y_bartender_01", "Bartender"}, {"s_m_m_cntrybar_01", "Bartender(Rural)"},
    {"s_f_y_baywatch_01", "Baywatch Female"}, {"s_m_y_baywatch_01", "Baywatch Male"},
    {"a_f_m_beach_01", "Beach Female"}, {"a_m_m_beach_01", "Beach Male"}, {"a_m_m_beach_02", "Beach Male 2"},
    {"a_m_y_musclbeac_01", "Beach Muscle Male"}, {"a_m_y_musclbeac_02", "Beach Muscle Male 2"},
    {"a_m_o_beach_01", "Beach Old Male"}, {"a_f_m_trampbeac_01", "Beach Tramp Female"},
    {"a_m_m_trampbeac_01", "Beach Tramp Male"}, {"a_f_y_beach_01", "Beach Young Female"},
    {"a_m_y_beach_01", "Beach Young Male"}, {"a_m_y_beach_02", "Beach Young Male 2"},
    {"a_m_y_beach_03", "Beach Young Male 3"}, {"ig_bestmen", "Best Man"}, {"a_f_m_bevhills_01", "Bev Hills Female"},
    {"a_f_m_bevhills_02", "Bev Hills Female 2"}, {"a_m_m_bevhills_01", "Bev Hills Male"},
    {"a_m_m_bevhills_02", "Bev Hills Male 2"}, {"a_f_y_bevhills_01", "Bev Hills Young Female"},
    {"a_f_y_bevhills_02", "Bev Hills Young Female 2"}, {"a_f_y_bevhills_03", "Bev Hills Young Female 3"},
    {"a_f_y_bevhills_04", "Bev Hills Young Female 4"}, {"a_m_y_bevhills_01", "Bev Hills Young Male"},
    {"a_m_y_bevhills_02", "Bev Hills Young Male 2"}, {"cs_orleans", "Bigfoot(CS)"}, {"ig_orleans", "Bigfoot"},
    {"u_m_m_bikehire_01", "Bike Hire Guy"}, {"u_f_y_bikerchic", "Biker Chic Female"},
    {"s_m_y_blackops_01", "Black Ops Soldier"}, {"s_m_y_blackops_02", "Black Ops Soldier 2"},
    {"s_m_y_blackops_03", "Black Ops Soldier 3"}, {"a_m_y_stbla_01", "Black Street Male"},
    {"a_m_y_stbla_02", "Black Street Male 2"}, {"a_f_m_bodybuild_01", "Bodybuilder Female"},
    {"s_m_m_bouncer_01", "Bouncer"}, {"a_m_y_breakdance_01", "Breakdancer Male"}, {"csb_bride", "Bride(CS?)"},
    {"ig_bride", "Bride"}, {"csb_burgerdrug", "Burger Drug Worker(CS?)"}, {"u_m_y_burgerdrug_01", "Burger Drug Worker"},
    {"s_m_y_busboy_01", "Busboy"}, {"a_m_y_busicas_01", "Business Casual"}, {"a_f_m_business_02", "Business Female 2"},
    {"a_m_m_business_01", "Business Male"}, {"a_f_y_business_01", "Business Young Female"},
    {"a_f_y_business_02", "Business Young Female 2"}, {"a_f_y_business_03", "Business Young Female 3"},
    {"a_f_y_business_04", "Business Young Female 4"}, {"a_m_y_business_01", "Business Young Male"},
    {"a_m_y_business_02", "Business Young Male 2"}, {"a_m_y_business_03", "Business Young Male 3"},
    {"s_m_o_busker_01", "Busker"}, {"csb_car3guy1", "Car 3 Guy 1(CS)"}, {"ig_car3guy1", "Car 3 Guy 1"},
    {"csb_car3guy2", "Car 3 Guy 2(CS)"}, {"ig_car3guy2", "Car 3 Guy 2"}, {"cs_carbuyer", "Car Buyer(CS)"},
    {"s_m_m_chemsec_01", "Chemical Plant Security"}, {"g_m_m_chemwork_01", "Chemical Plant Worker"},
    {"g_m_m_chiboss_01", "Chinese Boss"}, {"g_m_m_chigoon_01", "Chinese Goon"}, {"csb_chin_goon", "Chinese Goon(CS?)"},
    {"g_m_m_chigoon_02", "Chinese Goon 2"}, {"g_m_m_chicold_01", "Chinese Goon Older"}, {"s_m_y_clown_01", "Clown"},
    {"s_m_y_construct_01", "Construction Worker"}, {"s_m_y_construct_02", "Construction Worker 2"},
    {"csb_cop", "Cop(CS?)"}, {"s_f_y_cop_01", "Cop Female"}, {"s_m_y_cop_01", "Cop Male"},
    {"u_f_m_corpse_01", "Corpse Female"}, {"u_f_y_corpse_01", "Corpse Young Female"},
    {"u_f_y_corpse_02", "Corpse Young Female 2"}, {"s_m_m_ccrew_01", "Crew Member"},
    {"cs_chrisformage", "Cris Formage(CS)"}, {"ig_chrisformage", "Cris Formage"}, {"csb_customer", "Customer"},
    {"a_m_y_cyclist_01", "Cyclist Male"}, {"u_m_y_cyclist_01", "Cyclist Male"}, {"mp_f_deadhooker", "Dead Hooker"},
    {"s_m_y_dealer_01", "Dealer"}, {"u_m_m_doa_01", "DOA Man"}, {"s_m_m_dockwork_01", "Dock Worker"},
    {"s_m_y_dockwork_01", "Dock Worker"}, {"s_m_m_doctor_01", "Doctor"}, {"s_m_y_doorman_01", "Doorman"},
    {"a_m_y_dhill_01", "Downhill Cyclist"}, {"a_f_m_downtown_01", "Downtown Female"},
    {"a_m_y_downtown_01", "Downtown Male"}, {"a_f_y_scdressy_01", "Dressy Female"},
    {"s_m_y_dwservice_01", "DW Airport Worker"}, {"s_m_y_dwservice_02", "DW Airport Worker 2"},
    {"a_f_m_eastsa_01", "East SA Female"}, {"a_f_m_eastsa_02", "East SA Female 2"}, {"a_m_m_eastsa_01", "East SA Male"},
    {"a_m_m_eastsa_02", "East SA Male 2"}, {"a_f_y_eastsa_01", "East SA Young Female"},
    {"a_f_y_eastsa_02", "East SA Young Female 2"}, {"a_f_y_eastsa_03", "East SA Young Female 3"},
    {"a_m_y_eastsa_01", "East SA Young Male"}, {"a_m_y_eastsa_02", "East SA Young Male 2"},
    {"a_f_y_epsilon_01", "Epsilon Female"}, {"a_m_y_epsilon_01", "Epsilon Male"},
    {"a_m_y_epsilon_02", "Epsilon Male 2"}, {"mp_m_exarmy_01", "Ex-Army Male"}, {"u_m_y_militarybum", "Ex-Mil Bum"},
    {"s_f_y_factory_01", "Factory Worker Female"}, {"s_m_y_factory_01", "Factory Worker Male"},
    {"g_m_y_famca_01", "Families CA Male"}, {"mp_m_famdd_01", "Families DD Male"},
    {"g_m_y_famdnf_01", "Families DNF Male"}, {"g_f_y_families_01", "Families Female"},
    {"g_m_y_famfor_01", "Families FOR Male"}, {"csb_ramp_gang", "Families Gang Member ?"},
    {"ig_ramp_gang", "Families Gang Member ?"}, {"a_m_m_farmer_01", "Farmer"}, {"a_f_m_fatbla_01", "Fat Black Female"},
    {"a_f_m_fatcult_01", "Fat Cult Female"}, {"a_m_m_fatlatin_01", "Fat Latino Male"},
    {"a_f_m_fatwhite_01", "Fat White Female"}, {"a_f_y_femaleagent", "Female Agent"},
    {"u_m_m_fibarchitect", "FIB Architect"}, {"u_m_y_fibmugger_01", "FIB Mugger"},
    {"s_m_m_fiboffice_01", "FIB Office Worker"}, {"s_m_m_fiboffice_02", "FIB Office Worker 2"},
    {"mp_m_fibsec_01", "FIB Security"}, {"s_m_m_fibsec_01", "FIB Security"}, {"cs_fbisuit_01", "FIB Suit(CS)"},
    {"ig_fbisuit_01", "FIB Suit"}, {"u_m_o_finguru_01", "Financial Guru"}, {"s_m_y_fireman_01", "Fireman Male"},
    {"a_f_y_fitness_01", "Fitness Female"}, {"a_f_y_fitness_02", "Fitness Female 2"}, {"csb_fos_rep", "FOS Rep ?"},
    {"s_m_m_gaffer_01", "Gaffer"}, {"s_m_y_garbage", "Garbage Worker"}, {"s_m_m_gardener_01", "Gardener"},
    {"a_m_y_gay_01", "Gay Male"}, {"a_m_y_gay_02", "Gay Male 2"}, {"a_m_m_genfat_01", "G Fat Male"},
    {"a_m_m_genfat_02", "G Fat Male 2"}, {"a_f_y_genhot_01", "G Hot Young Female"},
    {"a_f_o_genstreet_01", "G Street Old Female"}, {"a_m_o_genstreet_01", "G Street Old Male"},
    {"a_m_y_genstreet_01", "G Street Young Male"}, {"a_m_y_genstreet_02", "G Street Young Male 2"},
    {"u_m_m_glenstank_01", "Glenstank Male"}, {"a_m_m_golfer_01", "Golfer Male"},
    {"a_f_y_golfer_01", "Golfer Young Female"}, {"a_m_y_golfer_01", "Golfer Young Male"}, {"u_m_m_griff_01", "Griff"},
    {"s_m_y_grip_01", "Grip"}, {"csb_groom", "Groom(CS?)"}, {"ig_groom", "Groom"},
    {"csb_grove_str_dlr", "Grove Street Dealer(CS?)"}, {"u_m_y_guido_01", "Guido"}, {"u_m_y_gunvend_01", "Gun Vendor"},
    {"cs_gurk", "GURK ? (CS)"}, {"s_m_m_hairdress_01", "Hairdresser Male"}, {"a_m_m_hasjew_01", "Hasidic Jew Male"},
    {"a_m_y_hasjew_01", "Hasidic Jew Young Male"}, {"csb_ramp_hic", "Hick(CS?)"}, {"ig_ramp_hic", "Hick"},
    {"s_m_m_highsec_01", "High Security"}, {"s_m_m_highsec_02", "High Security 2"}, {"s_m_y_hwaycop_01", "Highway Cop"},
    {"a_f_y_hiker_01", "Hiker Female"}, {"a_m_y_hiker_01", "Hiker Male"}, {"a_m_m_hillbilly_01", "Hillbilly Male"},
    {"a_m_m_hillbilly_02", "Hillbilly Male 2"}, {"a_f_y_hippie_01", "Hippie Female"},
    {"u_m_y_hippie_01", "Hippie Male"}, {"a_m_y_hippy_01", "Hippie Male 2"}, {"csb_ramp_hipster", "Hipster(CS?)"},
    {"ig_ramp_hipster", "Hipster"}, {"a_f_y_hipster_01", "Hipster Female"}, {"a_f_y_hipster_02", "Hipster Female 2"},
    {"a_f_y_hipster_03", "Hipster Female 3"}, {"a_f_y_hipster_04", "Hipster Female 4"},
    {"a_m_y_hipster_01", "Hipster Male"}, {"a_m_y_hipster_02", "Hipster Male 2"},
    {"a_m_y_hipster_03", "Hipster Male 3"}, {"s_f_y_hooker_01", "Hooker"}, {"s_f_y_hooker_02", "Hooker 2"},
    {"s_f_y_hooker_03", "Hooker 3"}, {"s_f_y_scrubs_01", "Hospital Scrubs Female"},
    {"u_f_y_hotposh_01", "Hot Posh Female"}, {"cs_hunter", "Hunter(CS)"}, {"ig_hunter", "Hunter"},
    {"s_m_m_ciasec_01", "IAA Security"}, {"u_m_y_imporage", "Impotent Rage"}, {"a_m_m_indian_01", "Indian Male"},
    {"a_f_o_indian_01", "Indian Old Female"}, {"a_f_y_indian_01", "Indian Young Female"},
    {"a_m_y_indian_01", "Indian Young Male"}, {"csb_janitor", "Janitor"}, {"s_m_m_janitor", "Janitor"},
    {"u_m_o_taphillbilly", "Jesco White"}, {"u_m_m_jesus_01", "Jesus"}, {"a_m_y_jetski_01", "Jetskier"},
    {"hc_driver", "Jewel Heist Driver"}, {"hc_gunman", "Jewel Heist Gunman"}, {"hc_hacker", "Jewel Heist Hacker"},
    {"u_m_m_jewelthief", "Jewel Thief"}, {"u_f_y_jewelass_01", "Jeweler Assistant"},
    {"cs_jewelass", "Jeweler Assistant(CS)"}, {"ig_jewelass", "Jeweler Assistant"},
    {"u_m_m_jewelsec_01", "Jeweler Security"}, {"a_f_y_runner_01", "Jogger Female"}, {"a_m_y_runner_01", "Jogger Male"},
    {"a_m_y_runner_02", "Jogger Male 2"}, {"a_f_y_juggalo_01", "Juggalo Female"}, {"a_m_y_juggalo_01", "Juggalo Male"},
    {"u_m_y_baygor", "Kifflom Guy"}, {"g_m_m_korboss_01", "Korean Boss"}, {"a_f_m_ktown_01", "Korean Female"},
    {"a_f_m_ktown_02", "Korean Female 2"}, {"g_m_y_korlieut_01", "Korean Lieutenant"},
    {"a_m_m_ktown_01", "Korean Male"}, {"a_f_o_ktown_01", "Korean Old Female"}, {"a_m_o_ktown_01", "Korean Old Male"},
    {"g_m_y_korean_01", "Korean Young Male"}, {"a_m_y_ktown_01", "Korean Young Male"},
    {"g_m_y_korean_02", "Korean Young Male 2"}, {"a_m_y_ktown_02", "Korean Young Male 2"},
    {"s_m_m_lathandy_01", "Latino Handyman Male"}, {"a_m_m_stlat_02", "Latino Street Male 2"},
    {"a_m_y_stlat_01", "Latino Street Young Male"}, {"a_m_y_latino_01", "Latino Young Male"},
    {"cs_lifeinvad_01", "Life Invader(CS)"}, {"ig_lifeinvad_01", "Life Invader"}, {"ig_lifeinvad_02", "Life Invader 2"},
    {"s_m_m_lifeinvad_01", "Life Invader Male"}, {"s_m_m_linecook", "Line Cook"},
    {"u_m_m_willyfist", "Love Fist Willy"}, {"s_m_m_lsmetro_01", "LS Metro Worker Male"}, {"s_f_m_maid_01", "Maid"},
    {"a_m_m_malibu_01", "Malibu Male"}, {"u_m_y_mani", "Mani"}, {"s_m_m_mariachi_01", "Mariachi"},
    {"csb_ramp_marine", "Marine"}, {"s_m_m_marine_01", "Marine"}, {"s_m_m_marine_02", "Marine 2"},
    {"s_m_y_marine_01", "Marine Young"}, {"s_m_y_marine_02", "Marine Young 2"}, {"s_m_y_marine_03", "Marine Young 3"},
    {"s_m_y_xmech_01", "Mechanic"}, {"s_m_y_xmech_02", "Mechanic 2"}, {"csb_mweather", "Merryweather Merc"},
    {"a_m_y_methhead_01", "Meth Addict"}, {"csb_ramp_mex", "Mexican"}, {"ig_ramp_mex", "Mexican"},
    {"g_m_m_mexboss_01", "Mexican Boss"}, {"g_m_m_mexboss_02", "Mexican Boss 2"},
    {"g_m_y_mexgang_01", "Mexican Gang Member"}, {"g_m_y_mexgoon_01", "Mexican Goon"},
    {"g_m_y_mexgoon_02", "Mexican Goon 2"}, {"g_m_y_mexgoon_03", "Mexican Goon 3"},
    {"a_m_m_mexlabor_01", "Mexican Laborer"}, {"a_m_m_mexcntry_01", "Mexican Rural"},
    {"a_m_y_mexthug_01", "Mexican Thug"}, {"s_f_y_migrant_01", "Migrant Female"}, {"s_m_m_migrant_01", "Migrant Male"},
    {"s_m_y_mime", "Mime Artist"}, {"u_f_y_mistress", "Mistress"}, {"csb_money", "Money Man(CS)"},
    {"ig_money", "Money Man"}, {"a_m_y_motox_01", "Motocross Biker"}, {"a_m_y_motox_02", "Motocross Biker 2"},
    {"s_m_m_movspace_01", "Movie Astronaut"}, {"u_m_m_filmdirector", "Movie Director"},
    {"s_f_y_movprem_01", "Movie Premiere Female"}, {"cs_movpremf_01", "Movie Premiere Female(CS)"},
    {"s_m_m_movprem_01", "Movie Premiere Male"}, {"cs_movpremmale", "Movie Premiere Male(CS)"},
    {"u_f_o_moviestar", "Movie Star Female"}, {"a_m_m_og_boss_01", "OG Boss"}, {"cs_old_man1a", "Old Man 1 (CS)"},
    {"ig_old_man1a", "Old Man 1"}, {"cs_old_man2", "Old Man 2 (CS)"}, {"ig_old_man2", "Old Man 2"},
    {"a_m_m_paparazzi_01", "Paparazzi Male"}, {"u_m_y_paparazzi", "Paparazzi Young Male"},
    {"s_m_m_paramedic_01", "Paramedic"}, {"u_m_m_partytarget", "Party Target"}, {"u_m_y_party_01", "Partygoer"},
    {"s_m_y_pestcont_01", "Pest Control"}, {"s_m_m_pilot_01", "Pilot"}, {"s_m_y_pilot_01", "Pilot"},
    {"s_m_m_pilot_02", "Pilot 2"}, {"a_m_m_polynesian_01", "Polynesian"}, {"g_m_y_pologoon_01", "Polynesian Goon"},
    {"g_m_y_pologoon_02", "Polynesian Goon 2"}, {"a_m_y_polynesian_01", "Polynesian Young"},
    {"csb_porndudes", "Porn Dude"}, {"s_m_m_postal_01", "Postal Worker Male"},
    {"s_m_m_postal_02", "Postal Worker Male 2"}, {"cs_priest", "Priest(CS)"}, {"ig_priest", "Priest"},
    {"u_f_y_princess", "Princess"}, {"s_m_m_prisguard_01", "Prison Guard"}, {"s_m_y_prisoner_01", "Prisoner"},
    {"u_m_y_prisoner_01", "Prisoner"}, {"s_m_y_prismuscl_01", "Prisoner(Muscular)"},
    {"u_m_y_proldriver_01", "Prologue Driver"}, {"csb_prologuedriver", "Prologue Driver"},
    {"a_f_m_prolhost_01", "Prologue Female"}, {"a_m_m_prolhost_01", "Prologue Male"},
    {"u_f_o_prolhost_01", "Prologue Old Female"}, {"u_f_m_promourn_01", "Prologue Mourner Female"},
    {"u_m_m_promourn_01", "Prologue Mourner Male"}, {"csb_prolsec", "Prologue Security"},
    {"u_m_m_prolsec_01", "Prologue Security"}, {"cs_prolsec_02", "Prologue Security 2 (CS)"},
    {"ig_prolsec_02", "Prologue Security 2"}, {"mp_g_m_pros_01", "Pros"}, {"s_f_y_ranger_01", "Ranger Female"},
    {"s_m_y_ranger_01", "Ranger Male"}, {"csb_reporter", "Reporter"}, {"u_m_y_rsranger_01", "Republican Space Ranger"},
    {"u_m_m_rivalpap", "Rival Paparazzo"}, {"a_m_y_roadcyc_01", "Road Cyclist"}, {"s_m_y_robber_01", "Robber"},
    {"a_f_y_rurmeth_01", "Rural Methhead Female"}, {"a_m_m_rurmeth_01", "Rural Methhead Male"},
    {"cs_russiandrunk", "Russian Drunk(CS)"}, {"ig_russiandrunk", "Russian Drunk"},
    {"s_f_m_shop_high", "Sales Assistant(High-End)"}, {"s_f_y_shop_low", "Sales Assistant(Low-End)"},
    {"s_m_y_shop_mask", "Sales Assistant(Mask Stall)"}, {"s_f_y_shop_mid", "Sales Assistant(Mid-Range)"},
    {"a_f_m_salton_01", "Salton Female"}, {"a_m_m_salton_01", "Salton Male"}, {"a_m_m_salton_02", "Salton Male 2"},
    {"a_m_m_salton_03", "Salton Male 3"}, {"a_m_m_salton_04", "Salton Male 4"},
    {"a_f_o_salton_01", "Salton Old Female"}, {"a_m_o_salton_01", "Salton Old Male"},
    {"a_m_y_salton_01", "Salton Young Male"}, {"g_m_y_salvaboss_01", "Salvadoran Boss"},
    {"g_m_y_salvagoon_01", "Salvadoran Goon"}, {"g_m_y_salvagoon_02", "Salvadoran Goon 2"},
    {"g_m_y_salvagoon_03", "Salvadoran Goon 3"}, {"s_m_m_scientist_01", "Scientist"},
    {"csb_screen_writer", "Screenwriter"}, {"ig_screen_writer", "Screenwriter"},
    {"s_m_m_security_01", "Security Guard"}, {"s_f_y_sheriff_01", "Sheriff Female"},
    {"s_m_y_sheriff_01", "Sheriff Male"}, {"mp_m_shopkeep_01", "Shopkeeper"}, {"a_f_y_skater_01", "Skater Female"},
    {"a_m_m_skater_01", "Skater Male"}, {"a_m_y_skater_01", "Skater Young Male"},
    {"a_m_y_skater_02", "Skater Young Male 2"}, {"a_f_m_skidrow_01", "Skid Row Female"},
    {"a_m_m_skidrow_01", "Skid Row Male"}, {"s_m_m_snowcop_01", "Snow Cop Male"},
    {"a_f_m_soucent_01", "S Central Female"}, {"a_f_m_soucent_02", "S Central Female 2"},
    {"a_m_m_socenlat_01", "S Central Latino Male"}, {"a_m_m_soucent_01", "S Central Male"},
    {"a_m_m_soucent_02", "S Central Male 2"}, {"a_m_m_soucent_03", "S Central Male 3"},
    {"a_m_m_soucent_04", "S Central Male 4"}, {"a_f_m_soucentmc_01", "S Central MC Female"},
    {"a_f_o_soucent_01", "S Central Old Female"}, {"a_f_o_soucent_02", "S Central Old Female 2"},
    {"a_m_o_soucent_01", "S Central Old Male"}, {"a_m_o_soucent_02", "S Central Old Male 2"},
    {"a_m_o_soucent_03", "S Central Old Male 3"}, {"a_f_y_soucent_01", "S Central Young Female"},
    {"a_f_y_soucent_02", "S Central Young Female 2"}, {"a_f_y_soucent_03", "S Central Young Female 3"},
    {"a_m_y_soucent_01", "S Central Young Male"}, {"a_m_y_soucent_02", "S Central Young Male 2"},
    {"a_m_y_soucent_03", "S Central Young Male 3"}, {"a_m_y_soucent_04", "S Central Young Male 4"},
    {"u_m_y_sbike", "Sports Biker"}, {"u_m_m_spyactor", "Spy Actor"}, {"u_f_y_spyactress", "Spy Actress"},
    {"u_m_y_staggrm_01", "Stag Party Groom"}, {"s_m_m_strperf_01", "Street Performer"},
    {"s_m_m_strpreach_01", "Street Preacher"}, {"g_m_y_strpunk_01", "Street Punk"},
    {"g_m_y_strpunk_02", "Street Punk 2"}, {"s_m_m_strvend_01", "Street Vendor"},
    {"s_m_y_strvend_01", "Street Vendor Young"}, {"csb_stripper_01", "Stripper"}, {"s_f_y_stripper_01", "Stripper"},
    {"csb_stripper_02", "Stripper 2(CS?)"}, {"s_f_y_stripper_02", "Stripper 2"},
    {"s_f_y_stripperlite", "Stripper Lite"}, {"mp_f_stripperlite", "Stripper Lite"},
    {"a_m_y_sunbathe_01", "Sunbather Male"}, {"a_m_y_surfer_01", "Surfer"}, {"s_m_y_swat_01", "SWAT"},
    {"s_f_m_sweatshop_01", "Sweatshop Worker"}, {"s_f_y_sweatshop_01", "Sweatshop Worker Young"},
    {"u_m_y_tattoo_01", "Tattoo Artist"}, {"cs_tenniscoach", "Tennis Coach(CS)"}, {"ig_tenniscoach", "Tennis Coach"},
    {"a_f_y_tennis_01", "Tennis Player Female"}, {"a_m_m_tennis_01", "Tennis Player Male"},
    {"g_f_y_lost_01", "The Lost MC Female"}, {"g_m_y_lost_01", "The Lost MC Male"},
    {"g_m_y_lost_02", "The Lost MC Male 2"}, {"g_m_y_lost_03", "The Lost MC Male 3"},
    {"csb_trafficwarden", "Traffic Warden"}, {"ig_trafficwarden", "Traffic Warden"}, {"a_f_y_topless_01", "Topless"},
    {"a_f_m_tourist_01", "Tourist Female"}, {"a_m_m_tourist_01", "Tourist Male"},
    {"a_f_y_tourist_01", "Tourist Young Female"}, {"a_f_y_tourist_02", "Tourist Young Female 2"},
    {"a_f_m_tramp_01", "Tramp Female"}, {"a_m_m_tramp_01", "Tramp Male"}, {"u_m_o_tramp_01", "Tramp Old Male"},
    {"a_m_o_tramp_01", "Tramp Old Male"}, {"s_m_m_gentransport", "Transport Worker Male"},
    {"a_m_m_tranvest_01", "Transvestite Male"}, {"a_m_m_tranvest_02", "Transvestite Male 2"},
    {"s_m_m_trucker_01", "Trucker Male"}, {"csb_undercover", "Undercover Cop"}, {"cs_paper", "United Paper Man(CS)"},
    {"ig_paper", "United Paper Man"}, {"s_m_m_ups_01", "UPS Driver"}, {"s_m_m_ups_02", "UPS Driver 2"},
    {"s_m_y_uscg_01", "US Coastguard"}, {"g_f_y_vagos_01", "Vagos Female"}, {"s_m_y_valet_01", "Valet"},
    {"a_m_y_beachvesp_01", "Vespucci Beach Male"}, {"a_m_y_beachvesp_02", "Vespucci Beach Male 2"},
    {"a_m_y_vindouche_01", "Vinewood Douche"}, {"a_f_y_vinewood_01", "Vinewood Female"},
    {"a_f_y_vinewood_02", "Vinewood Female 2"}, {"a_f_y_vinewood_03", "Vinewood Female 3"},
    {"a_f_y_vinewood_04", "Vinewood Female 4"}, {"a_m_y_vinewood_01", "Vinewood Male"},
    {"a_m_y_vinewood_02", "Vinewood Male 2"}, {"a_m_y_vinewood_03", "Vinewood Male 3"},
    {"a_m_y_vinewood_04", "Vinewood Male 4"}, {"s_m_y_waiter_01", "Waiter"}, {"a_m_y_stwhi_01", "White Street Male"},
    {"a_m_y_stwhi_02", "White Street Male 2"}, {"s_m_y_winclean_01", "Window Cleaner"},
    {"a_f_y_yoga_01", "Yoga Female"}, {"a_m_y_yoga_01", "Yoga Male"},
    // 680
    {"u_m_y_zombie_01", "Zombie"}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""},
    {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""},
    // 700
    {"a_c_boar", "Boar"}, {"a_c_chimp", "Chimp"}, {"a_c_cow", "Cow"}, {"a_c_coyote", "Coyote"}, {"a_c_deer", "Deer"},
    {"a_c_fish", "Fish"}, {"a_c_hen", "Hen"}, {"a_c_cat_01", "Cat"}, {"a_c_chickenhawk", "Hawk"},
    {"a_c_cormorant", "Cormorant"}, {"a_c_crow", "Crow"}, {"a_c_dolphin", "Dolphin"}, {"a_c_humpback", "Humpback"},
    {"a_c_killerwhale", "Whale"}, {"a_c_pigeon", "Pigeon"}, {"a_c_seagull", "Seagull"},
    {"a_c_sharkhammer", "Hammerhead Shark"}, {"a_c_pig", "Pig"}, {"a_c_rat", "Rat"}, {"a_c_rhesus", "Rhesus"},
    // 720
    {"a_c_chop", "Chop"}, {"a_c_husky", "Husky"}, {"a_c_mtlion", "Mountain Lion"}, {"a_c_retriever", "Retriever"},
    {"a_c_sharktiger", "Tiger Shark"}, {"a_c_shepherd", "German Shepherd"},
    // 726
    {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""}, {"", ""},
    {"", ""}, {"", ""}, {"", ""}};  // 726+13

LPCSTR getModel(int index)
{
    if (index < 0 || index >= 740)
        return "";
    return pedModelData[index][0];
}

LPCSTR getModelName(int index)
{
    if (index < 0 || index >= 740)
        return "";
    return pedModelData[index][1];
}
