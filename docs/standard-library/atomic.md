---
title: '&lt;atomic&gt;'
description: Descreve os tipos e funções disponíveis no cabeçalho atômico da biblioteca C++ padrão.
ms.date: 12/06/2019
f1_keywords:
- <atomic>
- atomic/std::atomic_int_least32_t
- atomic/std::atomic_ullong
- atomic/std::atomic_ptrdiff_t
- atomic/std::atomic_char16_t
- atomic/std::atomic_schar
- atomic/std::atomic_ulong
- atomic/std::atomic_uint_fast32_t
- atomic/std::atomic_uint8_t
- atomic/std::atomic_int32_t
- atomic/std::atomic_uint_fast64_t
- atomic/std::atomic_uint32_t
- atomic/std::atomic_int16_t
- atomic/std::atomic_uintmax_t
- atomic/std::atomic_intmax_t
- atomic/std::atomic_long
- atomic/std::atomic_int
- atomic/std::atomic_uint_least8_t
- atomic/std::atomic_size_t
- atomic/std::atomic_uint_fast16_t
- atomic/std::atomic_wchar_t
- atomic/std::atomic_int_fast64_t
- atomic/std::atomic_uint_fast8_t
- atomic/std::atomic_int_fast8_t
- atomic/std::atomic_intptr_t
- atomic/std::atomic_uint
- atomic/std::atomic_uint16_t
- atomic/std::atomic_char32_t
- atomic/std::atomic_uint64_t
- atomic/std::atomic_ushort
- atomic/std::atomic_int_least16_t
- atomic/std::atomic_char
- atomic/std::atomic_uint_least32_t
- atomic/std::atomic_uintptr_t
- atomic/std::atomic_short
- atomic/std::atomic_llong
- atomic/std::atomic_uint_least16_t
- atomic/std::atomic_int_fast16_t
- atomic/std::atomic_int_least8_t
- atomic/std::atomic_int_least64_t
- atomic/std::atomic_int_fast32_t
- atomic/std::atomic_uchar
- atomic/std::atomic_int8_t
- atomic/std::atomic_int64_t
- atomic/std::atomic_uint_least64_t
ms.assetid: e79a6b9f-52ff-48da-9554-654c4e1999f6
ms.openlocfilehash: 3c5f732dbda701eb7744b1b25a9a8e7426f7a3e2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87203891"
---
# <a name="ltatomicgt"></a>&lt;atomic&gt;

Define classes e modelos de classe a serem usados para criar tipos que dão suporte a operações atômicas.

## <a name="syntax"></a>Sintaxe

```cpp
#include <atomic>
```

## <a name="remarks"></a>Comentários

> [!NOTE]
> No código que é compilado usando [/CLR: Pure](../build/reference/clr-common-language-runtime-compilation.md), esse cabeçalho é bloqueado. Tanto **/CLR: Pure** quanto **/CLR: safe** são preteridos no Visual Studio 2017 e versões posteriores.

Uma operação atômica tem duas propriedades-chave que o ajudarão a usar vários threads para manipular um objeto corretamente sem usar bloqueios de mutex.

- Como uma operação atômica é indivisível, uma segunda operação atômica no mesmo objeto de um thread diferente pode obter o estado do objeto somente antes ou depois da primeira operação atômica.

- Com base em seu argumento [memory_order](../standard-library/atomic-enums.md#memory_order_enum), uma operação atômica estabelece os requisitos de ordenação para a visibilidade dos efeitos de outras operações atômicas no mesmo thread. Consequentemente, inibe a otimizações do compilador que violam os requisitos de ordenação.

Em algumas plataformas, pode não ser possível implementar operações atômicas com eficiência para alguns tipos sem usar bloqueios `mutex`. Um tipo atômico será *livre de bloqueio* se nenhuma operação atômica no tipo usar bloqueios.

**C++ 11**: em manipuladores de sinal, você pode executar operações atômicas em um objeto `obj` se `obj.is_lock_free()` ou `atomic_is_lock_free(x)` for true.

A classe [atomic_flag](../standard-library/atomic-flag-structure.md) fornece um tipo atômico mínimo que contém um **`bool`** sinalizador. Suas operações são sempre livres de bloqueio.

O modelo de classe `atomic<T>` armazena um objeto de seu tipo de argumento `T` e fornece acesso atômico ao valor armazenado. Você pode instanciá-la usando qualquer tipo que possa ser copiado usando [memcpy](../c-runtime-library/reference/memcpy-wmemcpy.md) e testadas quanto à igualdade usando [memcmp](../c-runtime-library/reference/memcmp-wmemcmp.md). Em particular, você pode usá-la com tipos definidos pelo usuário que atendam a esses requisitos e, em muitos casos, os tipos de ponto flutuante.

O modelo também tem um conjunto de especializações para tipos integrais e uma especialização parcial de ponteiros. Essas especializações fornecem operações adicionais que não estão disponíveis por meio do modelo primário.

## <a name="pointer-specializations"></a>Especializações do ponteiro

As especializações parciais `atomic<T *>` se aplicam a todos os tipos de ponteiro. Elas fornecem métodos para aritmética de ponteiro.

## <a name="integral-specializations"></a>Especializações integrais

As especializações `atomic<integral>` aplicam-se a todos os tipos integrais. Eles fornecem operações adicionais que não estão disponíveis por meio do modelo primário.

Cada tipo `atomic<integral>` tem uma macro correspondente que você pode usar em um `if directive` para determinar no tempo de compilação se operações desse tipo estão livres de bloqueio. Se o valor da macro for zero, as operações no tipo não serão sem bloqueio. Se o valor for 1, as operações podem ser livres de bloqueio e uma verificação de runtime será necessária. Se o valor for 2, as operações serão livres de bloqueio. Você pode usar a função `atomic_is_lock_free` para determinar no runtime se as operações no tipo são livres de bloqueio.

Para cada um dos tipos integrais, há um tipo atômico nomeado correspondente que gerencia um objeto desse tipo integral. Cada tipo `atomic_integral` tem o mesmo conjunto de funções membro que a instanciação correspondente de `atomic<T>` e pode ser passado para qualquer uma das funções atômicas não membro.

|Tipo `atomic_integral`|Tipo integral|Macro `atomic_is_lock_free`|
|----------------------------|-------------------|---------------------------------|
|`atomic_char`|**`char`**|ATOMIC_CHAR_LOCK_FREE|
|`atomic_schar`|**`signed char`**|ATOMIC_CHAR_LOCK_FREE|
|`atomic_uchar`|**`unsigned char`**|ATOMIC_CHAR_LOCK_FREE|
|`atomic_char16_t`|**`char16_t`**|ATOMIC_CHAR16_T_LOCK_FREE|
|`atomic_char32_t`|**`char32_t`**|ATOMIC_CHAR32_T_LOCK_FREE|
|`atomic_wchar_t`|**`wchar_t`**|ATOMIC_WCHAR_T_LOCK_FREE|
|`atomic_short`|**`short`**|ATOMIC_SHORT_LOCK_FREE|
|`atomic_ushort`|**`unsigned short`**|ATOMIC_SHORT_LOCK_FREE|
|`atomic_int`|**`int`**|ATOMIC_INT_LOCK_FREE|
|`atomic_uint`|**`unsigned int`**|ATOMIC_INT_LOCK_FREE|
|`atomic_long`|**`long`**|ATOMIC_LONG_LOCK_FREE|
|`atomic_ulong`|**`unsigned long`**|ATOMIC_LONG_LOCK_FREE|
|`atomic_llong`|**`long long`**|ATOMIC_LLONG_LOCK_FREE|
|`atomic_ullong`|**`unsigned long long`**|ATOMIC_LLONG_LOCK_FREE|

Existem nomes de typedef para especializações do modelo atômico para alguns dos tipos que são definidos no cabeçalho \<inttypes.h> .

|Tipo Atômico|Nome Typedef|
|-----------------|------------------|
|`atomic_int8_t`|`atomic<int8_t>`|
|`atomic_uint8_t`|`atomic<uint8_t>`|
|`atomic_int16_t`|`atomic<int16_t>`|
|`atomic_uint16_t`|`atomic<uint16_t>`|
|`atomic_int32_t`|`atomic<int32_t>`|
|`atomic_uint32_t`|`atomic<uint32_t>`|
|`atomic_int64_t`|`atomic<int64_t>`|
|`atomic_uint64_t`|`atomic<uint64_t>`|
|`atomic_int_least8_t`|`atomic<int_least8_t>`|
|`atomic_uint_least8_t`|`atomic<uint_least8_t>`|
|`atomic_int_least16_t`|`atomic<int_least16_t>`|
|`atomic_uint_least16_t`|`atomic<uint_least16_t>`|
|`atomic_int_least32_t`|`atomic<int_least32_t>`|
|`atomic_uint_least32_t`|`atomic<uint_least32_t>`|
|`atomic_int_least64_t`|`atomic<int_least64_t>`|
|`atomic_uint_least64_t`|`atomic<uint_least64_t>`|
|`atomic_int_fast8_t`|`atomic<int_fast8_t>`|
|`atomic_uint_fast8_t`|`atomic<uint_fast8_t>`|
|`atomic_int_fast16_t`|`atomic<int_fast16_t>`|
|`atomic_uint_fast16_`|`atomic<uint_fast16_t>`|
|`atomic_int_fast32_t`|`atomic<int_fast32_t>`|
|`atomic_uint_fast32_t`|`atomic<uint_fast32_t>`|
|`atomic_int_fast64_t`|`atomic<int_fast64_t>`|
|`atomic_uint_fast64_t`|`atomic<uint_fast64_t>`|
|`atomic_intptr_t`|`atomic<intptr_t>`|
|`atomic_uintptr_t`|`atomic<uintptr_t>`|
|`atomic_size_t`|`atomic<size_t>`|
|`atomic_ptrdiff_t`|`atomic<ptrdiff_t>`|
|`atomic_intmax_t`|`atomic<intmax_t>`|
|`atomic_uintmax_t`|`atomic<uintmax_t>`|

## <a name="structs"></a>Estruturas

|Nome|Descrição|
|----------|-----------------|
|[Estrutura atomic](../standard-library/atomic-structure.md)|Descreve um objeto que executa operações atômicas em um valor armazenado.|
|[Estrutura atomic_flag](../standard-library/atomic-flag-structure.md)|Descreve um objeto que define atomicamente e limpa um **`bool`** sinalizador.|

## <a name="enums"></a>Enumerações

|Nome|Descrição|
|----------|-----------------|
|[memory_order enum](../standard-library/atomic-enums.md#memory_order_enum)|Fornece nomes simbólicos para operações de sincronização em locais na memória. Essas operações afetam como atribuições em um thread se tornam visíveis em outro.|

## <a name="functions"></a>Funções

Na lista a seguir, as funções que não terminam `_explicit` têm a semântica do correspondente `_explicit` , exceto pelo fato de que elas têm os argumentos de [memory_order](../standard-library/atomic-enums.md#memory_order_enum) implícitos de `memory_order_seq_cst` .

|Nome|Descrição|
|----------|-----------------|
|[atomic_compare_exchange_strong](../standard-library/atomic-functions.md#atomic_compare_exchange_strong)|Executa uma operação de *comparação e troca atômica*.|
|[atomic_compare_exchange_strong_explicit](../standard-library/atomic-functions.md#atomic_compare_exchange_strong_explicit)|Executa uma operação de *comparação e troca atômica*.|
|[atomic_compare_exchange_weak](../standard-library/atomic-functions.md#atomic_compare_exchange_weak)|Executa uma operação de *comparação e troca atômica fraca*.|
|[atomic_compare_exchange_weak_explicit](../standard-library/atomic-functions.md#atomic_compare_exchange_weak_explicit)|Executa uma operação de *comparação e troca atômica fraca*.|
|[atomic_exchange](../standard-library/atomic-functions.md#atomic_exchange)|Substitui um valor armazenado.|
|[atomic_exchange_explicit](../standard-library/atomic-functions.md#atomic_exchange_explicit)|Substitui um valor armazenado.|
|[atomic_fetch_add](../standard-library/atomic-functions.md#atomic_fetch_add)|Adiciona um valor especificado a um valor armazenado existente.|
|[atomic_fetch_add_explicit](../standard-library/atomic-functions.md#atomic_fetch_add_explicit)|Adiciona um valor especificado a um valor armazenado existente.|
|[atomic_fetch_and](../standard-library/atomic-functions.md#atomic_fetch_and)|Executa um `and` bit a bit em um valor especificado e um valor armazenado existente.|
|[atomic_fetch_and_explicit](../standard-library/atomic-functions.md#atomic_fetch_and_explicit)|Executa um `and` bit a bit em um valor especificado e um valor armazenado existente.|
|[atomic_fetch_or](../standard-library/atomic-functions.md#atomic_fetch_or)|Executa um `or` bit a bit em um valor especificado e um valor armazenado existente.|
|[atomic_fetch_or_explicit](../standard-library/atomic-functions.md#atomic_fetch_or_explicit)|Executa um `or` bit a bit em um valor especificado e um valor armazenado existente.|
|[atomic_fetch_sub](../standard-library/atomic-functions.md#atomic_fetch_sub)|Subtrai um valor especificado de um valor armazenado existente.|
|[atomic_fetch_sub_explicit](../standard-library/atomic-functions.md#atomic_fetch_sub_explicit)|Subtrai um valor especificado de um valor armazenado existente.|
|[atomic_fetch_xor](../standard-library/atomic-functions.md#atomic_fetch_xor)|Executa um `exclusive or` bit a bit em um valor especificado e um valor armazenado existente.|
|[atomic_fetch_xor_explicit](../standard-library/atomic-functions.md#atomic_fetch_xor_explicit)|Executa um `exclusive or` bit a bit em um valor especificado e um valor armazenado existente.|
|[atomic_flag_clear](../standard-library/atomic-functions.md#atomic_flag_clear)|Define o sinalizador em um `atomic_flag` objeto como **`false`** .|
|[atomic_flag_clear_explicit](../standard-library/atomic-functions.md#atomic_flag_clear_explicit)|Define o sinalizador em um `atomic_flag` objeto como **`false`** .|
|[atomic_flag_test_and_set](../standard-library/atomic-functions.md#atomic_flag_test_and_set)|Define o sinalizador em um `atomic_flag` objeto como **`true`** .|
|[atomic_flag_test_and_set_explicit](../standard-library/atomic-functions.md#atomic_flag_test_and_set_explicit)|Define o sinalizador em um `atomic_flag` objeto como **`true`** .|
|[atomic_init](../standard-library/atomic-functions.md#atomic_init)|Define o valor armazenado em um objeto `atomic`.|
|[atomic_is_lock_free](../standard-library/atomic-functions.md#atomic_is_lock_free)|Especifica se operações atômicas em um objeto especificado estão livres de bloqueio.|
|[atomic_load](../standard-library/atomic-functions.md#atomic_load)|Recupera um valor atomicamente.|
|[atomic_load_explicit](../standard-library/atomic-functions.md#atomic_load_explicit)|Recupera um valor atomicamente.|
|[atomic_signal_fence](../standard-library/atomic-functions.md#atomic_signal_fence)|Atua como um *limite* que estabelece os requisitos de ordenação de memória entre limites em um thread de chamada que tem manipuladores de sinal executados no mesmo thread.|
|[atomic_store](../standard-library/atomic-functions.md#atomic_store)|Armazena um valor atomicamente.|
|[atomic_store_explicit](../standard-library/atomic-functions.md#atomic_store_explicit)|Armazena um valor atomicamente.|
|[atomic_thread_fence](../standard-library/atomic-functions.md#atomic_thread_fence)|Atua como um *limite* que estabelece os requisitos de ordenação de memória em relação a outros limites.|
|[kill_dependency](../standard-library/atomic-functions.md#kill_dependency)|Divide uma cadeia de dependências possível.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
