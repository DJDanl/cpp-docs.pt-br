---
title: Sequência de criação da janela geral
ms.date: 11/04/2016
helpviewer_keywords:
- sequence [MFC], window creation
- frame windows [MFC], creating
- windows [MFC], creating
- sequence [MFC]
ms.assetid: 9cd8c7ea-5e24-429e-b6d9-d7b6041d8ba6
ms.openlocfilehash: fb10ced78e230316a6e2982f24c1fb6e2e52ed8d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364268"
---
# <a name="general-window-creation-sequence"></a>Sequência de criação da janela geral

Quando você cria uma janela própria, como uma janela filho, a estrutura usa o mesmo processo descrito na [Criação de Documentos/Exibição](../mfc/document-view-creation.md).

Todas as classes de janelas fornecidas pela MFC empregam [construção em duas etapas](../mfc/one-stage-and-two-stage-construction-of-objects.md). Ou seja, durante uma invocação do **novo** operador C++, o construtor aloca e inicializa um objeto C++, mas não cria uma janela do Windows correspondente. Isso é feito depois, chamando a função [Criar](../mfc/reference/cwnd-class.md#create) membro do objeto da janela.

A `Create` função de membro torna `HWND` a janela do Windows e armazena a sua no membro de dados públicos do objeto C++ [m_hWnd](../mfc/reference/cwnd-class.md#m_hwnd). `Create`dá total flexibilidade sobre os parâmetros de criação. Antes `Create`de ligar, você pode querer registrar uma classe de janela com a função global [AfxRegisterWndClass,](../mfc/reference/application-information-and-management.md#afxregisterwndclass) a fim de definir o ícone e os estilos de classe para o quadro.

Para janelas de quadro, você pode usar `Create`a função [membro LoadFrame](../mfc/reference/cframewnd-class.md#loadframe) em vez de . `LoadFrame`faz com que a janela do Windows use menos parâmetros. Ele obtém muitos valores padrão de recursos, incluindo legenda, ícone, tabela do acelerador e menu do quadro.

> [!NOTE]
> Seu ícone, tabela de aceleração e recursos de menu devem ter um ID de recurso comum, como **IDR_MAINFRAME**, para que eles sejam carregados pelo LoadFrame.

## <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Objetos de janela](../mfc/window-objects.md)

- [Registrando "classes" da janela](../mfc/registering-window-classes.md)

- [Destruindo objetos de janela](../mfc/destroying-window-objects.md)

- [Criando janelas de quadrode documentos](../mfc/creating-document-frame-windows.md)

## <a name="see-also"></a>Confira também

[Criando janelas](../mfc/creating-windows.md)
