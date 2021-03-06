/******************************************************************************
 *
 *  Copyright (C) 2011-2013 Broadcom Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/


/******************************************************************************
 *
 *  This file contains compile-time configurable constants for NFA modules
 *
 ******************************************************************************/
#include "nfa_api.h"

/* the SetConfig for CE T3T/T4T */
const UINT8 nfa_dm_ce_cfg[] =
{
    13,                         /* total length */
    NFC_PMID_LF_T3T_PMM,        /* Type-3 tag default PMM */
    NCI_PARAM_LEN_LF_T3T_PMM,
    0x20,
    0x79,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    NFC_PMID_FWI,               /* FWI for ISO-DEP */
    1,
    CE_T4T_ISO_DEP_FWI
};

UINT8 *p_nfa_dm_ce_cfg = (UINT8 *) nfa_dm_ce_cfg;

/* the SetConfig for optional general NFC stack functions */
const UINT8 nfa_dm_gen_cfg[] =
{
    3,                         /* total length */
    NFC_PMID_RF_FIELD_INFO,     /* Instruct NFCC to report RF field generated by remote device (or not) */
    1,
    0x01
};

UINT8 *p_nfa_dm_gen_cfg = NULL;


/* the RF Discovery Frequency for each technology */
const tNFA_DM_DISC_FREQ_CFG nfa_dm_rf_disc_freq_cfg =
{
    1,      /* Frequency for NFC Technology A               */
    1,      /* Frequency for NFC Technology B               */
    1,      /* Frequency for NFC Technology F               */
    1,      /* Frequency for Proprietary Technology/15693   */
    1,      /* Frequency for Proprietary Technology/B-Prime */
    1,      /* Frequency for Proprietary Technology/Kovio   */
    1,      /* Frequency for NFC Technology A active mode   */
    1       /* Frequency for NFC Technology F active mode   */
};

tNFA_DM_DISC_FREQ_CFG *p_nfa_dm_rf_disc_freq_cfg = (tNFA_DM_DISC_FREQ_CFG *)&nfa_dm_rf_disc_freq_cfg;

UINT8 nfa_ee_max_ee_cfg = NFA_EE_MAX_EE_SUPPORTED;


const tNCI_DISCOVER_MAPS nfa_dm_interface_mapping[NFA_DM_NUM_INTERFACE_MAP] =
{
    /* Protocols that use Frame Interface do not need to be included in the interface mapping */
    {
        NCI_PROTOCOL_ISO_DEP,
        NCI_INTERFACE_MODE_POLL_N_LISTEN,
        NCI_INTERFACE_ISO_DEP
    },
    {
        NCI_PROTOCOL_NFC_DEP,
        NCI_INTERFACE_MODE_POLL_N_LISTEN,
        NCI_INTERFACE_NFC_DEP
    }
};
/* set to NULL to use the default mapping set by stack */
tNCI_DISCOVER_MAPS *p_nfa_dm_interface_mapping = NULL;
UINT8 nfa_dm_num_dm_interface_mapping = 0;


const tNFA_DM_CFG nfa_dm_cfg =
{
    NFA_DM_AUTO_DETECT_NDEF,                /* Automatic NDEF detection (when not in exclusive RF mode) */
    NFA_DM_AUTO_READ_NDEF                   /* Automatic NDEF read (when not in exclusive RF mode)      */

};

tNFA_DM_CFG *p_nfa_dm_cfg = (tNFA_DM_CFG *) &nfa_dm_cfg;


const tNFA_HCI_CFG nfa_hci_cfg =
{
    NFA_HCI_NETWK_INIT_IDLE_TIMEOUT, /* Max HCI Network IDLE time to wait for EE DISC REQ Ntf(s) */
    NFA_HCI_RESPONSE_TIMEOUT         /* Maximum HCP Response time to any HCP Command */
};

tNFA_HCI_CFG *p_nfa_hci_cfg = (tNFA_HCI_CFG *) &nfa_hci_cfg;
