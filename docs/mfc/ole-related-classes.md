---
title: Classes relacionadas a OLE
ms.date: 11/04/2016
helpviewer_keywords:
- ActiveX classes [MFC]
- OLE classes [MFC]
- OLE [MFC], classes
ms.assetid: 2135cf54-1d9d-4e0e-91b4-943b3440effa
ms.openlocfilehash: 6f6db6ce133b440a5ed86e7c1642396888744540
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621029"
---
# <a name="ole-related-classes"></a>Classes relacionadas a OLE

Essas classes fornecem vários serviços diferentes, desde exceções até entrada e saída de arquivo.

[COleObjectFactory](reference/coleobjectfactory-class.md)<br/>
Usado para criar itens quando solicitado por outros contêineres. Essa classe serve como a classe base para tipos mais específicos de fábricas, incluindo `COleTemplateServer` .

[COleMessageFilter](reference/colemessagefilter-class.md)<br/>
Usado para gerenciar a simultaneidade com as chamadas de procedimento remoto Lightweight OLE (LRPC).

[COleStreamFile](reference/colestreamfile-class.md)<br/>
Usa a `IStream` interface com para fornecer `CFile` acesso a arquivos compostos. Essa classe (derivada de `CFile` ) permite que a serialização do MFC use o armazenamento estruturado OLE.

[CRectTracker](reference/crecttracker-class.md)<br/>
Usado para permitir a movimentação, o redimensionamento e a reorientação de itens in-loco.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
