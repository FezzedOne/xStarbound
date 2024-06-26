#ifndef STAR_CURRENCY_HPP
#define STAR_CURRENCY_HPP

#include "StarItem.hpp"
#include "StarSwingableItem.hpp"

namespace Star {

STAR_CLASS(CurrencyItem);

class CurrencyItem : public Item, public SwingableItem {
public:
  CurrencyItem(Json const& config, String const& directory);

  virtual ItemPtr clone() const override;

  virtual List<Drawable> drawables() const override;

  virtual void fire(FireMode mode, bool shifting, bool edgeTriggered) override;
  virtual void fireTriggered() override;

  virtual String pickupSound() const override;

  String currencyType();

  // Value of a single instance of this currency
  uint64_t currencyValue();

  // Total value of all currencies (so currencyValue * count)
  uint64_t totalValue();

private:
  String m_currency;
  uint64_t m_value;
};

}

#endif
