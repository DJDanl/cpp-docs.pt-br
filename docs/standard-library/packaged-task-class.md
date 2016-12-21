---
title: "Classe packaged_task | Microsoft Docs"
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
  - "future/std::packaged_task"
dev_langs: 
  - "C++"
ms.assetid: 0a72cbe3-f22a-4bfe-8e50-dcb268c98780
caps.latest.revision: 9
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe packaged_task
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve *um provedor assíncrono* que é um wrapper de chamada cuja assinatura de chamada seja `Ty(ArgTypes...)`.  Seu *estado assíncrona associado* mantém uma cópia do objeto acessível além do resultado potencial.  
  
## Sintaxe  
  
```  
template<class>  
class packaged_task;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor packaged\_task::packaged\_task](../Topic/packaged_task::packaged_task%20Constructor.md)|Constrói um objeto `packaged_task`.|  
|[Destruidor packaged\_task::~packaged\_task](../Topic/packaged_task::~packaged_task%20Destructor.md)|Destrói um objeto de `packaged_task` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método packaged\_task::get\_future](../Topic/packaged_task::get_future%20Method.md)|Retorna um objeto de [futuro](../standard-library/future-class.md) que tem o mesmo estado assíncrona associado.|  
|[Método packaged\_task::make\_ready\_at\_thread\_exit](../Topic/packaged_task::make_ready_at_thread_exit%20Method.md)|Chama o objeto acessível que é armazenado no estado assíncrona associado e armazena o valor atômico retornado.|  
|[Método packaged\_task::reset](../Topic/packaged_task::reset%20Method.md)|Substitui o estado assíncrona associado.|  
|[Método packaged\_task::swap](../Topic/packaged_task::swap%20Method.md)|Troca o estado assíncrona associado com o custo de um objeto especificado.|  
|[Método packaged\_task::valid](../Topic/packaged_task::valid%20Method.md)|Especifica se o objeto tem um estado assíncrona associado.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador packaged\_task::operator\=](../Topic/packaged_task::operator=%20Operator.md)|Transfere um estado associado assíncrona de um objeto especificado.|  
|[Operador packaged\_task::operator\(\)](../Topic/packaged_task::operator\(\)%20Operator.md)|Chama o objeto acessível que é armazenado no estado assíncrona associado, armazena o valor atômico retornado, e define o estado *pronto para*.|  
|[Operador packaged\_task::operador booliano](../Topic/packaged_task::operator%20bool%20Operator.md)|Especifica se o objeto tem um estado assíncrona associado.|  
  
## Requisitos  
 **Cabeçalho:** futuro  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\< futuro \>](../standard-library/future.md)