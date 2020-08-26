---
title: Interface IThreadPoolConfig
ms.date: 11/04/2016
f1_keywords:
- IThreadPoolConfig
- ATLUTIL/ATL::IThreadPoolConfig
- ATLUTIL/ATL::GetSize
- ATLUTIL/ATL::GetTimeout
- ATLUTIL/ATL::SetSize
- ATLUTIL/ATL::SetTimeout
helpviewer_keywords:
- IThreadPoolConfig interface
ms.assetid: 69e642bf-6925-46e6-9a37-cce52231b1cc
ms.openlocfilehash: cba82055c292fc966dc2328773cce4aa64d45a64
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88835422"
---
# <a name="ithreadpoolconfig-interface"></a>Interface IThreadPoolConfig

Essa interface fornece métodos para configurar um pool de threads.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
__interface
    __declspec(uuid("B1F64757-6E88-4fa2-8886-7848B0D7E660")) IThreadPoolConfig : public IUnknown
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|Nome|Descrição|
|-|-|
|[GetSize](#getsize)|Chame esse método para obter o número de threads no pool.|
|[GetTimeout](#gettimeout)|Chame esse método para obter o tempo máximo em milissegundos que o pool de threads aguardará até que um thread seja desligado.|
|[Size](#setsize)|Chame esse método para definir o número de threads no pool.|
|[SetTimeout](#settimeout)|Chame esse método para definir o tempo máximo em milissegundos que o pool de threads aguardará até que um thread seja desligado.|

## <a name="remarks"></a>Comentários

Essa interface é implementada pelo [CThreadPool](../../atl/reference/cthreadpool-class.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil. h

## <a name="ithreadpoolconfiggetsize"></a><a name="getsize"></a> IThreadPoolConfig::GetSize

Chame esse método para obter o número de threads no pool.

```
STDMETHOD(GetSize)(int* pnNumThreads);
```

### <a name="parameters"></a>parâmetros

*pnNumThreads*<br/>
fora Endereço da variável que, em caso de êxito, recebe o número de threads no pool.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#134](../../atl/codesnippet/cpp/ithreadpoolconfig-interface_1.cpp)]

## <a name="ithreadpoolconfiggettimeout"></a><a name="gettimeout"></a> IThreadPoolConfig:: GetTimeout

Chame esse método para obter o tempo máximo em milissegundos que o pool de threads aguardará até que um thread seja desligado.

```
STDMETHOD(GetTimeout)(DWORD* pdwMaxWait);
```

### <a name="parameters"></a>parâmetros

*pdwMaxWait*<br/>
fora Endereço da variável que, em caso de êxito, recebe o tempo máximo em milissegundos que o pool de threads aguardará até que um thread seja desligado.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="example"></a>Exemplo

Consulte [IThreadPoolConfig:: GetSize](#getsize).

## <a name="ithreadpoolconfigsetsize"></a><a name="setsize"></a> IThreadPoolConfig:: SetSize

Chame esse método para definir o número de threads no pool.

```
STDMETHOD(SetSize)int nNumThreads);
```

### <a name="parameters"></a>parâmetros

*nNumThreads*<br/>
O número de threads solicitado no pool.

Se *nNumThreads* for negativo, seu valor absoluto será multiplicado pelo número de processadores no computador para obter o número total de threads.

Se *nNumThreads* for zero, ATLS_DEFAULT_THREADSPERPROC será multiplicado pelo número de processadores no computador para obter o número total de threads.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="example"></a>Exemplo

Consulte [IThreadPoolConfig:: GetSize](#getsize).

## <a name="ithreadpoolconfigsettimeout"></a><a name="settimeout"></a> IThreadPoolConfig:: SetTimeout

Chame esse método para definir o tempo máximo em milissegundos que o pool de threads aguardará até que um thread seja desligado.

```
STDMETHOD(SetTimeout)(DWORD dwMaxWait);
```

### <a name="parameters"></a>parâmetros

*dwMaxWait*<br/>
O tempo máximo solicitado em milissegundos que o pool de threads aguardará até que um thread seja desligado.

### <a name="return-value"></a>Valor Retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="example"></a>Exemplo

Consulte [IThreadPoolConfig:: GetSize](#getsize).

## <a name="see-also"></a>Confira também

[Classes](../../atl/reference/atl-classes.md)<br/>
[Classe CThreadPool](../../atl/reference/cthreadpool-class.md)
