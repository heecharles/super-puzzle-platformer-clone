#include "game/ui_layer.h"
#include "base/components/animation_sprite.h"
#include "base/components/bar_sprite.h"
#include "base/components/sprite.h"
#include "game/score.h"

const int UiTopPad = 23;

UiLayer::UiLayer() {
  auto black = std::make_shared<Sprite>("play/ui/black.png");
  black->SetAlpha(0.5);
  this->AddChild(black);
  this->lvbar = std::make_shared<BarSprite>();
  this->lvbar->SetTexture("play/ui/lvbar.png");
  this->lvbar->SetMinMax(0, 100);
  this->lvbar->X() = 98;
  this->lvbar->Y() = UiTopPad;
  this->AddChild(lvbar);

  this->AddChild(std::make_shared<Sprite>("play/ui/x1.png", 0, UiTopPad));
  this->AddChild(std::make_shared<Sprite>("play/ui/x2.png", 300, UiTopPad));
  this->AddChild(std::make_shared<Sprite>("play/ui/x3.png", 600, UiTopPad));
  auto max = std::make_shared<AnimationSprite>();
  max->SetAnimationTexture("play/ui/max.png", 4);
  max->X() = 845;
  max->Y() = UiTopPad - 17;
  this->AddChild(max);

  this->score = std::make_shared<Score>();
  this->AddChild(score);
}

void UiLayer::AddScore(long num) { this->score->Add(num); }

void UiLayer::SetEnerge(int value) { this->lvbar->SetValue(value); }