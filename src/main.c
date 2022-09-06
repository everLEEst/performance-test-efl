#define _CRT_SECURE_NO_WARNINGS    // strcpy 보안 경고로 인한 컴파일 에러 방지

#include <Elementary.h>
#include <appcore-efl.h>
#include "main.h"
#include <stdio.h>
#include <string.h>    // strcat 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일


#define PAGE_W 1080
#define PAGE_H 620


void create_laundry_card(appdata *ad, char* title, char *dur, float weight, Eina_Bool icon)
{
   char buf[128];
   char buf2[128];
   Evas_Object *card = elm_box_add(ad->win);
   evas_object_size_hint_weight_set(card, weight, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(card, EVAS_HINT_FILL, EVAS_HINT_FILL);
   evas_object_show(card);
	elm_box_horizontal_set(card, EINA_TRUE);

   Evas_Object *title_label = elm_label_add(card);
	evas_object_size_hint_weight_set(title_label, EVAS_HINT_EXPAND, 0);
	evas_object_size_hint_align_set(title_label, EVAS_HINT_FILL, 0);
   sprintf(buf, "%s,%s%s", "<font_size=30><align=center>", title, "</align></font_size>");
   elm_object_text_set(title_label, buf);
	evas_object_show(title_label);
	elm_box_pack_end(card, title_label);

   Evas_Object *dur_label = elm_label_add(card);
	evas_object_size_hint_weight_set(dur_label, EVAS_HINT_EXPAND, 0);
	evas_object_size_hint_align_set(dur_label, EVAS_HINT_FILL, 0);
   sprintf(buf2, "%s,%s%s", "<font_size=20><align=center>", dur, "</align></font_size>");
   elm_object_text_set(dur_label, buf2);
	evas_object_show(dur_label);
	elm_box_pack_end(card, dur_label);

   if (icon)
   {
      //add icon here
   }

   elm_box_pack_end(ad->laundryview, card);
}


void create_dryer_card(appdata *ad, char* title, char *dur, float progress, Eina_Bool is_started)
{
   Evas_Object *card = elm_box_add(ad->win);
   evas_object_size_hint_weight_set(card, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(card, EVAS_HINT_FILL, EVAS_HINT_FILL);
   evas_object_show(card);
	elm_box_horizontal_set(card, EINA_FALSE);

   char buf[128];
   char buf2[128];

   Evas_Object *title_label = elm_label_add(card);
	evas_object_size_hint_weight_set(title_label, EVAS_HINT_EXPAND, 0);
	evas_object_size_hint_align_set(title_label, EVAS_HINT_FILL, 0);
   sprintf(buf, "%s,%s%s", "<font_size=30><align=center>", title, "</align></font_size>");
   elm_object_text_set(title_label, buf);
	evas_object_show(title_label);
	elm_box_pack_end(card, title_label);


   Evas_Object *dur_progress_box = elm_box_add(card);
   evas_object_size_hint_weight_set(dur_progress_box, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(dur_progress_box, EVAS_HINT_FILL, EVAS_HINT_FILL);
   evas_object_show(dur_progress_box);
	elm_box_horizontal_set(dur_progress_box, EINA_TRUE);

   if (dur_progress_box != NULL)
   {
      Evas_Object *dur_label = elm_label_add(dur_progress_box);
      evas_object_size_hint_weight_set(dur_label, EVAS_HINT_EXPAND, 0);
      evas_object_size_hint_align_set(dur_label, EVAS_HINT_FILL, 0);
      sprintf(buf2, "%s,%s%s", "<font_size=20><align=center>", dur, "</align></font_size>");
      elm_object_text_set(dur_label, buf2);
      evas_object_show(dur_label);
      elm_box_pack_end(dur_progress_box, dur_label);

      //Evas_Object *playicon = elm_image_add(dur_progress_box);
   }
	elm_box_pack_end(card, dur_progress_box);

   Evas_Object *progressbar =  elm_progressbar_add(card);
	evas_object_size_hint_align_set(progressbar, EVAS_HINT_FILL, 0.5);
	evas_object_size_hint_weight_set(progressbar, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	elm_progressbar_value_set(progressbar, progress);
	evas_object_show(progressbar);
	elm_box_pack_end(card, progressbar);

   elm_box_pack_end(ad->dryerview, card);
}

void create_content(appdata *ad)
{
	/* Create Scroller */
   ad->contentview = elm_scroller_add(ad->rootview);
	elm_scroller_loop_set(ad->contentview, EINA_FALSE, EINA_FALSE);
	evas_object_size_hint_weight_set(ad->contentview, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(ad->contentview, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_scroller_page_relative_set(ad->contentview, 1.0, 0.0);
	elm_scroller_policy_set(ad->contentview, ELM_SCROLLER_POLICY_OFF, ELM_SCROLLER_POLICY_OFF);
	elm_scroller_page_scroll_limit_set(ad->contentview, 1, 0);
	elm_object_scroll_lock_y_set(ad->contentview, EINA_TRUE);
	elm_scroller_page_size_set(ad->contentview, PAGE_W, PAGE_H);
	//evas_object_smart_callback_add(ad->contentview, "scroll", scroller_scroll_cb, pd);

	/* Create Scroller Box */
   Evas_Object *contentbox = elm_box_add(ad->contentview);
   evas_object_size_hint_weight_set(contentbox, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(contentbox, EVAS_HINT_FILL, EVAS_HINT_FILL);
   evas_object_show(contentbox);
	elm_box_horizontal_set(contentbox, EINA_TRUE);
	elm_object_content_set(ad->contentview, contentbox);

	/* Create Laundry view */
   ad->laundryview = elm_box_add(contentbox);
	elm_box_horizontal_set(ad->laundryview, EINA_TRUE);
   evas_object_size_hint_min_set(ad->laundryview, PAGE_W, PAGE_H);
   elm_box_pack_end(contentbox, ad->laundryview);
   elm_box_padding_set(ad->laundryview, 10, 0);
   evas_object_show(ad->laundryview);

   create_laundry_card(ad, "AI 맞춤세탁", "1시간 50분", 0.5, EINA_TRUE);
   create_laundry_card(ad, "표준세탁", "59분", 0.25, EINA_FALSE);
   create_laundry_card(ad, "펫케어세탁", "2시간 30분", 0.25, EINA_FALSE);

	/* Create Dryer view */
   ad->dryerview = elm_box_add(contentbox);
	elm_box_horizontal_set(ad->dryerview, EINA_FALSE);
   evas_object_size_hint_min_set(ad->dryerview, PAGE_W, PAGE_H);
   elm_box_pack_end(contentbox, ad->dryerview);
   elm_box_padding_set(ad->dryerview, 10, 0);
   evas_object_show(ad->dryerview);

   create_dryer_card(ad, "표준 건조", "1시간 20분", 0.35, EINA_TRUE);
   create_dryer_card(ad, "AI 건조", "2시간 00분", 0.0, EINA_FALSE);

   elm_box_pack_end(ad->rootview, ad->contentview);
}

void create_tapbar(appdata *ad)
{
   /* Create box container for buttons. tapbar is not supported in some platforms */
   Evas_Object *box = elm_box_add(ad->rootview);
   evas_object_size_hint_weight_set(box, EVAS_HINT_EXPAND, 0);
   evas_object_size_hint_align_set(box, EVAS_HINT_FILL, 0);
   evas_object_show(box);
	elm_box_horizontal_set(box, EINA_TRUE);
	elm_object_content_set(ad->rootview, box);


   Evas_Object *laundrybtn = elm_button_add(box);
   evas_object_size_hint_weight_set(laundrybtn, 0.0, 0.0);
   evas_object_size_hint_align_set(laundrybtn, 1.0, 0.5);
   elm_object_text_set(laundrybtn, "세탁기");
   //evas_object_smart_callback_add(laundrybtn, "clicked", _laundrybtn_cb, ad);
   elm_box_pack_end(box, laundrybtn);
   evas_object_show(laundrybtn);

   Evas_Object *dryerbtn = elm_button_add(box);
   evas_object_size_hint_weight_set(dryerbtn, 0.0, 0.0);
   evas_object_size_hint_align_set(dryerbtn, 1.0, 0.5);
   elm_object_text_set(dryerbtn, "건조기");
   //evas_object_smart_callback_add(dryerbtn, "clicked", _dryerbtn_cb, ad);
   elm_box_pack_end(box, dryerbtn);
   evas_object_show(dryerbtn);

   elm_box_pack_end(ad->rootview, box);
}

void app_init(appdata *ad)
{
   Evas_Object *win, *bg;

   //elm_theme_overlay_add(NULL, BODER_EDJ);
   //elm_policy_set(ELM_POLICY_QUIT, ELM_POLICY_QUIT_LAST_WINDOW_CLOSED);

	/* Window */
	ad->win = elm_win_util_standard_add("performance-test-efl", "performance-test-efl");
	elm_win_conformant_set(ad->win, EINA_TRUE);
	elm_win_autodel_set(ad->win, EINA_TRUE);

   /* Background */
   bg = elm_bg_add(win);
   elm_bg_color_set(bg, 0, 0, 0);
   evas_object_size_hint_weight_set(bg, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(bg, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_win_resize_object_add(win, bg);
   evas_object_show(bg);

   ad->rootview = elm_box_add(ad->win);
   evas_object_size_hint_weight_set(ad->rootview, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(ad->rootview, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_win_resize_object_add(ad->win, ad->rootview);
   evas_object_show(ad->rootview);

   create_tapbar(ad);
   create_content(ad);

   //evas_object_resize(win, 400, 300);
   //evas_object_move(win, 100, 100);
   evas_object_show(win);
}

bool app_create(void *userdata)
{
   appdata *ad = userdata;

   app_init(ad);

   return true;
}

void app_terminate(void *user_data)
{
}

int main(int argc, char **argv)
{
   appdata app;
   memset(&app, 0, sizeof(app));

   struct appcore_ops ops = {
        .data = &app,
        .create = app_create,
        .terminate = app_terminate,
        .pause = NULL,
        .resume = NULL,
        .reset = NULL,
   };
   return appcore_efl_main("performance-test-efl", &argc, &argv, &ops);
}

