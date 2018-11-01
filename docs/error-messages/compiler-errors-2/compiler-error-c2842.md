---
title: Erro do compilador C2842
ms.date: 11/04/2016
f1_keywords:
- C2842
helpviewer_keywords:
- C2842
ms.assetid: 8674f08d-9f50-46ad-9229-abc6b74fa0e5
ms.openlocfilehash: 2ec39768a88da049c6a31ca2a9de226e25479c99
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50571464"
---
# <a name="compiler-error-c2842"></a>Erro do compilador C2842

'class': um gerenciado ou o tipo de WinRT não pode definir seu próprio 'operator new' ou 'operator delete'

Você pode definir seus próprios * * operador new ou **operador delete** para gerenciar a alocação de memória no heap nativo. No entanto, as classes de referência não é possível definir esses operadores, pois eles só serão alocados no heap gerenciado.

Para obter mais informações, consulte [operadores definidos pelo usuário (C + + / CLI)](../../dotnet/user-defined-operators-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2842.

```
// C2842.cpp
// compile with: /clr /c
ref class G {
   void* operator new( size_t nSize );   // C2842
};
```
