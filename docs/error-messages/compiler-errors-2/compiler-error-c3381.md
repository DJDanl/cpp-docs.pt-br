---
title: C3381 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
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
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 6b1a56658874eb5a62db7d272b40612e34bfc94a
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3381"></a>C3381 de erro do compilador
'assembly': especificadores de acesso de assembly só estão disponíveis no código compilado com uma opção /clr  
  
 Tipos nativos podem ser visíveis fora do assembly, mas você só pode especificar o acesso de assembly para tipos nativos em uma **/clr** compilação.  
  
 Para obter mais informações, consulte [visibilidade de tipo](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) e [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3381.  
  
```  
// C3381.cpp  
// compile with: /c  
public class A {};   // C3381  
```
