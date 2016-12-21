---
title: "Classe future | Microsoft Docs"
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
  - "future/std::future"
dev_langs: 
  - "C++"
ms.assetid: 495e82c3-5341-4e37-87dd-b40107fbdfb6
caps.latest.revision: 13
caps.handback.revision: 2
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe future
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve *um objeto de retorno assíncrona*.  
  
## Sintaxe  
  
```  
template<class Ty>  
class future;  
```  
  
## Comentários  
 Cada *provedor assíncrona* padrão retorna um objeto cujo tipo é uma instanciação desse modelo.  Um objeto de `future` fornece o único acesso ao provedor assíncrono que está associado.  Se você precisar vários objetos de retorno assíncronas que estão associados com o mesmo provedor assíncrona, copie o objeto de `future` a um objeto de [shared\_future](../standard-library/shared-future-class.md) .  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor future::future](../Topic/future::future%20Constructor.md)|Constrói um objeto `future`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método future::get](../Topic/future::get%20Method.md)|Recupera o resultado que é armazenado no estado assíncrona associado.|  
|[Método future::share](../Topic/future::share%20Method.md)|Converte o objeto a `shared_future`.|  
|[Método future::valid](../Topic/future::valid%20Method.md)|Especifica se o objeto não está vazia.|  
|[Método future::wait](../Topic/future::wait%20Method.md)|Bloqueia o thread atual até que o estado assíncrona associado esteja pronto.|  
|[Método future::wait\_for](../Topic/future::wait_for%20Method.md)|Bloqueia até que o estado associado assíncrona estão prontos ou até o tempo decorrido especificados.|  
|[Método future::wait\_until](../Topic/future::wait_until%20Method.md)|Bloqueia até que o estado associado assíncrona estão prontos ou até um point\-in\-time.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador future::operator\=](../Topic/future::operator=%20Operator.md)|Transfere o estado associado assíncrona de um objeto especificado.|  
  
## Requisitos  
 **Cabeçalho:** futuro  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\< futuro \>](../standard-library/future.md)