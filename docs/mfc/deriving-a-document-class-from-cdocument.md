---
title: Derivando uma classe de documento de CDocument
ms.date: 11/04/2016
helpviewer_keywords:
- CDocument class [MFC], deriving from
- classes [MFC], deriving from CDocument
- document objects [MFC], derived
- derived classes [MFC], functions often overridden
- document classes [MFC], functions often overridden
ms.assetid: e6a198e0-9799-43c0-83c5-04174d8b532c
ms.openlocfilehash: 042ba7adc8d36e57a714e03ec67c1c0f22b4da78
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50496116"
---
# <a name="deriving-a-document-class-from-cdocument"></a>Derivando uma classe de documento de CDocument

Documentos contêm e gerenciem os dados do aplicativo. Para usar a classe de documento fornecido pelo Assistente de aplicativo MFC, faça o seguinte:

- Derive uma classe de `CDocument` para cada tipo de documento.

- Adicione variáveis de membro para armazenar dados de cada documento.

- Substituir `CDocument`do `Serialize` a função de membro em sua classe de documento. `Serialize` grava e lê os dados do documento para e do disco.

## <a name="other-document-functions-often-overridden"></a>Outras funções de documento substituídas com frequência

Você também deseja substituir outros `CDocument` funções de membro. Em particular, você geralmente precisará substituir [OnNewDocument](../mfc/reference/cdocument-class.md#onnewdocument) e [OnOpenDocument](../mfc/reference/cdocument-class.md#onopendocument) para inicializar membros de dados do documento e [DeleteContents](../mfc/reference/cdocument-class.md#deletecontents) destruir dados alocados dinamicamente. Para obter informações sobre os membros substituíveis, consulte a classe [CDocument](../mfc/reference/cdocument-class.md) na *referência da MFC*.

## <a name="see-also"></a>Consulte também

[Usando documentos](../mfc/using-documents.md)

