---
title: Classe ISupportErrorInfoImpl
ms.date: 11/04/2016
f1_keywords:
- ISupportErrorInfoImpl
- ATLCOM/ATL::ISupportErrorInfoImpl
- ATLCOM/ATL::ISupportErrorInfoImpl::InterfaceSupportsErrorInfo
helpviewer_keywords:
- ISupportErrorInfo ATL implementation
- ISupportErrorInfoImpl class
- error information, ATL
ms.assetid: e33a4b11-a123-41cf-bcea-7b19743902af
ms.openlocfilehash: a4427a1190f145cc001a3288535df287326e97e3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50523272"
---
# <a name="isupporterrorinfoimpl-class"></a>Classe ISupportErrorInfoImpl

Essa classe fornece uma implementação padrão do [ISupportErrorInfo Interface](/previous-versions/windows/desktop/api/oaidl/nn-oaidl-isupporterrorinfo) e pode ser usada quando somente uma única interface gera erros em um objeto.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<const IID* piid>
class ATL_NO_VTABLE ISupportErrorInfoImpl
   : public ISupportErrorInfo
```

#### <a name="parameters"></a>Parâmetros

*piid*<br/>
Um ponteiro para o IID de uma interface que suporta [IErrorInfo](/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo).

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[ISupportErrorInfoImpl::InterfaceSupportsErrorInfo](#interfacesupportserrorinfo)|Indica se a interface identificada pelo `riid` oferece suporte a [IErrorInfo](/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo) interface.|

## <a name="remarks"></a>Comentários

O [ISupportErrorInfo Interface](/previous-versions/windows/desktop/api/oaidl/nn-oaidl-isupporterrorinfo) garante que as informações de erro podem ser retornadas ao cliente. Objetos que usam `IErrorInfo` deve implementar `ISupportErrorInfo`.

Classe `ISupportErrorInfoImpl` fornece uma implementação padrão de `ISupportErrorInfo` e pode ser usada quando somente uma única interface gera erros em um objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#48](../../atl/codesnippet/cpp/isupporterrorinfoimpl-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ISupportErrorInfo`

`ISupportErrorInfoImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="interfacesupportserrorinfo"></a>  ISupportErrorInfoImpl::InterfaceSupportsErrorInfo

Indica se a interface identificada pelo `riid` oferece suporte a [IErrorInfo](/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo) interface.

```
STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
```

### <a name="remarks"></a>Comentários

Ver [ISupportErrorInfo::InterfaceSupportsErrorInfo](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-isupporterrorinfo-interfacesupportserrorinfo) no Windows SDK.

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

[!code-cpp[NVC_ATL_Utilities#134](../../atl/codesnippet/cpp/isupporterrorinfoimpl-class_2.cpp)]

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

[Visão geral da classe](../../atl/atl-class-overview.md)
