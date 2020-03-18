---
title: Classes de transferência para arrastar e soltar dados OLE
ms.date: 11/04/2016
helpviewer_keywords:
- ActiveX classes [MFC]
- OLE drag and drop [MFC], and data transfer classes
- drag and drop [MFC], classes
- data transfer [MFC], OLE
- data transfer classes [MFC]
ms.assetid: c8ab2825-ed69-4b88-8ae6-f368b94726b8
ms.openlocfilehash: 7e01b6d5a7d14e0af4ca760e6e601e91359c8ab1
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447619"
---
# <a name="ole-drag-and-drop-and-data-transfer-classes"></a>Classes de transferência para arrastar e soltar dados OLE

Essas classes são usadas em transferências de dados OLE. Eles permitem que os dados sejam transferidos entre aplicativos usando a área de transferência ou arrastando e soltando.

[COleDropSource](../mfc/reference/coledropsource-class.md)<br/>
Controla a operação de arrastar e soltar do início ao fim. Essa classe determina quando a operação de arrastar começa e quando termina. Ele também exibe os comentários do cursor durante a operação de arrastar e soltar.

[COleDataSource](../mfc/reference/coledatasource-class.md)<br/>
Usado quando um aplicativo fornece dados para uma transferência de dados. `COleDataSource` pode ser exibido como um objeto de área de transferência orientado a objeto.

[COleDropTarget](../mfc/reference/coledroptarget-class.md)<br/>
Representa o destino de uma operação de arrastar e soltar. Um objeto `COleDropTarget` corresponde a uma janela na tela. Ele determina se os dados foram ignorados e implementa a operação de remoção real.

[COleDataObject](../mfc/reference/coledataobject-class.md)<br/>
Usado como o lado do destinatário para `COleDataSource`. os objetos `COleDataObject` fornecem acesso aos dados armazenados por um objeto `COleDataSource`.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
