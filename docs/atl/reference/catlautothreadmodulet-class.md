---
title: Classe CAtlAutoThreadModuleT
ms.date: 11/04/2016
f1_keywords:
- CAtlAutoThreadModuleT
- ATLBASE/ATL::CAtlAutoThreadModuleT
- ATLBASE/ATL::CAtlAutoThreadModuleT::GetDefaultThreads
helpviewer_keywords:
- CAtlAutoThreadModuleT class
ms.assetid: ae1667c6-3fb8-47bc-b35d-9ea5e9896d7f
ms.openlocfilehash: e7b7a327d7c47c4472b43ed58fbe9ad0556a7620
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321549"
---
# <a name="catlautothreadmodulet-class"></a>Classe CAtlAutoThreadModuleT

Esta classe fornece métodos para implementar um servidor COM com modelo de apartamento com thread pooled.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T,
         class ThreadAllocator = CComSimpleThreadAllocator,
         DWORD dwWait = INFINITE>
class ATL_NO_VTABLE CAtlAutoThreadModuleT : public IAtlAutoThreadModule
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
A classe que implementará o servidor COM.

*Alocador de thread*<br/>
A classe gerenciando a seleção de segmentos. O valor padrão é [CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md).

*dwWait*<br/>
Especifica o intervalo de tempo, em milissegundos. O padrão é INFINITE, o que significa que o intervalo de tempo do método nunca se desenrola.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlAutoThreadModuleT::GetDefaultThreads](#getdefaultthreads)|Esta função estática calcula e retorna dinamicamente o número máximo de threads para o módulo EXE, com base no número de processadores.|

## <a name="remarks"></a>Comentários

A classe [CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md) `CAtlAutoThreadModuleT` deriva para implementar um servidor COM de modelo de apartamento com thread pooled. Ele substitui a classe obsoleta [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).

> [!NOTE]
> Esta classe não deve ser usada em uma DLL, pois o valor padrão *dwWait* do INFINITE causará um impasse quando a DLL for descarregada.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IAtlAutoThreadModule`

`CAtlAutoThreadModuleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="catlautothreadmoduletgetdefaultthreads"></a><a name="getdefaultthreads"></a>CAtlAutoThreadModuleT::GetDefaultThreads

Esta função estática calcula e retorna dinamicamente o número máximo de threads para o módulo EXE, com base no número de processadores.

```
static int GetDefaultThreads();
```

### <a name="return-value"></a>Valor retornado

O número de threads a serem criados no módulo EXE.

### <a name="remarks"></a>Comentários

Anular este método se você quiser usar um método diferente para calcular o número de threads. Por padrão, o número de threads é baseado no número de processadores.

## <a name="see-also"></a>Confira também

[Classe IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)<br/>
[Aulas de módulo](../../atl/atl-module-classes.md)
