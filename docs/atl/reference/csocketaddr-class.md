---
title: Classe CSocketAddr
ms.date: 10/22/2018
f1_keywords:
- CSocketAddr
- ATLSOCKET/ATL::CSocketAddr
- ATLSOCKET/ATL::CSocketAddr::CSocketAddr
- ATLSOCKET/ATL::CSocketAddr::FindAddr
- ATLSOCKET/ATL::CSocketAddr::FindINET4Addr
- ATLSOCKET/ATL::CSocketAddr::FindINET6Addr
- ATLSOCKET/ATL::CSocketAddr::GetAddrInfo
- ATLSOCKET/ATL::CSocketAddr::GetAddrInfoList
helpviewer_keywords:
- CSocketAddr class
ms.assetid: 2fb2d8a7-899e-4a36-a342-cc9f4fcdd68c
ms.openlocfilehash: 66d33d62212389a2b0f318250c1c16a99167c6eb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330688"
---
# <a name="csocketaddr-class"></a>Classe CSocketAddr

Esta classe fornece métodos para converter nomes de host em endereços de host, suportando os formatos IPv4 e IPV6.

## <a name="syntax"></a>Sintaxe

```
class CSocketAddr
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSocketAddr::CSocketAddr](#csocketaddr)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSocketAddr::FindAddr](#findaddr)|Chame este método para converter o nome do host fornecido para o endereço host.|
|[CSocketAddr::FindINET4Addr](#findinet4addr)|Chame este método para converter o nome de host IPv4 para o endereço host.|
|[CSocketAddr::FindINET6Addr](#findinet6addr)|Chame este método para converter o nome de host IPv6 para o endereço host.|
|[CSocketAddr::GetAddrInfo](#getaddrinfo)|Chame este método para retornar um ponteiro `addrinfo` a um elemento específico da lista.|
|[CSocketAddr::GetAddrInfoList](#getaddrinfolist)|Chame este método para retornar `addrinfo` um ponteiro à lista.|

## <a name="remarks"></a>Comentários

Esta classe fornece uma abordagem agnóstica de versão IP para procurar endereços de rede para uso com funções de API de soquetes do Windows e invólucros de soquete em bibliotecas.

Os membros desta classe que são usados para procurar endereços de rede usam a função Win32 API [getaddrinfo](/windows/win32/api/ws2tcpip/nf-ws2tcpip-getaddrinfo). A versão ANSI ou UNICODE da função é chamada dependendo se seu código é compilado para ANSI ou UNICODE.

Esta classe suporta endereços de rede IPv4 e IPv6.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsocket.h

## <a name="csocketaddrcsocketaddr"></a><a name="csocketaddr"></a>CSocketAddr::CSocketAddr

O construtor.

```
CSocketAddr();
```

### <a name="remarks"></a>Comentários

Cria um `CSocketAddr` novo objeto e inicializa a lista vinculada contendo informações de resposta sobre o host.

## <a name="csocketaddrfindaddr"></a><a name="findaddr"></a>CSocketAddr::FindAddr

Chame este método para converter o nome do host fornecido para o endereço host.

```
int FindAddr(
    const TCHAR *szHost,
    const TCHAR *szPortOrServiceName,
    int flags,
    int addr_family,
    int sock_type,
    int ai_proto);

int FindAddr(
    const TCHAR *szHost,
    int nPortNo,
    int flags,
    int addr_family,
    int sock_type,
    int ai_proto);
```

### <a name="parameters"></a>Parâmetros

*szHost*<br/>
O nome do host ou o endereço IP pontilhado.

*szPortOrServiceName*<br/>
O número da porta ou o nome do serviço no host.

*nPortNo*<br/>
O número da porta.

*Sinalizadores*<br/>
0 ou combinação de AI_PASSIVE, AI_CANONNAME ou AI_NUMERICHOST.

*addr_family*<br/>
Abordar família (como PF_INET).

*sock_type*<br/>
Tipo de soquete (como SOCK_STREAM).

*ai_proto*<br/>
Protocolo (como IPPROTO_IP ou IPPROTO_IPV6).

### <a name="return-value"></a>Valor retornado

Retorna zero se o endereço for calculado com sucesso. Retorna um código de erro do Soquete do Windows sem zero em falha. Se for bem-sucedido, o endereço calculado é armazenado `CSocketAddr::GetAddrInfoList` `CSocketAddr::GetAddrInfo`em uma lista vinculada que pode ser referenciada usando e .

### <a name="remarks"></a>Comentários

O parâmetro de nome do host pode estar no formato IPv4 ou IPv6. Este método chama a função API Win32 [getaddrinfo](/windows/win32/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) para executar a conversão.

## <a name="csocketaddrfindinet4addr"></a><a name="findinet4addr"></a>CSocketAddr::FindINET4Addr

Chame este método para converter o nome de host IPv4 para o endereço host.

```
int FindINET4Addr(
    const TCHAR *szHost,
    int nPortNo,
    int flags = 0,
    int sock_type = SOCK_STREAM);
```

### <a name="parameters"></a>Parâmetros

*szHost*<br/>
O nome do host ou o endereço IP pontilhado.

*nPortNo*<br/>
O número da porta.

*Sinalizadores*<br/>
0 ou combinação de AI_PASSIVE, AI_CANONNAME ou AI_NUMERICHOST.

*sock_type*<br/>
Tipo de soquete (como SOCK_STREAM).

### <a name="return-value"></a>Valor retornado

Retorna zero se o endereço for calculado com sucesso. Retorna um código de erro do Soquete do Windows sem zero em falha. Se for bem-sucedido, o endereço calculado é armazenado `CSocketAddr::GetAddrInfoList` `CSocketAddr::GetAddrInfo`em uma lista vinculada que pode ser referenciada usando e .

### <a name="remarks"></a>Comentários

Este método chama a função API Win32 [getaddrinfo](/windows/win32/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) para executar a conversão.

## <a name="csocketaddrfindinet6addr"></a><a name="findinet6addr"></a>CSocketAddr::FindINET6Addr

Chame este método para converter o nome de host IPv6 para o endereço host.

```
int FindINET6Addr(
    const TCHAR *szHost,
    int nPortNo,
    int flags = 0,
    int sock_type = SOCK_STREAM);
```

### <a name="parameters"></a>Parâmetros

*szHost*<br/>
O nome do host ou o endereço IP pontilhado.

*nPortNo*<br/>
O número da porta.

*Sinalizadores*<br/>
0 ou combinação de AI_PASSIVE, AI_CANONNAME ou AI_NUMERICHOST.

*sock_type*<br/>
Tipo de soquete (como SOCK_STREAM).

### <a name="return-value"></a>Valor retornado

Retorna zero se o endereço for calculado com sucesso. Retorna um código de erro do Soquete do Windows sem zero em falha. Se for bem-sucedido, o endereço calculado é armazenado `CSocketAddr::GetAddrInfoList` `CSocketAddr::GetAddrInfo`em uma lista vinculada que pode ser referenciada usando e .

### <a name="remarks"></a>Comentários

Este método chama a função API Win32 [getaddrinfo](/windows/win32/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) para executar a conversão.

## <a name="csocketaddrgetaddrinfo"></a><a name="getaddrinfo"></a>CSocketAddr::GetAddrInfo

Chame este método para retornar um ponteiro `addrinfo` a um elemento específico da lista.

```
addrinfo* const GetAddrInfo(int nIndex = 0) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Uma referência a um elemento específico na lista [addrinfo.](/windows/win32/api/ws2def/ns-ws2def-addrinfow)

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro `addrinfo` à estrutura referenciada pelo *nIndex* na lista vinculada contendo informações de resposta sobre o host.

## <a name="csocketaddrgetaddrinfolist"></a><a name="getaddrinfolist"></a>CSocketAddr::GetAddrInfoList

Chame este método para retornar `addrinfo` um ponteiro à lista.

```
addrinfo* const GetAddrInfoList() const;
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma lista vinculada `addrinfo` de uma ou mais estruturas contendo informações de resposta sobre o host. Para obter mais informações, consulte [a estrutura addrinfo](/windows/win32/api/ws2def/ns-ws2def-addrinfow).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
