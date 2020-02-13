---
title: Estrutura de scheduler_ptr
ms.date: 11/04/2016
f1_keywords:
- scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::scheduler_ptr
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::get
- PPLINTERFACE/concurrency::scheduler_ptr::scheduler_ptr::operator bool
ms.assetid: e88c84af-c306-476d-aef1-f42a0fa0a80f
ms.openlocfilehash: fd044a6255a17882c26183223f71564f98c9f7b2
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142780"
---
# <a name="scheduler_ptr-structure"></a>Estrutura de scheduler_ptr

Representa um ponteiro para um Agendador. Essa classe existe para permitir a especificação de um tempo de vida compartilhado usando shared_ptr ou apenas uma referência simples usando ponteiro bruto.

## <a name="syntax"></a>Sintaxe

```cpp
struct scheduler_ptr;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[scheduler_ptr:: scheduler_ptr](#ctor)|Sobrecarregado. Cria um ponteiro do Agendador de shared_ptr para o Agendador|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[scheduler_ptr:: Get](#get)|Retorna o ponteiro bruto para o Agendador|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[scheduler_ptr:: Operator bool](#operator_bool)|Testar se o ponteiro do Agendador é não nulo|
|[operador scheduler_ptr:: Operator-&gt;](#operator_ptr)|Se comporta como um ponteiro|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`scheduler_ptr`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** pplinterface. h

**Namespace:** simultaneidade

## <a name="get"></a>Método scheduler_ptr:: Get

Retorna o ponteiro bruto para o Agendador.

```cpp
scheduler_interface* get() const;
```

### <a name="return-value"></a>Valor retornado

## <a name="operator_bool"></a>scheduler_ptr:: Operator bool

Testa se o ponteiro do Agendador é não nulo.

```cpp
operator bool() const;
```

## <a name="operator_ptr"></a>operador scheduler_ptr:: Operator-&gt;

Comporta-se como um ponteiro.

```cpp
scheduler_interface* operator->() const;
```

### <a name="return-value"></a>Valor retornado

## <a name="ctor"></a>Construtor scheduler_ptr:: scheduler_ptr

Cria um ponteiro do Agendador de shared_ptr para o Agendador.

```cpp
explicit scheduler_ptr(std::shared_ptr<scheduler_interface> scheduler);
explicit scheduler_ptr(_In_opt_ scheduler_interface* pScheduler);
```

### <a name="parameters"></a>Parâmetros

*Agendador*<br/>
O Agendador a ser convertido.

*pScheduler*<br/>
O ponteiro do Agendador a ser convertido.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
