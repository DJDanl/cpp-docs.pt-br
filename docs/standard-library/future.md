---
title: "&lt; futuro &gt; | Microsoft Docs"
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
  - "<future>"
dev_langs: 
  - "C++"
ms.assetid: 2f5830fc-455d-44f9-9e3d-94ea051596a2
caps.latest.revision: 23
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; futuro &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inclua o futuro padrão do cabeçalho\> \<para definir as classes de modelo e os modelos de suporte que simplificam executar uma função \- possível em um thread separado e recuperar seu resultado.  O resultado é o valor retornado pela função ou por uma exceção que é emitida pela função mas não é capturado na função.  
  
 Este cabeçalho usa o tempo de execução \(ConcRT\) de simultaneidade de forma que você possa usar o junto com outros mecanismos de ConcRT.  Para obter mais informações sobre como ConcRT, consulte [Tempo de Execução de Simultaneidade](../parallel/concrt/concurrency-runtime.md).  
  
## Sintaxe  
  
```cpp  
#include <future>  
```  
  
## Comentários  
  
> [!NOTE]
>  No código que é construído usando **\/clr** ou **\/clr:pure**, este cabeçalho é bloqueado.  
  
 *Um provedor assíncrona* armazena o resultado de uma chamada de função.  *Um objeto de retorno assíncrono* é usado para recuperar o resultado de uma chamada de função.  *Um estado assíncrona associado* fornece comunicação assíncrona entre um provedor e um ou mais objetos de retorno assíncronas.  
  
 Um programa não cria diretamente objetos assíncronos associados do estado.  O programa cria um provedor assíncrona sempre que necessário um e do que cria um objeto de retorno assíncrono que compartilha seu estado assíncrona associado ao provedor.  Os provedores assíncronas e retornam objetos assíncronos gerenciam os objetos que mantém seu estado assíncrona associado compartilhado.  Quando o objeto do último que referencia o estado associado assíncrona, o liberará o objeto que contém o estado assíncrona associado será destruído.  
  
 Um provedor assíncrono ou um objeto de retorno assíncrono que não tem nenhum estado assíncrona associado estiver *vazia*.  
  
 Um estado associado assíncrona está *pronto* apenas se o provedor assíncrona armazenou um valor de retorno ou armazenados uma exceção.  
  
 A função `async` do modelo e as classes `promise` e `packaged_task` de modelo são provedores assíncronas.  As classes `future` e `shared_future` do modelo descrevem objetos de retorno assíncronas.  
  
 Cada um modelo de classificação `promise`, `future`, e `shared_future` tem uma especialização para o tipo `void` e uma especialização parcial para armazenar e recuperar um valor por referência.  Essas especializações diferentes do modelo primário somente em assinaturas e semântica das funções de data warehouse e recupera o valor retornado.  
  
 As classes `future` e `shared_future` do modelo nunca bloqueiam em seus destruidores, a não ser que um caso em que são preservados para compatibilidade com versões anteriores: Em vez de todos futuros restantes, pois de `future`— ou `shared_future`o último — que anexado a uma tarefa começou a `std::async`, o destruidor se a tarefa não foi concluída; isto é, o bloqueia se esse thread não chamou ainda `.get()` ou `.wait()` e a tarefa ainda estiver em execução.  A seguinte observação de usabilidade foi adicionada à descrição de `std::async` no padrão de rascunho: “\[Observação: Se um futuro obtido de std::async é movido do escopo local, o outro código que usa o futuro deve estar atento que o destruidor do futuro pode bloquear para que o estado compartilhado fique pronto. — finaliza a observação\]” em todos os casos, `future` e destruidores restantes de `shared_future` é necessário e garantido para bloquear nunca.  
  
## Membros  
  
### Classes  
  
|Nome|Descrição|  
|----------|---------------|  
|[Classe future](../standard-library/future-class.md)|Descreve um objeto de retorno assíncrona.|  
|[Classe future\_error](../standard-library/future-error-class.md)|Descreve um objeto de exceção que pode ser gerado pelos métodos de tipos que gerenciam objetos de `future` .|  
|[Classe packaged\_task](../standard-library/packaged-task-class.md)|Descreve um provedor assíncrono que é um wrapper de chamada e cujo a assinatura de chamada seja `Ty(ArgTypes...)`.  Seu estado assíncrona associado mantém uma cópia do objeto acessível além do resultado potencial.|  
|[Classe promise](../standard-library/promise-class.md)|Descreve um provedor assíncrono.|  
|[Classe shared\_future](../standard-library/shared-future-class.md)|Descreve um objeto de retorno assíncrona.  Em contraste com um objeto de `future` , um provedor assíncrono pode ser associado a qualquer número de objetos de `shared_future` .|  
  
### Estruturas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Estrutura is\_error\_code\_enum](../standard-library/is-error-code-enum-structure.md)|Especialização que indica que `future_errc` é apropriado para armazenar `error_code`.|  
|[Estrutura uses\_allocator](../standard-library/uses-allocator-structure.md)|Especialização que contém sempre true.|  
  
### Funções  
  
|Nome|Descrição|  
|----------|---------------|  
|[Função async](../Topic/async%20Function.md)|Representa um provedor assíncrona.|  
|[Função future\_category](../Topic/future_category%20Function.md)|Retorna uma referência ao objeto de `error_category` que apresenta os erros associados aos objetos de `future` .|  
|[Função make\_error\_code](../Topic/make_error_code%20Function.md)|Cria `error_code` que possui o objeto de `error_category` que apresenta erros de `future` .|  
|[Função make\_error\_condition](../Topic/make_error_condition%20Function.md)|Cria `error_condition` que possui o objeto de `error_category` que apresenta erros de `future` .|  
|[troca de função \(\< futuro \>\)](../Topic/swap%20Function%20\(%3Cfuture%3E\).md)|Troca o estado associado assíncrona de um objeto de `promise` com o custo de outro.|  
  
### Enumerações  
  
|Nome|Descrição|  
|----------|---------------|  
|[Enumeração future\_errc](../Topic/future_errc%20Enumeration.md)|Fornece nomes simbólicos para os erros relatados pela classe de `future_error` .|  
|[Enumeração future\_status](../Topic/future_status%20Enumeration.md)|Fornece nomes simbólicos das razões pelas quais uma função de tempo de espera pode retornar.|  
|[Enumeração de inicialização](../Topic/launch%20Enumeration.md)|Representa um tipo de máscara de bits que descreve os possíveis modos para a função `async`do modelo.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)