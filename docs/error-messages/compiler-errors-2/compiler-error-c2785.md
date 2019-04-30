---
title: Erro do compilador C2785
ms.date: 11/04/2016
f1_keywords:
- C2785
helpviewer_keywords:
- C2785
ms.assetid: d8d13360-0d00-4815-8475-b49c7f0dc0f3
ms.openlocfilehash: fcf2bbb01f2aac668ff52884a6ccfb36c66aa89d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62395372"
---
# <a name="compiler-error-c2785"></a>Erro do compilador C2785

'declaration1' e 'declaration2' têm diferentes tipos de retorno

O tipo de retorno de especialização de modelo de função é diferente do tipo de retorno do modelo da função primária.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Verifique se todas as especializações do modelo da função para manter a consistência.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2785:

```
// C2785.cpp
// compile with: /c
template<class T> void f(T);

template<> int f(int); // C2785
template<> void f(int); // OK
```