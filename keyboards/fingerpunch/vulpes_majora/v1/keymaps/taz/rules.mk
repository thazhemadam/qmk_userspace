MACCEL_ENABLE ?= no
ifeq ($(strip $(MACCEL_ENABLE)), yes)
	include $(USER_PATH)/features/maccel/maccel/rules.mk
endif
