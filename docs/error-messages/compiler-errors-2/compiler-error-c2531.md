---
title: C2531 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2531
dev_langs: C++
helpviewer_keywords: C2531
ms.assetid: c49afe15-55f8-4dc8-ac01-bf653622a7db
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ee277ad1be9866edc92adb965513238e8c4e6389
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2531"></a>C2531 de erro do compilador
'Identificador': referência a um bit ilegal de campo  
  
 Não são permitidas referências a campos de bits.  
  
 O exemplo a seguir gera C2531:  
  
```  
// C2531.cpp  
// compile with: /c  
class P {  
   int &b1 : 10;   // C2531  
   int b2 : 10;   // OK  
};  
```