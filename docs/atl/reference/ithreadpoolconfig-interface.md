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
ms.openlocfilehash: b3757f0e90479962273a8295e055c91fb02260f4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62198181"
---
# <a name="ithreadpoolconfig-interface"></a>Interface IThreadPoolConfig

Essa interface fornece métodos para configurar um pool de threads.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
__interface
    __declspec(uuid("B1F64757-6E88-4fa2-8886-7848B0D7E660")) IThreadPoolConfig : public IUnknown
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[GetSize](#getsize)|Chame esse método para obter o número de threads no pool.|
|[GetTimeout](#gettimeout)|Chame esse método para obter o tempo máximo em milissegundos que o pool de threads irá esperar por um segmento para desligar.|
|[SetSize](#setsize)|Chame esse método para definir o número de threads no pool.|
|[SetTimeout](#settimeout)|Chame esse método para definir o tempo máximo em milissegundos que o pool de threads irá esperar por um segmento para desligar.|

## <a name="remarks"></a>Comentários

Essa interface é implementada pelo [CThreadPool](../../atl/reference/cthreadpool-class.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil

##  <a name="getsize"></a>  IThreadPoolConfig::GetSize

Chame esse método para obter o número de threads no pool.

```
STDMETHOD(GetSize)(int* pnNumThreads);
```

### <a name="parameters"></a>Parâmetros

*pnNumThreads*<br/>
[out] Endereço da variável que, em caso de sucesso, recebe o número de threads no pool.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#134](../../atl/codesnippet/cpp/ithreadpoolconfig-interface_1.cpp)]

##  <a name="gettimeout"></a>  IThreadPoolConfig::GetTimeout

Chame esse método para obter o tempo máximo em milissegundos que o pool de threads irá esperar por um segmento para desligar.

```
STDMETHOD(GetTimeout)(DWORD* pdwMaxWait);
```

### <a name="parameters"></a>Parâmetros

*pdwMaxWait*<br/>
[out] Endereço da variável que, em caso de sucesso, recebe o tempo máximo em milissegundos que o pool de threads irá esperar por um segmento para desligar.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="example"></a>Exemplo

Ver [IThreadPoolConfig::GetSize](#getsize).

##  <a name="setsize"></a>  IThreadPoolConfig::SetSize

Chame esse método para definir o número de threads no pool.

```
STDMETHOD(SetSize)int nNumThreads);
```

### <a name="parameters"></a>Parâmetros

*nNumThreads*<br/>
O número solicitado de threads no pool.

Se *nNumThreads* é negativo, seu valor absoluto será multiplicado pelo número de processadores no computador para obter o número total de threads.

Se *nNumThreads* for zero, ATLS_DEFAULT_THREADSPERPROC será multiplicado pelo número de processadores no computador para obter o número total de threads.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="example"></a>Exemplo

Ver [IThreadPoolConfig::GetSize](#getsize).

##  <a name="settimeout"></a>  IThreadPoolConfig::SetTimeout

Chame esse método para definir o tempo máximo em milissegundos que o pool de threads irá esperar por um segmento para desligar.

```
STDMETHOD(SetTimeout)(DWORD dwMaxWait);
```

### <a name="parameters"></a>Parâmetros

*dwMaxWait*<br/>
O tempo máximo solicitado em milissegundos que o pool de threads irá esperar por um segmento para desligar.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="example"></a>Exemplo

Ver [IThreadPoolConfig::GetSize](#getsize).

## <a name="see-also"></a>Consulte também

[Classes](../../atl/reference/atl-classes.md)<br/>
[Classe CThreadPool](../../atl/reference/cthreadpool-class.md)
