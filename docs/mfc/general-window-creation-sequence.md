---
title: Sequência de criação da janela geral
ms.date: 11/04/2016
helpviewer_keywords:
- sequence [MFC], window creation
- frame windows [MFC], creating
- windows [MFC], creating
- sequence [MFC]
ms.assetid: 9cd8c7ea-5e24-429e-b6d9-d7b6041d8ba6
ms.openlocfilehash: 63b5e0131642692d9372c148827a583f19114fb9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223155"
---
# <a name="general-window-creation-sequence"></a>Sequência de criação da janela geral

Quando você cria uma janela própria, como uma janela filho, a estrutura usa muito o mesmo processo descrito em [criação de documento/exibição](document-view-creation.md).

Todas as classes de janela fornecidas pelo MFC empregam [a construção de dois estágios](one-stage-and-two-stage-construction-of-objects.md). Ou seja, durante uma invocação do operador C++ **`new`** , o Construtor aloca e inicializa um objeto c++, mas não cria uma janela correspondente do Windows. Isso é feito depois de chamar a função de membro [Create](reference/cwnd-class.md#create) do objeto Window.

A `Create` função de membro torna a janela do Windows e armazena sua `HWND` no membro de dados públicos do objeto C++ [m_hWnd](reference/cwnd-class.md#m_hwnd). `Create`oferece flexibilidade completa sobre os parâmetros de criação. Antes de chamar, convém `Create` registrar uma classe de janela com a função global [AfxRegisterWndClass](reference/application-information-and-management.md#afxregisterwndclass) para definir o ícone e os estilos de classe para o quadro.

Para janelas de quadros, você pode usar a função de membro [LoadFrame](reference/cframewnd-class.md#loadframe) em vez de `Create` . `LoadFrame`faz com que a janela do Windows use menos parâmetros. Ele obtém muitos valores padrão de recursos, incluindo a legenda, o ícone, a tabela de acelerador e o menu do quadro.

> [!NOTE]
> Seus recursos de ícone, tabela de aceleração e menu devem ter uma ID de recurso comum, como **IDR_MAINFRAME**, para que eles sejam carregados pelo LoadFrame.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Objetos de janela](window-objects.md)

- [Registrando "classes" de janela](registering-window-classes.md)

- [Destruindo objetos de janela](destroying-window-objects.md)

- [Criando janelas com moldura de documento](creating-document-frame-windows.md)

## <a name="see-also"></a>Confira também

[Criando o Windows](creating-windows.md)
