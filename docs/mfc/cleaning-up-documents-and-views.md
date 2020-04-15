---
title: Limpando documentos e exibições
ms.date: 11/04/2016
helpviewer_keywords:
- views [MFC], cleaning up
- documents [MFC], cleaning up
- documents [MFC], closing
ms.assetid: 0c454db2-3644-434d-9e53-8108a7aedfe1
ms.openlocfilehash: 06ff60a2cf6245f64e80d899c13a8444558fcf0b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374617"
---
# <a name="cleaning-up-documents-and-views"></a>Limpando documentos e exibições

Quando um documento está fechando, a estrutura primeiro chama sua função de membro [DeleteContents.](../mfc/reference/cdocument-class.md#deletecontents) Se você alocou qualquer memória no heap durante `DeleteContents` o curso da operação do documento, é o melhor lugar para desalocá-la.

> [!NOTE]
> Você não deve desalocar dados de documentos no destruidor do documento. No caso de um aplicativo SDI, o objeto do documento pode ser reutilizado.

Você pode substituir o destruidor de uma vista para desalocar qualquer memória que você alocou no monte.

## <a name="see-also"></a>Confira também

[Inicializando e limpando documentos e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)
