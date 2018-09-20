---
title: OLE arrastar-e-soltar transferência de dados e Classes | Microsoft Docs
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
ms.openlocfilehash: a4b5d694d0081fbe2d852884c4a379e962c22f2a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46444132"
---
# <a name="ole-drag-and-drop-and-data-transfer-classes"></a>Classes de transferência para arrastar e soltar dados OLE

Essas classes são usadas nas transferências de dados OLE. Eles permitem que os dados a serem transferidos entre aplicativos usando a área de transferência ou por meio de arrastar e soltar.

[COleDropSource](../mfc/reference/coledropsource-class.md)<br/>
Controla a operação de arrastar e soltar do início ao fim. Essa classe determina quando a operação de arrastar for iniciado e quando ele termina. Ele também exibe os comentários do cursor durante a operação de arrastar e soltar.

[COleDataSource](../mfc/reference/coledatasource-class.md)<br/>
Usado quando um aplicativo fornece dados para uma transferência de dados. `COleDataSource` pode ser visto como um objeto de área de transferência orientada a objeto.

[COleDropTarget](../mfc/reference/coledroptarget-class.md)<br/>
Representa o destino de uma operação de arrastar e soltar. Um `COleDropTarget` objeto corresponde a uma janela na tela. Ele determina se deve aceitar todos os dados soltos nele e implementa a operação de soltar real.

[COleDataObject](../mfc/reference/coledataobject-class.md)<br/>
Usado como o lado do receptor para `COleDataSource`. `COleDataObject` objetos fornecem acesso aos dados armazenados por um `COleDataSource` objeto.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

