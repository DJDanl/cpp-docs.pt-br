---
title: Classes Container OLE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.ole
dev_langs:
- C++
helpviewer_keywords:
- ActiveX classes [MFC]
- container classes [MFC]
- OLE classes [MFC]
- visual editing [MFC], classes
- OLE [MFC], classes
- containers [MFC], OLE container applications
ms.assetid: 1e27e1ab-4c22-41eb-8547-6915c72668ae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cfdff6023beeedfa14d37e5b404fa3c223691b85
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="ole-container-classes"></a>Classes Container OLE
Essas classes são usadas por aplicativos de contêiner. Ambos `COleLinkingDoc` e `COleDocument` gerenciar coleções de `COleClientItem` objetos. Em vez de derivar de sua classe de documento da **CDocument**, vamos derivar de `COleLinkingDoc` ou `COleDocument`, dependendo se você quer o suporte para obter links para objetos incorporados no documento.  
  
 Use um `COleClientItem` objeto para representar cada item OLE no documento que é incorporado a partir de outro documento ou um link para outro documento.  
  
 [COleDocObjectItem](../mfc/reference/coledocobjectitem-class.md)  
 Dá suporte a contenção de documento ativo.  
  
 [COleDocument](../mfc/reference/coledocument-class.md)  
 Usado para a implementação do documento composto, bem como suporte básicos do contêiner. Funciona como um contêiner para classes derivadas de `CDocItem`. Essa classe pode ser usada como a classe base para o contêiner de documentos e é a classe base para `COleServerDoc`.  
  
 [COleLinkingDoc](../mfc/reference/colelinkingdoc-class.md)  
 Uma classe derivada de `COleDocument` que fornece a infraestrutura para vinculação. Você deve derivar de classes de documento para seus aplicativos de contêiner desta classe em vez de `COleDocument` se você deseja dar suporte a links para objetos inseridos.  
  
 [CRichEditDoc](../mfc/reference/cricheditdoc-class.md)  
 Mantém a lista de itens de cliente OLE que estão no controle de edição avançada. Usado com [CRichEditView](../mfc/reference/cricheditview-class.md) e [CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md).  
  
 [CDocItem](../mfc/reference/cdocitem-class.md)  
 Classe abstrata base de `COleClientItem` e `COleServerItem`. Objetos de classes derivam de `CDocItem` representar partes de documentos.  
  
 [COleClientItem](../mfc/reference/coleclientitem-class.md)  
 Uma classe de item do cliente que representa o lado do cliente de conexão para um item OLE incorporado ou vinculado. Derive seus itens de cliente desta classe.  
  
 [CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md)  
 Fornece acesso de cliente para uma item armazenada em um controle de edição rico quando usado com OLE `CRichEditView` e `CRichEditDoc`.  
  
 [COleException](../mfc/reference/coleexception-class.md)  
 Uma exceção resultante de uma falha no processamento de OLE. Essa classe é usada por contêineres e servidores.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

