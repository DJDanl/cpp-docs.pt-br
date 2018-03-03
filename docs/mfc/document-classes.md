---
title: Classes de documento | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.classes.document
dev_langs:
- C++
helpviewer_keywords:
- document classes [MFC]
ms.assetid: 4bf19b02-0a4f-4319-b68e-cddcba2705cb
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5a2436b46b7486bd30398dffc530d2adea3d2e48
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="document-classes"></a>Classes de documento
Objetos de classe de documento, criados por objetos de modelo de documento, gerenciam os dados do aplicativo. Você irá derivar uma classe para seus documentos de uma dessas classes.  
  
 Objetos de classe de documento interagirem com objetos de exibição. Exibir objetos representam a área cliente de uma janela, exibem dados de um documento e permitir que os usuários interajam com ele. Documentos e exibições são criadas por um objeto de modelo de documento.  
  
 [CDocument](../mfc/reference/cdocument-class.md)  
 A classe base para documentos específicos do aplicativo. Derive a classe de documento ou classes de **CDocument**.  
  
 [COleDocument](../mfc/reference/coledocument-class.md)  
 Usado para a implementação do documento composto, bem como suporte básicos do contêiner. Funciona como um contêiner para classes derivadas de [CDocItem](../mfc/reference/cdocitem-class.md). Essa classe pode ser usada como a classe base para o contêiner de documentos e é a classe base para `COleServerDoc`.  
  
 [COleLinkingDoc](../mfc/reference/colelinkingdoc-class.md)  
 Uma classe derivada de `COleDocument` que fornece a infraestrutura para vinculação. Você deve derivar de classes de documento para seus aplicativos de contêiner desta classe em vez de `COleDocument` se você deseja dar suporte a links para objetos inseridos.  
  
 [CRichEditDoc](../mfc/reference/cricheditdoc-class.md)  
 Mantém a lista de itens de cliente OLE que estão no controle de edição avançada. Usado com [CRichEditView](../mfc/reference/cricheditview-class.md) e [CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md).  
  
 [COleServerDoc](../mfc/reference/coleserverdoc-class.md)  
 Usado como a classe base para classes de documento do aplicativo de servidor. `COleServerDoc`objetos fornecem a maior parte do suporte do servidor por meio de interações com [COleServerItem](../mfc/reference/coleserveritem-class.md) objetos. Recurso de edição visual é fornecido usando a arquitetura de documento/exibição da biblioteca de classes.  
  
 [CHtmlEditDoc](../mfc/reference/chtmleditdoc-class.md)  
 Fornece, com [CHtmlEditView](../mfc/reference/chtmleditview-class.md), a funcionalidade da plataforma de edição de HTML WebBrowser dentro do contexto da arquitetura do modo de exibição de documentos do MFC.  
  
## <a name="related-classes"></a>Classes relacionadas  
 Objetos de classe de documento podem ser persistentes — em outras palavras, eles podem gravar seu estado em uma mídia de armazenamento e lê-lo novamente. MFC fornece o `CArchive` classe para facilitar a transferência de dados do documento para uma mídia de armazenamento.  
  
 [CArchive](../mfc/reference/carchive-class.md)  
 Coopera com um [CFile](../mfc/reference/cfile-class.md) objeto para implementar o armazenamento persistente de objetos por meio de serialização (consulte [CObject::Serialize](../mfc/reference/cobject-class.md#serialize)).  
  
 Documentos também podem conter objetos OLE. `CDocItem`é a classe base dos itens de servidor e cliente.  
  
 [CDocItem](../mfc/reference/cdocitem-class.md)  
 Classe abstrata base de [COleClientItem](../mfc/reference/coleclientitem-class.md) e [COleServerItem](../mfc/reference/coleserveritem-class.md). Objetos de classes derivam de `CDocItem` representar partes de documentos.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

