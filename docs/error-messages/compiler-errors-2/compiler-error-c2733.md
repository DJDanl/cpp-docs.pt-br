---
title: C2733 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2733
dev_langs:
- C++
helpviewer_keywords:
- C2733
ms.assetid: 67f83561-c633-407c-a2ee-f9fd16e165bf
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fb0c21850d93a39047bacfe38592e381e9fb5918
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2733"></a>C2733 de erro do compilador
segundo vínculo a C de função sobrecarregada 'function' não permitido  
  
 Mais de uma função sobrecarregada foi declarada com vínculo a C. Ao usar o vínculo a C, somente um formulário de uma função especificada pode ser externo. Como funções sobrecarregadas tem o mesmo nome não decorado, não pode ser usados com programas de C.  
  
 O exemplo a seguir gera C2733:  
  
```  
// C2733.cpp  
extern "C" {  
   void F1(int);  
}  
  
extern "C" {  
   void F1();   // C2733  
   // try the following line instead  
   // void F2();  
}  
```