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
ms.openlocfilehash: dac74085278418153ddec502f6257ce13885704d
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57282533"
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

*val*<br/>
A carga de relatório por meio de uma notificação de progresso.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
