---
title: "Compilador (nível 4) de aviso C4673 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4673
dev_langs: C++
helpviewer_keywords: C4673
ms.assetid: 95626ec6-f05b-43c7-8b9a-a60a6f98dd30
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 8242a083fbf7a9f94c419c1cf142c7c1ada65009
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-4-c4673"></a>Compilador C4673 de aviso (nível 4)
lançar 'Identificador' os seguintes tipos não será considerado no local de catch  
  
 Um objeto throw não pode ser manipulado no **catch** bloco. Cada tipo que não pode ser tratado é listado na saída de erro imediatamente após a linha que contém este aviso. Cada tipo sem tratamento tem seu próprio aviso. Leia o aviso para cada tipo específico para obter mais informações.  
  
 O exemplo a seguir gera C4673:  
  
```  
// C4673.cpp  
// compile with: /EHsc /W4  
class Base {  
private:  
   char * m_chr;  
public:  
   Base() {  
      m_chr = 0;  
   }  
  
   ~Base() {  
      if(m_chr)  
         delete m_chr;  
   }  
};  
  
class Derv : private Base {  
public:  
   Derv() {}  
   ~Derv() {}  
};  
  
int main() {  
   try {  
      Derv D1;  
      // delete previous line, uncomment the next line to resolve  
      // Base D1;  
      throw D1;   // C4673  
   }  
  
   catch(...) {}  
}  
```