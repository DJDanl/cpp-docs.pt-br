---
title: Classe CAsyncSocket | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CAsyncSocket
- AFXSOCK/CAsyncSocket
- AFXSOCK/CAsyncSocket::CAsyncSocket
- AFXSOCK/CAsyncSocket::Accept
- AFXSOCK/CAsyncSocket::AsyncSelect
- AFXSOCK/CAsyncSocket::Attach
- AFXSOCK/CAsyncSocket::Bind
- AFXSOCK/CAsyncSocket::Close
- AFXSOCK/CAsyncSocket::Connect
- AFXSOCK/CAsyncSocket::Create
- AFXSOCK/CAsyncSocket::Detach
- AFXSOCK/CAsyncSocket::FromHandle
- AFXSOCK/CAsyncSocket::GetLastError
- AFXSOCK/CAsyncSocket::GetPeerName
- AFXSOCK/CAsyncSocket::GetPeerNameEx
- AFXSOCK/CAsyncSocket::GetSockName
- AFXSOCK/CAsyncSocket::GetSockNameEx
- AFXSOCK/CAsyncSocket::GetSockOpt
- AFXSOCK/CAsyncSocket::IOCtl
- AFXSOCK/CAsyncSocket::Listen
- AFXSOCK/CAsyncSocket::Receive
- AFXSOCK/CAsyncSocket::ReceiveFrom
- AFXSOCK/CAsyncSocket::ReceiveFromEx
- AFXSOCK/CAsyncSocket::Send
- AFXSOCK/CAsyncSocket::SendTo
- AFXSOCK/CAsyncSocket::SendToEx
- AFXSOCK/CAsyncSocket::SetSockOpt
- AFXSOCK/CAsyncSocket::ShutDown
- AFXSOCK/CASyncSocket::Socket
- AFXSOCK/CAsyncSocket::OnAccept
- AFXSOCK/CAsyncSocket::OnClose
- AFXSOCK/CAsyncSocket::OnConnect
- AFXSOCK/CAsyncSocket::OnOutOfBandData
- AFXSOCK/CAsyncSocket::OnReceive
- AFXSOCK/CAsyncSocket::OnSend
- AFXSOCK/CAsyncSocket::m_hSocket
dev_langs:
- C++
helpviewer_keywords:
- CAsyncSocket [MFC], CAsyncSocket
- CAsyncSocket [MFC], Accept
- CAsyncSocket [MFC], AsyncSelect
- CAsyncSocket [MFC], Attach
- CAsyncSocket [MFC], Bind
- CAsyncSocket [MFC], Close
- CAsyncSocket [MFC], Connect
- CAsyncSocket [MFC], Create
- CAsyncSocket [MFC], Detach
- CAsyncSocket [MFC], FromHandle
- CAsyncSocket [MFC], GetLastError
- CAsyncSocket [MFC], GetPeerName
- CAsyncSocket [MFC], GetPeerNameEx
- CAsyncSocket [MFC], GetSockName
- CAsyncSocket [MFC], GetSockNameEx
- CAsyncSocket [MFC], GetSockOpt
- CAsyncSocket [MFC], IOCtl
- CAsyncSocket [MFC], Listen
- CAsyncSocket [MFC], Receive
- CAsyncSocket [MFC], ReceiveFrom
- CAsyncSocket [MFC], ReceiveFromEx
- CAsyncSocket [MFC], Send
- CAsyncSocket [MFC], SendTo
- CAsyncSocket [MFC], SendToEx
- CAsyncSocket [MFC], SetSockOpt
- CAsyncSocket [MFC], ShutDown
- CASyncSocket [MFC], Socket
- CAsyncSocket [MFC], OnAccept
- CAsyncSocket [MFC], OnClose
- CAsyncSocket [MFC], OnConnect
- CAsyncSocket [MFC], OnOutOfBandData
- CAsyncSocket [MFC], OnReceive
- CAsyncSocket [MFC], OnSend
- CAsyncSocket [MFC], m_hSocket
ms.assetid: cca4d5a1-aa0f-48bd-843e-ef0e2d7fc00b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 562f4920da6eff5af665b8424471ca847de169c7
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50082252"
---
# <a name="casyncsocket-class"></a>Classe CAsyncSocket

Representa um soquete do Windows — um ponto de extremidade de comunicação de rede.

## <a name="syntax"></a>Sintaxe

```
class CAsyncSocket : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncSocket::CAsyncSocket](#casyncsocket)|Constrói um objeto `CAsyncSocket`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncSocket::Accept](#accept)|Aceita uma conexão no soquete.|
|[CAsyncSocket::AsyncSelect](#asyncselect)|Notificação de eventos de solicitações para o soquete.|
|[CAsyncSocket::Attach](#attach)|Anexa um identificador de soquete para um `CAsyncSocket` objeto.|
|[CAsyncSocket::Bind](#bind)|Associa um endereço local com o soquete.|
|[CAsyncSocket::Close](#close)|Fecha o soquete.|
|[CAsyncSocket::Connect](#connect)|Estabelece uma conexão a um soquete de ponto a ponto.|
|[CAsyncSocket::Create](#create)|Cria um soquete.|
|[CAsyncSocket::Detach](#detach)|Desanexa um identificador de soquete de um `CAsyncSocket` objeto.|
|[CAsyncSocket::FromHandle](#fromhandle)|Retorna um ponteiro para um `CAsyncSocket` objeto, dado um identificador de soquete.|
|[CAsyncSocket::GetLastError](#getlasterror)|Obtém o status de erro para a última operação que falhou.|
|[CAsyncSocket::GetPeerName](#getpeername)|Obtém o endereço do soquete de mesmo nível ao qual o soquete está conectado.|
|[CAsyncSocket::GetPeerNameEx](#getpeernameex)|Obtém o endereço do soquete de ponto a ponto para o qual o soquete está conectadas (alças endereços IPv6).|
|[CAsyncSocket::GetSockName](#getsockname)|Obtém o nome local para um soquete.|
|[CAsyncSocket::GetSockNameEx](#getsocknameex)|Obtém o nome local para um soquete (alças endereços IPv6).|
|[CAsyncSocket::GetSockOpt](#getsockopt)|Recupera uma opção de soquete.|
|[CAsyncSocket::IOCtl](#ioctl)|Controla o modo do soquete.|
|[CAsyncSocket::Listen](#listen)|Estabelece um soquete para escutar solicitações de conexão de entrada.|
|[CAsyncSocket::Receive](#receive)|Recebe dados do soquete.|
|[CAsyncSocket::ReceiveFrom](#receivefrom)|Recebe um datagrama e armazena o endereço de origem.|
|[CAsyncSocket::ReceiveFromEx](#receivefromex)|Recebe um datagrama e armazena o endereço de origem (alças endereços IPv6).|
|[CAsyncSocket::Send](#send)|Envia dados para um soquete conectado.|
|[CAsyncSocket::SendTo](#sendto)|Envia dados para um destino específico.|
|[CAsyncSocket::SendToEx](#sendtoex)|Envia dados para um destino específico (alças endereços IPv6).|
|[CAsyncSocket::SetSockOpt](#setsockopt)|Define uma opção de soquete.|
|[CAsyncSocket::ShutDown](#shutdown)|Desabilita `Send` e/ou `Receive` chama no soquete.|
|[CASyncSocket::Socket](#socket)|Aloca um identificador de soquete.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncSocket::OnAccept](#onaccept)|Notifica um soquete de escuta que ele pode aceitar solicitações de conexão pendentes chamando `Accept`.|
|[CAsyncSocket::OnClose](#onclose)|Notifica um soquete que o soquete conectado a ela foi fechada.|
|[CAsyncSocket::OnConnect](#onconnect)|Notifica um soquete de conexão que a tentativa de conexão foi concluída, se com êxito ou com erro.|
|[CAsyncSocket::OnOutOfBandData](#onoutofbanddata)|Notifica um soquete de recebimento que há dados de fora de banda a serem lidos no soquete, normalmente, uma mensagem urgente.|
|[CAsyncSocket::OnReceive](#onreceive)|Notifica um soquete de escuta que há dados a ser recuperado chamando `Receive`.|
|[CAsyncSocket::OnSend](#onsend)|Notifica um soquete que ele pode enviar dados por meio da chamada `Send`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncSocket::operator =](#operator_eq)|Atribui um novo valor para um `CAsyncSocket` objeto.|
|[CAsyncSocket::operator soquete](#operator_socket)|Use este operador para recuperar o identificador de soquete do `CAsyncSocket` objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncSocket::m_hSocket](#m_hsocket)|Indica o identificador de soquete anexado a este `CAsyncSocket` objeto.|

## <a name="remarks"></a>Comentários

Classe `CAsyncSocket` encapsula a API de funções de soquete do Windows, fornecendo uma abstração orientada a objeto para os programadores que desejam usar soquetes do Windows em conjunto com o MFC.

Essa classe se baseia na suposição de que você compreenda as comunicações de rede. Você é responsável por gerenciar o bloqueio, diferenças de ordem de byte, e as conversões entre Unicode e multibyte character definir cadeias de caracteres (MBCS). Se você quiser uma interface mais conveniente que gerencia esses problemas para você, consulte a classe [CSocket](../../mfc/reference/csocket-class.md).

Usar um `CAsyncSocket` de objeto, chame seu construtor, em seguida, chame o [criar](#create) função para criar o identificador de soquete subjacente (tipo `SOCKET`), exceto em soquetes aceitos. Para uma chamada de soquete de servidor do [escutar](#listen) função de membro e para uma chamada de soquete de cliente a [Connect](#connect) função de membro. O soquete de servidor deve chamar o [Accept](#accept) função ao receber uma solicitação de conexão. Usar o restante `CAsyncSocket` funções realizarem as comunicações entre soquetes. Após a conclusão, destrua o `CAsyncSocket` se ele tiver sido criado no heap de objeto; o destruidor chama automaticamente o [fechar](#close) função. O tipo de dados do soquete é descrito no artigo [Windows Sockets: tela de fundo](../../mfc/windows-sockets-background.md).

> [!NOTE]
>  Ao usar soquetes MFC em threads secundários em um aplicativo MFC vinculado estaticamente, você deve chamar `AfxSocketInit` em cada thread que usa soquetes para inicializar as bibliotecas de soquete. Por padrão, `AfxSocketInit` é chamado somente no thread primário.

Para obter mais informações, consulte [Windows Sockets: usando classe CAsyncSocket](../../mfc/windows-sockets-using-class-casyncsocket.md) e artigos relacionados., bem como [API do Windows Sockets 2](/windows/desktop/WinSock/windows-sockets-start-page-2).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CAsyncSocket`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxsock.h

##  <a name="accept"></a>  CAsyncSocket::Accept

Chame essa função de membro para aceitar uma conexão em um soquete.

```
virtual BOOL Accept(
    CAsyncSocket& rConnectedSocket,
    SOCKADDR* lpSockAddr = NULL,
    int* lpSockAddrLen = NULL);
```

### <a name="parameters"></a>Parâmetros

*rConnectedSocket*<br/>
Uma referência identifica um novo soquete que está disponível para a conexão.

*lpSockAddr*<br/>
Um ponteiro para um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que recebe o endereço da conexão de soquete, como conhecido na rede. O formato exato do *lpSockAddr* argumento é determinado pela família de endereço estabelecida quando o soquete foi criado. Se *lpSockAddr* e/ou *lpSockAddrLen* são iguais a NULL, nenhuma informação sobre o endereço remoto do soquete aceito é retornado.

*lpSockAddrLen*<br/>
Um ponteiro para o comprimento do endereço no *lpSockAddr* em bytes. O *lpSockAddrLen* é um parâmetro de resultado de valor: inicialmente, ele deve conter a quantidade de espaço apontado por *lpSockAddr*; no retorno, ele conterá o comprimento real (em bytes) do endereço retornado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT a *lpSockAddrLen* argumento for muito pequeno (menos do que o tamanho de uma [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura).

- A WSAEINPROGRESS que chamar bloqueio soquetes do Windows está em andamento.

- WSAEINVAL `Listen` não foi invocado antes de aceitar.

- WSAEMFILE a fila está vazia após a entrada para aceitar e não há nenhum descritor disponíveis.

- Espaço do buffer WSAENOBUFS não está disponível.

- O descritor WSAENOTSOCK não é um soquete.

- WSAEOPNOTSUPP o soquete referenciado não é um tipo compatível com o serviço orientado a conexão.

- WSAEWOULDBLOCK o soquete está marcado como sem bloqueio e sem conexões estão presentes para serem aceitos.

### <a name="remarks"></a>Comentários

Extrai a primeira conexão na fila de conexões pendentes, cria um novo soquete com as mesmas propriedades que o soquete e anexa-o para essa rotina *rConnectedSocket*. Se não houver conexões pendentes presentes na fila, `Accept` retorna zero e `GetLastError` retornará um erro. O soquete aceito ( *rConnectedSocket)* não pode ser usado para aceitar mais conexões. O soquete original permanece aberto e está ouvindo.

O argumento *lpSockAddr* é um parâmetro de resultado será preenchido com o endereço do soquete está se conectando, como conhecidos para a camada de comunicações. `Accept` é usado com tipos de soquete com base em conexão como SOCK_STREAM.

##  <a name="asyncselect"></a>  CAsyncSocket::AsyncSelect

Chame essa função de membro para solicitar notificação de eventos para um soquete.

```
BOOL AsyncSelect(long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE);
```

### <a name="parameters"></a>Parâmetros

*lEvent*<br/>
Um bitmask que especifica uma combinação de eventos de rede no qual o aplicativo está interessado.

- FD_READ deseja receber notificação de preparação para leitura.

- FD_WRITE deseja receber notificação quando os dados estão disponíveis para serem lidos.

- FD_OOB deseja receber notificação da chegada de dados fora de banda.

- FD_ACCEPT deseja receber notificação de conexões de entrada.

- FD_CONNECT deseja receber notificação de resultados de conexão.

- FD_CLOSE deseja receber notificação quando um soquete foi fechado por um par.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEINVAL indica que um dos parâmetros especificados era inválido.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

### <a name="remarks"></a>Comentários

Essa função é usada para especificar quais funções de notificação de retorno de chamada do MFC serão chamadas para o soquete. `AsyncSelect` define automaticamente esse soquete para o modo sem bloqueio. Para obter mais informações, consulte o artigo [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).

##  <a name="attach"></a>  CAsyncSocket::Attach

Chame essa função de membro para anexar a *hSocket* identificador para um `CAsyncSocket` objeto.

```
BOOL Attach(
    SOCKET hSocket, long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE);
```

### <a name="parameters"></a>Parâmetros

*hSocket*<br/>
Contém um identificador para um soquete.

*lEvent*<br/>
Um bitmask que especifica uma combinação de eventos de rede no qual o aplicativo está interessado.

- FD_READ deseja receber notificação de preparação para leitura.

- FD_WRITE deseja receber notificação quando os dados estão disponíveis para serem lidos.

- FD_OOB deseja receber notificação da chegada de dados fora de banda.

- FD_ACCEPT deseja receber notificação de conexões de entrada.

- FD_CONNECT deseja receber notificação de resultados de conexão.

- FD_CLOSE deseja receber notificação quando um soquete foi fechado por um par.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida.

### <a name="remarks"></a>Comentários

O identificador de soquete é armazenado no objeto de [m_hSocket](#m_hsocket) membro de dados.

##  <a name="bind"></a>  CAsyncSocket::Bind

Chame essa função de membro para associar um endereço local com o soquete.

```
BOOL Bind(
    UINT nSocketPort,
    LPCTSTR lpszSocketAddress = NULL);

BOOL Bind (
    const SOCKADDR* lpSockAddr,
    int nSockAddrLen);
```

### <a name="parameters"></a>Parâmetros

*nSocketPort*<br/>
A porta que identifica o aplicativo de soquete.

*lpszSocketAddress*<br/>
O endereço de rede, um número pontilhado, como "128.56.22.8". Passando o nulo de cadeia de caracteres para esse parâmetro indica o `CAsyncSocket` instância deve escutar para a atividade do cliente em todas as interfaces de rede.

*lpSockAddr*<br/>
Um ponteiro para um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que contém o endereço para atribuir a este soquete.

*nSockAddrLen*<br/>
O comprimento do endereço no *lpSockAddr* em bytes.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEADDRINUSE o endereço especificado já está em uso. (Consulte a opção de soquete sob SO_REUSEADDR [SetSockOpt](#setsockopt).)

- WSAEFAULT a *nSockAddrLen* argumento for muito pequeno (menos do que o tamanho de uma [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura).

- A WSAEINPROGRESS que chamar bloqueio soquetes do Windows está em andamento.

- Não há suporte para WSAEAFNOSUPPORT a família de endereço especificado por essa porta.

- WSAEINVAL o soquete já está associado a um endereço.

- Buffers não WSAENOBUFS suficiente disponível, excesso de conexões.

- O descritor WSAENOTSOCK não é um soquete.

### <a name="remarks"></a>Comentários

Essa rotina é usada antes em um datagrama desconectada ou o soquete de fluxo, subsequentes `Connect` ou `Listen` chamadas. Antes que possa aceitar solicitações de conexão, um soquete de servidor escuta deve selecionar um número de porta e torná-lo conhecido para o Windows Sockets chamando `Bind`. `Bind` estabelece a associação de local (número de endereço/porta de host) do soquete atribuindo um nome local para um soquete sem nome.

##  <a name="casyncsocket"></a>  CAsyncSocket::CAsyncSocket

Constrói um objeto de soquete em branco.

```
CAsyncSocket();
```

### <a name="remarks"></a>Comentários

Depois de construir o objeto, você deve chamar seu `Create` função de membro para criar a estrutura de dados do soquete e associar seu endereço. (No lado do servidor de uma comunicação de Windows Sockets, quando o soquete de escuta cria um soquete para usar o `Accept` chamada, você não chamar `Create` para esse soquete.)

##  <a name="close"></a>  CAsyncSocket::Close

Fecha o soquete.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Essa função libera o descritor de soquete para que ainda mais as referências a ele falhará com o erro WSAENOTSOCK. Se esta for a última referência para o soquete subjacente, as informações de nomes associadas e os dados na fila são descartados. Chamadas de destruidor do objeto de soquete `Close` para você.

Para `CAsyncSocket`, mas não para `CSocket`, a semântica de `Close` são afetadas pelas opções de soquete SO_LINGER e SO_DONTLINGER. Para obter mais informações, consulte a função de membro `GetSockOpt`.

##  <a name="connect"></a>  CAsyncSocket::Connect

Chame essa função de membro para estabelecer uma conexão em um fluxo desconectado ou o soquete de datagrama.

```
BOOL Connect(
    LPCTSTR lpszHostAddress,
    UINT nHostPort);

BOOL Connect(
    const SOCKADDR* lpSockAddr,
    int nSockAddrLen);
```

### <a name="parameters"></a>Parâmetros

*lpszHostAddress*<br/>
O endereço de rede do soquete para o qual este objeto está conectado: um nome de máquina, como "ftp.microsoft.com" ou um número pontilhado, como "128.56.22.8".

*nHostPort*<br/>
A porta que identifica o aplicativo de soquete.

*lpSockAddr*<br/>
Um ponteiro para um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que contém o endereço do soquete conectado.

*nSockAddrLen*<br/>
O comprimento do endereço no *lpSockAddr* em bytes.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Se isso indica um código de erro de WSAEWOULDBLOCK e seu aplicativo está usando os retornos de chamada substituíveis, seu aplicativo receberá um `OnConnect` da mensagem quando a operação de conexão for concluída. Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEADDRINUSE o endereço especificado já está em uso.

- A WSAEINPROGRESS que chamar bloqueio soquetes do Windows está em andamento.

- WSAEADDRNOTAVAIL o endereço especificado não está disponível no computador local.

- WSAEAFNOSUPPORT endereços na família especificada não pode ser usados com este soquete.

- WSAECONNREFUSED a tentativa de conexão foi rejeitada.

- Endereço de destino A WSAEDESTADDRREQ é necessário.

- WSAEFAULT a *nSockAddrLen* argumento estiver incorreto.

- Endereço de host WSAEINVAL inválido.

- WSAEISCONN o soquete já está conectado.

- Não WSAEMFILE mais descritores de arquivo estão disponíveis.

- WSAENETUNREACH a rede não pode ser alcançada através deste host neste momento.

- Espaço do buffer WSAENOBUFS não está disponível. O soquete não pode ser conectado.

- O descritor WSAENOTSOCK não é um soquete.

- WSAETIMEDOUT a tentativa de conexão atingiu o tempo limite sem estabelecer uma conexão.

- WSAEWOULDBLOCK o soquete está marcado como sem bloqueio e a conexão não pode ser concluída imediatamente.

### <a name="remarks"></a>Comentários

Se o soquete não está associado, valores exclusivos são atribuídos à associação de local pelo sistema e o soquete está marcado como associados. Observe que, se o campo de endereço da estrutura de nome é todos os zeros, `Connect` retornará zero. Para obter outras informações de erro, chame o `GetLastError` função de membro.

Para soquetes de fluxo (tipo SOCK_STREAM), uma conexão ativa é iniciada para o host externo. Quando a chamada de soquete é concluída com êxito, o soquete está pronto para enviar/receber dados.

Para um soquete de datagrama (tipo SOCK_DGRAM), um destino padrão for definido, que será usado na subsequentes `Send` e `Receive` chamadas.

##  <a name="create"></a>  CAsyncSocket::Create

Chamar o `Create` a função de membro depois de construir um objeto de soquete para criar o soquete do Windows e anexá-lo.

```
BOOL Create(
    UINT nSocketPort = 0,
    int nSocketType = SOCK_STREAM,
    long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE,
    LPCTSTR lpszSocketAddress = NULL);
```

### <a name="parameters"></a>Parâmetros

*nSocketPort*<br/>
Uma porta conhecida para ser usado com o soquete, ou 0 se desejar que o Windows Sockets para selecionar uma porta.

*nSocketType*<br/>
SOCK_STREAM ou SOCK_DGRAM.

*lEvent*<br/>
Um bitmask que especifica uma combinação de eventos de rede no qual o aplicativo está interessado.

- FD_READ deseja receber notificação de preparação para leitura.

- FD_WRITE deseja receber notificação de preparação para gravação.

- FD_OOB deseja receber notificação da chegada de dados fora de banda.

- FD_ACCEPT deseja receber notificação de conexões de entrada.

- FD_CONNECT deseja receber notificação de conexão concluído.

- FD_CLOSE deseja receber notificação de fechamento de soquete.

*lpszSockAddress*<br/>
Um ponteiro para uma cadeia de caracteres que contém o endereço de rede do soquete conectado, um número pontilhado, como "128.56.22.8". Passando o nulo de cadeia de caracteres para esse parâmetro indica o `CAsyncSocket` instância deve escutar para a atividade do cliente em todas as interfaces de rede.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- Não há suporte para WSAEAFNOSUPPORT a família de endereços especificado.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- Não WSAEMFILE mais descritores de arquivo estão disponíveis.

- Espaço do buffer WSAENOBUFS não está disponível. Não é possível criar o soquete.

- Não há suporte para WSAEPROTONOSUPPORT a porta especificada.

- WSAEPROTOTYPE a porta especificada é do tipo incorreto para esse soquete.

- Não há suporte para o tipo de soquete especificado nessa família de endereços WSAESOCKTNOSUPPORT.

### <a name="remarks"></a>Comentários

`Create` chamadas [soquete](#socket) e se for bem-sucedido, ele chama [associar](#bind) ligar o soquete para o endereço especificado. Há suporte para os seguintes tipos de soquete:

- SOCK_STREAM fornece sequenciado, fluxos de bytes confiável, full duplex com base em conexão. Usa o protocolo TCP (Transmission Control) para a família de endereços da Internet.

- Suporta SOCK_DGRAM datagramas, pacotes sem conexão e não confiáveis de comprimento máximo fixo (normalmente pequeno). Usa o protocolo UDP (User Datagram) para a família de endereços da Internet.

    > [!NOTE]
    >  O `Accept` função de membro usa uma referência a um novo e vazio `CSocket` objeto como seu parâmetro. Você deve construir esse objeto antes de chamar `Accept`. Tenha em mente que, se esse objeto de soquete sai do escopo, fecha a conexão. Não chame `Create` para esse novo objeto de soquete.

> [!IMPORTANT]
> `Create` está **não** thread-safe.  Se você estiver chamando-lo em um ambiente multithread em que ele possa ser invocado simultaneamente por threads diferentes, certifique-se de proteger cada chamada com um mutex ou outro bloqueio de sincronização.

Para obter mais informações sobre os soquetes de datagrama e de fluxo, consulte os artigos [Windows Sockets: tela de fundo](../../mfc/windows-sockets-background.md) e [Windows Sockets: portas e endereços de soquete](../../mfc/windows-sockets-ports-and-socket-addresses.md) e [deAPIdoWindowsSockets2](/windows/desktop/WinSock/windows-sockets-start-page-2).

##  <a name="detach"></a>  CAsyncSocket::Detach

Chame essa função de membro para desanexar o identificador de soquete na *m_hSocket* membro de dados de `CAsyncSocket` do objeto e defina *m_hSocket* como NULL.

```
SOCKET Detach();
```

##  <a name="fromhandle"></a>  CAsyncSocket::FromHandle

Retorna um ponteiro para um `CAsyncSocket` objeto.

```
static CAsyncSocket* PASCAL FromHandle(SOCKET hSocket);
```

### <a name="parameters"></a>Parâmetros

*hSocket*<br/>
Contém um identificador para um soquete.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CAsyncSocket` do objeto ou nulo se não houver nenhum `CAsyncSocket` objeto associado *hSocket*.

### <a name="remarks"></a>Comentários

Quando é fornecido um identificador de soquete, se um `CAsyncSocket` objeto não está anexado ao identificador, a função membro retornará NULL.

##  <a name="getlasterror"></a>  CAsyncSocket::GetLastError

Chame essa função de membro para obter o status de erro para a última operação que falhou.

```
static int PASCAL GetLastError();
```

### <a name="return-value"></a>Valor de retorno

O valor de retorno indica o código de erro para a rotina de API do Windows Sockets última executada por esse thread.

### <a name="remarks"></a>Comentários

Quando uma função de membro particular indica que ocorreu um erro, `GetLastError` deve ser chamado para recuperar o código de erro apropriado. Consulte as descrições de função de membro individual para obter uma lista dos códigos de erro aplicável.

Para obter mais informações sobre os códigos de erro, consulte [API do Windows Sockets 2](/windows/desktop/WinSock/windows-sockets-start-page-2).

##  <a name="getpeername"></a>  CAsyncSocket::GetPeerName

Chame essa função de membro para obter o endereço do soquete par ao qual esse soquete está conectado.

```
BOOL GetPeerName(
    CString& rPeerAddress,
    UINT& rPeerPort);

BOOL GetPeerName(
    SOCKADDR* lpSockAddr,
    int* lpSockAddrLen);
```

### <a name="parameters"></a>Parâmetros

*rPeerAddress*<br/>
Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.

*rPeerPort*<br/>
Referência a um UINT que armazena uma porta.

*lpSockAddr*<br/>
Um ponteiro para o [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que recebe o nome do soquete de ponto a ponto.

*lpSockAddrLen*<br/>
Um ponteiro para o comprimento do endereço no *lpSockAddr* em bytes. No retorno, o *lpSockAddrLen* argumento contém o tamanho real do *lpSockAddr* retornados em bytes.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT a *lpSockAddrLen* argumento não é grande o suficiente.

- A WSAEINPROGRESS que chamar bloqueio soquetes do Windows está em andamento.

- WSAENOTCONN o soquete não está conectado.

- O descritor WSAENOTSOCK não é um soquete.

### <a name="remarks"></a>Comentários

Para lidar com endereços IPv6, use [CAsyncSocket::GetPeerNameEx](#getpeernameex).

##  <a name="getpeernameex"></a>  CAsyncSocket::GetPeerNameEx

Chame essa função de membro para obter o endereço do soquete de mesmo nível ao qual esse soquete está conectadas (alças endereços IPv6).

```
BOOL GetPeerNameEx(
    CString& rPeerAddress,
    UINT& rPeerPort);
```

### <a name="parameters"></a>Parâmetros

*rPeerAddress*<br/>
Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.

*rPeerPort*<br/>
Referência a um UINT que armazena uma porta.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT a *lpSockAddrLen* argumento não é grande o suficiente.

- A WSAEINPROGRESS que chamar bloqueio soquetes do Windows está em andamento.

- WSAENOTCONN o soquete não está conectado.

- O descritor WSAENOTSOCK não é um soquete.

### <a name="remarks"></a>Comentários

Essa função é igual a [CAsyncSocket::GetPeerName](#getpeername) protocolos mais antigos, bem como de endereços, exceto que ele lida com IPv6.

##  <a name="getsockname"></a>  CAsyncSocket::GetSockName

Chame essa função de membro para obter o nome do local para um soquete.

```
BOOL GetSockName(
    CString& rSocketAddress,
    UINT& rSocketPort);

BOOL GetSockName(
    SOCKADDR* lpSockAddr,
    int* lpSockAddrLen);
```

### <a name="parameters"></a>Parâmetros

*rSocketAddress*<br/>
Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.

*rSocketPort*<br/>
Referência a um UINT que armazena uma porta.

*lpSockAddr*<br/>
Um ponteiro para um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que recebe o endereço do soquete.

*lpSockAddrLen*<br/>
Um ponteiro para o comprimento do endereço no *lpSockAddr* em bytes.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT a *lpSockAddrLen* argumento não é grande o suficiente.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- O descritor WSAENOTSOCK não é um soquete.

- WSAEINVAL o soquete não foi associado a um endereço com `Bind`.

### <a name="remarks"></a>Comentários

Essa chamada é especialmente útil quando um `Connect` chamada foi feita sem fazer uma `Bind` primeiro; esta chamada fornece o único meio pelo qual você pode determinar a associação de local que foi definida pelo sistema.

Para lidar com endereços IPv6, use [CAsyncSocket::GetSockNameEx](#getsocknameex)

##  <a name="getsocknameex"></a>  CAsyncSocket::GetSockNameEx

Chame essa função de membro para obter o nome do local para um soquete (alças endereços IPv6).

```
BOOL GetSockNameEx(
    CString& rSocketAddress,
    UINT& rSocketPort);
```

### <a name="parameters"></a>Parâmetros

*rSocketAddress*<br/>
Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.

*rSocketPort*<br/>
Referência a um UINT que armazena uma porta.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT a *lpSockAddrLen* argumento não é grande o suficiente.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- O descritor WSAENOTSOCK não é um soquete.

- WSAEINVAL o soquete não foi associado a um endereço com `Bind`.

### <a name="remarks"></a>Comentários

Essa chamada é o mesmo que [CAsyncSocket::GetSockName](#getsockname) protocolos mais antigos, bem como de endereços, exceto que ele lida com IPv6.

Essa chamada é especialmente útil quando um `Connect` chamada foi feita sem fazer uma `Bind` primeiro; esta chamada fornece o único meio pelo qual você pode determinar a associação de local que foi definida pelo sistema.

##  <a name="getsockopt"></a>  CAsyncSocket::GetSockOpt

Chame essa função de membro para recuperar uma opção de soquete.

```
BOOL GetSockOpt(
    int nOptionName,
    void* lpOptionValue,
    int* lpOptionLen,
    int nLevel = SOL_SOCKET);
```

### <a name="parameters"></a>Parâmetros

*nOptionName*<br/>
A opção de soquete para o qual o valor deve ser recuperado.

*lpOptionValue*<br/>
Um ponteiro para o buffer no qual o valor da opção solicitada deve ser retornado. O valor associado com a opção selecionada é retornado no buffer *lpOptionValue*. O inteiro apontado por *lpOptionLen* originalmente deve conter o tamanho desse buffer em bytes; e no retorno, ele será definido como o tamanho do valor retornado. Para SO_LINGER, esse será o tamanho de um `LINGER` estrutura; para todas as outras opções, ele será o tamanho de um BOOL ou um **int**, dependendo da opção. Consulte a lista de opções e seus tamanhos na seção comentários.

*lpOptionLen*<br/>
Um ponteiro para o tamanho do *lpOptionValue* buffer em bytes.

*nLevel*<br/>
O nível no qual a opção estiver definida; os níveis com suporte somente são SOL_SOCKET e IPPROTO_TCP.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Se uma opção nunca foi definida com `SetSockOpt`, em seguida, `GetSockOpt` retorna o valor padrão para a opção. Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT a *lpOptionLen* argumento era inválido.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- A opção de WSAENOPROTOOPT é desconhecido ou sem suporte. Em particular, SO_BROADCAST não tem suporte em soquetes do tipo SOCK_STREAM, enquanto SO_ACCEPTCONN, SO_DONTLINGER, SO_KEEPALIVE, SO_LINGER e SO_OOBINLINE não têm suporte em soquetes do tipo SOCK_DGRAM.

- O descritor WSAENOTSOCK não é um soquete.

### <a name="remarks"></a>Comentários

`GetSockOpt` recupera o valor atual para uma opção de soquete associada com um soquete de qualquer tipo, em qualquer estado e armazena o resultado em *lpOptionValue*. Opções afetam as operações de soquete, como o roteamento de pacotes, transferência de dados fora de banda e assim por diante.

As opções a seguir têm suporte para `GetSockOpt`. O tipo identifica o tipo de dados endereçados pela *lpOptionValue*. A opção de TCP_NODELAY usa IPPROTO_TCP nível; todas as outras opções usam nível SOL_SOCKET.

|Valor|Tipo|Significado|
|-----------|----------|-------------|
|SO_ACCEPTCONN|BOOL|Soquete está escutando.|
|SO_BROADCAST|BOOL|Soquete é configurado para a transmissão de mensagens de difusão.|
|SO_DEBUG|BOOL|A depuração habilitada.|
|SO_DONTLINGER|BOOL|Se for true, a opção de SO_LINGER está desabilitada.|
|SO_DONTROUTE|BOOL|Roteamento está desabilitado.|
|SO_ERROR|**int**|Recuperar o status de erro e limpe.|
|SO_KEEPALIVE|BOOL|O Keep-Alive está sendo enviado.|
|SO_LINGER|`struct LINGER`|Retorna as opções atuais de remanescente.|
|SO_OOBINLINE|BOOL|Dados fora de banda está sendo recebidos no fluxo de dados normal.|
|SO_RCVBUF|int|Tamanho do buffer para recebe.|
|SO_REUSEADDR|BOOL|O soquete pode ser associado a um endereço que já está em uso.|
|SO_SNDBUF|**int**|Tamanho do buffer para envia.|
|SO_TYPE|**int**|O tipo de soquete (por exemplo, SOCK_STREAM).|
|TCP_NODELAY|BOOL|Desabilita o algoritmo Nagle para união de envio.|

Opções de Berkeley Software Distribution (BSD) não tem suportadas para `GetSockOpt` são:

|Valor|Tipo|Significado|
|-----------|----------|-------------|
|SO_RCVLOWAT|**int**|Receba a marca d'água inferior.|
|SO_RCVTIMEO|**int**|Tempo limite de recebimento.|
|SO_SNDLOWAT|**int**|Envie marca d'água inferior.|
|SO_SNDTIMEO|**int**|Tempo limite de envio.|
|IP_OPTIONS||Obter opções de cabeçalho IP.|
|TCP_MAXSEG|**int**|Obter o tamanho máximo de segmento TCP.|

Chamando `GetSockOpt` com uma opção sem suporte resultará em um código de erro de WSAENOPROTOOPT seja retornado do `GetLastError`.

##  <a name="ioctl"></a>  CAsyncSocket::IOCtl

Chame essa função de membro para controlar o modo de um soquete.

```
BOOL IOCtl(
    long lCommand,
    DWORD* lpArgument);
```

### <a name="parameters"></a>Parâmetros

*lCommand*<br/>
O comando para executar no soquete.

*lpArgument*<br/>
Um ponteiro para um parâmetro para *lCommand*.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEINVAL *lCommand* não é um comando válido, ou *lpArgument* não é um parâmetro aceitável para *lCommand*, ou o comando não é aplicável ao tipo de soquete fornecido .

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- O descritor WSAENOTSOCK não é um soquete.

### <a name="remarks"></a>Comentários

Essa rotina pode ser usada em qualquer soquete em qualquer estado. Ele é usado para obter ou recuperar parâmetros de operação associados ao soquete, independente do subsistema de protocolo e comunicações. Há suporte para os seguintes comandos:

- FIONBIO ativar ou desativar o modo sem bloqueio no soquete. O *lpArgument* parâmetro aponta para um `DWORD`, que é diferente de zero se o modo sem bloqueio deve ser habilitada e zero, se ele deverá estar desabilitado. Se `AsyncSelect` tiver sido emitida em um soquete, em seguida, qualquer tentativa de usar `IOCtl` para definir o soquete de volta para o modo de bloqueio falhará com WSAEINVAL. Para definir o soquete para o modo de bloqueio e evitar que o erro WSAEINVAL, um aplicativo necessário desabilitar primeiramente `AsyncSelect` chamando `AsyncSelect` com o *lEvent* parâmetro igual a 0, em seguida, chame `IOCtl`.

- FIONREAD determinam o número máximo de bytes que podem ser lidos com um `Receive` chamar desse soquete. O *lpArgument* parâmetro aponta para um `DWORD` na qual `IOCtl` armazena o resultado. Se o soquete é do tipo SOCK_STREAM, FIONREAD retorna a quantidade total de dados que podem ser lido em um único `Receive`; isso é normalmente o mesmo que a quantidade total de dados na fila no soquete. Se o soquete é do tipo SOCK_DGRAM, FIONREAD retorna que o tamanho do datagrama primeiro na fila no soquete.

- SIOCATMARK determinar se todos os dados fora de banda foi lido. Isso se aplica somente a um soquete SOCK_STREAM que foi configurado para recepção na linha de todos os dados fora de banda (SO_OOBINLINE) de tipo. Se nenhum dado de out-of-band está esperando para ser lido, a operação retorna não zero. Caso contrário, ele retorna 0 e a próxima `Receive` ou `ReceiveFrom` executada no soquete irá recuperar alguns ou todos os dados que precede a "marca"; o aplicativo deve usar a operação SIOCATMARK para determinar se restar algum dado. Se não houver nenhum dado normal que precede os dados (out-of-band) "urgentes", ele será recebido na ordem. (Observe que um `Receive` ou `ReceiveFrom` nunca irá misturar dados out-of-band e normais na mesma chamada.) O *lpArgument* parâmetro aponta para um `DWORD` na qual `IOCtl` armazena o resultado.

Essa função é um subconjunto de `ioctl()` como utilizado em soquetes Berkeley. Em particular, não há nenhum comando que é equivalente a FIOASYNC, enquanto SIOCATMARK é o comando apenas de nível de soquete que tem suporte.

##  <a name="listen"></a>  CAsyncSocket::Listen

Chame essa função de membro para escutar solicitações de conexão de entrada.

```
BOOL Listen(int nConnectionBacklog = 5);
```

### <a name="parameters"></a>Parâmetros

*nConnectionBacklog*<br/>
O comprimento máximo que pode alcançar a fila de conexões pendentes. O intervalo válido é de 1 a 5.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEADDRINUSE uma tentativa foi feita para escutar em um endereço em uso.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- WSAEINVAL o soquete não foi associado com `Bind` ou já está conectado.

- WSAEISCONN o soquete já está conectado.

- Não WSAEMFILE mais descritores de arquivo estão disponíveis.

- Espaço do buffer WSAENOBUFS não está disponível.

- O descritor WSAENOTSOCK não é um soquete.

- WSAEOPNOTSUPP o soquete referenciado não é de um tipo compatível com o `Listen` operação.

### <a name="remarks"></a>Comentários

Para aceitar conexões, o soquete é criado com `Create`, uma lista de pendências para conexões de entrada é especificada com `Listen`, e, em seguida, as conexões são aceitos com `Accept`. `Listen` aplica-se somente para soquetes que dão suporte a conexões, ou seja, aquelas do tipo SOCK_STREAM. O soquete será colocado no modo "passivo" em que as conexões de entrada são reconhecidas e na fila pendentes aceitação pelo processo.

Esta função geralmente é usada por servidores (ou qualquer aplicativo que deseja aceitar conexões) que pode ter mais de uma solicitação de conexão por vez: se chegar uma solicitação de conexão com a fila cheia, o cliente receberá um erro com uma indicação de WSAECONNREFUSED.

`Listen` tenta continuam a funcionar racionalmente quando não houver nenhuma porta disponível (descritores). Ele aceitará conexões até que a fila é esvaziada. Se as portas se tornam disponíveis, uma chamada posterior a `Listen` ou `Accept` será reabastecer a fila para a atual ou mais recente "lista de pendências," se possível e retomar a escuta de conexões de entrada.

##  <a name="m_hsocket"></a>  CAsyncSocket::m_hSocket

Contém o identificador de soquete para o soquete encapsulado por esse `CAsyncSocket` objeto.

```
SOCKET m_hSocket;
```

##  <a name="onaccept"></a>  CAsyncSocket::OnAccept

Chamado pelo framework para notificar um soquete de escuta que ele pode aceitar solicitações de conexão pendentes chamando o [Accept](#accept) função de membro.

```
virtual void OnAccept(int nErrorCode);
```

### <a name="parameters"></a>Parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os códigos de erro a seguir se aplica a `OnAccept` função de membro:

- **0** a função foi executada com êxito.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).

##  <a name="onclose"></a>  CAsyncSocket::OnClose

Chamado pelo framework para notificar o soquete que o soquete conectado é fechado pelo seu processo.

```
virtual void OnClose(int nErrorCode);
```

### <a name="parameters"></a>Parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam ao `OnClose` função de membro:

- **0** a função foi executada com êxito.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAECONNRESET a conexão foi redefinida pelo lado remoto.

- WSAECONNABORTED a conexão foi anulada devido a tempo limite ou outra falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).

##  <a name="onconnect"></a>  CAsyncSocket::OnConnect

Chamado pelo framework para notificar o soquete está se conectando a sua tentativa de conexão for concluída, seja com êxito ou erro.

```
virtual void OnConnect(int nErrorCode);
```

### <a name="parameters"></a>Parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam ao `OnConnect` função de membro:

- **0** a função foi executada com êxito.

- WSAEADDRINUSE o endereço especificado já está em uso.

- WSAEADDRNOTAVAIL o endereço especificado não está disponível no computador local.

- WSAEAFNOSUPPORT endereços na família especificada não pode ser usados com este soquete.

- WSAECONNREFUSED a tentativa de conexão foi rejeitada de modo forçado.

- Endereço de destino A WSAEDESTADDRREQ é necessário.

- WSAEFAULT a *lpSockAddrLen* argumento estiver incorreto.

- WSAEINVAL o soquete já está associado a um endereço.

- WSAEISCONN o soquete já está conectado.

- Não WSAEMFILE mais descritores de arquivo estão disponíveis.

- WSAENETUNREACH a rede não pode ser alcançada através deste host neste momento.

- Espaço do buffer WSAENOBUFS não está disponível. O soquete não pode ser conectado.

- WSAENOTCONN o soquete não está conectado.

- WSAENOTSOCK o descritor é um arquivo, não um soquete.

- WSAETIMEDOUT a tentativa de conexão atingiu o tempo limite sem estabelecer uma conexão.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Na [CSocket](../../mfc/reference/csocket-class.md), o `OnConnect` nunca é chamada de função de notificação. Para conexões, você simplesmente chamar `Connect`, que retornará quando a conexão for concluída (com êxito ou erro). Como as notificações de conexão são tratadas é um detalhe de implementação do MFC.

Para obter mais informações, consulte [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAsyncSocket#1](../../mfc/reference/codesnippet/cpp/casyncsocket-class_1.cpp)]

##  <a name="onoutofbanddata"></a>  CAsyncSocket::OnOutOfBandData

Chamado pelo framework para notificar o soquete de recebimento que o envio de soquete tem dados out-of-band para enviar.

```
virtual void OnOutOfBandData(int nErrorCode);
```

### <a name="parameters"></a>Parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam ao `OnOutOfBandData` função de membro:

- **0** a função foi executada com êxito.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

### <a name="remarks"></a>Comentários

Dados fora de banda são um canal logicamente independente que está associado a cada par de soquetes conectados do tipo SOCK_STREAM. O canal geralmente é usado para enviar dados urgentes.

MFC é compatível com os dados de fora da banda, mas os usuários da classe `CAsyncSocket` desaconselhável de usá-lo. A maneira mais fácil é criar um soquete de segundo para passar esses dados. Para obter mais informações sobre dados out-of-band, consulte [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).

##  <a name="onreceive"></a>  CAsyncSocket::OnReceive

Chamado pelo framework para notificar o soquete que há dados no buffer que pode ser recuperado chamando o `Receive` função de membro.

```
virtual void OnReceive(int nErrorCode);
```

### <a name="parameters"></a>Parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam ao `OnReceive` função de membro:

- **0** a função foi executada com êxito.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAsyncSocket#2](../../mfc/reference/codesnippet/cpp/casyncsocket-class_2.cpp)]

##  <a name="onsend"></a>  CAsyncSocket::OnSend

Chamado pelo framework para notificar o soquete que agora ele pode enviar dados por meio da chamada a `Send` função de membro.

```
virtual void OnSend(int nErrorCode);
```

### <a name="parameters"></a>Parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam ao `OnSend` função de membro:

- **0** a função foi executada com êxito.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAsyncSocket#3](../../mfc/reference/codesnippet/cpp/casyncsocket-class_3.cpp)]

##  <a name="operator_eq"></a>  CAsyncSocket::operator =

Atribui um novo valor para um `CAsyncSocket` objeto.

```
void operator=(const CAsyncSocket& rSrc);
```

### <a name="parameters"></a>Parâmetros

*rSrc*<br/>
Uma referência a um existente `CAsyncSocket` objeto.

### <a name="remarks"></a>Comentários

Chame essa função para copiar um existente `CAsyncSocket` objeto para outro `CAsyncSocket` objeto.

##  <a name="operator_socket"></a>  CAsyncSocket::operator soquete

Use este operador para recuperar o identificador de soquete do `CAsyncSocket` objeto.

```
operator SOCKET() const;
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, o identificador do objeto de soquete; Caso contrário, nulo.

### <a name="remarks"></a>Comentários

Você pode usar o identificador para chamar diretamente as APIs do Windows.

##  <a name="receive"></a>  CAsyncSocket::Receive

Chame essa função de membro para receber dados de um soquete.

```
virtual int Receive(
    void* lpBuf,
    int nBufLen,
    int nFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Um buffer para os dados de entrada.

*nBufLen*<br/>
O comprimento da *lpBuf* em bytes.

*nFlags*<br/>
Especifica a maneira na qual a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e o *nFlags* parâmetro. O último é construído pela combinação de qualquer um dos seguintes valores com o C++ **ou** operador:

- MSG_PEEK inspecionar os dados de entrada. Os dados são copiados no buffer, mas não são removidos da fila de entrada.

- Dados de out-of-band MSG_OOB processo.

### <a name="return-value"></a>Valor de retorno

Se nenhum erro ocorrer, `Receive` retorna o número de bytes recebidos. Se a conexão foi fechada, ela retornará 0. Caso contrário, um valor de SOCKET_ERROR é retornado e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAENOTCONN o soquete não está conectado.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- O descritor WSAENOTSOCK não é um soquete.

- WSAEOPNOTSUPP MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- Foi desligado do soquete WSAESHUTDOWN; não é possível chamar `Receive` em um soquete após `ShutDown` foi invocado com *nHow* definido como 0 ou 2.

- WSAEWOULDBLOCK o soquete está marcado como sem bloqueio e o `Receive` operação seria bloqueada.

- WSAEMSGSIZE o datagrama era muito grande para caber no buffer especificado e foi truncado.

- WSAEINVAL o soquete não foi associado com `Bind`.

- WSAECONNABORTED o circuito virtual foi anulada devido a tempo limite ou outra falha.

- WSAECONNRESET o circuito virtual foi redefinido pelo lado remoto.

### <a name="remarks"></a>Comentários

Essa função é usada para fluxo conectado ou soquetes de datagrama e é usada para ler dados de entrada.

Soquetes do tipo SOCK_STREAM, tanta informação quanto está disponível até o tamanho do buffer fornecido será retornada. Se o soquete foi configurado para recepção na linha de dados fora de banda (opção de soquete SO_OOBINLINE) e dados fora de banda forem lidos, apenas os dados fora de banda serão retornados. O aplicativo pode usar o `IOCtlSIOCATMARK` opção ou [OnOutOfBandData](#onoutofbanddata) para determinar se todos os dados mais out-of-band permanecem para ser lido.

Para soquetes de datagrama, os dados são extraídos do datagrama enfileiradas primeiro, até o tamanho do buffer fornecido. Se o datagrama é maior do que o buffer fornecido, o buffer é preenchido com a primeira parte do datagrama, o excesso de dados for perdido, e `Receive` retorna um valor de SOCKET_ERROR com o código de erro definido como WSAEMSGSIZE. Se nenhum dado de entrada está disponível no soquete, um valor de SOCKET_ERROR será retornado com o código de erro definido como WSAEWOULDBLOCK. O [OnReceive](#onreceive) função de retorno de chamada pode ser usada para determinar quando mais dados chegam.

Se o soquete é do tipo SOCK_STREAM e o lado remoto encerrou a conexão normalmente, um `Receive` será concluído imediatamente com 0 bytes recebidos. Se a conexão foi redefinida, um `Receive` falhará com o erro WSAECONNRESET.

`Receive` deve ser chamado apenas uma vez para cada vez [CAsyncSocket::OnReceive](#onreceive) é chamado.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CAsyncSocket::OnReceive](#onreceive).

##  <a name="receivefrom"></a>  CAsyncSocket::ReceiveFrom

Chame essa função de membro para receber um datagrama e armazenar o endereço de origem na [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura ou na *rSocketAddress*.

```
int ReceiveFrom(
    void* lpBuf,
    int nBufLen,
    CString& rSocketAddress,
    UINT& rSocketPort,
    int nFlags = 0);

int ReceiveFrom(
    void* lpBuf,
    int nBufLen,
    SOCKADDR* lpSockAddr,
    int* lpSockAddrLen,
    int nFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Um buffer para os dados de entrada.

*nBufLen*<br/>
O comprimento da *lpBuf* em bytes.

*rSocketAddress*<br/>
Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.

*rSocketPort*<br/>
Referência a um UINT que armazena uma porta.

*lpSockAddr*<br/>
Um ponteiro para um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que contém o endereço de origem após o retorno.

*lpSockAddrLen*<br/>
Um ponteiro para o comprimento do endereço de origem no *lpSockAddr* em bytes.

*nFlags*<br/>
Especifica a maneira na qual a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e o *nFlags* parâmetro. O último é construído pela combinação de qualquer um dos seguintes valores com o C++ **ou** operador:

- MSG_PEEK inspecionar os dados de entrada. Os dados são copiados no buffer, mas não são removidos da fila de entrada.

- Dados de out-of-band MSG_OOB processo.

### <a name="return-value"></a>Valor de retorno

Se nenhum erro ocorrer, `ReceiveFrom` retorna o número de bytes recebidos. Se a conexão foi fechada, ela retornará 0. Caso contrário, um valor de SOCKET_ERROR é retornado e um código de erro específico pode ser recuperado chamando `GetLastError`. Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT a *lpSockAddrLen* argumento era inválido: o *lpSockAddr* buffer era muito pequeno para acomodar o endereço de ponto a ponto.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- WSAEINVAL o soquete não foi associado com `Bind`.

- WSAENOTCONN o soquete não está conectado (SOCK_STREAM).

- O descritor WSAENOTSOCK não é um soquete.

- WSAEOPNOTSUPP MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- Foi desligado do soquete WSAESHUTDOWN; não é possível chamar `ReceiveFrom` em um soquete após `ShutDown` foi invocado com *nHow* definido como 0 ou 2.

- WSAEWOULDBLOCK o soquete está marcado como sem bloqueio e o `ReceiveFrom` operação seria bloqueada.

- WSAEMSGSIZE o datagrama era muito grande para caber no buffer especificado e foi truncado.

- WSAECONNABORTED o circuito virtual foi anulada devido a tempo limite ou outra falha.

- WSAECONNRESET o circuito virtual foi redefinido pelo lado remoto.

### <a name="remarks"></a>Comentários

Essa função é usada para ler dados de entrada em um soquete (possivelmente conectado) e capture o endereço do qual os dados foram enviados.

Para lidar com endereços IPv6, use [CAsyncSocket::ReceiveFromEx](#receivefromex).

Soquetes do tipo SOCK_STREAM, tanta informação quanto está disponível até o tamanho do buffer fornecido será retornada. Se o soquete foi configurado para recepção na linha de dados fora de banda (opção de soquete SO_OOBINLINE) e dados fora de banda forem lidos, apenas os dados fora de banda serão retornados. O aplicativo pode usar o `IOCtlSIOCATMARK` opção ou `OnOutOfBandData` para determinar se todos os dados mais out-of-band permanecem para ser lido. O *lpSockAddr* e *lpSockAddrLen* parâmetros serão ignorados para SOCK_STREAM soquetes.

Para soquetes de datagrama, os dados são extraídos do datagrama enfileiradas primeiro, até o tamanho do buffer fornecido. Se o datagrama é maior do que o buffer fornecido, o buffer é preenchido com a primeira parte da mensagem, o excesso de dados for perdido, e `ReceiveFrom` retorna um valor de SOCKET_ERROR com o código de erro definido como WSAEMSGSIZE.

Se *lpSockAddr* for diferente de zero e o soquete é do tipo SOCK_DGRAM, o endereço de rede do soquete que enviou os dados é copiado para os respectivos [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura. O valor apontado por *lpSockAddrLen* é inicializado para o tamanho desta estrutura e é modificado no retorno para indicar o tamanho real do endereço armazenado ali. Se nenhum dado de entrada está disponível no soquete, o `ReceiveFrom` chamada aguarda os dados chegarem a menos que seja o soquete sem bloqueio. Nesse caso, um valor de SOCKET_ERROR é retornado com o código de erro definido como WSAEWOULDBLOCK. O `OnReceive` retorno de chamada pode ser usado para determinar quando mais dados chegam.

Se o soquete é do tipo SOCK_STREAM e o lado remoto encerrou a conexão normalmente, um `ReceiveFrom` será concluído imediatamente com 0 bytes recebidos.

##  <a name="receivefromex"></a>  CAsyncSocket::ReceiveFromEx

Chame essa função de membro para receber um datagrama e armazenar o endereço de origem na [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura ou na *rSocketAddress* (lida com endereços IPv6).

```
int ReceiveFromEx(
    void* lpBuf,
    int nBufLen,
    CString& rSocketAddress,
    UINT& rSocketPort,
    int nFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Um buffer para os dados de entrada.

*nBufLen*<br/>
O comprimento da *lpBuf* em bytes.

*rSocketAddress*<br/>
Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.

*rSocketPort*<br/>
Referência a um UINT que armazena uma porta.

*nFlags*<br/>
Especifica a maneira na qual a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e o *nFlags* parâmetro. O último é construído pela combinação de qualquer um dos seguintes valores com o C++ **ou** operador:

- MSG_PEEK inspecionar os dados de entrada. Os dados são copiados no buffer, mas não são removidos da fila de entrada.

- Dados de out-of-band MSG_OOB processo.

### <a name="return-value"></a>Valor de retorno

Se nenhum erro ocorrer, `ReceiveFromEx` retorna o número de bytes recebidos. Se a conexão foi fechada, ela retornará 0. Caso contrário, um valor de SOCKET_ERROR é retornado e um código de erro específico pode ser recuperado chamando `GetLastError`. Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT a *lpSockAddrLen* argumento era inválido: o *lpSockAddr* buffer era muito pequeno para acomodar o endereço de ponto a ponto.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- WSAEINVAL o soquete não foi associado com `Bind`.

- WSAENOTCONN o soquete não está conectado (SOCK_STREAM).

- O descritor WSAENOTSOCK não é um soquete.

- WSAEOPNOTSUPP MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- Foi desligado do soquete WSAESHUTDOWN; não é possível chamar `ReceiveFromEx` em um soquete após `ShutDown` foi invocado com *nHow* definido como 0 ou 2.

- WSAEWOULDBLOCK o soquete está marcado como sem bloqueio e o `ReceiveFromEx` operação seria bloqueada.

- WSAEMSGSIZE o datagrama era muito grande para caber no buffer especificado e foi truncado.

- WSAECONNABORTED o circuito virtual foi anulada devido a tempo limite ou outra falha.

- WSAECONNRESET o circuito virtual foi redefinido pelo lado remoto.

### <a name="remarks"></a>Comentários

Essa função é usada para ler dados de entrada em um soquete (possivelmente conectado) e capture o endereço do qual os dados foram enviados.

Essa função é igual a [CAsyncSocket::ReceiveFrom](#receivefrom) protocolos mais antigos, bem como de endereços, exceto que ele lida com IPv6.

Soquetes do tipo SOCK_STREAM, tanta informação quanto está disponível até o tamanho do buffer fornecido será retornada. Se o soquete foi configurado para recepção na linha de dados fora de banda (opção de soquete SO_OOBINLINE) e dados fora de banda forem lidos, apenas os dados fora de banda serão retornados. O aplicativo pode usar o `IOCtlSIOCATMARK` opção ou `OnOutOfBandData` para determinar se todos os dados mais out-of-band permanecem para ser lido. O *lpSockAddr* e *lpSockAddrLen* parâmetros serão ignorados para SOCK_STREAM soquetes.

Para soquetes de datagrama, os dados são extraídos do datagrama enfileiradas primeiro, até o tamanho do buffer fornecido. Se o datagrama é maior do que o buffer fornecido, o buffer é preenchido com a primeira parte da mensagem, o excesso de dados for perdido, e `ReceiveFromEx` retorna um valor de SOCKET_ERROR com o código de erro definido como WSAEMSGSIZE.

Se *lpSockAddr* for diferente de zero e o soquete é do tipo SOCK_DGRAM, o endereço de rede do soquete que enviou os dados é copiado para os respectivos [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura. O valor apontado por *lpSockAddrLen* é inicializado para o tamanho desta estrutura e é modificado no retorno para indicar o tamanho real do endereço armazenado ali. Se nenhum dado de entrada está disponível no soquete, o `ReceiveFromEx` chamada aguarda os dados chegarem a menos que seja o soquete sem bloqueio. Nesse caso, um valor de SOCKET_ERROR é retornado com o código de erro definido como WSAEWOULDBLOCK. O `OnReceive` retorno de chamada pode ser usado para determinar quando mais dados chegam.

Se o soquete é do tipo SOCK_STREAM e o lado remoto encerrou a conexão normalmente, um `ReceiveFromEx` será concluído imediatamente com 0 bytes recebidos.

##  <a name="send"></a>  CAsyncSocket::Send

Chame essa função de membro para enviar dados em um soquete conectado.

```
virtual int Send(
    const void* lpBuf,
    int nBufLen,
    int nFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Um buffer que contém os dados a serem transmitidos.

*nBufLen*<br/>
O comprimento dos dados no *lpBuf* em bytes.

*nFlags*<br/>
Especifica a maneira na qual a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e o *nFlags* parâmetro. O último é construído pela combinação de qualquer um dos seguintes valores com o C++ **ou** operador:

- MSG_DONTROUTE Especifica que os dados não devem estar sujeitos a roteamento. Um fornecedor de soquetes do Windows pode optar por ignorar esse sinalizador.

- Enviar MSG_OOB out-of-band dados (SOCK_STREAM).

### <a name="return-value"></a>Valor de retorno

Se nenhum erro ocorrer, `Send` retorna o número total de caracteres enviados. (Observe que isso pode ser menor que o número indicado por *nBufLen*.) Caso contrário, um valor de SOCKET_ERROR é retornado e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEACCES o endereço solicitado é um endereço de difusão, mas o sinalizador apropriado não foi definido.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- WSAEFAULT a *lpBuf* argumento não é parte do espaço de endereço de usuário válida.

- WSAENETRESET a conexão deve ser redefinido porque a implementação do Windows Sockets descartada-lo.

- Implementação WSAENOBUFS o Windows Sockets informa um travamento do buffer.

- WSAENOTCONN o soquete não está conectado.

- O descritor WSAENOTSOCK não é um soquete.

- WSAEOPNOTSUPP MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- Foi desligado do soquete WSAESHUTDOWN; não é possível chamar `Send` em um soquete após `ShutDown` foi invocado com *nHow* definido como 1 ou 2.

- WSAEWOULDBLOCK o soquete está marcado como sem bloqueio e bloquearia a operação solicitada.

- WSAEMSGSIZE o soquete é do tipo SOCK_DGRAM e o datagrama é maior do que o máximo com suporte pela implementação do Windows Sockets.

- WSAEINVAL o soquete não foi associado com `Bind`.

- WSAECONNABORTED o circuito virtual foi anulada devido a tempo limite ou outra falha.

- WSAECONNRESET o circuito virtual foi redefinido pelo lado remoto.

### <a name="remarks"></a>Comentários

`Send` é usado para gravar dados de saída no fluxo conectado ou soquetes de datagrama. Para soquetes de datagrama, tome cuidado para não exceder o tamanho máximo do pacote IP das sub-redes subjacentes, que é fornecido pelo `iMaxUdpDg` elemento na [WSADATA](../../mfc/reference/wsadata-structure.md) estrutura retornada pelo `AfxSocketInit`. Se os dados forem muito para passar de forma atômica por meio do protocolo subjacente, o erro WSAEMSGSIZE é retornado por meio de `GetLastError`, e nenhum dado é transmitido.

Observe que, para um datagrama de soquete da conclusão bem-sucedida de um `Send` não indica que os dados foi entregue com êxito.

Em `CAsyncSocket` objetos do tipo SOCK_STREAM, o número de bytes gravados pode ser entre 1 e o tamanho solicitado, dependendo da disponibilidade de buffer nos hosts locais e externos.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CAsyncSocket::OnSend](#onsend).

##  <a name="sendto"></a>  CAsyncSocket::SendTo

Chame essa função de membro para enviar dados para um destino específico.

```
int SendTo(
    const void* lpBuf,
    int nBufLen,
    UINT nHostPort,
    LPCTSTR lpszHostAddress = NULL,
    int nFlags = 0);

int SendTo(
    const void* lpBuf,
    int nBufLen,
    const SOCKADDR* lpSockAddr,
    int nSockAddrLen,
    int nFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Um buffer que contém os dados a serem transmitidos.

*nBufLen*<br/>
O comprimento dos dados no *lpBuf* em bytes.

*nHostPort*<br/>
A porta que identifica o aplicativo de soquete.

*lpszHostAddress*<br/>
O endereço de rede do soquete para o qual este objeto está conectado: um nome de máquina, como "ftp.microsoft.com" ou um número pontilhado, como "128.56.22.8".

*nFlags*<br/>
Especifica a maneira na qual a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e o *nFlags* parâmetro. O último é construído pela combinação de qualquer um dos seguintes valores com o C++ **ou** operador:

- MSG_DONTROUTE Especifica que os dados não devem estar sujeitos a roteamento. Um fornecedor de soquetes do Windows pode optar por ignorar esse sinalizador.

- Enviar MSG_OOB out-of-band dados (SOCK_STREAM).

*lpSockAddr*<br/>
Um ponteiro para um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que contém o endereço do soquete de destino.

*nSockAddrLen*<br/>
O comprimento do endereço no *lpSockAddr* em bytes.

### <a name="return-value"></a>Valor de retorno

Se nenhum erro ocorrer, `SendTo` retorna o número total de caracteres enviados. (Observe que isso pode ser menor que o número indicado por *nBufLen*.) Caso contrário, um valor de SOCKET_ERROR é retornado e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEACCES o endereço solicitado é um endereço de difusão, mas o sinalizador apropriado não foi definido.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- WSAEFAULT a *lpBuf* ou *lpSockAddr* parâmetros não são parte do espaço de endereço do usuário, ou o *lpSockAddr* argumento for muito pequeno (menos do que o tamanho de um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura).

- O nome do host WSAEINVAL é inválido.

- WSAENETRESET a conexão deve ser redefinido porque a implementação do Windows Sockets descartada-lo.

- Implementação WSAENOBUFS o Windows Sockets informa um travamento do buffer.

- WSAENOTCONN o soquete não está conectado (SOCK_STREAM).

- O descritor WSAENOTSOCK não é um soquete.

- WSAEOPNOTSUPP MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- Foi desligado do soquete WSAESHUTDOWN; não é possível chamar `SendTo` em um soquete após `ShutDown` foi invocado com *nHow* definido como 1 ou 2.

- WSAEWOULDBLOCK o soquete está marcado como sem bloqueio e bloquearia a operação solicitada.

- WSAEMSGSIZE o soquete é do tipo SOCK_DGRAM e o datagrama é maior do que o máximo com suporte pela implementação do Windows Sockets.

- WSAECONNABORTED o circuito virtual foi anulada devido a tempo limite ou outra falha.

- WSAECONNRESET o circuito virtual foi redefinido pelo lado remoto.

- WSAEADDRNOTAVAIL o endereço especificado não está disponível no computador local.

- WSAEAFNOSUPPORT endereços na família especificada não pode ser usados com este soquete.

- Endereço de destino A WSAEDESTADDRREQ é necessário.

- WSAENETUNREACH a rede não pode ser alcançada através deste host neste momento.

### <a name="remarks"></a>Comentários

`SendTo` é usado em soquetes de datagrama ou fluxo e é usado para gravar dados de saída em um soquete. Para soquetes de datagrama, tome cuidado para não exceder o tamanho máximo do pacote IP das sub-redes subjacentes, que é fornecido pelo `iMaxUdpDg` elemento na [WSADATA](../../mfc/reference/wsadata-structure.md) estrutura preenchido por [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit). Se os dados forem muito para passar de forma atômica por meio do protocolo subjacente, o erro WSAEMSGSIZE será retornado e nenhum dado é transmitido.

Observe que a conclusão bem-sucedida de um `SendTo` não indica que os dados foi entregue com êxito.

`SendTo` só é usado em um soquete SOCK_DGRAM para enviar um datagrama para um soquete específico identificado pela *lpSockAddr* parâmetro.

Para enviar uma difusão (em um SOCK_DGRAM somente), o endereço na *lpSockAddr* parâmetro deve ser construído usando o endereço IP especial INADDR_BROADCAST (definido no arquivo de cabeçalho WINSOCK do Windows Sockets. H) junto com o número da porta pretendido. Ou, se o *lpszHostAddress* parâmetro for NULL, o soquete é configurado para transmissão. Não é geralmente recomendável para um datagrama de difusão exceda o tamanho em que a fragmentação pode ocorrer, que significa que a parte de dados do datagrama (excluindo cabeçalhos) não deve exceder 512 bytes.

Para lidar com endereços IPv6, use [CAsyncSocket::SendToEx](#sendtoex).

##  <a name="sendtoex"></a>  CAsyncSocket::SendToEx

Chame essa função de membro para enviar dados para um destino específico (alças endereços IPv6).

```
int SendToEx(
    const void* lpBuf,
    int nBufLen,
    UINT nHostPort,
    LPCTSTR lpszHostAddress = NULL,
    int nFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*lpBuf*<br/>
Um buffer que contém os dados a serem transmitidos.

*nBufLen*<br/>
O comprimento dos dados no *lpBuf* em bytes.

*nHostPort*<br/>
A porta que identifica o aplicativo de soquete.

*lpszHostAddress*<br/>
O endereço de rede do soquete para o qual este objeto está conectado: um nome de máquina, como "ftp.microsoft.com" ou um número pontilhado, como "128.56.22.8".

*nFlags*<br/>
Especifica a maneira na qual a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e o *nFlags* parâmetro. O último é construído pela combinação de qualquer um dos seguintes valores com o C++ **ou** operador:

- MSG_DONTROUTE Especifica que os dados não devem estar sujeitos a roteamento. Um fornecedor de soquetes do Windows pode optar por ignorar esse sinalizador.

- Enviar MSG_OOB out-of-band dados (SOCK_STREAM).

### <a name="return-value"></a>Valor de retorno

Se nenhum erro ocorrer, `SendToEx` retorna o número total de caracteres enviados. (Observe que isso pode ser menor que o número indicado por *nBufLen*.) Caso contrário, um valor de SOCKET_ERROR é retornado e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEACCES o endereço solicitado é um endereço de difusão, mas o sinalizador apropriado não foi definido.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- WSAEFAULT a *lpBuf* ou *lpSockAddr* parâmetros não são parte do espaço de endereço do usuário, ou o *lpSockAddr* argumento for muito pequeno (menos do que o tamanho de um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura).

- O nome do host WSAEINVAL é inválido.

- WSAENETRESET a conexão deve ser redefinido porque a implementação do Windows Sockets descartada-lo.

- Implementação WSAENOBUFS o Windows Sockets informa um travamento do buffer.

- WSAENOTCONN o soquete não está conectado (SOCK_STREAM).

- O descritor WSAENOTSOCK não é um soquete.

- WSAEOPNOTSUPP MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- Foi desligado do soquete WSAESHUTDOWN; não é possível chamar `SendToEx` em um soquete após `ShutDown` foi invocado com *nHow* definido como 1 ou 2.

- WSAEWOULDBLOCK o soquete está marcado como sem bloqueio e bloquearia a operação solicitada.

- WSAEMSGSIZE o soquete é do tipo SOCK_DGRAM e o datagrama é maior do que o máximo com suporte pela implementação do Windows Sockets.

- WSAECONNABORTED o circuito virtual foi anulada devido a tempo limite ou outra falha.

- WSAECONNRESET o circuito virtual foi redefinido pelo lado remoto.

- WSAEADDRNOTAVAIL o endereço especificado não está disponível no computador local.

- WSAEAFNOSUPPORT endereços na família especificada não pode ser usados com este soquete.

- Endereço de destino A WSAEDESTADDRREQ é necessário.

- WSAENETUNREACH a rede não pode ser alcançada através deste host neste momento.

### <a name="remarks"></a>Comentários

Esse método é o mesmo que [CAsyncSocket::SendTo](#sendto) protocolos mais antigos, bem como de endereços, exceto que ele lida com IPv6.

`SendToEx` é usado em soquetes de datagrama ou fluxo e é usado para gravar dados de saída em um soquete. Para soquetes de datagrama, tome cuidado para não exceder o tamanho máximo do pacote IP das sub-redes subjacentes, que é fornecido pelo `iMaxUdpDg` elemento na [WSADATA](../../mfc/reference/wsadata-structure.md) estrutura preenchido por [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit). Se os dados forem muito para passar de forma atômica por meio do protocolo subjacente, o erro WSAEMSGSIZE será retornado e nenhum dado é transmitido.

Observe que a conclusão bem-sucedida de um `SendToEx` não indica que os dados foi entregue com êxito.

`SendToEx` só é usado em um soquete SOCK_DGRAM para enviar um datagrama para um soquete específico identificado pela *lpSockAddr* parâmetro.

Para enviar uma difusão (em um SOCK_DGRAM somente), o endereço na *lpSockAddr* parâmetro deve ser construído usando o endereço IP especial INADDR_BROADCAST (definido no arquivo de cabeçalho WINSOCK do Windows Sockets. H) junto com o número da porta pretendido. Ou, se o *lpszHostAddress* parâmetro for NULL, o soquete é configurado para transmissão. Não é geralmente recomendável para um datagrama de difusão exceda o tamanho em que a fragmentação pode ocorrer, que significa que a parte de dados do datagrama (excluindo cabeçalhos) não deve exceder 512 bytes.

##  <a name="setsockopt"></a>  CAsyncSocket::SetSockOpt

Chame essa função de membro para definir uma opção de soquete.

```
BOOL SetSockOpt(
    int nOptionName,
    const void* lpOptionValue,
    int nOptionLen,
    int nLevel = SOL_SOCKET);
```

### <a name="parameters"></a>Parâmetros

*nOptionName*<br/>
A opção de soquete para o qual o valor deve ser definido.

*lpOptionValue*<br/>
Um ponteiro para o buffer no qual o valor da opção solicitada é fornecido.

*nOptionLen*<br/>
O tamanho do *lpOptionValue* buffer em bytes.

*nLevel*<br/>
O nível no qual a opção estiver definida; os níveis com suporte somente são SOL_SOCKET e IPPROTO_TCP.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT *lpOptionValue* não é parte do espaço de endereço de processo válida.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- WSAEINVAL *nLevel* não é válido, ou as informações *lpOptionValue* não é válido.

- Conexão WSAENETRESET foi atingido quando SO_KEEPALIVE está definido.

- A opção de WSAENOPROTOOPT é desconhecido ou sem suporte. Em particular, SO_BROADCAST não tem suporte em soquetes do tipo SOCK_STREAM, enquanto SO_DONTLINGER, SO_KEEPALIVE, SO_LINGER e SO_OOBINLINE não têm suporte em soquetes do tipo SOCK_DGRAM.

- WSAENOTCONN Conexão foi redefinida quando SO_KEEPALIVE está definido.

- O descritor WSAENOTSOCK não é um soquete.

### <a name="remarks"></a>Comentários

`SetSockOpt` Define o valor atual para uma opção de soquete associada com um soquete de qualquer tipo, em qualquer estado. Embora as opções podem existir em vários níveis de protocolo, essa especificação define apenas as opções que existem no nível superior "soquete". Opções afetam as operações de soquete, como se os dados emitidos são recebidos no fluxo de dados normal, se as mensagens de difusão podem ser enviadas no soquete e assim por diante.

Há dois tipos de opções de soquete: Boolean opções que habilitam ou desabilitam a um recurso ou comportamento e as opções que exigem uma estrutura ou um valor inteiro. Para habilitar uma opção de booliana *lpOptionValue* aponta para um inteiro diferente de zero. Para desabilitar a opção *lpOptionValue* aponta para um número inteiro igual a zero. *nOptionLen* deve ser igual ao `sizeof(BOOL)` para opções de Boolianas. Para obter outras opções, *lpOptionValue* aponta para o inteiro ou uma estrutura que contém o valor desejado para a opção, e *nOptionLen* é o comprimento do número inteiro ou estrutura.

SO_LINGER controla a ação executada quando os dados não enviados são enfileirados em um soquete e o `Close` função é chamada para fechar o soquete.

Por padrão, não é possível associar um soquete (consulte [associar](#bind)) para um endereço local que já está em uso. Às vezes, no entanto, ele pode ser desejável para um endereço dessa forma de "reuse". Uma vez que cada conexão é identificado exclusivamente pela combinação dos endereços locais e remotos, não há nenhum problema com ter dois soquetes vinculados para o mesmo endereço local, desde que os endereços remotos são diferentes.

Para informar a implementação do Windows Sockets que um `Bind` chamada em um soquete não deve ser desativada porque o endereço desejado já está em uso por outro soquete, o aplicativo deve definir a opção de soquete para o soquete SO_REUSEADDR antes de emitir o `Bind` chamar. Observe que a opção é interpretada somente no momento do `Bind` chamar: portanto é desnecessário (mas inofensivo) definir a opção em um soquete que não deve ser associado a um endereço existente, e configurando ou redefinir a opção após o `Bind` chamada tem nenhum efeito neste ou em qualquer outro soquete.

Um aplicativo pode solicitar que a implementação do Windows Sockets permitem o uso de pacotes "keep-alive" em conexões de protocolo TCP (Transmission Control) ao ativar a opção de soquete SO_KEEPALIVE. Uma implementação de soquetes do Windows não precisa suportar o uso de keep alives: em caso afirmativo, a semântica precisa são específicos de implementação, mas deve estar em conformidade com RFC 1122 seção 4.2.3.6: "requisitos para Hosts da Internet — camadas de comunicação." Se uma conexão é descartada como resultado de "keep-alive" código de erro WSAENETRESET é retornado para todas as chamadas em andamento no soquete, e todas as chamadas subsequentes falharão com WSAENOTCONN.

A opção TCP_NODELAY desabilita o algoritmo de Nagle. O algoritmo de Nagle é usado para reduzir o número de pacotes pequenos enviada por um host pelo buffer de dados de envio não confirmadas até que um pacote em tamanho normal pode ser enviado. No entanto, para alguns aplicativos esse algoritmo pode impedir o desempenho e TCP_NODELAY pode ser usado para desativá-lo. Criadores de aplicativo não deverá definir TCP_NODELAY, a menos que o impacto de fazer então é bem compreendido e desejada, desde que a configuração TCP_NODELAY pode ter um impacto negativo significativo no desempenho da rede. TCP_NODELAY é a única opção de soquete que usa o nível IPPROTO_TCP; com suporte todas as outras opções usam nível SOL_SOCKET.

Algumas implementações do fornecimento de Windows Sockets informações de depuração de saída se a opção SO_DEBUG é definida por um aplicativo.

As opções a seguir têm suporte para `SetSockOpt`. O tipo identifica o tipo de dados endereçados pela *lpOptionValue*.

|Valor|Tipo|Significado|
|-----------|----------|-------------|
|SO_BROADCAST|BOOL|Permitir transmissão de mensagens de difusão no soquete.|
|SO_DEBUG|BOOL|Registre informações de depuração.|
|SO_DONTLINGER|BOOL|Não bloquear `Close` esperar que haja dados a serem enviados. Essa opção é equivalente a definir SO_LINGER com `l_onoff` definido como zero.|
|SO_DONTROUTE|BOOL|Não encaminhar: enviar diretamente para a interface.|
|SO_KEEPALIVE|BOOL|Envie keep alives.|
|SO_LINGER|`struct LINGER`|Demora no `Close` se não enviados os dados estão presentes.|
|SO_OOBINLINE|BOOL|Recebe dados fora de banda no fluxo de dados normal.|
|SO_RCVBUF|**int**|Especifique o tamanho do buffer para recebe.|
|SO_REUSEADDR|BOOL|Permitir que o soquete a ser associado a um endereço que já está em uso. (Consulte [associar](#bind).)|
|SO_SNDBUF|**int**|Especifique o tamanho do buffer para envios.|
|TCP_NODELAY|BOOL|Desabilita o algoritmo Nagle para união de envio.|

Opções de Berkeley Software Distribution (BSD) não tem suportadas para `SetSockOpt` são:

|Valor|Tipo|Significado|
|-----------|----------|-------------|
|SO_ACCEPTCONN|BOOL|Soquete está escutando|
|SO_ERROR|**int**|Obter o status de erro e limpe.|
|SO_RCVLOWAT|**int**|Receba a marca d'água inferior.|
|SO_RCVTIMEO|**int**|Tempo limite de recebimento|
|SO_SNDLOWAT|**int**|Envie marca d'água inferior.|
|SO_SNDTIMEO|**int**|Tempo limite de envio.|
|SO_TYPE|**int**|Tipo de soquete.|
|IP_OPTIONS||Defina o campo de opções no cabeçalho IP.|

##  <a name="shutdown"></a>  CAsyncSocket::ShutDown

Chamada para essa função de membro para desabilitar a envia, receber, ou ambos no soquete.

```
BOOL ShutDown(int nHow = sends);
```

### <a name="parameters"></a>Parâmetros

*nHow*<br/>
Um sinalizador que descreve quais tipos de operação não será permitido, usando os seguintes valores enumerados:

- **recebe = 0**

- **envia = 1**

- **tanto = 2**

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:

- WSANOTINITIALISED A bem-sucedida [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.

- Implementação WSAENETDOWN o Windows Sockets detectou que o subsistema de rede falhou.

- WSAEINVAL *nHow* não é válido.

- Operação de Windows Sockets WSAEINPROGRESS A bloqueio está em andamento.

- WSAENOTCONN o soquete não está conectado (SOCK_STREAM).

- O descritor WSAENOTSOCK não é um soquete.

### <a name="remarks"></a>Comentários

`ShutDown` é usado em todos os tipos de soquetes para desabilitar recepção, transmissão ou ambos. Se *nHow* for 0, recebe subsequentes em soquete não será permitido. Isso não tem nenhum efeito nas camadas inferiores do protocolo.

Para o protocolo TCP (Transmission Control), a janela TCP não é alterada e os dados de entrada serão aceitos (mas não confirmada) até que a janela é esgotada. Para o protocolo UDP (User Datagram), os datagramas de entrada são aceitos e enfileirados. Em nenhum caso de um pacote de erro ICMP ser gerado. Se *nHow* é 1, envios subsequentes não são permitidos. Para soquetes TCP, será enviado um FIN. Definindo *nHow* 2 desabilita ambos os envios e recebimentos conforme descrito acima.

Observe que `ShutDown` não fechar o soquete e recursos anexados para o soquete não será liberado até `Close` é chamado. Um aplicativo não deve confiar no que está sendo capaz de reutilizar um soquete, depois que ele foi desligado. Em particular, uma implementação de soquetes do Windows não é necessário para dar suporte ao uso de `Connect` em tal um soquete.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CAsyncSocket::OnReceive](#onreceive).

##  <a name="socket"></a>  CASyncSocket::Socket

Aloca um identificador de soquete.

```
BOOL Socket(
    int nSocketType = SOCK_STREAM,
    long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE,
    int nProtocolType = 0,
    int nAddressFormat = PF_INET);
```

### <a name="parameters"></a>Parâmetros

*nSocketType*<br/>
Especifica `SOCK_STREAM` ou `SOCK_DGRAM`.

*lEvent*<br/>
Um bitmask que especifica uma combinação de eventos de rede no qual o aplicativo está interessado.

- `FD_READ`: Deseja receber notificação de preparação para leitura.

- `FD_WRITE`: Deseja receber notificação de preparação para gravação.

- `FD_OOB`: Deseja receber notificação da chegada de dados fora de banda.

- `FD_ACCEPT`: Deseja receber notificação de conexões de entrada.

- `FD_CONNECT`: Deseja receber notificação de conexão concluído.

- `FD_CLOSE`: Deseja receber notificação de fechamento de soquete.

*nProtocolType*<br/>
Protocolo a ser usado com o soquete que é específico para a família de endereço indicado.

*nAddressFormat*<br/>
Especificação da família de endereços.

### <a name="return-value"></a>Valor de retorno

Retorna `TRUE` em caso de sucesso, `FALSE` em caso de falha.

### <a name="remarks"></a>Comentários

Esse método aloca um identificador de soquete. Ele não chama [CAsyncSocket::Bind](#bind) ligar o soquete para um endereço especificado, portanto, você precisará chamar `Bind` posteriormente para ligar o soquete a um endereço especificado. Você pode usar [CAsyncSocket::SetSockOpt](#setsockopt) para definir a opção de soquete antes que ele está associado.

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CSocket](../../mfc/reference/csocket-class.md)<br/>
[Classe CSocketFile](../../mfc/reference/csocketfile-class.md)
