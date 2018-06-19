---
title: Derivando uma classe de documento de CDocument | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CDocument class [MFC], deriving from
- classes [MFC], deriving from CDocument
- document objects [MFC], derived
- derived classes [MFC], functions often overridden
- document classes [MFC], functions often overridden
ms.assetid: e6a198e0-9799-43c0-83c5-04174d8b532c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 698957d4e307ad1f099d5aef7de131c538ee4871
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33342612"
---
# <a name="deriving-a-document-class-from-cdocument"></a>Derivando uma classe de documento de CDocument
Documentos contêm e gerenciam os dados do aplicativo. Para usar a classe de documento fornecido pelo Assistente de aplicativo MFC, faça o seguinte:  
  
-   Derive uma classe de **CDocument** para cada tipo de documento.  
  
-   Adicione variáveis de membro para armazenar dados de cada documento.  
  
-   Substituir **CDocument**do `Serialize` a função de membro em sua classe de documento. `Serialize` grava e lê os dados do documento para e de disco.  
  
## <a name="other-document-functions-often-overridden"></a>Outras funções de documento substituídas com frequência  
 Talvez você queira substituir outras **CDocument** funções de membro. Em particular, você geralmente precisará substituir [OnNewDocument](../mfc/reference/cdocument-class.md#onnewdocument) e [OnOpenDocument](../mfc/reference/cdocument-class.md#onopendocument) para inicializar os membros de dados do documento e [DeleteContents](../mfc/reference/cdocument-class.md#deletecontents) destruir dados alocados dinamicamente. Para obter informações sobre membros, consulte a classe [CDocument](../mfc/reference/cdocument-class.md) no *referência MFC*.  
  
## <a name="see-also"></a>Consulte também  
 [Usando documentos](../mfc/using-documents.md)

