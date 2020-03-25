---
title: Aviso do compilador (nível 1) C4788
ms.date: 11/04/2016
f1_keywords:
- C4788
helpviewer_keywords:
- C4788
ms.assetid: 47d75bda-f833-4bdd-93a0-a134df0cd303
ms.openlocfilehash: 76a33b24446debffb2c00bf1b0497cfc86022ce0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175124"
---
# <a name="compiler-warning-level-1-c4788"></a>Aviso do compilador (nível 1) C4788

' identifier ': identificador foi truncado para ' Number ' caracteres

O compilador limita o comprimento máximo permitido para um nome de função. Quando o compilador gera funclets para o código de EH/SEH, ele forma o nome funclet, predependendo do nome da função com algum texto, por exemplo, "__catch", "\__unwind" ou outra cadeia de caracteres.

O nome resultante do funclet pode ser muito longo e o compilador irá truncar e gerar C4788.

Para resolver esse aviso, diminua o nome da função original. Se a função for um C++ método ou função de modelo, use um typedef para parte do nome. Por exemplo:

```cpp
C1<x, y, z<T>>::C2<a,b,c>::f
```

pode ser substituído por:

```cpp
typedef C1<x, y, z<T>>::C2<a,b,c> new_class ;
new_class::f
```

Esse aviso ocorre apenas no compilador x64.
