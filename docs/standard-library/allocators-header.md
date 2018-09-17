---
title: '&lt;allocators&gt; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- <allocators>
dev_langs:
- C++
helpviewer_keywords:
- allocators header
ms.assetid: 4393a607-4df8-4278-bbb2-c8ec52e60b83
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dcda07b5d2ab499a769c389538e8f272fd8441a6
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713161"
---
# <a name="ltallocatorsgt"></a>&lt;allocators&gt;

Define vários modelos que ajudam a alocar e liberar os blocos de memória para contêineres baseados em nó.

## <a name="syntax"></a>Sintaxe

```cpp
#include <allocators>
```

## <a name="remarks"></a>Comentários

O cabeçalho \<allocators> fornece seis modelos de alocadores que podem ser usados para selecionar as estratégias de gerenciamento de memória para contêineres baseados em nó. Para usar com esses modelos, ele também fornece vários filtros de sincronização diferentes para personalizar a estratégia de gerenciamento de memória para uma variedade de diferentes esquemas de multithreading (incluindo nenhum). Corresponder uma estratégia de gerenciamento de memória aos padrões de uso de memória e aos requisitos de sincronização conhecidos de um determinado aplicativo, geralmente pode aumentar a velocidade ou reduzir os requisitos de memória gerais de um aplicativo.

Os modelos de alocadores são implementados com componentes reutilizáveis que podem ser personalizados ou substituídos para fornecer estratégias adicionais de gerenciamento de memória.

Os contêineres baseados em nó na Biblioteca Padrão do C++ (std::list, std::set, std::multiset, std::map e std::multimap) armazenam seus elementos em nós individuais. Todos os nós de um tipo de contêiner específico têm o mesmo tamanho, portanto, não é necessário ter a flexibilidade de um gerenciador de memória de uso geral. Como o tamanho de cada bloco de memória é conhecido no tempo de compilação, o gerenciador de memória pode ser muito mais simples e rápido.

Quando usados com contêineres que não são baseados em nó (por exemplo, os contêineres std::vector std::deque e std::basic_string da Biblioteca Padrão do C++), os modelos de alocadores funcionarão corretamente, mas provavelmente não fornecerão nenhuma melhoria de desempenho em relação ao alocador padrão.

Um alocador é uma classe de modelo que descreve um objeto que gerencia a alocação e a liberação de armazenamento para objetos e matrizes de objetos de um tipo designado. Os objetos alocadores são usados por várias classes de modelo de contêiner na Biblioteca Padrão do C++.

Os alocadores são todos os modelos deste tipo:

```cpp
template<class Type>
class allocator;
```

em que o argumento de modelo `Type` é do tipo gerenciado pela instância do alocador. A Biblioteca Padrão do C++ fornece um alocador padrão, a classe de modelo [allocator](../standard-library/allocator-class.md), que é definida em [ \<memory>](../standard-library/memory.md). O cabeçalho \<allocators> fornece os alocadores a seguir:

- [allocator_newdel](../standard-library/allocator-newdel-class.md)

- [allocator_unbounded](../standard-library/allocator-unbounded-class.md)

- [allocator_fixed_size](../standard-library/allocator-fixed-size-class.md)

- [allocator_variable_size](../standard-library/allocator-variable-size-class.md)

- [allocator_suballoc](../standard-library/allocator-suballoc-class.md)

- [allocator_chunklist](../standard-library/allocator-chunklist-class.md)

Use uma criação de instância apropriada de um alocador como o segundo argumento de tipo ao criar um contêiner, como o exemplo de código a seguir.

`#include <list>`

`#include <allocators>`

`std::list<int, stdext::allocators::allocator_chunklist<int> > _List0;`

_List0 aloca nós com `allocator_chunklist` e o filtro de sincronização padrão.

Use a macro [ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl) para criar modelos de alocadores com filtros de sincronização diferentes do padrão:

`#include <list>`

`#include <allocators>`

`ALLOCATOR_DECL(CACHE_CHUNKLIST, stdext::allocators::sync_per_thread, Alloc);`

`std::list<int, alloc<int> > _List1;`

_Lst1 aloca nós com `allocator_chunklist` e o filtro de sincronização [sync_per_thread](../standard-library/sync-per-thread-class.md).

Um alocador de blocos é um cache ou um filtro. Um cache é uma classe de modelo que usa um argumento do tipo std:: size_t. Ele define um alocador de blocos que aloca e desaloca os blocos de memória de um único tamanho. Ele deve obter memória usando o operador **novos**, mas não precisa fazer uma chamada separada ao operador **novos** para cada bloco. Ele pode, por exemplo, subalocar de um bloco maior ou armazenar em cache os blocos desalocados para uma próxima realocação.

Com um compilador que não pode compilar reassociação, o valor do argumento std::size_t usado quando a instância do modelo foi criada não é necessariamente o valor do argumento _Sz passado para as funções de membro do cache alocar e desalocar.

\<allocators> fornece os seguintes modelos de cache:

- [cache_freelist](../standard-library/cache-freelist-class.md)

- [cache_suballoc](../standard-library/cache-suballoc-class.md)

- [cache_chunklist](../standard-library/cache-chunklist-class.md)

Um filtro é um alocador de blocos que implementa as funções de membro usando outro alocador de blocos que é passado para ele como um argumento de modelo. A forma mais comum de filtro é um filtro de sincronização, que aplica uma política de sincronização para controlar o acesso às funções de membro de uma instância de outro alocador de blocos. \<allocators> fornece os seguintes filtros de sincronização:

- [sync_none](../standard-library/sync-none-class.md)

- [sync_per_container](../standard-library/sync-per-container-class.md)

- [sync_per_thread](../standard-library/sync-per-thread-class.md)

- [sync_shared](../standard-library/sync-shared-class.md)

\<allocators> também fornece o filtro [rts_alloc](../standard-library/rts-alloc-class.md), que contém diversas instâncias de alocador de blocos e determina qual instância deve ser usada para alocação ou desalocação no tempo de execução, em vez de no tempo de compilação. Ele é usado com os compiladores que não podem compilar reassociação.

Uma política de sincronização determina como uma instância de alocador manipula solicitações simultâneas de alocação e desalocação de vários threads. A política mais simples é passar todas as solicitações diretamente para o objeto de cache subjacente, deixando o gerenciamento de sincronização para o usuário. Uma política mais complexa poderia ser usar um mutex para serializar o acesso ao objeto de cache subjacente.

Se um compilador der suporte à compilação de aplicativos de single-threaded e multi-threaded, o filtro de sincronização padrão para aplicativos de single-threaded será `sync_none`, para todos os outros casos, será `sync_shared`.

O modelo de cache `cache_freelist` usa um argumento de classe max que determina o número máximo de elementos a serem armazenados na lista livre.

\<allocators> fornece as seguintes classes max:

- [max_none](../standard-library/max-none-class.md)

- [max_unbounded](../standard-library/max-unbounded-class.md)

- [max_fixed_size](../standard-library/max-fixed-size-class.md)

- [max_variable_size](../standard-library/max-variable-size-class.md)

### <a name="macros"></a>Macros

|Macro|Descrição|
|-|-|
|[ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl)|Produz uma classe de modelo allocator.|
|[CACHE_CHUNKLIST](../standard-library/allocators-functions.md#cache_chunklist)|Produz `stdext::allocators::cache_chunklist<sizeof(Type)>`.|
|[CACHE_FREELIST](../standard-library/allocators-functions.md#cache_freelist)|Produz `stdext::allocators::cache_freelist<sizeof(Type), max>`.|
|[CACHE_SUBALLOC](../standard-library/allocators-functions.md#cache_suballoc)|Produz `stdext::allocators::cache_suballoc<sizeof(Type)>`.|
|[SYNC_DEFAULT](../standard-library/allocators-functions.md#sync_default)|Produz um filtro de sincronização.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator!= (\<allocators>)](../standard-library/allocators-operators.md#op_neq)|Testa a desigualdade entre objetos do alocador de uma classe especificada.|
|[operator== (\<allocators>)](../standard-library/allocators-operators.md#op_eq_eq)|Testa a igualdade entre objetos do alocador de uma classe especificada.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[allocator_base](../standard-library/allocator-base-class.md)|Define a classe base e as funções comuns necessárias para criar um alocador definido pelo usuário de um filtro de sincronização.|
|[allocator_chunklist](../standard-library/allocator-chunklist-class.md)|Descreve um objeto que gerencia a alocação de armazenamento e a liberação de objetos usando um cache do tipo [cache_chunklist](../standard-library/cache-chunklist-class.md).|
|[allocator_fixed_size](../standard-library/allocator-fixed-size-class.md)|Descreve um objeto que gerencia a alocação e a liberação de armazenamento para objetos do tipo `Type` usando um cache do tipo [cache_freelist](../standard-library/cache-freelist-class.md) com um comprimento gerenciado por [max_fixed_size](../standard-library/max-fixed-size-class.md).|
|[allocator_newdel](../standard-library/allocator-newdel-class.md)|Implementa um alocador que usa **operador delete** para desalocar uma memória bloco e **operador new** para alocar um bloco de memória.|
|[allocator_suballoc](../standard-library/allocator-suballoc-class.md)|Descreve um objeto que gerencia a alocação e a liberação de armazenamento para objetos do tipo `Type` usando um cache do tipo [cache_suballoc](../standard-library/cache-suballoc-class.md).|
|[allocator_unbounded](../standard-library/allocator-unbounded-class.md)|Descreve um objeto que gerencia a alocação e a liberação de armazenamento de objetos do tipo `Type`, usando um cache do tipo [cache_freelist](../standard-library/cache-freelist-class.md) com um comprimento gerenciado por [max_unbounded](../standard-library/max-unbounded-class.md).|
|[allocator_variable_size](../standard-library/allocator-variable-size-class.md)|Descreve um objeto que gerencia a alocação e a liberação de armazenamento para objetos do tipo `Type`, usando um cache do tipo [cache_freelist](../standard-library/cache-freelist-class.md) com um comprimento gerenciado por [max_variable_size](../standard-library/max-variable-size-class.md).|
|[cache_chunklist](../standard-library/cache-chunklist-class.md)|Define um alocador de blocos que aloca e desaloca os blocos de memória de um único tamanho.|
|[cache_freelist](../standard-library/cache-freelist-class.md)|Define um alocador de blocos que aloca e desaloca os blocos de memória de um único tamanho.|
|[cache_suballoc](../standard-library/cache-suballoc-class.md)|Define um alocador de blocos que aloca e desaloca os blocos de memória de um único tamanho.|
|[freelist](../standard-library/freelist-class.md)|Gerencia uma lista de blocos de memória.|
|[max_fixed_size](../standard-library/max-fixed-size-class.md)|Descreve um objeto da classe max que limita um objeto [freelist](../standard-library/freelist-class.md) a um comprimento máximo fixo.|
|[max_none](../standard-library/max-none-class.md)|Descreve um objeto da classe max que limita um objeto [freelist](../standard-library/freelist-class.md) a um comprimento máximo igual a zero.|
|[max_unbounded](../standard-library/max-unbounded-class.md)|Descreve um objeto da classe max que não limita o comprimento máximo de um objeto [freelist](../standard-library/freelist-class.md).|
|[max_variable_size](../standard-library/max-variable-size-class.md)|Descreve um objeto da classe max que limita um objeto [freelist](../standard-library/freelist-class.md) a um comprimento máximo aproximadamente proporcional ao número de blocos de memória alocados.|
|[rts_alloc](../standard-library/rts-alloc-class.md)|A classe de modelo rts_alloc descreve um [filtro](../standard-library/allocators-header.md) que contém uma matriz de instâncias de cache e determina qual instância será usada para alocação e desalocação no tempo de execução, em vez de no tempo de compilação.|
|[sync_none](../standard-library/sync-none-class.md)|Descreve um filtro de sincronização que não fornece nenhuma sincronização.|
|[sync_per_container](../standard-library/sync-per-container-class.md)|Descreve um filtro de sincronização que fornece um objeto de cache separado para cada objeto alocador.|
|[sync_per_thread](../standard-library/sync-per-thread-class.md)|Descreve um filtro de sincronização que fornece um objeto de cache separado para cada thread.|
|[sync_shared](../standard-library/sync-shared-class.md)|Descreve um filtro de sincronização que usa um mutex para controlar o acesso a um objeto de cache que é compartilhado por todos os alocadores.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
