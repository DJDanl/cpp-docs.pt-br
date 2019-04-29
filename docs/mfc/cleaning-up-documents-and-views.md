---
title: Limpando documentos e exibições
ms.date: 11/04/2016
helpviewer_keywords:
- views [MFC], cleaning up
- documents [MFC], cleaning up
- documents [MFC], closing
ms.assetid: 0c454db2-3644-434d-9e53-8108a7aedfe1
ms.openlocfilehash: 940c768823d26950d9710fb1d1a52e6a1955fead
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62327152"
---
# <a name="cleaning-up-documents-and-views"></a>Limpando documentos e exibições

Quando um documento está sendo fechado, o framework chama primeiro seu [DeleteContents](../mfc/reference/cdocument-class.md#deletecontents) função de membro. Se você tiver atribuído qualquer memória no heap no decorrer da operação do documento, `DeleteContents` é o melhor lugar para desalocá-la.

> [!NOTE]
>  Você não deverá desalocar os dados de documentos no destruidor do documento. No caso de um aplicativo SDI, o objeto do documento poderá ser reutilizado.

Você pode substituir o destruidor do modo de exibição para desalocar toda a memória alocada no heap.

## <a name="see-also"></a>Consulte também

[Inicializando e limpando documentos e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)
