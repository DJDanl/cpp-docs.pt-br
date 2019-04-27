---
title: Compilador aviso (nível 1) C4788
ms.date: 11/04/2016
f1_keywords:
- C4788
helpviewer_keywords:
- C4788
ms.assetid: 47d75bda-f833-4bdd-93a0-a134df0cd303
ms.openlocfilehash: c51a4409c2a3028823462539343654b5eac365d0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62187199"
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