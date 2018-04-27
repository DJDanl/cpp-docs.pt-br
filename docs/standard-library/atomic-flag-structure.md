---
title: Estrutura atomic_flag | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- atomic/std::atomic_flag
- atomic/std::atomic_flag::clear
- atomic/std::atomic_flag::test_and_set
dev_langs:
- C++
ms.assetid: 17f0c2f5-fd39-4a44-873a-b569720a670e
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1f36164427f7cbc1cea9fda5f7e4d20896323d08
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="atomicflag-structure"></a>Estrutura atomic_flag

Descreve um objeto que define e limpa atomicamente um sinalizador `bool`. Operações em sinalizadores atômicos são sempre livres de bloqueio.

## <a name="syntax"></a>Sintaxe

```cpp
struct atomic_flag;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[clear](#clear)|Define o sinalizador armazenado como `false`.|
|[test_and_set](#test_and_set)|Define o sinalizador armazenado como `true` e retorna o valor de sinalizador inicial.|

## <a name="remarks"></a>Comentários

Objetos `atomic_flag` podem ser passados para as funções não membro [atomic_flag_clear](../standard-library/atomic-functions.md#atomic_flag_clear), [atomic_flag_clear_explicit](../standard-library/atomic-functions.md#atomic_flag_clear_explicit), [atomic_flag_test_and_set](../standard-library/atomic-functions.md#atomic_flag_test_and_set) e [atomic_flag_test_and_set_explicit](../standard-library/atomic-functions.md#atomic_flag_test_and_set_explicit). Eles podem ser inicializados usando o valor `ATOMIC_FLAG_INIT`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<atômico >

**Namespace:** std

## <a name="clear"></a>  atomic_flag::clear

Define o sinalizador `bool` que é armazenado em `*this` para `false`, dentro das restrições [memory_order](../standard-library/atomic-enums.md#memory_order_enum) especificadas.

```cpp
void atomic_flag::clear(memory_order Order = memory_order_seq_cst) volatile noexcept;
void atomic_flag::clear(memory_order Order = memory_order_seq_cst) noexcept;
```

### <a name="parameters"></a>Parâmetros

`Order` Um [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

## <a name="test_and_set"></a>  atomic_flag::test_and_set

Define o sinalizador `bool` que é armazenado em `*this` para `true`, dentro das restrições [memory_order](../standard-library/atomic-enums.md#memory_order_enum) especificadas.

```cpp
bool atomic_flag::test_and_set(memory_order Order = memory_order_seq_cst) volatile noexcept;
bool atomic_flag::test_and_set(memory_order Order = memory_order_seq_cst) noexcept;
```

### <a name="parameters"></a>Parâmetros

`Order` Um [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

### <a name="return-value"></a>Valor de retorno

O valor inicial do sinalizador armazenado em `*this`.

## <a name="see-also"></a>Consulte também

[\<atomic>](../standard-library/atomic.md)<br/>
