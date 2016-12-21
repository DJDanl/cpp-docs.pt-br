---
title: "Classe shared_future | Microsoft Docs"
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
  - "future/std::shared_future"
dev_langs: 
  - "C++"
ms.assetid: 454ebedd-f42b-405f-99a5-a25cc9ad7c90
caps.latest.revision: 13
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe shared_future
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve *um objeto de retorno assíncrona*.  Em contraste com um objeto de [futuro](../standard-library/future-class.md) , *um provedor assíncrono* pode ser associado a qualquer número de objetos de `shared_future` .  
  
## Sintaxe  
  
```  
template<class Ty>  
class shared_future;  
```  
  
## Comentários  
 Não chame os métodos diferentes de `valid`, de `operator=`, e de destruidor em um objeto de `shared_future` que está *vazia*.  
  
 os objetos de`shared_future` não estão sincronizados.  Os métodos de chamada no mesmo objeto de vários threads introduzem uma uma corrida de dados com resultados imprevisíveis.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor shared\_future::shared\_future](../Topic/shared_future::shared_future%20Constructor.md)|Constrói um objeto `shared_future`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método shared\_future::get](../Topic/shared_future::get%20Method.md)|Recupera o resultado que é armazenado no *estado assíncrona associado*.|  
|[Método shared\_future::valid](../Topic/shared_future::valid%20Method.md)|Especifica se o objeto não está vazia.|  
|[Método shared\_future::wait](../Topic/shared_future::wait%20Method.md)|Bloqueia o thread atual até que o estado assíncrona associado esteja pronto.|  
|[Método shared\_future::wait\_for](../Topic/shared_future::wait_for%20Method.md)|Bloqueia até que o estado associado assíncrona estão prontos ou até o tempo decorrido especificados.|  
|[Método shared\_future::wait\_until](../Topic/shared_future::wait_until%20Method.md)|Bloqueia até que o estado associado assíncrona estão prontos ou até um point\-in\-time.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador shared\_future::operator\=](../Topic/shared_future::operator=%20Operator.md)|Atribui um novo estado assíncrona associado.|  
  
## Requisitos  
 **Cabeçalho:** futuro  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\< futuro \>](../standard-library/future.md)