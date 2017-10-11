---
title: C3371 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3371
dev_langs:
- C++
helpviewer_keywords:
- C3371
ms.assetid: f7ecf1aa-ed0a-4f73-81e5-62cf98f88ea1
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 1bc5af03841fe0a06b1ae0a31887565a3c1eb197
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3371"></a>C3371 de erro do compilador
'idl_module': apenas a propriedade 'name' é permitida aqui  
  
 [idl_module](../../windows/idl-module.md) uso diretamente em uma declaração de função não pode ter qualquer parâmetro que não seja o nome.  
  
 O exemplo a seguir gera C3371:  
  
```  
// C3371.cpp  
[idl_module(name="Name", dllname="Some.dll")];  
[idl_module(name="Name", helpstring="Some help")]   // C3371  
int f1();  
// try  
// [idl_module(name="Name")]  
// int f1();  
  
int main()  
{  
}  
```
