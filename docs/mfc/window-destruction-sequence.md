---
title: Sequência de destruição da janela
ms.date: 11/04/2016
helpviewer_keywords:
- destruction, windows
- destroying windows
- sequence [MFC], window destruction
- CWnd objects [MFC], destruction sequence
- sequence [MFC]
- windows [MFC], destroying
ms.assetid: 2d819196-6240-415f-a308-db43745e616c
ms.openlocfilehash: d4592e6ac0077d6bc335b50f2d67b140402b4fe2
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57287655"
---
# <a name="window-destruction-sequence"></a>Sequência de destruição da janela

No framework MFC, quando o usuário fecha a janela de quadro, o padrão da janela [OnClose](../mfc/reference/cwnd-class.md#onclose) chamadas do manipulador [DestroyWindow](../mfc/reference/cwnd-class.md#destroywindow). É a última função de membro chamada quando a janela do Windows é destruída [OnNcDestroy](../mfc/reference/cwnd-class.md#onncdestroy), que faz alguma limpeza, chama o [padrão](../mfc/reference/cwnd-class.md#default) membro de função para executar a limpeza do Windows e, por fim, chama o função membro virtual [PostNcDestroy](../mfc/reference/cwnd-class.md#postncdestroy). O [CFrameWnd](../mfc/reference/cframewnd-class.md) implementação de `PostNcDestroy` exclui o objeto de janela C++.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Alocando e desalocando a memória da janela](../mfc/allocating-and-deallocating-window-memory.md)

- [Desanexando um CWnd de HWND](../mfc/detaching-a-cwnd-from-its-hwnd.md)

## <a name="see-also"></a>Consulte também

[Destruindo objetos de janela](../mfc/destroying-window-objects.md)
