---
title: Erro do compilador C3813
ms.date: 11/04/2016
f1_keywords:
- C3813
helpviewer_keywords:
- C3813
ms.assetid: ffdbc489-71bf-4cd6-988c-f824c9ab3ceb
ms.openlocfilehash: c16ce501e25040a7ac7672a9ea131b4fe89570f5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165607"
---
# <a name="compiler-error-c3813"></a>Erro do compilador C3813

uma declaração de propriedade só pode aparecer dentro da definição de um tipo gerenciado ou WinRT

Uma [Propriedade](../../dotnet/how-to-use-properties-in-cpp-cli.md) só pode ser declarada dentro de um tipo gerenciado ou Windows Runtime. Os tipos nativos não dão suporte à palavra-chave `property`.

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
