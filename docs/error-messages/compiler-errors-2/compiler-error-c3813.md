---
title: Erro do compilador C3813
ms.date: 11/04/2016
f1_keywords:
- C3813
helpviewer_keywords:
- C3813
ms.assetid: ffdbc489-71bf-4cd6-988c-f824c9ab3ceb
ms.openlocfilehash: 88aca16363af22a6671832264889b1a26e43d460
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223363"
---
# <a name="compiler-error-c3813"></a>Erro do compilador C3813

uma declaração de propriedade só pode aparecer dentro da definição de um tipo gerenciado ou WinRT

Uma [Propriedade](../../dotnet/how-to-use-properties-in-cpp-cli.md) só pode ser declarada dentro de um tipo gerenciado ou Windows Runtime. Os tipos nativos não oferecem suporte à **`property`** palavra-chave.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3813 e mostra como corrigi-lo:

```cpp
// C3813.cpp
// compile by using: cl /c /clr C3813.cpp
class A
{
   property int Int; // C3813
};

ref class B
{
   property int Int; // OK - declared within managed type
};
```
