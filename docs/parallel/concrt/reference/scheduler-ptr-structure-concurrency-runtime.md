---
title: Estrutura scheduler_ptr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::get
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::operator bool
dev_langs:
- C++
ms.assetid: e88c84af-c306-476d-aef1-f42a0fa0a80f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ea128a6122bf69735d118045eef2e8d8e323f8de
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46393406"
---
# <a name="schedulerptr-structure"></a>Estrutura scheduler_ptr

Representa um ponteiro para um agendador. Esta classe existe para permitir a especificação de um tempo de vida compartilhado usando o shared_ptr ou apenas uma referência simples usando o ponteiro bruto.

## <a name="syntax"></a>Sintaxe

```
struct scheduler_ptr;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[scheduler_ptr::scheduler_ptr](#ctor)|Sobrecarregado. Cria um ponteiro de Agendador de shared_ptr para Agendador|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[scheduler_ptr::get](#get)|Retorna o ponteiro bruto ao Agendador|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[scheduler_ptr:: Operator bool](#operator_bool)|Testar se o ponteiro de Agendador é não nulo|
|[scheduler_ptr::operator-&gt;](#operator_ptr)|Atua como um ponteiro|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`scheduler_ptr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** pplinterface. h

**Namespace:** simultaneidade

##  <a name="get"></a>  scheduler_ptr:: Get método

Retorna o ponteiro bruto ao Agendador

```
scheduler_interface* get() const;
```

### <a name="return-value"></a>Valor de retorno

##  <a name="operator_bool"></a>  scheduler_ptr:: Operator bool

Testar se o ponteiro de Agendador é não nulo

' ' operador bool () const;
```

##  <a name="operator_ptr"></a>  scheduler_ptr::operator-&gt;

Behave like a pointer

```
scheduler_interface * operator -> () const;
```

### Return Value

##  <a name="ctor"></a>  scheduler_ptr::scheduler_ptr Constructor

Creates a scheduler pointer from shared_ptr to scheduler

```
scheduler_ptr explícita (Agendador std:: shared_ptr < scheduler_interface >);

scheduler_ptr explícito (_In_opt_ scheduler_interface * pScheduler);
```

### Parameters

*scheduler*<br/>
The scheduler to convert.

*pScheduler*<br/>
The scheduler pointer to convert.

## See Also

[concurrency Namespace](concurrency-namespace.md)
