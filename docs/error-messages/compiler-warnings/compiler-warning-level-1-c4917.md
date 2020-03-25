---
title: Aviso do compilador (nível 1) C4917
ms.date: 11/04/2016
f1_keywords:
- C4917
helpviewer_keywords:
- C4917
ms.assetid: c05e2610-4a5d-4f4b-a99b-c15fd7f1d5f1
ms.openlocfilehash: c7a2d72b429f762e476286093c7f273a9a546cb6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174668"
---
# <a name="compiler-warning-level-1-c4917"></a>Aviso do compilador (nível 1) C4917

' declarador ': um GUID só pode ser associado a uma classe, interface ou namespace

Uma estrutura definida pelo usuário diferente da [classe](../../cpp/class-cpp.md), [interface](../../cpp/interface.md)ou [namespace](../../cpp/namespaces-cpp.md) não pode ter um GUID.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo de código a seguir gera C4917:

```cpp
// C4917.cpp
// compile with: /W1
#pragma warning(default : 4917)
__declspec(uuid("00000000-0000-0000-0000-000000000001")) struct S
{
} s;   // C4917, don't put uuid on a struct

int main()
{
}
```
