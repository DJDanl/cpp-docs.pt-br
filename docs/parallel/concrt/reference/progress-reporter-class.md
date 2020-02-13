---
title: Classe progress_reporter
ms.date: 11/04/2016
f1_keywords:
- progress_reporter
- PPLTASKS/concurrency::progress_reporter
- PPLTASKS/concurrency::progress_reporter::progress_reporter
- PPLTASKS/concurrency::progress_reporter::report
helpviewer_keywords:
- progress_reporter class
ms.assetid: b836efab-2d05-4649-b6fa-d15236f1f813
ms.openlocfilehash: bd8f50a8c9829ff9de3e2412b89aa4de88d90db6
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77138766"
---
# <a name="progress_reporter-class"></a>Classe progress_reporter

A classe de relator de andamento permite criar relatórios de notificações de andamento de um tipo específico. Cada objeto progress_reporter está associado a uma determinada ação ou operação assíncrona.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename _ProgressType>
class progress_reporter;
```

### <a name="parameters"></a>Parâmetros

*_ProgressType*<br/>
O tipo de carga de cada notificação de andamento relatada pelo relator de andamento.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[progress_reporter](#ctor)||

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[relatar](#report)|Envia um relatório de andamento para a ação ou operação assíncrona à qual este relator de andamento está associado.|

## <a name="remarks"></a>Comentários

Esse tipo só está disponível para Windows Runtime aplicativos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`progress_reporter`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ppltasks. h

**Namespace:** simultaneidade

## <a name="ctor"></a>progress_reporter

```cpp
progress_reporter();
```

## <a name="report"></a>relatar

Envia um relatório de andamento para a ação ou operação assíncrona à qual este relator de andamento está associado.

```cpp
void report(const _ProgressType& val) const;
```

### <a name="parameters"></a>Parâmetros

*val*<br/>
A carga a ser relatada por meio de uma notificação de progresso.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
