---
title: Limpando documentos e exibições
ms.date: 11/04/2016
helpviewer_keywords:
- views [MFC], cleaning up
- documents [MFC], cleaning up
- documents [MFC], closing
ms.assetid: 0c454db2-3644-434d-9e53-8108a7aedfe1
ms.openlocfilehash: 8cb6e9337b69daf78286f57898c9badf513c7921
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626521"
---
# <a name="cleaning-up-documents-and-views"></a>Limpando documentos e exibições

Quando um documento está sendo fechado, a estrutura primeiro chama sua função de membro [DeleteContents](reference/cdocument-class.md#deletecontents) . Se você tiver alocado alguma memória no heap durante a operação do documento, `DeleteContents` será o melhor lugar para desalocá-la.

> [!NOTE]
> Você não deve desalocar dados do documento no destruidor do documento. No caso de um aplicativo SDI, o objeto Document pode ser reutilizado.

Você pode substituir o destruidor de uma exibição para desalocar qualquer memória alocada no heap.

## <a name="see-also"></a>Consulte também

[Inicializando e limpando documentos e exibições](initializing-and-cleaning-up-documents-and-views.md)
