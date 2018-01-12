---
title: C2951 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2951
dev_langs: C++
helpviewer_keywords: C2951
ms.assetid: c6f95aa2-c894-425b-a51c-d40d70c8daa1
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ad6d5f3b7ab97b799a23c124505d8930774918aa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2951"></a>C2951 de erro do compilador
declarações de tipo são permitidas apenas no namespace global ou escopo de classe  
  
 Você não pode declarar um genérico ou escopo de namespace ou classe de modelo global externo. Se você fizer suas declarações genérico ou modelo em um arquivo de inclusão, verifique se o arquivo de inclusão está no escopo global.  
  
 O exemplo a seguir gera C2951:  
  
```  
// C2951.cpp  
template <class T>  
class A {};  
  
int main() {  
   template <class T>   // C2951  
   class B {};  
}  
```  
  
 C2951 também pode ocorrer ao usar genéricos:  
  
```  
// C2951b.cpp  
// compile with: /clr /c  
  
// OK  
generic <class T>   
ref class GC { };  
  
int main() {  
   generic <class T> ref class GC2 {};   // C2951  
}  
```