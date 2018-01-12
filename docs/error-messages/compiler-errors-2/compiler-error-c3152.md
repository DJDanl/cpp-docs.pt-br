---
title: C3152 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3152
dev_langs: C++
helpviewer_keywords: C3152
ms.assetid: 4ee6e2cd-5d19-4b73-833d-765c35797e4b
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c5e375586f6047ac0fef846cd6bf7b4f1e68d330
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3152"></a>C3152 de erro do compilador
'Criar': 'palavra-chave' só pode ser aplicado a uma classe, struct ou função membro virtual  
  
 Determinadas palavras-chave só pode ser aplicado a uma classe do C++.  
  
 O exemplo a seguir gera C3152 e mostra como corrigi-lo:  
  
```  
// C3152.cpp  
// compile with: /clr /c  
ref class C {  
   int (*pfn)() sealed;   // C3152  
   virtual int g() sealed;   // OK  
};  
```  
