---
title: "Classe promise | Microsoft Docs"
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
  - "future/std::promise"
dev_langs: 
  - "C++"
ms.assetid: 2931558c-d94a-4ba1-ac4f-20bf7b6e23f9
caps.latest.revision: 15
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe promise
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um *provedor assíncrono*.  
  
## Sintaxe  
  
```  
template<class Ty>  
class promise;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor promise::promise](../Topic/promise::promise%20Constructor.md)|Constrói um objeto `promise`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método promise::get\_future](../Topic/promise::get_future%20Method.md)|Retorna um [futuro](../standard-library/future-class.md) associado a essa promessa.|  
|[Método promise::set\_exception](../Topic/promise::set_exception%20Method.md)|Define de maneira atômica o resultado dessa promessa para indicar uma exceção.|  
|[Método promise::set\_exception\_at\_thread\_exit](../Topic/promise::set_exception_at_thread_exit%20Method.md)|Define de maneira atômica o resultado dessa promessa para indicar uma exceção e entrega notificação somente quando todos os objetos locais do thread no thread atual foram destruídos \(geralmente na saída do thread\).|  
|[Método promise::set\_value](../Topic/promise::set_value%20Method.md)|Define de maneira atômica o resultado dessa promessa para indicar um valor.|  
|[Método promise::set\_value\_at\_thread\_exit](../Topic/promise::set_value_at_thread_exit%20Method.md)|Define de maneira atômica o resultado dessa promessa para indicar um valor e entrega notificação somente quando todos os objetos locais do thread no thread atual foram destruídos \(geralmente na saída do thread\).|  
|[Método promise::swap](../Topic/promise::swap%20Method.md)|Troca o *estado assíncrono associado* desse Promise com o de um objeto Promise especificado.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador promise::operator\=](../Topic/promise::operator=%20Operator.md)|Atribuição de estado compartilhado desse objeto de promessa.|  
  
## Hierarquia de Herança  
 `promise`  
  
## Requisitos  
 **Cabeçalho:** futuro  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)