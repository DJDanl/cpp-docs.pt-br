---
title: "Instru&#231;&#245;es passo a passo: adicionando um objeto D2D a um projeto | Microsoft Docs"
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
  - "D2D [MFC]"
  - "MFC, D2D"
ms.assetid: dda36c33-c231-4da6-a62f-72d69a12b6dd
caps.latest.revision: 20
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: adicionando um objeto D2D a um projeto
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este passo a passo ensina como adicionar um objeto básico do Visual C\+\+, um projeto de Direct2D \(D2D\) da biblioteca de classes do Microsoft \(MFC\), e então constrói o projeto em um aplicativo que cópias “hello world”, em um plano de fundo da gradação.  
  
 O passo a passo mostra como executar essas tarefas:  
  
-   Crie um aplicativo MFC.  
  
-   Crie uma escova de cor sólida e uma escova de linear\- gradação.  
  
-   Modifique a escova da gradação de forma que se modifique adequadamente quando a janela é redimensionada.  
  
-   Implementar um manipulador de desenho de D2D.  
  
-   Verificar os resultados.  
  
 [!INCLUDE[note_settings_general](../mfc/includes/note_settings_general_md.md)]  
  
## Pré-requisitos  
 Para concluir este passo a passo, você deve ter o Visual Studio.  
  
### Para criar um aplicativo de MFC  
  
1.  No menu **Arquivo**, aponte para **Novo** e clique em **Projeto**.  
  
2.  Na caixa de diálogo de **Novo Projeto** , no painel esquerdo em **Modelos Instalados**, expanda **Visual C\+\+** e selecione **MFC**.  No painel central, **Aplicativo do MFC**selecione.  Na caixa de **Nome** , digite `MFCD2DWalkthrough`.  Clique em **OK**.  
  
3.  Em **Assistente para Aplicativo do MFC**, clique **Concluir** sem que nenhuma configurações.  
  
### Para criar uma escova de cor sólida e uma escova de linear\- gradação  
  
1.  Em **Gerenciador de Soluções**, no projeto de **MFCD2DWalkthrough** , na pasta de **Arquivos de Cabeçalho** , abra MFCD2DWalkthroughView.h.  Adicione o seguinte código na classe de `CMFCD2DWalkthroughView` para criar três variáveis de dados.  
  
    ```  
    CD2DTextFormat* m_pTextFormat;  
    CD2DSolidColorBrush* m_pBlackBrush;  
    CD2DLinearGradientBrush* m_pLinearGradientBrush;  
    ```  
  
     Salve o arquivo e feche\-o.  
  
2.  Na pasta de **Arquivos de Origem** , abra MFCD2DWalkthroughView.cpp.  No construtor da classe de `CMFCD2DWalkthroughView` , adicione o seguinte código.  
  
    ```  
    // Enable D2D support for this window:  
    EnableD2DSupport();  
  
    // Initialize D2D resources:  
    m_pBlackBrush = new CD2DSolidColorBrush(GetRenderTarget(), D2D1::ColorF(D2D1::ColorF::Black));  
  
    m_pTextFormat = new CD2DTextFormat(GetRenderTarget(), _T("Verdana"), 50);  
    m_pTextFormat->Get()->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);  
    m_pTextFormat->Get()->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);  
  
    D2D1_GRADIENT_STOP gradientStops[2];  
  
    gradientStops[0].color = D2D1::ColorF(D2D1::ColorF::White);  
    gradientStops[0].position = 0.f;  
    gradientStops[1].color = D2D1::ColorF(D2D1::ColorF::Indigo);  
    gradientStops[1].position = 1.f;  
  
    m_pLinearGradientBrush = new CD2DLinearGradientBrush(GetRenderTarget(),   
        gradientStops, ARRAYSIZE(gradientStops),  
        D2D1::LinearGradientBrushProperties(D2D1::Point2F(0, 0), D2D1::Point2F(0, 0)));  
    ```  
  
     Salve o arquivo e feche\-o.  
  
### Para alterar a escova da gradação de forma que se modifique adequadamente quando a janela é redimensionada  
  
1.  No menu de **Projeto** , clique em **Assistente de classe**.  
  
2.  Em **Assistente de Classe MFC**, em **Nome da classe**, `CMFCD2DWalkthroughView`selecione.  
  
3.  Na guia de **Mensagens** , na caixa de **Mensagens** , `WM_SIZE` selecione e clique em **Adicionar Manipulador**.  Essa ação adiciona o manipulador de mensagens de `OnSize` à classe de `CMFCD2DWalkthroughView` .  
  
4.  Na caixa de **Manipuladores existentes** , `OnSize`selecione.  Clique em **Editar Código** para exibir o método de `CMFCD2DWalkthroughView::OnSize` .  No final do método, adicione o seguinte código.  
  
    ```  
    m_pLinearGradientBrush->SetEndPoint(CPoint(cx, cy));  
    ```  
  
     Salve o arquivo e feche\-o.  
  
### Para implementar um manipulador de desenho de D2D  
  
1.  No menu de **Projeto** , clique em **Assistente de classe**.  
  
2.  Em **Assistente de Classe MFC**, em **Nome da classe**, `CMFCD2DWalkthroughView`selecione.  
  
3.  Na guia de **Mensagens** , clique **Adicionar Mensagem Personalizada**.  
  
4.  Na caixa de diálogo de **Adicionar Mensagem Personalizada** , na caixa de **Mensagem Personalizada do Windows** , tipo `AFX_WM_DRAW2D`.  Na caixa de **Nome do Manipulador de Mensagens** , digite `OnDraw2D`.  Selecione a opção de **Mensagem Registrada** e clique em **OK**.  Essa ação adiciona um manipulador da mensagem de `AFX_WM_DRAW2D` à classe de `CMFCD2DWalkthroughView` .  
  
5.  Na caixa de **Manipuladores existentes** , `OnDraw2D`selecione.  Clique em **Editar Código** para exibir o método de `CMFCD2DWalkthroughView::OnDraw2D` .  Use o seguinte código para o método de `CMFCD2DWalkthroughView::OnDrawD2D` .  
  
    ```  
    afx_msg LRESULT CMFCD2DWalkthroughView::OnDraw2D(WPARAM wParam, LPARAM lParam)  
    {  
        CHwndRenderTarget* pRenderTarget = (CHwndRenderTarget*)lParam;  
        ASSERT_VALID(pRenderTarget);  
  
        CRect rect;  
        GetClientRect(rect);  
  
        pRenderTarget->FillRectangle(rect, m_pLinearGradientBrush);  
        pRenderTarget->DrawText(_T("Hello, World!"), rect, m_pBlackBrush, m_pTextFormat);  
  
        return TRUE;  
    }  
    ```  
  
     Salve o arquivo e feche\-o.  
  
### Para verificar os resultados  
  
1.  Criar e executar o aplicativo.  Deve ter um retângulo de gradação que altera quando você redimensionar a janela. “Hello world\!” deve ser exibido no centro do retângulo.  
  
## Consulte também  
 [Explicações Passo\-a\-passo](../mfc/walkthroughs-mfc.md)