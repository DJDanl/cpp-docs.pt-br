---
title: 'Passo a passo: Adicionando um objeto D2D a um projeto MFC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC, D2D
- D2D [MFC]
ms.assetid: dda36c33-c231-4da6-a62f-72d69a12b6dd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7985b36c0eeaa7adf5441a7a6fbb3314bac8353f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="walkthrough-adding-a-d2d-object-to-an-mfc-project"></a>Instruções passo a passo: adicionando um objeto D2D a um projeto
Este passo a passo ensina como adicionar um Direct2D básica (D2D) do objeto para um Visual C++, o projeto de biblioteca do Microsoft Foundation Class (MFC) e, em seguida, compilar o projeto em um aplicativo que imprime "Olá, mundo" em um plano de fundo do gradiente.  
  
 Passo a passo mostra como realizar estas tarefas:  
  
-   Crie um aplicativo do MFC.  
  
-   Crie um pincel de cor sólida e um pincel de gradiente linear.  
  
-   Modificar o pincel de gradiente para que ele será alterado adequadamente quando a janela é redimensionada.  
  
-   Implemente um manipulador de desenho D2D.  
  
-   Verifique se os resultados.  
  
 [!INCLUDE[note_settings_general](../mfc/includes/note_settings_general_md.md)]  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Para concluir este passo a passo, você deve ter o Visual Studio.  
  
### <a name="to-create-an-mfc-application"></a>Para criar um aplicativo MFC  
  
1.  No menu **Arquivo**, aponte para **Novo** e clique em **Projeto**.  
  
2.  No **novo projeto** caixa de diálogo, no painel esquerdo, em **modelos instalados**, expanda **Visual C++** e, em seguida, selecione **MFC**. No painel central, selecione **aplicativo MFC**. Na caixa **Nome**, digite `MFCD2DWalkthrough`. Clique em **OK**.  
  
3.  No **Assistente de aplicativo MFC**, clique em **concluir** sem alterar as configurações.  
  
### <a name="to-create-a-solid-color-brush-and-a-linear-gradient-brush"></a>Para criar um pincel de cor sólida e um pincel de gradiente linear  
  
1.  Em **Solution Explorer**, no **MFCD2DWalkthrough** projeto, o **arquivos de cabeçalho** MFCD2DWalkthroughView.h Abrir pasta. Adicione o seguinte código para o `CMFCD2DWalkthroughView` classe para criar três variáveis de dados.  
  
 ```  
    CD2DTextFormat* m_pTextFormat;  
    CD2DSolidColorBrush* m_pBlackBrush;  
    CD2DLinearGradientBrush* m_pLinearGradientBrush;  
 ```  
  
     Salve o arquivo e feche-o.  
  
2.  No **arquivos de origem** MFCD2DWalkthroughView.cpp Abrir pasta. No construtor para o `CMFCD2DWalkthroughView` de classe, adicione o código a seguir.  
  
 ' ' * / / Habilitar D2D suporte para esta janela:  
    EnableD2DSupport();

 * / / Inicializar D2D recursos:  
    m_pBlackBrush = novo CD2DSolidColorBrush(GetRenderTarget(), D2D1::ColorF(D2D1::ColorF::Black));

 
    m_pTextFormat = novo CD2DTextFormat(GetRenderTarget(), _T("Verdana"), 50);

    m_pTextFormat -> Get () -> SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);

 m_pTextFormat -> Get () -> SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

 
    D2D1_GRADIENT_STOP gradientStops [2];  
 
    gradientStops [0] .color = D2D1::ColorF(D2D1::ColorF::White);

    gradientStops [0] .position = 0.f;  
    gradientStops [1] .color = D2D1::ColorF(D2D1::ColorF::Indigo);

    gradientStops [1] .position = 1.f;  
 
    m_pLinearGradientBrush = CD2DLinearGradientBrush(GetRenderTarget() novo,   
    gradientStops, ARRAYSIZE(gradientStops),  
    D2D1::LinearGradientBrushProperties (D2D1::Point2F (0, 0), D2D1::Point2F (0, 0)));

 ```  
  
     Save the file and close it.  
  
### To modify the gradient brush so that it will change appropriately when the window is resized  
  
1.  On the **Project** menu, click **Class Wizard**.  
  
2.  In the **MFC Class Wizard**, under **Class name**, select `CMFCD2DWalkthroughView`.  
  
3.  On the **Messages** tab, in the **Messages** box, select `WM_SIZE` and then click **Add Handler**. This action adds the `OnSize` message handler to the `CMFCD2DWalkthroughView` class.  
  
4.  In the **Existing handlers** box, select `OnSize`. Click **Edit Code** to display the `CMFCD2DWalkthroughView::OnSize` method. At the end of the method, add the following code.  
  
 ```  
    m_pLinearGradientBrush -> SetEndPoint (CPoint (cx, cy));

 ```  
  
     Save the file and close it.  
  
### To implement a D2D drawing handler  
  
1.  On the **Project** menu, click **Class Wizard**.  
  
2.  In the **MFC Class Wizard**, under **Class name**, select `CMFCD2DWalkthroughView`.  
  
3.  On the **Messages** tab, click **Add Custom Message**.  
  
4.  In the **Add Custom Message** dialog box, in the **Custom Windows Message** box, type `AFX_WM_DRAW2D`. In the **Message handler name** box, type `OnDraw2D`. Select the **Registered Message** option and then click **OK**. This action adds a message handler for the `AFX_WM_DRAW2D` message to the `CMFCD2DWalkthroughView` class.  
  
5.  In the **Existing handlers** box, select `OnDraw2D`. Click **Edit Code** to display the `CMFCD2DWalkthroughView::OnDraw2D` method. Use the following code for the `CMFCD2DWalkthroughView::OnDrawD2D` method.  
  
 ```  
    afx_msg LRESULT CMFCD2DWalkthroughView::OnDraw2D(WPARAM wParam, LPARAM lParam)  
    {  
 CHwndRenderTarget * pRenderTarget = (CHwndRenderTarget *) lParam;  
    ASSERT_VALID(pRenderTarget);

 
    CRect rect;  
    GetClientRect(rect);

 
    pRenderTarget -> FillRectangle (rect, m_pLinearGradientBrush);

    pRenderTarget -> DrawText (rect ("Olá, mundo!"), de t, m_pBlackBrush, m_pTextFormat);

 
    retornar TRUE;  
 }  
 ```  
  
     Save the file and close it.  
  
### To verify the results  
  
1.  Build and run the application. It should have a gradient rectangle that changes when you resize the window. “Hello World!” should be displayed in the center of the rectangle.  
  
## See Also  
 [Walkthroughs](../mfc/walkthroughs-mfc.md)

