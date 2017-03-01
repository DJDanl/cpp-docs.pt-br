---
title: C3862 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3862
dev_langs:
- C++
helpviewer_keywords:
- C3862
ms.assetid: ba547366-4189-4077-8c00-ab45e08a9533
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: cc82b83860786ffc3f0aee73ede18ecadef16a7a
ms.openlocfilehash: 48dbae62c367616a437db0607d84fa89e8006021
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3862"></a>C3862 de erro do compilador
'function': não é possível compilar uma função não gerenciada com /clr: puro ou /CLR: safe  
  
 O **/clr: puro** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015.  
  
 Uma compilação com **/clr: puro** ou **/CLR: safe** produzirá uma imagem única do MSIL, uma imagem sem código nativo de (não gerenciado).  Portanto, você não pode usar o `unmanaged` pragma em uma **/clr: puro** ou **/CLR: safe** compilação.  
  
 Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) e [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3862:  
  
```  
// C3862.cpp  
// compile with: /clr:pure /c  
#pragma unmanaged  
void f() {}   // C3862  
```
