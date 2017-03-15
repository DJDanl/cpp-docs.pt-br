---
title: "Atribuindo e liberando mem&#243;ria para um BSTR | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "bstr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "BSTRs, alocação de memória"
  - "memória [C++], liberando"
  - "alocação de memória, BSTRs"
  - "desalocação de memória, Memória de BSTR"
  - "desalocação de memória, memória de cadeia de caracteres"
  - "cadeias de caracteres [C++], liberando"
ms.assetid: 98041e29-3442-4a02-b425-7a4a13e9cc84
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atribuindo e liberando mem&#243;ria para um BSTR
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você cria `BSTR`s e os passa entre objetos COM, você deve tomar manipular na memória que usam para evitar vazamentos de memória.  Quando `BSTR` permanece em uma interface, você deve liberar a memória quando você terminar com ele.  Em o entanto, quando `BSTR` passa para fora de uma interface, o objeto de recepção recebe a responsabilidade para o gerenciamento de memória.  
  
 Em geral, as regras para atribuir e liberar memória alocada para `BSTR`s são:  
  
-   Quando você chama em uma função que espera um argumento de `BSTR` , você deve alocar memória para `BSTR` antes da chamada e liberar\-la mais tarde.  Por exemplo:  
  
     [!code-cpp[NVC_ATLMFC_Utilities#192](../atl-mfc-shared/codesnippet/CPP/allocating-and-releasing-memory-for-a-bstr_1.cpp)]  
  
     [!code-cpp[NVC_ATLMFC_Utilities#193](../atl-mfc-shared/codesnippet/CPP/allocating-and-releasing-memory-for-a-bstr_2.cpp)]  
  
-   Quando você chama em uma função que retorna `BSTR`, você deve liberar a cadeia de caracteres você mesmo.  Por exemplo:  
  
     [!code-cpp[NVC_ATLMFC_Utilities#194](../atl-mfc-shared/codesnippet/CPP/allocating-and-releasing-memory-for-a-bstr_3.cpp)]  
  
     [!code-cpp[NVC_ATLMFC_Utilities#195](../atl-mfc-shared/codesnippet/CPP/allocating-and-releasing-memory-for-a-bstr_4.cpp)]  
  
-   Quando você implementa uma função que retorna `BSTR`, atribua a cadeia de caracteres mas não para liberar.  A receptor de função libera memória.  Por exemplo:  
  
     [!code-cpp[NVC_ATLMFC_Utilities#196](../atl-mfc-shared/codesnippet/CPP/allocating-and-releasing-memory-for-a-bstr_5.cpp)]  
  
## Consulte também  
 [Cadeias de caracteres](../atl-mfc-shared/strings-atl-mfc.md)   
 [CStringT::AllocSysString](../Topic/CStringT::AllocSysString.md)   
 [SysAllocString](http://msdn.microsoft.com/pt-br/9e0437a2-9b4a-4576-88b0-5cb9d08ca29b)   
 [SysFreeString](http://msdn.microsoft.com/pt-br/8f230ee3-5f6e-4cb9-a910-9c90b754dcd3)