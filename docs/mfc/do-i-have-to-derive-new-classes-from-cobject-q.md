---
title: Preciso derivar novas classes de CObject?
ms.date: 11/04/2016
helpviewer_keywords:
- derived classes [MFC], from CObject
- CObject class [MFC], when to use
ms.assetid: 26021031-feaf-424c-80d1-9547c4409d6a
ms.openlocfilehash: 371ede0f0921182c066b4cb224e66b18eb6f1208
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616734"
---
# <a name="do-i-have-to-derive-new-classes-from-cobject"></a>Preciso derivar novas classes de CObject?

Não, você não tem.

Derive uma classe de [CObject](reference/cobject-class.md) quando precisar dos recursos que ele fornece, como serialização ou criação dinâmica. Muitas classes de dados precisam ser serializadas para arquivos, portanto, geralmente é uma boa ideia derivar delas `CObject` . Para obter um exemplo de uma classe derivada de `CObject` , consulte o [exemplo de rabisco](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Classe CObject: perguntas frequentes](cobject-class-frequently-asked-questions.md)
