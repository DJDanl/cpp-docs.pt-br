---
title: C3381 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3381
dev_langs:
- C++
helpviewer_keywords:
- C3381
ms.assetid: d276c89f-8377-4cb6-a8d4-7770885f06c4
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
ms.openlocfilehash: 25d41ac2445fe8ec93385d4cf4f159e0149ae7b6
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3381"></a>C3381 de erro do compilador
'assembly': especificadores de acesso do assembly só estão disponíveis no código compilado com a opção /clr  
  
 Tipos nativos podem ser vistos fora do assembly, mas você pode especificar apenas o acesso de assembly para tipos nativos em uma **/clr** compilação.  
  
 Para obter mais informações, consulte [digite visibilidade](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) e [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3381.  
  
```  
// C3381.cpp  
// compile with: /c  
public class A {};   // C3381  
```
