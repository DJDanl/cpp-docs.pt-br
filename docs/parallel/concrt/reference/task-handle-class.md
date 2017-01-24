---
title: "Classe task_handle | Microsoft Docs"
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
  - "ppl/concurrency::task_handle"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe task_handle"
ms.assetid: 74a34b15-708b-4231-a509-947874292b13
caps.latest.revision: 23
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe task_handle
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `task_handle` representa um item de trabalho paralelo individual.  Encapsula as instruções e os dados necessários para executar um bico de trabalho.  
  
## Sintaxe  
  
```  
template<  
   typename _Function  
>  
class task_handle : public ::Concurrency::details::_UnrealizedChore;  
```  
  
#### Parâmetros  
 `_Function`  
 O tipo de objeto de função que será invocado para executar o trabalho representada pelo objeto de `task_handle` .  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor task\_handle::task\_handle](../Topic/task_handle::task_handle%20Constructor.md)|Cria um novo objeto de `task_handle` .  O trabalho da tarefa é executado chamando a função especificada como um parâmetro para o construtor.|  
|[Destruidor task\_handle::~task\_handle](../Topic/task_handle::~task_handle%20Destructor.md)|Destrói o objeto `task_handle`.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador task\_handle::operator\(\)](../Topic/task_handle::operator\(\)%20Operator.md)|O operador de chamada de função que o tempo de execução chama para executar o trabalho do identificador da tarefa.|  
  
## Comentários  
 os objetos de`task_handle` podem ser usados em conjunto com `structured_task_group` ou mais um objeto de `task_group` geral, para decompor o trabalho em tarefas paralelas.  Para obter mais informações, consulte [Paralelismo da tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
 Observe que o criador de um objeto de `task_handle` é responsável por manter o tempo de vida do objeto criado de `task_handle` até que seja necessário já não no tempo de execução de simultaneidade.  Normalmente, isso significa que o objeto de `task_handle` não deve destruct ou até `wait` ou método de `run_and_wait` de `task_group` ou `structured_task_group` a que foi enfileirado esteve chamado.  
  
 os objetos de`task_handle` são usados em conjunto com lambdas C\+\+.  Como você não souber o tipo de lambda true, a função de [make\_task](../Topic/make_task%20Function.md) normalmente é usado para criar um objeto de `task_handle` .  
  
 O tempo de execução cria uma cópia da função de trabalho que você passa a um objeto de `task_handle` .  Em virtude disso, qualquer alteração de estado que ocorrem em um objeto de função que você transmita a um objeto de `task_handle` não aparecerão em sua cópia do objeto de função.  
  
## Hierarquia de Herança  
 `task_handle`  
  
## Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe task\_group](../Topic/task_group%20Class.md)   
 [Classe structured\_task\_group](../../../parallel/concrt/reference/structured-task-group-class.md)   
 [Função make\_task](../Topic/make_task%20Function.md)   
 [Método task\_group::run](../Topic/task_group::run%20Method.md)   
 [Método task\_group::wait](../Topic/task_group::wait%20Method.md)   
 [Método task\_group::run\_and\_wait](../Topic/task_group::run_and_wait%20Method.md)   
 [Método structured\_task\_group::run](../Topic/structured_task_group::run%20Method.md)   
 [Método structured\_task\_group::wait](../Topic/structured_task_group::wait%20Method.md)   
 [Método structured\_task\_group::run\_and\_wait](../Topic/structured_task_group::run_and_wait%20Method.md)