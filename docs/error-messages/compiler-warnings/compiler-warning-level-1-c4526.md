---
title: "Compilador aviso (nível 1) C4526 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4526
dev_langs:
- C++
helpviewer_keywords:
- C4526
ms.assetid: 490f8916-5fdc-4cad-b412-76c3382a5976
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 98c4e325fc38bf3e9ce8949660c9b38b4017866a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4526"></a>Compilador C4526 de aviso (nível 1)
'function': função de membro estático não pode substituir a função virtual ' virtual function'override ignorado, ficará oculta a função virtual  
  
 A função de membro estático atende aos critérios para substituir a função virtual, o que torna a função de membro virtual e estáticos.  
  
 O código a seguir gera C4526:  
  
```  
// C4526.cpp  
// compile with: /W1 /c  
// C4526 expected  
struct myStruct1 {  
   virtual void __stdcall func( int ) = 0;  
};  
  
struct myStruct2: public myStruct1 {  
   static void __stdcall func( int );  
};  
```  
  
 Estas são as possíveis correções:  
  
-   Se a função foi destinada para substituir a função de classe base virtual, remova o especificador estático.  
  
-   Se a função foi deve ser uma função de membro estático, renomeá-lo para que ele não entre em conflito com a função virtual da classe base.
