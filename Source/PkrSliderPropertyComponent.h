//
//  PkrSliderPropertyComponent.h
//  midiplug
//
//  Created by Kyle Kurz on 9/20/14.
//
//

#ifndef midiplug_PkrSliderPropertyComponent_h
#define midiplug_PkrSliderPropertyComponent_h

class PkrSliderPropertyComponent : public SliderPropertyComponent
{
public:
    PkrSliderPropertyComponent(const String &propertyName, double min, double max, double step)
    : SliderPropertyComponent(propertyName, min, max, step)
    {
        slider.setSliderStyle(Slider::LinearHorizontal);
        setValue(0.0);
    }
    
    void setValue (double newValue) override
    {
        slider.setValue(newValue);
    }
};

#endif
