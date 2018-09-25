---
title: 'Passo a passo: Adicionando animação a um projeto MFC | Microsoft Docs'
ms.custom: ''
ms.date: 09/20/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- animation [MFC]
- MFC, animation
ms.assetid: 004f832c-9fd5-4f88-9ca9-ae65dececdc2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 326535395599a76f521100475cfc80b014ba6cd9
ms.sourcegitcommit: edb46b0239a0e616af4ec58906e12338c3e8d2c6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2018
ms.locfileid: "47169431"
---
# <a name="walkthrough-adding-animation-to-an-mfc-project"></a>Instruções passo a passo: adicionando animação a um projeto MFC

Este passo a passo ensina como adicionar um objeto animado básico para um Visual C++, o projeto de biblioteca do Microsoft Foundation Class (MFC).

O passo a passo mostra como realizar essas tarefas:

- Crie um aplicativo do MFC.

- Adicionar um menu e, em seguida, adicionar comandos para iniciar e parar uma animação.

- Crie manipuladores para os comandos de início e parada.

- Adicione um objeto animado para o projeto.

- Centralize o objeto animado na janela.

- Verifique se os resultados.

[!INCLUDE[note_settings_general](../mfc/includes/note_settings_general_md.md)]

## <a name="prerequisites"></a>Pré-requisitos

Para concluir este passo a passo, você deve ter o Visual Studio.

### <a name="to-create-an-mfc-application"></a>Para criar um aplicativo do MFC

1. No menu **Arquivo**, aponte para **Novo** e clique em **Projeto**.

1. No **novo projeto** caixa de diálogo, no painel esquerdo, em **modelos instalados**, expanda **Visual C++** e, em seguida, selecione **MFC**. No painel central, selecione **aplicativo do MFC**. No **nome** , digite *MFCAnimationWalkthrough*. Clique em **OK**.

1. No **Assistente de aplicativo MFC** diálogo caixa, verifique **tipo de aplicativo** é **vários documentos**, **estilo de projeto** é  **Visual Studio**e o **suporte de arquitetura de documento/exibição** opção está selecionada. Clique em **Finalizar**.

### <a name="to-add-a-menu-and-then-add-commands-to-start-and-stop-an-animation"></a>Para adicionar um menu e, em seguida, adicionar comandos para iniciar e parar uma animação

1. Sobre o **modo de exibição** , aponte para **Other Windows** e, em seguida, clique em **exibição de recurso**.

1. Na **exibição de recurso**, navegue até a **Menu** pasta e abri-lo. Clique duas vezes o **IDR_MFCAnimationWalkthroughTYPE** recurso para abri-lo para modificação.

1. Na barra de menus, na **tipo aqui** , digite *t & exto* para criar um menu de animação.

1. Sob **animação**, no **digite aqui** , digite *Iniciar & Avançar* para criar um comando Iniciar para a frente.

1. Sob **Iniciar para frente**, no **digite aqui** , digite *Iniciar & para trás*.

1. Sob **começar com versões anteriores**, no **digite aqui** , digite *p & arar* para criar um comando de parada.

1. Salve MFCAnimationWalkthrough.rc e fechá-lo.

1. Na **Gerenciador de soluções**, clique duas vezes em MainFrm.cpp para abri-lo para modificação. No `CMainFrame::OnCreate` método, localize a seção que tem várias chamadas para `lstBasicCommands.AddTail`. Logo após essa seção, adicione o código a seguir.

    ```cpp
    lstBasicCommands.AddTail(ID_ANIMATION_STARTFORWARD);
    lstBasicCommands.AddTail(ID_ANIMATION_STARTBACKWARD);
    lstBasicCommands.AddTail(ID_ANIMATION_STOP);
    ```

1. Salve o arquivo e fechá-lo.

### <a name="to-create-handlers-for-the-start-and-stop-commands"></a>Para criar manipuladores para o início e interromper comandos

1. Sobre o **Project** menu, clique em **Class Wizard**.

1. No **MFC Class Wizard**, em **nome da classe**, selecione **CMFCAnimationWalkthroughView**.

1. No **comandos** guia, o **IDs de objeto** caixa, selecione **ID_ANIMATION_STARTFORWARD**e, em seguida, no **mensagens** , selecione  **COMANDO**. Clique em **Adicionar manipulador**.

1. No **adicionar a função de membro** caixa de diálogo, clique em **Okey**.

1. No **IDs de objeto** caixa, selecione **ID_ANIMATION_STARTBACKWARD**e, em seguida, no **mensagens** caixa, selecione **comando**. Clique em **Adicionar manipulador**.

1. No **adicionar a função de membro** caixa de diálogo, clique em **Okey**.

1. No **IDs de objeto** caixa, selecione **ID_ANIMATION_STOP**e, em seguida, no **mensagens** caixa, selecione **comando**. Clique em **Add Handler** e, em seguida, clique em **Okey**.

1. No **adicionar a função de membro** caixa de diálogo, clique em **Okey**.

1. No **MFC Class Wizard**, clique em **Okey**.

1. Salvar MFCAnimationWalkthroughView.cpp, que é aberto no editor, mas não o feche.

### <a name="to-add-an-animated-object-to-the-project"></a>Para adicionar um objeto animado para o projeto

1. No Gerenciador de soluções, clique duas vezes em MFCAnimationWalkthroughView.h para abri-lo para modificação. Antes da definição do `CMFCAnimationWalkthroughView` de classe, adicione o seguinte código para criar um controlador de animação personalizada que irá manipular conflitos de agendamento com o objeto de animação.

    ```cpp
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

1. No final o `CMFCAnimationWalkthroughView` , adicione o código a seguir.

    ```cpp
    CCustomAnimationController m_animationController;
    CAnimationColor m_animationColor;
    CAnimationRect m_animationRect;
    ```

1. Após o `DECLARE_MESSAGE_MAP()` linha, adicione o seguinte código.

    ```cpp
    void Animate(BOOL bDirection);
    ```

1. Salve o arquivo e fechá-lo.

1. Em MFCAnimationWalkthroughView.cpp, na parte superior do arquivo após o `#include` instruções, mas antes de qualquer classe de métodos, adicionam o seguinte código.

    ```cpp
    static int nAnimationGroup = 0;
    static int nInfoAreaHeight = 40;
    ```

1. No final do construtor para `CMFCAnimationWalkthroughView`, adicione o seguinte código.

    ```cpp
    m_animationController.EnableAnimationTimerEventHandler();
    m_animationController.EnablePriorityComparisonHandler(UI_ANIMATION_PHT_TRIM);
    m_animationColor = RGB(255, 255, 255);
    m_animationRect = CRect(0, 0, 0, 0);
    m_animationColor.SetID(-1, nAnimationGroup);
    m_animationRect.SetID(-1, nAnimationGroup);
    m_animationController.AddAnimationObject(&m_animationColor);
    m_animationController.AddAnimationObject(&m_animationRect);
    ```

1. Localize o `CAnimationWalthroughView::PreCreateWindow` método e, em seguida, substitua-o pelo código a seguir.

    ```cpp
    BOOL CMFCAnimationWalkthroughView::PreCreateWindow(CREATESTRUCT& cs)
    {
        // TODO: Modify the Window class or styles here by modifying
        //       the CREATESTRUCT cs
        m_animationController.SetRelatedWnd(this);

        return CView::PreCreateWindow(cs);
    }
    ```

1. Localize o `CAnimationWalkthroughView::OnDraw` método e, em seguida, substitua-o pelo código a seguir.

    ```cpp
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
        strRGB.Format(_T("Fill Color is: %d; %d; %d"),
            GetRValue(m_animationColor),
            GetGValue(m_animationColor),
            GetBValue(m_animationColor));

        dc.DrawText(strRGB, rect, DT_CENTER);
        rect.top += nInfoAreaHeight;

        CBrush br;
        br.CreateSolidBrush(m_animationColor);
        CBrush* pBrushOld = dc.SelectObject(&br);

        dc.Rectangle((CRect)m_animationRect);

        dc.SelectObject(pBrushOld);
    }
    ```

1. No final do arquivo, adicione o código a seguir.

    ```cpp
    void CMFCAnimationWalkthroughView::Animate(BOOL bDirection)
    {
        static UI_ANIMATION_SECONDS duration = 3;
        static DOUBLE dblSpeed = 35.;
        static BYTE nStartColor = 50;
        static BYTE nEndColor = 255;

        BYTE nRedColorFinal = bDirection ? nStartColor : nEndColor;
        BYTE nGreenColorFinal = bDirection ? nStartColor : nEndColor;
        BYTE nBlueColorFinal = bDirection ? nStartColor : nEndColor;

        CLinearTransition* pRedTransition =
            new CLinearTransition(duration, (DOUBLE)nRedColorFinal);

        CSmoothStopTransition* pGreenTransition =
            new CSmoothStopTransition(duration, (DOUBLE)nGreenColorFinal);

        CLinearTransitionFromSpeed* pBlueTransition =
            new CLinearTransitionFromSpeed(dblSpeed, (DOUBLE)nBlueColorFinal);

        m_animationColor.AddTransition(pRedTransition,
            pGreenTransition,
            pBlueTransition);

        CRect rectClient;
        GetClientRect(rectClient);

        rectClient.top += nInfoAreaHeight;

        int nLeftFinal = bDirection ? rectClient.left : rectClient.CenterPoint().x;
        int nTopFinal = bDirection ? rectClient.top : rectClient.CenterPoint().y;
        int nRightFinal = bDirection ? rectClient.right : rectClient.CenterPoint().x;
        int nBottomFinal = bDirection ? rectClient.bottom : rectClient.CenterPoint().y;

        CLinearTransition* pLeftTransition =
            new CLinearTransition(duration, nLeftFinal);

        CLinearTransition* pTopTransition =
            new CLinearTransition(duration, nTopFinal);

        CLinearTransition* pRightTransition =
            new CLinearTransition(duration, nRightFinal);

        CLinearTransition* pBottomTransition =
            new CLinearTransition(duration, nBottomFinal);

        m_animationRect.AddTransition(pLeftTransition,
            pTopTransition,
            pRightTransition,
            pBottomTransition);

        CBaseKeyFrame* pKeyframeStart =
            CAnimationController::GetKeyframeStoryboardStart();
        CKeyFrame* pKeyFrameEnd =
            m_animationController.CreateKeyframe(nAnimationGroup,
                pBlueTransition);

        pLeftTransition->SetKeyframes(pKeyframeStart, pKeyFrameEnd);
        pTopTransition->SetKeyframes(pKeyframeStart, pKeyFrameEnd);
        pRightTransition->SetKeyframes(pKeyframeStart, pKeyFrameEnd);
        pBottomTransition->SetKeyframes(pKeyframeStart, pKeyFrameEnd);

        m_animationController.AnimateGroup(nAnimationGroup);
    }
    ```

1. Sobre o **Project** menu, clique em **Class Wizard**.

1. No **MFC Class Wizard**, em **nome da classe**, selecione **CMFCAnimationWalkthroughView**.

1. Sobre o **mensagens** guia da **mensagens** caixa, selecione **WM_ERASEBKGND**, clique em **Adicionar manipulador**e, em seguida, clique em **Okey** .

1. No MFCAnimationWalkthroughView.cpp, substitua a implementação de `OnEraseBkgnd` com o código a seguir para reduzir a cintilação no objeto animado quando ele é redesenhado.

    ```cpp
    BOOL CMFCAnimationWalkthroughView::OnEraseBkgnd(CDC* /*pDC*/)
    {
        return TRUE;
    }
    ```

1. Substituir as implementações de `CMFCAnimationWalkthroughView::OnAnimationStartforward`, `CMFCAnimationWalkthroughView::OnAnimationStartbackward`, e `CMFCAnimationWalkthroughView::OnAnimationStop` com o código a seguir.

    ```cpp
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

1. Salve o arquivo e fechá-lo.

### <a name="to-center-the-animated-object-in-the-window"></a>Para centralizar o objeto animado na janela

1. Na **Gerenciador de soluções**, clique duas vezes em MFCAnimationWalkthroughView.h para abri-lo para modificação. No final o `CMFCAnimationWalkthroughView` classe, logo após a definição de `m_animationRect`, adicione o seguinte código.

    ```cpp
    BOOL m_bCurrentDirection;
    ```

1. Salve o arquivo e fechá-lo.

1. Sobre o **Project** menu, clique em **Class Wizard**.

1. No **MFC Class Wizard**, em **nome da classe**, selecione **CMFCAnimationWalkthroughView**.

1. Sobre o **mensagens** guia da **mensagens** caixa, selecione **WM_SIZE**, clique em **Adicionar manipulador**e, em seguida, clique em **Okey**.

1. Em MFCAnimationWalkthroughView.cpp, substitua o código para `CMFCAnimationWalkthroughView::OnSize` com o código a seguir.

    ```cpp
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

1. No início do construtor para `CMFCAnimationWalkthroughView`, adicione o seguinte código.

    ```cpp
    m_bCurrentDirection = TRUE;
    ```

1. No início do `CMFCAnimationWalkthroughView::Animate` método, adicione o seguinte código.

    ```cpp
    m_bCurrentDirection = bDirection;
    ```

1. Salve o arquivo e fechá-lo.

### <a name="to-verify-the-results"></a>Para verificar os resultados

1. Crie e execute o aplicativo. Sobre o **animação** menu, clique em **iniciar Forward**. Um retângulo deve aparecer e, em seguida, preencher a área central. Quando você clica em **começar com versões anteriores**, a animação deve reverter e, quando você clica em **parar**, ele deve ser interrompida. A cor de preenchimento do retângulo deve alterar conforme o andamento da animação e a cor atual deve ser exibida na parte superior da janela de animação.

## <a name="see-also"></a>Consulte também

[Explicações Passo a Passo](../mfc/walkthroughs-mfc.md)
