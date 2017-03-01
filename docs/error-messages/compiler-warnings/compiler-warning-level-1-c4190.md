---
title: "Compilador aviso (nível 1) C4190 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4190
dev_langs:
- C++
helpviewer_keywords:
- C4190
ms.assetid: a4d0ad93-a19a-4063-addd-36d605831567
caps.latest.revision: 7
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
translationtype: Machine Translation
ms.sourcegitcommit: 4ac033535632e94a365aa8dafd849f2ab28a3af7
ms.openlocfilehash: bf45c0737f52da93f93c1f95d313771f0e92a10e
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4190"></a>Compilador C4190 de aviso (nível 1)
'identifier1' foi especificada para vinculação de C, mas retorna UDT 'identifier2', que é incompatível com C  
  
 Uma função ou um ponteiro para função tem um UDT (-tipo definido pelo usuário, que é uma classe, estrutura, enum ou união) como tipo de retorno e `extern` vinculação "C". Isso é legal se:  
  
-   Todas as chamadas para essa função ocorrerem do C++.  
  
-   A definição da função é em C++.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// C4190.cpp  
// compile with: /W1 /LD  
struct X  
{  
   int i;  
   X ();  
   virtual ~X ();  
};  
  
extern "C" X func ();   // C4190  
```
