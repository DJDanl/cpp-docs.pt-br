---
title: "Instru&#231;&#245;es passo a passo: adicionando anima&#231;&#227;o a um projeto MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "animação [MFC]"
  - "MFC, animação"
ms.assetid: 004f832c-9fd5-4f88-9ca9-ae65dececdc2
caps.latest.revision: 18
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: adicionando anima&#231;&#227;o a um projeto MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este passo a passo ensina como adicionar um objeto animado básico do Visual C\+\+, projeto de biblioteca de classes do Microsoft \(MFC\).  
  
 O passo a passo mostra como executar essas tarefas:  
  
-   Crie um aplicativo MFC.  
  
-   Adicionar um menu e adicione comandos iniciar e interromper uma animação.  
  
-   Criar manipuladores para os comandos de início e de parada.  
  
-   Adicionar um objeto animado ao projeto.  
  
-   Centralize o objeto animado na janela.  
  
-   Verificar os resultados.  
  
 [!INCLUDE[note_settings_general](../mfc/includes/note_settings_general_md.md)]  
  
## Pré-requisitos  
 Para concluir este passo a passo, você deve ter o Visual Studio.  
  
### Para criar um aplicativo de MFC  
  
1.  No menu **Arquivo**, aponte para **Novo** e clique em **Projeto**.  
  
2.  Na caixa de diálogo de **Novo Projeto** , no painel esquerdo em **Modelos Instalados**, expanda **Visual C\+\+** e selecione **MFC**.  No painel central, **Aplicativo do MFC**selecione.  Na caixa de **Nome** , digite `MFCAnimationWalkthrough`.  Clique em **OK**.  
  
3.  Na caixa de diálogo de **Assistente para Aplicativo do MFC** , verifique se **Tipo de Aplicativo** é **Vários documentos**, **Estilo de projeto** é **Visual Studio**, e a opção de **Suporte à arquitetura do documento\/exibição** é selecionada.  Clique em **Concluir**.  
  
### Para adicionar um menu e adicione comandos iniciar e interromper uma animação  
  
1.  No menu de **Exibir** , aponte para **Outras Janelas** e clique em **Modo de Exibição de Recurso**.  
  
2.  Em **Modo de Exibição de Recurso**, navegue até a pasta de **Menu** e abra.  Clique duas vezes no recurso de `IDR_MFCAnimationWalTYPE` para abri\-la da alteração.  
  
3.  Na barra de menus, na caixa de **Digite Aqui** , tipo `A&nimation` para criar um menu de animação.  
  
4.  Em **Animação**, na caixa de **Digite Aqui** , tipo `Início &Avançar` para criar um comando para iniciar.  
  
5.  Em **Início para frente**, na caixa de **Digite Aqui** , tipo `Início &Para trás`.  
  
6.  Em **Início para trás**, na caixa de **Digite Aqui** , tipo `S&parte superior` para criar um comando de parada.  
  
7.  Salvar MFCAnimationWalkthrough.rc e feche\-o.  
  
8.  Em **Gerenciador de Soluções**, clique duas vezes em para abri\-lo MainFrm.cpp da alteração.  No método de `CMainFrame::OnCreate` , localize a seção que tem várias chamadas a `lstBasicCommands.AddTail`.  Imediatamente depois que essa seção, adicione o código a seguir.  
  
    ```  
    lstBasicCommands.AddTail(ID_ANIMATION_STARTFORWARD);  
    lstBasicCommands.AddTail(ID_ANIMATION_STARTBACKWARD);  
    lstBasicCommands.AddTail(ID_ANIMATION_STOP);  
    ```  
  
9. Salve o arquivo e feche\-o.  
  
### Para criar manipuladores para os comandos de início e término  
  
1.  No menu de **Projeto** , clique em **Assistente de classe**.  
  
2.  Em **Assistente de Classe MFC**, em **Nome da classe**, `CMFCAnimationWalkthroughView`selecione.  
  
3.  Na guia de **Comandos** , na caixa de **IDs de objeto** , em `ID_ANIMATION_STARTFORWARD`selecione e, na caixa de **Mensagens** , `COMMAND`selecione.  Clique **Adicionar Manipulador**.  
  
4.  Na caixa de diálogo de **Adicionar a Função de Membro** , clique **OK**.  
  
5.  Na caixa de **IDs de objeto** , em `ID_ANIMATION_STARTBACKWARD`selecione e, na caixa de **Mensagens** , `COMMAND`selecione.  Clique **Adicionar Manipulador**.  
  
6.  Na caixa de diálogo de **Adicionar a Função de Membro** , clique **OK**.  
  
7.  Na caixa de **IDs de objeto** , em `ID_ANIMATION_STOP`selecione e, na caixa de **Mensagens** , `COMMAND`selecione.  Clique em **Adicionar Manipulador** e clique em **OK**.  
  
8.  Na caixa de diálogo de **Adicionar a Função de Membro** , clique **OK**.  
  
9. Em **Assistente de Classe MFC**, clique **OK**.  
  
10. Salvar MFCAnimationWalkthroughView.cpp, que está aberto no editor, mas não feche o.  
  
### Para adicionar um objeto ao projeto animado  
  
1.  No Solution Explorer, clique duas vezes em para abri\-lo MFCAnimationWalkthroughView.h da alteração.  Imediatamente antes da definição da classe de `CMFCAnimationWalkthroughView` , adicione o seguinte código para criar um controlador de animação personalizado que trata conflitos de programar com o objeto de animação.  
  
    ```  
    class CCustomAnimationController : public CAnimationController  
    {  
    public:  
        CCustomAnimationController()  
        {  
        }  
  
        virtual BOOL OnHasPriorityTrim(CAnimationGroup* pGroupScheduled, CAnimationGroup* pGroupNew, UI_ANIMATION_PRIORITY_EFFECT priorityEffect)  
        {  
            return TRUE;  
        }  
    };  
    ```  
  
2.  No final da classe de `CMFCAnimationWalkthroughView` , adicione o seguinte código.  
  
    ```  
    CCustomAnimationController m_animationController;  
    CAnimationColor m_animationColor;   
    CAnimationRect m_animationRect;  
    ```  
  
3.  Depois da linha de `DECLARE_MESSAGE_MAP()` , adicione o seguinte código.  
  
    ```  
    void Animate(BOOL bDirection);  
    ```  
  
4.  Salve o arquivo e feche\-o.  
  
5.  Em MFCAnimationWalkthroughView.cpp, na parte superior do arquivo depois que as instruções de `#include` mas antes de classificação de alguns métodos, adicione o seguinte código.  
  
    ```  
    static int nAnimationGroup = 0;  
    static int nInfoAreaHeight = 40;  
    ```  
  
6.  No final do construtor para `CMFCAnimationWalkthroughView`, adicione o seguinte código.  
  
    ```  
    m_animationController.EnableAnimationTimerEventHandler();  
    m_animationController.EnablePriorityComparisonHandler(UI_ANIMATION_PHT_TRIM);  
  
    m_animationColor = RGB(255, 255, 255);  
    m_animationRect = CRect(0, 0, 0, 0);  
  
    m_animationColor.SetID(-1, nAnimationGroup);  
    m_animationRect.SetID(-1, nAnimationGroup);  
  
    m_animationController.AddAnimationObject(&m_animationColor);  
    m_animationController.AddAnimationObject(&m_animationRect);  
    ```  
  
7.  Localize o método de `CAnimationWalthroughView::PreCreateWindow` e substitua\-o com o código a seguir.  
  
    ```  
    BOOL CMFCAnimationWalkthroughView::PreCreateWindow(CREATESTRUCT& cs)  
    {  
        // TODO: Modify the Window class or styles here by modifying  
        //  the CREATESTRUCT cs  
  
        m_animationController.SetRelatedWnd(this);  
        return CView::PreCreateWindow(cs);  
    }  
    ```  
  
8.  Localize o método de `CAnimationWalkthroughView::OnDraw` e substitua\-o com o código a seguir.  
  
    ```  
    void CMFCAnimationWalkthroughView::OnDraw(CDC* pDC)  
    {  
        CMFCAnimationWalkthroughDoc* pDoc = GetDocument();  
        ASSERT_VALID(pDoc);  
        if (!pDoc)  
            return;  
  
        // TODO: add draw code for native data here  
        CMemDC dcMem(*pDC, this);  
        CDC& dc = dcMem.GetDC();  
  
        CRect rect;  
        GetClientRect(rect);  
  
        dc.FillSolidRect(rect, GetSysColor(COLOR_WINDOW));  
  
        CString strRGB;  
        strRGB.Format(_T("Fill Color is: %d; %d; %d"), GetRValue(m_animationColor), GetGValue(m_animationColor), GetBValue(m_animationColor));  
  
        dc.DrawText(strRGB, rect, DT_CENTER);  
        rect.top += nInfoAreaHeight;  
  
        CBrush br;  
  
        br.CreateSolidBrush(m_animationColor);  
        CBrush* pBrushOld = dc.SelectObject(&br);  
  
        dc.Rectangle((CRect)m_animationRect);  
        dc.SelectObject(pBrushOld);  
    }  
    ```  
  
9. No final do arquivo, adicione o seguinte código.  
  
    ```  
    void CMFCAnimationWalkthroughView::Animate(BOOL bDirection)  
    {  
        static UI_ANIMATION_SECONDS duration = 3;  
        static DOUBLE dblSpeed = 35.;  
        static BYTE nStartColor = 50;  
        static BYTE nEndColor = 255;  
  
        BYTE nRedColorFinal = bDirection ? nStartColor : nEndColor;  
        BYTE nGreenColorFinal = bDirection ? nStartColor : nEndColor;  
        BYTE nBlueColorFinal = bDirection ? nStartColor : nEndColor;  
  
        CLinearTransition* pRedTransition = new CLinearTransition(duration, (DOUBLE)nRedColorFinal);  
        CSmoothStopTransition* pGreenTransition = new CSmoothStopTransition(duration, (DOUBLE)nGreenColorFinal);  
        CLinearTransitionFromSpeed* pBlueTransition = new CLinearTransitionFromSpeed(dblSpeed, (DOUBLE)nBlueColorFinal);  
  
        m_animationColor.AddTransition(pRedTransition, pGreenTransition, pBlueTransition);  
  
        CRect rectClient;  
        GetClientRect(rectClient);  
        rectClient.top += nInfoAreaHeight;  
  
        int nLeftFinal = bDirection ? rectClient.left : rectClient.CenterPoint().x;  
        int nTopFinal = bDirection ? rectClient.top : rectClient.CenterPoint().y;  
        int nRightFinal = bDirection ? rectClient.right : rectClient.CenterPoint().x;  
        int nBottomFinal = bDirection ? rectClient.bottom : rectClient.CenterPoint().y;  
  
        CLinearTransition* pLeftTransition = new CLinearTransition(duration, nLeftFinal);  
        CLinearTransition* pTopTransition = new CLinearTransition(duration, nTopFinal);  
        CLinearTransition* pRightTransition = new CLinearTransition(duration, nRightFinal);  
        CLinearTransition* pBottomTransition = new CLinearTransition(duration, nBottomFinal);  
  
        m_animationRect.AddTransition(pLeftTransition, pTopTransition, pRightTransition, pBottomTransition);  
  
        CBaseKeyFrame* pKeyframeStart = CAnimationController::GetKeyframeStoryboardStart();  
        CKeyFrame* pKeyFrameEnd = m_animationController.CreateKeyframe(nAnimationGroup, pBlueTransition);  
  
        pLeftTransition->SetKeyframes(pKeyframeStart, pKeyFrameEnd);  
        pTopTransition->SetKeyframes(pKeyframeStart, pKeyFrameEnd);  
        pRightTransition->SetKeyframes(pKeyframeStart, pKeyFrameEnd);  
        pBottomTransition->SetKeyframes(pKeyframeStart, pKeyFrameEnd);  
  
        m_animationController.AnimateGroup(nAnimationGroup);  
    }  
    ```  
  
10. No menu de **Projeto** , clique em **Assistente de classe**.  
  
11. Em **Assistente de Classe MFC**, em **Nome da classe**, `CMFCAnimationWalkthroughView`selecione.  
  
12. Na guia de **Mensagens** , na caixa de **Mensagens** , `WM_ERASEBKGND`selecione, clique em **Adicionar Manipulador**, e clique em **OK**.  
  
13. Em MFCAnimationWalkthroughView.cpp, substitua a implementação de `OnEraseBkgnd` com o código a seguir para reduzir cintilar no objeto animado quando é redesenhado.  
  
    ```  
    BOOL CMFCAnimationWalkthroughView::OnEraseBkgnd(CDC* /*pDC*/)  
    {  
        return TRUE;  
    }  
    ```  
  
14. Substituir as implementações de `CMFCAnimationWalkthroughView::OnAnimationStartforward`, de `CMFCAnimationWalkthroughView::OnAnimationStartbackward`, e de `CMFCAnimationWalkthroughView::OnAnimationStop` com o código a seguir.  
  
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
  
15. Salve o arquivo e feche\-o.  
  
### Para centralizar o objeto animado na janela  
  
1.  Em **Gerenciador de Soluções**, clique duas vezes em para abri\-lo MFCAnimationWalkthroughView.h da alteração.  No final da classe de `CMFCAnimationWalkthroughView` , imediatamente depois da definição de `m_animationRect`, adicione o seguinte código.  
  
    ```  
    BOOL m_bCurrentDirection;  
    ```  
  
2.  Salve o arquivo e feche\-o.  
  
3.  No menu de **Projeto** , clique em **Assistente de classe**.  
  
4.  Em **Assistente de Classe MFC**, em **Nome da classe**, `CMFCAnimationWalkthroughView`selecione.  
  
5.  Na guia de **Mensagens** , na caixa de **Mensagens** , `WM_SIZE`selecione, clique em **Adicionar Manipulador**, e clique em **OK**.  
  
6.  Em MFCAnimationWalkthroughView.cpp, substitua o código para `CMFCAnimationWalkthroughView::OnSize` com o código a seguir.  
  
    ```  
    void CMFCAnimationWalkthroughView::OnSize(UINT nType, int cx, int cy)  
    {  
        CView::OnSize(nType, cx, cy);  
  
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
  
8.  No início do método de `CMFCAnimationWalkthroughView::Animate` , adicione o seguinte código.  
  
    ```  
    m_bCurrentDirection = bDirection;  
    ```  
  
9. Salve o arquivo e feche\-o.  
  
### Para verificar os resultados  
  
1.  Criar e executar o aplicativo.  No menu de **Animação** , clique em **Início para frente**.  Um retângulo deve aparecer e depois preencher a área do centro.  Quando você clicar em, a **Início para trás**animação deve reverter e, quando você clicar em **Parar**, deve parar.  A cor de preenchimento do retângulo deve ser alterada desde que a animação progride, e a cor atual deve ser exibida na parte superior da janela de animação.  
  
## Consulte também  
 [Explicações Passo\-a\-passo](../mfc/walkthroughs-mfc.md)