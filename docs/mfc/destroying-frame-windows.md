---
title: Destruindo janelas com moldura
ms.date: 11/04/2016
f1_keywords:
- PostNcDestroy
helpviewer_keywords:
- Default method [MFC]
- DestroyWindow method [MFC]
- frame windows [MFC], destroying
- OnNcDestroy method, and frame windows
- document frame windows [MFC], destroying
- destroying frame windows
- MFC, frame windows
- windows [MFC], destroying
- OnClose method [MFC]
- PostNcDestroy method [MFC]
ms.assetid: 5affca77-1999-4507-a2b2-9aa226611b4b
ms.openlocfilehash: b64298bd2b0f14c30c824d78947a17628adec8b5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394631"
---
# <a name="destroying-frame-windows"></a>Destruindo janelas com moldura

Estrutura MFC gerencia a destruição de janela, bem como a criação dessas janelas associadas com a estrutura de documentos e exibições. Se você criar janelas adicionais, você é responsável por destrui-los.

No framework, quando o usuário fecha a janela de quadro, o padrão da janela [OnClose](../mfc/reference/cwnd-class.md#onclose) chamadas do manipulador [DestroyWindow](../mfc/reference/cwnd-class.md#destroywindow). É a última função de membro chamada quando a janela do Windows é destruída [OnNcDestroy](../mfc/reference/cwnd-class.md#onncdestroy), que faz alguma limpeza, chama o [padrão](../mfc/reference/cwnd-class.md#default) membro de função para executar a limpeza do Windows e, por fim, chama o função membro virtual [PostNcDestroy](../mfc/reference/cwnd-class.md#postncdestroy). O [CFrameWnd](../mfc/reference/cframewnd-class.md) implementação de `PostNcDestroy` exclui o objeto de janela C++. Você nunca deve usar o C++ **excluir** operador em uma janela do quadro. Use `DestroyWindow` em seu lugar.

Quando a janela principal é fechada, o aplicativo é fechado. Se há forem modificados documentos não salvos, o framework exibe uma caixa de mensagem para perguntar se os documentos devem ser salvas e garante que os documentos apropriados são salvos se necessário.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Criando janelas com moldura de documento](../mfc/creating-document-frame-windows.md)

## <a name="see-also"></a>Consulte também

[Usando janelas com moldura](../mfc/using-frame-windows.md)
