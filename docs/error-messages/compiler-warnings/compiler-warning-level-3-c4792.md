---
title: Compilador aviso (nível 3) C4792
ms.date: 11/04/2016
f1_keywords:
- C4792
helpviewer_keywords:
- C4792
ms.assetid: c047ce69-a622-44e1-9425-d41aa9261c61
ms.openlocfilehash: adf233673c4b654927aa9488565adf6ceef5d3e2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401560"
---
# <a name="compiler-warning-level-3-c4792"></a>Compilador aviso (nível 3) C4792

função 'function' declarada usando sysimport e referenciada em código nativo; biblioteca de importação necessária para vincular

Uma função nativa que foi importada para o programa com DllImport foi chamada de uma função não gerenciada. Portanto, você deve vincular a biblioteca de importação para a DLL.

Esse aviso não pode ser resolvido no código ou alterando a maneira como você compilar. Use o [aviso](../../preprocessor/warning.md) pragma para desabilitar esse aviso.

O exemplo a seguir gera C4792:

```
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