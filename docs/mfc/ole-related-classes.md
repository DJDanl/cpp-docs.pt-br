---
title: Classes relacionadas a OLE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.classes.ole
dev_langs: C++
helpviewer_keywords:
- ActiveX classes [MFC]
- OLE classes [MFC]
- OLE [MFC], classes
ms.assetid: 2135cf54-1d9d-4e0e-91b4-943b3440effa
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 58e969213e749f5970f87013452b04ada306a8c3
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ole-related-classes"></a>Classes relacionadas a OLE
Essas classes fornecem vários serviços diferentes, variando de exceções para o arquivo de entrada e saída.  
  
 [COleObjectFactory](../mfc/reference/coleobjectfactory-class.md)  
 Usado para criar itens quando solicitado de outros contêineres. Esta classe serve como a classe base para tipos específicos de mais de fábricas, incluindo `COleTemplateServer`.  
  
 [COleMessageFilter](../mfc/reference/colemessagefilter-class.md)  
 Usado para gerenciar a simultaneidade com OLE Lightweight remoto procedimento chamadas LRPC ().  
  
 [COleStreamFile](../mfc/reference/colestreamfile-class.md)  
 Usa o COM `IStream` interface para fornecer `CFile` acesso compor os arquivos. Essa classe (derivado de `CFile`) permite a serialização do MFC para usar o armazenamento estruturado OLE.  
  
 [CRectTracker](../mfc/reference/crecttracker-class.md)  
 Usado para permitir a mover, redimensionar e reorientation de itens no local.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

