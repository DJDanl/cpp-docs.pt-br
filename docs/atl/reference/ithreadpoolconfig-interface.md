---
title: IThreadPoolConfig Interface
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
ms.openlocfilehash: e4b90534fa89ef2aeffe4cd682d92efc16452487
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326353"
---
# <a name="ithreadpoolconfig-interface"></a>IThreadPoolConfig Interface

Esta interface fornece métodos para configurar um pool de segmentos.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
__interface
    __declspec(uuid("B1F64757-6E88-4fa2-8886-7848B0D7E660")) IThreadPoolConfig : public IUnknown
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[GetSize](#getsize)|Ligue para este método para obter o número de threads na piscina.|
|[GetTimeout](#gettimeout)|Chame este método para obter o tempo máximo em milissegundos que a piscina de roscas esperará por um fio para desligar.|
|[Setsize](#setsize)|Chame este método para definir o número de threads na piscina.|
|[Settimeout](#settimeout)|Chame este método para definir o tempo máximo em milissegundos que o pool de segmentos esperará por um fio para desligar.|

## <a name="remarks"></a>Comentários

Esta interface é implementada pelo [CThreadPool](../../atl/reference/cthreadpool-class.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil.h

## <a name="ithreadpoolconfiggetsize"></a><a name="getsize"></a>ithreadpoolconfig::getSize

Ligue para este método para obter o número de threads na piscina.

```
STDMETHOD(GetSize)(int* pnNumThreads);
```

### <a name="parameters"></a>Parâmetros

*pnNumThreads*<br/>
[fora] Endereço da variável que, no sucesso, recebe o número de threads no pool.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#134](../../atl/codesnippet/cpp/ithreadpoolconfig-interface_1.cpp)]

## <a name="ithreadpoolconfiggettimeout"></a><a name="gettimeout"></a>IThreadPoolConfig::GetTimeout

Chame este método para obter o tempo máximo em milissegundos que a piscina de roscas esperará por um fio para desligar.

```
STDMETHOD(GetTimeout)(DWORD* pdwMaxWait);
```

### <a name="parameters"></a>Parâmetros

*pdwMaxWait*<br/>
[fora] Endereço da variável que, no sucesso, recebe o tempo máximo em milissegundos que o pool de segmentos esperará por um segmento para desligar.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="example"></a>Exemplo

Ver [ithreadpoolconfig::getsize](#getsize).

## <a name="ithreadpoolconfigsetsize"></a><a name="setsize"></a>iThreadPoolConfig::SetSize

Chame este método para definir o número de threads na piscina.

```
STDMETHOD(SetSize)int nNumThreads);
```

### <a name="parameters"></a>Parâmetros

*Nnumthreads*<br/>
O número solicitado de fios na piscina.

Se *nNumThreads* for negativo, seu valor absoluto será multiplicado pelo número de processadores na máquina para obter o número total de threads.

Se *nNumThreads* for zero, ATLS_DEFAULT_THREADSPERPROC será multiplicado pelo número de processadores na máquina para obter o número total de threads.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="example"></a>Exemplo

Ver [ithreadpoolconfig::getsize](#getsize).

## <a name="ithreadpoolconfigsettimeout"></a><a name="settimeout"></a>IThreadPoolConfig::SetTimeout

Chame este método para definir o tempo máximo em milissegundos que o pool de segmentos esperará por um fio para desligar.

```
STDMETHOD(SetTimeout)(DWORD dwMaxWait);
```

### <a name="parameters"></a>Parâmetros

*dwMaxWait*<br/>
O tempo máximo solicitado em milissegundos para que a piscina de segmentos espere um fio ser desligado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="example"></a>Exemplo

Ver [ithreadpoolconfig::getsize](#getsize).

## <a name="see-also"></a>Confira também

[Classes](../../atl/reference/atl-classes.md)<br/>
[Classe CThreadPool](../../atl/reference/cthreadpool-class.md)
