---
title: C2598 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2598
dev_langs: C++
helpviewer_keywords: C2598
ms.assetid: 40777c62-39ba-441e-b081-f49f94b43547
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: a7876b9fccadcd8a47cc3f76fbdc7ca097afae73
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c2598"></a>C2598 de erro do compilador
especificação de vinculação deve estar no escopo global  
  
 O especificador de vinculação é declarado no escopo local.  
  
 O exemplo a seguir gera C2598:  
  
```  
// C2598.cpp  
// compile with: /c  
void func() {  
   extern "C" int func2();   // C2598  
}  
  
extern "C" int func( int i );  
```