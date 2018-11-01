---
title: Limpando documentos e exibições
ms.date: 11/04/2016
helpviewer_keywords:
- views [MFC], cleaning up
- documents [MFC], cleaning up
- documents [MFC], closing
ms.assetid: 0c454db2-3644-434d-9e53-8108a7aedfe1
ms.openlocfilehash: 1357a02379a848af23a6f78dee29e5b6adc1efcc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50653889"
---
# <a name="cleaning-up-documents-and-views"></a>Limpando documentos e exibições

Quando um documento está sendo fechado, o framework chama primeiro seu [DeleteContents](../mfc/reference/cdocument-class.md#deletecontents) função de membro. Se você tiver atribuído qualquer memória no heap no decorrer da operação do documento, `DeleteContents` é o melhor lugar para desalocá-la.

> [!NOTE]
>  Você não deverá desalocar os dados de documentos no destruidor do documento. No caso de um aplicativo SDI, o objeto do documento poderá ser reutilizado.

Você pode substituir o destruidor do modo de exibição para desalocar toda a memória alocada no heap.

## <a name="see-also"></a>Consulte também

[Inicializando e limpando documentos e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)

