#ifndef ESCHER_MODAL_VIEW_CONTROLLER_H
#define ESCHER_MODAL_VIEW_CONTROLLER_H

#include <escher/view_controller.h>
#include <escher/stack_view.h>

class ModalViewController : public ViewController {
public:
  ModalViewController(Responder * parentResponder, ViewController * child);
  View * view() override;
  const char * title() const override;

  bool handleEvent(Ion::Events::Event event) override;
  void didBecomeFirstResponder() override;
  void displayModalViewController(ViewController * vc, float verticalAlignment, float horizontalAlignment,
    KDCoordinate topMargin = 0, KDCoordinate leftMargin = 0,  KDCoordinate bottomMargin = 0, KDCoordinate rightMargin = 0);
  void dismissModalViewController();
  bool isDisplayingModal();
private:
  class ContentView : public View {
  public:
    ContentView();
    void setMainView(View * regularView);
    int numberOfSubviews() const override;
    View * subviewAtIndex(int index) override;
    void layoutSubviews() override;
    void presentModalView(View * modalView, float verticalAlignment, float horizontalAlignment,
      KDCoordinate topMargin, KDCoordinate leftMargin,  KDCoordinate bottomMargin, KDCoordinate rightMargin);
    void dismissModalView();
    bool isDisplayingModal() const;
  private:
    KDRect frame();
    View * m_regularView;
    View * m_currentModalView;
    bool m_isDisplayingModal;
    float m_verticalAlignment;
    float m_horizontalAlignment;
    KDCoordinate m_topMargin;
    KDCoordinate m_leftMargin;
    KDCoordinate m_bottomMargin;
    KDCoordinate m_rightMargin;
  };
  ContentView m_contentView;
  Responder * m_previousResponder;
  ViewController * m_currentModalViewController;
  ViewController * m_regularViewController;
};

#endif