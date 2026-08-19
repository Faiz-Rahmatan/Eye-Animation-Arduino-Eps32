{
  "version": 1,
  "symbols": [
    {
      "id": "oled-128x64-mszrtv89",
      "type": "reg:oled-128x64",
      "ref": "U2",
      "x": 18,
      "y": 17,
      "rotation": 0,
      "mirror": false
    },
    {
      "id": "arduino-nano-v3-mszs6ugw",
      "type": "reg:arduino-nano-v3",
      "ref": "U2",
      "x": 18,
      "y": 17,
      "rotation": 0,
      "mirror": false
    }
  ],
  "wires": [
    {
      "id": "bbs_w_0",
      "points": [
        {
          "x": 24,
          "y": 29
        },
        {
          "x": 12,
          "y": 29
        },
        {
          "x": 12,
          "y": 16
        }
      ],
      "net": "0"
    },
    {
      "id": "bbs_w_1",
      "points": [
        {
          "x": 12,
          "y": 16
        },
        {
          "x": 44,
          "y": 16
        },
        {
          "x": 44,
          "y": 53
        },
        {
          "x": 12,
          "y": 53
        },
        {
          "x": 12,
          "y": 25
        }
      ],
      "net": "0"
    },
    {
      "id": "bbs_w_2",
      "points": [
        {
          "x": 24,
          "y": 31
        },
        {
          "x": 12,
          "y": 31
        },
        {
          "x": 12,
          "y": 18
        }
      ],
      "net": "VIN"
    },
    {
      "id": "bbs_w_3",
      "points": [
        {
          "x": 24,
          "y": 19
        },
        {
          "x": 44,
          "y": 19
        },
        {
          "x": 44,
          "y": 33
        },
        {
          "x": 76,
          "y": 33
        },
        {
          "x": 76,
          "y": 16
        },
        {
          "x": 24,
          "y": 16
        }
      ],
      "net": "N_A5"
    },
    {
      "id": "bbs_w_4",
      "points": [
        {
          "x": 24,
          "y": 17
        },
        {
          "x": 79,
          "y": 17
        },
        {
          "x": 79,
          "y": 18
        },
        {
          "x": 24,
          "y": 18
        }
      ],
      "net": "N_A4"
    }
  ],
  "junctions": [
    {
      "id": "j_12_29",
      "x": 12,
      "y": 29
    },
    {
      "id": "j_12_25",
      "x": 12,
      "y": 25
    }
  ],
  "netLabels": [
    {
      "id": "bbs_nl_0",
      "name": "GND",
      "x": 24,
      "y": 29,
      "owner": "arduino-nano-v3-mszs6ugw",
      "anchor": "start"
    },
    {
      "id": "bbs_nl_1",
      "name": "VIN",
      "x": 24,
      "y": 31,
      "owner": "arduino-nano-v3-mszs6ugw",
      "anchor": "start"
    },
    {
      "id": "bbs_nl_2",
      "name": "N_A5",
      "x": 24,
      "y": 19,
      "owner": "arduino-nano-v3-mszs6ugw",
      "anchor": "start"
    },
    {
      "id": "bbs_nl_3",
      "name": "N_A4",
      "x": 24,
      "y": 17,
      "owner": "arduino-nano-v3-mszs6ugw",
      "anchor": "start"
    }
  ],
  "probes": [],
  "directives": [],
  "breadboardSync": {
    "sourceHash": "6951:1998159893",
    "symbolIds": [
      "oled-128x64-mszrtv89",
      "arduino-nano-v3-mszs6ugw"
    ],
    "wireIds": [
      "bbs_w_0",
      "bbs_w_1",
      "bbs_w_2",
      "bbs_w_3",
      "bbs_w_4"
    ],
    "netLabelIds": [
      "bbs_nl_0",
      "bbs_nl_1",
      "bbs_nl_2",
      "bbs_nl_3"
    ]
  }
}