---
title: Erro do compilador C3813
ms.date: 11/04/2016
f1_keywords:
- C3813
helpviewer_keywords:
- C3813
ms.assetid: ffdbc489-71bf-4cd6-988c-f824c9ab3ceb
ms.openlocfilehash: 302b21d709424cda50abd0247f7b82048511cd73
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62384303"
---
# <a name="compiler-error-c3813"></a>Erro do compilador C3813

uma declaração de propriedade só pode aparecer dentro da definição de um ou um tipo de WinRT

Um [propriedade](../../dotnet/how-to-use-properties-in-cpp-cli.md) só podem ser declarados dentro de um gerenciado ou tempo de execução do Windows tipo. Tipos nativos não dão suporte a `property` palavra-chave.

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