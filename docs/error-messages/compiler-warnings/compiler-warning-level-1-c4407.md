---
title: "Compilador aviso (nível 1) C4407 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4407
dev_langs:
- C++
helpviewer_keywords:
- C4407
ms.assetid: 32bc2c21-363a-4bb8-b486-725faeaededc
caps.latest.revision: 12
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d500312686ddef76950c3038f52101ad946ee7df
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4407"></a>Compilador C4407 de aviso (nível 1)
conversão entre diferentes representações de ponteiro para membro, compilador pode gerar código incorreto  
  
 Foi detectada uma conversão incorreta.  
  
 C4407 podem ser geradas devido ao trabalho de conformidade do compilador que foi feito no Visual C++ 2005. Ponteiro para membro agora requer um nome qualificado e o operador address-of (&).  
  
 C4407 pode ocorrer se você converter entre um vários herança ponteiro para membro para um única herança ponteiro para membro. Às vezes, isso pode funcionar, mas às vezes, ele não pode porque a representação de ponteiro para membro herança única não conter informações suficientes. Compilando com a **/vmm** podem ajudar a (para obter mais informações, consulte [/vmm, /vms, /vmv (representação de finalidade geral)](../../build/reference/vmm-vms-vmv-general-purpose-representation.md)). Você também pode tentar reorganizar suas classes base; o compilador está detectando uma perda de informações na conversão porque uma classe base é um deslocamento diferente de zero a derivada.  
  
 O exemplo a seguir gera C4407:  
  
```  
// C4407.cpp  
// compile with: /W1 /c  
struct C1 {};  
struct C2 {};  
struct C3 : C1, C2 {};  
  
typedef void(C3::*PMF_C3)();  
typedef void(C2::*PMF_C2)();  
  
PMF_C2 f1(PMF_C3 pmf) {  
   return (PMF_C2)pmf;   // C4407, change type of cast,  
   // or reverse base class inheritance of C3 (i.e. : C2, C1)  
}  
```
