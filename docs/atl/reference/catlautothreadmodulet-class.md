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
ms.openlocfilehash: 7308e3a51c531fbe942e2df326c03273eeb326e2
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168716"
---
# <a name="catlautothreadmodulet-class"></a>Classe CAtlAutoThreadModuleT

Essa classe fornece métodos para implementar um servidor COM de modelo de apartamento em pool de threads.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T,
         class ThreadAllocator = CComSimpleThreadAllocator,
         DWORD dwWait = INFINITE>
class ATL_NO_VTABLE CAtlAutoThreadModuleT : public IAtlAutoThreadModule
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
A classe que implementará o servidor COM.

*ThreadAllocator*<br/>
A classe que gerencia a seleção de thread. O valor padrão é [CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md).

*dwWait*<br/>
Especifica o intervalo de tempo limite, em milissegundos. O padrão é infinito, o que significa que o intervalo de tempo limite do método nunca é decorrido.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlAutoThreadModuleT::GetDefaultThreads](#getdefaultthreads)|Essa função estática calcula dinamicamente e retorna o número máximo de threads para o módulo EXE, com base no número de processadores.|

## <a name="remarks"></a>Comentários

A classe [CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md) deriva de `CAtlAutoThreadModuleT` para implementar um servidor com de modelo de apartamento em pool de threads. Ele substitui a classe obsoleta [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).

> [!NOTE]
> Essa classe não deve ser usada em uma DLL, pois o valor padrão de *dwWait* de infinito causará um deadlock quando a DLL for descarregada.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IAtlAutoThreadModule`

`CAtlAutoThreadModuleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="catlautothreadmoduletgetdefaultthreads"></a><a name="getdefaultthreads"></a>CAtlAutoThreadModuleT::GetDefaultThreads

Essa função estática calcula dinamicamente e retorna o número máximo de threads para o módulo EXE, com base no número de processadores.

```cpp
static int GetDefaultThreads();
```

### <a name="return-value"></a>Valor retornado

O número de threads a serem criados no módulo EXE.

### <a name="remarks"></a>Comentários

Substitua esse método se desejar usar um método diferente para calcular o número de threads. Por padrão, o número de threads é baseado no número de processadores.

## <a name="see-also"></a>Confira também

[Classe IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)
