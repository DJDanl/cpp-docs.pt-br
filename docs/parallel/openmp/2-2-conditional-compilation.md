---
title: "2.2 Conditional Compilation | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 8f9c914d-736c-48cf-899d-c8029dbe1e32
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.2 Conditional Compilation
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O \_**OPENMP** nome da macro é definido pelas implementações compatíveis com OpenMP como a constante decimal  *yyyymm*, qual será o ano e mês da especificação aprovada.  Esta macro não deve ser o assunto de um  **\# define** ou um  **\#undef** diretiva de pré\-processamento.  
  
```  
#ifdef _OPENMP  
iam = omp_get_thread_num() + index;  
#endif  
```  
  
 Se os fornecedores de definem as extensões para OpenMP, eles podem especificar outras macros predefinidas.