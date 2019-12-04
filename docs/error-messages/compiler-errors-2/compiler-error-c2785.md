---
title: Erro do compilador C2785
ms.date: 11/04/2016
f1_keywords:
- C2785
helpviewer_keywords:
- C2785
ms.assetid: d8d13360-0d00-4815-8475-b49c7f0dc0f3
ms.openlocfilehash: 6aff2e5c96e3c79fc748d8a95779d6a08647ab03
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74739617"
---
# <a name="compiler-error-c2785"></a>Erro do compilador C2785

' declaration1 ' e ' declaration2 ' têm tipos de retorno diferentes

O tipo de retorno da especialização do modelo de função difere do tipo de retorno do modelo de função principal.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Verifique se há consistência em todas as especializações do modelo de função.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2785:

```cpp
// C2785.cpp
// compile with: /c
template<class T> void f(T);

template<> int f(int); // C2785
template<> void f(int); // OK
```
