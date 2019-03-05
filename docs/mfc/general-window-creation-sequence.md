---
title: Sequência de criação da janela geral
ms.date: 11/04/2016
helpviewer_keywords:
- sequence [MFC], window creation
- frame windows [MFC], creating
- windows [MFC], creating
- sequence [MFC]
ms.assetid: 9cd8c7ea-5e24-429e-b6d9-d7b6041d8ba6
ms.openlocfilehash: 949cf72910654b502ca4b57be72bedc2db63c315
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57269221"
---
# <a name="general-window-creation-sequence"></a>Sequência de criação da janela geral

Quando você cria uma janela de sua próprias, como um filho de janela, a estrutura usa muito o mesmo processo descrito em [criação de documento/exibição](../mfc/document-view-creation.md).

Todas as classes de janela fornecidas pelo empregam MFC [construção de dois estágios](../mfc/one-stage-and-two-stage-construction-of-objects.md). Ou seja, durante uma invocação do C++ **novo** operador, o construtor aloca e inicializa um objeto de C++, mas não cria uma janela do Windows correspondente. Isso é feito posteriormente por meio da chamada a [criar](../mfc/reference/cwnd-class.md#create) função de membro do objeto window.

O `Create` função de membro torna a janela do Windows e armazena suas `HWND` no membro de dados públicos do objeto C++ [m_hWnd](../mfc/reference/cwnd-class.md#m_hwnd). `Create` Fornece concluir flexibilidade sobre os parâmetros de criação. Antes de chamar `Create`, talvez você queira registrar uma classe de janela com a função global [AfxRegisterWndClass](../mfc/reference/application-information-and-management.md#afxregisterwndclass) para definir os estilos de ícone e a classe para o quadro.

Para janelas de quadro, você pode usar o [LoadFrame](../mfc/reference/cframewnd-class.md#loadframe) função de membro em vez de `Create`. `LoadFrame` torna a janela do Windows usando menos parâmetros. Ele obtém muitos valores padrão de recursos, incluindo a legenda do quadro, ícone, tabela de Aceleradores e menu.

> [!NOTE]
>  Seu ícone, tabela de Aceleradores e recursos de menu devem ter uma ID de recurso comuns, como **IDR_MAINFRAME**, para que eles possam ser carregados pelo LoadFrame.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Objetos de janela](../mfc/window-objects.md)

- [Registrando classes"janela"](../mfc/registering-window-classes.md)

- [Destruindo objetos de janela](../mfc/destroying-window-objects.md)

- [Criando janelas com moldura de documento](../mfc/creating-document-frame-windows.md)

## <a name="see-also"></a>Consulte também

[Criando janelas](../mfc/creating-windows.md)
