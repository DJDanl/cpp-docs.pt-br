---
title: "Compilador (nível 1) de aviso C4407 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4407
dev_langs: C++
helpviewer_keywords: C4407
ms.assetid: 32bc2c21-363a-4bb8-b486-725faeaededc
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 736b5f99115d6e2a39ee77005c7b3248ac191453
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4407"></a>Compilador C4407 de aviso (nível 1)
conversão entre diferente ponteiro para representações de membro, compilador pode gerar código incorreto  
  
 Foi detectada uma conversão incorreta.  
  
 C4407 pode ser gerado devido ao trabalho de conformidade do compilador que foi feito no Visual C++ 2005. Ponteiro para membro agora requer um nome qualificado e o operador address-of (&).  
  
 C4407 pode ocorrer se você converter entre vários herança ponteiro-para-membro para um herança única ponteiro para membro. Às vezes, isso pode funcionar, mas, às vezes, ele não é possível porque a representação de ponteiro para membro de herança única não conter informações suficientes. Compilando com o **/vmm** pode ajudar (para obter mais informações, consulte [/vmm, /vms, /vmv (representação de finalidade geral)](../../build/reference/vmm-vms-vmv-general-purpose-representation.md)). Você também pode tentar reorganizar suas classes base; o compilador é detectar uma perda de informações na conversão porque uma classe base está em um deslocamento diferente de zero de derivada.  
  
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