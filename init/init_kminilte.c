/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "G800F")) {
        /* kminiltexx */
        property_set("ro.build.fingerprint", "samsung/kminiltexx/kminilte:4.4.2/KOT49H/G800FXXU1ANL1:user/release-keys");
        property_set("ro.build.description", "kminiltexx-user 4.4.2 KOT49H G800FXXU1ANL1 release-keys");
        property_set("ro.product.model", "SM-G800F");
        property_set("ro.product.device", "kminiltexx");
    } else if (strstr(bootloader, "G800Y")) {
        /* kminiltedv */
        property_set("ro.build.fingerprint", "samsung/kminiltedv/kminilte:4.4.2/KOT49H/G800YDVU1ANG4:user/release-keys");
        property_set("ro.build.description", "kminiltedv-user 4.4.2 KOT49H G800YDVU1ANG4 release-keys");
        property_set("ro.product.model", "SM-G800Y");
        property_set("ro.product.device", "kminiltedv");
    } else if (strstr(bootloader, "G800M")) {
        /* kminilteub */
        property_set("ro.build.fingerprint", "samsung/kminilteub/kminilte:4.4.2/KOT49H/G800MUBU1ANH3:user/release-keys");
        property_set("ro.build.description", "kminilteub-user 4.4.2 KOT49H G800MUBU1ANH3 release-keys");
        property_set("ro.product.model", "SM-G800M");
        property_set("ro.product.device", "kminilteub");
    }
    
    property_get("ro.product.device", device);
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, device);
}
