---
title: "Estrutura once_flag | Microsoft Docs"
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
  - "mutex/std::once_flag"
dev_langs: 
  - "C++"
ms.assetid: 71bfb88d-ca8c-4082-a6e1-ff52151e8629
caps.latest.revision: 13
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estrutura once_flag
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa `struct` usado com a função [call\_once](../Topic/call_once%20Function.md) do modelo para assegurar que o código de inicialização ser chamado apenas uma vez, mesmo na presença de vários threads de execução.  
  
## Sintaxe  
  
```cpp  
struct once_flag  
{  
   constexpr once_flag() noexcept;  
   once_flag(const once_flag&);  
   once_flag& operator=(const once_flag&);  
};  
```  
  
## Comentários  
 `once_flag` `struct` tem apenas um construtor padrão.  
  
 Os objetos do tipo `once_flag` podem ser criados, mas não podem ser copiados.  
  
## Requisitos  
 **Cabeçalho:** mutex  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex\>](../standard-library/mutex.md)