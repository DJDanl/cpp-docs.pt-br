---
title: Preciso derivar novas classes de CObject?
ms.date: 11/04/2016
f1_keywords:
- CObject
helpviewer_keywords:
- derived classes [MFC], from CObject
- CObject class [MFC], when to use
ms.assetid: 26021031-feaf-424c-80d1-9547c4409d6a
ms.openlocfilehash: cbefed5f44981d784d1fc5b6616bab5ee45e4115
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57279504"
---
# <a name="do-i-have-to-derive-new-classes-from-cobject"></a>Preciso derivar novas classes de CObject?

Não, não é necessário.

Derive uma classe de [CObject](../mfc/reference/cobject-class.md) quando precisar que os recursos que ele fornece, como a serialização ou creatability dinâmico. Muitas classes de dados precisam ser serializados para arquivos, portanto, geralmente é uma boa ideia de derivá-las de `CObject`. Para um exemplo de uma classe derivada de `CObject`, consulte o [exemplo de Scribble](../visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Classe CObject: Perguntas frequentes](../mfc/cobject-class-frequently-asked-questions.md)
