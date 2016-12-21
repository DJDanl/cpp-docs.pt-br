---
title: "Classe task (Tempo de Execu&#231;&#227;o de Simultaneidade) | Microsoft Docs"
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
  - "ppltasks/concurrency::task"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe task"
ms.assetid: cdc3a8c0-5cbe-45a0-b5d5-e9f81d94df1a
caps.latest.revision: 12
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe task (Tempo de Execu&#231;&#227;o de Simultaneidade)
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe da Biblioteca de Padrões Paralela \(PPL\) `task`.  Um objeto `task` representa o trabalho que pode ser executado de forma assíncrona, simultaneamente com outras tarefas e trabalhos paralelos produzidos por algoritmos paralelos em tempo de execução de simultaneidade.  Gera um resultado do tipo `_ResultType` na conclusão com êxito.  As tarefas de tipo `task<void>` não produzem resultados.  Uma tarefa pode ser esperada e cancelada independentemente de outras tarefas.  Também pode ser composto por outras tarefas usando padrões de continuações\(`then`\) e de união\(`when_all`\) e de escolha\(`when_any`\).  
  
## Sintaxe  
  
```  
template <  
   typename _Type  
>  
class task;  
  
template <>  
class task<void>;  
  
template<  
   typename _ReturnType  
>  
class task;  
```  
  
#### Parâmetros  
 `_Type`  
 `T`  
 `_ReturnType`  
 O tipo de resultado desta tarefa.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`result_type`|O tipo de resultado que um objeto dessa classe produz.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor task::task](../Topic/task::task%20Constructor.md)|Sobrecarregado.  Constrói um objeto `task`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método task::get](../Topic/task::get%20Method.md)|Sobrecarregado.  Retorna o resultado que gerou essa tarefa.  Se a tarefa não estiver em um estado terminal, uma chamada para `get` aguardará a conclusão da tarefa.  Este método não retorna um valor quando chamado em uma tarefa com um `result_type` de `void`.|  
|[Método task::is\_apartment\_aware](../Topic/task::is_apartment_aware%20Method.md)|Determina se a tarefa desempacota uma interface `IAsyncInfo` de Tempo de Execução do Windows ou descende de tal tarefa.|  
|[Método task::is\_done \(Tempo de Execução de Simultaneidade\)](../Topic/task::is_done%20Method%20\(Concurrency%20Runtime\).md)|Determina se a tarefa está concluída.|  
|[Método task::scheduler \(Tempo de Execução de Simultaneidade\)](../Topic/task::scheduler%20Method%20\(Concurrency%20Runtime\).md)|Retorna o agendador para esta tarefa|  
|[Método task::then](../Topic/task::then%20Method.md)|Sobrecarregado.  Adiciona uma tarefa de continuação de linha para esta tarefa.|  
|[Método task::wait](../Topic/task::wait%20Method.md)|Aguarda esta tarefa atingir um estado terminal.  É possível para `wait` executar a tarefa embutida, se todas as dependências de tarefas forem atendidas, e caso ela ainda não tenha sido escolhida para execução por um trabalhador em segundo plano.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador task::operator\!\=](../Topic/task::operator!=%20Operator.md)|Sobrecarregado.  Determina se dois objetos `task` representam tarefas internas diferentes.|  
|[Operador task::operator\=](../Topic/task::operator=%20Operator.md)|Sobrecarregado.  Substitui o conteúdo de um objeto de `task` por outro.|  
|[Operador task::operator\=\=](../Topic/task::operator==%20Operator.md)|Sobrecarregado.  Determina se dois objetos `task` representam as mesmas tarefas internas.|  
  
## Comentários  
 Para obter mais informações, consulte [Paralelismo da tarefa](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).  
  
## Hierarquia de Herança  
 `task`  
  
## Requisitos  
 **Cabeçalho:** ppltasks.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)