---
title: '&lt;memory&gt;'
ms.date: 08/04/2019
f1_keywords:
- memory/std::<memory>
- <memory>
- std::<memory>
helpviewer_keywords:
- memory header
ms.openlocfilehash: 0e3ce4a4411bd6d4c352802a96c97e93c66491df
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88836459"
---
# <a name="ltmemorygt"></a>&lt;memory&gt;

Define uma classe, um operador e vários modelos que ajudam a alocar e a liberar objetos.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<memory>

**Namespace:** std

## <a name="members"></a>Membros

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[AddressOf](../standard-library/memory-functions.md#addressof)|Obtém o endereço verdadeiro de um objeto.|
|[align](../standard-library/memory-functions.md#align)|Retorna um ponteiro para um intervalo de um determinado tamanho, com base no endereço de início e alinhamento fornecidos.|
|[allocate_shared](../standard-library/memory-functions.md#allocate_shared)|Cria um `shared_ptr` para objetos atribuídos e construídos para um determinado tipo com um alocador especificado.|
|[atomic_compare_exchange_strong](../standard-library/memory-functions.md#atomic_compare_exchange_strong)||
|[atomic_compare_exchange_weak](../standard-library/memory-functions.md#atomic_compare_exchange_weak)||
|[atomic_compare_exchange_strong_explicit](../standard-library/memory-functions.md#atomic_compare_exchange_strong_explicit)||
|[atomic_compare_exchange_weak_explicit](../standard-library/memory-functions.md#atomic_compare_exchange_weak_explicit)||
|[atomic_exchange](../standard-library/memory-functions.md#atomic_exchange)||
|[atomic_exchange_explicit](../standard-library/memory-functions.md#atomic_exchange_explicit)||
|[atomic_is_lock_free](../standard-library/memory-functions.md#atomic_is_lock_free)||
|[atomic_load](../standard-library/memory-functions.md#atomic_load)||
|[atomic_load_explicit](../standard-library/memory-functions.md#atomic_load_explicit)||
|[atomic_store](../standard-library/memory-functions.md#atomic_store)||
|[atomic_store_explicit](../standard-library/memory-functions.md#atomic_store_explicit)||
|[const_pointer_cast](../standard-library/memory-functions.md#const_pointer_cast)|Conversão constante para `shared_ptr`.|
|[declare_no_pointers](../standard-library/memory-functions.md#declare_no_pointers)|Informa a um coletor de lixo que os caracteres começando em um endereço especificado e recaindo no tamanho de bloco indicado não contêm ponteiros rastreáveis.|
|[declare_reachable](../standard-library/memory-functions.md#declare_reachable)|Informa a coleta de lixo que o endereço indicado é para armazenamento alocado e é alcançável.|
|[default_delete](../standard-library/memory-functions.md#default_delete)|Exclui objetos alocados com `operator new`. Adequado para uso com `unique_ptr`.|
|[destroy_at](../standard-library/memory-functions.md#destroy_at)|Método abreviado `destroy` .|
|[destruir](../standard-library/memory-functions.md#destroy)|Método abreviado `destroy` .|
|[destroy_n](../standard-library/memory-functions.md#destroy_n)|Método abreviado `destroy` .|
|[dynamic_pointer_cast](../standard-library/memory-functions.md#dynamic_pointer_cast)|Conversão dinâmica para `shared_ptr`.|
|[get_deleter](../standard-library/memory-functions.md#get_deleter)|Obtenha o deletor de `shared_ptr`.|
|[get_pointer_safety](../standard-library/memory-functions.md#get_pointer_safety)|Retorna o tipo de segurança do ponteiro pressuposto por qualquer coletor de lixo.|
|[get_temporary_buffer](../standard-library/memory-functions.md#get_temporary_buffer)|Atribui o armazenamento temporário para uma sequência de elementos que não excede um número especificado de elementos.|
|[make_shared](../standard-library/memory-functions.md#make_shared)|Cria e retorna um `shared_ptr` que aponta para o objeto alocado construído do zero ou mais argumentos usando o alocador padrão.|
|[make_unique](../standard-library/memory-functions.md#make_unique)|Cria e retorna um [unique_ptr](../standard-library/unique-ptr-class.md) que aponta para o objeto alocado construído de zero ou mais argumentos.|
|[pointer_safety](../standard-library/memory-enums.md#pointer_safety)|Uma enumeração de todos os possíveis valores de retorno para `get_pointer_safety`.|
|[return_temporary_buffer](../standard-library/memory-functions.md#return_temporary_buffer)|Desaloca a memória temporária que foi alocada usando a função de modelo `get_temporary_buffer`.|
|[static_pointer_cast](../standard-library/memory-functions.md#static_pointer_cast)|Conversão estática para `shared_ptr`.|
|[permuta](../standard-library/memory-functions.md#swap)|Troca dois objetos `shared_ptr` ou `weak_ptr`.|
|[undeclare_no_pointers](../standard-library/memory-functions.md#undeclare_no_pointers)|Informa um coletor de lixo que os caracteres no bloco de memória definido por um ponteiro de endereço básico e o tamanho de bloco agora podem conter ponteiros rastreáveis.|
|[undeclare_reachable](../standard-library/memory-functions.md#undeclare_reachable)|Informa um `garbage_collector` que um local de memória especificado não é alcançável.|
|[uninitialized_copy](../standard-library/memory-functions.md#uninitialized_copy)|Copia objetos de um intervalo de entrada especificado em um intervalo de destino não inicializado.|
|[uninitialized_copy_n](../standard-library/memory-functions.md#uninitialized_copy_n)|Cria uma cópia de um número especificado de elementos de um iterador de entrada. As cópias são colocadas em um iterador de avanço.|
|[uninitialized_default_construct](../standard-library/memory-functions.md#uninitialized_default_construct)|Método abreviado `uninitialized_default_construct` .|
|[uninitialized_default_construct_n](../standard-library/memory-functions.md#uninitialized_default_construct_n)|Método abreviado `uninitialized_construct` .|
|[uninitialized_fill](../standard-library/memory-functions.md#uninitialized_fill)|Copia objetos de um valor especificado em um intervalo de destino não inicializado.|
|[uninitialized_fill_n](../standard-library/memory-functions.md#uninitialized_fill_n)|Copia objetos de um valor especificado em um número especificado de elementos de um intervalo de destino não inicializado.|
|[uninitialized_move](../standard-library/memory-functions.md#uninitialized_move)|Método abreviado `uninitialized_move` .|
|[uninitialized_move_n](../standard-library/memory-functions.md#uninitialized_move_n)|Método abreviado `uninitialized_move` .|
|[uninitialized_value_construct](../standard-library/memory-functions.md#uninitialized_value_construct)|Método abreviado `uninitialized_value_construct` .|
|[uninitialized_value_construct_n](../standard-library/memory-functions.md#uninitialized_value_construct_n)|Método abreviado `uninitialized_value_construct` .|
|[uses_allocator_v](../standard-library/memory-functions.md#uses_allocator_v)||

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador! =](../standard-library/memory-operators.md#op_neq)|Testa a desigualdade entre objetos do alocador de uma classe especificada.|
|[operador = =](../standard-library/memory-operators.md#op_eq_eq)|Testa a igualdade entre objetos do alocador de uma classe especificada.|
|[>do operador =](../standard-library/memory-operators.md#op_gt_eq)|Testa um objeto do alocador que é maior ou igual a um segundo objeto do alocador de uma classe especificada.|
|[<do operador ](../standard-library/memory-operators.md#op_lt)|Testa um objeto que é menor que um segundo objeto de uma classe especificada.|
|[operador\<=](../standard-library/memory-operators.md#op_gt_eq)|Testa um objeto que é menor ou igual a um segundo objeto de uma classe especificada.|
|[>do operador ](../standard-library/memory-operators.md#op_gt)|Testa um objeto que é maior que um segundo objeto de uma classe especificada.|
|[<<do operador ](../standard-library/memory-operators.md#op_lt_lt)|Inserção de `shared_ptr`.|

### <a name="classes"></a>Classes

|Nome|Descrição|
|-|-|
|[allocator](../standard-library/allocator-class.md)|O modelo de classe descreve um objeto que gerencia a alocação de armazenamento e libera para matrizes de objetos **do tipo Type.**|
|[allocator_traits](../standard-library/allocator-traits-class.md)|Descreve um objeto que determina todas as informações necessárias a um contêiner habilitado para alocador.|
|[auto_ptr](../standard-library/auto-ptr-class.md)|O modelo de classe descreve um objeto que armazena um ponteiro para um objeto alocado do **tipo Type** <strong>\*</strong> que garante o objeto ao qual os pontos de ti são excluídos quando seu auto_ptr de circunscrição é destruído.|
|[bad_weak_ptr](../standard-library/bad-weak-ptr-class.md)|Relata a exceção weak_ptr incorreta.|
|[enabled_shared_from_this](../standard-library/enable-shared-from-this-class.md)|Ajuda a gerar um `shared_ptr`.|
|[pointer_traits](../standard-library/pointer-traits-struct.md)|Fornece informações necessárias para um objeto do tipo `allocator_traits` para descrever um alocador com tipo de ponteiro `Ptr` .|
|[raw_storage_iterator](../standard-library/raw-storage-iterator-class.md)|Uma classe de adaptador que é fornecida para permitir que algoritmos armazenem seus resultados na memória não inicializada.|
|[shared_ptr](../standard-library/shared-ptr-class.md)|Encapsula um ponteiro inteligente de contagem de referência em torno de um objeto alocado dinamicamente.|
|[unique_ptr](../standard-library/unique-ptr-class.md)|Armazena um ponteiro para um objeto possuído. O ponteiro não é possuído por nenhum outro `unique_ptr`. O `unique_ptr` é destruído quando o proprietário é destruído.|
|[weak_ptr](../standard-library/weak-ptr-class.md)|Encapsula um ponteiro vinculado de modo fraco.|

### <a name="structures"></a>Estruturas

|Nome|Descrição|
|-|-|
|[allocator_arg_t](../standard-library/allocator-class.md#allocator_arg_t)||
|[default_delete](../standard-library/default-delete-struct.md)||
|hash|Fornece sobrecargas especializadas para `unique_ptr` e `shared_ptr` .|
|[owner_less](../standard-library/memory-functions.md#owner_less)|Permite comparações mistas baseadas em propriedade de ponteiros compartilhados e fracos.|
|[uses_allocator](../standard-library/allocator-class.md#uses_allocator)||

### <a name="specializations"></a>Especializações

|Nome|Descrição|
|-|-|
|[allocator\<void>](../standard-library/allocator-void-class.md)|Uma especialização do alocador de modelo de classe a ser digitada **`void`** , definindo somente os tipos de membro que fazem sentido nesse contexto especializado.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
