---
title: '&lt;allocators&gt;'
ms.date: 11/04/2016
f1_keywords:
- <allocators>
helpviewer_keywords:
- allocators header
ms.assetid: 4393a607-4df8-4278-bbb2-c8ec52e60b83
ms.openlocfilehash: f981b86ed8f5d3b240d9f02380a603eb4f2605bc
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623576"
---
# <a name="ltallocatorsgt"></a>&lt;allocators&gt;

Define vários modelos que ajudam a alocar e liberar os blocos de memória para contêineres baseados em nó.

## <a name="syntax"></a>Sintaxe

```cpp
#include <allocators>
```

> [!NOTE]
> \<allocators>é preterido, começando com o Visual Studio 2019 versão 16,3.

## <a name="remarks"></a>Comentários

O \<allocators> cabeçalho fornece seis modelos de alocador que podem ser usados para selecionar estratégias de gerenciamento de memória para contêineres baseados em nó. Para usar com esses modelos, ele também fornece vários filtros de sincronização diferentes para personalizar a estratégia de gerenciamento de memória para uma variedade de diferentes esquemas de multithreading (incluindo nenhum). Você pode acelerar seu aplicativo ou reduzir seus requisitos de memória, combinando uma estratégia de gerenciamento de memória para seus padrões de uso de memória e requisitos de sincronização.

Os modelos de alocadores são implementados com componentes reutilizáveis que podem ser personalizados ou substituídos para fornecer estratégias adicionais de gerenciamento de memória.

Os contêineres baseados em nó na biblioteca padrão C++ (std:: list, std:: set, std:: multiconjunto, std:: Map e std:: Multimap) armazenam seus elementos em nós individuais. Todos os nós de um tipo de contêiner específico têm o mesmo tamanho, portanto, não é necessário ter a flexibilidade de um gerenciador de memória de uso geral. Como o tamanho de cada bloco de memória é conhecido no tempo de compilação, o gerenciador de memória pode ser muito mais simples e rápido.

Quando usado com contêineres que não são baseados em nó (como os contêineres de biblioteca padrão C++ std:: vector std::d eque e std:: basic_string), os modelos de alocador funcionarão corretamente, mas provavelmente não fornecerão nenhuma melhoria de desempenho sobre o alocador padrão.

Um alocador é um modelo de classe que descreve um objeto que gerencia a alocação de armazenamento e libera para objetos e matrizes de objetos de um tipo designado. Os objetos de alocador são usados por vários modelos de classe de contêiner na biblioteca padrão C++.

Os alocadores são todos os modelos deste tipo:

```cpp
template<class Type>
class allocator;
```

em que o argumento de modelo `Type` é do tipo gerenciado pela instância do alocador. A biblioteca padrão C++ fornece um alocador padrão, [alocador](allocator-class.md)de modelo de classe, que é definido em [\<memory>](memory.md) . O \<allocators> cabeçalho fornece os seguintes alocadores:

- [allocator_newdel](allocator-newdel-class.md)

- [allocator_unbounded](allocator-unbounded-class.md)

- [allocator_fixed_size](allocator-fixed-size-class.md)

- [allocator_variable_size](allocator-variable-size-class.md)

- [allocator_suballoc](allocator-suballoc-class.md)

- [allocator_chunklist](allocator-chunklist-class.md)

Use uma criação de instância apropriada de um alocador como o segundo argumento de tipo ao criar um contêiner, como o exemplo de código a seguir.

```cpp
#include <list>
#include <allocators>
std::list<int, stdext::allocators::allocator_chunklist<int> > _List0;
```

_List0 aloca nós com `allocator_chunklist` e o filtro de sincronização padrão.

Use a macro [ALLOCATOR_DECL](allocators-functions.md#allocator_decl) para criar modelos de alocadores com filtros de sincronização diferentes do padrão:

```cpp
#include <list>
#include <allocators>
ALLOCATOR_DECL(CACHE_CHUNKLIST, stdext::allocators::sync_per_thread, Alloc);
std::list<int, alloc<int> > _List1;
```

_Lst1 aloca nós com `allocator_chunklist` e o filtro de sincronização [sync_per_thread](sync-per-thread-class.md).

Um alocador de blocos é um cache ou um filtro. Um cache é um modelo de classe que usa um argumento do tipo std:: size_t. Ele define um alocador de blocos que aloca e desaloca os blocos de memória de um único tamanho. Ele deve obter a memória usando o operador **New**, mas não precisa fazer uma chamada separada para o operador **New** para cada bloco. Ele pode, por exemplo, subalocar de um bloco maior ou armazenar em cache os blocos desalocados para uma próxima realocação.

Com um compilador que não pode reassociar o valor do argumento std:: size_t usado quando o modelo foi instanciado não é necessariamente o valor do argumento _Sz passado para as funções membro de um cache, aloque e desaloque.

\<allocators>fornece os seguintes modelos de cache:

- [cache_freelist](cache-freelist-class.md)

- [cache_suballoc](cache-suballoc-class.md)

- [cache_chunklist](cache-chunklist-class.md)

Um filtro é um alocador de bloco que implementa suas funções de membro usando outro alocador de bloco, que é passado para ele como um argumento de modelo. A forma mais comum de filtro é um filtro de sincronização, que aplica uma política de sincronização para controlar o acesso às funções de membro de uma instância de outro alocador de blocos. \<allocators>fornece os seguintes filtros de sincronização:

- [sync_none](sync-none-class.md)

- [sync_per_container](sync-per-container-class.md)

- [sync_per_thread](sync-per-thread-class.md)

- [sync_shared](sync-shared-class.md)

\<allocators>também fornece o [rts_alloc](rts-alloc-class.md)de filtro, que contém várias instâncias de alocador de bloco e determina qual instância usar para alocação ou desalocação em tempo de execução em vez de em tempo de compilação. Ele é usado com os compiladores que não podem compilar reassociação.

Uma política de sincronização determina como uma instância de alocador manipula solicitações simultâneas de alocação e desalocação de vários threads. A política mais simples é passar todas as solicitações diretamente para o objeto de cache subjacente, deixando o gerenciamento de sincronização para o usuário. Uma política mais complexa poderia ser usar um mutex para serializar o acesso ao objeto de cache subjacente.

Se um compilador der suporte à compilação de aplicativos de single-threaded e multi-threaded, o filtro de sincronização padrão para aplicativos de single-threaded será `sync_none`, para todos os outros casos, será `sync_shared`.

O modelo de cache `cache_freelist` usa um argumento de classe Max, que determina o número máximo de elementos a serem armazenados na lista livre.

\<allocators>fornece as seguintes classes máximas:

- [max_none](max-none-class.md)

- [max_unbounded](max-unbounded-class.md)

- [max_fixed_size](max-fixed-size-class.md)

- [max_variable_size](max-variable-size-class.md)

### <a name="macros"></a>Macros

|Macro|Descrição|
|-|-|
|[ALLOCATOR_DECL](allocators-functions.md#allocator_decl)|Produz um modelo de classe de alocador.|
|[CACHE_CHUNKLIST](allocators-functions.md#cache_chunklist)|Produz `stdext::allocators::cache_chunklist<sizeof(Type)>`.|
|[CACHE_FREELIST](allocators-functions.md#cache_freelist)|Produz `stdext::allocators::cache_freelist<sizeof(Type), max>`.|
|[CACHE_SUBALLOC](allocators-functions.md#cache_suballoc)|Produz `stdext::allocators::cache_suballoc<sizeof(Type)>`.|
|[SYNC_DEFAULT](allocators-functions.md#sync_default)|Produz um filtro de sincronização.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador! = ( \<allocators> )](allocators-operators.md#op_neq)|Testa a desigualdade entre objetos do alocador de uma classe especificada.|
|[operador = = ( \<allocators> )](allocators-operators.md#op_eq_eq)|Testa a igualdade entre objetos do alocador de uma classe especificada.|

### <a name="classes"></a>Classes

|Class|Descrição|
|-|-|
|[allocator_base](allocator-base-class.md)|Define a classe base e as funções comuns necessárias para criar um alocador definido pelo usuário de um filtro de sincronização.|
|[allocator_chunklist](allocator-chunklist-class.md)|Descreve um objeto que gerencia a alocação de armazenamento e a liberação de objetos usando um cache do tipo [cache_chunklist](cache-chunklist-class.md).|
|[allocator_fixed_size](allocator-fixed-size-class.md)|Descreve um objeto que gerencia a alocação e a liberação de armazenamento para objetos do tipo `Type` usando um cache do tipo [cache_freelist](cache-freelist-class.md) com um comprimento gerenciado por [max_fixed_size](max-fixed-size-class.md).|
|[allocator_newdel](allocator-newdel-class.md)|Implementa um alocador que usa o **operador Delete** para desalocar um bloco de memória e um **operador novo** para alocar um bloco de memória.|
|[allocator_suballoc](allocator-suballoc-class.md)|Descreve um objeto que gerencia a alocação e a liberação de armazenamento para objetos do tipo `Type` usando um cache do tipo [cache_suballoc](cache-suballoc-class.md).|
|[allocator_unbounded](allocator-unbounded-class.md)|Descreve um objeto que gerencia a alocação e a liberação de armazenamento de objetos do tipo `Type`, usando um cache do tipo [cache_freelist](cache-freelist-class.md) com um comprimento gerenciado por [max_unbounded](max-unbounded-class.md).|
|[allocator_variable_size](allocator-variable-size-class.md)|Descreve um objeto que gerencia a alocação e a liberação de armazenamento para objetos do tipo `Type`, usando um cache do tipo [cache_freelist](cache-freelist-class.md) com um comprimento gerenciado por [max_variable_size](max-variable-size-class.md).|
|[cache_chunklist](cache-chunklist-class.md)|Define um alocador de blocos que aloca e desaloca os blocos de memória de um único tamanho.|
|[cache_freelist](cache-freelist-class.md)|Define um alocador de blocos que aloca e desaloca os blocos de memória de um único tamanho.|
|[cache_suballoc](cache-suballoc-class.md)|Define um alocador de blocos que aloca e desaloca os blocos de memória de um único tamanho.|
|[freelist](freelist-class.md)|Gerencia uma lista de blocos de memória.|
|[max_fixed_size](max-fixed-size-class.md)|Descreve um objeto da classe max que limita um objeto [freelist](freelist-class.md) a um comprimento máximo fixo.|
|[max_none](max-none-class.md)|Descreve um objeto da classe max que limita um objeto [freelist](freelist-class.md) a um comprimento máximo igual a zero.|
|[max_unbounded](max-unbounded-class.md)|Descreve um objeto da classe max que não limita o comprimento máximo de um objeto [freelist](freelist-class.md).|
|[max_variable_size](max-variable-size-class.md)|Descreve um objeto da classe max que limita um objeto [freelist](freelist-class.md) a um comprimento máximo aproximadamente proporcional ao número de blocos de memória alocados.|
|[rts_alloc](rts-alloc-class.md)|O modelo de classe rts_alloc descreve um [filtro](allocators-header.md) que contém uma matriz de instâncias de cache e determina qual instância usar para alocação e desalocação em tempo de execução em vez de em tempo de compilação.|
|[sync_none](sync-none-class.md)|Descreve um filtro de sincronização que não fornece nenhuma sincronização.|
|[sync_per_container](sync-per-container-class.md)|Descreve um filtro de sincronização que fornece um objeto de cache separado para cada objeto alocador.|
|[sync_per_thread](sync-per-thread-class.md)|Descreve um filtro de sincronização que fornece um objeto de cache separado para cada thread.|
|[sync_shared](sync-shared-class.md)|Descreve um filtro de sincronização que usa um mutex para controlar o acesso a um objeto de cache que é compartilhado por todos os alocadores.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](cpp-standard-library-header-files.md)
