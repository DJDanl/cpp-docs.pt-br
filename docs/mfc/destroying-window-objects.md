---
title: Destruindo objetos de janela | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- frame windows [MFC], destroying
- window objects [MFC], deleting
- window objects [MFC], destroying
- window objects [MFC], removing
ms.assetid: 3241fea0-c614-4a25-957d-20f21bd5fd0c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 704122f028cd744f0ce064f0153825830144d5b7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46401635"
---
# <a name="destroying-window-objects"></a>Destruindo objetos de janela

Deve ter cuidado com suas próprias janelas filho para destruir o objeto de janela C++ quando o usuário é concluído com a janela. Se esses objetos não são destruídos, seu aplicativo não recuperará a memória. Felizmente, a estrutura gerencia a destruição de janela, bem como a criação de janelas de quadro, exibições e caixas de diálogo. Se você criar janelas adicionais, você é responsável por destrui-los.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Sequência de destruição da janela](../mfc/window-destruction-sequence.md)

- [Alocando e desalocando a memória da janela](../mfc/allocating-and-deallocating-window-memory.md)

- [Desanexando um CWnd de HWND](../mfc/detaching-a-cwnd-from-its-hwnd.md)

- [Sequência de criação da janela geral](../mfc/general-window-creation-sequence.md)

- [Destruindo janelas com moldura](../mfc/destroying-frame-windows.md)

## <a name="see-also"></a>Consulte também

[Objetos de janela](../mfc/window-objects.md)

