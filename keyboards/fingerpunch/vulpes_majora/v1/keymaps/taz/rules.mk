MACCEL_ENABLE ?= no
ifeq ($(strip $(MACCEL_ENABLE)), yes)
	include $(USER_PATH)/features/maccel/maccel/rules.mk
endif

AUDIO_ENABLE = yes
ENCODER_ENABLE = yes
FP_TRACKBALL_ENABLE = yes
RGBLIGHT_ENABLE = yes
