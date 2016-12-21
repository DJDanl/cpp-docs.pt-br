---
title: "&lt; condition_variable &gt; | Microsoft Docs"
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
  - "<condition_variable>"
dev_langs: 
  - "C++"
ms.assetid: 8567f7cc-20bd-42a7-9137-87c46f878009
caps.latest.revision: 19
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; condition_variable &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define as classes [condition\_variable](../standard-library/condition-variable-class.md) e [condition\_variable\_any](../standard-library/condition-variable-any-class.md) que são usadas para criar os objetos que esperam uma condição para se tornarem true.  
  
 Este cabeçalho usa o tempo de execução \(ConcRT\) de simultaneidade de forma que você possa usar o junto com outros mecanismos de ConcRT.  Para obter mais informações sobre como ConcRT, consulte [Tempo de Execução de Simultaneidade](../parallel/concrt/concurrency-runtime.md).  
  
## Sintaxe  
  
```cpp  
#include <condition_variable>  
```  
  
> [!NOTE]
>  No código que é construído usando **\/clr** ou **\/clr:pure**, este cabeçalho é bloqueado.  
  
### Comentários  
 O código que as esperas de uma variável de condição também devem usar `mutex`.  Um thread de chamada precisará bloquear `mutex` antes de chamar funções que esperam a variável da condição.  `mutex` está bloqueado em quando a função retorna chamado.  `mutex` não é bloqueada quando o thread está esperando a condição para se tornarem true.  De modo que não haja nenhum resultado imprevisível, cada thread que as esperas de uma variável de condição devem usar o mesmo objeto de `mutex` .  
  
 Os objetos do tipo `condition_variable_any` podem ser usados com um mutex de qualquer tipo.  O tipo do mutex usado não precisa fornecer o método de `try_lock` .  Os objetos do tipo `condition_variable` podem ser usados somente com um mutex do tipo `unique_lock<mutex>`.  Os objetos desse tipo pode ser mais rápido do que objetos de tipo `condition_variable_any<unique_lock<mutex>>`.  
  
 Para aguardar um evento, bloqueie primeiro o mutex, e chame um dos métodos de `wait` na variável da condição.  Os blocos de chamada de `wait` até outro thread sinalizam a variável da condição.  
  
 *As excitações falsos* ocorrem quando os threads que estão aguardando variáveis de condição se tornam desbloqueados sem notificações apropriadas.  Para reconhecer como excitações falsos, o código que as esperas para que uma condição seja verdadeira explicitamente devem verificar essa condição quando retornar de código de uma espera de tabela.  Isso é feito normalmente usando um loop; você pode usar `wait(unique_lock<mutex>& lock, Predicate pred)` para executar esse loop para você.  
  
```cpp  
while (condition is false)  
    wait for condition variable;  
```  
  
 `condition_variable_any` e `condition_variable` classificam possuem três métodos que esperam uma condição.  
  
-   `wait` espera um período de tempo ilimitado.  
  
-   esperas de`wait_until` até `time`especificado.  
  
-   `wait_for` espera `time interval`especificado.  
  
 Cada um desses métodos tem duas versões sobrecarregadas.  Apenas um espera e pode acordar spuriously.  O outro usa um argumento adicional do modelo que define um predicado.  O método não retorna até que o predicado deve ser `true`.  
  
 Cada classe também tem dois métodos que são usados para notificar uma variável da condição que sua condição é `true`.  
  
-   `notify_one` acorda um dos threads que estão esperando a variável da condição.  
  
-   `notify_all` acorda todos os threads que estão esperando a variável da condição.  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Classe condition\_variable](../standard-library/condition-variable-class.md)   
 [Classe condition\_variable\_any](../standard-library/condition-variable-any-class.md)   
 [Enumeração cv\_status](../Topic/cv_status%20Enumeration.md)