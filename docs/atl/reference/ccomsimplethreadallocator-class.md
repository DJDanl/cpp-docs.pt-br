---
title: Classe ccomsimplethreadalocador
ms.date: 11/04/2016
f1_keywords:
- CComSimpleThreadAllocator
- ATLBASE/ATL::CComSimpleThreadAllocator
- ATLBASE/ATL::CComSimpleThreadAllocator::GetThread
helpviewer_keywords:
- threading [ATL], selecting threads
- ATL threads
- CComSimpleThreadAllocator class
- ATL threads, allocating
ms.assetid: 66b2166a-8c50-49fd-b8e4-7f293470327d
ms.openlocfilehash: 4a3cce492db4db9f46aeb4efe738ee6a594ddcfc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327338"
---
# <a name="ccomsimplethreadallocator-class"></a>Classe ccomsimplethreadalocador

Esta classe gerencia a seleção de segmentos para a classe `CComAutoThreadModule`.

## <a name="syntax"></a>Sintaxe

```
class CComSimpleThreadAllocator
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSimpleThreadAlocador::GetThread](#getthread)|Seleciona um segmento.|

## <a name="remarks"></a>Comentários

`CComSimpleThreadAllocator`gerencia a seleção de threads para [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md). `CComSimpleThreadAllocator::GetThread`simplesmente percorre cada segmento e retorna o próximo na sequência.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccomsimplethreadallocatorgetthread"></a><a name="getthread"></a>CComSimpleThreadAlocador::GetThread

Seleciona um segmento especificando o próximo segmento na seqüência.

```
int GetThread(CComApartment* /* pApt */, int nThreads);
```

### <a name="parameters"></a>Parâmetros

*pApt*<br/>
Não usado na implementação padrão da ATL.

*Nthreads*<br/>
O número máximo de threads no módulo EXE.

### <a name="return-value"></a>Valor retornado

Um inteiro entre zero e *(nThreads* - 1). Identifica um dos segmentos no módulo EXE.

### <a name="remarks"></a>Comentários

Você pode `GetThread` substituir para fornecer um método diferente de seleção ou para fazer uso do parâmetro *pApt.*

`GetThread`é chamado por [CComAutoThreadModule:CreateInstance](../../atl/reference/ccomautothreadmodule-class.md#createinstance).

## <a name="see-also"></a>Confira também

[Classe CComApartment](../../atl/reference/ccomapartment-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
