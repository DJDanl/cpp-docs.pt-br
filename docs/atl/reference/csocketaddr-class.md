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
ms.openlocfilehash: 9ab0367d5a83096c1bb6e9166ee2b43fe2000ab4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50570450"
---
# <a name="csocketaddr-class"></a>Classe CSocketAddr

Essa classe fornece métodos para converter nomes de host em endereços de host, que dão suporte a formatos IPv4 e IPV6.

## <a name="syntax"></a>Sintaxe

```
class CSocketAddr
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSocketAddr::CSocketAddr](#csocketaddr)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSocketAddr::FindAddr](#findaddr)|Chame esse método para converter o nome de host fornecido para o endereço do host.|
|[CSocketAddr::FindINET4Addr](#findinet4addr)|Chame esse método para converter o nome de host do IPv4 para o endereço do host.|
|[CSocketAddr::FindINET6Addr](#findinet6addr)|Chame esse método para converter o nome de host do IPv6 para o endereço do host.|
|[CSocketAddr::GetAddrInfo](#getaddrinfo)|Chame esse método para retornar um ponteiro para um elemento específico no `addrinfo` lista.|
|[CSocketAddr::GetAddrInfoList](#getaddrinfolist)|Chame esse método para retornar um ponteiro para o `addrinfo` lista.|

## <a name="remarks"></a>Comentários

Essa classe fornece uma abordagem independente para procurar endereços de rede para uso com o Windows sockets funções de API e wrappers de soquete em bibliotecas de versão de IP.

Os membros dessa classe são usados para procurar endereços de rede usam a função de API do Win32 [getaddrinfo](/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo). A versão ANSI ou UNICODE da função é chamada, dependendo se o seu código é compilado para ANSI ou UNICODE.

Esta classe dá suporte a ambos os endereços de rede IPv4 andIPv6.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsocket.h

##  <a name="csocketaddr"></a>  CSocketAddr::CSocketAddr

O construtor.

```
CSocketAddr();
```

### <a name="remarks"></a>Comentários

Cria um novo `CSocketAddr` do objeto e inicializa a lista vinculada, que contém informações de resposta sobre o host.

##  <a name="findaddr"></a>  CSocketAddr::FindAddr

Chame esse método para converter o nome de host fornecido para o endereço do host.

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
O número da porta ou nome do serviço no host.

*nPortNo*<br/>
O número da porta.

*flags*<br/>
0 ou combinação de AI_PASSIVE, AI_CANONNAME ou AI_NUMERICHOST.

*addr_family*<br/>
Família (como PF_INET) de endereços.

*sock_type*<br/>
Tipo de soquete (como SOCK_STREAM).

*ai_proto*<br/>
Protocolo (como IPPROTO_IP ou IPPROTO_IPV6).

### <a name="return-value"></a>Valor de retorno

Retorna zero se o endereço é calculado com êxito. Retorna um código de erro de soquete do Windows diferente de zero em caso de falha. Se for bem-sucedido, o endereço calculado é armazenado em uma lista vinculada que pode ser referenciada usando `CSocketAddr::GetAddrInfoList` e `CSocketAddr::GetAddrInfo`.

### <a name="remarks"></a>Comentários

O parâmetro de nome de host pode estar no formato IPv4 ou IPv6. Esse método chama a função de API do Win32 [getaddrinfo](/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) para realizar a conversão.

##  <a name="findinet4addr"></a>  CSocketAddr::FindINET4Addr

Chame esse método para converter o nome de host do IPv4 para o endereço do host.

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

*flags*<br/>
0 ou combinação de AI_PASSIVE, AI_CANONNAME ou AI_NUMERICHOST.

*sock_type*<br/>
Tipo de soquete (como SOCK_STREAM).

### <a name="return-value"></a>Valor de retorno

Retorna zero se o endereço é calculado com êxito. Retorna um código de erro de soquete do Windows diferente de zero em caso de falha. Se for bem-sucedido, o endereço calculado é armazenado em uma lista vinculada que pode ser referenciada usando `CSocketAddr::GetAddrInfoList` e `CSocketAddr::GetAddrInfo`.

### <a name="remarks"></a>Comentários

Esse método chama a função de API do Win32 [getaddrinfo](/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) para realizar a conversão.

##  <a name="findinet6addr"></a>  CSocketAddr::FindINET6Addr

Chame esse método para converter o nome de host do IPv6 para o endereço do host.

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

*flags*<br/>
0 ou combinação de AI_PASSIVE, AI_CANONNAME ou AI_NUMERICHOST.

*sock_type*<br/>
Tipo de soquete (como SOCK_STREAM).

### <a name="return-value"></a>Valor de retorno

Retorna zero se o endereço é calculado com êxito. Retorna um código de erro de soquete do Windows diferente de zero em caso de falha. Se for bem-sucedido, o endereço calculado é armazenado em uma lista vinculada que pode ser referenciada usando `CSocketAddr::GetAddrInfoList` e `CSocketAddr::GetAddrInfo`.

### <a name="remarks"></a>Comentários

Esse método chama a função de API do Win32 [getaddrinfo](/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) para realizar a conversão.

##  <a name="getaddrinfo"></a>  CSocketAddr::GetAddrInfo

Chame esse método para retornar um ponteiro para um elemento específico no `addrinfo` lista.

```
addrinfo* const GetAddrInfo(int nIndex = 0) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Uma referência a um elemento específico na [addrinfo](https://msdn.microsoft.com/library/windows/desktop/ms737530) lista.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o `addrinfo` estrutura referenciada pelo *nIndex* na lista vinculada que contém informações de resposta sobre o host.

##  <a name="getaddrinfolist"></a>  CSocketAddr::GetAddrInfoList

Chame esse método para retornar um ponteiro para o `addrinfo` lista.

```
addrinfo* const GetAddrInfoList() const;
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma lista vinculada de uma ou mais `addrinfo` estruturas que contém informações de resposta sobre o host. Para obter mais informações, consulte [addrinfo estrutura](https://msdn.microsoft.com/library/windows/desktop/ms737530).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
