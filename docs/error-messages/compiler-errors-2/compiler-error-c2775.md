---
title: C2775 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2775
dev_langs: C++
helpviewer_keywords: C2775
ms.assetid: 9c488508-ade0-48f1-b94f-d538d15f807a
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 823b6886e87a6c5d1a6aaedd7ab8e9b3ad67adb0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c2775"></a>C2775 de erro do compilador
'Identificador': nenhum método 'get' está associado esta propriedade  
  
 Um membro de dados declarado com o [propriedade](../../cpp/property-cpp.md) atributo estendido não tem um `get` função especificada, mas uma expressão tenta recuperar seu valor.  
  
 O exemplo a seguir gera C2775:  
  
```  
// C2775.cpp  
struct A {  
   __declspec(property(put=PutProp2, get=GetProp2)) int prop2;  
   int GetProp2(){return 0;}  
   void PutProp2(int){}  
  
   __declspec(property(put=PutProp)) int prop;  
   int PutProp(void){}  
  
};  
  
int main() {  
   A* pa = new A;  
   int x;  
   x = pa->prop;   // C2775  
   x = pa->prop2;  
}  
```