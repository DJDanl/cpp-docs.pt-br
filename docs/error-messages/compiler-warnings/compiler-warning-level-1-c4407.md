---
title: "Aviso do compilador (n&#237;vel 1) C4407 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4407"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4407"
ms.assetid: 32bc2c21-363a-4bb8-b486-725faeaededc
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4407
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

conversão entre o ponteiro diferente às representações de membro, compilador pode gerar código incorreta  
  
 Uma conversão incorreta foi detectada.  
  
 C4407 pode ser gerado devido ao trabalho de conformidade do compilador que foi feito no Visual C\+\+ 2005.  o Ponteiro\-à\- membro agora requer um nome qualificado e endereços do operador \(&\).  
  
 C4407 pode ocorrer se você converter entre um ponteiro\-à\- membro de herança múltipla a um único membro ponteiro\-à\- de herança.  Às vezes pode funcionar, mas às vezes pode não porque a única representação de ponteiro\-à\- membro de herança não contém informações suficientes.  A compilação com **\/vmm** pode ajudar \(para obter mais informações, consulte [\/vmm, \/vms, \/vmv \(representação de finalidade geral\)](../../build/reference/vmm-vms-vmv-general-purpose-representation.md)\).  Você também pode tentar reorganizar suas classes base; o compilador está detectando uma perda de informações na conversão porque uma classe base estiver em um deslocamento diferente de zero do derivada.  
  
 O seguinte exemplo gera C4407:  
  
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