#include "member.h"

Member::Member() {
  priv = true;
  prot = false;
  pub = false;
}

bool Member::getPriv() { return priv; }
bool Member::getProt() { return prot; }
bool Member::getPub() { return pub; }

void Member::setPriv(bool param) { priv = param; }
void Member::setProt(bool param) { prot = param; }
void Member::setPub(bool param) { pub = param; }
