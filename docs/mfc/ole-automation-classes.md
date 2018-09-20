---
title: Classes de automação OLE | Microsoft Docs
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
- Automation, classes
- Automation classes [MFC], OLE classes
- OLE Automation [MFC], classes
- Automation classes [MFC]
- OLE Automation [MFC]
ms.assetid: 96e5372b-ff8a-4da1-933b-4d9bbf4dceb3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ea35e51296b2fc528657c4dd9f9b9b76b84aae83
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46391508"
---
# <a name="ole-automation-classes"></a>Classes de automação OLE

Essas classes de dar suporte a clientes de automação (aplicativos que controlam a outros aplicativos). Servidores de automação (aplicativos que podem ser controlados por outros aplicativos) têm suporte por meio [mapas de envios](../mfc/reference/dispatch-maps.md).

[COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md)<br/>
Usado para chamar os servidores de automação de seu cliente de automação. Ao adicionar uma classe, essa classe é usada para criar classes fortemente tipadas para os servidores de automação que fornecem uma biblioteca de tipos.

[COleDispatchException](../mfc/reference/coledispatchexception-class.md)<br/>
Uma exceção resultante de um erro durante a automação OLE. Exceções de automação são geradas por servidores de automação e capturadas por clientes de automação.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

