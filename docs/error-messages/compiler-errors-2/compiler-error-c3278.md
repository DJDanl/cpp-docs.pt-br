---
title: Erro do compilador C3278
ms.date: 11/04/2016
f1_keywords:
- C3278
helpviewer_keywords:
- C3278
ms.assetid: 56f818f5-85a6-4792-843b-54fe16327658
ms.openlocfilehash: ec51064853afa37f75022042c8c6121b6c5248a4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201429"
---
# <a name="compiler-error-c3278"></a>Erro do compilador C3278

> a chamada direta da interface ou do método puro '*Method*' falhará em tempo de execução

## <a name="remarks"></a>Comentários

Foi feita uma chamada para um método de interface ou um método puro, o que não é permitido.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3278:

```cpp
// C3278_2.cpp
// compile with: /clr
using namespace System;
interface class I
{
   void vmf();
};

public ref class C: public I
{
public:
   void vmf()
   {
      Console::WriteLine( "In C::vmf()" );
      I::vmf(); // C3278
   }

};

int main()
{
   C^ pC = gcnew C;
   pC->vmf();
}
```
