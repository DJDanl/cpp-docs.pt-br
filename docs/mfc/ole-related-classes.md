---
title: Classes relacionadas a OLE
ms.date: 11/04/2016
f1_keywords:
- vc.classes.ole
helpviewer_keywords:
- ActiveX classes [MFC]
- OLE classes [MFC]
- OLE [MFC], classes
ms.assetid: 2135cf54-1d9d-4e0e-91b4-943b3440effa
ms.openlocfilehash: 7d58072d133b9348558804b848ecfda4497931e1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62378291"
---
# <a name="ole-related-classes"></a>Classes relacionadas a OLE

Essas classes fornecem vários serviços diferentes, variando de exceções em um arquivo de entrada e saída.

[COleObjectFactory](../mfc/reference/coleobjectfactory-class.md)<br/>
Usado para criar itens quando solicitado de outros contêineres. Esta classe serve como a classe base para tipos específicos de mais de fábricas, incluindo `COleTemplateServer`.

[COleMessageFilter](../mfc/reference/colemessagefilter-class.md)<br/>
Usado para gerenciar a simultaneidade com OLE Lightweight remoto procedimento chamadas LRPC ().

[COleStreamFile](../mfc/reference/colestreamfile-class.md)<br/>
Usa o COM `IStream` interface para fornecer `CFile` acesso compor os arquivos. Essa classe (derivado de `CFile`) habilita a serialização do MFC usar o armazenamento estruturado OLE.

[CRectTracker](../mfc/reference/crecttracker-class.md)<br/>
Usado para permitir a mover, redimensionar e reorientation de itens no local.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
