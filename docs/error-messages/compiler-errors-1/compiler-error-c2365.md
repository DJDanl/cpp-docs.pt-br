---
title: C2365 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2365
dev_langs:
- C++
helpviewer_keywords:
- C2365
ms.assetid: 35839b0b-4055-4b79-8957-b3a0871bdd02
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f696a9379550bfeb47c65471a345322ddaadcf4a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2365"></a>C2365 de erro do compilador
'membro de classe': redefinição; definição anterior era 'membro de classe'  
  
 Você tentou redefinir um membro de classe.  
  
 O exemplo a seguir gera C2365.  
  
```  
// C2365.cpp  
// compile with: /c  
class C1 {  
   int CFunc();  
   char *CFunc;   // C2365, already exists as a member function  
  
   int CMem;  
   char *CMem();   // C2365, already exists as a data member  
};  
```