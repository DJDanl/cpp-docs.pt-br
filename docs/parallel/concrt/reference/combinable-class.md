---
title: "Classe combinable | Microsoft Docs"
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
  - "ppl/concurrency::combinable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe combinable"
ms.assetid: fe0bfbf6-6250-47da-b8d0-f75369f0b5be
caps.latest.revision: 20
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe combinable
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

O objeto de `combinable<T>` é destinado fornecer cópias de privadas dos dados, para executar computações subelemento lock\-partition\-id&gt livres de thread local durante algoritmos paralelos.  No final da operação paralela, as computações um thread privadas podem ser mescladas em um resultado final.  Esta classe pode ser usada em vez de uma variável compartilhado, e pode levar a uma melhoria de desempenho se haveria de outra forma muita contenção em que a variável compartilhado.  
  
## Sintaxe  
  
```  
template<  
   typename _Ty  
>  
class combinable;  
```  
  
#### Parâmetros  
 `_Ty`  
 O tipo de dados do resultado final mesclada.  O tipo deve ter um construtor de cópia e um construtor padrão.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor combinable::combinable](../Topic/combinable::combinable%20Constructor.md)|Sobrecarregado.  Cria um novo objeto de `combinable` .|  
|[Destruidor combinable::~combinable](../Topic/combinable::~combinable%20Destructor.md)|Destrói um objeto de `combinable` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método combinable::clear](../Topic/combinable::clear%20Method.md)|Limpa todos os resultados intermediários computacionais de um uso anterior.|  
|[Método combinable::combine](../Topic/combinable::combine%20Method.md)|Computa um valor final do conjunto de subcadeia computações de thread local chamando o funtor fornecido de combinadas.|  
|[Método combinable::combine\_each](../Topic/combinable::combine_each%20Method.md)|Computa um valor final do conjunto de subcadeia computações de thread local chamando o funtor fornecido de iniciar uma vez por um cálculo de thread local.  O resultado final é acumulado pelo objeto de função.|  
|[Método combinable::local](../Topic/combinable::local%20Method.md)|Sobrecarregado.  Retorna uma referência à subcadeia de computação particular.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador combinable::operator\=](../Topic/combinable::operator=%20Operator.md)|Atribui a `combinable` um objeto de outro objeto de `combinable` .|  
  
## Comentários  
 Para obter mais informações, consulte [Contêineres e objetos em paralelo](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## Hierarquia de Herança  
 `combinable`  
  
## Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)