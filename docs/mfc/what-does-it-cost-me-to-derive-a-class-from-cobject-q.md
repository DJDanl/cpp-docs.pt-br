---
title: O que me custa derivar uma classe a partir de CObject?
ms.date: 11/04/2016
helpviewer_keywords:
- CObject class [MFC], overhead of derived classes [MFC]
ms.assetid: 9b92c98b-b3dd-48a7-9d24-c3b8554edf90
ms.openlocfilehash: 8f83bf9ee522487761aaa865a8315a174a47302d
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446047"
---
# <a name="what-does-it-cost-me-to-derive-a-class-from-cobject"></a>O que me custa derivar uma classe a partir de CObject?

A sobrecarga na derivação da classe [CObject](../mfc/reference/cobject-class.md) é mínima. Sua classe derivada herda apenas quatro funções virtuais e um único objeto [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) .

## <a name="see-also"></a>Consulte também

[Classe CObject: perguntas frequentes](../mfc/cobject-class-frequently-asked-questions.md)
