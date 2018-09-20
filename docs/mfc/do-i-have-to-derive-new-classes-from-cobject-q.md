---
title: Preciso derivar novas classes de CObject? | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CObject
dev_langs:
- C++
helpviewer_keywords:
- derived classes [MFC], from CObject
- CObject class [MFC], when to use
ms.assetid: 26021031-feaf-424c-80d1-9547c4409d6a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ec080e556b57afadbc3d958f4dba5ac6393108aa
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46408902"
---
# <a name="do-i-have-to-derive-new-classes-from-cobject"></a>Preciso derivar novas classes de CObject?

Não, não é necessário.

Derive uma classe de [CObject](../mfc/reference/cobject-class.md) quando precisar que os recursos que ele fornece, como a serialização ou creatability dinâmico. Muitas classes de dados precisam ser serializados para arquivos, portanto, geralmente é uma boa ideia de derivá-las de `CObject`. Para um exemplo de uma classe derivada de `CObject`, consulte o [exemplo de Scribble](../visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Classe CObject: perguntas frequentes](../mfc/cobject-class-frequently-asked-questions.md)
