---
title: O que me custa derivar uma classe a partir de CObject?
ms.date: 11/04/2016
f1_keywords:
- CObject
helpviewer_keywords:
- CObject class [MFC], overhead of derived classes [MFC]
ms.assetid: 9b92c98b-b3dd-48a7-9d24-c3b8554edf90
ms.openlocfilehash: 521b6a32e3e5b34b4da9dab3117d55a728bd8e88
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50500435"
---
# <a name="what-does-it-cost-me-to-derive-a-class-from-cobject"></a>O que me custa derivar uma classe a partir de CObject?

A sobrecarga no derivando da classe [CObject](../mfc/reference/cobject-class.md) é mínima. Sua classe derivada herda apenas quatro funções virtuais e uma única [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) objeto.

## <a name="see-also"></a>Consulte também

[Classe CObject: perguntas frequentes](../mfc/cobject-class-frequently-asked-questions.md)
