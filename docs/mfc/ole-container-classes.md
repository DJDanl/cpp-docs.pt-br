---
title: "Classes Container OLE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.classes.ole"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classes ActiveX [C++]"
  - "classes de contêiner [C++]"
  - "contêineres [C++], aplicativos de contêiner OLE"
  - "OLE [C++], Classes "
  - "Classes OLE [C++]"
  - "edição visual [C++], Classes "
ms.assetid: 1e27e1ab-4c22-41eb-8547-6915c72668ae
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes Container OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essas classes são usadas por aplicativos do contêiner.  `COleLinkingDoc` e `COleDocument` gerenciar coleções de objetos de `COleClientItem` .  Em vez de com sua classe do documento de **CDocument**, você derivá\-lo\-á de `COleLinkingDoc` ou de `COleDocument`, dependendo se você deseja que o suporte para links para objetos inserido no documento.  
  
 Use um objeto de `COleClientItem` para representar cada item OLE no documento que é inserida de outro documento ou é um link para outro documento.  
  
 [COleDocObjectItem](../Topic/COleDocObjectItem%20Class.md)  
 Oferece suporte à retenção ativa do documento.  
  
 [COleDocument](../mfc/reference/coledocument-class.md)  
 Usado para a implementação composta de documento, bem como o suporte básico do contêiner.  Funciona como um contêiner para classes derivaram\-se de `CDocItem`.  Esta classe pode ser usada como a classe base para documentos contêiner e é a classe base para `COleServerDoc`.  
  
 [COleLinkingDoc](../mfc/reference/colelinkingdoc-class.md)  
 Uma classe derivada de `COleDocument` que fornece a infraestrutura para vincular.  Você deve derivar as classes do documento para aplicativos de contêiner desta classe em vez de `COleDocument` se desejar aos links de suporte a objetos inseridos.  
  
 [CRichEditDoc](../mfc/reference/cricheditdoc-class.md)  
 Mantém a lista de itens do cliente que estão no controle de edição sofisticado.  Usado com [CRichEditView](../mfc/reference/cricheditview-class.md) e [CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md).  
  
 [CDocItem](../mfc/reference/cdocitem-class.md)  
 Classe base abstrata de `COleClientItem` e de `COleServerItem`.  Os objetos das classes derivadas de `CDocItem` representam partes de documentos.  
  
 [COleClientItem](../mfc/reference/coleclientitem-class.md)  
 Uma classe do item do cliente que representa o lado do cliente de conexão a um item OLE inserido ou vinculado.  Derivar os itens do cliente dessa classe.  
  
 [CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md)  
 Fornece acesso ao lado do cliente a um item OLE armazenado em um controle de edição rico quando usado com `CRichEditView` e `CRichEditDoc`.  
  
 [COleException](../mfc/reference/coleexception-class.md)  
 Uma exceção resultante de uma falha no processamento OLE.  Esta classe é usada por contêineres e por servidores.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)