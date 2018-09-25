---
title: 'Passo a passo: Adicionando um objeto D2D a um projeto MFC | Microsoft Docs'
ms.custom: ''
ms.date: 09/20/2018
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
ms.openlocfilehash: 6117b17421e37238c9bc585677eb7b0c8ed557fb
ms.sourcegitcommit: edb46b0239a0e616af4ec58906e12338c3e8d2c6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2018
ms.locfileid: "47169652"
---
# <a name="walkthrough-adding-a-d2d-object-to-an-mfc-project"></a>Instruções passo a passo: adicionando um objeto D2D a um projeto

Este passo a passo ensina como adicionar um Direct2D básica (D2D) do objeto para um Visual C++, o projeto de biblioteca do Microsoft Foundation Class (MFC) e, em seguida, compile o projeto em um aplicativo que imprime "Hello, world" em um plano de fundo gradiente.

O passo a passo mostra como realizar essas tarefas:

- Crie um aplicativo do MFC.

- Crie um pincel de cor sólida e um pincel de gradiente linear.

- Modificar o pincel de gradiente para que ele será alterado apropriadamente quando a janela é redimensionada.

- Implemente um manipulador de desenho D2D.

- Verifique se os resultados.

[!INCLUDE[note_settings_general](../mfc/includes/note_settings_general_md.md)]

## <a name="prerequisites"></a>Pré-requisitos

Para concluir este passo a passo, você deve ter o Visual Studio instalada com o **desenvolvimento para Desktop com C++** carga de trabalho e opcional **Visual C++ MFC para x86 e x64** componente.

## <a name="to-create-an-mfc-application"></a>Para criar um aplicativo do MFC

1. Sobre o **arquivo** , aponte para **New** e, em seguida, escolha **projeto**.

1. No **novo projeto** caixa de diálogo, no painel esquerdo, em **modelos instalados**, expanda **Visual C++** e, em seguida, selecione **MFC**. No painel central, selecione **aplicativo do MFC**. No **nome** , digite *MFCD2DWalkthrough*. Escolha **OK**.

1. No **Assistente de aplicativo MFC**, escolha **concluir** sem alterar as configurações.

## <a name="to-create-a-solid-color-brush-and-a-linear-gradient-brush"></a>Para criar um pincel de cor sólida e um pincel de gradiente linear

1. Na **Gerenciador de soluções**, no **MFCD2DWalkthrough** projeto, o **arquivos de cabeçalho** MFCD2DWalkthroughView.h Abrir pasta. Adicione este código para o `CMFCD2DWalkthroughView` classe para criar três variáveis de dados:

   ```cpp
   CD2DTextFormat* m_pTextFormat;
   CD2DSolidColorBrush* m_pBlackBrush;
   CD2DLinearGradientBrush* m_pLinearGradientBrush;
   ```

   Salve o arquivo e fechá-lo.

1. No **arquivos de origem** MFCD2DWalkthroughView.cpp Abrir pasta. No construtor para o `CMFCD2DWalkthroughView` de classe, adicione este código:

   ```cpp
   // Enable D2D support for this window:
   EnableD2DSupport();

   // Initialize D2D resources:
   m_pBlackBrush = new CD2DSolidColorBrush(
       GetRenderTarget(),
       D2D1::ColorF(D2D1::ColorF::Black));

   m_pTextFormat = new CD2DTextFormat(
       GetRenderTarget(),
       _T("Verdana"),
       50);

   m_pTextFormat->Get()->SetTextAlignment(
       DWRITE_TEXT_ALIGNMENT_CENTER);

   m_pTextFormat->Get()->SetParagraphAlignment(
       DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

   D2D1_GRADIENT_STOP gradientStops[2];

   gradientStops[0].color =
       D2D1::ColorF(D2D1::ColorF::White);

   gradientStops[0].position = 0.f;
   gradientStops[1].color =
       D2D1::ColorF(D2D1::ColorF::Indigo);

   gradientStops[1].position = 1.f;

   m_pLinearGradientBrush = new CD2DLinearGradientBrush(
       GetRenderTarget(),
       gradientStops,
       ARRAYSIZE(gradientStops),
       D2D1::LinearGradientBrushProperties(
           D2D1::Point2F(0,0),
           D2D1::Point2F(0,0)));
   ```

   Salve o arquivo e fechá-lo.

## <a name="to-modify-the-gradient-brush-so-that-it-will-change-appropriately-when-the-window-is-resized"></a>Para modificar o pincel de gradiente para que ele será alterado apropriadamente quando a janela é redimensionada

1. Sobre o **Project** menu, escolha **Class Wizard**.

1. No **MFC Class Wizard**, em **nome da classe**, selecione `CMFCD2DWalkthroughView`.

1. Sobre o **mensagens** guia da **mensagens** caixa, selecione `WM_SIZE` e, em seguida, escolha **Add Handler**. Essa ação adiciona o `OnSize` manipulador de mensagens para o `CMFCD2DWalkthroughView` classe.

1. No **manipuladores existentes** caixa, selecione `OnSize`. Escolher **Edit Code** para exibir o `CMFCD2DWalkthroughView::OnSize` método. No final do método, adicione o código a seguir.

   ```cpp
   m_pLinearGradientBrush->SetEndPoint(CPoint(cx, cy));
   ```

   Salve o arquivo e fechá-lo.

## <a name="to-implement-a-d2d-drawing-handler"></a>Implementar um manipulador de desenho D2D

1. Sobre o **Project** menu, escolha **Class Wizard**.

1. No **MFC Class Wizard**, em **nome da classe**, selecione `CMFCD2DWalkthroughView`.

1. Sobre o **mensagens** guia, escolha **adicionar personalizado mensagem**.

1. No **adicionar personalizado mensagem** na caixa de **Custom Windows Message** , digite *AFX_WM_DRAW2D*. No **nome do manipulador de mensagem** , digite *OnDraw2D*. Selecione o **mensagem registrada** opção e, em seguida, escolha **Okey**. Essa ação adiciona um manipulador de mensagens para a mensagem AFX_WM_DRAW2D o `CMFCD2DWalkthroughView` classe.

1. No **manipuladores existentes** caixa, selecione `OnDraw2D`. Escolher **Edit Code** para exibir o `CMFCD2DWalkthroughView::OnDraw2D` método. Use este código para o `CMFCD2DWalkthroughView::OnDrawD2D` método:

   ```cpp
   afx_msg LRESULT CMFCD2DWalkthroughView::OnDraw2D(
       WPARAM wParam,
       LPARAM lParam)
   {
       CHwndRenderTarget* pRenderTarget = (CHwndRenderTarget*)lParam;
       ASSERT_VALID(pRenderTarget);

       CRect rect;
       GetClientRect(rect);

       pRenderTarget->FillRectangle(rect, m_pLinearGradientBrush);

       pRenderTarget->DrawText(
           _T("Hello, World!"),
           rect,
           m_pBlackBrush,
           m_pTextFormat);

       return TRUE;
   }
   ```

   Salve o arquivo e fechá-lo.

## <a name="to-verify-the-results"></a>Para verificar os resultados

Crie e execute o aplicativo. Ele deve ter um retângulo de gradiente que muda quando você redimensiona a janela. "Hello World!" deve ser exibido no centro do retângulo.

## <a name="see-also"></a>Consulte também

[Explicações Passo a Passo](../mfc/walkthroughs-mfc.md)
