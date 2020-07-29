---
title: Classe CAsyncSocket
ms.date: 06/25/2020
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
ms.openlocfilehash: 95d24c9fb9e432a54705a6b8f9fa7638affad2d2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87195090"
---
# <a name="casyncsocket-class"></a>Classe CAsyncSocket

Representa um soquete do Windows — um ponto de extremidade de comunicação de rede.

## <a name="syntax"></a>Sintaxe

```
class CAsyncSocket : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncSocket::CAsyncSocket](#casyncsocket)|Constrói um objeto `CAsyncSocket`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncSocket:: aceitar](#accept)|Aceita uma conexão no soquete.|
|[CAsyncSocket::AsyncSelect](#asyncselect)|Solicita notificação de eventos para o soquete.|
|[CAsyncSocket:: Attach](#attach)|Anexa um identificador de soquete a um `CAsyncSocket` objeto.|
|[CAsyncSocket:: bind](#bind)|Associa um endereço local ao soquete.|
|[CAsyncSocket:: fechar](#close)|Fecha o soquete.|
|[CAsyncSocket:: conectar](#connect)|Estabelece uma conexão com um soquete de mesmo nível.|
|[CAsyncSocket:: criar](#create)|Cria um soquete.|
|[CAsyncSocket::CreateEx](#createex)|Cria um soquete com opções avançadas.|
|[CAsyncSocket::D Etach](#detach)|Desanexa um identificador de soquete de um `CAsyncSocket` objeto.|
|[CAsyncSocket:: FromHandle](#fromhandle)|Retorna um ponteiro para um `CAsyncSocket` objeto, dado um identificador de soquete.|
|[CAsyncSocket:: GetLastError](#getlasterror)|Obtém o status de erro para a última operação que falhou.|
|[CAsyncSocket:: getemparelhaname](#getpeername)|Obtém o endereço do soquete par ao qual o soquete está conectado.|
|[CAsyncSocket::GetPeerNameEx](#getpeernameex)|Obtém o endereço do soquete par ao qual o soquete está conectado (manipula endereços IPv6).|
|[CAsyncSocket::GetSockName](#getsockname)|Obtém o nome local de um soquete.|
|[CAsyncSocket::GetSockNameEx](#getsocknameex)|Obtém o nome local de um soquete (manipula endereços IPv6).|
|[CAsyncSocket::GetSockOpt](#getsockopt)|Recupera uma opção de soquete.|
|[CAsyncSocket:: IOCtl](#ioctl)|Controla o modo do soquete.|
|[CAsyncSocket:: escutar](#listen)|Estabelece um soquete para escutar solicitações de conexão de entrada.|
|[CAsyncSocket:: receber](#receive)|Recebe dados do soquete.|
|[CAsyncSocket::ReceiveFrom](#receivefrom)|Recebe um datagrama e armazena o endereço de origem.|
|[CAsyncSocket::ReceiveFromEx](#receivefromex)|Recebe um datagrama e armazena o endereço de origem (manipula endereços IPv6).|
|[CAsyncSocket:: enviar](#send)|Envia dados para um soquete conectado.|
|[CAsyncSocket:: SendTo](#sendto)|Envia dados para um destino específico.|
|[CAsyncSocket::SendToEx](#sendtoex)|Envia dados para um destino específico (manipula endereços IPv6).|
|[CAsyncSocket::SetSockOpt](#setsockopt)|Define uma opção de soquete.|
|[CAsyncSocket:: ShutDown](#shutdown)|Desabilita `Send` e/ou `Receive` chamadas no soquete.|
|[CASyncSocket:: Socket](#socket)|Aloca um identificador de soquete.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncSocket:: OnAccept](#onaccept)|Notifica um soquete de escuta de que ele pode aceitar solicitações de conexão pendentes chamando `Accept` .|
|[CAsyncSocket:: fechamento](#onclose)|Notifica um soquete de que o Soquete conectado a ele foi fechado.|
|[CAsyncSocket:: OnConnect](#onconnect)|Notifica um soquete de conexão de que a tentativa de conexão foi concluída, seja com êxito ou com erro.|
|[CAsyncSocket::OnOutOfBandData](#onoutofbanddata)|Notifica um soquete de recebimento de que há dados fora de banda a serem lidos no soquete, geralmente uma mensagem urgente.|
|[CAsyncSocket:: OnReceive](#onreceive)|Notifica um soquete de escuta de que há dados a serem recuperados chamando `Receive` .|
|[CAsyncSocket:: OnSend](#onsend)|Notifica um soquete de que ele pode enviar dados chamando `Send` .|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncSocket:: Operator =](#operator_eq)|Atribui um novo valor a um `CAsyncSocket` objeto.|
|[SOQUETE CAsyncSocket:: Operator](#operator_socket)|Use esse operador para recuperar o identificador de soquete do `CAsyncSocket` objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncSocket:: m_hSocket](#m_hsocket)|Indica o identificador de soquete anexado a este `CAsyncSocket` objeto.|

## <a name="remarks"></a>Comentários

`CAsyncSocket`A classe encapsula a API de funções de soquete do Windows, fornecendo uma abstração orientada a objeto para programadores que desejam usar o Windows Sockets em conjunto com o MFC.

Essa classe se baseia na suposição de que você entende as comunicações de rede. Você é responsável por lidar com bloqueio, diferenças de ordem de byte e conversões entre cadeias de caracteres Unicode e MBCS (conjunto de caractere multibyte). Se você quiser uma interface mais conveniente que gerencie esses problemas para você, consulte Class [CSocket](../../mfc/reference/csocket-class.md).

Para usar um `CAsyncSocket` objeto, chame seu construtor e, em seguida, chame a função [Create](#create) para criar o identificador de soquete subjacente (Type `SOCKET` ), exceto nos soquetes aceitos. Para um soquete de servidor, chame a função de membro [Listen](#listen) e, para um soquete de cliente, chame a função de membro [Connect](#connect) . O soquete do servidor deve chamar a função [Accept](#accept) após receber uma solicitação de conexão. Use as `CAsyncSocket` funções restantes para realizar comunicações entre soquetes. Após a conclusão, destrua o `CAsyncSocket` objeto se ele foi criado no heap; o destruidor chama automaticamente a função [Close](#close) . O tipo de dados SOCKET é descrito no artigo [Windows Sockets: Background](../../mfc/windows-sockets-background.md).

> [!NOTE]
> Ao usar soquetes MFC em threads secundários em um aplicativo MFC vinculado estaticamente, você deve chamar `AfxSocketInit` em cada thread que usa soquetes para inicializar as bibliotecas de soquete. Por padrão, `AfxSocketInit` é chamado apenas no thread primário.

Para obter mais informações, consulte [Windows Sockets: usando a classe CAsyncSocket](../../mfc/windows-sockets-using-class-casyncsocket.md) e artigos relacionados., bem como a [API do Windows Sockets 2](/windows/win32/WinSock/windows-sockets-start-page-2).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CAsyncSocket`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AfxSock. h

## <a name="casyncsocketaccept"></a><a name="accept"></a>CAsyncSocket:: aceitar

Chame essa função de membro para aceitar uma conexão em um soquete.

```
virtual BOOL Accept(
    CAsyncSocket& rConnectedSocket,
    SOCKADDR* lpSockAddr = NULL,
    int* lpSockAddrLen = NULL);
```

### <a name="parameters"></a>parâmetros

*rConnectedSocket*<br/>
Uma referência que identifica um novo soquete que está disponível para conexão.

*lpSockAddr*<br/>
Um ponteiro para uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que recebe o endereço do soquete de conexão, como conhecido na rede. O formato exato do argumento *lpSockAddr* é determinado pela família de endereços estabelecida quando o soquete foi criado. Se *lpSockAddr* e/ou *lpSockAddrLen* forem iguais a NULL, nenhuma informação sobre o endereço remoto do soquete aceito será retornada.

*lpSockAddrLen*<br/>
Um ponteiro para o comprimento do endereço em *lpSockAddr* em bytes. O *lpSockAddrLen* é um parâmetro de resultado de valor: inicialmente, ele deve conter a quantidade de espaço apontada por *lpSockAddr*; em retorno, ele conterá o comprimento real (em bytes) do endereço retornado.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT o argumento *lpSockAddrLen* é muito pequeno (menor que o tamanho de uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) ).

- WSAEINPROGRESS uma chamada bloqueada do Windows Sockets está em andamento.

- WSAEINVAL `Listen` não foi invocado antes de aceitar.

- WSAEMFILE a fila está vazia na entrada a ser aceita e não há descritores disponíveis.

- WSAENOBUFS Não há espaço de buffer disponível.

- WSAENOTSOCK o descritor não é um soquete.

- WSAEOPNOTSUPP o soquete referenciado não é um tipo que dá suporte ao serviço orientado a conexões.

- WSAEWOULDBLOCK o soquete está marcado como sem bloqueio e nenhuma conexão está presente para ser aceita.

### <a name="remarks"></a>Comentários

Essa rotina extrai a primeira conexão na fila de conexões pendentes, cria um novo soquete com as mesmas propriedades que esse soquete e anexa-o a *rConnectedSocket*. Se nenhuma conexão pendente estiver presente na fila, `Accept` retornará zero e `GetLastError` retornará um erro. O soquete aceito ( *rConnectedSocket)* não pode ser usado para aceitar mais conexões. O soquete original permanece aberto e ouvindo.

O argumento *lpSockAddr* é um parâmetro de resultado que é preenchido com o endereço do soquete de conexão, como conhecido pela camada de comunicação. `Accept`é usado com tipos de soquete com base em conexão, como SOCK_STREAM.

## <a name="casyncsocketasyncselect"></a><a name="asyncselect"></a>CAsyncSocket::AsyncSelect

Chame essa função de membro para solicitar notificação de eventos para um soquete.

```
BOOL AsyncSelect(long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE);
```

### <a name="parameters"></a>parâmetros

*lEvent*<br/>
Um bitmask que especifica uma combinação de eventos de rede em que o aplicativo está interessado.

- FD_READ deseja receber a notificação de prontidão para leitura.

- FD_WRITE deseja receber a notificação quando os dados estiverem disponíveis para serem lidos.

- FD_OOB deseja receber a notificação sobre a chegada de dados fora de banda.

- FD_ACCEPT Deseja receber a notificação de conexões de entrada.

- FD_CONNECT deseja receber a notificação de resultados da conexão.

- FD_CLOSE deseja receber a notificação quando um soquete tiver sido fechado por um par.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEINVAL indica que um dos parâmetros especificados era inválido.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

### <a name="remarks"></a>Comentários

Essa função é usada para especificar quais funções de notificação de retorno de chamada MFC serão chamadas para o soquete. `AsyncSelect`define automaticamente este Soquete para o modo de não bloqueio. Para obter mais informações, consulte o artigo [Windows Sockets: Socket Notifications](../../mfc/windows-sockets-socket-notifications.md).

## <a name="casyncsocketattach"></a><a name="attach"></a>CAsyncSocket:: Attach

Chame essa função de membro para anexar o identificador *hSocket* a um `CAsyncSocket` objeto.

```
BOOL Attach(
    SOCKET hSocket, long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE);
```

### <a name="parameters"></a>parâmetros

*hSocket*<br/>
Contém um identificador para um soquete.

*lEvent*<br/>
Um bitmask que especifica uma combinação de eventos de rede em que o aplicativo está interessado.

- FD_READ deseja receber a notificação de prontidão para leitura.

- FD_WRITE deseja receber a notificação quando os dados estiverem disponíveis para serem lidos.

- FD_OOB deseja receber a notificação sobre a chegada de dados fora de banda.

- FD_ACCEPT Deseja receber a notificação de conexões de entrada.

- FD_CONNECT deseja receber a notificação de resultados da conexão.

- FD_CLOSE deseja receber a notificação quando um soquete tiver sido fechado por um par.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida.

### <a name="remarks"></a>Comentários

O identificador de soquete é armazenado no membro de dados de [m_hSocket](#m_hsocket) do objeto.

## <a name="casyncsocketbind"></a><a name="bind"></a>CAsyncSocket:: bind

Chame essa função de membro para associar um endereço local ao soquete.

```
BOOL Bind(
    UINT nSocketPort,
    LPCTSTR lpszSocketAddress = NULL);

BOOL Bind (
    const SOCKADDR* lpSockAddr,
    int nSockAddrLen);
```

### <a name="parameters"></a>parâmetros

*nSocketPort*<br/>
A porta que identifica o aplicativo de soquete.

*lpszSocketAddress*<br/>
O endereço de rede, um número pontilhado, como "128.56.22.8". Passar a cadeia de caracteres nula para esse parâmetro indica que a `CAsyncSocket` instância deve escutar a atividade do cliente em todas as interfaces de rede.

*lpSockAddr*<br/>
Um ponteiro para uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que contém o endereço a ser atribuído a este Soquete.

*nSockAddrLen*<br/>
O comprimento do endereço em *lpSockAddr* em bytes.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). A lista a seguir aborda alguns dos erros que podem ser retornados. Para obter uma lista completa, consulte [códigos de erro do Windows Sockets](/windows/win32/winsock/windows-sockets-error-codes-2).

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEADDRINUSE o endereço especificado já está em uso. (Consulte a opção Soquete de SO_REUSEADDR em [setsockopt](#setsockopt).)

- WSAEFAULT o argumento *nSockAddrLen* é muito pequeno (menor que o tamanho de uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) ).

- WSAEINPROGRESS uma chamada bloqueada do Windows Sockets está em andamento.

- WSAEAFNOSUPPORT a família de endereços especificada não tem suporte nesta porta.

- WSAEINVAL o soquete já está associado a um endereço.

- WSAENOBUFS Não há buffers suficientes disponíveis, muitas conexões.

- WSAENOTSOCK o descritor não é um soquete.

### <a name="remarks"></a>Comentários

Essa rotina é usada em um datagrama ou soquete de fluxo não conectado, antes das chamadas subsequentes `Connect` ou `Listen` . Antes que possa aceitar solicitações de conexão, um soquete de servidor de escuta deve selecionar um número de porta e torná-lo conhecido para Windows Sockets chamando `Bind` . `Bind`estabelece a associação local (número da porta/endereço do host) do soquete atribuindo um nome local a um soquete sem nome.

## <a name="casyncsocketcasyncsocket"></a><a name="casyncsocket"></a>CAsyncSocket::CAsyncSocket

Constrói um objeto de soquete em branco.

```
CAsyncSocket();
```

### <a name="remarks"></a>Comentários

Depois de construir o objeto, você deve chamar sua `Create` função de membro para criar a estrutura de dados de soquete e associar seu endereço. (No lado do servidor de uma comunicação do Windows Sockets, quando o soquete de escuta cria um soquete para usar na `Accept` chamada, você não chama `Create` esse soquete.)

## <a name="casyncsocketclose"></a><a name="close"></a>CAsyncSocket:: fechar

Fecha o soquete.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Essa função libera o descritor de soquete para que outras referências a ele falhem com o erro WSAENOTSOCK. Se essa for a última referência ao soquete subjacente, as informações de nomenclatura associadas e os dados na fila serão descartados. O destruidor do objeto de soquete chama `Close` para você.

Para `CAsyncSocket` , mas não para `CSocket` , a semântica de `Close` é afetada pelas opções de soquete SO_LINGER e SO_DONTLINGER. Para obter mais informações, consulte função de membro `GetSockOpt` .

## <a name="casyncsocketconnect"></a><a name="connect"></a>CAsyncSocket:: conectar

Chame essa função de membro para estabelecer uma conexão com um fluxo não conectado ou um soquete de datagrama.

```
BOOL Connect(
    LPCTSTR lpszHostAddress,
    UINT nHostPort);

BOOL Connect(
    const SOCKADDR* lpSockAddr,
    int nSockAddrLen);
```

### <a name="parameters"></a>parâmetros

*lpszHostAddress*<br/>
O endereço de rede do soquete ao qual esse objeto está conectado: um nome de computador, como "ftp.microsoft.com", ou um número pontilhado, como "128.56.22.8".

*nHostPort*<br/>
A porta que identifica o aplicativo de soquete.

*lpSockAddr*<br/>
Um ponteiro para uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que contém o endereço do Soquete conectado.

*nSockAddrLen*<br/>
O comprimento do endereço em *lpSockAddr* em bytes.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Se isso indicar um código de erro de WSAEWOULDBLOCK e seu aplicativo estiver usando retornos de chamada substituíveis, seu aplicativo receberá uma `OnConnect` mensagem quando a operação de conexão for concluída. Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEADDRINUSE o endereço especificado já está em uso.

- WSAEINPROGRESS uma chamada bloqueada do Windows Sockets está em andamento.

- WSAEADDRNOTAVAIL o endereço especificado não está disponível no computador local.

- Os endereços WSAEAFNOSUPPORT na família especificada não podem ser usados com este Soquete.

- WSAECONNREFUSED a tentativa de conexão foi rejeitada.

- WSAEDESTADDRREQ um endereço de destino é necessário.

- WSAEFAULT o argumento *nSockAddrLen* está incorreto.

- WSAEINVAL endereço de host inválido.

- WSAEISCONN o soquete já está conectado.

- WSAEMFILE não há mais descritores de arquivo disponíveis.

- WSAENETUNREACH a rede não pode ser acessada neste host no momento.

- WSAENOBUFS Não há espaço de buffer disponível. O soquete não pode ser conectado.

- WSAENOTSOCK o descritor não é um soquete.

- WSAETIMEDOUT tentativa de conexão atingiu o tempo limite sem estabelecer uma conexão.

- WSAEWOULDBLOCK o soquete está marcado como não bloqueado e a conexão não pode ser concluída imediatamente.

### <a name="remarks"></a>Comentários

Se o soquete estiver desassociado, os valores exclusivos serão atribuídos à associação local pelo sistema e o Soquete será marcado como associado. Observe que, se o campo endereço da estrutura de nome for todos os zeros, o `Connect` retornará zero. Para obter informações de erro estendidas, chame a `GetLastError` função de membro.

Para soquetes de fluxo (tipo SOCK_STREAM), uma conexão ativa é iniciada para o host externo. Quando a chamada de soquete for concluída com êxito, o soquete estará pronto para enviar/receber dados.

Para um soquete de datagrama (tipo SOCK_DGRAM), um destino padrão é definido, que será usado nas `Send` chamadas subsequentes e `Receive` .

## <a name="casyncsocketcreate"></a><a name="create"></a>CAsyncSocket:: criar

Chame a `Create` função de membro depois de construir um objeto de soquete para criar o soquete do Windows e anexá-lo.

```
BOOL Create(
    UINT nSocketPort = 0,
    int nSocketType = SOCK_STREAM,
    long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE,
    LPCTSTR lpszSocketAddress = NULL);
```

### <a name="parameters"></a>parâmetros

*nSocketPort*<br/>
Uma porta conhecida a ser usada com o soquete ou 0 se você quiser que o Windows Sockets selecione uma porta.

*nSocketType*<br/>
SOCK_STREAM ou SOCK_DGRAM.

*lEvent*<br/>
Um bitmask que especifica uma combinação de eventos de rede em que o aplicativo está interessado.

- FD_READ deseja receber a notificação de prontidão para leitura.

- FD_WRITE deseja receber a notificação de preparação para gravação.

- FD_OOB deseja receber a notificação sobre a chegada de dados fora de banda.

- FD_ACCEPT Deseja receber a notificação de conexões de entrada.

- FD_CONNECT deseja receber a notificação de conexão concluída.

- FD_CLOSE deseja receber a notificação de fechamento do soquete.

*lpszSockAddress*<br/>
Um ponteiro para uma cadeia de caracteres que contém o endereço de rede do Soquete conectado, um número pontilhado, como "128.56.22.8". Passar a cadeia de caracteres nula para esse parâmetro indica que a `CAsyncSocket` instância deve escutar a atividade do cliente em todas as interfaces de rede.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEAFNOSUPPORT Não há suporte para a família de endereços especificada.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAEMFILE não há mais descritores de arquivo disponíveis.

- WSAENOBUFS Não há espaço de buffer disponível. Não é possível criar o soquete.

- WSAEPROTONOSUPPORT não há suporte para a porta especificada.

- WSAEPROTOTYPE a porta especificada é do tipo incorreto para este Soquete.

- WSAESOCKTNOSUPPORT não há suporte para o tipo de soquete especificado nesta família de endereços.

### <a name="remarks"></a>Comentários

`Create`chama o [soquete](#socket) e, se for bem-sucedido, ele chamará a [ligação](#bind) para associar o soquete ao endereço especificado. Há suporte para os seguintes tipos de soquete:

- O SOCK_STREAM fornece fluxos de bytes seqüenciais, confiáveis, completos e baseados em conexões. Usa o protocolo TCP para a família de endereços da Internet.

- O SOCK_DGRAM dá suporte a datagramas, que são pacotes sem conexão de um tamanho máximo fixo (normalmente pequeno). Usa o UDP (User Datagram Protocol) para a família de endereços da Internet.

    > [!NOTE]
    >  A `Accept` função member usa uma referência a um novo objeto vazio `CSocket` como seu parâmetro. Você deve construir esse objeto antes de chamar `Accept` . Tenha em mente que, se esse objeto de soquete sair do escopo, a conexão será fechada. Não chame `Create` esse novo objeto de soquete.

> [!IMPORTANT]
> `Create`**não** é thread-safe.  Se você estiver chamando-o em um ambiente multi-threaded, em que ele poderia ser invocado simultaneamente por threads diferentes, certifique-se de proteger cada chamada com um mutex ou outro bloqueio de sincronização.

Para obter mais informações sobre Stream e soquetes de datagrama, consulte os artigos [Windows Sockets: Background](../../mfc/windows-sockets-background.md) and [Windows Sockets: portas and socket Addresses](../../mfc/windows-sockets-ports-and-socket-addresses.md) e [Windows Sockets 2 API](/windows/win32/WinSock/windows-sockets-start-page-2).

## <a name="casyncsocketcreateex"></a><a name="createex"></a>CAsyncSocket::CreateEx

Chame a `CreateEx` função de membro depois de construir um objeto de soquete para criar o soquete do Windows e anexá-lo.

Use essa função quando precisar fornecer opções avançadas, como o tipo de soquete.

```
BOOL CreateEx(
    ADDRINFOT* pAI,
    long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE);
```

### <a name="parameters"></a>parâmetros

*pAI*<br/>
Um ponteiro para um [ADDRINFOT](https://docs.microsoft.com/windows/win32/api/ws2def/ns-ws2def-addrinfoa) para armazenar informações de soquete, como a família e o tipo de soquete.

*lEvent*<br/>
Um bitmask que especifica uma combinação de eventos de rede em que o aplicativo está interessado.

- FD_READ deseja receber a notificação de prontidão para leitura.

- FD_WRITE deseja receber a notificação de preparação para gravação.

- FD_OOB deseja receber a notificação sobre a chegada de dados fora de banda.

- FD_ACCEPT Deseja receber a notificação de conexões de entrada.

- FD_CONNECT deseja receber a notificação de conexão concluída.

- FD_CLOSE deseja receber a notificação de fechamento do soquete.

### <a name="return-value"></a>Valor retornado

Consulte o valor de retorno para [Create ()](#return-value-5).

### <a name="remarks"></a>Comentários

Consulte os comentários para [Create ()](#remarks-8).

## <a name="casyncsocketdetach"></a><a name="detach"></a>CAsyncSocket::D Etach

Chame essa função de membro para desanexar o identificador de soquete no membro de dados *m_hSocket* do `CAsyncSocket` objeto e defina *m_hSocket* como nulo.

```
SOCKET Detach();
```

## <a name="casyncsocketfromhandle"></a><a name="fromhandle"></a>CAsyncSocket:: FromHandle

Retorna um ponteiro para um `CAsyncSocket` objeto.

```
static CAsyncSocket* PASCAL FromHandle(SOCKET hSocket);
```

### <a name="parameters"></a>parâmetros

*hSocket*<br/>
Contém um identificador para um soquete.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um `CAsyncSocket` objeto ou NULL se não houver nenhum `CAsyncSocket` objeto anexado a *hSocket*.

### <a name="remarks"></a>Comentários

Quando um identificador de soquete é fornecido, se um `CAsyncSocket` objeto não estiver anexado ao identificador, a função de membro retornará NULL.

## <a name="casyncsocketgetlasterror"></a><a name="getlasterror"></a>CAsyncSocket:: GetLastError

Chame essa função de membro para obter o status de erro para a última operação que falhou.

```
static int PASCAL GetLastError();
```

### <a name="return-value"></a>Valor retornado

O valor de retorno indica o código de erro para a última rotina da API do Windows Sockets executada por esse thread.

### <a name="remarks"></a>Comentários

Quando uma determinada função de membro indica que ocorreu um erro, `GetLastError` deve ser chamada para recuperar o código de erro apropriado. Consulte as descrições da função membro individual para obter uma lista de códigos de erro aplicáveis.

Para obter mais informações sobre os códigos de erro, consulte [API do Windows Sockets 2](/windows/win32/WinSock/windows-sockets-start-page-2).

## <a name="casyncsocketgetpeername"></a><a name="getpeername"></a>CAsyncSocket:: getemparelhaname

Chame essa função de membro para obter o endereço do soquete par ao qual esse soquete está conectado.

```
BOOL GetPeerName(
    CString& rPeerAddress,
    UINT& rPeerPort);

BOOL GetPeerName(
    SOCKADDR* lpSockAddr,
    int* lpSockAddrLen);
```

### <a name="parameters"></a>parâmetros

*rPeerAddress*<br/>
Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.

*rPeerPort*<br/>
Referência a um UINT que armazena uma porta.

*lpSockAddr*<br/>
Um ponteiro para a estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que recebe o nome do soquete par.

*lpSockAddrLen*<br/>
Um ponteiro para o comprimento do endereço em *lpSockAddr* em bytes. No retorno, o argumento *lpSockAddrLen* contém o tamanho real de *lpSockAddr* retornado em bytes.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT o argumento *lpSockAddrLen* não é grande o suficiente.

- WSAEINPROGRESS uma chamada bloqueada do Windows Sockets está em andamento.

- WSAENOTCONN o soquete não está conectado.

- WSAENOTSOCK o descritor não é um soquete.

### <a name="remarks"></a>Comentários

Para manipular endereços IPv6, use [CAsyncSocket:: GetPeerNameEx](#getpeernameex).

## <a name="casyncsocketgetpeernameex"></a><a name="getpeernameex"></a>CAsyncSocket::GetPeerNameEx

Chame essa função de membro para obter o endereço do soquete par ao qual esse soquete está conectado (manipula endereços IPv6).

```
BOOL GetPeerNameEx(
    CString& rPeerAddress,
    UINT& rPeerPort);
```

### <a name="parameters"></a>parâmetros

*rPeerAddress*<br/>
Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.

*rPeerPort*<br/>
Referência a um UINT que armazena uma porta.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT o argumento *lpSockAddrLen* não é grande o suficiente.

- WSAEINPROGRESS uma chamada bloqueada do Windows Sockets está em andamento.

- WSAENOTCONN o soquete não está conectado.

- WSAENOTSOCK o descritor não é um soquete.

### <a name="remarks"></a>Comentários

Essa função é igual a [CAsyncSocket:: Getemparelhaname](#getpeername) , exceto pelo fato de tratar endereços IPv6, bem como protocolos mais antigos.

## <a name="casyncsocketgetsockname"></a><a name="getsockname"></a>CAsyncSocket::GetSockName

Chame essa função de membro para obter o nome local de um soquete.

```
BOOL GetSockName(
    CString& rSocketAddress,
    UINT& rSocketPort);

BOOL GetSockName(
    SOCKADDR* lpSockAddr,
    int* lpSockAddrLen);
```

### <a name="parameters"></a>parâmetros

*rSocketAddress*<br/>
Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.

*rSocketPort*<br/>
Referência a um UINT que armazena uma porta.

*lpSockAddr*<br/>
Um ponteiro para uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que recebe o endereço do soquete.

*lpSockAddrLen*<br/>
Um ponteiro para o comprimento do endereço em *lpSockAddr* em bytes.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT o argumento *lpSockAddrLen* não é grande o suficiente.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAENOTSOCK o descritor não é um soquete.

- WSAEINVAL o soquete não foi associado a um endereço com `Bind` .

### <a name="remarks"></a>Comentários

Essa chamada é especialmente útil quando uma `Connect` chamada foi feita sem fazer a `Bind` primeira; essa chamada fornece o único meio pelo qual você pode determinar a associação local que foi definida pelo sistema.

Para manipular endereços IPv6, use [CAsyncSocket:: GetSockNameEx](#getsocknameex)

## <a name="casyncsocketgetsocknameex"></a><a name="getsocknameex"></a>CAsyncSocket::GetSockNameEx

Chame essa função de membro para obter o nome local de um soquete (manipula endereços IPv6).

```
BOOL GetSockNameEx(
    CString& rSocketAddress,
    UINT& rSocketPort);
```

### <a name="parameters"></a>parâmetros

*rSocketAddress*<br/>
Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.

*rSocketPort*<br/>
Referência a um UINT que armazena uma porta.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT o argumento *lpSockAddrLen* não é grande o suficiente.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAENOTSOCK o descritor não é um soquete.

- WSAEINVAL o soquete não foi associado a um endereço com `Bind` .

### <a name="remarks"></a>Comentários

Essa chamada é a mesma que [CAsyncSocket:: getsockname](#getsockname) , exceto que ela trata endereços IPv6, bem como protocolos mais antigos.

Essa chamada é especialmente útil quando uma `Connect` chamada foi feita sem fazer a `Bind` primeira; essa chamada fornece o único meio pelo qual você pode determinar a associação local que foi definida pelo sistema.

## <a name="casyncsocketgetsockopt"></a><a name="getsockopt"></a>CAsyncSocket::GetSockOpt

Chame essa função de membro para recuperar uma opção de soquete.

```
BOOL GetSockOpt(
    int nOptionName,
    void* lpOptionValue,
    int* lpOptionLen,
    int nLevel = SOL_SOCKET);
```

### <a name="parameters"></a>parâmetros

*nOptionName*<br/>
A opção de soquete para a qual o valor deve ser recuperado.

*lpOptionValue*<br/>
Um ponteiro para o buffer no qual o valor da opção solicitada deve ser retornado. O valor associado à opção selecionada é retornado no buffer *lpOptionValue*. O inteiro apontado por *lpOptionLen* deve conter originalmente o tamanho desse buffer em bytes; e, no retorno, ele será definido como o tamanho do valor retornado. Por SO_LINGER, esse será o tamanho de uma `LINGER` estrutura; para todas as outras opções, ele será o tamanho de um bool ou de um **`int`** , dependendo da opção. Consulte a lista de opções e seus tamanhos na seção comentários.

*lpOptionLen*<br/>
Um ponteiro para o tamanho do buffer *lpOptionValue* em bytes.

*nLevel*<br/>
O nível no qual a opção é definida; os únicos níveis com suporte são SOL_SOCKET e IPPROTO_TCP.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Se uma opção nunca foi definida com `SetSockOpt` , `GetSockOpt` o retornará o valor padrão para a opção. Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT o argumento *lpOptionLen* era inválido.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAENOPROTOOPT a opção é desconhecida ou sem suporte. Em particular, não há suporte para SO_BROADCAST em soquetes do tipo SOCK_STREAM, enquanto SO_ACCEPTCONN, SO_DONTLINGER, SO_KEEPALIVE, SO_LINGER e SO_OOBINLINE não têm suporte em soquetes do tipo SOCK_DGRAM.

- WSAENOTSOCK o descritor não é um soquete.

### <a name="remarks"></a>Comentários

`GetSockOpt`Recupera o valor atual para uma opção de soquete associada a um soquete de qualquer tipo, em qualquer Estado, e armazena o resultado em *lpOptionValue*. As opções afetam as operações de soquete, como o roteamento de pacotes, transferência de dados fora de banda e assim por diante.

As opções a seguir têm suporte para `GetSockOpt` . O tipo identifica o tipo de dados endereçado por *lpOptionValue*. A opção TCP_NODELAY usa IPPROTO_TCP de nível; todas as outras opções usam SOL_SOCKET de nível.

|Valor|Type|Significado|
|-----------|----------|-------------|
|SO_ACCEPTCONN|BOOL|O soquete está ouvindo.|
|SO_BROADCAST|BOOL|O soquete está configurado para a transmissão de mensagens de difusão.|
|SO_DEBUG|BOOL|A depuração está habilitada.|
|SO_DONTLINGER|BOOL|Se for true, a opção SO_LINGER será desabilitada.|
|SO_DONTROUTE|BOOL|O roteamento está desabilitado.|
|SO_ERROR|**`int`**|Recupere o status de erro e desmarque.|
|SO_KEEPALIVE|BOOL|Os keep alives estão sendo enviados.|
|SO_LINGER|`struct LINGER`|Retorna as opções atuais remanescentes.|
|SO_OOBINLINE|BOOL|Os dados fora de banda estão sendo recebidos no fluxo de dados normal.|
|SO_RCVBUF|INT|Tamanho do buffer para receives.|
|SO_REUSEADDR|BOOL|O soquete pode ser associado a um endereço que já está em uso.|
|SO_SNDBUF|**`int`**|Tamanho do buffer para envios.|
|SO_TYPE|**`int`**|O tipo de soquete (por exemplo, SOCK_STREAM).|
|TCP_NODELAY|BOOL|Desabilita o algoritmo Nagle para união de envio.|

As opções do BSD (Berkeley Software Distribution) sem suporte para o `GetSockOpt` são:

|Valor|Type|Significado|
|-----------|----------|-------------|
|SO_RCVLOWAT|**`int`**|Receber marca d' água baixa.|
|SO_RCVTIMEO|**`int`**|Tempo limite de recebimento.|
|SO_SNDLOWAT|**`int`**|Enviar marca d' água baixa.|
|SO_SNDTIMEO|**`int`**|Tempo limite de envio.|
|IP_OPTIONS||Obter opções no cabeçalho IP.|
|TCP_MAXSEG|**`int`**|Obter tamanho máximo de segmento TCP.|

Chamar `GetSockOpt` com uma opção sem suporte resultará em um código de erro de WSAENOPROTOOPT sendo retornado de `GetLastError` .

## <a name="casyncsocketioctl"></a><a name="ioctl"></a>CAsyncSocket:: IOCtl

Chame essa função de membro para controlar o modo de um soquete.

```
BOOL IOCtl(
    long lCommand,
    DWORD* lpArgument);
```

### <a name="parameters"></a>parâmetros

*lCommand*<br/>
O comando a ser executado no soquete.

*lpArgument*<br/>
Um ponteiro para um parâmetro para *lCommand*.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEINVAL *lCommand* não é um comando válido, ou *lpArgument* não é um parâmetro aceitável para *lCommand*ou o comando não é aplicável ao tipo de soquete fornecido.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAENOTSOCK o descritor não é um soquete.

### <a name="remarks"></a>Comentários

Essa rotina pode ser usada em qualquer soquete em qualquer Estado. Ele é usado para obter ou recuperar os parâmetros operacionais associados ao soquete, independentemente do subsistema de comunicações e do protocolo. Há suporte para os seguintes comandos:

- FIONBIO habilitar ou desabilitar o modo de não bloqueio no soquete. O parâmetro *lpArgument* aponta para um `DWORD` , que é diferente de zero se o modo de não bloqueio for habilitado e zero se for para ser desabilitado. Se `AsyncSelect` tiver sido emitido em um soquete, qualquer tentativa de usar `IOCtl` para definir o soquete de volta para o modo de bloqueio falhará com WSAEINVAL. Para definir o soquete de volta para o modo de bloqueio e evitar o erro WSAEINVAL, um aplicativo deve primeiro ser desabilitado `AsyncSelect` chamando `AsyncSelect` com o parâmetro *Levent* igual a 0 e, em seguida, chamar `IOCtl` .

- FIONREAD determina o número máximo de bytes que podem ser lidos com uma `Receive` chamada desse soquete. O parâmetro *lpArgument* aponta para um `DWORD` no qual `IOCtl` armazena o resultado. Se esse soquete for do tipo SOCK_STREAM, FIONREAD retornará a quantidade total de dados que podem ser lidos em um único `Receive` ; normalmente, isso é o mesmo que a quantidade total de dados enfileirados no soquete. Se esse soquete for do tipo SOCK_DGRAM, FIONREAD retornará o tamanho do primeiro datagrama na fila no soquete.

- SIOCATMARK determinar se todos os dados fora de banda foram lidos. Isso se aplica somente a um soquete do tipo SOCK_STREAM que foi configurado para a recepção em linha de qualquer dado fora de banda (SO_OOBINLINE). Se nenhum dado fora de banda estiver aguardando para ser lido, a operação retornará zero. Caso contrário, ele retornará 0 e o próximo `Receive` ou o `ReceiveFrom` executado no soquete recuperará alguns ou todos os dados que antecedem a "marca"; o aplicativo deve usar a operação SIOCATMARK para determinar se os dados permanecem. Se houver dados normais que antecedem os dados "urgentes" (fora de banda), eles serão recebidos na ordem. (Observe que um `Receive` ou `ReceiveFrom` nunca vai misturar dados fora de banda e normais na mesma chamada.) O parâmetro *lpArgument* aponta para um `DWORD` no qual `IOCtl` armazena o resultado.

Essa função é um subconjunto do `ioctl()` , conforme usado em Berkeley Sockets. Em particular, não há nenhum comando que seja equivalente a FIOASYNC, enquanto SIOCATMARK é o único comando de nível de soquete com suporte.

## <a name="casyncsocketlisten"></a><a name="listen"></a>CAsyncSocket:: escutar

Chame essa função de membro para escutar solicitações de conexão de entrada.

```
BOOL Listen(int nConnectionBacklog = 5);
```

### <a name="parameters"></a>parâmetros

*nConnectionBacklog*<br/>
O comprimento máximo para o qual a fila de conexões pendentes pode crescer. O intervalo válido é de 1 a 5.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEADDRINUSE foi feita uma tentativa de escutar em um endereço em uso.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAEINVAL o soquete não foi associado `Bind` ou já está conectado.

- WSAEISCONN o soquete já está conectado.

- WSAEMFILE não há mais descritores de arquivo disponíveis.

- WSAENOBUFS Não há espaço de buffer disponível.

- WSAENOTSOCK o descritor não é um soquete.

- WSAEOPNOTSUPP o soquete referenciado não é de um tipo que ofereça suporte à `Listen` operação.

### <a name="remarks"></a>Comentários

Para aceitar conexões, o soquete é criado primeiro com o `Create` , uma lista de pendências para conexões de entrada é especificada com `Listen` o e, em seguida, as conexões são aceitas com o `Accept` . `Listen`aplica-se somente a soquetes que dão suporte a conexões, ou seja, as do tipo SOCK_STREAM. Esse soquete é colocado no modo "passivo" em que as conexões de entrada são confirmadas e a aceitação pendente na fila pelo processo.

Essa função é normalmente usada por servidores (ou qualquer aplicativo que queira aceitar conexões) que poderiam ter mais de uma solicitação de conexão por vez: se uma solicitação de conexão chegar à fila cheia, o cliente receberá um erro com uma indicação de WSAECONNREFUSED.

`Listen`Tenta continuar a funcionar de modo racional quando não há portas disponíveis (descritores). Ele aceitará conexões até que a fila seja esvaziada. Se as portas forem disponibilizadas, uma chamada posterior para `Listen` ou `Accept` irá reabastecer a fila para a "pendência" atual ou mais recente, se possível, e retomar a escuta de conexões de entrada.

## <a name="casyncsocketm_hsocket"></a><a name="m_hsocket"></a>CAsyncSocket:: m_hSocket

Contém o identificador de soquete para o soquete encapsulado por esse `CAsyncSocket` objeto.

```
SOCKET m_hSocket;
```

## <a name="casyncsocketonaccept"></a><a name="onaccept"></a>CAsyncSocket:: OnAccept

Chamado pelo Framework para notificar um soquete de escuta de que ele pode aceitar solicitações de conexão pendentes chamando a função de membro [Accept](#accept) .

```
virtual void OnAccept(int nErrorCode);
```

### <a name="parameters"></a>parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam à `OnAccept` função de membro:

- **0** a função foi executada com êxito.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Windows Sockets: Socket Notifications](../../mfc/windows-sockets-socket-notifications.md).

## <a name="casyncsocketonclose"></a><a name="onclose"></a>CAsyncSocket:: fechamento

Chamado pelo Framework para notificar esse soquete de que o Soquete conectado está fechado por seu processo.

```
virtual void OnClose(int nErrorCode);
```

### <a name="parameters"></a>parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam à `OnClose` função de membro:

- **0** a função foi executada com êxito.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAECONNRESET a conexão foi redefinida pelo lado remoto.

- WSAECONNABORTED a conexão foi anulada devido a tempo limite ou outra falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Windows Sockets: Socket Notifications](../../mfc/windows-sockets-socket-notifications.md).

## <a name="casyncsocketonconnect"></a><a name="onconnect"></a>CAsyncSocket:: OnConnect

Chamado pelo Framework para notificar esse soquete de conexão de que sua tentativa de conexão foi concluída, seja com êxito ou com erro.

```
virtual void OnConnect(int nErrorCode);
```

### <a name="parameters"></a>parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam à `OnConnect` função de membro:

- **0** a função foi executada com êxito.

- WSAEADDRINUSE o endereço especificado já está em uso.

- WSAEADDRNOTAVAIL o endereço especificado não está disponível no computador local.

- Os endereços WSAEAFNOSUPPORT na família especificada não podem ser usados com este Soquete.

- WSAECONNREFUSED a tentativa de conexão foi rejeitada de modo forçado.

- WSAEDESTADDRREQ um endereço de destino é necessário.

- WSAEFAULT o argumento *lpSockAddrLen* está incorreto.

- WSAEINVAL o soquete já está associado a um endereço.

- WSAEISCONN o soquete já está conectado.

- WSAEMFILE não há mais descritores de arquivo disponíveis.

- WSAENETUNREACH a rede não pode ser acessada neste host no momento.

- WSAENOBUFS Não há espaço de buffer disponível. O soquete não pode ser conectado.

- WSAENOTCONN o soquete não está conectado.

- WSAENOTSOCK o descritor é um arquivo, não um soquete.

- WSAETIMEDOUT a tentativa de conexão atingiu o tempo limite sem estabelecer uma conexão.

### <a name="remarks"></a>Comentários

> [!NOTE]
> No [CSocket](../../mfc/reference/csocket-class.md), a `OnConnect` função de notificação nunca é chamada. Para conexões, basta chamar `Connect` , que retornará quando a conexão for concluída (com êxito ou com erro). Como as notificações de conexão são tratadas é um detalhe de implementação do MFC.

Para obter mais informações, consulte [Windows Sockets: Socket Notifications](../../mfc/windows-sockets-socket-notifications.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAsyncSocket#1](../../mfc/reference/codesnippet/cpp/casyncsocket-class_1.cpp)]

## <a name="casyncsocketonoutofbanddata"></a><a name="onoutofbanddata"></a>CAsyncSocket::OnOutOfBandData

Chamado pelo Framework para notificar o soquete de recebimento de que o soquete de envio tem dados fora de banda a serem enviados.

```
virtual void OnOutOfBandData(int nErrorCode);
```

### <a name="parameters"></a>parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam à `OnOutOfBandData` função de membro:

- **0** a função foi executada com êxito.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

### <a name="remarks"></a>Comentários

Os dados fora de banda são um canal logicamente independente associado a cada par de soquetes conectados do tipo SOCK_STREAM. O canal geralmente é usado para enviar dados urgentes.

O MFC dá suporte a dados fora de banda, mas os usuários da classe não `CAsyncSocket` são incentivados a usá-los. A maneira mais fácil é criar um segundo soquete para passar esses dados. Para obter mais informações sobre dados fora de banda, consulte [Windows Sockets: Socket Notifications](../../mfc/windows-sockets-socket-notifications.md).

## <a name="casyncsocketonreceive"></a><a name="onreceive"></a>CAsyncSocket:: OnReceive

Chamado pelo Framework para notificar esse soquete de que há dados no buffer que podem ser recuperados chamando a `Receive` função de membro.

```
virtual void OnReceive(int nErrorCode);
```

### <a name="parameters"></a>parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam à `OnReceive` função de membro:

- **0** a função foi executada com êxito.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Windows Sockets: Socket Notifications](../../mfc/windows-sockets-socket-notifications.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAsyncSocket#2](../../mfc/reference/codesnippet/cpp/casyncsocket-class_2.cpp)]

## <a name="casyncsocketonsend"></a><a name="onsend"></a>CAsyncSocket:: OnSend

Chamado pelo Framework para notificar o soquete de que agora ele pode enviar dados chamando a `Send` função de membro.

```
virtual void OnSend(int nErrorCode);
```

### <a name="parameters"></a>parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam à `OnSend` função de membro:

- **0** a função foi executada com êxito.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Windows Sockets: Socket Notifications](../../mfc/windows-sockets-socket-notifications.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAsyncSocket#3](../../mfc/reference/codesnippet/cpp/casyncsocket-class_3.cpp)]

## <a name="casyncsocketoperator-"></a><a name="operator_eq"></a>CAsyncSocket:: Operator =

Atribui um novo valor a um `CAsyncSocket` objeto.

```cpp
void operator=(const CAsyncSocket& rSrc);
```

### <a name="parameters"></a>parâmetros

*rSrc*<br/>
Uma referência a um `CAsyncSocket` objeto existente.

### <a name="remarks"></a>Comentários

Chame essa função para copiar um `CAsyncSocket` objeto existente para outro `CAsyncSocket` objeto.

## <a name="casyncsocketoperator-socket"></a><a name="operator_socket"></a>SOQUETE CAsyncSocket:: Operator

Use esse operador para recuperar o identificador de soquete do `CAsyncSocket` objeto.

```
operator SOCKET() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, o identificador do objeto de soquete; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Você pode usar a alça para chamar as APIs do Windows diretamente.

## <a name="casyncsocketreceive"></a><a name="receive"></a>CAsyncSocket:: receber

Chame essa função de membro para receber dados de um soquete.

```
virtual int Receive(
    void* lpBuf,
    int nBufLen,
    int nFlags = 0);
```

### <a name="parameters"></a>parâmetros

*lpBuf*<br/>
Um buffer para os dados de entrada.

*nBufLen*<br/>
O comprimento de *lpBuf* em bytes.

*nFlags*<br/>
Especifica a maneira como a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e pelo parâmetro *nFlags* . O último é construído combinando qualquer um dos seguintes valores com o operador C++ **ou** :

- MSG_PEEK inspecionar os dados de entrada. Os dados são copiados para o buffer, mas não são removidos da fila de entrada.

- MSG_OOB processar dados fora de banda.

### <a name="return-value"></a>Valor retornado

Se nenhum erro ocorrer, `Receive` o retornará o número de bytes recebidos. Se a conexão tiver sido fechada, ela retornará 0. Caso contrário, um valor de SOCKET_ERROR será retornado e um código de erro específico poderá ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAENOTCONN o soquete não está conectado.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAENOTSOCK o descritor não é um soquete.

- WSAEOPNOTSUPP MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- WSAESHUTDOWN o soquete foi desligado; Não é possível chamar `Receive` em um Soquete depois que ele foi `ShutDown` invocado com *Nhow* definido como 0 ou 2.

- WSAEWOULDBLOCK o soquete está marcado como não bloqueado e a `Receive` operação seria bloqueada.

- WSAEMSGSIZE o datagrama era muito grande para caber no buffer especificado e foi truncado.

- WSAEINVAL o soquete não foi associado `Bind` .

- WSAECONNABORTED o circuito virtual foi anulado devido a tempo limite ou outra falha.

- WSAECONNRESET o circuito virtual foi redefinido pelo lado remoto.

### <a name="remarks"></a>Comentários

Essa função é usada para o fluxo conectado ou soquetes de datagrama e é usada para ler dados de entrada.

Para soquetes do tipo SOCK_STREAM, a quantidade de informações que está disponível atualmente até o tamanho do buffer fornecido é retornada. Se o soquete tiver sido configurado para a recepção embutida de dados fora de banda (opção de Soquete SO_OOBINLINE) e dados fora de banda forem não lidos, somente os dados fora de banda serão retornados. O aplicativo pode usar a `IOCtlSIOCATMARK` opção ou [OnOutOfBandData](#onoutofbanddata) para determinar se mais dados fora de banda continuam a ser lidos.

Para soquetes de datagramas, os dados são extraídos do primeiro datagrama enfileirado, até o tamanho do buffer fornecido. Se o datagrama for maior do que o buffer fornecido, o buffer será preenchido com a primeira parte do datagrama, os dados em excesso serão perdidos e `Receive` retornará um valor de SOCKET_ERROR com o código de erro definido como WSAEMSGSIZE. Se nenhum dado de entrada estiver disponível no soquete, um valor de SOCKET_ERROR será retornado com o código de erro definido como WSAEWOULDBLOCK. A função de retorno de chamada [OnReceive](#onreceive) pode ser usada para determinar quando mais dados chegam.

Se o soquete for do tipo SOCK_STREAM e o lado remoto desligar a conexão normalmente, um `Receive` será concluído imediatamente com 0 bytes recebidos. Se a conexão tiver sido redefinida, um `Receive` falhará com o erro WSAECONNRESET.

`Receive`deve ser chamado apenas uma vez para cada vez que [CAsyncSocket:: OnReceive](#onreceive) é chamado.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CAsyncSocket:: OnReceive](#onreceive).

## <a name="casyncsocketreceivefrom"></a><a name="receivefrom"></a>CAsyncSocket::ReceiveFrom

Chame essa função de membro para receber um datagrama e armazenar o endereço de origem na estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) ou em *rSocketAddress*.

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

### <a name="parameters"></a>parâmetros

*lpBuf*<br/>
Um buffer para os dados de entrada.

*nBufLen*<br/>
O comprimento de *lpBuf* em bytes.

*rSocketAddress*<br/>
Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.

*rSocketPort*<br/>
Referência a um UINT que armazena uma porta.

*lpSockAddr*<br/>
Um ponteiro para uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que contém o endereço de origem no retorno.

*lpSockAddrLen*<br/>
Um ponteiro para o comprimento do endereço de origem em *lpSockAddr* em bytes.

*nFlags*<br/>
Especifica a maneira como a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e pelo parâmetro *nFlags* . O último é construído combinando qualquer um dos seguintes valores com o operador C++ **ou** :

- MSG_PEEK inspecionar os dados de entrada. Os dados são copiados para o buffer, mas não são removidos da fila de entrada.

- MSG_OOB processar dados fora de banda.

### <a name="return-value"></a>Valor retornado

Se nenhum erro ocorrer, `ReceiveFrom` o retornará o número de bytes recebidos. Se a conexão tiver sido fechada, ela retornará 0. Caso contrário, um valor de SOCKET_ERROR será retornado e um código de erro específico poderá ser recuperado chamando `GetLastError` . Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT o argumento *lpSockAddrLen* era inválido: o buffer *lpSockAddr* era muito pequeno para acomodar o endereço de mesmo nível.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAEINVAL o soquete não foi associado `Bind` .

- WSAENOTCONN o soquete não está conectado (somente SOCK_STREAM).

- WSAENOTSOCK o descritor não é um soquete.

- WSAEOPNOTSUPP MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- WSAESHUTDOWN o soquete foi desligado; Não é possível chamar `ReceiveFrom` em um Soquete depois que ele foi `ShutDown` invocado com *Nhow* definido como 0 ou 2.

- WSAEWOULDBLOCK o soquete está marcado como não bloqueado e a `ReceiveFrom` operação seria bloqueada.

- WSAEMSGSIZE o datagrama era muito grande para caber no buffer especificado e foi truncado.

- WSAECONNABORTED o circuito virtual foi anulado devido a tempo limite ou outra falha.

- WSAECONNRESET o circuito virtual foi redefinido pelo lado remoto.

### <a name="remarks"></a>Comentários

Essa função é usada para ler dados de entrada em um soquete (possivelmente conectado) e capturar o endereço do qual os dados foram enviados.

Para manipular endereços IPv6, use [CAsyncSocket:: ReceiveFromEx](#receivefromex).

Para soquetes do tipo SOCK_STREAM, a quantidade de informações que está disponível atualmente até o tamanho do buffer fornecido é retornada. Se o soquete tiver sido configurado para a recepção embutida de dados fora de banda (opção de Soquete SO_OOBINLINE) e dados fora de banda forem não lidos, somente os dados fora de banda serão retornados. O aplicativo pode usar a `IOCtlSIOCATMARK` opção ou `OnOutOfBandData` para determinar se mais dados fora de banda continuam a ser lidos. Os parâmetros *lpSockAddr* e *lpSockAddrLen* são ignorados para soquetes de SOCK_STREAM.

Para soquetes de datagramas, os dados são extraídos do primeiro datagrama enfileirado, até o tamanho do buffer fornecido. Se o datagrama for maior do que o buffer fornecido, o buffer será preenchido com a primeira parte da mensagem, os dados em excesso serão perdidos e `ReceiveFrom` retornará um valor de SOCKET_ERROR com o código de erro definido como WSAEMSGSIZE.

Se *lpSockAddr* for diferente de zero e o soquete for do tipo SOCK_DGRAM, o endereço de rede do soquete que enviou os dados será copiado para a estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) correspondente. O valor apontado por *lpSockAddrLen* é inicializado com o tamanho dessa estrutura e é modificado no retorno para indicar o tamanho real do endereço armazenado lá. Se nenhum dado de entrada estiver disponível no soquete, a `ReceiveFrom` chamada aguardará que os dados cheguem, a menos que o soquete esteja sem bloqueio. Nesse caso, um valor de SOCKET_ERROR é retornado com o código de erro definido como WSAEWOULDBLOCK. O `OnReceive` retorno de chamada pode ser usado para determinar quando mais dados chegam.

Se o soquete for do tipo SOCK_STREAM e o lado remoto desligar a conexão normalmente, um `ReceiveFrom` será concluído imediatamente com 0 bytes recebidos.

## <a name="casyncsocketreceivefromex"></a><a name="receivefromex"></a>CAsyncSocket::ReceiveFromEx

Chame essa função de membro para receber um datagrama e armazenar o endereço de origem na estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) ou em *rSocketAddress* (manipula endereços IPv6).

```
int ReceiveFromEx(
    void* lpBuf,
    int nBufLen,
    CString& rSocketAddress,
    UINT& rSocketPort,
    int nFlags = 0);
```

### <a name="parameters"></a>parâmetros

*lpBuf*<br/>
Um buffer para os dados de entrada.

*nBufLen*<br/>
O comprimento de *lpBuf* em bytes.

*rSocketAddress*<br/>
Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.

*rSocketPort*<br/>
Referência a um UINT que armazena uma porta.

*nFlags*<br/>
Especifica a maneira como a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e pelo parâmetro *nFlags* . O último é construído combinando qualquer um dos seguintes valores com o operador C++ **ou** :

- MSG_PEEK inspecionar os dados de entrada. Os dados são copiados para o buffer, mas não são removidos da fila de entrada.

- MSG_OOB processar dados fora de banda.

### <a name="return-value"></a>Valor retornado

Se nenhum erro ocorrer, `ReceiveFromEx` o retornará o número de bytes recebidos. Se a conexão tiver sido fechada, ela retornará 0. Caso contrário, um valor de SOCKET_ERROR será retornado e um código de erro específico poderá ser recuperado chamando `GetLastError` . Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT o argumento *lpSockAddrLen* era inválido: o buffer *lpSockAddr* era muito pequeno para acomodar o endereço de mesmo nível.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAEINVAL o soquete não foi associado `Bind` .

- WSAENOTCONN o soquete não está conectado (somente SOCK_STREAM).

- WSAENOTSOCK o descritor não é um soquete.

- WSAEOPNOTSUPP MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- WSAESHUTDOWN o soquete foi desligado; Não é possível chamar `ReceiveFromEx` em um Soquete depois que ele foi `ShutDown` invocado com *Nhow* definido como 0 ou 2.

- WSAEWOULDBLOCK o soquete está marcado como não bloqueado e a `ReceiveFromEx` operação seria bloqueada.

- WSAEMSGSIZE o datagrama era muito grande para caber no buffer especificado e foi truncado.

- WSAECONNABORTED o circuito virtual foi anulado devido a tempo limite ou outra falha.

- WSAECONNRESET o circuito virtual foi redefinido pelo lado remoto.

### <a name="remarks"></a>Comentários

Essa função é usada para ler dados de entrada em um soquete (possivelmente conectado) e capturar o endereço do qual os dados foram enviados.

Essa função é igual a [CAsyncSocket:: ReceiveFrom](#receivefrom) , exceto pelo fato de que ela lida com endereços IPv6, bem como com protocolos mais antigos.

Para soquetes do tipo SOCK_STREAM, a quantidade de informações que está disponível atualmente até o tamanho do buffer fornecido é retornada. Se o soquete tiver sido configurado para a recepção embutida de dados fora de banda (opção de Soquete SO_OOBINLINE) e dados fora de banda forem não lidos, somente os dados fora de banda serão retornados. O aplicativo pode usar a `IOCtlSIOCATMARK` opção ou `OnOutOfBandData` para determinar se mais dados fora de banda continuam a ser lidos. Os parâmetros *lpSockAddr* e *lpSockAddrLen* são ignorados para soquetes de SOCK_STREAM.

Para soquetes de datagramas, os dados são extraídos do primeiro datagrama enfileirado, até o tamanho do buffer fornecido. Se o datagrama for maior do que o buffer fornecido, o buffer será preenchido com a primeira parte da mensagem, os dados em excesso serão perdidos e `ReceiveFromEx` retornará um valor de SOCKET_ERROR com o código de erro definido como WSAEMSGSIZE.

Se *lpSockAddr* for diferente de zero e o soquete for do tipo SOCK_DGRAM, o endereço de rede do soquete que enviou os dados será copiado para a estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) correspondente. O valor apontado por *lpSockAddrLen* é inicializado com o tamanho dessa estrutura e é modificado no retorno para indicar o tamanho real do endereço armazenado lá. Se nenhum dado de entrada estiver disponível no soquete, a `ReceiveFromEx` chamada aguardará que os dados cheguem, a menos que o soquete esteja sem bloqueio. Nesse caso, um valor de SOCKET_ERROR é retornado com o código de erro definido como WSAEWOULDBLOCK. O `OnReceive` retorno de chamada pode ser usado para determinar quando mais dados chegam.

Se o soquete for do tipo SOCK_STREAM e o lado remoto desligar a conexão normalmente, um `ReceiveFromEx` será concluído imediatamente com 0 bytes recebidos.

## <a name="casyncsocketsend"></a><a name="send"></a>CAsyncSocket:: enviar

Chame essa função de membro para enviar dados em um Soquete conectado.

```
virtual int Send(
    const void* lpBuf,
    int nBufLen,
    int nFlags = 0);
```

### <a name="parameters"></a>parâmetros

*lpBuf*<br/>
Um buffer que contém os dados a serem transmitidos.

*nBufLen*<br/>
O comprimento dos dados em *lpBuf* em bytes.

*nFlags*<br/>
Especifica a maneira como a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e pelo parâmetro *nFlags* . O último é construído combinando qualquer um dos seguintes valores com o operador C++ **ou** :

- MSG_DONTROUTE especifica que os dados não devem estar sujeitos ao roteamento. Um fornecedor do Windows Sockets pode optar por ignorar esse sinalizador.

- MSG_OOB enviar dados fora de banda (somente SOCK_STREAM).

### <a name="return-value"></a>Valor retornado

Se nenhum erro ocorrer, `Send` o retornará o número total de caracteres enviados. (Observe que isso pode ser menor que o número indicado por *nBufLen*.) Caso contrário, um valor de SOCKET_ERROR será retornado e um código de erro específico poderá ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEACCES o endereço solicitado é um endereço de difusão, mas o sinalizador apropriado não foi definido.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAEFAULT o argumento *lpBuf* não está em uma parte válida do espaço de endereço de usuário.

- WSAENETRESET a conexão deve ser redefinida porque a implementação do Windows Sockets o removeu.

- WSAENOBUFS a implementação do Windows Sockets relata um deadlock de buffer.

- WSAENOTCONN o soquete não está conectado.

- WSAENOTSOCK o descritor não é um soquete.

- WSAEOPNOTSUPP MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- WSAESHUTDOWN o soquete foi desligado; Não é possível chamar `Send` em um Soquete depois que ele foi `ShutDown` invocado com *Nhow* definido como 1 ou 2.

- WSAEWOULDBLOCK o soquete está marcado como não bloqueado e a operação solicitada será bloqueada.

- WSAEMSGSIZE o soquete é do tipo SOCK_DGRAM e o datagrama é maior do que o máximo suportado pela implementação do Windows Sockets.

- WSAEINVAL o soquete não foi associado `Bind` .

- WSAECONNABORTED o circuito virtual foi anulado devido a tempo limite ou outra falha.

- WSAECONNRESET o circuito virtual foi redefinido pelo lado remoto.

### <a name="remarks"></a>Comentários

`Send`é usado para gravar dados de saída no fluxo ou soquetes de datagramas conectados. Para soquetes de datagramas, deve-se ter cuidado para não exceder o tamanho máximo do pacote IP das sub-redes subjacentes, que é fornecido pelo `iMaxUdpDg` elemento na estrutura [WSADATA](/windows/win32/api/winsock2/ns-winsock2-wsadata) retornada por `AfxSocketInit` . Se os dados forem muito longos para serem passados atomicamente por meio do protocolo subjacente, o Erro WSAEMSGSIZE será retornado via `GetLastError` e nenhum dado será transmitido.

Observe que, para um soquete de datagrama, a conclusão bem-sucedida de a `Send` não indica que os dados foram entregues com êxito.

Em `CAsyncSocket` objetos do tipo SOCK_STREAM, o número de bytes gravados pode estar entre 1 e o comprimento solicitado, dependendo da disponibilidade do buffer nos hosts locais e estrangeiros.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CAsyncSocket:: OnSend](#onsend).

## <a name="casyncsocketsendto"></a><a name="sendto"></a>CAsyncSocket:: SendTo

Chame essa função de membro para enviar dados a um destino específico.

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

### <a name="parameters"></a>parâmetros

*lpBuf*<br/>
Um buffer que contém os dados a serem transmitidos.

*nBufLen*<br/>
O comprimento dos dados em *lpBuf* em bytes.

*nHostPort*<br/>
A porta que identifica o aplicativo de soquete.

*lpszHostAddress*<br/>
O endereço de rede do soquete ao qual este objeto está conectado: um nome de computador, como "ftp.microsoft.com", ou um número pontilhado, como "128.56.22.8".

*nFlags*<br/>
Especifica a maneira como a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e pelo parâmetro *nFlags* . O último é construído combinando qualquer um dos seguintes valores com o operador C++ **ou** :

- MSG_DONTROUTE especifica que os dados não devem estar sujeitos ao roteamento. Um fornecedor do Windows Sockets pode optar por ignorar esse sinalizador.

- MSG_OOB enviar dados fora de banda (somente SOCK_STREAM).

*lpSockAddr*<br/>
Um ponteiro para uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que contém o endereço do soquete de destino.

*nSockAddrLen*<br/>
O comprimento do endereço em *lpSockAddr* em bytes.

### <a name="return-value"></a>Valor retornado

Se nenhum erro ocorrer, `SendTo` o retornará o número total de caracteres enviados. (Observe que isso pode ser menor que o número indicado por *nBufLen*.) Caso contrário, um valor de SOCKET_ERROR será retornado e um código de erro específico poderá ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEACCES o endereço solicitado é um endereço de difusão, mas o sinalizador apropriado não foi definido.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAEFAULT os parâmetros *lpBuf* ou *lpSockAddr* não fazem parte do espaço de endereço de usuário ou o argumento *lpSockAddr* é muito pequeno (menor que o tamanho de uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) ).

- WSAEINVAL o nome do host é inválido.

- WSAENETRESET a conexão deve ser redefinida porque a implementação do Windows Sockets o removeu.

- WSAENOBUFS a implementação do Windows Sockets relata um deadlock de buffer.

- WSAENOTCONN o soquete não está conectado (somente SOCK_STREAM).

- WSAENOTSOCK o descritor não é um soquete.

- WSAEOPNOTSUPP MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- WSAESHUTDOWN o soquete foi desligado; Não é possível chamar `SendTo` em um Soquete depois que ele foi `ShutDown` invocado com *Nhow* definido como 1 ou 2.

- WSAEWOULDBLOCK o soquete está marcado como não bloqueado e a operação solicitada será bloqueada.

- WSAEMSGSIZE o soquete é do tipo SOCK_DGRAM e o datagrama é maior do que o máximo suportado pela implementação do Windows Sockets.

- WSAECONNABORTED o circuito virtual foi anulado devido a tempo limite ou outra falha.

- WSAECONNRESET o circuito virtual foi redefinido pelo lado remoto.

- WSAEADDRNOTAVAIL o endereço especificado não está disponível no computador local.

- Os endereços WSAEAFNOSUPPORT na família especificada não podem ser usados com este Soquete.

- WSAEDESTADDRREQ um endereço de destino é necessário.

- WSAENETUNREACH a rede não pode ser acessada neste host no momento.

### <a name="remarks"></a>Comentários

`SendTo`é usado em soquetes de datagrama ou fluxo e é usado para gravar dados de saída em um soquete. Para soquetes de datagramas, deve-se ter cuidado para não exceder o tamanho máximo do pacote IP das sub-redes subjacentes, que é fornecido pelo `iMaxUdpDg` elemento na estrutura [WSADATA](/windows/win32/api/winsock2/ns-winsock2-wsadata) preenchida por [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit). Se os dados forem muito longos para serem passados atomicamente por meio do protocolo subjacente, o Erro WSAEMSGSIZE será retornado e nenhum dado será transmitido.

Observe que a conclusão bem-sucedida de um não `SendTo` indica que os dados foram entregues com êxito.

`SendTo`é usado apenas em um soquete de SOCK_DGRAM para enviar um datagrama para um soquete específico identificado pelo parâmetro *lpSockAddr* .

Para enviar uma difusão (somente em um SOCK_DGRAM), o endereço no parâmetro *lpSockAddr* deve ser construído usando o endereço IP especial INADDR_BROADCAST (definido no arquivo de cabeçalho do Windows Sockets WINSOCK. H) junto com o número da porta pretendida. Ou, se o parâmetro *lpszHostAddress* for NULL, o Soquete será configurado para difusão. Geralmente, é inaconselhável que um datagrama de difusão exceda o tamanho no qual a fragmentação pode ocorrer, o que implica que a parte de dados do datagrama (excluindo cabeçalhos) não deve exceder 512 bytes.

Para manipular endereços IPv6, use [CAsyncSocket:: SendToEx](#sendtoex).

## <a name="casyncsocketsendtoex"></a><a name="sendtoex"></a>CAsyncSocket::SendToEx

Chame essa função de membro para enviar dados a um destino específico (manipula endereços IPv6).

```
int SendToEx(
    const void* lpBuf,
    int nBufLen,
    UINT nHostPort,
    LPCTSTR lpszHostAddress = NULL,
    int nFlags = 0);
```

### <a name="parameters"></a>parâmetros

*lpBuf*<br/>
Um buffer que contém os dados a serem transmitidos.

*nBufLen*<br/>
O comprimento dos dados em *lpBuf* em bytes.

*nHostPort*<br/>
A porta que identifica o aplicativo de soquete.

*lpszHostAddress*<br/>
O endereço de rede do soquete ao qual este objeto está conectado: um nome de computador, como "ftp.microsoft.com", ou um número pontilhado, como "128.56.22.8".

*nFlags*<br/>
Especifica a maneira como a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e pelo parâmetro *nFlags* . O último é construído combinando qualquer um dos seguintes valores com o operador C++ **ou** :

- MSG_DONTROUTE especifica que os dados não devem estar sujeitos ao roteamento. Um fornecedor do Windows Sockets pode optar por ignorar esse sinalizador.

- MSG_OOB enviar dados fora de banda (somente SOCK_STREAM).

### <a name="return-value"></a>Valor retornado

Se nenhum erro ocorrer, `SendToEx` o retornará o número total de caracteres enviados. (Observe que isso pode ser menor que o número indicado por *nBufLen*.) Caso contrário, um valor de SOCKET_ERROR será retornado e um código de erro específico poderá ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEACCES o endereço solicitado é um endereço de difusão, mas o sinalizador apropriado não foi definido.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAEFAULT os parâmetros *lpBuf* ou *lpSockAddr* não fazem parte do espaço de endereço de usuário ou o argumento *lpSockAddr* é muito pequeno (menor que o tamanho de uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) ).

- WSAEINVAL o nome do host é inválido.

- WSAENETRESET a conexão deve ser redefinida porque a implementação do Windows Sockets o removeu.

- WSAENOBUFS a implementação do Windows Sockets relata um deadlock de buffer.

- WSAENOTCONN o soquete não está conectado (somente SOCK_STREAM).

- WSAENOTSOCK o descritor não é um soquete.

- WSAEOPNOTSUPP MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- WSAESHUTDOWN o soquete foi desligado; Não é possível chamar `SendToEx` em um Soquete depois que ele foi `ShutDown` invocado com *Nhow* definido como 1 ou 2.

- WSAEWOULDBLOCK o soquete está marcado como não bloqueado e a operação solicitada será bloqueada.

- WSAEMSGSIZE o soquete é do tipo SOCK_DGRAM e o datagrama é maior do que o máximo suportado pela implementação do Windows Sockets.

- WSAECONNABORTED o circuito virtual foi anulado devido a tempo limite ou outra falha.

- WSAECONNRESET o circuito virtual foi redefinido pelo lado remoto.

- WSAEADDRNOTAVAIL o endereço especificado não está disponível no computador local.

- Os endereços WSAEAFNOSUPPORT na família especificada não podem ser usados com este Soquete.

- WSAEDESTADDRREQ um endereço de destino é necessário.

- WSAENETUNREACH a rede não pode ser acessada neste host no momento.

### <a name="remarks"></a>Comentários

Esse método é o mesmo que [CAsyncSocket:: SendTo](#sendto) , exceto pelo fato de ele tratar endereços IPv6, bem como protocolos mais antigos.

`SendToEx`é usado em soquetes de datagrama ou fluxo e é usado para gravar dados de saída em um soquete. Para soquetes de datagramas, deve-se ter cuidado para não exceder o tamanho máximo do pacote IP das sub-redes subjacentes, que é fornecido pelo `iMaxUdpDg` elemento na estrutura [WSADATA](/windows/win32/api/winsock2/ns-winsock2-wsadata) preenchida por [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit). Se os dados forem muito longos para serem passados atomicamente por meio do protocolo subjacente, o Erro WSAEMSGSIZE será retornado e nenhum dado será transmitido.

Observe que a conclusão bem-sucedida de um não `SendToEx` indica que os dados foram entregues com êxito.

`SendToEx`é usado apenas em um soquete de SOCK_DGRAM para enviar um datagrama para um soquete específico identificado pelo parâmetro *lpSockAddr* .

Para enviar uma difusão (somente em um SOCK_DGRAM), o endereço no parâmetro *lpSockAddr* deve ser construído usando o endereço IP especial INADDR_BROADCAST (definido no arquivo de cabeçalho do Windows Sockets WINSOCK. H) junto com o número da porta pretendida. Ou, se o parâmetro *lpszHostAddress* for NULL, o Soquete será configurado para difusão. Geralmente, é inaconselhável que um datagrama de difusão exceda o tamanho no qual a fragmentação pode ocorrer, o que implica que a parte de dados do datagrama (excluindo cabeçalhos) não deve exceder 512 bytes.

## <a name="casyncsocketsetsockopt"></a><a name="setsockopt"></a>CAsyncSocket::SetSockOpt

Chame essa função de membro para definir uma opção de soquete.

```
BOOL SetSockOpt(
    int nOptionName,
    const void* lpOptionValue,
    int nOptionLen,
    int nLevel = SOL_SOCKET);
```

### <a name="parameters"></a>parâmetros

*nOptionName*<br/>
A opção de soquete para a qual o valor deve ser definido.

*lpOptionValue*<br/>
Um ponteiro para o buffer no qual o valor da opção solicitada é fornecido.

*nOptionLen*<br/>
O tamanho do buffer *lpOptionValue* em bytes.

*nLevel*<br/>
O nível no qual a opção é definida; os únicos níveis com suporte são SOL_SOCKET e IPPROTO_TCP.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT *lpOptionValue* não está em uma parte válida do espaço de endereço do processo.

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAEINVAL *nLevel* não é válido ou as informações em *lpOptionValue* não são válidas.

- A conexão WSAENETRESET atingiu o tempo limite quando SO_KEEPALIVE está definida.

- WSAENOPROTOOPT a opção é desconhecida ou sem suporte. Em particular, não há suporte para SO_BROADCAST em soquetes do tipo SOCK_STREAM, enquanto SO_DONTLINGER, SO_KEEPALIVE, SO_LINGER e SO_OOBINLINE não têm suporte em soquetes do tipo SOCK_DGRAM.

- A conexão WSAENOTCONN foi redefinida quando SO_KEEPALIVE está definida.

- WSAENOTSOCK o descritor não é um soquete.

### <a name="remarks"></a>Comentários

`SetSockOpt`define o valor atual para uma opção de soquete associada a um soquete de qualquer tipo, em qualquer Estado. Embora as opções possam existir em vários níveis de protocolo, essa especificação só define opções que existem no nível de "soquete" superior. As opções afetam as operações de soquete, como se os dados acelerados são recebidos no fluxo de dados normal, se as mensagens de difusão podem ser enviadas no soquete e assim por diante.

Há dois tipos de opções de soquete: opções boolianas que habilitam ou desabilitam um recurso ou comportamento e opções que exigem um valor ou uma estrutura de número inteiro. Para habilitar uma opção booliana, *lpOptionValue* aponta para um número inteiro diferente de zero. Para desabilitar a opção *lpOptionValue* aponta para um número inteiro igual a zero. *nOptionLen* deve ser igual a `sizeof(BOOL)` para opções boolianas. Para outras opções, *lpOptionValue* aponta para o inteiro ou a estrutura que contém o valor desejado para a opção e *nOptionLen* é o comprimento do inteiro ou da estrutura.

SO_LINGER controla a ação tomada quando os dados não enviados são enfileirados em um soquete e a `Close` função é chamada para fechar o soquete.

Por padrão, um soquete não pode ser associado (consulte [associar](#bind)) a um endereço local que já está em uso. Na ocasião, no entanto, pode ser desejável "reutilizar" um endereço dessa maneira. Como cada conexão é identificada exclusivamente pela combinação de endereços locais e remotos, não há nenhum problema com a existência de dois soquetes associados ao mesmo endereço local, desde que os endereços remotos sejam diferentes.

Para informar a implementação do Windows Sockets de que uma `Bind` chamada em um soquete não deve ser permitida porque o endereço desejado já está em uso por outro soquete, o aplicativo deve definir a opção de soquete SO_REUSEADDR para o soquete antes de emitir a `Bind` chamada. Observe que a opção é interpretada somente no momento da `Bind` chamada: ela é, portanto, desnecessária (mas inofensiva) para definir a opção em um soquete que não deve ser associado a um endereço existente e definindo ou redefinindo a opção depois que a `Bind` chamada não tem nenhum efeito sobre este ou qualquer outro soquete.

Um aplicativo pode solicitar que a implementação do Windows Sockets habilite o uso de pacotes "Keep Alive" em conexões TCP, ativando a opção de soquete SO_KEEPALIVE. Uma implementação do Windows Sockets não precisa dar suporte ao uso de Keep-Alive: se tiver, a semântica precisa será específica da implementação, mas deverá estar em conformidade com a seção 4.2.3.6 da RFC 1122: "requisitos para hosts da Internet – camadas de comunicação". Se uma conexão for descartada como resultado de "keep-alives", o código de erro WSAENETRESET será retornado a todas as chamadas em andamento no soquete, e quaisquer chamadas subsequentes falharão com WSAENOTCONN.

A opção TCP_NODELAY desabilita o algoritmo Nagle. O algoritmo Nagle é usado para reduzir o número de pacotes pequenos enviados por um host, armazenando em buffer os dados de envio não confirmados até que um pacote de tamanho completo possa ser enviado. No entanto, para alguns aplicativos, esse algoritmo pode impedir o desempenho e TCP_NODELAY pode ser usado para desativá-lo. Os gravadores de aplicativo não devem definir TCP_NODELAY, a menos que o impacto disso seja bem compreendido e desejado, já que a configuração TCP_NODELAY pode ter um impacto negativo significativo no desempenho da rede. TCP_NODELAY é a única opção de soquete com suporte que usa o nível IPPROTO_TCP; todas as outras opções usam SOL_SOCKET de nível.

Algumas implementações do Windows Sockets fornecem informações de depuração de saída se a opção SO_DEBUG for definida por um aplicativo.

As opções a seguir têm suporte para `SetSockOpt` . O tipo identifica o tipo de dados endereçado por *lpOptionValue*.

|Valor|Type|Significado|
|-----------|----------|-------------|
|SO_BROADCAST|BOOL|Permitir a transmissão de mensagens de difusão no soquete.|
|SO_DEBUG|BOOL|Registre informações de depuração.|
|SO_DONTLINGER|BOOL|Não bloqueie `Close` a espera de envio de dados não enviados. Definir essa opção é equivalente a definir SO_LINGER com `l_onoff` definido como zero.|
|SO_DONTROUTE|BOOL|Não rotear: enviar diretamente para a interface.|
|SO_KEEPALIVE|BOOL|Enviar Keep Alive.|
|SO_LINGER|`struct LINGER`|Remanescente em `Close` se os dados não enviados estiverem presentes.|
|SO_OOBINLINE|BOOL|Receber dados fora de banda no fluxo de dados normal.|
|SO_RCVBUF|**`int`**|Especifique o tamanho do buffer para receives.|
|SO_REUSEADDR|BOOL|Permitir que o soquete seja associado a um endereço que já está em uso. (Consulte [ligar](#bind).)|
|SO_SNDBUF|**`int`**|Especifique o tamanho do buffer para envios.|
|TCP_NODELAY|BOOL|Desabilita o algoritmo Nagle para união de envio.|

As opções do BSD (Berkeley Software Distribution) sem suporte para o `SetSockOpt` são:

|Valor|Type|Significado|
|-----------|----------|-------------|
|SO_ACCEPTCONN|BOOL|O soquete está ouvindo|
|SO_ERROR|**`int`**|Obter status de erro e limpar.|
|SO_RCVLOWAT|**`int`**|Receber marca d' água baixa.|
|SO_RCVTIMEO|**`int`**|Tempo limite de recebimento|
|SO_SNDLOWAT|**`int`**|Enviar marca d' água baixa.|
|SO_SNDTIMEO|**`int`**|Tempo limite de envio.|
|SO_TYPE|**`int`**|Tipo do soquete.|
|IP_OPTIONS||Definir o campo de opções no cabeçalho IP.|

## <a name="casyncsocketshutdown"></a><a name="shutdown"></a>CAsyncSocket:: ShutDown

Chame essa função de membro para desabilitar envios, Recebimentos ou ambos no soquete.

```
BOOL ShutDown(int nHow = sends);
```

### <a name="parameters"></a>parâmetros

*nHow*<br/>
Um sinalizador que descreve quais tipos de operação não serão mais permitidos, usando os seguintes valores enumerados:

- **receives = 0**

- **envios = 1**

- **ambos = 2**

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a essa função de membro:

- WSANOTINITIALISED um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar essa API.

- WSAENETDOWN a implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEINVAL *Nhow* .

- WSAEINPROGRESS uma operação de bloqueio de soquetes do Windows em andamento.

- WSAENOTCONN o soquete não está conectado (somente SOCK_STREAM).

- WSAENOTSOCK o descritor não é um soquete.

### <a name="remarks"></a>Comentários

`ShutDown`é usado em todos os tipos de soquetes para desabilitar a recepção, a transmissão ou ambos. Se *Nhow* for 0, os recebimentos subsequentes no soquete não serão permitidos. Isso não tem nenhum efeito sobre as camadas de protocolo inferior.

Para o protocolo TCP, a janela TCP não é alterada e os dados de entrada serão aceitos (mas não confirmados) até que a janela seja esgotada. Para UDP (User Datagram Protocol), os datagramas de entrada são aceitos e enfileirados. Em nenhum caso, um pacote de erro ICMP será gerado. Se *Nhow* for 1, os envios subsequentes não serão permitidos. Para Soquetes TCP, um FIN será enviado. A definição de *Nhow* como 2 desabilita tanto o envio quanto o recebimento, conforme descrito acima.

Observe que `ShutDown` o não fecha o soquete, e os recursos anexados ao soquete não serão liberados até que `Close` seja chamado. Um aplicativo não deve depender de ser capaz de reutilizar um Soquete depois que ele tiver sido desligado. Em particular, uma implementação do Windows Sockets não é necessária para dar suporte ao uso do `Connect` em um soquete.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CAsyncSocket:: OnReceive](#onreceive).

## <a name="casyncsocketsocket"></a><a name="socket"></a>CASyncSocket:: Socket

Aloca um identificador de soquete.

```
BOOL Socket(
    int nSocketType = SOCK_STREAM,
    long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE,
    int nProtocolType = 0,
    int nAddressFormat = PF_INET);
```

### <a name="parameters"></a>parâmetros

*nSocketType*<br/>
Especifica `SOCK_STREAM` ou `SOCK_DGRAM` .

*lEvent*<br/>
Um bitmask que especifica uma combinação de eventos de rede em que o aplicativo está interessado.

- `FD_READ`: Deseja receber a notificação de prontidão para leitura.

- `FD_WRITE`: Deseja receber a notificação de preparação para gravação.

- `FD_OOB`: Deseja receber a notificação de chegada de dados fora de banda.

- `FD_ACCEPT`: Deseja receber a notificação de conexões de entrada.

- `FD_CONNECT`: Deseja receber a notificação de conexão concluída.

- `FD_CLOSE`: Deseja receber a notificação de fechamento do soquete.

*nProtocolType*<br/>
Protocolo a ser usado com o soquete específico para a família de endereços indicada.

*nAddressFormat*<br/>
Especificação da família de endereços.

### <a name="return-value"></a>Valor retornado

Retorna `TRUE` em caso de êxito, `FALSE` em caso de falha.

### <a name="remarks"></a>Comentários

Esse método aloca um identificador de soquete. Ele não chama [CAsyncSocket:: bind](#bind) para associar o soquete a um endereço especificado, portanto, você precisará chamar `Bind` posteriormente para associar o soquete a um endereço especificado. Você pode usar [CAsyncSocket:: setsockopt](#setsockopt) para definir a opção de soquete antes que ela seja associada.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CSocket](../../mfc/reference/csocket-class.md)<br/>
[Classe CSocketFile](../../mfc/reference/csocketfile-class.md)
