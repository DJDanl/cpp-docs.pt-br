---
title: Estrutura scheduler_ptr
ms.date: 11/04/2016
f1_keywords:
- scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::get
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::operator bool
ms.assetid: e88c84af-c306-476d-aef1-f42a0fa0a80f
ms.openlocfilehash: 60d71a26e5dffcadfb900ef15c26a6d9dc6d6f8b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358775"
---
# <a name="scheduler_ptr-structure"></a>Estrutura scheduler_ptr

Representa um ponteiro para um agendador. Esta classe existe para permitir a especificação de uma vida compartilhada usando shared_ptr ou apenas uma referência simples usando ponteiro bruto.

## <a name="syntax"></a>Sintaxe

```cpp
struct scheduler_ptr;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[scheduler_ptr:scheduler_ptr](#ctor)|Sobrecarregado. Cria um ponteiro do agendador de shared_ptr ao agendador|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[scheduler_ptr::get](#get)|Retorna o ponteiro bruto para o agendador|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[scheduler_ptr:operador bool](#operator_bool)|Teste se o ponteiro do agendador não é nulo|
|[scheduler_ptr:operador-&gt;](#operator_ptr)|Comporto-se como um ponteiro|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`scheduler_ptr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** pplinterface.h

**Namespace:** concurrency

## <a name="scheduler_ptrget-method"></a><a name="get"></a>scheduler_ptr::get Método

Retorna o ponteiro bruto para o agendador.

```cpp
scheduler_interface* get() const;
```

### <a name="return-value"></a>Valor retornado

## <a name="scheduler_ptroperator-bool"></a><a name="operator_bool"></a>scheduler_ptr:operador bool

Testa se o ponteiro do agendador não é nulo.

```cpp
operator bool() const;
```

## <a name="scheduler_ptroperator-gt"></a><a name="operator_ptr"></a>scheduler_ptr:operador-&gt;

Comporta-se como um ponteiro.

```cpp
scheduler_interface* operator->() const;
```

### <a name="return-value"></a>Valor retornado

## <a name="scheduler_ptrscheduler_ptr-constructor"></a><a name="ctor"></a>scheduler_ptr:scheduler_ptr Construtor

Cria um ponteiro do agendador de shared_ptr ao agendador.

```cpp
explicit scheduler_ptr(std::shared_ptr<scheduler_interface> scheduler);
explicit scheduler_ptr(_In_opt_ scheduler_interface* pScheduler);
```

### <a name="parameters"></a>Parâmetros

*Agendador*<br/>
O agendador para converter.

*pScheduler*<br/>
O ponteiro do agendador para converter.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)
