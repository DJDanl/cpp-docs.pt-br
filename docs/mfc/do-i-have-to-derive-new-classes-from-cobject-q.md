---
title: Preciso derivar novas classes de CObject?
ms.date: 11/04/2016
f1_keywords:
- CObject
helpviewer_keywords:
- derived classes [MFC], from CObject
- CObject class [MFC], when to use
ms.assetid: 26021031-feaf-424c-80d1-9547c4409d6a
ms.openlocfilehash: c2361967dcfce5e46aeec65ade3d7056b362949d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50636599"
---
# <a name="do-i-have-to-derive-new-classes-from-cobject"></a>Preciso derivar novas classes de CObject?

Não, não é necessário.

Derive uma classe de [CObject](../mfc/reference/cobject-class.md) quando precisar que os recursos que ele fornece, como a serialização ou creatability dinâmico. Muitas classes de dados precisam ser serializados para arquivos, portanto, geralmente é uma boa ideia de derivá-las de `CObject`. Para um exemplo de uma classe derivada de `CObject`, consulte o [exemplo de Scribble](../visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Classe CObject: perguntas frequentes](../mfc/cobject-class-frequently-asked-questions.md)
