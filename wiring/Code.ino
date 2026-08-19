#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// =====================================================
// OLED
// =====================================================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// =====================================================
// MODE
// =====================================================

bool demo_mode = true;

const int MAX_ANIMATION_INDEX = 8;
int current_animation_index = 0;

// =====================================================
// KONFIGURASI MATA
// =====================================================

const int REF_EYE_HEIGHT = 40;
const int REF_EYE_WIDTH = 40;
const int REF_SPACE_BETWEEN_EYE = 10;
const int REF_CORNER_RADIUS = 10;

// Posisi mata
int left_eye_x = 39;
int left_eye_y = 32;

int right_eye_x = 89;
int right_eye_y = 32;

// Ukuran mata
int left_eye_width = REF_EYE_WIDTH;
int left_eye_height = REF_EYE_HEIGHT;

int right_eye_width = REF_EYE_WIDTH;
int right_eye_height = REF_EYE_HEIGHT;


// =====================================================
// DRAW EYES
// =====================================================

void draw_eyes(bool update = true)
{
  display.clearDisplay();

  // -------------------------
  // Mata kiri
  // -------------------------

  int x = left_eye_x - left_eye_width / 2;
  int y = left_eye_y - left_eye_height / 2;

  display.fillRoundRect(
    x,
    y,
    left_eye_width,
    left_eye_height,
    REF_CORNER_RADIUS,
    SSD1306_WHITE
  );

  // -------------------------
  // Mata kanan
  // -------------------------

  x = right_eye_x - right_eye_width / 2;
  y = right_eye_y - right_eye_height / 2;

  display.fillRoundRect(
    x,
    y,
    right_eye_width,
    right_eye_height,
    REF_CORNER_RADIUS,
    SSD1306_WHITE
  );

  if (update)
  {
    display.display();
  }
}


// =====================================================
// CENTER EYES
// =====================================================

void center_eyes(bool update = true)
{
  left_eye_width = REF_EYE_WIDTH;
  right_eye_width = REF_EYE_WIDTH;

  left_eye_height = REF_EYE_HEIGHT;
  right_eye_height = REF_EYE_HEIGHT;

  left_eye_x =
    SCREEN_WIDTH / 2
    - REF_EYE_WIDTH / 2
    - REF_SPACE_BETWEEN_EYE / 2;

  right_eye_x =
    SCREEN_WIDTH / 2
    + REF_EYE_WIDTH / 2
    + REF_SPACE_BETWEEN_EYE / 2;

  left_eye_y = SCREEN_HEIGHT / 2;
  right_eye_y = SCREEN_HEIGHT / 2;

  draw_eyes(update);
}


// =====================================================
// BLINK
// =====================================================

void blink(int speed = 10)
{
  // Tutup
  for (int h = REF_EYE_HEIGHT; h >= 2; h -= speed)
  {
    left_eye_height = h;
    right_eye_height = h;

    draw_eyes();
    delay(25);
  }

  // Pastikan benar-benar tertutup
  left_eye_height = 2;
  right_eye_height = 2;

  draw_eyes();
  delay(40);

  // Buka
  for (int h = 2; h <= REF_EYE_HEIGHT; h += speed)
  {
    left_eye_height = h;
    right_eye_height = h;

    draw_eyes();
    delay(25);
  }

  center_eyes();
}


// =====================================================
// SLEEP
// =====================================================

void sleep_eyes()
{
  left_eye_height = 2;
  right_eye_height = 2;

  draw_eyes();
}


// =====================================================
// WAKE UP
// =====================================================

void wakeup()
{
  sleep_eyes();

  for (int h = 2; h <= REF_EYE_HEIGHT; h += 2)
  {
    left_eye_height = h;
    right_eye_height = h;

    draw_eyes();
    delay(20);
  }

  center_eyes();
}


// =====================================================
// HAPPY EYES
// =====================================================

void happy_eye()
{
  center_eyes(false);

  display.clearDisplay();

  // =================================================
  // Mata kiri dibuat seperti lengkungan senyum
  // =================================================

  int leftX = left_eye_x;
  int rightX = right_eye_x;

  int eyeTop = 17;
  int eyeBottom = 47;

  // Mata kiri
  display.fillTriangle(
    leftX - 20,
    eyeBottom,
    leftX + 20,
    eyeBottom,
    leftX,
    eyeTop,
    SSD1306_WHITE
  );

  // Mata kanan
  display.fillTriangle(
    rightX - 20,
    eyeBottom,
    rightX + 20,
    eyeBottom,
    rightX,
    eyeTop,
    SSD1306_WHITE
  );

  // Tutup bagian bawah sehingga bentuk lebih seperti mata senyum
  display.fillRect(
    leftX - 21,
    eyeBottom,
    42,
    20,
    SSD1306_BLACK
  );

  display.fillRect(
    rightX - 21,
    eyeBottom,
    42,
    20,
    SSD1306_BLACK
  );

  display.display();

  delay(600);

  center_eyes();
}


// =====================================================
// SACCADE
// =====================================================

void saccade(int direction_x, int direction_y)
{
  const int X_AMPLITUDE = 7;
  const int Y_AMPLITUDE = 5;

  // Simpan posisi
  int oldLeftX = left_eye_x;
  int oldRightX = right_eye_x;
  int oldLeftY = left_eye_y;
  int oldRightY = right_eye_y;

  // Bergerak
  left_eye_x += direction_x * X_AMPLITUDE;
  right_eye_x += direction_x * X_AMPLITUDE;

  left_eye_y += direction_y * Y_AMPLITUDE;
  right_eye_y += direction_y * Y_AMPLITUDE;

  draw_eyes();
  delay(60);

  // Kembali
  left_eye_x = oldLeftX;
  right_eye_x = oldRightX;

  left_eye_y = oldLeftY;
  right_eye_y = oldRightY;

  draw_eyes();
}


// =====================================================
// MOVE BIG EYE
// =====================================================

void move_big_eye(int direction)
{
  const int MOVE_AMOUNT = 2;
  const int EXTRA_SIZE = 2;

  // Bergerak
  for (int i = 0; i < 5; i++)
  {
    left_eye_x += direction * MOVE_AMOUNT;
    right_eye_x += direction * MOVE_AMOUNT;

    if (direction > 0)
    {
      right_eye_width += 1;
      right_eye_height += 1;
    }
    else
    {
      left_eye_width += 1;
      left_eye_height += 1;
    }

    draw_eyes();
    delay(30);
  }

  delay(300);

  // Kembali
  for (int i = 0; i < 5; i++)
  {
    left_eye_x -= direction * MOVE_AMOUNT;
    right_eye_x -= direction * MOVE_AMOUNT;

    if (direction > 0)
    {
      right_eye_width -= 1;
      right_eye_height -= 1;
    }
    else
    {
      left_eye_width -= 1;
      left_eye_height -= 1;
    }

    draw_eyes();
    delay(30);
  }

  center_eyes();
}


void move_right_big_eye()
{
  move_big_eye(1);
}


void move_left_big_eye()
{
  move_big_eye(-1);
}


// =====================================================
// RANDOM SACCADE
// =====================================================

void random_saccade()
{
  center_eyes();

  for (int i = 0; i < 10; i++)
  {
    int dir_x = random(-1, 2);
    int dir_y = random(-1, 2);

    saccade(dir_x, dir_y);

    delay(80);
  }

  center_eyes();
}


// =====================================================
// JALANKAN ANIMASI
// =====================================================

void launch_animation_with_index(int animation_index)
{
  // Pastikan index valid
  if (
    animation_index < 0 ||
    animation_index > MAX_ANIMATION_INDEX
  )
  {
    animation_index = 0;
  }

  switch (animation_index)
  {
    // -------------------------------------------------
    // A0 = WAKE UP
    // -------------------------------------------------

    case 0:
      wakeup();
      break;


    // -------------------------------------------------
    // A1 = CENTER
    // -------------------------------------------------

    case 1:
      center_eyes();
      delay(300);
      break;


    // -------------------------------------------------
    // A2 = BIG EYE RIGHT
    // -------------------------------------------------

    case 2:
      move_right_big_eye();
      break;


    // -------------------------------------------------
    // A3 = BIG EYE LEFT
    // -------------------------------------------------

    case 3:
      move_left_big_eye();
      break;


    // -------------------------------------------------
    // A4 = BLINK
    // -------------------------------------------------

    case 4:
      blink(8);
      break;


    // -------------------------------------------------
    // A5 = FAST BLINK
    // -------------------------------------------------

    case 5:
      blink(15);
      break;


    // -------------------------------------------------
    // A6 = HAPPY
    // -------------------------------------------------

    case 6:
      happy_eye();
      break;


    // -------------------------------------------------
    // A7 = SLEEP
    // -------------------------------------------------

    case 7:
      sleep_eyes();
      delay(500);
      break;


    // -------------------------------------------------
    // A8 = RANDOM SACCADE
    // -------------------------------------------------

    case 8:
      random_saccade();
      break;
  }
}


// =====================================================
// SERIAL COMMAND
// =====================================================

void process_serial()
{
  if (!Serial.available())
  {
    return;
  }

  String data = Serial.readStringUntil('\n');

  data.trim();

  if (data.length() == 0)
  {
    return;
  }

  char cmd = data.charAt(0);

  // =================================================
  // A0 - A8
  // =================================================

  if (cmd == 'A' || cmd == 'a')
  {
    demo_mode = false;

    String arg = data.substring(1);
    arg.trim();

    int animation = arg.toInt();

    Serial.print(F("Animation: "));
    Serial.println(animation);

    launch_animation_with_index(animation);
  }

  // =================================================
  // D = DEMO
  // =================================================

  else if (cmd == 'D' || cmd == 'd')
  {
    demo_mode = true;

    Serial.println(F("Demo mode ON"));
  }

  // =================================================
  // C = CENTER
  // =================================================

  else if (cmd == 'C' || cmd == 'c')
  {
    demo_mode = false;

    center_eyes();

    Serial.println(F("Eyes centered"));
  }

  // =================================================
  // S = SLEEP
  // =================================================

  else if (cmd == 'S' || cmd == 's')
  {
    demo_mode = false;

    sleep_eyes();

    Serial.println(F("Eyes sleeping"));
  }

  // =================================================
  // W = WAKE
  // =================================================

  else if (cmd == 'W' || cmd == 'w')
  {
    demo_mode = false;

    wakeup();

    Serial.println(F("Eyes awake"));
  }
}


// =====================================================
// SETUP
// =====================================================

void setup()
{
  Serial.begin(115200);

  // -------------------------------------------------
  // I2C
  // -------------------------------------------------

  Wire.begin();

  // -------------------------------------------------
  // OLED
  // -------------------------------------------------

  if (!display.begin(
        SSD1306_SWITCHCAPVCC,
        SCREEN_ADDRESS
      ))
  {
    Serial.println(F("OLED gagal diinisialisasi!"));

    while (true)
    {
      delay(1000);
    }
  }

  // -------------------------------------------------
  // Random seed
  // -------------------------------------------------

  randomSeed(analogRead(A0));

  // -------------------------------------------------
  // Splash screen
  // -------------------------------------------------

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.println(F("EYE ANIMATION"));

  display.setCursor(0, 15);
  display.println(F("SSD1306 128x64"));

  display.setCursor(0, 30);
  display.println(F("Starting..."));

  display.display();

  delay(1500);

  // -------------------------------------------------
  // Sleep
  // -------------------------------------------------

  sleep_eyes();

  delay(700);

  // -------------------------------------------------
  // Wake up
  // -------------------------------------------------

  wakeup();
}


// =====================================================
// LOOP
// =====================================================

void loop()
{
  // -------------------------------------------------
  // Serial selalu diperiksa
  // -------------------------------------------------

  process_serial();

  // -------------------------------------------------
  // Demo mode
  // -------------------------------------------------

  if (demo_mode)
  {
    launch_animation_with_index(
      current_animation_index
    );

    current_animation_index++;

    if (
      current_animation_index >
      MAX_ANIMATION_INDEX
    )
    {
      current_animation_index = 0;
    }
  }
}