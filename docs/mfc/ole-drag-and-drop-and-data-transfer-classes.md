---
title: OLE arrastar e soltar dados Classes de transferência | Microsoft Docs
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
- OLE drag and drop [MFC], and data transfer classes
- drag and drop [MFC], classes
- data transfer [MFC], OLE
- data transfer classes [MFC]
ms.assetid: c8ab2825-ed69-4b88-8ae6-f368b94726b8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d55d6d171f490631afe17a605f50607fb55f070b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33347036"
---
# <a name="ole-drag-and-drop-and-data-transfer-classes"></a>Classes de transferência para arrastar e soltar dados OLE
Essas classes são usadas nas transferências de dados OLE. Permitem que os dados a serem transferidos entre aplicativos usando a área de transferência ou por meio de arrastar e soltar.  
  
 [COleDropSource](../mfc/reference/coledropsource-class.md)  
 Controla a operação de arrastar e soltar do início ao fim. Essa classe determina quando a operação de arrastar inicia e quando ele termina. Ele também exibe comentários de cursor durante a operação de arrastar e soltar.  
  
 [COleDataSource](../mfc/reference/coledatasource-class.md)  
 Usado quando um aplicativo fornece dados para uma transferência de dados. `COleDataSource` pode ser exibido como um objeto de área de transferência e orientada a objeto.  
  
 [COleDropTarget](../mfc/reference/coledroptarget-class.md)  
 Representa o destino de uma operação de arrastar e soltar. Um `COleDropTarget` objeto corresponde a uma janela na tela. Determina se deve aceitar os dados solto nele e implementa a operação de remoção real.  
  
 [COleDataObject](../mfc/reference/coledataobject-class.md)  
 Usado como o lado do destinatário para `COleDataSource`. `COleDataObject` objetos fornecem acesso aos dados armazenados por um `COleDataSource` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

