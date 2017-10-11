---
title: Erro fatal C1190 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1190
dev_langs:
- C++
helpviewer_keywords:
- C1190
ms.assetid: dee2266d-6c40-4f6e-91db-f01e65f8d2bc
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 1b04b08bd57a527145cafde1073430a78d68b89b
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1190"></a>Erro fatal C1190
código gerenciado direcionado requer uma ' / clr' opção  
  
 Você está usando construções CLR, mas você não especificou **/clr**.  
  
 Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 O exemplo a seguir gera C1190:  
  
```  
// C1190.cpp  
// compile with: /c  
__gc class A {};   // C1190  
ref class A {};  
```
