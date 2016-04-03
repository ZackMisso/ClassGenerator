#ifndef __MEMBER_H__
#define __MEMBER_H__

class Member {
private:
  bool priv;
  bool prot;
  bool pub;
public:
  Member();
  // getter methods
  bool getPriv();
  bool getProt();
  bool getPub();
  // setter methods
  void setPriv(bool param);
  void setProt(bool param);
  void setPub(bool param);
};

#endif
