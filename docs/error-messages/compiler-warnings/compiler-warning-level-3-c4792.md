---
title: "Compilador aviso (nível 3) C4792 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4792
dev_langs:
- C++
helpviewer_keywords:
- C4792
ms.assetid: c047ce69-a622-44e1-9425-d41aa9261c61
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: db3e0bcb878271b5c0b4ea687963d777093b209c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4792"></a>Compilador C4792 de aviso (nível 3)
' função ' declarado usando sysimport e referenciada no código nativo; biblioteca de importação precisa vincular  
  
 Uma função nativa que foi importada para o programa com DllImport foi chamada de uma função não gerenciada. Portanto, você deve vincular a biblioteca de importação para a DLL.  
  
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
