const int LED = 10;//set led pin from D10
const int LDR = A0;//set photo cell pin from A0

int inputval = 0; //values variable to be read from A0
int outputval = 0;//output value variable



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);//mode:led as output
  pinMode(LDR, INPUT);//mode:photo cell data as input
}

void loop() {
  // put your main code here, to run repeatedly: 
  Serial.println(inputval);//printing input value the photo cell receives 
  inputval = analogRead(LDR); //set input val variable to reading values from photo cell
  outputval = map(inputval, 0, 100, 255, 0);//map (inputval,fromLow,fromHigh,toLow,toHigh)  

  int lightval = constrain(outputval, 0,255);//constrains output value to be within 0 and 255 for led
  analogWrite(LED, lightval);  //led brightness changes based on input
  delay (100);

}
