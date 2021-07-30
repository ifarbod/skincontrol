/* Mod Menu Implementation File v1.5 */
// NeutrinoBeam
//
//
// You may modify for use in your mods.
// The current version of this file will always be available with Mod Menu.

#pragma once

#include "modMenu.h"
#include <deque>
#include <string>

#pragma warning(disable : 4244 4305)

namespace MM
{
/* void isolateControls() */
void isolateControls()
{
    PLAYER::SET_PLAYER_CONTROL(PLAYER::PLAYER_ID(), 0, 0);
}

/* void isolateControlsExcludeCamera() */
void isolateControlsExcludeCamera()
{
    PLAYER::SET_PLAYER_CONTROL(PLAYER::PLAYER_ID(), 0, 256);
}

/* void resetControls() */
void resetControls()
{
    PLAYER::SET_PLAYER_CONTROL(PLAYER::PLAYER_ID(), 1, 0);
}

/* Input getInput() */
Input getInput()
{
    if ((CONTROLS::IS_CONTROL_PRESSED(2, MoveRight) | CONTROLS::IS_CONTROL_PRESSED(2, MenuRight)) != 0)
        return RIGHT;
    if ((CONTROLS::IS_CONTROL_PRESSED(2, MoveUp) | CONTROLS::IS_CONTROL_PRESSED(2, MenuUp)) != 0)
        return UP;
    if ((CONTROLS::IS_CONTROL_PRESSED(2, MoveLeft) | CONTROLS::IS_CONTROL_PRESSED(2, MenuLeft)) != 0)
        return LEFT;
    if ((CONTROLS::IS_CONTROL_PRESSED(2, MoveDown) | CONTROLS::IS_CONTROL_PRESSED(2, MenuDown)) != 0)
        return DOWN;
    if (CONTROLS::IS_CONTROL_JUST_RELEASED(2, Cancel) != 0)
        return BACK;
    if (CONTROLS::IS_CONTROL_JUST_RELEASED(2, ControllerRLeft) != 0)
        return OPTION;
    if ((CONTROLS::IS_CONTROL_JUST_RELEASED(2, Select) | CONTROLS::IS_DISABLED_CONTROL_JUST_RELEASED(2, Select)) != 0)
        return SELECT;  // changed in Mod Menu
    // if (CONTROLS::IS_CONTROL_JUST_RELEASED(2, Select) != 0) return SELECT;
    return NONE;
}

static Hex getRed(Color color)
{
    return (color >> 24) & 255;
}

static Hex getGreen(Color color)
{
    return (color >> 16) & 255;
}

static Hex getBlue(Color color)
{
    return (color >> 8) & 255;
}

static Hex getAlpha(Color color)
{
    return color & 255;
}

static Color getColor(Hex red, Hex green, Hex blue, Hex alpha)
{
    return (Color)alpha + ((Color)blue << 8) + ((Color)green << 16) + ((Color)red << 24);
}

/* void drawRect(float xPos, float yPos, float width, float height, Color backColor) */
void drawRect(float xPos, float yPos, float width, float height, Color backColor)
{
    GRAPHICS::DRAW_RECT(xPos + width * 0.5f, yPos + height * 0.5f, width, height, (int)getRed(backColor),
        (int)getGreen(backColor), (int)getBlue(backColor), (int)getAlpha(backColor));
}

/* void drawRect(float xPos, float yPos, float width, float height, Hex red, Hex green, Hex blue, Hex alpha) */
void drawRect(float xPos, float yPos, float width, float height, Hex red, Hex green, Hex blue, Hex alpha)
{
    GRAPHICS::DRAW_RECT(
        xPos + width * 0.5f, yPos + height * 0.5f, width, height, (int)red, (int)green, (int)blue, (int)alpha);
}

/* void drawRectWithText(std::string caption, float rectWidth, float vertPadding, float rectTop, float rectLeft, float
 * textLeft, bool center = false, Color textColor = 0xFFFFFFFF, float scale = 0.35, int font = 0, Color backColor =
 * 0x0000009B) */
void drawRectWithText(std::string caption, float rectWidth, float vertPadding, float rectTop, float rectLeft,
    float textLeft, bool center, Color textColor, float scale, int font, Color backColor)
{
    int screen_w, screen_h;
    GRAPHICS::GET_SCREEN_RESOLUTION(&screen_w, &screen_h);  // 1280x720 internally apparently
    float rectWidthScaled = rectWidth / (float)screen_w;
    float rectTopScaled = rectTop / (float)screen_h;
    float textLeftScaled = textLeft / (float)screen_w;
    float vertPaddingScaled = vertPadding / (float)screen_h;
    float rectLeftScaled = rectLeft / (float)screen_w;
    UI::SET_TEXT_FONT(font);
    UI::SET_TEXT_SCALE(0.0, scale);
    UI::SET_TEXT_COLOUR(
        (int)getRed(textColor), (int)getGreen(textColor), (int)getBlue(textColor), (int)getAlpha(textColor));
    if (center)
    {
        UI::SET_TEXT_CENTRE(1);
        textLeftScaled += 0.5 * rectWidthScaled;
    }
    else
    {
        UI::SET_TEXT_CENTRE(0);
    }
    UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
    UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
    UI::_SET_TEXT_ENTRY("STRING");
    UI::_ADD_TEXT_COMPONENT_STRING((char*)caption.c_str());
    UI::_DRAW_TEXT(rectLeftScaled + textLeftScaled, rectTopScaled + vertPaddingScaled - 0.00278);

    UI::_SET_TEXT_GXT_ENTRY("STRING");
    UI::_ADD_TEXT_COMPONENT_STRING((char*)caption.c_str());
    int num25 = UI::_0x9040DFB09BE75706(textLeftScaled, rectTopScaled + vertPaddingScaled - 0.00278);

    drawRect(rectLeftScaled, rectTopScaled, rectWidthScaled,
        (float)(num25)*UI::_0xDB88A37483346780(scale, 0) + vertPaddingScaled * 2, backColor);
}

void drawRectWithText(std::string caption, float rectWidth, float vertPadding, float rectTop, float rectLeft,
    Color textColor, Color backColor)
{
    drawRectWithText(caption, rectWidth, vertPadding, rectTop, rectLeft, 0.0f, true, textColor, 0.35, 0, backColor);
}

/* A stand in for Alexander Blade's implementation of the game default. */
void draw_menu_line(std::string caption, float rectWidth, float vertPadding, float rectTop, float rectLeft,
    float textLeft, bool active, bool title, bool rescaleText)
{
    Color text = 0xFFFFFFFF;
    Color rect = 0x465F5FFF;
    float scale = 0.35;
    int font = 0;
    if (active)
    {
        text = 0x000000FF;
        rect = 0xDAF2D8FF;
        if (rescaleText)
            scale = 0.40;
    }
    if (title)
    {
        rect = 0x000000FF;
        if (rescaleText)
            scale = 0.50;
        font = 1;
    }
    drawRectWithText(caption, rectWidth, vertPadding, rectTop, rectLeft, textLeft, false, text, scale, font, rect);
}

/* Puts a message up to 80 characters above the map. */
void notifyAboveMap(std::string msg)
{
    if (msg.size() > 81)
        msg = msg.substr(0, 80);
    char caption[80];
    strcpy_s(caption, msg.c_str());
    UI::_SET_NOTIFICATION_TEXT_ENTRY((char*)"STRING");
    UI::_ADD_TEXT_COMPONENT_STRING(caption);
    UI::_DRAW_NOTIFICATION(FALSE, FALSE);  // = DRAW ABOVE MAP
}

// Audio
std::deque<std::deque<const char*>> sounds = {
    {"none", "arm_3_car_glass_crash", "arm_3_pistol_cock", "arm_wrestling_whoosh_master",
        "bull_shark_testosterone_end_master", "bull_shark_testosterone_start_master", "chop_cam_a", "chop_cam_b",
        "chop_cam_c", "computers_mouse_click", "cop_heli_cam_background", "cop_heli_cam_bleep",
        "cop_heli_cam_bleep_too_far", "cop_heli_cam_scan_ped_failure", "cop_heli_cam_scan_ped_loop",
        "cop_heli_cam_scan_ped_success", "cop_heli_cam_turn", "cop_heli_cam_zoom",
        "cutscene_dialogue_override_sound_01", "cutscene_dialogue_override_sound_02",
        "drug_traffic_air_bomb_drop_error_master", "drug_traffic_air_screams", "exile_3_train_brake_pull_master",
        "exile_3_train_brake_release_master", "fbi_02_snatch_and_grab_amb_heli", "fbi_04_heat_c4_doors",
        "fbi_05_raid_breath", "freight_elevator_02_motor", "garage_door_scripted_close", "garage_door_scripted_open",
        "generic_alarm_electronic_01", "generic_alarm_fire_electronic", "golf_hud_hole_in_one_master",
        "golf_hud_scorecard_master", "hacking_click", "hacking_click_bad", "hacking_click_good",
        "hacking_countdown_crack_pass", "hacking_countdown_ip_find", "hacking_failure", "hacking_move_cursor",
        "hacking_success", "lamar1_partygirls_master", "martin1_distant_train_horns_master",
        "michael_sofa_remote_click_volume_master", "michael_sofa_tv_change_channel_master", "michael_sofa_tv_on_master",
        "hud_freemode_cancel_master", "net_race_start_event_master", "ps2a_distant_train_horns_master",
        "rampage_killed_counter_master", "rampage_killed_head_shot_master", "rampage_passed_master",
        "rampage_roar_master", "rampage_timer_countdown_loop_3_min_master", "rampage_timer_countdown_loop_master",
        "remote_sniper_rifle_fire", "remote_sniper_rifle_move", "remote_sniper_rifle_zoom", "scope_ui_master",
        "slipstream_master", "thermal_vision_goggles_on_master", "thermal_vision_goggles_off_master",
        "time_lapse_master", "timer_stop_master", "trevor_4_747_tv", "under_water_come_up", "uw_rebreather",
        "uw_ambience", "variable_countdown_clock_wp", "wooden_door_closed_at", "wooden_door_closing_at",
        "wooden_door_open_handle_at", "wooden_door_open_no_handle_at"},
    {"321_go_low_vol_soundset", "3_2_1", "go"}, {"assassination_multi", "assassinations_hotel_timer_countdown"},
    {"atm_sounds", "pin_button"}, {"barry_02_soundset", "hooray"},
    // 5
    {"basejumps_sounds", "grab_parachute"},
    {"big_score_3a_sounds", "traffic_control_bg_noise", "traffic_control_change_cam", "traffic_control_fail",
        "traffic_control_fail_blank", "traffic_control_light_switch_back", "traffic_control_move_crosshair",
        "traffic_control_toggle_light"},
    {"big_score_setup_sounds", "big_score_setup_sounds", "camera_zoom"}, {"bulldozerdefault", "diggerrevoneshot"},
    {"bustedsounds", "bed", "mp_flash", "mp_impact", "screenflash", "texthit"},
    // 10
    {"car_steal_2_soundset", "distant_dog_bark", "thermal_off", "thermal_on"},
    {"cb_radio_sfx", "background_loop", "end_squelch", "start_squelch"},
    {"celebration_soundset", "round_ending_stinger_custom", "screen_swipe"},
    {"construction_accident_1_sounds", "cable_snaps", "pipes_land", "weaken", "wind"},
    {"dlc_heist_fleeca_soundset", "drill_pin_break"},
    // 15
    {"dlc_heist_biolab_prep_hacking_sounds", "hack_failed", "hack_success", "pin_bad", "pin_centred", "pin_good",
        "pin_movement"},
    {"dlc_heist_hacking_snake_sounds", "background", "beep_green", "beep_red", "click", "crash", "failure", "goal",
        "lester_laugh_phone", "power_down", "start", "success", "trail_custom", "turn"},
    {"dlc_heist_planning_board_sounds", "continue_accepted", "highlight_accept", "highlight_cancel", "highlight_error",
        "highlight_move", "map_roll_down", "map_roll_up", "paper_shuffle", "pen_tick", "zoom_in", "zoom_left",
        "zoom_out", "zoom_right"},
    {"dlc_heists_biolab_finale_sounds", "emp_blast"}, {"dlc_heists_failed_screen_sounds", "pre_screen_stinger"},
    // 20
    {"dlc_heists_finale_screen_sounds", "pre_screen_stinger"},
    {"dlc_heists_general_frontend_sounds", "5_second_timer", "local_plyr_cash_counter_complete",
        "local_plyr_cash_counter_increase", "mission_pass_notify", "nav_arrow_ahead", "nav_arrow_behind",
        "nav_arrow_left", "nav_arrow_right", "on_call_player_join", "out_of_bounds_timer",
        "remote_plyr_cash_counter_complete", "remote_plyr_cash_counter_increase"},
    {"dlc_heists_generic_sounds", "payment_non_player", "payment_player"},
    {"dlc_heists_prep_screen_sounds", "pre_screen_stinger"}, {"dlc_pilot_chase_parachute_sounds", "grab_chute_foley"},
    // 25
    {"dlc_pilot_mp_hud_sounds", "player_collect"}, {"dlc_prison_break_heist_sounds", "bus_schedule_pickup"},
    {"docks_heist_finale_2b_sounds", "door_open"}, {"door_garage", "opened", "opening"},
    {"exile_1", "altitude_warning", "falling_crates"},
    // 30
    {"family1_boat", "family_1_car_breakdown", "family_1_car_breakdown_additional"},
    {"family_5_sounds", "drugs_aliens", "drugs_chimps", "drugs_heartbeat", "flying_stream_end_instant",
        "michael_long_scream"},
    {"fbi_heist_finale_chopper", "heli_crash"},
    {"gtao_apt_door_downstairs_glass_sounds", "limit", "push", "swing_shut"}, {"gtao_mugshot_room_sounds", "lights_on"},
    // 35
    {"heist_bulletin_board_soundset", "marker_erase", "person_scroll", "person_select", "undo"},
    {"hintcamsounds", "focusin", "focusout"},
    {"hud_ammo_shop_soundset", "back", "error", "nav", "weapon_purchase", "weapon_select_armor", "weapon_select_other"},
    {"hud_awards", "base_jump_passed", "challenge_unlocked", "collected", "flight_school_lesson_passed", "golf_birdie",
        "golf_eagle", "golf_new_record", "loser", "medal_bronze", "medal_gold", "medal_silver", "other_text",
        "peyote_completed", "property_purchase", "race_placed", "rank_up", "shooting_range_round_over",
        "sign_destroyed", "tennis_match_point", "tennis_point_won", "under_the_bridge", "win"},
    {"hud_deathmatch_soundset", "add_spawn_point", "delete", "edit", "place_checkpoint", "place_enemy", "place_object",
        "place_pickup", "place_vehicle", "place_weapon", "select_location", "select_start_grid_position"},
    // 40
    {"hud_freemode_soundset", "back", "cancel", "nav_up_down", "nav_left_right", "select"},
    {"hud_frontend_clothesshop_soundset", "cancel", "error", "nav_up_down", "select"},
    {"hud_frontend_custom_soundset", "pick_up_weapon", "robbery_money_total"},
    {"hud_frontend_default_soundset", "10_sec_warning", "atm_window", "back", "cancel", "character_", "continue",
        "continuous_slider", "error", "exit", "highlight", "highlight_nav_up_down", "horde_cool_down_timer",
        "leader_board", "medal_up", "mp_5_second_timer", "mp_award", "mp_idle_kick", "mp_idle_timer", "mp_rank_up",
        "mp_wave_complete", "multiplier_increase", "nav_up_down", "nav_left_right", "no", "ok", "pick_up", "quit",
        "restart", "retry", "select", "skip", "timer", "timer_stop", "toggle_on", "yes"},
    {"hud_frontend_mp_collectable_sounds", "deliver_pick_up", "dropped", "enemy_deliver", "enemy_pick_up",
        "friend_deliver", "friend_pick_up"},
    // 45
    {"hud_frontend_mp_soundset", "select"},
    {"hud_frontend_tattoo_shop_soundset", "back", "error", "nav_up_down", "purchase"},
    {"hud_frontend_weapons_pickups_soundset", "pickup_weapon_ball", "pickup_weapon_smokegrenade"},
    {"hud_liquor_store_soundset", "cancel", "error", "nav_up_down", "select", "purchase"},
    {"hud_mini_game_soundset", "10_sec_warning", "3_2_1", "3_2_1_non_race", "5_sec_warning", "back", "cam_pan_darts",
        "cancel", "checkpoint_ahead", "checkpoint_behind", "checkpoint_missed", "checkpoint_normal",
        "checkpoint_perfect", "checkpoint_under_the_bridge", "confirm_beep", "first_place", "go", "go_non_race",
        "leaderboard", "leader_board", "loose_match", "medal_up", "multiplier_increase", "nav_up_down", "select",
        "timer_stop", "quit_whoosh"},
    // 50
    {"hud_minigame_soundset", "phone_generic_key_02", "phone_generic_key_03"},
    {"hud_mission_creator_soundset", "add_spawn_point", "delete", "edit", "place_checkpoint", "place_enemy",
        "place_object", "place_pickup", "place_vehicle", "place_weapon", "select_location",
        "select_start_grid_position"},
    {"hud_property_soundset", "property_purchase_large", "property_purchase_medium", "property_purchase_small"},
    {"hud_race_creator_soundset", "add_spawn_point", "delete", "edit", "place_checkpoint", "place_enemy",
        "place_object", "place_pickup", "place_vehicle", "place_weapon", "select_location",
        "select_start_grid_position"},
    {"lester1a_sounds", "close_window", "finding_virus", "lester1a_sounds"},
    // 55
    {"long_player_switch_sounds", "hit_1"}, {"minute_man_01_soundset", "stun_collect"},
    {"missionfailedsounds", "bed", "screenflash", "texthit"},
    {"mp_cctv_soundset", "background", "change_cam", "pan", "zoom"},
    {"mp_lobby_sounds", "boats_planes_helis_boom", "car_bike_whoosh", "whoosh_1s_l_to_r", "whoosh_1s_r_to_l"},
    // 56
    {"mp_mission_countdown_soundset", "10s", "5s", "oneshot_final"}, {"mp_player_apartment", "door_buzz"},
    {"mp_properties_elevator_doors", "closed", "closing", "opened", "opening"},
    {"mp_radio_sfx", "off_high", "off_low", "on_high", "on_low", "retune_high", "retune_low"},
    {"mp_snacks_soundset", "knuckle_crack_hard_cel", "knuckle_crack_slap_cel", "slow_clap_cel"},
    // 60
    {"noir_filter_sounds", "loop", "on", "off"}, {"paleto_score_2a_bank_ss", "ps2a_money_lost"},
    {"paparazzo_02_soundsets", "zoom"},
    {"phone_soundset_default", "camera_shoot", "camera_zoom", "dial_and_remote_ring", "hang_up", "menu_accept",
        "menu_back", "menu_navigate", "notification", "pull_out", "put_away", "remote_engaged", "remote_ring",
        "text_arrive_tone"},
    {"phone_soundset_franklin", "camera_shoot", "camera_zoom", "dial_and_remote_ring", "hang_up", "menu_accept",
        "menu_back", "menu_navigate", "notification", "pull_out", "put_away", "remote_engaged", "remote_ring",
        "text_arrive_tone"},
    // 65
    {"phone_soundset_glasses_cam", "background_sound", "camera_shoot", "camera_zoom"},
    {"phone_soundset_michael", "camera_shoot", "camera_zoom", "dial_and_remote_ring", "hang_up", "menu_accept",
        "menu_back", "menu_navigate", "notification", "pull_out", "put_away", "remote_engaged", "remote_ring",
        "text_arrive_tone"},
    {"phone_soundset_prologue", "camera_shoot", "camera_zoom", "dial_and_remote_ring", "hang_up", "menu_accept",
        "menu_back", "menu_navigate", "notification", "pull_out", "put_away", "remote_engaged", "remote_ring",
        "text_arrive_tone"},
    {"phone_soundset_trevor", "camera_shoot", "camera_zoom", "dial_and_remote_ring", "hang_up", "menu_accept",
        "menu_back", "menu_navigate", "notification", "pull_out", "put_away", "remote_engaged", "remote_ring",
        "text_arrive_tone"},
    {"player_switch_custom_soundset", "1st_person_transition", "camera_move_loop", "hit_in", "hit_out",
        "short_transition_in", "short_transition_out"},
    // 70
    {"police_chopper_cam_sounds", "found_target", "lost_target", "microphone"},
    {"radio_soundset", "change_station_loud"}, {"respawn_online_soundset", "faster_bar_full", "faster_click", "hit"},
    {"respawn_soundset", "hit", "whoosh"}, {"rope_cut_soundset", "rope_cut"},
    // 75
    {"safe_crack_soundset", "safe_door_close", "safe_door_open", "tumbler_pin_fall", "tumbler_pin_fall_final",
        "tumbler_reset", "tumbler_turn"},
    {"short_player_switch_sound_set", "all", "in", "out"},
    {"special_ability_soundset", "switchredwarning", "switchwhitewarning"},
    {"tattooist_sounds", "tattooing_oneshot", "tattooing_oneshot_remove"}, {"truck_ramp_down", "ramp_down", "ramp_up"},
    // 80
    {"wastedsounds", "bed", "mp_flash", "mp_impact", "screenflash", "texthit"},
    {"web_navigation_sounds_phone", "click_back", "click_fail", "click_special"}};

void menu_beep()
{
    //AUDIO::PLAY_SOUND_FRONTEND(-1, sounds[44][22], sounds[44][0], 0);
}

void playSound(DWORD collection, DWORD sound)
{
    //AUDIO::PLAY_SOUND_FRONTEND(-1, sounds.at(collection).at(sound + 1), sounds.at(collection).at(0), 0);
}
}
