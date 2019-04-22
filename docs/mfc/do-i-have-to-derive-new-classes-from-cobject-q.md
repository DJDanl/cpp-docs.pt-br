---
title: Preciso derivar novas classes de CObject?
ms.date: 11/04/2016
f1_keywords:
- CObject
helpviewer_keywords:
- derived classes [MFC], from CObject
- CObject class [MFC], when to use
ms.assetid: 26021031-feaf-424c-80d1-9547c4409d6a
ms.openlocfilehash: 30eb3ce5bbb72ab685ed891644a478a36026ebea
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58772300"
---
# <a name="do-i-have-to-derive-new-classes-from-cobject"></a>Preciso derivar novas classes de CObject?

Não, não é necessário.

Derive uma classe de [CObject](../mfc/reference/cobject-class.md) quando precisar que os recursos que ele fornece, como a serialização ou creatability dinâmico. Muitas classes de dados precisam ser serializados para arquivos, portanto, geralmente é uma boa ideia de derivá-las de `CObject`. Para um exemplo de uma classe derivada de `CObject`, consulte o [exemplo de Scribble](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Classe CObject: Perguntas frequentes](../mfc/cobject-class-frequently-asked-questions.md)
