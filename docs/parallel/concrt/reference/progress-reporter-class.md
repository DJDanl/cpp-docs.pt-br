---
title: Classe progress_reporter | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- progress_reporter
- PPLTASKS/concurrency::progress_reporter
- PPLTASKS/concurrency::progress_reporter::progress_reporter
- PPLTASKS/concurrency::progress_reporter::report
dev_langs:
- C++
helpviewer_keywords:
- progress_reporter class
ms.assetid: b836efab-2d05-4649-b6fa-d15236f1f813
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8dfb224fb0c0f641e4b7ef8809268fa4fad58890
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46438789"
---
# <a name="progressreporter-class"></a>Classe progress_reporter

A classe de relator de andamento permite criar relatórios de notificações de andamento de um tipo específico. Cada objeto progress_reporter está associado a uma determinada ação ou operação assíncrona.

## <a name="syntax"></a>Sintaxe

```
template<typename _ProgressType>
class progress_reporter;
```

#### <a name="parameters"></a>Parâmetros

*_ProgressType*<br/>
O tipo de carga de cada notificação de andamento relatada pelo relator de andamento.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[progress_reporter](#ctor)||

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[report](#report)|Envia um relatório de andamento para a ação ou operação assíncrona à qual este relator de andamento está associado.|

## <a name="remarks"></a>Comentários

Esse tipo só está disponível para aplicativos do Windows Runtime.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`progress_reporter`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppltasks. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> progress_reporter

```
progress_reporter();
```

##  <a name="report"></a> relatório

Envia um relatório de andamento para a ação ou operação assíncrona à qual este relator de andamento está associado.

```
void report(const _ProgressType& val) const;
```

### <a name="parameters"></a>Parâmetros

*Val*<br/>
A carga de relatório por meio de uma notificação de progresso.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
