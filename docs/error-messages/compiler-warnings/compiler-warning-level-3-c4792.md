---
title: Aviso do compilador (nível 3) C4792
ms.date: 11/04/2016
f1_keywords:
- C4792
helpviewer_keywords:
- C4792
ms.assetid: c047ce69-a622-44e1-9425-d41aa9261c61
ms.openlocfilehash: f0efed41fad2648d7e681fa4e5575e7f36fb6aeb
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991680"
---
# <a name="compiler-warning-level-3-c4792"></a>Aviso do compilador (nível 3) C4792

função ' function ' declarada usando sysimport e referenciada de código nativo; biblioteca de importação necessária para vincular

Uma função nativa que foi importada para o programa com DllImport foi chamada de uma função não gerenciada. Portanto, você deve vincular à biblioteca de importação para a DLL.

Esse aviso não pode ser resolvido no código ou alterando a maneira como você compila. Use o pragma de [aviso](../../preprocessor/warning.md) para desabilitar este aviso.

O exemplo a seguir gera C4792:

```cpp
// C4792.cpp
// compile with: /clr /W3
// C4792 expected
using namespace System::Runtime::InteropServices;
[DllImport("msvcrt")]
extern "C" int __cdecl puts(const char *);
int main() {}

// Uncomment the following line to resolve.
// #pragma warning(disable : 4792)
#pragma unmanaged
void func(void){
   puts("test");
}
```
