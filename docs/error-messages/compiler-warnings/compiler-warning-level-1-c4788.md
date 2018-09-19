---
title: Compilador aviso (nível 1) C4788 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4788
dev_langs:
- C++
helpviewer_keywords:
- C4788
ms.assetid: 47d75bda-f833-4bdd-93a0-a134df0cd303
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1c8a6ad1aa3ae17944b8c2a292d484d55c24d9cd
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46051707"
---
# <a name="compiler-warning-level-1-c4788"></a>Compilador aviso (nível 1) C4788

'identifier': identificador foi truncado para caracteres 'number'

O compilador limita o comprimento máximo permitido para um nome de função. Quando o compilador gera funclets para código EH/SEH, faz o funclet nome acrescentando o nome da função com algum texto, por exemplo "__catch," "\__unwind", ou outra cadeia de caracteres.

O nome de funclet resultante pode ser muito longo, e o compilador irá truncá-los e gerar C4788.

Para resolver este aviso, encurte o nome da função original. Se a função é um método ou função de modelo do C++, use um typedef para parte do nome. Por exemplo:

```
C1<x, y, z<T>>::C2<a,b,c>::f
```

pode ser substituído por:

```
typedef C1<x, y, z<T>>::C2<a,b,c> new_class ;
new_class::f
```

Este aviso ocorre apenas no x64 compilador.