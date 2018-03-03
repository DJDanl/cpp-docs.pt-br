---
title: "Passo a passo: Adicionando animação a um projeto MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- animation [MFC]
- MFC, animation
ms.assetid: 004f832c-9fd5-4f88-9ca9-ae65dececdc2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f027da0e90bc8dde015c2d42bd72ceb388aa0bba
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-adding-animation-to-an-mfc-project"></a>Instruções passo a passo: adicionando animação a um projeto MFC
Este passo a passo mostra como adicionar um objeto animado básico para um Visual C++, o projeto de biblioteca do Microsoft Foundation Class (MFC).  
  
 Passo a passo mostra como realizar estas tarefas:  
  
-   Crie um aplicativo do MFC.  
  
-   Adicionar um menu e, em seguida, adicionar comandos para iniciar e parar uma animação.  
  
-   Crie manipuladores para os comandos de início e parada.  
  
-   Adicione um objeto animado ao projeto.  
  
-   Centralize o objeto animado na janela.  
  
-   Verifique se os resultados.  
  
 [!INCLUDE[note_settings_general](../mfc/includes/note_settings_general_md.md)]  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Para concluir este passo a passo, você deve ter o Visual Studio.  
  
### <a name="to-create-an-mfc-application"></a>Para criar um aplicativo MFC  
  
1.  No menu **Arquivo**, aponte para **Novo** e clique em **Projeto**.  
  
2.  No **novo projeto** caixa de diálogo, no painel esquerdo, em **modelos instalados**, expanda **Visual C++** e, em seguida, selecione **MFC**. No painel central, selecione **aplicativo MFC**. Na caixa **Nome**, digite `MFCAnimationWalkthrough`. Clique em **OK**.  
  
3.  No **Assistente de aplicativo MFC** caixa de diálogo caixa, verifique **tipo de aplicativo** é **vários documentos**, **estilo de projeto** é  **O Visual Studio**e o **suporte para a arquitetura de documento/exibição** opção é selecionada. Clique em **Finalizar**.  
  
### <a name="to-add-a-menu-and-then-add-commands-to-start-and-stop-an-animation"></a>Para adicionar um menu e, em seguida, adicionar comandos para iniciar e parar uma animação  
  
1.  Sobre o **exibição** , aponte para **outras janelas** e, em seguida, clique em **exibição recursos**.  
  
2.  Em **exibição recursos**, navegue até o **Menu** pasta e abri-lo. Clique duas vezes o `IDR_MFCAnimationWalTYPE` recurso para abri-lo para modificação.  
  
3.  Na barra de menus, no **tipo aqui** , digite `A&nimation` para criar um menu de animação.  
  
4.  Em **animação**, no **tipo aqui** , digite `Start &Forward` para criar um comando Iniciar para frente.  
  
5.  Em **iniciar Forward**, no **tipo aqui** , digite `Start &Backward`.  
  
6.  Em **iniciar com versões anteriores**, no **tipo aqui** , digite `S&top` para criar um comando de parada.  
  
7.  Salvar MFCAnimationWalkthrough.rc e fechá-lo.  
  
8.  Em **Solution Explorer**, clique duas vezes em MainFrm.cpp para abri-lo para modificação. No `CMainFrame::OnCreate` método, localize a seção que tem várias chamadas para `lstBasicCommands.AddTail`. Logo após essa seção, adicione o código a seguir.  
  
 ```  
    lstBasicCommands.AddTail(ID_ANIMATION_STARTFORWARD);

 lstBasicCommands.AddTail(ID_ANIMATION_STARTBACKWARD);

    lstBasicCommands.AddTail(ID_ANIMATION_STOP);

 ```  
  
9. Salve o arquivo e feche-o.  
  
### <a name="to-create-handlers-for-the-start-and-stop-commands"></a>Para criar manipuladores para o início e interromper comandos  
  
1.  Sobre o **projeto** menu, clique em **Assistente de classe**.  
  
2.  No **Assistente de classe MFC**, em **nome da classe**, selecione `CMFCAnimationWalkthroughView`.  
  
3.  No **comandos** guia o **IDs de objeto** caixa, selecione `ID_ANIMATION_STARTFORWARD`e, em seguida, no **mensagens** caixa, selecione `COMMAND`. Clique em **Adicionar manipulador**.  
  
4.  No **Adicionar função de membro** caixa de diálogo, clique em **Okey**.  
  
5.  No **IDs de objeto** selecione `ID_ANIMATION_STARTBACKWARD`e, em seguida, no **mensagens** caixa, selecione `COMMAND`. Clique em **Adicionar manipulador**.  
  
6.  No **Adicionar função de membro** caixa de diálogo, clique em **Okey**.  
  
7.  No **IDs de objeto** selecione `ID_ANIMATION_STOP`e, em seguida, no **mensagens** caixa, selecione `COMMAND`. Clique em **Adicionar manipulador** e, em seguida, clique em **Okey**.  
  
8.  No **Adicionar função de membro** caixa de diálogo, clique em **Okey**.  
  
9. No **Assistente de classe MFC**, clique em **Okey**.  
  
10. Salvar MFCAnimationWalkthroughView.cpp, que é aberto no editor, mas não o feche.  
  
### <a name="to-add-an-animated-object-to-the-project"></a>Para adicionar um objeto animado ao projeto  
  
1.  No Solution Explorer, clique duas vezes em MFCAnimationWalkthroughView.h para abri-lo para modificação. Antes da definição do `CMFCAnimationWalkthroughView` de classe, adicione o código a seguir para criar um controlador de animação personalizada que manipulará o agendamento entra em conflito com o objeto de animação.  
  
 ```  
    class CCustomAnimationController : public CAnimationController  
 {  
    public: 
    CCustomAnimationController() 
 {  
 }  
 
    virtual BOOL OnHasPriorityTrim(CAnimationGroup* pGroupScheduled,
    CAnimationGroup* pGroupNew,
    UI_ANIMATION_PRIORITY_EFFECT priorityEffect)  
 {  
    return TRUE;  
 }  
 };  
 ```  
  
2.  No final de `CMFCAnimationWalkthroughView` classe, adicione o código a seguir.  
  
 ```  
    CCustomAnimationController m_animationController;  
    CAnimationColor m_animationColor;   
    CAnimationRect m_animationRect;  
 ```  
  
3.  Após o `DECLARE_MESSAGE_MAP()` de linha, adicione o código a seguir.  
  
 ```  
    void Animate(BOOL bDirection);

 ```  
  
4.  Salve o arquivo e feche-o.  
  
5.  Em MFCAnimationWalkthroughView.cpp, na parte superior do arquivo após o `#include` instruções mas antes de qualquer classe métodos, adicionam o código a seguir.  
  
 ```  
    static int nAnimationGroup = 0;  
    static int nInfoAreaHeight = 40;  
 ```  
  
6.  No final do construtor para `CMFCAnimationWalkthroughView`, adicione o seguinte código.  
  
 ```  
    m_animationController.EnableAnimationTimerEventHandler();
m_animationController.EnablePriorityComparisonHandler(UI_ANIMATION_PHT_TRIM);

 
    m_animationColor = RGB(255,
    255,
    255);

    m_animationRect = CRect(0,
    0,
    0,
    0);

 
    m_animationColor.SetID(-1,
    nAnimationGroup);

    m_animationRect.SetID(-1,
    nAnimationGroup);

 
    m_animationController.AddAnimationObject(&m_animationColor);

 m_animationController.AddAnimationObject(&m_animationRect);

 ```  
  
7.  Localize o `CAnimationWalthroughView::PreCreateWindow` método e, em seguida, substitua-o com o código a seguir.  
  
 ```  
    BOOL CMFCAnimationWalkthroughView::PreCreateWindow(CREATESTRUCT& cs)  
 { *// TODO: Modify the Window class or styles here by modifying *//  the CREATESTRUCT cs  
 
    m_animationController.SetRelatedWnd(this);

 return CView::PreCreateWindow(cs);

 }  
 ```  
  
8.  Localize o `CAnimationWalkthroughView::OnDraw` método e, em seguida, substitua-o com o código a seguir.  
  
 ```  
    void CMFCAnimationWalkthroughView::OnDraw(CDC* pDC)  
 {  
    CMFCAnimationWalkthroughDoc* pDoc = GetDocument();
ASSERT_VALID(pDoc);

 if (!pDoc)  
    return; 
 *// TODO: add draw code for native data here  
    CMemDC dcMem(*pDC,
    this);

    CDC& dc = dcMem.GetDC();

 
    CRect rect;  
    GetClientRect(rect);

 
    dc.FillSolidRect(rect,
    GetSysColor(COLOR_WINDOW));

 
    CString strRGB;  
    strRGB.Format(_T("Fill Color is: %d; %d; %d"),
    GetRValue(m_animationColor),
    GetGValue(m_animationColor),
    GetBValue(m_animationColor));

 
    dc.DrawText(strRGB,
    rect,
    DT_CENTER);

    rect.top += nInfoAreaHeight;  
 
    CBrush br;  
 
    br.CreateSolidBrush(m_animationColor);

 CBrush* pBrushOld = dc.SelectObject(&br);

 
    dc.Rectangle((CRect)m_animationRect);

 dc.SelectObject(pBrushOld);

 }  
 ```  
  
9. No final do arquivo, adicione o código a seguir.  
  
 ```  
    void CMFCAnimationWalkthroughView::Animate(BOOL bDirection)  
 {  
    static UI_ANIMATION_SECONDS duration = 3;  
    static DOUBLE dblSpeed = 35.;  
    static BYTE nStartColor = 50;  
    static BYTE nEndColor = 255;  
 
    BYTE nRedColorFinal = bDirection  nStartColor : nEndColor;  
    BYTE nGreenColorFinal = bDirection  nStartColor : nEndColor;  
    BYTE nBlueColorFinal = bDirection  nStartColor : nEndColor;  
 
    CLinearTransition* pRedTransition = new CLinearTransition(duration, (DOUBLE)nRedColorFinal);

    CSmoothStopTransition* pGreenTransition = new CSmoothStopTransition(duration, (DOUBLE)nGreenColorFinal);

    CLinearTransitionFromSpeed* pBlueTransition = new CLinearTransitionFromSpeed(dblSpeed, (DOUBLE)nBlueColorFinal);

 
    m_animationColor.AddTransition(pRedTransition,
    pGreenTransition,
    pBlueTransition);

 
    CRect rectClient;  
    GetClientRect(rectClient);

 rectClient.top += nInfoAreaHeight;  
 
    int nLeftFinal = bDirection  rectClient.left : rectClient.CenterPoint().x;  
    int nTopFinal = bDirection  rectClient.top : rectClient.CenterPoint().y;  
    int nRightFinal = bDirection  rectClient.right : rectClient.CenterPoint().x;  
    int nBottomFinal = bDirection  rectClient.bottom : rectClient.CenterPoint().y;  
 
    CLinearTransition* pLeftTransition = new CLinearTransition(duration,
    nLeftFinal);

    CLinearTransition* pTopTransition = new CLinearTransition(duration,
    nTopFinal);

    CLinearTransition* pRightTransition = new CLinearTransition(duration,
    nRightFinal);

    CLinearTransition* pBottomTransition = new CLinearTransition(duration,
    nBottomFinal);

 
    m_animationRect.AddTransition(pLeftTransition,
    pTopTransition,
    pRightTransition,
    pBottomTransition);

 
    CBaseKeyFrame* pKeyframeStart = CAnimationController::GetKeyframeStoryboardStart();
CKeyFrame* pKeyFrameEnd = m_animationController.CreateKeyframe(nAnimationGroup,
    pBlueTransition);

 
    pLeftTransition->SetKeyframes(pKeyframeStart,
    pKeyFrameEnd);

    pTopTransition->SetKeyframes(pKeyframeStart,
    pKeyFrameEnd);

    pRightTransition->SetKeyframes(pKeyframeStart,
    pKeyFrameEnd);

    pBottomTransition->SetKeyframes(pKeyframeStart,
    pKeyFrameEnd);

 
    m_animationController.AnimateGroup(nAnimationGroup);

 }  
 ```  
  
10. Sobre o **projeto** menu, clique em **Assistente de classe**.  
  
11. No **Assistente de classe MFC**, em **nome da classe**, selecione `CMFCAnimationWalkthroughView`.  
  
12. No **mensagens** guia o **mensagens** selecione `WM_ERASEBKGND`, clique em **Adicionar manipulador**e, em seguida, clique em **Okey**.  
  
13. No MFCAnimationWalkthroughView.cpp, substitua a implementação de `OnEraseBkgnd` com o código a seguir para reduzir a cintilação no objeto animado quando ele é redesenhado.  
  
 ```  
    BOOL CMFCAnimationWalkthroughView::OnEraseBkgnd(CDC* /*pDC*/)  
 {  
    return TRUE;  
 }  
 ```  
  
14. Substitua as implementações de `CMFCAnimationWalkthroughView::OnAnimationStartforward`, `CMFCAnimationWalkthroughView::OnAnimationStartbackward`, e `CMFCAnimationWalkthroughView::OnAnimationStop` com o código a seguir.  
  
 ```  
    void CMFCAnimationWalkthroughView::OnAnimationStartforward()  
 {  
    Animate(TRUE);

 }  
 
    void CMFCAnimationWalkthroughView::OnAnimationStartbackward()  
 {  
    Animate(FALSE);

 }  
 
    void CMFCAnimationWalkthroughView::OnAnimationStop()  
 {  
    IUIAnimationManager* pManager = m_animationController.GetUIAnimationManager();
if (pManager != NULL)  
 {  
    pManager->AbandonAllStoryboards();

 }  
 }  
 
 ```  
  
15. Salve o arquivo e feche-o.  
  
### <a name="to-center-the-animated-object-in-the-window"></a>Para centralizar o objeto animado na janela  
  
1.  Em **Solution Explorer**, clique duas vezes em MFCAnimationWalkthroughView.h para abri-lo para modificação. No final de `CMFCAnimationWalkthroughView` logo após a definição de classe `m_animationRect`, adicione o seguinte código.  
  
 ```  
    BOOL m_bCurrentDirection;  
 ```  
  
2.  Salve o arquivo e feche-o.  
  
3.  Sobre o **projeto** menu, clique em **Assistente de classe**.  
  
4.  No **Assistente de classe MFC**, em **nome da classe**, selecione `CMFCAnimationWalkthroughView`.  
  
5.  No **mensagens** guia o **mensagens** selecione `WM_SIZE`, clique em **Adicionar manipulador**e, em seguida, clique em **Okey**.  
  
6.  No MFCAnimationWalkthroughView.cpp, substitua o código para `CMFCAnimationWalkthroughView::OnSize` com o código a seguir.  
  
 ```  
    void CMFCAnimationWalkthroughView::OnSize(UINT nType,
    int cx,
    int cy)  
 {  
    CView::OnSize(nType,
    cx,
    cy);

 
    CRect rect;  
    GetClientRect(rect);

 rect.top += nInfoAreaHeight;  
 
    CRect rectAnim = m_animationRect;  
    m_animationRect = CRect(CPoint(rect.CenterPoint().x - rectAnim.Width() / 2,   
    rect.CenterPoint().y - rectAnim.Height() / 2),   
    rectAnim.Size());

 
    if (m_animationController.IsAnimationInProgress())  
 {  
    Animate(m_bCurrentDirection);

 }  
 }  
 ```  
  
7.  No início do construtor para `CMFCAnimationWalkthroughView`, adicione o seguinte código.  
  
 ```  
    m_bCurrentDirection = TRUE;  
 ```  
  
8.  No início de `CMFCAnimationWalkthroughView::Animate` método, adicione o seguinte código.  
  
 ```  
    m_bCurrentDirection = bDirection;  
 ```  
  
9. Salve o arquivo e feche-o.  
  
### <a name="to-verify-the-results"></a>Para verificar os resultados  
  
1.  Crie e execute o aplicativo. Sobre o **animação** menu, clique em **iniciar Forward**. Um retângulo deve aparecer e, em seguida, preencher a área central. Quando você clica em **iniciar com versões anteriores**, a animação deve reverter e, quando você clica em **parar**, deve parar. A cor de preenchimento do retângulo deve alterar conforme o andamento da animação e a cor atual deve ser exibida na parte superior da janela de animação.  
  
## <a name="see-also"></a>Consulte também  
 [Explicações Passo a Passo](../mfc/walkthroughs-mfc.md)

