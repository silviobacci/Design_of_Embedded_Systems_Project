function WI(block)
% Level-2 M file S-Function for interface demo.
%   Copyright 1990-2004 The MathWorks, Inc.
%   $Revision: 1.1.6.1 $ 

  setup(block);
  
%endfunction

function setup(block)
  global timebutton
  global timesetbutton
  global alarmbutton
  global plusbutton
  global minusbutton
  global swatchbutton
  global alarmOnOff
  global ringing
  global counterRings;
  global counterBlinks;
  global PERIOD;
  
 %% global alarmOnOff

  %% Register dialog parameters: No parameters for this block 
  block.NumDialogPrms = 0;
  %% Register number of input and output ports
  block.NumInputPorts  = 9;
  block.NumOutputPorts  = 7;


  %% Setup functional port properties to dynamically
  %% inherited.
  block.SetPreCompInpPortInfoToDynamic;                    % port inherits sample rates

  %% Input 1 is for hours
  block.InputPort(1).Complexity   = 'Real'; 
  block.InputPort(1).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(1).SamplingMode = 'Sample';
  block.InputPort(1).Dimensions   = 1;
  block.InputPort(1).DirectFeedthrough   = 0;

  %% Input 2 is for minutes
  block.InputPort(2).Complexity   = 'Real'; 
  block.InputPort(2).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(2).SamplingMode = 'Sample';
  block.InputPort(2).Dimensions   = 1;
  block.InputPort(2).DirectFeedthrough   = 0;

  %% Input 3 is for seconds
  block.InputPort(3).Complexity   = 'Real'; 
  block.InputPort(3).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(3).SamplingMode = 'Sample';
  block.InputPort(3).Dimensions   = 1;
  block.InputPort(3).DirectFeedthrough   = 0;

  %% Input 4 is for tenths
  block.InputPort(4).Complexity   = 'Real'; 
  block.InputPort(4).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(4).SamplingMode = 'Sample';
  block.InputPort(4).Dimensions   = 1;
  block.InputPort(4).DirectFeedthrough   = 0;

  %% Input 5 is for mode
  block.InputPort(5).Complexity   = 'Real'; 
  block.InputPort(5).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(5).SamplingMode = 'Sample';
  block.InputPort(5).Dimensions   = 1;
  block.InputPort(5).DirectFeedthrough   = 0;
  
  %% Input 5 is for mode
  block.InputPort(6).Complexity   = 'Real'; 
  block.InputPort(6).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(6).SamplingMode = 'Sample';
  block.InputPort(6).Dimensions   = 1;
  block.InputPort(6).DirectFeedthrough   = 0;
  
  block.InputPort(7).Complexity   = 'Real'; 
  block.InputPort(7).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(7).SamplingMode = 'Sample';
  block.InputPort(7).Dimensions   = 1;
  block.InputPort(7).DirectFeedthrough   = 0;
  
  block.InputPort(8).Complexity   = 'Real'; 
  block.InputPort(8).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(8).SamplingMode = 'Sample';
  block.InputPort(8).Dimensions   = 1;
  block.InputPort(8).DirectFeedthrough   = 0;
  
  block.InputPort(9).Complexity   = 'Real'; 
  block.InputPort(9).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(9).SamplingMode = 'Sample';
  block.InputPort(9).Dimensions   = 1;
  block.InputPort(9).DirectFeedthrough   = 0;

  %% Setup functional port properties to dynamically
  %% inherited.
  block.SetPreCompOutPortInfoToDynamic;

  block.OutputPort(1).Complexity   = 'Real'; 
  block.OutputPort(1).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(1).SamplingMode = 'Sample';
  block.OutputPort(1).Dimensions   = 1;

  block.OutputPort(2).Complexity   = 'Real'; 
  block.OutputPort(2).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(2).SamplingMode = 'Sample';
  block.OutputPort(2).Dimensions   = 1;

  block.OutputPort(3).Complexity   = 'Real'; 
  block.OutputPort(3).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(3).SamplingMode = 'Sample';
  block.OutputPort(3).Dimensions   = 1;

  block.OutputPort(4).Complexity   = 'Real'; 
  block.OutputPort(4).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(4).SamplingMode = 'Sample';
  block.OutputPort(4).Dimensions   = 1;

  block.OutputPort(5).Complexity   = 'Real'; 
  block.OutputPort(5).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(5).SamplingMode = 'Sample';
  block.OutputPort(5).Dimensions   = 1;

  block.OutputPort(6).Complexity   = 'Real'; 
  block.OutputPort(6).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(6).SamplingMode = 'Sample';
  block.OutputPort(6).Dimensions   = 1;
  
  block.OutputPort(7).Complexity   = 'Real'; 
  block.OutputPort(7).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(7).SamplingMode = 'Sample';
  block.OutputPort(7).Dimensions   = 1;

  %% Register methods
  block.RegBlockMethod('SetInputPortSamplingMode',@SetInputPortSamplingMode);
  block.RegBlockMethod('Start',                   @Start);  
  %   block.RegBlockMethod('WriteRTW',                @WriteRTW);
  block.RegBlockMethod('Outputs',                 @Outputs);

  timebutton = 0;
  timesetbutton = 0;
  alarmbutton = 0;
  plusbutton = 0;
  minusbutton = 0;
  swatchbutton = 0;
  alarmOnOff = 0;
  ringing = 0;
  PERIOD = 500;
  counterRings = 0;
  counterBlinks = 0;
  
  %endfunction

 function SetInputPortSamplingMode(block, idx, fd)
   block.InputPort(idx).SamplingMode = fd;

function ButtonDown(hObj,evnt)
   global timebutton
   global timesetbutton
   global alarmbutton
   global plusbutton
   global minusbutton
   global swatchbutton
   global alarmOnOff
 

  pos = get(hObj,'CurrentPoint');

  if ((pos(2) > 240-(186+43)) && (pos(2) < 240-186) && (pos(1) > 30) && (pos(1) < (30+42)))
            timebutton=1;
  end;
  if ((pos(2) > 240-(186+43)) && (pos(2) < 240-186) && (pos(1) > 98) && (pos(1) < (98+42)))
            timesetbutton=1;
  end;
  if ((pos(2) > 240-(186+43)) && (pos(2) < 240-186) && (pos(1) > 169) && (pos(1) < (169+42)))
            alarmbutton=1;
  end;
  if ((pos(2) > 240-(186+43)) && (pos(2) < 240-186) && (pos(1) > 244) && (pos(1) < (244+42)))
            swatchbutton=1;
  end;
  if ((pos(2) > 240-(56+40)) && (pos(2) < 240-58) && (pos(1) > 250) && (pos(1) < (250+40)))
            plusbutton=1;
  end;
  if ((pos(2) > 240-(110+40)) && (pos(2) < 240-110) && (pos(1) > 250) && (pos(1) < (250+40)))
           minusbutton = 1;
  end;
  if ((pos(2) > 240-(20+20)) && (pos(2) < 240-20) && (pos(1) > 135) && (pos(1) < (135+50)))
            alarmOnOff = 1;
  end;

function ButtonUp(hObj,evnt)
   global timebutton
   global timesetbutton
   global alarmbutton
   global plusbutton
   global minusbutton
   global swatchbutton
   global alarmOnOff
 

  pos = get(hObj,'CurrentPoint');

  if ((pos(2) > 240-(186+43)) && (pos(2) < 240-186) && (pos(1) > 30) && (pos(1) < (30+42)))
            timebutton=0;
  end;
  if ((pos(2) > 240-(186+43)) && (pos(2) < 240-186) && (pos(1) > 98) && (pos(1) < (98+42)))
            timesetbutton=0;
  end;
  if ((pos(2) > 240-(186+43)) && (pos(2) < 240-186) && (pos(1) > 169) && (pos(1) < (169+42)))
            alarmbutton=0;
  end;
  if ((pos(2) > 240-(186+43)) && (pos(2) < 240-186) && (pos(1) > 244) && (pos(1) < (244+42)))
            swatchbutton=0;
  end;
  if ((pos(2) > 240-(56+40)) && (pos(2) < 240-58) && (pos(1) > 250) && (pos(1) < (250+40)))
            plusbutton=0;
  end;
  if ((pos(2) > 240-(110+40)) && (pos(2) < 240-110) && (pos(1) > 250) && (pos(1) < (250+40)))
            minusbutton=0;
  end;
  if ((pos(2) > 240-(20+20)) && (pos(2) < 240-20) && (pos(1) > 135) && (pos(1) < (135+50)))
            alarmOnOff = 0;
  end;


function Start(block) 

  global IM
  global FH
  global timemode_hnd;
  global timesetmode_hnd;
  global alarmsetmode_hnd;
  global swatchmode_hnd;
  global alarmOn_hnd;
  global alarmOff_hnd;

  global hrs_digits;
  global min_digits;
  global sec_digits;
  global ten_digits;
 
  global timemode;
  global timesetmode;
  global alarmsetmode;
  global swatchmode;
  global alarmOn;
  global alarmOff;

  global sep2;
  global sep3;

  IM = imread('images/orologio.png');
  timemode = imread('images/timeON.png');
  timesetmode = imread('images/timesetON.png');
  alarmsetmode = imread('images/alarmON.png');
  swatchmode = imread('images/swatchON.png');
  alarmOn = imread('images/ON.png');
  alarmOff = imread('images/OFF.png');

  bhD = @ButtonDown;
  bhU = @ButtonUp;

% background image 

  FH = figure('Toolbar', 'none', 'Menubar', 'none', 'Name', 'Figname', 'WindowButtonDownFcn', bhD, 'WindowButtonUpFcn', bhU, 'Resize', 'off');
  scrsz = get(0,'ScreenSize');
  set(FH, 'Units','pixels');
  set(FH, 'Position',[1 scrsz(4)-500 320 240]);
  hax = axes('Units', 'pixels', 'Position', [1, 1, 320, 240], 'Visible', 'off');
  image(IM)
  axis off

% text output 

% skipping Arial
  hrs_digits = text(32, 240-90,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 16);
  set(hrs_digits, 'Color',[1 1 1]); %white
  set(hrs_digits, 'VerticalAlignment','top');
  set(hrs_digits, 'FontName', 'Arial');

  sep1 = text(70, 240-90,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 16);
  set(sep1, 'Color',[1 1 1]);
  set(sep1, 'VerticalAlignment','top');
  set(sep1, 'FontName', 'Arial');
  set(sep1, 'string', ':');

  min_digits = text(90, 240-90,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 16);
  set(min_digits, 'Color',[1 1 1]);
  set(min_digits, 'VerticalAlignment','top');
  set(min_digits, 'FontName', 'Arial');

  sep2 = text(128, 240-90,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 16);
  set(sep2, 'Color',[1 1 1]);
  set(sep2, 'VerticalAlignment','top');
  set(sep2, 'FontName', 'Arial');
  set(sep2, 'string', ':');

  sec_digits = text(148, 240-90,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 16);
  set(sec_digits, 'Color',[1 1 1]);
  set(sec_digits, 'VerticalAlignment','top');
  set(sec_digits, 'FontName', 'Arial');

  sep3 = text(186, 240-90,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 16);
  set(sep3, 'Color',[1 1 1]);
  set(sep3, 'VerticalAlignment','top');
  set(sep3, 'FontName', 'Arial');
  set(sep3, 'string', '.');

  ten_digits = text(206, 240-90,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 16);
  set(ten_digits, 'Color',[1 1 1]);
  set(ten_digits, 'VerticalAlignment','top');
  set(ten_digits, 'FontName', 'Arial');

  hax = axes('Units', 'pixels', 'Position', [30, 240-185-43, 42, 43], 'Visible', 'off');
  timemode_hnd = image(timemode, 'Visible', 'off');
  axis off;
  hax = axes('Units', 'pixels', 'Position', [98, 240-185-43, 42, 43], 'Visible', 'off');
  timesetmode_hnd = image(timesetmode, 'Visible', 'off');
  axis off;
  hax = axes('Units', 'pixels', 'Position', [169, 240-185-43, 42, 43], 'Visible', 'off');
  alarmsetmode_hnd = image(alarmsetmode, 'Visible', 'off');
  axis off;
  hax = axes('Units', 'pixels', 'Position', [244, 240-185-43, 42, 43], 'Visible', 'off');
  swatchmode_hnd = image(swatchmode, 'Visible', 'off');
  axis off;
  hax = axes('Units', 'pixels', 'Position', [135, 240-20-20, 50, 20], 'Visible', 'off');
  alarmOn_hnd = image(alarmOn, 'Visible', 'off');
  axis off;
  hax = axes('Units', 'pixels', 'Position', [135, 240-20-20, 50, 20], 'Visible', 'off');
  alarmOff_hnd = image(alarmOff, 'Visible', 'off');
  axis off;

%endfunction

function con_str = convertDto2S(dig)
  shw_val = mod(dig, 100);
  con_str = int2str(shw_val);
  if shw_val < 10 
      con_str = strcat('0',con_str);
  end
%endfunction

function con_str = convertDto1S(dig)
  shw_val = mod(dig, 10);
  con_str = int2str(shw_val);
%endfunction

    function Outputs(block)
  
   global timebutton
   global timesetbutton
   global alarmbutton
   global plusbutton
   global minusbutton
   global swatchbutton
   global alarmOnOff
 
   global timemode_hnd;
   global timesetmode_hnd;
   global alarmsetmode_hnd;
   global swatchmode_hnd;
   global alarmOn_hnd;
   global alarmOff_hnd;
 
   global hrs_digits;
   global min_digits;
   global sec_digits;
   global ten_digits;
 
   global sep2;
   global sep3;
   
   global counterRings;
   global counterBlinks;
   global PERIOD;   

%Update graphics based on input ports

 if boolean(plusbutton) == true || boolean(minusbutton) == true || boolean(timebutton) == true || boolean(timesetbutton) == true|| boolean(alarmbutton) == true|| boolean(swatchbutton) == true || boolean(alarmOnOff) == true
     counterBlinks = 0;
 end;
 
%% Need to transform block.InputPort(1).Data value into string of 2 chars
 if block.InputPort(8).Data == false
   set(hrs_digits, 'Visible', 'on')
 end;
  set(hrs_digits, 'string',  convertDto2S(block.InputPort(1).Data))
%% Need to transform block.InputPort(2).Data value into string of 2 chars
  if block.InputPort(9).Data == false
    set(min_digits, 'Visible', 'on')
  end;
  set(min_digits, 'string', convertDto2S(block.InputPort(2).Data))
%% Need to transform block.InputPort(3).Data value into string of 2 chars
%% Attention!! display is on only if mode is time or stopwatch
  if (block.InputPort(5).Data == 3) || (block.InputPort(5).Data == 0) 
    set(sec_digits, 'Visible', 'on')
    set(sec_digits, 'string', convertDto2S(block.InputPort(3).Data))
    set(sep2, 'Visible', 'on')
  else
    set(sec_digits, 'Visible', 'off')
    set(sep2, 'Visible', 'off')
  end;
%% Need to transform block.InputPort(4).Data value into string of 1 char
%% Attention!! display is on only if mode is stopwatch
  if block.InputPort(5).Data == 3  
    set(ten_digits, 'Visible', 'on')
    set(ten_digits, 'string', convertDto1S(block.InputPort(4).Data))
    set(sep3, 'Visible', 'on')
  else
    set(ten_digits, 'Visible', 'off')
    set(sep3, 'Visible', 'off')
  end;
  
  if block.InputPort(5).Data == 0 
      set(timemode_hnd, 'Visible', 'on')
  else
      set(timemode_hnd, 'Visible', 'off')
  end;

  if block.InputPort(5).Data == 1 
      set(timesetmode_hnd, 'Visible', 'on')
      if block.InputPort(6).Data == true
        set(min_digits, 'Visible', 'on')
        if(counterBlinks == 2*PERIOD)
            counterBlinks = 0;
        end;
        if counterBlinks >= PERIOD
            set(hrs_digits, 'Visible', 'off')
        else 
            set(hrs_digits, 'Visible', 'on')
        end;
        counterBlinks = counterBlinks+1;
      end;
      if block.InputPort(7).Data == true
        set(hrs_digits, 'Visible', 'on')
        if(counterBlinks == 2*PERIOD)
            counterBlinks = 0;
        end;
        if counterBlinks >= PERIOD
            set(min_digits, 'Visible', 'off')
        else 
            set(min_digits, 'Visible', 'on')
        end;
        counterBlinks = counterBlinks+1;
      end;
  else
      set(timesetmode_hnd, 'Visible', 'off')
  end;

  if block.InputPort(5).Data == 2
      if block.InputPort(9).Data == false
        set(alarmsetmode_hnd, 'Visible', 'on')
      end;
      
      if block.InputPort(8).Data == false
        set(alarmOn_hnd, 'Visible', 'off')
        set(alarmOff_hnd, 'Visible', 'on')  
      else
        set(alarmOff_hnd, 'Visible', 'off')
        set(alarmOn_hnd, 'Visible', 'on')
      end;
      
      if block.InputPort(6).Data == true
        set(min_digits, 'Visible', 'on')
        if(counterBlinks == 2*PERIOD)
            counterBlinks = 0;
        end;
        if counterBlinks >= PERIOD
            set(hrs_digits, 'Visible', 'off')
        else 
            set(hrs_digits, 'Visible', 'on')
        end;
        counterBlinks = counterBlinks+1;
      end;
      if block.InputPort(7).Data == true
        set(hrs_digits, 'Visible', 'on')
        if(counterBlinks == 2*PERIOD)
            counterBlinks = 0;
        end;
        if counterBlinks >= PERIOD
            set(min_digits, 'Visible', 'off')
        else 
            set(min_digits, 'Visible', 'on')
        end;
        counterBlinks = counterBlinks+1;
      end;
  else
      if block.InputPort(9).Data == false
        set(alarmsetmode_hnd, 'Visible', 'off')
      end;
      set(alarmOn_hnd, 'Visible', 'off')
      set(alarmOff_hnd, 'Visible', 'off')
  end;

  if block.InputPort(5).Data == 3 
      set(swatchmode_hnd, 'Visible', 'on')
  else
      set(swatchmode_hnd, 'Visible', 'off')
  end;
  
  if block.InputPort(9).Data == true
        if(counterRings == 2*PERIOD)
            counterRings = 0;
        end;
        if counterRings >= PERIOD
           set(alarmsetmode_hnd, 'Visible', 'off')
        else 
           set(alarmsetmode_hnd, 'Visible', 'on')
        end;
        counterRings = counterRings+1;
  else
      counterRings = 0;
  end;
 
%Update output ports

  block.OutputPort(1).Data = boolean(plusbutton);   % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(2).Data = boolean(minusbutton);   % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(3).Data = boolean(timebutton);   % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(4).Data = boolean(timesetbutton);   % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(5).Data = boolean(alarmbutton);   % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(6).Data = boolean(swatchbutton);   % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(7).Data = boolean(alarmOnOff);
  %endfunction

