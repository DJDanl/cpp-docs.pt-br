---
title: O que me custa derivar uma classe a partir de CObject?
ms.date: 11/04/2016
f1_keywords:
- CObject
helpviewer_keywords:
- CObject class [MFC], overhead of derived classes [MFC]
ms.assetid: 9b92c98b-b3dd-48a7-9d24-c3b8554edf90
ms.openlocfilehash: de760a2fd2908595314dc09cf5a317da3581e3bb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62186043"
---
# <a name="what-does-it-cost-me-to-derive-a-class-from-cobject"></a>O que me custa derivar uma classe a partir de CObject?

A sobrecarga no derivando da classe [CObject](../mfc/reference/cobject-class.md) é mínima. Sua classe derivada herda apenas quatro funções virtuais e uma única [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) objeto.

## <a name="see-also"></a>Consulte também

[Classe CObject: perguntas frequentes](../mfc/cobject-class-frequently-asked-questions.md)
