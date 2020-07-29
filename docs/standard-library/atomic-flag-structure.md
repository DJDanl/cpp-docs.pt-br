---
title: Estrutura atomic_flag
ms.date: 11/04/2016
f1_keywords:
- atomic/std::atomic_flag
- atomic/std::atomic_flag::clear
- atomic/std::atomic_flag::test_and_set
ms.assetid: 17f0c2f5-fd39-4a44-873a-b569720a670e
ms.openlocfilehash: ff60e05c7d14104e164e8251a9146f8b0d0dcde3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87203917"
---
# <a name="atomic_flag-structure"></a>Estrutura atomic_flag

Descreve um objeto que define atomicamente e limpa um **`bool`** sinalizador. Operações em sinalizadores atômicos são sempre livres de bloqueio.

## <a name="syntax"></a>Sintaxe

```cpp
struct atomic_flag;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[formatação](#clear)|Define o sinalizador armazenado como **`false`** .|
|[test_and_set](#test_and_set)|Define o sinalizador armazenado como **`true`** e retorna o valor inicial do sinalizador.|

## <a name="remarks"></a>Comentários

Objetos `atomic_flag` podem ser passados para as funções não membro [atomic_flag_clear](../standard-library/atomic-functions.md#atomic_flag_clear), [atomic_flag_clear_explicit](../standard-library/atomic-functions.md#atomic_flag_clear_explicit), [atomic_flag_test_and_set](../standard-library/atomic-functions.md#atomic_flag_test_and_set) e [atomic_flag_test_and_set_explicit](../standard-library/atomic-functions.md#atomic_flag_test_and_set_explicit). Eles podem ser inicializados usando o valor `ATOMIC_FLAG_INIT`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<atomic>

**Namespace:** std

## <a name="atomic_flagclear"></a><a name="clear"></a>atomic_flag:: Clear

Define o **`bool`** sinalizador que é armazenado no **`*this`** para **`false`** , dentro das restrições de [memory_order](../standard-library/atomic-enums.md#memory_order_enum) especificadas.

```cpp
void atomic_flag::clear(memory_order Order = memory_order_seq_cst) volatile noexcept;
void atomic_flag::clear(memory_order Order = memory_order_seq_cst) noexcept;
```

### <a name="parameters"></a>parâmetros

*Ordene*\
Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

## <a name="atomic_flagtest_and_set"></a><a name="test_and_set"></a>atomic_flag:: test_and_set

Define o **`bool`** sinalizador que é armazenado no **`*this`** para **`true`** , dentro das restrições de [memory_order](../standard-library/atomic-enums.md#memory_order_enum) especificadas.

```cpp
bool atomic_flag::test_and_set(memory_order Order = memory_order_seq_cst) volatile noexcept;
bool atomic_flag::test_and_set(memory_order Order = memory_order_seq_cst) noexcept;
```

### <a name="parameters"></a>parâmetros

*Ordene*\
Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

### <a name="return-value"></a>Valor retornado

O valor inicial do sinalizador armazenado em **`*this`** .

## <a name="see-also"></a>Confira também

[\<atomic>](../standard-library/atomic.md)
