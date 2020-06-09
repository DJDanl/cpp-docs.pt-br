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
ms.openlocfilehash: 399230446977636cc8769efe32b8f86fad466b83
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616111"
---
# <a name="deriving-a-document-class-from-cdocument"></a>Derivando uma classe de documento de CDocument

Os documentos contêm e gerenciam os dados do aplicativo. Para usar a classe de documento fornecida pelo assistente de aplicativo MFC, você deve fazer o seguinte:

- Derive uma classe de `CDocument` para cada tipo de documento.

- Adicione variáveis de membro para armazenar os dados de cada documento.

- `CDocument`Função de `Serialize` membro de substituição em sua classe de documento. `Serialize`grava e lê os dados do documento de e para o disco.

## <a name="other-document-functions-often-overridden"></a>Outras funções de documento geralmente substituídas

Talvez você também queira substituir outras `CDocument` funções de membro. Em particular, muitas vezes você precisará substituir [OnNewDocument](reference/cdocument-class.md#onnewdocument) e [OnOpenDocument](reference/cdocument-class.md#onopendocument) para inicializar os membros de dados do documento e [DeleteContents](reference/cdocument-class.md#deletecontents) para destruir dados alocados dinamicamente. Para obter informações sobre Membros substituíveis, consulte classe [CDocument](reference/cdocument-class.md) na *referência do MFC*.

## <a name="see-also"></a>Consulte também

[Usando documentos](using-documents.md)
