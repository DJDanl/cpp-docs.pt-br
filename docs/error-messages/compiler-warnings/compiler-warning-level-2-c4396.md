---
title: Aviso do compilador (nível 2) C4396
ms.date: 11/04/2016
f1_keywords:
- C4396
helpviewer_keywords:
- C4396
ms.assetid: 7cd6b283-db17-4574-b299-03e0b913ad70
ms.openlocfilehash: e874e00d44eef29240cca55541837facfcf64495
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052035"
---
# <a name="compiler-warning-level-2-c4396"></a>Aviso do compilador (nível 2) C4396

"Name": o especificador embutido não pode ser usado quando uma declaração Friend se refere a uma especialização de um modelo de função

Uma especialização de um modelo de função não pode especificar nenhum dos especificadores [embutidos](../../cpp/inline-functions-cpp.md) . O compilador emite C4396 de aviso e ignora o especificador embutido.

### <a name="to-correct-this-error"></a>Para corrigir este erro

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