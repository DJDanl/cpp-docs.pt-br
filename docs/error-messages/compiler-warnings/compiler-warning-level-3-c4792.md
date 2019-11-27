---
title: Aviso do compilador (nível 3) C4792
ms.date: 11/04/2016
f1_keywords:
- C4792
helpviewer_keywords:
- C4792
ms.assetid: c047ce69-a622-44e1-9425-d41aa9261c61
ms.openlocfilehash: 84a8a8bbb08ac97fe87d63d1ea44587790f87d92
ms.sourcegitcommit: 217fac22604639ebd62d366a69e6071ad5b724ac
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/19/2019
ms.locfileid: "74189339"
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