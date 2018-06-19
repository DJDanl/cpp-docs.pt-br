---
title: Compilador aviso (nível 3) C4792 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4792
dev_langs:
- C++
helpviewer_keywords:
- C4792
ms.assetid: c047ce69-a622-44e1-9425-d41aa9261c61
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a4b0867305c56fc551e55680b6ed48bdb701cc09
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33292094"
---
# <a name="compiler-warning-level-3-c4792"></a>Compilador C4792 de aviso (nível 3)
função 'function' declarada usando sysimport e referenciada em código nativo; biblioteca de importação requerida para vínculo  
  
 Uma função nativa que foi importada para o programa com DllImport chamava-se de uma função não gerenciada. Portanto, você deve vincular para a biblioteca de importação para a DLL.  
  
 Este aviso não pode ser resolvido no código ou alterando a maneira como você compilar. Use o [aviso](../../preprocessor/warning.md) pragma para desabilitar esse aviso.  
  
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