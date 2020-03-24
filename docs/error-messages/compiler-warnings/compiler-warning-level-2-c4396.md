---
title: Aviso do compilador (nível 2) C4396
ms.date: 11/04/2016
f1_keywords:
- C4396
helpviewer_keywords:
- C4396
ms.assetid: 7cd6b283-db17-4574-b299-03e0b913ad70
ms.openlocfilehash: f37fcc7ece09bb9028a522ec6baf85d0e0e585c2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80161809"
---
# <a name="compiler-warning-level-2-c4396"></a>Aviso do compilador (nível 2) C4396

"Name": o especificador embutido não pode ser usado quando uma declaração Friend se refere a uma especialização de um modelo de função

Uma especialização de um modelo de função não pode especificar nenhum dos especificadores [embutidos](../../cpp/inline-functions-cpp.md) . O compilador emite C4396 de aviso e ignora o especificador embutido.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Remova o especificador `inline`, `__inline`ou `__forceinline` da declaração de função Friend.

## <a name="example"></a>Exemplo

O exemplo de código a seguir mostra uma declaração de função Friend inválida com um especificador de `inline`.

```cpp
// C4396.cpp
// compile with: /W2 /c

class X;
template<class T> void Func(T t, int i);

class X {
    friend inline void Func<char>(char t, int i);  //C4396
// try the following line instead
//    friend void Func<char>(char t, int i);
    int i;
};
```
