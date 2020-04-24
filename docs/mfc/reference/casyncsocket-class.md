---
title: Classe CAsyncSocket
ms.date: 09/03/2019
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
ms.openlocfilehash: e384be534bdbb355554c28383e9e214e9084f217
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753022"
---
# <a name="casyncsocket-class"></a>Classe CAsyncSocket

Representa um soquete do Windows — um ponto final da comunicação de rede.

## <a name="syntax"></a>Sintaxe

```
class CAsyncSocket : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CasyncSocket::CAsyncSocket](#casyncsocket)|Constrói um objeto `CAsyncSocket`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CasyncSocket::Aceitar](#accept)|Aceita uma conexão na tomada.|
|[CAsyncSocket::AsyncSelect](#asyncselect)|Solicita notificação de evento para o soquete.|
|[CasyncSocket::Anexar](#attach)|Anexa uma alça de `CAsyncSocket` soquete a um objeto.|
|[CasyncSocket::Bind](#bind)|Associa um endereço local com o soquete.|
|[CasyncSocket::Fechar](#close)|Fecha o soquete.|
|[CAsyncSocket::Conecte](#connect)|Estabelece uma conexão com um soquete de pares.|
|[CAsyncSocket::Criar](#create)|Cria um soquete.|
|[CAsyncSocket::Detach](#detach)|Destaca uma alça de `CAsyncSocket` soquete de um objeto.|
|[CasyncSocket::FromHandle](#fromhandle)|Retorna um ponteiro `CAsyncSocket` para um objeto, dada a alça do soquete.|
|[CasyncSocket::GetLastError](#getlasterror)|Obtém o status de erro da última operação que falhou.|
|[CasyncSocket::GetPeerName](#getpeername)|Obtém o endereço do soquete de ponto ao qual o soquete está conectado.|
|[CasyncSocket::GetPeerNameEx](#getpeernameex)|Obtém o endereço do soquete de ponto ao qual o soquete está conectado (manipula endereços IPv6).|
|[CasyncSocket::GetSockName](#getsockname)|Pega o nome local de um soquete.|
|[CasyncSocket::GetsockNameEx](#getsocknameex)|Obtém o nome local de um soquete (manipula endereços IPv6).|
|[CasyncSocket::GetSockopt](#getsockopt)|Recupera uma opção de soquete.|
|[CAsyncSocket::IOCtl](#ioctl)|Controla o modo do soquete.|
|[CAsyncSocket::Ouça](#listen)|Estabelece um soquete para ouvir solicitações de conexão recebidas.|
|[CAsyncSocket::Receber](#receive)|Recebe dados do soquete.|
|[CasyncSocket::ReceiveFrom](#receivefrom)|Recebe um datagrama e armazena o endereço de origem.|
|[CasyncSocket::ReceiveFromEx](#receivefromex)|Recebe um datagrama e armazena o endereço de origem (lida com endereços IPv6).|
|[CAsyncSocket::Enviar](#send)|Envia dados para um soquete conectado.|
|[CasyncSocket::Sendto](#sendto)|Envia dados para um destino específico.|
|[Casyncsocket::SendtoEx](#sendtoex)|Envia dados para um destino específico (lida com endereços IPv6).|
|[CasyncSocket::setSockopt](#setsockopt)|Define uma opção de soquete.|
|[CAsyncSocket::ShutDown](#shutdown)|Desabilita `Send` e/ou `Receive` chamadas na tomada.|
|[CASyncSocket::Socket](#socket)|Aloca uma alça de soquete.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CasyncSocket::OnAccept](#onaccept)|Notifica um soquete de escuta `Accept`que pode aceitar solicitações pendentes de conexão ligando .|
|[CasyncSocket::OnClose](#onclose)|Notifica um soquete que o soquete conectado a ele fechou.|
|[CasyncSocket:OnConnect](#onconnect)|Notifica um soquete de conexão de que a tentativa de conexão está completa, seja com sucesso ou em erro.|
|[CasyncSocket::OnOutOfBandData](#onoutofbanddata)|Notifica um soquete receptor de que há dados fora da banda a serem lidos na tomada, geralmente uma mensagem urgente.|
|[CasyncSocket::OnReceive](#onreceive)|Notifica um soquete de escuta de `Receive`que há dados a serem recuperados por chamada .|
|[CasyncSocket::OnSend](#onsend)|Notifica um soquete que `Send`ele pode enviar dados ligando .|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncSocket::operador =](#operator_eq)|Atribui um novo valor `CAsyncSocket` a um objeto.|
|[CAsyncSocket::socket do operador](#operator_socket)|Use este operador para recuperar `CAsyncSocket` a alça SOCKET do objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAsyncSocket::m_hSocket](#m_hsocket)|Indica a alça SOCKET `CAsyncSocket` presa a este objeto.|

## <a name="remarks"></a>Comentários

A `CAsyncSocket` classe encapsula a API funções do soquete do Windows, fornecendo uma abstração orientada a objetos para programadores que desejam usar soquetes do Windows em conjunto com o MFC.

Esta aula baseia-se na suposição de que você entende as comunicações de rede. Você é responsável por lidar com o bloqueio, as diferenças de ordem de byte e as conversões entre as strings MBCS (Multicode e Multibyte Character Set). Se você quiser uma interface mais conveniente que gerencie esses problemas para você, consulte [classe CSocket](../../mfc/reference/csocket-class.md).

Para usar `CAsyncSocket` um objeto, chame seu construtor e, em seguida, chame `SOCKET`a função [Criar](#create) para criar a alça do soquete subjacente (tipo), exceto em soquetes aceitos. Para um soquete do servidor ligue para a função [Ouvir](#listen) membro e para um soquete cliente ligue para a função [Conecte-se.](#connect) O soquete do servidor deve chamar a função [Aceitar](#accept) ao receber uma solicitação de conexão. Use as `CAsyncSocket` funções restantes para realizar comunicações entre tomadas. Após a conclusão, destrua o `CAsyncSocket` objeto se ele foi criado no monte; o destruidor chama automaticamente a função [Fechar.](#close) O tipo de dados SOCKET é descrito no artigo [Soquetes do Windows: Plano de fundo](../../mfc/windows-sockets-background.md).

> [!NOTE]
> Ao usar soquetes MFC em segmentos secundários em `AfxSocketInit` um aplicativo MFC estático ligado, você deve chamar em cada segmento que usa soquetes para inicializar as bibliotecas de soquetes. Por padrão, `AfxSocketInit` é chamado apenas no segmento principal.

Para obter mais informações, consulte [Soquetes do Windows: Usando classe CAsyncSocket](../../mfc/windows-sockets-using-class-casyncsocket.md) e artigos relacionados., bem como [API do Windows Sockets 2](/windows/win32/WinSock/windows-sockets-start-page-2).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CAsyncSocket`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxsock.h

## <a name="casyncsocketaccept"></a><a name="accept"></a>CasyncSocket::Aceitar

Ligue para esta função de membro para aceitar uma conexão em um soquete.

```
virtual BOOL Accept(
    CAsyncSocket& rConnectedSocket,
    SOCKADDR* lpSockAddr = NULL,
    int* lpSockAddrLen = NULL);
```

### <a name="parameters"></a>Parâmetros

*rConnectedSocket*<br/>
Uma referência que identifica um novo soquete disponível para conexão.

*Lpsockaddr*<br/>
Um ponteiro para uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que recebe o endereço do soquete de conexão, como é conhecido na rede. O formato exato do argumento *lpSockAddr* é determinado pela família de endereços estabelecida quando o soquete foi criado. Se *lpSockAddr* e/ou *lpSockAddrLen* forem iguais a NULL, então nenhuma informação sobre o endereço remoto do soquete aceito será devolvida.

*Lpsockaddrlen*<br/>
Um ponteiro para o comprimento do endereço em *lpSockAddr* em bytes. O *lpSockAddrLen* é um parâmetro de valor-resultado: ele deve inicialmente conter a quantidade de espaço apontado por *lpSockAddr*; no retorno, ele conterá o comprimento real (em bytes) do endereço retornado.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT O argumento *lpSockAddrLen* é muito pequeno (menor do que o tamanho de uma estrutura [SOCKADDR).](/windows/win32/winsock/sockaddr-2)

- WSAEINPROGRESS Uma chamada de soquetes do Windows de bloqueio está em andamento.

- O WSAEINVAL `Listen` não foi invocado antes de aceitar.

- WSAEMFILE A fila está vazia na entrada para aceitar e não há descritores disponíveis.

- WSAENOBUFS Não há espaço para buffer.

- WSAENOTSOCK O descritor não é um soquete.

- WSAEOPNOTSUPP O soquete referenciado não é um tipo que suporta serviço orientado à conexão.

- WSAEWOULDBLOCK O soquete está marcado como não-bloqueio e nenhuma conexão está presente para ser aceita.

### <a name="remarks"></a>Comentários

Essa rotina extrai a primeira conexão na fila de conexões pendentes, cria um novo soquete com as mesmas propriedades deste soquete e o conecta ao *rConnectedSocket*. Se não houver conexões pendentes na `Accept` fila, `GetLastError` retorna zero e retorna um erro. O soquete aceito *(rConnectedSocket)* não pode ser usado para aceitar mais conexões. O soquete original permanece aberto e ouvindo.

O argumento *lpSockAddr* é um parâmetro de resultado preenchido com o endereço do soquete de conexão, como é conhecido na camada de comunicações. `Accept`é usado com tipos de soquete baseados em conexão, como SOCK_STREAM.

## <a name="casyncsocketasyncselect"></a><a name="asyncselect"></a>CAsyncSocket::AsyncSelect

Ligue para esta função de membro para solicitar a notificação de evento para um soquete.

```
BOOL AsyncSelect(long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE);
```

### <a name="parameters"></a>Parâmetros

*Levent*<br/>
Uma máscara de bit que especifica uma combinação de eventos de rede nos quais o aplicativo está interessado.

- FD_READ Quer receber uma notificação de prontidão para leitura.

- FD_WRITE Deseja receber a notificação quando os dados estão disponíveis para serem lidos.

- FD_OOB Quer receber uma notificação da chegada de dados fora da banda.

- FD_ACCEPT Quer receber uma notificação de conexões recebidas.

- FD_CONNECT Quer receber a notificação dos resultados da conexão.

- FD_CLOSE Deseja receber uma notificação quando um soquete tiver sido fechado por um par.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEINVAL Indica que um dos parâmetros especificados era inválido.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

### <a name="remarks"></a>Comentários

Esta função é usada para especificar quais funções de notificação de retorno de chamada do MFC serão chamadas para o soquete. `AsyncSelect`define automaticamente este soquete para o modo de não bloqueio. Para obter mais informações, consulte o artigo [Soquetes do Windows: Notificações do soquete](../../mfc/windows-sockets-socket-notifications.md).

## <a name="casyncsocketattach"></a><a name="attach"></a>CasyncSocket::Anexar

Ligue esta função de membro para `CAsyncSocket` anexar a alça *hSocket* a um objeto.

```
BOOL Attach(
    SOCKET hSocket, long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE);
```

### <a name="parameters"></a>Parâmetros

*hSocket*<br/>
Contém uma alça em um soquete.

*Levent*<br/>
Uma máscara de bit que especifica uma combinação de eventos de rede nos quais o aplicativo está interessado.

- FD_READ Quer receber uma notificação de prontidão para leitura.

- FD_WRITE Deseja receber a notificação quando os dados estão disponíveis para serem lidos.

- FD_OOB Quer receber uma notificação da chegada de dados fora da banda.

- FD_ACCEPT Quer receber uma notificação de conexões recebidas.

- FD_CONNECT Quer receber a notificação dos resultados da conexão.

- FD_CLOSE Deseja receber uma notificação quando um soquete tiver sido fechado por um par.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida.

### <a name="remarks"></a>Comentários

A alça SOCKET é armazenada no membro [de dados m_hSocket](#m_hsocket) do objeto.

## <a name="casyncsocketbind"></a><a name="bind"></a>CasyncSocket::Bind

Ligue para esta função de membro para associar um endereço local com o soquete.

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
A porta que identifica a aplicação do soquete.

*lpszSocketAddress*<br/>
O endereço da rede, um número pontilhado como "128.56.22.8". Passar a seqüência NULL `CAsyncSocket` para este parâmetro indica que a instância deve ouvir a atividade do cliente em todas as interfaces de rede.

*Lpsockaddr*<br/>
Um ponteiro para uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que contém o endereço a ser atribuído a este soquete.

*nSockAddrlen*<br/>
O comprimento do endereço em *lpSockAddr* em bytes.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). A lista a seguir abrange alguns dos erros que podem ser devolvidos. Para obter uma lista completa, consulte [Códigos de erro do Soquete do Windows](/windows/win32/winsock/windows-sockets-error-codes-2).

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEADDRINUSE O endereço especificado já está em uso. (Consulte a opção de soquete SO_REUSEADDR em [SetSockOpt](#setsockopt).)

- WSAEFAULT O argumento *nSockAddrLen* é muito pequeno (menor do que o tamanho de uma estrutura [SOCKADDR).](/windows/win32/winsock/sockaddr-2)

- WSAEINPROGRESS Uma chamada de soquetes do Windows de bloqueio está em andamento.

- WSAEAFNOSUPPORT A família de endereços especificado não é suportada por esta porta.

- WSAEINVAL O soquete já está vinculado a um endereço.

- WSAENOBUFS Não há buffers suficientes disponíveis, muitas conexões.

- WSAENOTSOCK O descritor não é um soquete.

### <a name="remarks"></a>Comentários

Essa rotina é usada em um datagrama ou `Connect` `Listen` soquete de fluxo não conectados, antes de chamadas subseqüentes ou chamadas. Antes de aceitar solicitações de conexão, um soquete do servidor `Bind`de escuta deve selecionar um número de porta e torná-lo conhecido para soquetes do Windows chamando . `Bind`estabelece a associação local (endereço de host/número da porta) do soquete atribuindo um nome local a um soquete sem nome.

## <a name="casyncsocketcasyncsocket"></a><a name="casyncsocket"></a>CasyncSocket::CAsyncSocket

Constrói um objeto de soquete em branco.

```
CAsyncSocket();
```

### <a name="remarks"></a>Comentários

Depois de construir o objeto, `Create` você deve chamar sua função de membro para criar a estrutura de dados SOCKET e vincular seu endereço. (No lado do servidor de uma comunicação do Windows Sockets, `Accept` quando o soquete de escuta cria um soquete para usar na chamada, você não chama `Create` por esse soquete.)

## <a name="casyncsocketclose"></a><a name="close"></a>CasyncSocket::Fechar

Fecha o soquete.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Esta função libera o descritor do soquete para que outras referências a ele falhem com o erro WSAENOTSOCK. Se esta for a última referência ao soquete subjacente, as informações de nomeação associadas e os dados enfileirados serão descartados. O destruidor do objeto de soquete chama `Close` por você.

Para `CAsyncSocket`, mas `CSocket`não para , `Close` a semântica de são afetados pelas opções de soquete SO_LINGER e SO_DONTLINGER. Para obter mais informações, consulte a função `GetSockOpt`do membro .

## <a name="casyncsocketconnect"></a><a name="connect"></a>CAsyncSocket::Conecte

Ligue para esta função de membro para estabelecer uma conexão com um soquete de fluxo ou datagrama não conectado.

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
O endereço de rede do soquete ao qual este objeto está conectado: um nome de máquina como "ftp.microsoft.com", ou um número pontilhado como "128.56.22.8".

*nHostPort*<br/>
A porta que identifica a aplicação do soquete.

*Lpsockaddr*<br/>
Um ponteiro para uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que contém o endereço do soquete conectado.

*nSockAddrlen*<br/>
O comprimento do endereço em *lpSockAddr* em bytes.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Se isso indicar um código de erro do WSAEWOULDBLOCK e seu aplicativo estiver usando `OnConnect` os retornos de chamada superridicularizados, seu aplicativo receberá uma mensagem quando a operação de conexão estiver concluída. Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEADDRINUSE O endereço especificado já está em uso.

- WSAEINPROGRESS Uma chamada de soquetes do Windows de bloqueio está em andamento.

- WSAEADDRNOTAVAIL O endereço especificado não está disponível na máquina local.

- WSAEAFNOSUPPORT Os endereços na família especificada não podem ser usados com este soquete.

- WSAECONNREFUSED A tentativa de conexão foi rejeitada.

- WSAEDESTADDRREQ É necessário um endereço de destino.

- WSAEFAULT O argumento *nSockAddrLen* está incorreto.

- Endereço de host inválido wsaeinval.

- WSAEISCONN O soquete já está conectado.

- WSAEMFILE Não há mais descritores de arquivos disponíveis.

- WSAENETUNREACH A rede não pode ser alcançada a partir deste host neste momento.

- WSAENOBUFS Não há espaço para buffer. O soquete não pode ser conectado.

- WSAENOTSOCK O descritor não é um soquete.

- WSAETIMEDOUT Tente conectar o tempo esgotado sem estabelecer uma conexão.

- WSAEWOULDBLOCK O soquete está marcado como não bloqueador e a conexão não pode ser concluída imediatamente.

### <a name="remarks"></a>Comentários

Se o soquete estiver desvinculado, valores únicos serão atribuídos à associação local pelo sistema e o soquete será marcado como vinculado. Observe que se o campo de endereço da `Connect` estrutura de nome for todos zeros, retornará zero. Para obter informações de `GetLastError` erro estendidas, ligue para a função membro.

Para soquetes de fluxo (tipo SOCK_STREAM), uma conexão ativa é iniciada no host estrangeiro. Quando a chamada do soquete é concluída com sucesso, o soquete está pronto para enviar/receber dados.

Para um soquete de datagrama (tipo SOCK_DGRAM), um `Send` `Receive` destino padrão é definido, que será usado em chamadas e chamadas subseqüentes.

## <a name="casyncsocketcreate"></a><a name="create"></a>CAsyncSocket::Criar

Ligue `Create` para a função de membro depois de construir um objeto de soquete para criar o soquete do Windows e anexá-lo.

```
BOOL Create(
    UINT nSocketPort = 0,
    int nSocketType = SOCK_STREAM,
    long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE,
    LPCTSTR lpszSocketAddress = NULL);
```

### <a name="parameters"></a>Parâmetros

*nSocketPort*<br/>
Uma porta bem conhecida para ser usada com o soquete, ou 0 se você quiser que os Soquetes do Windows selecionem uma porta.

*nSocketType*<br/>
SOCK_STREAM ou SOCK_DGRAM.

*Levent*<br/>
Uma máscara de bit que especifica uma combinação de eventos de rede nos quais o aplicativo está interessado.

- FD_READ Quer receber uma notificação de prontidão para leitura.

- FD_WRITE Quer receber uma notificação de prontidão para escrever.

- FD_OOB Quer receber uma notificação da chegada de dados fora da banda.

- FD_ACCEPT Quer receber uma notificação de conexões recebidas.

- FD_CONNECT Deseja receber uma notificação de conexão concluída.

- FD_CLOSE Quer receber uma notificação de fechamento do soquete.

*lpszSockAddress*<br/>
Um ponteiro para uma seqüência contendo o endereço de rede do soquete conectado, um número pontilhado como "128.56.22.8". Passar a seqüência NULL `CAsyncSocket` para este parâmetro indica que a instância deve ouvir a atividade do cliente em todas as interfaces de rede.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEAFNOSUPPORT A família de endereços especificado não é suportada.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAEMFILE Não há mais descritores de arquivos disponíveis.

- WSAENOBUFS Não há espaço para buffer. O soquete não pode ser criado.

- WSAEPROTONOSUPPORT A porta especificada não é suportada.

- WSAEPROTOTYPE A porta especificada é o tipo errado para este soquete.

- WSAESOCKTNOSUPPORT O tipo de soquete especificado não é suportado nesta família de endereços.

### <a name="remarks"></a>Comentários

`Create`chama [Soquete](#socket) e, se for bem-sucedido, ele chama [Bind](#bind) para vincular o soquete ao endereço especificado. Os seguintes tipos de soquete são suportados:

- SOCK_STREAM Fornece fluxos de bytes seqüenciados, confiáveis, full-duplex e baseados em conexão. Usa o Protocolo de Controle de Transmissão (TCP) para a família de endereços da Internet.

- SOCK_DGRAM suporta datagramas, que são pacotes sem conexão e não confiáveis de um comprimento máximo fixo (tipicamente pequeno). Usa o Protocolo de Datagrama de Usuário (UDP) para a família de endereços da Internet.

    > [!NOTE]
    >  A `Accept` função membro tem como parâmetro `CSocket` uma referência a um objeto novo e vazio. Você deve construir este `Accept`objeto antes de chamar. Tenha em mente que se este objeto de soquete sair do escopo, a conexão se fecha. Não chame `Create` por este novo objeto de soquete.

> [!IMPORTANT]
> `Create`**não** é seguro para rosca.  Se você estiver chamando-o em um ambiente de várias linhas onde ele pode ser invocado simultaneamente por diferentes segmentos, certifique-se de proteger cada chamada com um mutex ou outro bloqueio de sincronização.

Para obter mais informações sobre soquetes de fluxo e datagram, consulte os artigos [Soquetes do Windows: Soquetes de fundo](../../mfc/windows-sockets-background.md) e [windows: Portas e Endereços de Soquete](../../mfc/windows-sockets-ports-and-socket-addresses.md) e [API do Windows Sockets 2](/windows/win32/WinSock/windows-sockets-start-page-2).

## <a name="casyncsocketdetach"></a><a name="detach"></a>CAsyncSocket::Detach

Chame esta função de membro para separar a alça `CAsyncSocket` SOCKET no *m_hSocket* membro de dados do objeto e definir *m_hSocket* para NULL.

```
SOCKET Detach();
```

## <a name="casyncsocketfromhandle"></a><a name="fromhandle"></a>CasyncSocket::FromHandle

Retorna um ponteiro `CAsyncSocket` para um objeto.

```
static CAsyncSocket* PASCAL FromHandle(SOCKET hSocket);
```

### <a name="parameters"></a>Parâmetros

*hSocket*<br/>
Contém uma alça em um soquete.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CAsyncSocket` para um objeto ou `CAsyncSocket` NULL se não houver nenhum objeto conectado ao *hSocket*.

### <a name="remarks"></a>Comentários

Quando dada uma alça `CAsyncSocket` SOCKET, se um objeto não estiver conectado à alça, a função do membro retorna NULL.

## <a name="casyncsocketgetlasterror"></a><a name="getlasterror"></a>CasyncSocket::GetLastError

Ligue para esta função de membro para obter o status de erro da última operação que falhou.

```
static int PASCAL GetLastError();
```

### <a name="return-value"></a>Valor retornado

O valor de retorno indica o código de erro da última rotina de API do Windows Sockets realizada por este segmento.

### <a name="remarks"></a>Comentários

Quando uma função de membro em particular `GetLastError` indicar que ocorreu um erro, deve ser chamada para recuperar o código de erro apropriado. Consulte as descrições da função de membro individual para obter uma lista de códigos de erro aplicáveis.

Para obter mais informações sobre os códigos de erro, consulte [a API do Windows Sockets 2](/windows/win32/WinSock/windows-sockets-start-page-2).

## <a name="casyncsocketgetpeername"></a><a name="getpeername"></a>CasyncSocket::GetPeerName

Ligue para esta função de membro para obter o endereço do soquete de ponto ao qual este soquete está conectado.

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
Faça referência `CString` a um objeto que recebe um endereço IP de número pontilhado.

*rPeerPort*<br/>
Referência a um UINT que armazena uma porta.

*Lpsockaddr*<br/>
Um ponteiro para a estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que recebe o nome do soquete de pares.

*Lpsockaddrlen*<br/>
Um ponteiro para o comprimento do endereço em *lpSockAddr* em bytes. No retorno, o argumento *lpSockAddrLen* contém o tamanho real de *lpSockAddr* retornado em bytes.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT O argumento *lpSockAddrLen* não é grande o suficiente.

- WSAEINPROGRESS Uma chamada de soquetes do Windows de bloqueio está em andamento.

- WSAENOTCONN O soquete não está conectado.

- WSAENOTSOCK O descritor não é um soquete.

### <a name="remarks"></a>Comentários

Para lidar com endereços IPv6, use [CAsyncSocket::GetPeerNameEx](#getpeernameex).

## <a name="casyncsocketgetpeernameex"></a><a name="getpeernameex"></a>CasyncSocket::GetPeerNameEx

Ligue para esta função de membro para obter o endereço do soquete de ponto ao qual este soquete está conectado (manipula endereços IPv6).

```
BOOL GetPeerNameEx(
    CString& rPeerAddress,
    UINT& rPeerPort);
```

### <a name="parameters"></a>Parâmetros

*rPeerAddress*<br/>
Faça referência `CString` a um objeto que recebe um endereço IP de número pontilhado.

*rPeerPort*<br/>
Referência a um UINT que armazena uma porta.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT O argumento *lpSockAddrLen* não é grande o suficiente.

- WSAEINPROGRESS Uma chamada de soquetes do Windows de bloqueio está em andamento.

- WSAENOTCONN O soquete não está conectado.

- WSAENOTSOCK O descritor não é um soquete.

### <a name="remarks"></a>Comentários

Esta função é a mesma do [CAsyncSocket::GetPeerName,](#getpeername) exceto que ele lida com endereços IPv6, bem como protocolos mais antigos.

## <a name="casyncsocketgetsockname"></a><a name="getsockname"></a>CasyncSocket::GetSockName

Ligue para esta função de membro para obter o nome local de um soquete.

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
Faça referência `CString` a um objeto que recebe um endereço IP de número pontilhado.

*rSocketPort*<br/>
Referência a um UINT que armazena uma porta.

*Lpsockaddr*<br/>
Um ponteiro para uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que recebe o endereço do soquete.

*Lpsockaddrlen*<br/>
Um ponteiro para o comprimento do endereço em *lpSockAddr* em bytes.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT O argumento *lpSockAddrLen* não é grande o suficiente.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAENOTSOCK O descritor não é um soquete.

- WSAEINVAL O soquete não `Bind`foi vinculado a um endereço com .

### <a name="remarks"></a>Comentários

Esta chamada é especialmente `Connect` útil quando uma chamada `Bind` foi feita sem fazer uma primeira; esta chamada fornece o único meio pelo qual você pode determinar a associação local que foi definida pelo sistema.

Para lidar com endereços IPv6, use [CAsyncSocket::GetSockNameEx](#getsocknameex)

## <a name="casyncsocketgetsocknameex"></a><a name="getsocknameex"></a>CasyncSocket::GetsockNameEx

Ligue para esta função de membro para obter o nome local de um soquete (manipula endereços IPv6).

```
BOOL GetSockNameEx(
    CString& rSocketAddress,
    UINT& rSocketPort);
```

### <a name="parameters"></a>Parâmetros

*rSocketAddress*<br/>
Faça referência `CString` a um objeto que recebe um endereço IP de número pontilhado.

*rSocketPort*<br/>
Referência a um UINT que armazena uma porta.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT O argumento *lpSockAddrLen* não é grande o suficiente.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAENOTSOCK O descritor não é um soquete.

- WSAEINVAL O soquete não `Bind`foi vinculado a um endereço com .

### <a name="remarks"></a>Comentários

Esta chamada é a mesma do [CAsyncSocket::GetSockName,](#getsockname) exceto que lida com endereços IPv6, bem como protocolos mais antigos.

Esta chamada é especialmente `Connect` útil quando uma chamada `Bind` foi feita sem fazer uma primeira; esta chamada fornece o único meio pelo qual você pode determinar a associação local que foi definida pelo sistema.

## <a name="casyncsocketgetsockopt"></a><a name="getsockopt"></a>CasyncSocket::GetSockopt

Ligue para esta função de membro para recuperar uma opção de soquete.

```
BOOL GetSockOpt(
    int nOptionName,
    void* lpOptionValue,
    int* lpOptionLen,
    int nLevel = SOL_SOCKET);
```

### <a name="parameters"></a>Parâmetros

*nOpçãoNome*<br/>
A opção de soquete para a qual o valor deve ser recuperado.

*Lpoptionvalue*<br/>
Um ponteiro para o buffer no qual o valor para a opção solicitada deve ser devolvido. O valor associado à opção selecionada é devolvido no buffer *lpOptionValue*. O inteiro apontado por *lpOptionLen* deve originalmente conter o tamanho deste buffer em bytes; e no retorno, ele será definido para o tamanho do valor devolvido. Para SO_LINGER, este será o `LINGER` tamanho de uma estrutura; para todas as outras opções será do tamanho de um BOOL ou um **int,** dependendo da opção. Veja a lista de opções e seus tamanhos na seção Observações.

*lpOptionLen*<br/>
Um ponteiro para o tamanho do buffer *lpOptionValue* em bytes.

*nNível*<br/>
O nível em que a opção é definida; os únicos níveis suportados são SOL_SOCKET e IPPROTO_TCP.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Se uma opção nunca `SetSockOpt`foi `GetSockOpt` definida com , então retorna o valor padrão para a opção. Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT O argumento *lpOptionLen* era inválido.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAENOPROTOOPT A opção é desconhecida ou não suportada. Em particular, SO_BROADCAST não é suportado em tomadas de tipo SOCK_STREAM, enquanto SO_ACCEPTCONN, SO_DONTLINGER, SO_KEEPALIVE, SO_LINGER e SO_OOBINLINE não são suportados em tomadas de tipo SOCK_DGRAM.

- WSAENOTSOCK O descritor não é um soquete.

### <a name="remarks"></a>Comentários

`GetSockOpt`recupera o valor atual de uma opção de soquete associada a um soquete de qualquer tipo, em qualquer estado, e armazena o resultado em *lpOptionValue*. As opções afetam as operações de soquete, como o roteamento de pacotes, transferência de dados fora de banda e assim por diante.

As seguintes opções `GetSockOpt`são suportadas para . O Tipo identifica o tipo de dados endereçados pelo *lpOptionValue*. A opção TCP_NODELAY usa IPPROTO_TCP de nível; todas as outras opções usam nível SOL_SOCKET.

|Valor|Type|Significado|
|-----------|----------|-------------|
|SO_ACCEPTCONN|BOOL|O soquete está ouvindo.|
|So_broadcast|BOOL|O soquete está configurado para a transmissão de mensagens de transmissão.|
|SO_DEBUG|BOOL|A depuração está ativada.|
|So_dontlinger|BOOL|Se for verdade, a opção SO_LINGER está desativada.|
|SO_DONTROUTE|BOOL|O roteamento está desativado.|
|SO_ERROR|**int**|Recupere o status de erro e limpe.|
|So_keepalive|BOOL|Keep-alives estão sendo enviados.|
|So_linger|`struct LINGER`|Retorna as opções de permanência atuais.|
|So_oobinline|BOOL|Dados fora da banda estão sendo recebidos no fluxo de dados normal.|
|SO_RCVBUF|INT|Tamanho do buffer para receber.|
|So_reuseaddr|BOOL|O soquete pode ser ligado a um endereço que já está em uso.|
|SO_SNDBUF|**int**|Tamanho do buffer para envios.|
|SO_TYPE|**int**|O tipo do soquete (por exemplo, SOCK_STREAM).|
|Tcp_nodelay|BOOL|Desabilita o algoritmo Nagle para união de envio.|

As opções de Distribuição de Software `GetSockOpt` Berkeley (BSD) não suportadas são:

|Valor|Type|Significado|
|-----------|----------|-------------|
|SO_RCVLOWAT|**int**|Receba baixa marca d'água.|
|SO_RCVTIMEO|**int**|Receba tempo.|
|SO_SNDLOWAT|**int**|Mande uma marca d'água baixa.|
|SO_SNDTIMEO|**int**|Mande tempo.|
|IP_OPTIONS||Obtenha opções no cabeçalho IP.|
|TCP_MAXSEG|**int**|Obtenha o tamanho máximo do segmento TCP.|

A `GetSockOpt` chamada com uma opção não suportada resultará no retorno de `GetLastError`um código de erro do WSAENOPROTOOPT .

## <a name="casyncsocketioctl"></a><a name="ioctl"></a>CAsyncSocket::IOCtl

Chame esta função de membro para controlar o modo de um soquete.

```
BOOL IOCtl(
    long lCommand,
    DWORD* lpArgument);
```

### <a name="parameters"></a>Parâmetros

*lComando*<br/>
O comando para executar na tomada.

*lpArgument*<br/>
Um ponteiro para um parâmetro para *lCommand*.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEINVAL *lCommand* não é um comando válido, ou *lpArgument* não é um parâmetro aceitável para *lCommand,* ou o comando não é aplicável ao tipo de soquete fornecido.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAENOTSOCK O descritor não é um soquete.

### <a name="remarks"></a>Comentários

Esta rotina pode ser usada em qualquer tomada em qualquer estado. É usado para obter ou recuperar parâmetros operacionais associados ao soquete, independente do subsistema de protocolo e comunicações. Há suporte para os seguintes comandos:

- FIONBIO Habilite ou desative o modo de não bloqueio no soquete. O parâmetro *lpArgument* aponta `DWORD`para um , que não é zero se o modo de não bloqueio for ativado e zero se ele for desativado. Se `AsyncSelect` tiver sido emitido em um soquete, qualquer tentativa de uso `IOCtl` para definir o soquete de volta ao modo de bloqueio falhará com o WSAEINVAL. Para definir o soquete de volta ao modo de bloqueio e `AsyncSelect` evitar `AsyncSelect` o erro WSAEINVAL, `IOCtl`um aplicativo deve primeiro desativar chamando com o parâmetro *lEvent* igual a 0 e, em seguida, chamar .

- FIONREAD Determine o número máximo de bytes `Receive` que podem ser lidos com uma chamada deste soquete. O parâmetro *lpArgument* aponta `DWORD` para `IOCtl` uma em que armazena o resultado. Se este soquete for do tipo SOCK_STREAM, a FIONREAD `Receive`retorna a quantidade total de dados que podem ser lidos em um único ; isso é normalmente o mesmo que a quantidade total de dados enfileirados na tomada. Se este soquete for do tipo SOCK_DGRAM, fionread retorna o tamanho do primeiro datagrama enfileirado na tomada.

- SIOCATMARK Determine se todos os dados fora da banda foram lidos. Isso se aplica apenas a um soquete de tipo SOCK_STREAM que tenha sido configurado para recepção em linha de quaisquer dados fora de banda (SO_OOBINLINE). Se nenhum dado fora da banda estiver esperando para ser lido, a operação retorna sem zero. Caso contrário, ele retorna `Receive` 0, e o próximo ou `ReceiveFrom` executado no soquete recuperará alguns ou todos os dados anteriores à "marca"; o aplicativo deve usar a operação SIOCATMARK para determinar se algum dado permanece. Se houver dados normais que precedem os dados "urgentes" (fora de banda), eles serão recebidos em ordem. (Observe que `Receive` `ReceiveFrom` um ou nunca misturará dados fora da banda e normais na mesma chamada.) O parâmetro *lpArgument* aponta `DWORD` para `IOCtl` uma em que armazena o resultado.

Esta função é um `ioctl()` subconjunto de como usado em soquetes berkeley. Em particular, não há comando equivalente ao FIOASYNC, enquanto o SIOCATMARK é o único comando de nível de soquete que é suportado.

## <a name="casyncsocketlisten"></a><a name="listen"></a>CAsyncSocket::Ouça

Ligue para esta função de membro para ouvir solicitações de conexão recebidas.

```
BOOL Listen(int nConnectionBacklog = 5);
```

### <a name="parameters"></a>Parâmetros

*nConexãoBacklog*<br/>
O comprimento máximo para o qual a fila de conexões pendentes pode crescer. O intervalo válido é de 1 a 5.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEADDRINUSE Uma tentativa foi feita para ouvir um endereço em uso.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAEINVAL O soquete `Bind` não foi ligado ou já está conectado.

- WSAEISCONN O soquete já está conectado.

- WSAEMFILE Não há mais descritores de arquivos disponíveis.

- WSAENOBUFS Não há espaço para buffer.

- WSAENOTSOCK O descritor não é um soquete.

- WSAEOPNOTSUPP O soquete referenciado não `Listen` é de um tipo que suporta a operação.

### <a name="remarks"></a>Comentários

Para aceitar conexões, o soquete é criado primeiro com `Create`, `Listen`um backlog para conexões `Accept`de entrada é especificado com , e, em seguida, as conexões são aceitas com . `Listen`aplica-se apenas a soquetes que suportam conexões, ou seja, aquelas de tipo SOCK_STREAM. Este soquete é colocado no modo "passivo", onde as conexões recebidas são reconhecidas e enfileiradas até a aceitação pelo processo.

Essa função é normalmente usada por servidores (ou qualquer aplicativo que queira aceitar conexões) que podem ter mais de uma solicitação de conexão por vez: se uma solicitação de conexão chegar com a fila cheia, o cliente receberá um erro com uma indicação de WSAECONNREFUSED.

`Listen`tentativas de continuar a funcionar racionalmente quando não há portas disponíveis (descritores). Ele aceitará conexões até que a fila seja esvaziada. Se as portas estiverem disponíveis, uma chamada posterior `Listen` ou `Accept` recarregará a fila para o "backlog" atual ou mais recente, se possível, e retomará a escuta das conexões recebidas.

## <a name="casyncsocketm_hsocket"></a><a name="m_hsocket"></a>CAsyncSocket::m_hSocket

Contém a alça SOCKET para o `CAsyncSocket` soquete encapsulado por este objeto.

```
SOCKET m_hSocket;
```

## <a name="casyncsocketonaccept"></a><a name="onaccept"></a>CasyncSocket::OnAccept

Chamado pela estrutura para notificar um soquete de escuta que ele pode aceitar solicitações pendentes de conexão ligando para a função de membro [Aceitar.](#accept)

```
virtual void OnAccept(int nErrorCode);
```

### <a name="parameters"></a>Parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os seguintes códigos de `OnAccept` erro se aplicam à função membro:

- **0** A função foi executada com sucesso.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Soquetes do Windows: Notificações do soquete](../../mfc/windows-sockets-socket-notifications.md).

## <a name="casyncsocketonclose"></a><a name="onclose"></a>CasyncSocket::OnClose

Chamado pela estrutura para notificar este soquete que o soquete conectado está fechado pelo seu processo.

```
virtual void OnClose(int nErrorCode);
```

### <a name="parameters"></a>Parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os seguintes códigos `OnClose` de erro se aplicam à função membro:

- **0** A função foi executada com sucesso.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAECONNRESET A conexão foi redefinida pelo lado remoto.

- WSAECONNABORTED A conexão foi abortada devido ao tempo de intervalo ou outra falha.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Soquetes do Windows: Notificações do soquete](../../mfc/windows-sockets-socket-notifications.md).

## <a name="casyncsocketonconnect"></a><a name="onconnect"></a>CasyncSocket:OnConnect

Chamado pela estrutura para notificar este soquete de conexão que sua tentativa de conexão está concluída, seja com sucesso ou em erro.

```
virtual void OnConnect(int nErrorCode);
```

### <a name="parameters"></a>Parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os seguintes códigos `OnConnect` de erro se aplicam à função membro:

- **0** A função foi executada com sucesso.

- WSAEADDRINUSE O endereço especificado já está em uso.

- WSAEADDRNOTAVAIL O endereço especificado não está disponível na máquina local.

- WSAEAFNOSUPPORT Os endereços na família especificada não podem ser usados com este soquete.

- WSAECONNREFUSED A tentativa de conexão foi rejeitada com força.

- WSAEDESTADDRREQ É necessário um endereço de destino.

- WSAEFAULT O argumento *lpSockAddrLen* está incorreto.

- WSAEINVAL O soquete já está vinculado a um endereço.

- WSAEISCONN O soquete já está conectado.

- WSAEMFILE Não há mais descritores de arquivos disponíveis.

- WSAENETUNREACH A rede não pode ser alcançada a partir deste host neste momento.

- WSAENOBUFS Não há espaço para buffer. O soquete não pode ser conectado.

- WSAENOTCONN O soquete não está conectado.

- WSAENOTSOCK O descritor é um arquivo, não um soquete.

- WSAETIMEDOUT A tentativa de conectar o tempo está fora sem estabelecer uma conexão.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Em [CSocket,](../../mfc/reference/csocket-class.md)a `OnConnect` função de notificação nunca é chamada. Para conexões, basta `Connect`ligar, que retornará quando a conexão estiver concluída (com sucesso ou erro). Como as notificações de conexão são tratadas é um detalhe de implementação do MFC.

Para obter mais informações, consulte [Soquetes do Windows: Notificações do soquete](../../mfc/windows-sockets-socket-notifications.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAsyncSocket#1](../../mfc/reference/codesnippet/cpp/casyncsocket-class_1.cpp)]

## <a name="casyncsocketonoutofbanddata"></a><a name="onoutofbanddata"></a>CasyncSocket::OnOutOfBandData

Chamado pela estrutura para notificar o soquete receptor que o soquete de envio tem dados fora da banda para enviar.

```
virtual void OnOutOfBandData(int nErrorCode);
```

### <a name="parameters"></a>Parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os seguintes códigos `OnOutOfBandData` de erro se aplicam à função membro:

- **0** A função foi executada com sucesso.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

### <a name="remarks"></a>Comentários

Os dados fora de banda são um canal logicamente independente que está associado a cada par de soquetes conectados do tipo SOCK_STREAM. O canal é geralmente usado para enviar dados urgentes.

O MFC suporta dados fora de banda, `CAsyncSocket` mas os usuários de classe são desencorajados a usá-los. A maneira mais fácil é criar um segundo soquete para passar tais dados. Para obter mais informações sobre dados fora da banda, consulte [Soquetes do Windows: Notificações do soquete](../../mfc/windows-sockets-socket-notifications.md).

## <a name="casyncsocketonreceive"></a><a name="onreceive"></a>CasyncSocket::OnReceive

Chamado pela estrutura para notificar este soquete que há dados `Receive` no buffer que podem ser recuperados ligando para a função do membro.

```
virtual void OnReceive(int nErrorCode);
```

### <a name="parameters"></a>Parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os seguintes códigos `OnReceive` de erro se aplicam à função membro:

- **0** A função foi executada com sucesso.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Soquetes do Windows: Notificações do soquete](../../mfc/windows-sockets-socket-notifications.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAsyncSocket#2](../../mfc/reference/codesnippet/cpp/casyncsocket-class_2.cpp)]

## <a name="casyncsocketonsend"></a><a name="onsend"></a>CasyncSocket::OnSend

Chamado pela estrutura para notificar o soquete `Send` que agora pode enviar dados ligando para a função do membro.

```
virtual void OnSend(int nErrorCode);
```

### <a name="parameters"></a>Parâmetros

*nErrorCode*<br/>
O erro mais recente em um soquete. Os seguintes códigos `OnSend` de erro se aplicam à função membro:

- **0** A função foi executada com sucesso.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Soquetes do Windows: Notificações do soquete](../../mfc/windows-sockets-socket-notifications.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCAsyncSocket#3](../../mfc/reference/codesnippet/cpp/casyncsocket-class_3.cpp)]

## <a name="casyncsocketoperator-"></a><a name="operator_eq"></a>CAsyncSocket::operador =

Atribui um novo valor `CAsyncSocket` a um objeto.

```cpp
void operator=(const CAsyncSocket& rSrc);
```

### <a name="parameters"></a>Parâmetros

*Rsrc*<br/>
Uma referência a `CAsyncSocket` um objeto existente.

### <a name="remarks"></a>Comentários

Chame esta função para `CAsyncSocket` copiar um `CAsyncSocket` objeto existente para outro objeto.

## <a name="casyncsocketoperator-socket"></a><a name="operator_socket"></a>CAsyncSocket::socket do operador

Use este operador para recuperar `CAsyncSocket` a alça SOCKET do objeto.

```
operator SOCKET() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, a alça do objeto SOCKET; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Você pode usar a alça para chamar apis do Windows diretamente.

## <a name="casyncsocketreceive"></a><a name="receive"></a>CAsyncSocket::Receber

Ligue para esta função de membro para receber dados de um soquete.

```
virtual int Receive(
    void* lpBuf,
    int nBufLen,
    int nFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*Lpbuf*<br/>
Um buffer para os dados de entrada.

*nBufLen*<br/>
O comprimento de *lpBuf* em bytes.

*Nflags*<br/>
Especifica a forma como a chamada é feita. A semântica desta função é determinada pelas opções de soquete e pelo parâmetro *nFlags.* Este último é construído combinando qualquer um dos seguintes valores com o operador C++ **OR:**

- MSG_PEEK Espie os dados de entrada. Os dados são copiados para o buffer, mas não são removidos da fila de entrada.

- MSG_OOB processe dados fora da banda.

### <a name="return-value"></a>Valor retornado

Se não ocorrer `Receive` nenhum erro, retorna o número de bytes recebidos. Se a conexão foi fechada, ela retorna 0. Caso contrário, um valor de SOCKET_ERROR é devolvido e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAENOTCONN O soquete não está conectado.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAENOTSOCK O descritor não é um soquete.

- O wsaeopnotsupp MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- WSAESHUTDOWN O soquete foi desligado; não é possível `Receive` chamar um `ShutDown` soquete depois de ter sido invocado com *nHow* definido como 0 ou 2.

- WSAEWOULDBLOCK O soquete está `Receive` marcado como não bloqueado e a operação bloquearia.

- WSAEMSGSIZE O datagrama era muito grande para caber no buffer especificado e foi truncado.

- WSAEINVAL O soquete `Bind`não foi ligado a .

- WSAECONNABORTED O circuito virtual foi abortado devido ao tempo de intervalo ou outra falha.

- WSAECONNRESET O circuito virtual foi redefinido pelo lado remoto.

### <a name="remarks"></a>Comentários

Esta função é usada para soquetes de fluxo ou datagrama conectados e é usada para ler dados de entrada.

Para soquetes de tipo SOCK_STREAM, o máximo de informações que estão disponíveis atualmente até o tamanho do buffer fornecido é devolvido. Se o soquete tiver sido configurado para recepção em linha de dados fora de banda (opção de soquete SO_OOBINLINE) e dados fora da banda não forem lidos, somente dados fora da banda serão retornados. O aplicativo pode `IOCtlSIOCATMARK` usar a opção ou [OnOutOfBandData](#onoutofbanddata) para determinar se mais dados fora da banda ainda serão lidos.

Para soquetes de datagram, os dados são extraídos do primeiro datagram enfileirado, até o tamanho do buffer fornecido. Se o datagrama for maior que o buffer fornecido, o buffer será preenchido com a `Receive` primeira parte do datagrama, o excesso de dados será perdido e retorna um valor de SOCKET_ERROR com o código de erro definido para WSAEMSGSIZE. Se nenhum dado de entrada estiver disponível no soquete, um valor de SOCKET_ERROR é devolvido com o código de erro definido como WSAEWOULDBLOCK. A função [onReceive](#onreceive) de retorno de chamada pode ser usada para determinar quando mais dados chegam.

Se o soquete for de tipo SOCK_STREAM e o `Receive` lado remoto tiver desligado a conexão graciosamente, uma será completada imediatamente com 0 bytes recebidos. Se a conexão tiver `Receive` sido redefinida, uma falha com o erro WSAECONNRESET.

`Receive`deve ser chamado apenas uma vez para cada vez [que CAsyncSocket::OnReceive](#onreceive) é chamado.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CAsyncSocket::OnReceive](#onreceive).

## <a name="casyncsocketreceivefrom"></a><a name="receivefrom"></a>CasyncSocket::ReceiveFrom

Ligue para esta função de membro para receber um datagrama e armazenar o endereço de origem na estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) ou em *rSocketAddress*.

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

*Lpbuf*<br/>
Um buffer para os dados de entrada.

*nBufLen*<br/>
O comprimento de *lpBuf* em bytes.

*rSocketAddress*<br/>
Faça referência `CString` a um objeto que recebe um endereço IP de número pontilhado.

*rSocketPort*<br/>
Referência a um UINT que armazena uma porta.

*Lpsockaddr*<br/>
Um ponteiro para uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que contém o endereço de origem no retorno.

*Lpsockaddrlen*<br/>
Um ponteiro para o comprimento do endereço de origem em *lpSockAddr* em bytes.

*Nflags*<br/>
Especifica a forma como a chamada é feita. A semântica desta função é determinada pelas opções de soquete e pelo parâmetro *nFlags.* Este último é construído combinando qualquer um dos seguintes valores com o operador C++ **OR:**

- MSG_PEEK Espie os dados de entrada. Os dados são copiados para o buffer, mas não são removidos da fila de entrada.

- MSG_OOB processe dados fora da banda.

### <a name="return-value"></a>Valor retornado

Se não ocorrer `ReceiveFrom` nenhum erro, retorna o número de bytes recebidos. Se a conexão foi fechada, ela retorna 0. Caso contrário, um valor de SOCKET_ERROR é devolvido, e um `GetLastError`código de erro específico pode ser recuperado por chamada . Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT O argumento *lpSockAddrLen* era inválido: o buffer *lpSockAddr* era muito pequeno para acomodar o endereço de pares.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAEINVAL O soquete `Bind`não foi ligado a .

- WSAENOTCONN O soquete não está conectado ( apenas SOCK_STREAM).

- WSAENOTSOCK O descritor não é um soquete.

- O wsaeopnotsupp MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- WSAESHUTDOWN O soquete foi desligado; não é possível `ReceiveFrom` chamar um `ShutDown` soquete depois de ter sido invocado com *nHow* definido como 0 ou 2.

- WSAEWOULDBLOCK O soquete está `ReceiveFrom` marcado como não bloqueado e a operação bloquearia.

- WSAEMSGSIZE O datagrama era muito grande para caber no buffer especificado e foi truncado.

- WSAECONNABORTED O circuito virtual foi abortado devido ao tempo de intervalo ou outra falha.

- WSAECONNRESET O circuito virtual foi redefinido pelo lado remoto.

### <a name="remarks"></a>Comentários

Esta função é usada para ler dados de entrada em um soquete (possivelmente conectado) e capturar o endereço de onde os dados foram enviados.

Para lidar com endereços IPv6, use [CAsyncSocket::ReceiveFromEx](#receivefromex).

Para soquetes de tipo SOCK_STREAM, o máximo de informações que estão disponíveis atualmente até o tamanho do buffer fornecido é devolvido. Se o soquete tiver sido configurado para recepção em linha de dados fora de banda (opção de soquete SO_OOBINLINE) e dados fora da banda não forem lidos, somente dados fora da banda serão retornados. O aplicativo pode `IOCtlSIOCATMARK` usar `OnOutOfBandData` a opção ou determinar se mais dados fora da banda ainda serão lidos. Os parâmetros *lpSockAddr* e *lpSockAddrLen* são ignorados para soquetes SOCK_STREAM.

Para soquetes de datagram, os dados são extraídos do primeiro datagram enfileirado, até o tamanho do buffer fornecido. Se o datagrama for maior que o buffer fornecido, o buffer será preenchido com a `ReceiveFrom` primeira parte da mensagem, o excesso de dados será perdido e retorna um valor de SOCKET_ERROR com o código de erro definido para WSAEMSGSIZE.

Se *lpSockAddr* não for zero e o soquete for de tipo SOCK_DGRAM, o endereço de rede do soquete que enviou os dados será copiado para a estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) correspondente. O valor apontado por *lpSockAddrLen* é inicializado para o tamanho desta estrutura, e é modificado no retorno para indicar o tamanho real do endereço armazenado lá. Se não houver dados de entrada `ReceiveFrom` disponíveis na tomada, a chamada aguarda a chegada de dados, a menos que o soquete não esteja bloqueado. Neste caso, um valor de SOCKET_ERROR é devolvido com o código de erro definido como WSAEWOULDBLOCK. O `OnReceive` retorno de chamada pode ser usado para determinar quando mais dados chegam.

Se o soquete for de tipo SOCK_STREAM e o `ReceiveFrom` lado remoto tiver desligado a conexão graciosamente, uma será completada imediatamente com 0 bytes recebidos.

## <a name="casyncsocketreceivefromex"></a><a name="receivefromex"></a>CasyncSocket::ReceiveFromEx

Ligue para esta função de membro para receber um datagrama e armazenar o endereço de origem na estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) ou em *rSocketAddress* (lida com endereços IPv6).

```
int ReceiveFromEx(
    void* lpBuf,
    int nBufLen,
    CString& rSocketAddress,
    UINT& rSocketPort,
    int nFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*Lpbuf*<br/>
Um buffer para os dados de entrada.

*nBufLen*<br/>
O comprimento de *lpBuf* em bytes.

*rSocketAddress*<br/>
Faça referência `CString` a um objeto que recebe um endereço IP de número pontilhado.

*rSocketPort*<br/>
Referência a um UINT que armazena uma porta.

*Nflags*<br/>
Especifica a forma como a chamada é feita. A semântica desta função é determinada pelas opções de soquete e pelo parâmetro *nFlags.* Este último é construído combinando qualquer um dos seguintes valores com o operador C++ **OR:**

- MSG_PEEK Espie os dados de entrada. Os dados são copiados para o buffer, mas não são removidos da fila de entrada.

- MSG_OOB processe dados fora da banda.

### <a name="return-value"></a>Valor retornado

Se não ocorrer `ReceiveFromEx` nenhum erro, retorna o número de bytes recebidos. Se a conexão foi fechada, ela retorna 0. Caso contrário, um valor de SOCKET_ERROR é devolvido, e um `GetLastError`código de erro específico pode ser recuperado por chamada . Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT O argumento *lpSockAddrLen* era inválido: o buffer *lpSockAddr* era muito pequeno para acomodar o endereço de pares.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAEINVAL O soquete `Bind`não foi ligado a .

- WSAENOTCONN O soquete não está conectado ( apenas SOCK_STREAM).

- WSAENOTSOCK O descritor não é um soquete.

- O wsaeopnotsupp MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- WSAESHUTDOWN O soquete foi desligado; não é possível `ReceiveFromEx` chamar um `ShutDown` soquete depois de ter sido invocado com *nHow* definido como 0 ou 2.

- WSAEWOULDBLOCK O soquete está `ReceiveFromEx` marcado como não bloqueado e a operação bloquearia.

- WSAEMSGSIZE O datagrama era muito grande para caber no buffer especificado e foi truncado.

- WSAECONNABORTED O circuito virtual foi abortado devido ao tempo de intervalo ou outra falha.

- WSAECONNRESET O circuito virtual foi redefinido pelo lado remoto.

### <a name="remarks"></a>Comentários

Esta função é usada para ler dados de entrada em um soquete (possivelmente conectado) e capturar o endereço de onde os dados foram enviados.

Esta função é a mesma do [CAsyncSocket::ReceiveFrom,](#receivefrom) exceto que lida com endereços IPv6, bem como protocolos mais antigos.

Para soquetes de tipo SOCK_STREAM, o máximo de informações que estão disponíveis atualmente até o tamanho do buffer fornecido é devolvido. Se o soquete tiver sido configurado para recepção em linha de dados fora de banda (opção de soquete SO_OOBINLINE) e dados fora da banda não forem lidos, somente dados fora da banda serão retornados. O aplicativo pode `IOCtlSIOCATMARK` usar `OnOutOfBandData` a opção ou determinar se mais dados fora da banda ainda serão lidos. Os parâmetros *lpSockAddr* e *lpSockAddrLen* são ignorados para soquetes SOCK_STREAM.

Para soquetes de datagram, os dados são extraídos do primeiro datagram enfileirado, até o tamanho do buffer fornecido. Se o datagrama for maior que o buffer fornecido, o buffer será preenchido com a `ReceiveFromEx` primeira parte da mensagem, o excesso de dados será perdido e retorna um valor de SOCKET_ERROR com o código de erro definido para WSAEMSGSIZE.

Se *lpSockAddr* não for zero e o soquete for de tipo SOCK_DGRAM, o endereço de rede do soquete que enviou os dados será copiado para a estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) correspondente. O valor apontado por *lpSockAddrLen* é inicializado para o tamanho desta estrutura, e é modificado no retorno para indicar o tamanho real do endereço armazenado lá. Se não houver dados de entrada `ReceiveFromEx` disponíveis na tomada, a chamada aguarda a chegada de dados, a menos que o soquete não esteja bloqueado. Neste caso, um valor de SOCKET_ERROR é devolvido com o código de erro definido como WSAEWOULDBLOCK. O `OnReceive` retorno de chamada pode ser usado para determinar quando mais dados chegam.

Se o soquete for de tipo SOCK_STREAM e o `ReceiveFromEx` lado remoto tiver desligado a conexão graciosamente, uma será completada imediatamente com 0 bytes recebidos.

## <a name="casyncsocketsend"></a><a name="send"></a>CAsyncSocket::Enviar

Ligue para esta função de membro para enviar dados em um soquete conectado.

```
virtual int Send(
    const void* lpBuf,
    int nBufLen,
    int nFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*Lpbuf*<br/>
Um buffer contendo os dados a serem transmitidos.

*nBufLen*<br/>
A duração dos dados em *lpBuf* em bytes.

*Nflags*<br/>
Especifica a forma como a chamada é feita. A semântica desta função é determinada pelas opções de soquete e pelo parâmetro *nFlags.* Este último é construído combinando qualquer um dos seguintes valores com o operador C++ **OR:**

- MSG_DONTROUTE Especifica que os dados não devem estar sujeitos ao roteamento. Um fornecedor de Soquetes do Windows pode optar por ignorar essa bandeira.

- MSG_OOB Envie dados de fora da banda (somente SOCK_STREAM).

### <a name="return-value"></a>Valor retornado

Se não ocorrer `Send` nenhum erro, retorna o número total de caracteres enviados. (Observe que isso pode ser menor do que o número indicado por *nBufLen*.) Caso contrário, um valor de SOCKET_ERROR é devolvido e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEACCES O endereço solicitado é um endereço de transmissão, mas a bandeira apropriada não foi definida.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAEFAULT O argumento *lpBuf* não está em uma parte válida do espaço de endereço do usuário.

- WSAENETRESET A conexão deve ser redefinida porque a implementação do Windows Sockets a derrubou.

- WSAENOBUFS A implementação do Windows Sockets relata um impasse de buffer.

- WSAENOTCONN O soquete não está conectado.

- WSAENOTSOCK O descritor não é um soquete.

- O wsaeopnotsupp MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- WSAESHUTDOWN O soquete foi desligado; não é possível `Send` chamar um `ShutDown` soquete depois de ter sido invocado com *nHow* definido como 1 ou 2.

- WSAEWOULDBLOCK O soquete está marcado como não bloqueado e a operação solicitada seria bloqueada.

- WSAEMSGSIZE O soquete é de tipo SOCK_DGRAM, e o datagrama é maior do que o máximo suportado pela implementação do Windows Sockets.

- WSAEINVAL O soquete `Bind`não foi ligado a .

- WSAECONNABORTED O circuito virtual foi abortado devido ao tempo de intervalo ou outra falha.

- WSAECONNRESET O circuito virtual foi redefinido pelo lado remoto.

### <a name="remarks"></a>Comentários

`Send`é usado para escrever dados de saída em soquetes de fluxo conectado ou datagram. Para soquetes de datagram, deve-se tomar cuidado para não exceder o `iMaxUdpDg` tamanho máximo do pacote IP das `AfxSocketInit`sub-redes subjacentes, que é dado pelo elemento na estrutura [WSADATA](/windows/win32/api/winsock2/ns-winsock2-wsadata) retornado por . Se os dados forem muito longos para passar atomicamente através do protocolo subjacente, `GetLastError`o erro WSAEMSGSIZE é devolvido via , e nenhum dado é transmitido.

Observe que para um soquete `Send` de datagram a conclusão bem sucedida de um não indica que os dados foram entregues com sucesso.

Em `CAsyncSocket` objetos de tipo SOCK_STREAM, o número de bytes escritos pode ser entre 1 e o comprimento solicitado, dependendo da disponibilidade de buffer nos hosts locais e estrangeiros.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CAsyncSocket::OnSend](#onsend).

## <a name="casyncsocketsendto"></a><a name="sendto"></a>CasyncSocket::Sendto

Ligue para esta função de membro para enviar dados para um destino específico.

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

*Lpbuf*<br/>
Um buffer contendo os dados a serem transmitidos.

*nBufLen*<br/>
A duração dos dados em *lpBuf* em bytes.

*nHostPort*<br/>
A porta que identifica a aplicação do soquete.

*lpszHostAddress*<br/>
O endereço de rede do soquete ao qual este objeto está conectado: um nome de máquina como "ftp.microsoft.com", ou um número pontilhado como "128.56.22.8".

*Nflags*<br/>
Especifica a forma como a chamada é feita. A semântica desta função é determinada pelas opções de soquete e pelo parâmetro *nFlags.* Este último é construído combinando qualquer um dos seguintes valores com o operador C++ **OR:**

- MSG_DONTROUTE Especifica que os dados não devem estar sujeitos ao roteamento. Um fornecedor de Soquetes do Windows pode optar por ignorar essa bandeira.

- MSG_OOB Envie dados de fora da banda (somente SOCK_STREAM).

*Lpsockaddr*<br/>
Um ponteiro para uma estrutura [SOCKADDR](/windows/win32/winsock/sockaddr-2) que contém o endereço do soquete de destino.

*nSockAddrlen*<br/>
O comprimento do endereço em *lpSockAddr* em bytes.

### <a name="return-value"></a>Valor retornado

Se não ocorrer `SendTo` nenhum erro, retorna o número total de caracteres enviados. (Observe que isso pode ser menor do que o número indicado por *nBufLen*.) Caso contrário, um valor de SOCKET_ERROR é devolvido e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEACCES O endereço solicitado é um endereço de transmissão, mas a bandeira apropriada não foi definida.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAEFAULT Os parâmetros *lpBuf* ou *lpSockAddr* não fazem parte do espaço de endereço do usuário, ou o argumento *lpSockAddr* é muito pequeno (menor do que o tamanho de uma estrutura [SOCKADDR).](/windows/win32/winsock/sockaddr-2)

- WSAEINVAL O nome do host é inválido.

- WSAENETRESET A conexão deve ser redefinida porque a implementação do Windows Sockets a derrubou.

- WSAENOBUFS A implementação do Windows Sockets relata um impasse de buffer.

- WSAENOTCONN O soquete não está conectado (apenas SOCK_STREAM).

- WSAENOTSOCK O descritor não é um soquete.

- O wsaeopnotsupp MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- WSAESHUTDOWN O soquete foi desligado; não é possível `SendTo` chamar um `ShutDown` soquete depois de ter sido invocado com *nHow* definido como 1 ou 2.

- WSAEWOULDBLOCK O soquete está marcado como não bloqueado e a operação solicitada seria bloqueada.

- WSAEMSGSIZE O soquete é de tipo SOCK_DGRAM, e o datagrama é maior do que o máximo suportado pela implementação do Windows Sockets.

- WSAECONNABORTED O circuito virtual foi abortado devido ao tempo de intervalo ou outra falha.

- WSAECONNRESET O circuito virtual foi redefinido pelo lado remoto.

- WSAEADDRNOTAVAIL O endereço especificado não está disponível na máquina local.

- WSAEAFNOSUPPORT Os endereços na família especificada não podem ser usados com este soquete.

- WSAEDESTADDRREQ É necessário um endereço de destino.

- WSAENETUNREACH A rede não pode ser alcançada a partir deste host neste momento.

### <a name="remarks"></a>Comentários

`SendTo`é usado em datagram ou soquetes de fluxo e é usado para escrever dados de saída em um soquete. Para soquetes de datagram, deve-se tomar cuidado para não exceder o `iMaxUdpDg` tamanho máximo do pacote IP das sub-redes subjacentes, que é dado pelo elemento na estrutura [WSADATA](/windows/win32/api/winsock2/ns-winsock2-wsadata) preenchido pelo [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit). Se os dados forem muito longos para passar atomicamente através do protocolo subjacente, o erro WSAEMSGSIZE é devolvido e nenhum dado é transmitido.

Observe que a conclusão `SendTo` bem-sucedida de um não indica que os dados foram entregues com sucesso.

`SendTo`é usado apenas em um soquete SOCK_DGRAM para enviar um datagrama para um soquete específico identificado pelo parâmetro *lpSockAddr.*

Para enviar uma transmissão (apenas em SOCK_DGRAM), o endereço no parâmetro *lpSockAddr* deve ser construído usando o endereço IP especial INADDR_BROADCAST (definido no arquivo de cabeçalho do Windows Sockets WINSOCK. H) juntamente com o número de porta pretendido. Ou, se o parâmetro *lpszHostAddress* for NULL, o soquete será configurado para transmissão. É geralmente desaconselhável que um datagrama de transmissão exceda o tamanho em que a fragmentação pode ocorrer, o que implica que a parte de dados do datagram (excluindo cabeçalhos) não deve exceder 512 bytes.

Para lidar com endereços IPv6, use [CAsyncSocket::SendToEx](#sendtoex).

## <a name="casyncsocketsendtoex"></a><a name="sendtoex"></a>Casyncsocket::SendtoEx

Ligue para esta função de membro para enviar dados para um destino específico (lida com endereços IPv6).

```
int SendToEx(
    const void* lpBuf,
    int nBufLen,
    UINT nHostPort,
    LPCTSTR lpszHostAddress = NULL,
    int nFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*Lpbuf*<br/>
Um buffer contendo os dados a serem transmitidos.

*nBufLen*<br/>
A duração dos dados em *lpBuf* em bytes.

*nHostPort*<br/>
A porta que identifica a aplicação do soquete.

*lpszHostAddress*<br/>
O endereço de rede do soquete ao qual este objeto está conectado: um nome de máquina como "ftp.microsoft.com", ou um número pontilhado como "128.56.22.8".

*Nflags*<br/>
Especifica a forma como a chamada é feita. A semântica desta função é determinada pelas opções de soquete e pelo parâmetro *nFlags.* Este último é construído combinando qualquer um dos seguintes valores com o operador C++ **OR:**

- MSG_DONTROUTE Especifica que os dados não devem estar sujeitos ao roteamento. Um fornecedor de Soquetes do Windows pode optar por ignorar essa bandeira.

- MSG_OOB Envie dados de fora da banda (somente SOCK_STREAM).

### <a name="return-value"></a>Valor retornado

Se não ocorrer `SendToEx` nenhum erro, retorna o número total de caracteres enviados. (Observe que isso pode ser menor do que o número indicado por *nBufLen*.) Caso contrário, um valor de SOCKET_ERROR é devolvido e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEACCES O endereço solicitado é um endereço de transmissão, mas a bandeira apropriada não foi definida.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAEFAULT Os parâmetros *lpBuf* ou *lpSockAddr* não fazem parte do espaço de endereço do usuário, ou o argumento *lpSockAddr* é muito pequeno (menor do que o tamanho de uma estrutura [SOCKADDR).](/windows/win32/winsock/sockaddr-2)

- WSAEINVAL O nome do host é inválido.

- WSAENETRESET A conexão deve ser redefinida porque a implementação do Windows Sockets a derrubou.

- WSAENOBUFS A implementação do Windows Sockets relata um impasse de buffer.

- WSAENOTCONN O soquete não está conectado (apenas SOCK_STREAM).

- WSAENOTSOCK O descritor não é um soquete.

- O wsaeopnotsupp MSG_OOB foi especificado, mas o soquete não é do tipo SOCK_STREAM.

- WSAESHUTDOWN O soquete foi desligado; não é possível `SendToEx` chamar um `ShutDown` soquete depois de ter sido invocado com *nHow* definido como 1 ou 2.

- WSAEWOULDBLOCK O soquete está marcado como não bloqueado e a operação solicitada seria bloqueada.

- WSAEMSGSIZE O soquete é de tipo SOCK_DGRAM, e o datagrama é maior do que o máximo suportado pela implementação do Windows Sockets.

- WSAECONNABORTED O circuito virtual foi abortado devido ao tempo de intervalo ou outra falha.

- WSAECONNRESET O circuito virtual foi redefinido pelo lado remoto.

- WSAEADDRNOTAVAIL O endereço especificado não está disponível na máquina local.

- WSAEAFNOSUPPORT Os endereços na família especificada não podem ser usados com este soquete.

- WSAEDESTADDRREQ É necessário um endereço de destino.

- WSAENETUNREACH A rede não pode ser alcançada a partir deste host neste momento.

### <a name="remarks"></a>Comentários

Este método é o mesmo [que CAsyncSocket::SendTo,](#sendto) exceto que ele lida com endereços IPv6, bem como protocolos mais antigos.

`SendToEx`é usado em datagram ou soquetes de fluxo e é usado para escrever dados de saída em um soquete. Para soquetes de datagram, deve-se tomar cuidado para não exceder o `iMaxUdpDg` tamanho máximo do pacote IP das sub-redes subjacentes, que é dado pelo elemento na estrutura [WSADATA](/windows/win32/api/winsock2/ns-winsock2-wsadata) preenchido pelo [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit). Se os dados forem muito longos para passar atomicamente através do protocolo subjacente, o erro WSAEMSGSIZE é devolvido e nenhum dado é transmitido.

Observe que a conclusão `SendToEx` bem-sucedida de um não indica que os dados foram entregues com sucesso.

`SendToEx`é usado apenas em um soquete SOCK_DGRAM para enviar um datagrama para um soquete específico identificado pelo parâmetro *lpSockAddr.*

Para enviar uma transmissão (apenas em SOCK_DGRAM), o endereço no parâmetro *lpSockAddr* deve ser construído usando o endereço IP especial INADDR_BROADCAST (definido no arquivo de cabeçalho do Windows Sockets WINSOCK. H) juntamente com o número de porta pretendido. Ou, se o parâmetro *lpszHostAddress* for NULL, o soquete será configurado para transmissão. É geralmente desaconselhável que um datagrama de transmissão exceda o tamanho em que a fragmentação pode ocorrer, o que implica que a parte de dados do datagram (excluindo cabeçalhos) não deve exceder 512 bytes.

## <a name="casyncsocketsetsockopt"></a><a name="setsockopt"></a>CasyncSocket::setSockopt

Ligue para esta função de membro para definir uma opção de soquete.

```
BOOL SetSockOpt(
    int nOptionName,
    const void* lpOptionValue,
    int nOptionLen,
    int nLevel = SOL_SOCKET);
```

### <a name="parameters"></a>Parâmetros

*nOpçãoNome*<br/>
A opção de soquete para a qual o valor deve ser definido.

*Lpoptionvalue*<br/>
Um ponteiro para o buffer no qual o valor para a opção solicitada é fornecido.

*nOptionLen*<br/>
O tamanho do *buffer lpOptionValue* em bytes.

*nNível*<br/>
O nível em que a opção é definida; os únicos níveis suportados são SOL_SOCKET e IPPROTO_TCP.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEFAULT *lpOptionValue* não está em uma parte válida do espaço de endereço do processo.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAEINVAL *nLevel* não é válido ou as informações no *lpOptionValue* não são válidas.

- A conexão WSAENETRESET tem tempo cronometrado quando SO_KEEPALIVE está definida.

- WSAENOPROTOOPT A opção é desconhecida ou não suportada. Em particular, SO_BROADCAST não é suportado em tomadas de SOCK_STREAM tipo, enquanto SO_DONTLINGER, SO_KEEPALIVE, SO_LINGER e SO_OOBINLINE não são suportados em tomadas de tipo SOCK_DGRAM.

- A conexão WSAENOTCONN foi redefinida quando SO_KEEPALIVE estiver configurada.

- WSAENOTSOCK O descritor não é um soquete.

### <a name="remarks"></a>Comentários

`SetSockOpt`define o valor atual para uma opção de soquete associada a um soquete de qualquer tipo, em qualquer estado. Embora as opções possam existir em vários níveis de protocolo, essa especificação define apenas opções que existem no nível mais alto de "soquete". As opções afetam as operações do soquete, como se os dados acelerados são recebidos no fluxo de dados normal, se as mensagens de transmissão podem ser enviadas no soquete e assim por diante.

Existem dois tipos de opções de soquete: opções booleanas que ativam ou desativam um recurso ou comportamento, e opções que requerem um valor inteiro ou estrutura. Para habilitar uma opção Boolean, *lpOptionValue* aponta para um inteiro não zero. Para desativar a opção *lpOptionValue* aponta para um inteiro igual a zero. *nOptionLen* deve ser `sizeof(BOOL)` igual a opções booleanas. Para outras opções, *lpOptionValue* aponta para o inteiro ou estrutura que contém o valor desejado para a opção, e *nOptionLen* é o comprimento do inteiro ou estrutura.

SO_LINGER controla a ação tomada quando os dados não `Close` enviados estão na fila de uma tomada e a função é chamada para fechar o soquete.

Por padrão, um soquete não pode ser vinculado (ver [Bind](#bind)) a um endereço local que já está em uso. Às vezes, no entanto, pode ser desejável "reutilizar" um endereço desta forma. Uma vez que cada conexão é identificada exclusivamente pela combinação de endereços locais e remotos, não há problema em ter dois soquetes vinculados ao mesmo endereço local, desde que os endereços remotos sejam diferentes.

Para informar a implementação `Bind` do Soquete do Windows que uma chamada em um soquete não deve ser proibida porque o `Bind` endereço desejado já está em uso por outro soquete, o aplicativo deve definir a opção de soquete SO_REUSEADDR para o soquete antes de emitir a chamada. Observe que a opção é interpretada `Bind` apenas no momento da chamada: portanto, é desnecessário (mas inofensivo) definir a opção em um soquete `Bind` que não deve ser vinculado a um endereço existente, e definir ou redefinir a opção após a chamada não tem efeito sobre este ou qualquer outro soquete.

Um aplicativo pode solicitar que a implementação do Windows Sockets habilite o uso de pacotes "keep-alive" em conexões TCP (Transmission Control Protocol, protocolo de controle de transmissão) ativando a opção de soquete SO_KEEPALIVE. Uma implementação do Windows Sockets não precisa suportar o uso de keep-alives: se isso acontecer, a semântica precisa é específica da implementação, mas deve estar em conformidade com a seção 4.2.3.6 do RFC 1122: "Requisitos para hosts de Internet — Camadas de Comunicação". Se uma conexão for descartada como resultado de "keep-alives" o código de erro WSAENETRESET é retornado para quaisquer chamadas em andamento no soquete, e quaisquer chamadas subseqüentes falharão com o WSAENOTCONN.

A opção TCP_NODELAY desativa o algoritmo Nagle. O algoritmo Nagle é usado para reduzir o número de pequenos pacotes enviados por um host, bufferndo dados de envio não reconhecidos até que um pacote em tamanho real possa ser enviado. No entanto, para algumas aplicações este algoritmo pode impedir o desempenho, e TCP_NODELAY pode ser usado para desligá-lo. Os autores de aplicativos não devem definir TCP_NODELAY a menos que o impacto de fazê-lo seja bem compreendido e desejado, uma vez que definir TCP_NODELAY pode ter um impacto negativo significativo no desempenho da rede. TCP_NODELAY é a única opção de soquete suportado que usa IPPROTO_TCP de nível; todas as outras opções usam nível SOL_SOCKET.

Algumas implementações do Windows Sockets fornecem informações de saída se a opção SO_DEBUG for definida por um aplicativo.

As seguintes opções `SetSockOpt`são suportadas para . O Tipo identifica o tipo de dados endereçados pelo *lpOptionValue*.

|Valor|Type|Significado|
|-----------|----------|-------------|
|So_broadcast|BOOL|Permitir a transmissão de mensagens de transmissão na tomada.|
|SO_DEBUG|BOOL|Registre informações de depuração.|
|So_dontlinger|BOOL|Não bloqueie `Close` a espera por dados não enviados para serem enviados. Definir esta opção é equivalente `l_onoff` a definir SO_LINGER com definido como zero.|
|SO_DONTROUTE|BOOL|Não faça a rota: envie diretamente para a interface.|
|So_keepalive|BOOL|Mande keep-alives.|
|So_linger|`struct LINGER`|Demore `Close` se os dados não enviados estão presentes.|
|So_oobinline|BOOL|Receba dados fora da banda no fluxo de dados normal.|
|SO_RCVBUF|**int**|Especifique o tamanho do buffer para receber.|
|So_reuseaddr|BOOL|Permitir que o soquete seja ligado a um endereço que já esteja em uso. (Ver [Vincular](#bind).)|
|SO_SNDBUF|**int**|Especifique o tamanho do buffer para envios.|
|Tcp_nodelay|BOOL|Desabilita o algoritmo Nagle para união de envio.|

As opções de Distribuição de Software `SetSockOpt` Berkeley (BSD) não suportadas são:

|Valor|Type|Significado|
|-----------|----------|-------------|
|SO_ACCEPTCONN|BOOL|O soquete está ouvindo|
|SO_ERROR|**int**|Obter status de erro e limpar.|
|SO_RCVLOWAT|**int**|Receba baixa marca d'água.|
|SO_RCVTIMEO|**int**|Receba tempo de tempo|
|SO_SNDLOWAT|**int**|Mande uma marca d'água baixa.|
|SO_SNDTIMEO|**int**|Mande tempo.|
|SO_TYPE|**int**|Tipo do soquete.|
|IP_OPTIONS||Defina o campo de opções no cabeçalho IP.|

## <a name="casyncsocketshutdown"></a><a name="shutdown"></a>CAsyncSocket::ShutDown

Ligue para esta função de membro para desativar envios, recebedores ou ambos no soquete.

```
BOOL ShutDown(int nHow = sends);
```

### <a name="parameters"></a>Parâmetros

*Nhow*<br/>
Uma bandeira que descreve quais tipos de operação não serão mais permitidas, usando os seguintes valores enumerados:

- **recebe = 0**

- **sends = 1**

- **ambos = 2**

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os seguintes erros se aplicam a esta função de membro:

- WSANOTINITIALISED Um [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) bem-sucedido deve ocorrer antes de usar esta API.

- WSAENETDOWN A implementação do Windows Sockets detectou que o subsistema de rede falhou.

- WSAEINVAL *nHow* não é válido.

- WSAEINPROGRESS Uma operação de soquetes do Windows de bloqueio está em andamento.

- WSAENOTCONN O soquete não está conectado (apenas SOCK_STREAM).

- WSAENOTSOCK O descritor não é um soquete.

### <a name="remarks"></a>Comentários

`ShutDown`é usado em todos os tipos de tomadas para desativar a recepção, transmissão ou ambos. Se *nHow* for 0, os recebe-se subseqüentes no soquete serão proibidos. Isso não tem efeito nas camadas de protocolo inferiores.

Para o TCP (Transmission Control Protocol, protocolo de controle de transmissão), a janela TCP não é alterada e os dados de entrada serão aceitos (mas não reconhecidos) até que a janela esteja esgotada. Para o User Datagram Protocol (UDP), os datagramas de entrada são aceitos e enfileirados. Em nenhum caso será gerado um pacote de erro ICMP. Se *nHow* for 1, os envios subseqüentes serão proibidos. Para soquetes TCP, uma FIN será enviada. A configuração *nComo* a 2 desativa tanto os envios quanto os receba, conforme descrito acima.

Observe `ShutDown` que não fecha o soquete, e os `Close` recursos anexados ao soquete não serão liberados até que seja chamado. Um aplicativo não deve depender de ser capaz de reutilizar um soquete depois de ter sido desligado. Em particular, uma implementação do Windows Sockets `Connect` não é necessária para suportar o uso de tal soquete.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CAsyncSocket::OnReceive](#onreceive).

## <a name="casyncsocketsocket"></a><a name="socket"></a>CASyncSocket::Socket

Aloca uma alça de soquete.

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

*Levent*<br/>
Uma máscara de bit que especifica uma combinação de eventos de rede nos quais o aplicativo está interessado.

- `FD_READ`: Quer receber notificação de prontidão para leitura.

- `FD_WRITE`: Quer receber notificação de prontidão para redação.

- `FD_OOB`: Quer receber notificação da chegada de dados fora da banda.

- `FD_ACCEPT`: Quer receber notificação de conexões recebidas.

- `FD_CONNECT`: Deseja receber notificação de conexão completa.

- `FD_CLOSE`: Deseja receber notificação de fechamento do soquete.

*nProtocolType*<br/>
Protocolo a ser usado com o soquete específico para a família de endereço indicada.

*nFormato de endereço*<br/>
Dirija-se à especificação familiar.

### <a name="return-value"></a>Valor retornado

Retorna `TRUE` no `FALSE` sucesso, no fracasso.

### <a name="remarks"></a>Comentários

Este método aloca uma alça de soquete. Ele não chama [CAsyncSocket::Vincular](#bind) para vincular o soquete a `Bind` um endereço especificado, então você precisa ligar mais tarde para vincular o soquete a um endereço especificado. Você pode usar [CAsyncSocket::SetSockOpt](#setsockopt) para definir a opção de soquete antes que ela seja vinculada.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CSocket](../../mfc/reference/csocket-class.md)<br/>
[Classe CSocketFile](../../mfc/reference/csocketfile-class.md)
