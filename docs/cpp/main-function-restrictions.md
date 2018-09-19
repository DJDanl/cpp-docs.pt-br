---
title: Restrições da função Main | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- Main
dev_langs:
- C++
helpviewer_keywords:
- main function, restrictions on using
ms.assetid: 7b3df731-344b-44a8-850c-11cbcbfbfa83
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 93f5cce15d4db9f7f6d4e3361d22028fccd676f2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46117355"
---
# <a name="main-function-restrictions"></a>Restrições da função main

Várias restrições se aplicam para o **principal** função que não se aplicam a quaisquer outras funções do C++. O **principal** função:

- Não pode ser sobrecarregado (consulte [sobrecarregamento de função](function-overloading.md)).

- Não pode ser declarado como **embutido**.

- Não pode ser declarado como **estático**.

- Não pode ter seu endereço removido.

- Não pode ser chamada.

## <a name="see-also"></a>Consulte também

[main: inicialização do programa](../cpp/main-program-startup.md)