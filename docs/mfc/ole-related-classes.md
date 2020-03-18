---
title: Classes relacionadas a OLE
ms.date: 11/04/2016
helpviewer_keywords:
- ActiveX classes [MFC]
- OLE classes [MFC]
- OLE [MFC], classes
ms.assetid: 2135cf54-1d9d-4e0e-91b4-943b3440effa
ms.openlocfilehash: dfcc07b3fbd0c5badce8e397f4d52bc7d8d3028c
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447611"
---
# <a name="ole-related-classes"></a>Classes relacionadas a OLE

Essas classes fornecem vários serviços diferentes, desde exceções até entrada e saída de arquivo.

[COleObjectFactory](../mfc/reference/coleobjectfactory-class.md)<br/>
Usado para criar itens quando solicitado por outros contêineres. Essa classe serve como a classe base para tipos mais específicos de fábricas, incluindo `COleTemplateServer`.

[COleMessageFilter](../mfc/reference/colemessagefilter-class.md)<br/>
Usado para gerenciar a simultaneidade com as chamadas de procedimento remoto Lightweight OLE (LRPC).

[COleStreamFile](../mfc/reference/colestreamfile-class.md)<br/>
Usa a interface de `IStream` COM para fornecer `CFile` acesso a arquivos compostos. Essa classe (derivada de `CFile`) permite que a serialização do MFC use o armazenamento estruturado OLE.

[CRectTracker](../mfc/reference/crecttracker-class.md)<br/>
Usado para permitir a movimentação, o redimensionamento e a reorientação de itens in-loco.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
