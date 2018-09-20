---
title: Função da exibição na impressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- views [MFC], printing
- OnDraw method [MFC], and printing
- printing [MFC], OnDraw method [MFC]
- printing [MFC], views
- CView class [MFC], role in printing
- printing views [MFC]
ms.assetid: 8d4a3c8e-1fce-4edc-b608-94cb5f3e487e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4c78756ea84df66b77f71d8f8ad8d0b9dfa1a6c9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46377520"
---
# <a name="role-of-the-view-in-printing"></a>Função da exibição na impressão

O modo de exibição também desempenha duas funções importantes no seu documento associado de impressão.

O modo de exibição:

- Usa as mesmas [OnDraw](../mfc/reference/cview-class.md#ondraw) código para desenhar na impressora para desenhar na tela.

- Gerencia a dividir o documento em páginas para impressão.

Para obter mais informações sobre impressão e a função da exibição na impressão, consulte [impressão e visualização de impressão](../mfc/printing-and-print-preview.md).

## <a name="see-also"></a>Consulte também

[Usando exibições](../mfc/using-views.md)

