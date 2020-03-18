---
title: Preciso derivar novas classes de CObject?
ms.date: 11/04/2016
helpviewer_keywords:
- derived classes [MFC], from CObject
- CObject class [MFC], when to use
ms.assetid: 26021031-feaf-424c-80d1-9547c4409d6a
ms.openlocfilehash: d38e589f371fc56f5566c56de7b19c366065a503
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446928"
---
# <a name="do-i-have-to-derive-new-classes-from-cobject"></a>Preciso derivar novas classes de CObject?

Não, você não tem.

Derive uma classe de [CObject](../mfc/reference/cobject-class.md) quando precisar dos recursos que ele fornece, como serialização ou criação dinâmica. Muitas classes de dados precisam ser serializadas para arquivos, portanto, geralmente é uma boa ideia derivar delas de `CObject`. Para obter um exemplo de uma classe derivada de `CObject`, consulte o [exemplo de rabisco](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Classe CObject: perguntas frequentes](../mfc/cobject-class-frequently-asked-questions.md)
