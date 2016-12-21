---
title: "&lt;allocators&gt; | Microsoft Docs"
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
  - "stdext::<allocators>"
  - "allocators/stdext::allocators"
  - "<allocators>"
  - "stdext.<allocators>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho allocators"
ms.assetid: 4393a607-4df8-4278-bbb2-c8ec52e60b83
caps.latest.revision: 19
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;allocators&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define vários modelos que ajudam a alocar e liberar blocos de memória para o contêiner baseados.  
  
## Sintaxe  
  
```  
#include <allocators>  
```  
  
## Comentários  
 \<O cabeçalho\> de alocadores fornece seis modelos do alocador que podem ser usados para selecionar estratégias de gerenciamento de memória para o contêiner baseados.  Para uso com esses modelos, também fornece vários filtros diferentes de sincronização para personalizar a estratégia de gerenciamento de memória a uma variedade de esquemas diferentes de multithreading \(que não incluem nenhum\).  Corresponder a uma estratégia de gerenciamento de memória os padrões conhecidos uso de memória, e requisitos de sincronização, de um aplicativo específico pode frequentemente aumentar a velocidade ou reduzir os requisitos de memória total de um aplicativo.  
  
 Os modelos do alocador são implementados por componentes reutilizáveis que podem ser personalizados ou substituído para fornecer estratégias de gerenciamento de memória adicionais.  
  
 Os contêineres conjunto de nós com base na biblioteca padrão \(C\+\+ std::list, std::set, std::multiset, std::map e std::multimap\) armazenam seus elementos em nós individuais.  Todos os nós para um tipo específico do contêiner são do mesmo tamanho, a flexibilidade de um gerenciador de memória de uso geral não é necessária.  Como o tamanho de cada bloco de memória é conhecido em tempo de compilação, o gerenciador de memória poderá ser muito mais simples e mais rapidamente.  
  
 Quando usados com um contêiner que não se baseiam \(como o std::deque de std::vector contêineres de biblioteca padrão, C\+\+ e std::basic\_string\), modelos de alllocator funcionará corretamente, mas não poderão fornecer nenhuma melhoria de desempenho sobre o alocador padrão.  
  
 Um alocador é uma classe do modelo que descreve um objeto que gerencia a alocação de armazenamento e se liberar para objetos e matrizes de objetos de um tipo designado.  Os objetos do alocador são usados por várias classes de modelo do contêiner na biblioteca padrão C\+\+.  
  
 Os alocadores em todos os modelos desse tipo:  
  
 `template<class`  `Type` `>`  
  
 `class allocator;`  
  
 onde o argumento `Type` do modelo é o tipo gerenciado pela instância do alocador.  A biblioteca padrão do C\+\+ fornece um alocador padrão, a classe [alocador](../standard-library/allocator-class.md)do modelo, que é definida em [\<memory\>](../standard-library/memory.md).  \<O cabeçalho\> de alocadores alocadores fornece os seguintes:  
  
-   [allocator\_newdel](../standard-library/allocator-newdel-class.md)  
  
-   [allocator\_unbounded](../standard-library/allocator-unbounded-class.md)  
  
-   [allocator\_fixed\_size](../standard-library/allocator-fixed-size-class.md)  
  
-   [allocator\_variable\_size](../standard-library/allocator-variable-size-class.md)  
  
-   [allocator\_suballoc](../standard-library/allocator-suballoc-class.md)  
  
-   [allocator\_chunklist](../Topic/allocator_chunklist%20Class.md)  
  
 Use uma instanciação apropriado de um alocador como o segundo argumento do tipo ao criar um contêiner, como o seguinte exemplo de código.  
  
 `#include <list>`  
  
 `#include <allocators>`  
  
 `std::list<int, stdext::allocators::allocator_chunklist<int> > _List0;`  
  
 \_List0 atribui nós com `allocator_chunklist` e o filtro padrão de sincronização.  
  
 Use a macro [ALLOCATOR\_DECL](../Topic/ALLOCATOR_DECL%20\(%3Callocators%3E\).md) para criar modelos do alocador com filtros de sincronização diferentes da opção:  
  
 `#include <list>`  
  
 `#include <allocators>`  
  
 `ALLOCATOR_DECL(CACHE_CHUNKLIST, stdext::allocators::sync_per_thread, Alloc);`  
  
 `std::list<int, alloc<int> > _List1;`  
  
 \_Lst1 atribui nós com `allocator_chunklist` e o filtro de sincronização de [synchronization\_per\_thread](../standard-library/sync-per-thread-class.md) .  
  
 Um alocador do bloco é um cache ou um filtro.  Um cache é uma classe do modelo que usa um argumento de std::size\_t do tipo.  Define um alocador do bloco que aloque e desaloque blocos de memória de um único tamanho.  Deve obter a memória usando o operador `new`, mas não precisa fazer uma ligação separada para o operador `new` para cada bloco.  Pode, por exemplo, suballocate de um bloco maior ou mais blocos desalocados cache para redistribuição subsequente.  
  
 Com um compilador que não pode criar reassociar o valor do argumento de std::size\_t usado quando o modelo foi criado uma instância não é necessariamente o valor de \_Sz de argumento passou para funções de membro de um cache de atributo e desalocam.  
  
 \<os alocadores\> fornecem os seguintes modelos de cache:  
  
-   [cache\_freelist](../standard-library/cache-freelist-class.md)  
  
-   [cache\_suballoc](../standard-library/cache-suballoc-class.md)  
  
-   [cache\_chunklist](../standard-library/cache-chunklist-class.md)  
  
 Um filtro é um alocador do bloco que implementa as funções de membro usando outro alocador do bloco que ele é passado como um argumento do modelo.  A maioria de forma comum de filtro é um filtro de sincronização, que aplica uma política de sincronização para controlar o acesso às funções de membro de uma instância de outro alocador do bloco. \<os alocadores\> fornecem os seguintes filtros de sincronização:  
  
-   [synchronization\_none](../standard-library/sync-none-class.md)  
  
-   [synchronization\_per\_container](../standard-library/sync-per-container-class.md)  
  
-   [synchronization\_per\_thread](../standard-library/sync-per-thread-class.md)  
  
-   [synchronization\_shared](../Topic/sync_shared%20Class.md)  
  
 \<os alocadores\> também fornecem o filtro [rts\_alloc](../standard-library/rts-alloc-class.md), que mantém o alocador do bloco várias instâncias e determina qual instância a ser usada para alocação ou desalocação em tempo de execução em vez de em tempo de compilação.  É usado com compiladores que não podem criar reassociações.  
  
 Uma política de sincronização determina como uma instância do alocador trata solicitações simultâneas de alocação e desalocação de vários threads.  A política a mais simples é passar diretamente todas as solicitações no objeto subjacente do cache, deixando o gerenciamento de sincronização para o usuário.  Uma política mais complexa foi possível usar um mutex para serializar o acesso ao objeto subjacente do cache.  
  
 Se um compilador da suporte à criação de thread único e aplicativos multi\-threaded, o filtro padrão de sincronização para aplicativos de thread único é `sync_none`; para todos os outros casos é `sync_shared`.  
  
 O modelo `cache_freelist` de cache usa um argumento máximo da classe que determina o número máximo de elementos a serem armazenados na lista livre.  
  
 \<os alocadores\> fornecem as seguintes classes mínima:  
  
-   [max\_none](../Topic/max_none%20Class.md)  
  
-   [max\_unbounded](../standard-library/max-unbounded-class.md)  
  
-   [max\_fixed\_size](../standard-library/max-fixed-size-class.md)  
  
-   [max\_variable\_size](../standard-library/max-variable-size-class.md)  
  
### Macros  
  
|||  
|-|-|  
|[ALLOCATOR\_DECL](../Topic/ALLOCATOR_DECL%20\(%3Callocators%3E\).md)|Gerencie uma classe do modelo do alocador.|  
|[CACHE\_CHUNKLIST](../Topic/CACHE_CHUNKLIST%20\(%3Callocators%3E\).md)|Gerencie `stdext::allocators::cache_chunklist<sizeof(Type)>`.|  
|[CACHE\_FREELIST](../Topic/CACHE_FREELIST%20\(%3Callocators%3E\).md)|Gerencie `stdext::allocators::cache_freelist<sizeof(Type), max>`.|  
|[CACHE\_SUBALLOC](../Topic/CACHE_SUBALLOC%20\(%3Callocators%3E\).md)|Gerencie `stdext::allocators::cache_suballoc<sizeof(Type)>`.|  
|[SYNC\_DEFAULT](../Topic/SYNC_DEFAULT%20\(%3Callocators%3E\).md)|Gerencie um filtro de sincronização.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\!\=](../Topic/operator!=%20\(%3Callocators%3E\).md)|Testes de desigualdade entre objetos do alocador de uma classe especificada.|  
|[operator\=\=](../Topic/operator==%20\(%3Callocators%3E\).md)|Testes de igualdade entre objetos do alocador de uma classe especificada.|  
  
### Classes  
  
|||  
|-|-|  
|[allocator\_base](../standard-library/allocator-base-class.md)|Define as funções da classe base e comum necessárias para criar um alocador definido pelo usuário de um filtro de sincronização.|  
|[allocator\_chunklist](../Topic/allocator_chunklist%20Class.md)|Descreve um objeto que gerencia a alocação de armazenamento e se liberar para objetos que usam um cache de tipo [cache\_chunklist](../standard-library/cache-chunklist-class.md).|  
|[allocator\_fixed\_size](../standard-library/allocator-fixed-size-class.md)|Descreve um objeto que gerencia a alocação de armazenamento e se liberar para objetos de tipo `Type` usando um cache de tipo [cache\_freelist](../standard-library/cache-freelist-class.md) com um comprimento gerenciado por [max\_fixed\_size](../standard-library/max-fixed-size-class.md).|  
|[allocator\_newdel](../standard-library/allocator-newdel-class.md)|Implementa um alocador que usa `operator delete` para desalocar um bloco e `operator new` de memória para alocar um bloco de memória.|  
|[allocator\_suballoc](../standard-library/allocator-suballoc-class.md)|Descreve um objeto que gerencia a alocação de armazenamento e se liberar para objetos de tipo `Type` usando um cache de tipo [cache\_suballoc](../standard-library/cache-suballoc-class.md).|  
|[allocator\_unbounded](../standard-library/allocator-unbounded-class.md)|Descreve um objeto que gerencia a alocação de armazenamento e se liberar para objetos de tipo `Type` usando um cache de tipo [cache\_freelist](../standard-library/cache-freelist-class.md) com um comprimento gerenciado por [max\_unbounded](../standard-library/max-unbounded-class.md).|  
|[allocator\_variable\_size](../standard-library/allocator-variable-size-class.md)|Descreve um objeto que gerencia a alocação de armazenamento e se liberar para objetos de tipo `Type` usando um cache de tipo [cache\_freelist](../standard-library/cache-freelist-class.md) com um comprimento gerenciado por [max\_variable\_size](../standard-library/max-variable-size-class.md).|  
|[cache\_chunklist](../standard-library/cache-chunklist-class.md)|Define um alocador do bloco que aloque e desaloque blocos de memória de um único tamanho.|  
|[cache\_freelist](../standard-library/cache-freelist-class.md)|Define um alocador do bloco que aloque e desaloque blocos de memória de um único tamanho.|  
|[cache\_suballoc](../standard-library/cache-suballoc-class.md)|Define um alocador do bloco que aloque e desaloque blocos de memória de um único tamanho.|  
|[freelist](../Topic/freelist%20Class.md)|Gerencia uma lista de blocos de memória.|  
|[max\_fixed\_size](../standard-library/max-fixed-size-class.md)|Descreve um objeto máximo da classe que limita um objeto de [freelist](../Topic/freelist%20Class.md) a um comprimento máximo fixo.|  
|[max\_none](../Topic/max_none%20Class.md)|Descreve um objeto máximo da classe que limita um objeto de [freelist](../Topic/freelist%20Class.md) a um comprimento máximo de zero.|  
|[max\_unbounded](../standard-library/max-unbounded-class.md)|Descreve um objeto máximo da classe que não limite o tamanho máximo de um objeto de [freelist](../Topic/freelist%20Class.md) .|  
|[max\_variable\_size](../standard-library/max-variable-size-class.md)|Descreve um objeto máximo da classe que limita um objeto de [freelist](../Topic/freelist%20Class.md) o comprimento máximo que é aproximadamente proporcional ao número de blocos de memória alocado.|  
|[rts\_alloc](../standard-library/rts-alloc-class.md)|A classe do modelo de rts\_alloc descreve [filtro](../standard-library/allocators-header.md) que contém uma matriz de instâncias do cache e determina qual instância a ser usada para a alocação e a desalocação em tempo de execução em vez de em tempo de compilação.|  
|[synchronization\_none](../standard-library/sync-none-class.md)|Descreve um filtro de sincronização que não fornece nenhuma sincronização.|  
|[synchronization\_per\_container](../standard-library/sync-per-container-class.md)|Descreve um filtro de sincronização que fornece um objeto separado de cache para cada objeto do alocador.|  
|[synchronization\_per\_thread](../standard-library/sync-per-thread-class.md)|Descreve um filtro de sincronização que fornece um objeto separado de cache para cada thread.|  
|[synchronization\_shared](../Topic/sync_shared%20Class.md)|Descreve um filtro de sincronização que usa um mutex para controlar o acesso a um objeto de cache que é compartilhado por todos os alocadores.|  
  
## Requisitos  
 alocadores \<de**Cabeçalho:** \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)