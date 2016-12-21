---
title: "Estrutura space_info | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "filesystem/std::tr2::sys::space_info"
dev_langs: 
  - "C++"
ms.assetid: f2b35b42-06ff-45bd-8617-39a0f5358a54
caps.latest.revision: 13
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estrutura space_info
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Contém informações sobre um volume.  
  
## Sintaxe  
  
```  
struct space_info;  
```  
  
## Membros  
  
### Membros de dados públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`unsigned long long available`|Representa o número de bytes que estão disponíveis para representar os dados no volume.|  
|`unsigned long long capacity`|Representa o número total de bytes que pode representar o volume.|  
|`unsigned long long free`|Representa o número de bytes que não são usados para representar os dados no volume.|  
  
## Requisitos  
 **Cabeçalho:** sistema de arquivos  
  
 **Namespace:** std::tr2::sys  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\< filesystem \>](../Topic/%3Cfilesystem%3E.md)   
 [Função space](http://msdn.microsoft.com/pt-br/7fce0b0e-523b-4598-b218-47245d0204ca)   
 [Navegação no sistema de arquivos \(C\+\+\)](../standard-library/file-system-navigation.md)