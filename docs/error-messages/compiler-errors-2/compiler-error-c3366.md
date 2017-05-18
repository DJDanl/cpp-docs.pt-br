---
title: C3366 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3366
dev_langs:
- C++
helpviewer_keywords:
- C3366
ms.assetid: efc55bcf-c16d-43c1-a36f-87a6165fa2a8
caps.latest.revision: 10
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
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: 930114bfb06019f13b4f44cc51b72922237a62f6
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3366"></a>C3366 de erro do compilador
'variável': membros de dados estáticos gerenciados ou WinRTtypes devem ser definidos dentro da definição de classe  
  
 Você tentou fazer referência a um membro estático da classe WinRT ou .NET ou interface fora da definição da classe ou interface.  
  
 O compilador precisa saber a definição completa da classe (para emitir os metadados após uma passagem) e requer que os membros de dados estáticos sejam inicializados dentro da classe.  
  
 Por exemplo, o exemplo a seguir gera C3366 e mostra como corrigi-lo:  
  
```  
// C3366.cpp  
// compile with: /clr /c  
ref class X {  
   public:  
   static int i;   // initialize i here to avoid C3366  
};  
  
int X::i = 5;      // C3366  
```  

