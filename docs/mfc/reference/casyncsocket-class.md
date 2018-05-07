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
ms.openlocfilehash: 5eaefa40be2a6cf1d57326c2135d848fa08dbc87
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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
|[CAsyncSocket::Attach](#attach)|Anexa um identificador de soquete para uma `CAsyncSocket` objeto.|  
|[CAsyncSocket::Bind](#bind)|Associa um endereço local com o soquete.|  
|[CAsyncSocket::Close](#close)|Fecha o soquete.|  
|[CAsyncSocket::Connect](#connect)|Estabelece uma conexão a um soquete de ponto a ponto.|  
|[CAsyncSocket::Create](#create)|Cria um soquete.|  
|[CAsyncSocket::Detach](#detach)|Desanexa um identificador de soquete de um `CAsyncSocket` objeto.|  
|[CAsyncSocket::FromHandle](#fromhandle)|Retorna um ponteiro para um `CAsyncSocket` objeto, considerando um identificador de soquete.|  
|[CAsyncSocket::GetLastError](#getlasterror)|Obtém o status de erro para a última operação que falhou.|  
|[CAsyncSocket::GetPeerName](#getpeername)|Obtém o endereço de soquete de ponto a ponto para o qual o soquete está conectado.|  
|[CAsyncSocket::GetPeerNameEx](#getpeernameex)|Obtém o endereço de soquete de ponto a ponto para o qual o soquete está conectados (identificadores de endereços IPv6).|  
|[CAsyncSocket::GetSockName](#getsockname)|Obtém o nome do local para um soquete.|  
|[CAsyncSocket::GetSockNameEx](#getsocknameex)|Obtém o nome do local para um soquete (identificadores de endereços IPv6).|  
|[CAsyncSocket::GetSockOpt](#getsockopt)|Recupera uma opção de soquete.|  
|[CAsyncSocket::IOCtl](#ioctl)|Controla o modo do soquete.|  
|[CAsyncSocket::Listen](#listen)|Estabelece um soquete para escutar solicitações de conexão de entrada.|  
|[CAsyncSocket::Receive](#receive)|Recebe dados do soquete.|  
|[CAsyncSocket::ReceiveFrom](#receivefrom)|Recebe um datagrama e armazena o endereço de origem.|  
|[CAsyncSocket::ReceiveFromEx](#receivefromex)|Recebe um datagrama e armazena o endereço de origem (identificadores de endereços IPv6).|  
|[CAsyncSocket::Send](#send)|Envia dados para um soquete conectado.|  
|[CAsyncSocket::SendTo](#sendto)|Envia dados para um destino específico.|  
|[CAsyncSocket::SendToEx](#sendtoex)|Envia dados para um destino específico (identificadores de endereços IPv6).|  
|[CAsyncSocket::SetSockOpt](#setsockopt)|Define uma opção de soquete.|  
|[CAsyncSocket::ShutDown](#shutdown)|Desabilita **enviar** e/ou **Receive** chama no soquete.|  
|[CASyncSocket::Socket](#socket)|Aloca um identificador de soquete.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAsyncSocket::OnAccept](#onaccept)|Notifica um soquete de escuta que ele possa aceitar solicitações de conexão pendentes chamando **aceitar**.|  
|[CAsyncSocket::OnClose](#onclose)|Notifica um soquete que o soquete conectado a ela foi fechada.|  
|[CAsyncSocket::OnConnect](#onconnect)|Notifica um soquete de conexão que a tentativa de conexão foi concluída, se com êxito ou com erro.|  
|[CAsyncSocket::OnOutOfBandData](#onoutofbanddata)|Notifica um soquete de recebimento que há dados fora de banda a ser lido no soquete, geralmente uma mensagem urgente.|  
|[CAsyncSocket::OnReceive](#onreceive)|Notifica um soquete de escuta que há dados a serem recuperados chamando **Receive**.|  
|[CAsyncSocket::OnSend](#onsend)|Notifica um soquete de que ele pode enviar dados por meio da chamada **enviar**.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAsyncSocket::operator =](#operator_eq)|Atribui um novo valor para uma `CAsyncSocket` objeto.|  
|[CAsyncSocket::operator soquete](#operator_socket)|Use este operador para recuperar o **soquete** tratar do `CAsyncSocket` objeto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAsyncSocket::m_hSocket](#m_hsocket)|Indica o **soquete** identificador anexado a este `CAsyncSocket` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Classe `CAsyncSocket` encapsula a API de funções de soquete do Windows, fornecendo uma abstração orientada a objeto para os programadores que desejam usar o Windows Sockets em conjunto com MFC.  
  
 Essa classe é baseada na suposição de que você compreenda as comunicações de rede. Você é responsável pelo tratamento de bloqueio, diferenças de ordem de byte, e conversões entre Unicode e multibyte character defina cadeias de caracteres (MBCS). Se você quiser uma interface mais conveniente que gerencia esses problemas para você, consulte a classe [CSocket](../../mfc/reference/csocket-class.md).  
  
 Para usar um `CAsyncSocket` de objeto, chame o construtor, em seguida, chame o [criar](#create) função para criar o identificador de soquete subjacente (tipo `SOCKET`), exceto em soquetes aceitos. Para uma chamada de soquete do servidor de [escutar](#listen) função de membro e para uma chamada de soquete do cliente a [conectar](#connect) função de membro. O soquete de servidor deve chamar o [aceitar](#accept) função ao receber uma solicitação de conexão. Use o restante `CAsyncSocket` funções para executar as comunicações entre soquetes. Ao concluir, destruir o `CAsyncSocket` se ele foi criado no heap do objeto; o destrutor chama automaticamente o [fechar](#close) função. O `SOCKET` tipo de dados é descrito no artigo [Windows Sockets: plano de fundo](../../mfc/windows-sockets-background.md).  
  
> [!NOTE]
>  Ao usar soquetes MFC em threads secundários em um aplicativo MFC vinculado estaticamente, você deve chamar `AfxSocketInit` em cada thread que usa soquetes para inicializar as bibliotecas de soquete. Por padrão, `AfxSocketInit` é chamado somente no thread principal.  
  
 Para obter mais informações, consulte [Windows Sockets: usando classe CAsyncSocket](../../mfc/windows-sockets-using-class-casyncsocket.md) e artigos relacionados., bem como [API do Windows Sockets 2](http://msdn.microsoft.com/library/windows/desktop/ms740673).  
  
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
 `rConnectedSocket`  
 Uma referência de identificação de um novo soquete que está disponível para a conexão.  
  
 `lpSockAddr`  
 Um ponteiro para um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que recebe o endereço de conexão de soquete, como conhecido na rede. O formato exato do `lpSockAddr` argumento é determinado pela família de endereço estabelecida quando o soquete foi criado. Se `lpSockAddr` e/ou `lpSockAddrLen` são iguais a **nulo**, nenhuma informação sobre o endereço remoto do soquete aceito será retornado.  
  
 `lpSockAddrLen`  
 Um ponteiro para o comprimento do endereço no `lpSockAddr` em bytes. O `lpSockAddrLen` é um parâmetro de valor de resultado: inicialmente, ela deve conter a quantidade de espaço apontada pelo `lpSockAddr`; no retorno, ela conterá o comprimento real (em bytes) do endereço retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEFAULT** o `lpSockAddrLen` argumento é muito pequeno (menor que o tamanho de um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura).  
  
- **WSAEINPROGRESS** uma chamada de bloqueio do Windows Sockets está em andamento.  
  
- **WSAEINVAL** `Listen` não foi chamado antes de aceitar.  
  
- **WSAEMFILE** a fila está vazia na entrada para aceitar e não há nenhum descritor disponíveis.  
  
- `WSAENOBUFS` Nenhum espaço de buffer está disponível.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
- **WSAEOPNOTSUPP** o soquete referenciado não é um tipo que oferece suporte ao serviço orientado a conexão.  
  
- **WSAEWOULDBLOCK** o soquete está marcado como não bloqueadas e nenhuma conexão estiver presente para serem aceitos.  
  
### <a name="remarks"></a>Comentários  
 Esta rotina extrai a primeira conexão na fila de conexões pendentes, cria um novo soquete com as mesmas propriedades que este soquete e anexa-o para `rConnectedSocket`. Não se houver nenhuma conexão pendente na fila, **aceitar** retorna zero e `GetLastError` retornará um erro. O soquete aceito ( *rConnectedSocket)* não pode ser usado para aceitar mais conexões. O soquete original permanece aberta e está ouvindo.  
  
 O argumento `lpSockAddr` é um parâmetro de resultado que é preenchido com o endereço de soquete de conexão como conhecidos para a camada de comunicações. **Aceitar** é usado com tipos de soquete com base em conexão como **SOCK_STREAM**.  
  
##  <a name="asyncselect"></a>  CAsyncSocket::AsyncSelect  
 Chame essa função de membro para solicitar a notificação de eventos para um soquete.  
  
```  
BOOL AsyncSelect(long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lEvent`  
 Um bitmask que especifica uma combinação de eventos de rede no qual o aplicativo está interessado.  
  
- **FD_READ** para receber notificação da preparação para leitura.  
  
- **FD_WRITE** para receber notificação quando os dados estão disponíveis para serem lidos.  
  
- **FD_OOB** para receber a notificação de chegada de dados fora de banda.  
  
- **FD_ACCEPT** para receber a notificação de conexões de entrada.  
  
- **FD_CONNECT** para receber a notificação de resultados de conexão.  
  
- **FD_CLOSE** para receber notificação quando um soquete foi fechado por um colega.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEINVAL** indica que um dos parâmetros especificados era inválido.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
### <a name="remarks"></a>Comentários  
 Essa função é usada para especificar quais funções de notificação de retorno de chamada do MFC serão chamadas para o soquete. `AsyncSelect` define automaticamente esse soquete para o modo sem bloqueio. Para obter mais informações, consulte o artigo [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).  
  
##  <a name="attach"></a>  CAsyncSocket::Attach  
 Chamar essa função de membro para anexar o `hSocket` identificador para um `CAsyncSocket` objeto.  
  
```  
BOOL Attach(
    SOCKET hSocket, long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hSocket`  
 Contém um identificador para um soquete.  
  
 `lEvent`  
 Um bitmask que especifica uma combinação de eventos de rede no qual o aplicativo está interessado.  
  
- **FD_READ** para receber notificação da preparação para leitura.  
  
- **FD_WRITE** para receber notificação quando os dados estão disponíveis para serem lidos.  
  
- **FD_OOB** para receber a notificação de chegada de dados fora de banda.  
  
- **FD_ACCEPT** para receber a notificação de conexões de entrada.  
  
- **FD_CONNECT** para receber a notificação de resultados de conexão.  
  
- **FD_CLOSE** para receber notificação quando um soquete foi fechado por um colega.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O **soquete** identificador é armazenado no objeto de [m_hSocket](#m_hsocket) membro de dados.  
  
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
 `nSocketPort`  
 A porta que identifica o aplicativo de soquete.  
  
 `lpszSocketAddress`  
 O endereço de rede, um número pontilhado, como "128.56.22.8". Passando o **nulo** cadeia de caracteres para esse parâmetro indica o **CAsyncSocket** instância deve ouvir para a atividade de cliente em todas as interfaces de rede.  
  
 `lpSockAddr`  
 Um ponteiro para um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que contém o endereço para atribuir a esse soquete.  
  
 `nSockAddrLen`  
 O comprimento do endereço no `lpSockAddr` em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEADDRINUSE** o endereço especificado já está em uso. (Consulte o **SO_REUSEADDR** opção de soquete [SetSockOpt](#setsockopt).)  
  
- **WSAEFAULT** o `nSockAddrLen` argumento é muito pequeno (menor que o tamanho de um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura).  
  
- **WSAEINPROGRESS** uma chamada de bloqueio do Windows Sockets está em andamento.  
  
- **WSAEAFNOSUPPORT** não há suporte para a família de endereços especificado por essa porta.  
  
- **WSAEINVAL** o soquete já está associado a um endereço.  
  
- `WSAENOBUFS` Não há buffers disponíveis, muitas conexões.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
### <a name="remarks"></a>Comentários  
 Esta rotina é usada em um datagrama desconectada ou o soquete de fluxo, antes subsequentes **conectar** ou `Listen` chamadas. Antes que possa aceitar solicitações de conexão, um soquete de escuta de servidor deve selecionar um número de porta e torná-lo conhecido para o Windows Sockets chamando **associar**. **Associar** estabelece a associação de local (número de porta do endereço do host) do soquete, atribuindo um nome local para um soquete sem nome.  
  
##  <a name="casyncsocket"></a>  CAsyncSocket::CAsyncSocket  
 Constrói um objeto de soquete em branco.  
  
```  
CAsyncSocket();
```  
  
### <a name="remarks"></a>Comentários  
 Após a criação do objeto, você deve chamar seu **criar** a função de membro para criar o **soquete** da estrutura de dados e associar seu endereço. (No lado do servidor de uma comunicação de Windows Sockets, quando o soquete de escuta cria um soquete para usar o **aceitar** chamada, você não chama **criar** para esse soquete.)  
  
##  <a name="close"></a>  CAsyncSocket::Close  
 Fecha o soquete.  
  
```  
virtual void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função libera o descritor de soquete para que mais referências a ela falhará com o erro **WSAENOTSOCK**. Se esta for a última referência para o soquete subjacente, as informações de nomenclatura associadas e os dados na fila são descartados. Chamadas de destruidor do objeto de soquete **fechar** para você.  
  
 Para `CAsyncSocket`, mas não para `CSocket`, a semântica de **fechar** são afetados pelas opções de soquete **SO_LINGER** e **SO_DONTLINGER**. Para obter mais informações, consulte a função de membro `GetSockOpt`.  
  
##  <a name="connect"></a>  CAsyncSocket::Connect  
 Chame essa função de membro para estabelecer uma conexão a um fluxo desconectado ou um soquete de datagrama.  
  
```  
BOOL Connect(
    LPCTSTR lpszHostAddress,  
    UINT nHostPort);

 
BOOL Connect(
    const SOCKADDR* lpSockAddr,  
    int nSockAddrLen);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszHostAddress`  
 O endereço de rede do soquete para o qual esse objeto está conectado: um nome de máquina, como "ftp.microsoft.com" ou um número pontilhado, como "128.56.22.8".  
  
 `nHostPort`  
 A porta que identifica o aplicativo de soquete.  
  
 `lpSockAddr`  
 Um ponteiro para um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que contém o endereço de soquete conectado.  
  
 `nSockAddrLen`  
 O comprimento do endereço no `lpSockAddr` em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Se isso indica um código de erro **WSAEWOULDBLOCK**e o aplicativo está usando os retornos de chamada substituíveis, seu aplicativo recebe um `OnConnect` mensagem quando a operação de conexão for concluída. Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEADDRINUSE** o endereço especificado já está em uso.  
  
- **WSAEINPROGRESS** uma chamada de bloqueio do Windows Sockets está em andamento.  
  
- **WSAEADDRNOTAVAIL** o endereço especificado não está disponível no computador local.  
  
- **WSAEAFNOSUPPORT** endereços na família especificada não podem ser usados com este soquete.  
  
- **WSAECONNREFUSED** a tentativa de conexão foi rejeitada.  
  
- **WSAEDESTADDRREQ** é necessário um endereço de destino.  
  
- **WSAEFAULT** o `nSockAddrLen` argumento é incorreto.  
  
- **WSAEINVAL** endereço de host inválido.  
  
- **WSAEISCONN** o soquete já está conectado.  
  
- **WSAEMFILE** mais descritores de arquivo estão disponíveis.  
  
- **WSAENETUNREACH** a rede não pode ser alcançada através deste host neste momento.  
  
- `WSAENOBUFS` Nenhum espaço de buffer está disponível. O soquete não pode ser conectado.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
- **WSAETIMEDOUT** tentativa de conexão atingiu o tempo limite sem estabelecer uma conexão.  
  
- **WSAEWOULDBLOCK** o soquete está marcado como sem bloqueio e a conexão não pode ser concluída imediatamente.  
  
### <a name="remarks"></a>Comentários  
 Se o soquete é desassociado, valores exclusivos são atribuídos à associação de local pelo sistema e o soquete está marcado como associados. Observe que, se o campo de endereço da estrutura de nome é zero, **conectar** retornará zero. Para obter mais informações sobre o erro, chame o `GetLastError` função de membro.  
  
 Para soquetes de fluxo (tipo **SOCK_STREAM**), uma conexão ativa é iniciado para o host externo. Quando a chamada do soquete é concluída com êxito, o soquete está pronto para enviar/receber dados.  
  
 Para um soquete de datagrama (tipo **SOCK_DGRAM**), um destino padrão for definido, que será usado na subsequentes **enviar** e **Receive** chamadas.  
  
##  <a name="create"></a>  CAsyncSocket::Create  
 Chamar o **criar** função membro após a criação de um objeto de soquete para criar o soquete de Windows e anexá-lo.  
  
```  
BOOL Create(
    UINT nSocketPort = 0,  
    int nSocketType = SOCK_STREAM,  
    long lEvent = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE,  
    LPCTSTR lpszSocketAddress = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSocketPort`  
 Uma porta conhecida para ser usado com o soquete ou 0 se desejar que o Windows Sockets para selecionar uma porta.  
  
 `nSocketType`  
 **SOCK_STREAM** ou **SOCK_DGRAM**.  
  
 `lEvent`  
 Um bitmask que especifica uma combinação de eventos de rede no qual o aplicativo está interessado.  
  
- **FD_READ** para receber notificação da preparação para leitura.  
  
- **FD_WRITE** para receber notificação da preparação para gravação.  
  
- **FD_OOB** para receber a notificação de chegada de dados fora de banda.  
  
- **FD_ACCEPT** para receber a notificação de conexões de entrada.  
  
- **FD_CONNECT** para receber notificação da conexão concluída.  
  
- **FD_CLOSE** para receber a notificação de fechamento de soquete.  
  
 *lpszSockAddress*  
 Um ponteiro para uma cadeia de caracteres que contém o endereço de rede do soquete conectado, um número pontilhado, como "128.56.22.8". Passando o **nulo** cadeia de caracteres para esse parâmetro indica o **CAsyncSocket** instância deve ouvir para a atividade de cliente em todas as interfaces de rede.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEAFNOSUPPORT** não há suporte para a família de endereços especificado.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAEMFILE** mais descritores de arquivo estão disponíveis.  
  
- `WSAENOBUFS` Nenhum espaço de buffer está disponível. Não é possível criar o soquete.  
  
- **WSAEPROTONOSUPPORT** não há suporte para a porta especificada.  
  
- **WSAEPROTOTYPE** a porta especificada é do tipo incorreto para este soquete.  
  
- **WSAESOCKTNOSUPPORT** o tipo de soquete especificado não é suportado nesta família de endereço.  
  
### <a name="remarks"></a>Comentários  
 **Criar** chamadas [soquete](#socket) e se for bem-sucedido, ele chama [associar](#bind) ligar o soquete para o endereço especificado. Há suporte para os seguintes tipos de soquete:  
  
- **SOCK_STREAM** fornece sequenciado, os fluxos de byte confiável, full duplex, com base em conexão. Usa o protocolo de controle de transmissão (TCP) para a família de endereços da Internet.  
  
- **SOCK_DGRAM** suporta datagramas, que são pacotes sem conexão e não confiáveis de comprimento máximo fixo (normalmente pequeno). Usa o protocolo UDP (User Datagram) para a família de endereços da Internet.  
  
    > [!NOTE]
    >  O **aceitar** função de membro usa uma referência a um novo e vazio `CSocket` objeto como seu parâmetro. Você deve construir esse objeto antes de chamar **aceitar**. Tenha em mente que, se esse objeto de soquete sai do escopo, fecha a conexão. Não chame **criar** para esse novo objeto de soquete.  
  
> [!IMPORTANT]
> **Criar** é **não** thread-safe.  Se você estiver chamando-o em um ambiente multithread onde ele pode ser invocado simultaneamente por threads diferentes, certifique-se de proteger cada chamada com um mutex ou outros bloqueio de sincronização.  
  
 Para obter mais informações sobre os soquetes de datagrama e de fluxo, consulte os artigos [Windows Sockets: plano de fundo](../../mfc/windows-sockets-background.md) e [Windows Sockets: portas e endereços de soquete](../../mfc/windows-sockets-ports-and-socket-addresses.md) e [deAPIdoWindowsSockets2](http://msdn.microsoft.com/library/windows/desktop/ms740673).  
  
##  <a name="detach"></a>  CAsyncSocket::Detach  
 Chamar essa função de membro para desanexar o **soquete** tratam o `m_hSocket` membro de dados a `CAsyncSocket` do objeto e defina `m_hSocket` para **nulo**.  
  
```  
SOCKET Detach();
```  
  
##  <a name="fromhandle"></a>  CAsyncSocket::FromHandle  
 Retorna um ponteiro para um `CAsyncSocket` objeto.  
  
```  
static CAsyncSocket* PASCAL FromHandle(SOCKET hSocket);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hSocket`  
 Contém um identificador para um soquete.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CAsyncSocket` objeto, ou **nulo** se não houver nenhum `CAsyncSocket` objeto anexado a `hSocket`.  
  
### <a name="remarks"></a>Comentários  
 Quando é fornecido um **soquete** tratar, se um `CAsyncSocket` objeto não está anexado ao identificador de, a função de membro retorna **nulo**.  
  
##  <a name="getlasterror"></a>  CAsyncSocket::GetLastError  
 Chame essa função de membro para obter o status de erro para a última operação que falhou.  
  
```  
static int PASCAL GetLastError();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno indica o código de erro para a rotina de API do Windows Sockets última executada por esse thread.  
  
### <a name="remarks"></a>Comentários  
 Quando uma função de membro específico indica que ocorreu um erro, `GetLastError` deve ser chamado para recuperar o código de erro apropriado. Consulte as descrições de função de membro individual para obter uma lista dos códigos de erro aplicável.  
  
 Para obter mais informações sobre os códigos de erro, consulte [API do Windows Sockets 2](http://msdn.microsoft.com/library/windows/desktop/ms740673).  
  
##  <a name="getpeername"></a>  CAsyncSocket::GetPeerName  
 Chame essa função de membro para obter o endereço de soquete de ponto a ponto ao qual este soquete está conectado.  
  
```  
BOOL GetPeerName(
    CString& rPeerAddress,  
    UINT& rPeerPort);

 
BOOL GetPeerName(
    SOCKADDR* lpSockAddr,  
    int* lpSockAddrLen);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rPeerAddress`  
 Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.  
  
 `rPeerPort`  
 Referência a um **UINT** que armazena uma porta.  
  
 `lpSockAddr`  
 Um ponteiro para o [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que recebe o nome do soquete ponto a ponto.  
  
 `lpSockAddrLen`  
 Um ponteiro para o comprimento do endereço no `lpSockAddr` em bytes. No retorno, o `lpSockAddrLen` argumento contém o tamanho real do `lpSockAddr` retornados em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEFAULT** o `lpSockAddrLen` argumento não é grande o suficiente.  
  
- **WSAEINPROGRESS** uma chamada de bloqueio do Windows Sockets está em andamento.  
  
- **WSAENOTCONN** o soquete não está conectado.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
### <a name="remarks"></a>Comentários  
 Para lidar com endereços IPv6, use [CAsyncSocket::GetPeerNameEx](#getpeernameex).  
  
##  <a name="getpeernameex"></a>  CAsyncSocket::GetPeerNameEx  
 Chame essa função de membro para obter o endereço de soquete de ponto a ponto para o qual este soquete está conectados (identificadores de endereços IPv6).  
  
```  
BOOL GetPeerNameEx(
    CString& rPeerAddress,  
    UINT& rPeerPort);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rPeerAddress`  
 Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.  
  
 `rPeerPort`  
 Referência a um **UINT** que armazena uma porta.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEFAULT** o `lpSockAddrLen` argumento não é grande o suficiente.  
  
- **WSAEINPROGRESS** uma chamada de bloqueio do Windows Sockets está em andamento.  
  
- **WSAENOTCONN** o soquete não está conectado.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
### <a name="remarks"></a>Comentários  
 Essa função é o mesmo que [CAsyncSocket::GetPeerName](#getpeername) exceto que ele trata IPv6 endereços protocolos bem mais antigos.  
  
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
 `rSocketAddress`  
 Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.  
  
 `rSocketPort`  
 Referência a um **UINT** que armazena uma porta.  
  
 `lpSockAddr`  
 Um ponteiro para um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que recebe o endereço de soquete.  
  
 `lpSockAddrLen`  
 Um ponteiro para o comprimento do endereço no `lpSockAddr` em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEFAULT** o `lpSockAddrLen` argumento não é grande o suficiente.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
- **WSAEINVAL** o soquete não foi associado a um endereço com **associar**.  
  
### <a name="remarks"></a>Comentários  
 Esta chamada é especialmente útil quando um **conectar** chamada foi feita sem fazer uma **associar** primeiro; esta chamada fornece o único meio pelo qual você pode determinar a associação de local que foi definida pelo sistema.  
  
 Para lidar com endereços IPv6, use [CAsyncSocket::GetSockNameEx](#getsocknameex)  
  
##  <a name="getsocknameex"></a>  CAsyncSocket::GetSockNameEx  
 Chame essa função de membro para obter o nome do local para um soquete (identificadores de endereços IPv6).  
  
```  
BOOL GetSockNameEx(
    CString& rSocketAddress,  
    UINT& rSocketPort);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSocketAddress`  
 Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.  
  
 `rSocketPort`  
 Referência a um **UINT** que armazena uma porta.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEFAULT** o `lpSockAddrLen` argumento não é grande o suficiente.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
- **WSAEINVAL** o soquete não foi associado a um endereço com **associar**.  
  
### <a name="remarks"></a>Comentários  
 Esta chamada é o mesmo que [CAsyncSocket::GetSockName](#getsockname) exceto que ele trata IPv6 endereços protocolos bem mais antigos.  
  
 Esta chamada é especialmente útil quando um **conectar** chamada foi feita sem fazer uma **associar** primeiro; esta chamada fornece o único meio pelo qual você pode determinar a associação de local que foi definida pelo sistema.  
  
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
 `nOptionName`  
 A opção de soquete para o qual o valor é a ser recuperado.  
  
 `lpOptionValue`  
 Um ponteiro para o buffer no qual o valor para a opção solicitada é a ser retornado. O valor associado com a opção selecionada é retornado no buffer `lpOptionValue`. O inteiro apontada pelo `lpOptionLen` originalmente deve conter o tamanho desse buffer em bytes, e no retorno, será definido para o tamanho do valor retornado. Para **SO_LINGER**, esse será o tamanho de um `LINGER` estrutura; para todas as outras opções de será o tamanho de um **BOOL** ou um `int`, dependendo da opção. Consulte a lista de opções e seus tamanhos na seção comentários.  
  
 `lpOptionLen`  
 Um ponteiro para o tamanho do `lpOptionValue` buffer em bytes.  
  
 `nLevel`  
 O nível no qual a opção estiver definida; os níveis com suporte somente são **SOL_SOCKET** e **IPPROTO_TCP**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Se uma opção nunca foi definida com `SetSockOpt`, em seguida, `GetSockOpt` retorna o valor padrão para a opção. Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEFAULT** o `lpOptionLen` argumento era inválido.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAENOPROTOOPT** a opção é desconhecido ou sem suporte. Em particular, **SO_BROADCAST** não tem suporte em soquetes do tipo **SOCK_STREAM**, enquanto **SO_ACCEPTCONN**, **SO_DONTLINGER**,  **SO_KEEPALIVE**, **SO_LINGER**, e **SO_OOBINLINE** não têm suporte em soquetes do tipo **SOCK_DGRAM**.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
### <a name="remarks"></a>Comentários  
 `GetSockOpt` recupera o valor atual de uma opção de soquete associada a um soquete de qualquer tipo, em qualquer estado e armazena o resultado em `lpOptionValue`. Opções afetam as operações de soquete, como o roteamento de pacotes, transferência de dados fora de banda e assim por diante.  
  
 As opções a seguir têm suporte para `GetSockOpt`. O tipo identifica o tipo de dados endereçados pela `lpOptionValue`. O **TCP_NODELAY** opção usa o nível de **IPPROTO_TCP**; todas as outras opções usam nível **SOL_SOCKET**.  
  
|Valor|Tipo|Significado|  
|-----------|----------|-------------|  
|**SO_ACCEPTCONN**|**BOOL**|Soquete está escutando.|  
|**SO_BROADCAST**|**BOOL**|Soquete está configurado para a transmissão de mensagens de difusão.|  
|**SO_DEBUG**|**BOOL**|Depuração está habilitada.|  
|**SO_DONTLINGER**|**BOOL**|Se for true, o **SO_LINGER** opção está desabilitada.|  
|**SO_DONTROUTE**|**BOOL**|Roteamento é desabilitado.|  
|**SO_ERROR**|`int`|Recuperar o status de erro e limpar.|  
|**SO_KEEPALIVE**|**BOOL**|Keep-Alive está sendo enviado.|  
|**SO_LINGER**|**estrutura LINGER**|Retorna as opções de linger atual.|  
|**SO_OOBINLINE**|**BOOL**|Dados fora de banda está sendo recebidos no fluxo de dados normal.|  
|**SO_RCVBUF**|`int`|Tamanho do buffer para recebe.|  
|**SO_REUSEADDR**|**BOOL**|O soquete pode ser vinculado a um endereço que já está em uso.|  
|**SO_SNDBUF**|`int`|Tamanho do buffer de envia.|  
|**SO_TYPE**|`int`|O tipo de soquete (por exemplo, **SOCK_STREAM**).|  
|**TCP_NODELAY**|**BOOL**|Desabilita o algoritmo Nagle para união de envio.|  
  
 Opções de Berkeley Software Distribution (BSD) não tem suportadas para `GetSockOpt` são:  
  
|Valor|Tipo|Significado|  
|-----------|----------|-------------|  
|**SO_RCVLOWAT**|`int`|Receba a marca d'água.|  
|**SO_RCVTIMEO**|`int`|Tempo limite de recebimento.|  
|**SO_SNDLOWAT**|`int`|Envie a marca d'água.|  
|**SO_SNDTIMEO**|`int`|Tempo limite de envio.|  
|**IP_OPTIONS**||Obter opções no cabeçalho IP.|  
|**TCP_MAXSEG**|`int`|Obter o tamanho máximo de segmento TCP.|  
  
 Chamando `GetSockOpt` com uma opção sem suporte resultará em um código de erro **WSAENOPROTOOPT** sendo retornados de `GetLastError`.  
  
##  <a name="ioctl"></a>  CAsyncSocket::IOCtl  
 Chame essa função de membro para controlar o modo de um soquete.  
  
```  
BOOL IOCtl(
    long lCommand,  
    DWORD* lpArgument);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lCommand`  
 O comando para executar no soquete.  
  
 `lpArgument`  
 Um ponteiro para um parâmetro para `lCommand`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEINVAL** `lCommand` não é um comando válido, ou `lpArgument` não é um parâmetro aceitável para `lCommand`, ou o comando não é aplicável ao tipo de soquete fornecido.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
### <a name="remarks"></a>Comentários  
 Esta rotina pode ser usada em qualquer soquete em qualquer estado. Ele é usado para obter ou recuperar parâmetros operacionais associados ao soquete, independente do subsistema de comunicação e protocolo. Há suporte para os seguintes comandos:  
  
- **FIONBIO** habilitar ou desabilitar o modo sem bloqueio no soquete. O `lpArgument` parâmetro aponta para um `DWORD`, que é diferente de zero se o modo sem bloqueio será habilitada e zero se ele é desativado. Se `AsyncSelect` tiver sido emitida em um soquete, em seguida, qualquer tentativa de usar **IOCtl** definir o soquete para o modo de bloqueio falhará com **WSAEINVAL**. Para definir o soquete para o modo de bloqueio e impedir que o **WSAEINVAL** , um aplicativo deve primeiro desativar erro `AsyncSelect` chamando `AsyncSelect` com o `lEvent` parâmetro igual a 0, em seguida, chame **IOCtl** .  
  
- **FIONREAD** determinar o número máximo de bytes que podem ser lidos com uma **Receive** chamada neste soquete. O `lpArgument` parâmetro aponta para uma `DWORD` no qual **IOCtl** armazena o resultado. Se este soquete é do tipo **SOCK_STREAM**, **FIONREAD** retorna a quantidade total de dados que podem ser lidos em um único **Receive**; Isso normalmente é o mesmo que a quantidade total de dados em fila no soquete. Se este soquete é do tipo **SOCK_DGRAM**, **FIONREAD** retorna o tamanho do datagrama primeiro na fila no soquete.  
  
- **SIOCATMARK** determinar se todos os dados fora de banda foi lido. Isso se aplica apenas a um soquete do tipo **SOCK_STREAM** que foi configurado para recepção na linha de dados fora de banda ( **SO_OOBINLINE**). Se nenhum dado fora de banda está esperando para ser lido, a operação retornará zero. Caso contrário, retorna 0 e o próximo **Receive** ou `ReceiveFrom` executada no soquete irá recuperar alguns ou todos os dados anteriores "marca"; o aplicativo deve usar o **SIOCATMARK** operação Determine se restar algum dado. Se não houver nenhum dado normal precede os dados (out-of-band) "urgentes", será recebida na ordem. (Observe que um **Receive** ou `ReceiveFrom` nunca será misturar dados fora de banda e normais na mesma chamada.) O `lpArgument` parâmetro aponta para uma `DWORD` no qual **IOCtl** armazena o resultado.  
  
 Essa função é um subconjunto de **IOCTL ()** conforme usado em soquetes Berkeley. Em particular, não há nenhum comando que é equivalente a **FIOASYNC**, enquanto **SIOCATMARK** é o comando apenas de nível de soquete que tem suporte.  
  
##  <a name="listen"></a>  CAsyncSocket::Listen  
 Chame essa função de membro para escutar solicitações de conexão de entrada.  
  
```  
BOOL Listen(int nConnectionBacklog = 5);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nConnectionBacklog*  
 O comprimento máximo para o qual a fila de conexões pendentes pode atingir. O intervalo válido é de 1 a 5.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEADDRINUSE** foi feita uma tentativa para escutar em um endereço em uso.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAEINVAL** o soquete não foi vinculado com **associar** ou já está conectado.  
  
- **WSAEISCONN** o soquete já está conectado.  
  
- **WSAEMFILE** mais descritores de arquivo estão disponíveis.  
  
- `WSAENOBUFS` Nenhum espaço de buffer está disponível.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
- **WSAEOPNOTSUPP** o soquete referenciado não é de um tipo que oferece suporte a `Listen` operação.  
  
### <a name="remarks"></a>Comentários  
 Para aceitar conexões, o soquete é criado com **criar**, uma lista de pendências para conexões de entrada é especificada com `Listen`, e, em seguida, as conexões são aceitos com **aceitar**. `Listen` aplica-se somente a que suportam conexões, ou seja, de tipo **SOCK_STREAM**. Este soquete é colocado em modo "passivo" onde as conexões de entrada são confirmadas e em fila pendentes aceitação pelo processo.  
  
 Esta função geralmente é usada por servidores (ou qualquer aplicativo que deseja aceitar conexões) que pode ter mais de uma solicitação de conexão em um momento: se chegar uma solicitação de conexão com a fila completa, o cliente receberá um erro com uma indicação de  **WSAECONNREFUSED**.  
  
 `Listen` tenta continuam a funcionar racionalmente quando nenhuma porta disponível (descritores). Ele aceitará conexões até que a fila é esvaziada. Se as portas estiverem disponíveis, uma chamada posterior a `Listen` ou **aceitar** será recarga de fila para a atual ou mais recente "lista de pendências," se possível e retomar a escuta de conexões de entrada.  
  
##  <a name="m_hsocket"></a>  CAsyncSocket::m_hSocket  
 Contém o **soquete** identificador para o soquete encapsulado por este `CAsyncSocket` objeto.  
  
```  
SOCKET m_hSocket;  
```  
  
##  <a name="onaccept"></a>  CAsyncSocket::OnAccept  
 Chamado pelo framework para notificar um soquete de escuta que ele possa aceitar solicitações de conexão pendentes chamando o [aceitar](#accept) função de membro.  
  
```  
virtual void OnAccept(int nErrorCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nErrorCode`  
 O erro mais recente em um soquete. Os códigos de erro a seguir se aplica a `OnAccept` função de membro:  
  
- **0** a função executada com êxito.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).  
  
##  <a name="onclose"></a>  CAsyncSocket::OnClose  
 Chamado pelo framework para notificar este soquete que o soquete conectado é fechado pelo seu processo.  
  
```  
virtual void OnClose(int nErrorCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nErrorCode`  
 O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam ao `OnClose` função de membro:  
  
- **0** a função executada com êxito.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAECONNRESET** a conexão foi redefinido pelo lado remoto.  
  
- **WSAECONNABORTED** a conexão foi interrompida devido a tempo limite ou outra falha.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).  
  
##  <a name="onconnect"></a>  CAsyncSocket::OnConnect  
 Chamado pelo framework para notificar este soquete de conexão que a tentativa de conexão for concluída, se com êxito ou com erro.  
  
```  
virtual void OnConnect(int nErrorCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nErrorCode`  
 O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam ao `OnConnect` função de membro:  
  
- **0** a função executada com êxito.  
  
- **WSAEADDRINUSE** o endereço especificado já está em uso.  
  
- **WSAEADDRNOTAVAIL** o endereço especificado não está disponível no computador local.  
  
- **WSAEAFNOSUPPORT** endereços na família especificada não podem ser usados com este soquete.  
  
- **WSAECONNREFUSED** a tentativa de conexão foi rejeitada de modo forçado.  
  
- **WSAEDESTADDRREQ** é necessário um endereço de destino.  
  
- **WSAEFAULT** o `lpSockAddrLen` argumento é incorreto.  
  
- **WSAEINVAL** o soquete já está associado a um endereço.  
  
- **WSAEISCONN** o soquete já está conectado.  
  
- **WSAEMFILE** mais descritores de arquivo estão disponíveis.  
  
- **WSAENETUNREACH** a rede não pode ser alcançada através deste host neste momento.  
  
- `WSAENOBUFS` Nenhum espaço de buffer está disponível. O soquete não pode ser conectado.  
  
- **WSAENOTCONN** o soquete não está conectado.  
  
- **WSAENOTSOCK** o descritor é um arquivo, não um soquete.  
  
- **WSAETIMEDOUT** a tentativa de conexão atingiu o tempo limite sem estabelecer uma conexão.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Em [CSocket](../../mfc/reference/csocket-class.md), o `OnConnect` nunca é chamada de função de notificação. Para conexões, você simplesmente chama **conectar**, que será retornado quando a conexão for concluída (com êxito ou erro). Como são tratadas os notificações de conexão são um detalhe de implementação do MFC.  
  
 Para obter mais informações, consulte [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAsyncSocket#1](../../mfc/reference/codesnippet/cpp/casyncsocket-class_1.cpp)]  
  
##  <a name="onoutofbanddata"></a>  CAsyncSocket::OnOutOfBandData  
 Chamado pelo framework para notificar o soquete de recebimento que o envio de soquete tem dados fora de banda para enviar.  
  
```  
virtual void OnOutOfBandData(int nErrorCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nErrorCode`  
 O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam ao `OnOutOfBandData` função de membro:  
  
- **0** a função executada com êxito.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
### <a name="remarks"></a>Comentários  
 Dados fora de banda são um canal logicamente independente que está associado a cada par de soquetes conectados do tipo **SOCK_STREAM**. O canal geralmente é usado para enviar dados urgentes.  
  
 Dados de fora da banda, mas os usuários da classe oferece suporte a MFC `CAsyncSocket` são desaconselhável usá-lo. A maneira mais fácil é criar um soquete de segundo para passar esses dados. Para obter mais informações sobre dados fora de banda, consulte [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).  
  
##  <a name="onreceive"></a>  CAsyncSocket::OnReceive  
 Chamado pelo framework para notificar este soquete que há dados no buffer que pode ser recuperado chamando o **Receive** função de membro.  
  
```  
virtual void OnReceive(int nErrorCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nErrorCode`  
 O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam ao `OnReceive` função de membro:  
  
- **0** a função executada com êxito.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAsyncSocket#2](../../mfc/reference/codesnippet/cpp/casyncsocket-class_2.cpp)]  
  
##  <a name="onsend"></a>  CAsyncSocket::OnSend  
 Chamado pelo framework para notificar o soquete que agora ela pode enviar dados por meio da chamada de **enviar** função de membro.  
  
```  
virtual void OnSend(int nErrorCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nErrorCode`  
 O erro mais recente em um soquete. Os códigos de erro a seguir se aplicam ao `OnSend` função de membro:  
  
- **0** a função executada com êxito.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Windows Sockets: notificações de soquete](../../mfc/windows-sockets-socket-notifications.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAsyncSocket#3](../../mfc/reference/codesnippet/cpp/casyncsocket-class_3.cpp)]  
  
##  <a name="operator_eq"></a>  CAsyncSocket::operator =  
 Atribui um novo valor para uma `CAsyncSocket` objeto.  
  
```  
void operator=(const CAsyncSocket& rSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSrc`  
 Uma referência a um existente `CAsyncSocket` objeto.  
  
### <a name="remarks"></a>Comentários  
 Chamar esta função para copiar um existente `CAsyncSocket` objeto para outro `CAsyncSocket` objeto.  
  
##  <a name="operator_socket"></a>  CAsyncSocket::operator soquete  
 Use este operador para recuperar o **soquete** tratar do `CAsyncSocket` objeto.  
  
```  
operator SOCKET() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o identificador do **soquete** objeto; caso contrário, **nulo**.  
  
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
 `lpBuf`  
 Um buffer de dados de entrada.  
  
 `nBufLen`  
 O comprimento de `lpBuf` em bytes.  
  
 `nFlags`  
 Especifica a maneira na qual a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e `nFlags` parâmetro. O segundo é construído, combinando qualquer um dos seguintes valores com o C++ `OR` operador:  
  
- **MSG_PEEK** inspecionar os dados de entrada. Os dados são copiados para o buffer, mas não são removidos da fila de entrada.  
  
- **MSG_OOB** processar dados fora de banda.  
  
### <a name="return-value"></a>Valor de retorno  
 Se nenhum erro ocorrer, **Receive** retorna o número de bytes recebidos. Se a conexão foi fechada, ela retornará 0. Caso contrário, um valor de **SOCKET_ERROR** for retornado, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAENOTCONN** o soquete não está conectado.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
- **WSAEOPNOTSUPP MSG_OOB** foi especificado, mas o soquete não é do tipo **SOCK_STREAM**.  
  
- **WSAESHUTDOWN** o soquete foi desligado, não é possível chamar **Receive** em um soquete após `ShutDown` foi chamado com `nHow` definido como 0 ou 2.  
  
- **WSAEWOULDBLOCK** o soquete está marcado como não bloqueadas e o **Receive** operação seria bloqueada.  
  
- **WSAEMSGSIZE** o datagrama era muito grande para caber no buffer especificado e foi truncado.  
  
- **WSAEINVAL** o soquete não foi vinculado com **associar**.  
  
- **WSAECONNABORTED** o circuito virtual foi anulado devido ao tempo limite ou outra falha.  
  
- **WSAECONNRESET** o circuito virtual foi redefinido pelo lado remoto.  
  
### <a name="remarks"></a>Comentários  
 Essa função é usada para o fluxo conectado ou soquetes de datagrama e é usada para ler os dados de entrada.  
  
 Para soquetes do tipo **SOCK_STREAM**, conforme a quantidade de informações está atualmente disponível até o tamanho do buffer fornecido é retornado. Se o soquete foi configurado para recepção na linha de dados fora de banda (opção de soquete **SO_OOBINLINE**) e dados fora de banda são lidos, fora de banda apenas os dados serão retornados. O aplicativo pode usar o **IOCtlSIOCATMARK** opção ou [OnOutOfBandData](#onoutofbanddata) para determinar se todos os dados fora de banda mais continua a ser lido.  
  
 Para soquetes de datagrama, os dados são extraídos do datagrama enfileiradas primeiro, até o tamanho do buffer fornecido. Se o datagrama é maior do que o buffer fornecido, o buffer é preenchido com a primeira parte do datagrama, o excesso de dados é perdido, e **Receive** retorna um valor de **SOCKET_ERROR** com o código de erro definido como **WSAEMSGSIZE**. Se os dados de entrada não estão disponíveis no soquete, um valor de **SOCKET_ERROR** é retornado com o código de erro definido como **WSAEWOULDBLOCK**. O [OnReceive](#onreceive) função de retorno de chamada pode ser usada para determinar quando mais dados chegam.  
  
 Se o soquete é do tipo **SOCK_STREAM** e o lado remoto encerrou a conexão normalmente, um **Receive** será concluído imediatamente com 0 bytes recebidos. Se a conexão tiver sido redefinido, um **Receive** falhará com o erro **WSAECONNRESET**.  
  
 **Receber** deve ser chamado apenas uma vez para cada vez [CAsyncSocket::OnReceive](#onreceive) é chamado.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CAsyncSocket::OnReceive](#onreceive).  
  
##  <a name="receivefrom"></a>  CAsyncSocket::ReceiveFrom  
 Chamar essa função de membro para receber um datagrama e armazenar o endereço de origem no [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura ou em `rSocketAddress`.  
  
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
 `lpBuf`  
 Um buffer de dados de entrada.  
  
 `nBufLen`  
 O comprimento de `lpBuf` em bytes.  
  
 `rSocketAddress`  
 Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.  
  
 `rSocketPort`  
 Referência a um **UINT** que armazena uma porta.  
  
 `lpSockAddr`  
 Um ponteiro para um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que contém o endereço de origem após retornar.  
  
 `lpSockAddrLen`  
 Um ponteiro para o comprimento do endereço de origem na `lpSockAddr` em bytes.  
  
 `nFlags`  
 Especifica a maneira na qual a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e `nFlags` parâmetro. O segundo é construído, combinando qualquer um dos seguintes valores com o C++ `OR` operador:  
  
- **MSG_PEEK** inspecionar os dados de entrada. Os dados são copiados para o buffer, mas não são removidos da fila de entrada.  
  
- **MSG_OOB** processar dados fora de banda.  
  
### <a name="return-value"></a>Valor de retorno  
 Se nenhum erro ocorrer, `ReceiveFrom` retorna o número de bytes recebidos. Se a conexão foi fechada, ela retornará 0. Caso contrário, um valor de **SOCKET_ERROR** for retornado, e um código de erro específico pode ser recuperado chamando `GetLastError`. Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEFAULT** o `lpSockAddrLen` argumento era inválido: o `lpSockAddr` buffer era muito pequeno para acomodar o endereço par.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAEINVAL** o soquete não foi vinculado com **associar**.  
  
- **WSAENOTCONN** o soquete não está conectado ( **SOCK_STREAM** somente).  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
- **WSAEOPNOTSUPP MSG_OOB** foi especificado, mas o soquete não é do tipo **SOCK_STREAM**.  
  
- **WSAESHUTDOWN** o soquete foi desligado, não é possível chamar `ReceiveFrom` em um soquete após `ShutDown` foi chamado com `nHow` definido como 0 ou 2.  
  
- **WSAEWOULDBLOCK** o soquete está marcado como não bloqueadas e o `ReceiveFrom` operação seria bloqueada.  
  
- **WSAEMSGSIZE** o datagrama era muito grande para caber no buffer especificado e foi truncado.  
  
- **WSAECONNABORTED** o circuito virtual foi anulado devido ao tempo limite ou outra falha.  
  
- **WSAECONNRESET** o circuito virtual foi redefinido pelo lado remoto.  
  
### <a name="remarks"></a>Comentários  
 Essa função é usada para ler os dados de entrada em um soquete (possivelmente conectado) e capturar o endereço do qual os dados foram enviados.  
  
 Para lidar com endereços IPv6, use [CAsyncSocket::ReceiveFromEx](#receivefromex).  
  
 Para soquetes do tipo **SOCK_STREAM**, conforme a quantidade de informações está atualmente disponível até o tamanho do buffer fornecido é retornado. Se o soquete foi configurado para recepção na linha de dados fora de banda (opção de soquete **SO_OOBINLINE**) e dados fora de banda são lidos, fora de banda apenas os dados serão retornados. O aplicativo pode usar o **IOCtlSIOCATMARK** opção ou `OnOutOfBandData` para determinar se todos os dados fora de banda mais continua a ser lido. O `lpSockAddr` e `lpSockAddrLen` parâmetros são ignorados para **SOCK_STREAM** soquetes.  
  
 Para soquetes de datagrama, os dados são extraídos do datagrama enfileiradas primeiro, até o tamanho do buffer fornecido. Se o datagrama é maior do que o buffer fornecido, o buffer é preenchido com a primeira parte da mensagem, o excesso de dados é perdido, e `ReceiveFrom` retorna um valor de **SOCKET_ERROR** com o código de erro definido como  **WSAEMSGSIZE**.  
  
 Se `lpSockAddr` é diferente de zero, e o soquete é do tipo **SOCK_DGRAM**, o endereço de rede do soquete que enviou os dados é copiado para o correspondente [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura. O valor apontado por `lpSockAddrLen` é inicializada com o tamanho dessa estrutura e é modificado no retorno para indicar o tamanho real do endereço armazenado lá. Se os dados de entrada não estão disponíveis no soquete, o `ReceiveFrom` chamada aguarda os dados chegar a menos que seja o soquete sem bloqueio. Nesse caso, um valor de **SOCKET_ERROR** é retornado com o código de erro definido como **WSAEWOULDBLOCK**. O `OnReceive` retorno de chamada pode ser usado para determinar quando mais dados chegam.  
  
 Se o soquete é do tipo **SOCK_STREAM** e o lado remoto encerrou a conexão normalmente, um `ReceiveFrom` será concluído imediatamente com 0 bytes recebidos.  
  
##  <a name="receivefromex"></a>  CAsyncSocket::ReceiveFromEx  
 Chamar essa função de membro para receber um datagrama e armazenar o endereço de origem no [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura ou no `rSocketAddress` (lida com endereços IPv6).  
  
```  
int ReceiveFromEx(
    void* lpBuf,  
    int nBufLen,  
    CString& rSocketAddress,  
    UINT& rSocketPort,  
    int nFlags = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpBuf`  
 Um buffer de dados de entrada.  
  
 `nBufLen`  
 O comprimento de `lpBuf` em bytes.  
  
 `rSocketAddress`  
 Referência a um `CString` objeto que recebe um endereço IP de número pontilhado.  
  
 `rSocketPort`  
 Referência a um **UINT** que armazena uma porta.  
  
 `nFlags`  
 Especifica a maneira na qual a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e `nFlags` parâmetro. O segundo é construído, combinando qualquer um dos seguintes valores com o C++ `OR` operador:  
  
- **MSG_PEEK** inspecionar os dados de entrada. Os dados são copiados para o buffer, mas não são removidos da fila de entrada.  
  
- **MSG_OOB** processar dados fora de banda.  
  
### <a name="return-value"></a>Valor de retorno  
 Se nenhum erro ocorrer, `ReceiveFromEx` retorna o número de bytes recebidos. Se a conexão foi fechada, ela retornará 0. Caso contrário, um valor de **SOCKET_ERROR** for retornado, e um código de erro específico pode ser recuperado chamando `GetLastError`. Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEFAULT** o `lpSockAddrLen` argumento era inválido: o `lpSockAddr` buffer era muito pequeno para acomodar o endereço par.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAEINVAL** o soquete não foi vinculado com **associar**.  
  
- **WSAENOTCONN** o soquete não está conectado ( **SOCK_STREAM** somente).  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
- **WSAEOPNOTSUPP MSG_OOB** foi especificado, mas o soquete não é do tipo **SOCK_STREAM**.  
  
- **WSAESHUTDOWN** o soquete foi desligado, não é possível chamar `ReceiveFromEx` em um soquete após `ShutDown` foi chamado com `nHow` definido como 0 ou 2.  
  
- **WSAEWOULDBLOCK** o soquete está marcado como não bloqueadas e o `ReceiveFromEx` operação seria bloqueada.  
  
- **WSAEMSGSIZE** o datagrama era muito grande para caber no buffer especificado e foi truncado.  
  
- **WSAECONNABORTED** o circuito virtual foi anulado devido ao tempo limite ou outra falha.  
  
- **WSAECONNRESET** o circuito virtual foi redefinido pelo lado remoto.  
  
### <a name="remarks"></a>Comentários  
 Essa função é usada para ler os dados de entrada em um soquete (possivelmente conectado) e capturar o endereço do qual os dados foram enviados.  
  
 Essa função é o mesmo que [CAsyncSocket::ReceiveFrom](#receivefrom) exceto que ele trata IPv6 endereços protocolos bem mais antigos.  
  
 Para soquetes do tipo **SOCK_STREAM**, conforme a quantidade de informações está atualmente disponível até o tamanho do buffer fornecido é retornado. Se o soquete foi configurado para recepção na linha de dados fora de banda (opção de soquete **SO_OOBINLINE**) e dados fora de banda são lidos, fora de banda apenas os dados serão retornados. O aplicativo pode usar o **IOCtlSIOCATMARK** opção ou `OnOutOfBandData` para determinar se todos os dados fora de banda mais continua a ser lido. O `lpSockAddr` e `lpSockAddrLen` parâmetros são ignorados para **SOCK_STREAM** soquetes.  
  
 Para soquetes de datagrama, os dados são extraídos do datagrama enfileiradas primeiro, até o tamanho do buffer fornecido. Se o datagrama é maior do que o buffer fornecido, o buffer é preenchido com a primeira parte da mensagem, o excesso de dados é perdido, e `ReceiveFromEx` retorna um valor de **SOCKET_ERROR** com o código de erro definido como  **WSAEMSGSIZE**.  
  
 Se `lpSockAddr` é diferente de zero, e o soquete é do tipo **SOCK_DGRAM**, o endereço de rede do soquete que enviou os dados é copiado para o correspondente [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura. O valor apontado por `lpSockAddrLen` é inicializada com o tamanho dessa estrutura e é modificado no retorno para indicar o tamanho real do endereço armazenado lá. Se os dados de entrada não estão disponíveis no soquete, o `ReceiveFromEx` chamada aguarda os dados chegar a menos que seja o soquete sem bloqueio. Nesse caso, um valor de **SOCKET_ERROR** é retornado com o código de erro definido como **WSAEWOULDBLOCK**. O `OnReceive` retorno de chamada pode ser usado para determinar quando mais dados chegam.  
  
 Se o soquete é do tipo **SOCK_STREAM** e o lado remoto encerrou a conexão normalmente, um `ReceiveFromEx` será concluído imediatamente com 0 bytes recebidos.  
  
##  <a name="send"></a>  CAsyncSocket::Send  
 Chame essa função de membro para enviar dados em um soquete conectado.  
  
```  
virtual int Send(
    const void* lpBuf,  
    int nBufLen,  
    int nFlags = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpBuf`  
 Um buffer que contém os dados sejam transmitidos.  
  
 `nBufLen`  
 O comprimento dos dados `lpBuf` em bytes.  
  
 `nFlags`  
 Especifica a maneira na qual a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e `nFlags` parâmetro. O segundo é construído, combinando qualquer um dos seguintes valores com o C++ `OR` operador:  
  
- **MSG_DONTROUTE** Especifica que os dados não devem estar sujeito a roteamento. Um fornecedor de Windows Sockets pode optar por ignorar esse sinalizador.  
  
- **MSG_OOB** enviar dados fora de banda ( **SOCK_STREAM** somente).  
  
### <a name="return-value"></a>Valor de retorno  
 Se nenhum erro ocorrer, **enviar** retorna o número total de caracteres enviada. (Observe que isso pode ser menor que o número indicado pelo `nBufLen`.) Caso contrário, um valor de **SOCKET_ERROR** for retornado, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEACCES** o endereço solicitado é um endereço de difusão, mas o sinalizador apropriado não foi definido.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAEFAULT** o `lpBuf` argumento não é parte do espaço de endereço de usuário válida.  
  
- **WSAENETRESET** a conexão deve ser redefinido porque a implementação do Windows Sockets soltou.  
  
- `WSAENOBUFS` A implementação do Windows Sockets informa um travamento de buffer.  
  
- **WSAENOTCONN** o soquete não está conectado.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
- **WSAEOPNOTSUPP MSG_OOB** foi especificado, mas o soquete não é do tipo **SOCK_STREAM**.  
  
- **WSAESHUTDOWN** o soquete foi desligado, não é possível chamar **enviar** em um soquete após `ShutDown` foi chamado com `nHow` definido como 1 ou 2.  
  
- **WSAEWOULDBLOCK** o soquete está marcado como não bloqueadas e bloqueia a operação solicitada.  
  
- **WSAEMSGSIZE** o soquete é do tipo **SOCK_DGRAM**, e o datagrama é maior do que o máximo com suporte a implementação do Windows Sockets.  
  
- **WSAEINVAL** o soquete não foi vinculado com **associar**.  
  
- **WSAECONNABORTED** o circuito virtual foi anulado devido ao tempo limite ou outra falha.  
  
- **WSAECONNRESET** o circuito virtual foi redefinido pelo lado remoto.  
  
### <a name="remarks"></a>Comentários  
 **Enviar** é usada para gravar dados de saída conectado soquetes de fluxo ou datagrama. Para soquetes de datagrama, tome cuidado para não exceder o tamanho máximo de pacotes IP das sub-redes subjacentes, que é determinado pelo **iMaxUdpDg** elemento o [WSADATA](../../mfc/reference/wsadata-structure.md) estrutura retornada por `AfxSocketInit`. Se os dados são muito longos para passar o protocolo subjacente, o erro atomicamente **WSAEMSGSIZE** é retornado por meio de `GetLastError`, e nenhum dado é transmitido.  
  
 Observe que, para um datagrama soquete a conclusão bem-sucedida de uma **enviar** não indica que os dados foi entregue com êxito.  
  
 Em `CAsyncSocket` objetos do tipo **SOCK_STREAM**, o número de bytes gravados pode ser entre 1 e o tamanho solicitado, dependendo da disponibilidade do buffer em hosts locais e externas.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CAsyncSocket::OnSend](#onsend).  
  
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
 `lpBuf`  
 Um buffer que contém os dados sejam transmitidos.  
  
 `nBufLen`  
 O comprimento dos dados `lpBuf` em bytes.  
  
 `nHostPort`  
 A porta que identifica o aplicativo de soquete.  
  
 `lpszHostAddress`  
 O endereço de rede do soquete para o qual esse objeto está conectado: um nome de máquina, como "ftp.microsoft.com" ou um número pontilhado, como "128.56.22.8".  
  
 `nFlags`  
 Especifica a maneira na qual a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e `nFlags` parâmetro. O segundo é construído, combinando qualquer um dos seguintes valores com o C++ `OR` operador:  
  
- **MSG_DONTROUTE** Especifica que os dados não devem estar sujeito a roteamento. Um fornecedor de Windows Sockets pode optar por ignorar esse sinalizador.  
  
- **MSG_OOB** enviar dados fora de banda ( **SOCK_STREAM** somente).  
  
 `lpSockAddr`  
 Um ponteiro para um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura que contém o endereço de soquete de destino.  
  
 `nSockAddrLen`  
 O comprimento do endereço no `lpSockAddr` em bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Se nenhum erro ocorrer, `SendTo` retorna o número total de caracteres enviada. (Observe que isso pode ser menor que o número indicado pelo `nBufLen`.) Caso contrário, um valor de **SOCKET_ERROR** for retornado, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEACCES** o endereço solicitado é um endereço de difusão, mas o sinalizador apropriado não foi definido.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAEFAULT** o `lpBuf` ou `lpSockAddr` parâmetros não fazem parte do espaço de endereço do usuário, ou o `lpSockAddr` argumento é muito pequeno (menor que o tamanho de um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura).  
  
- **WSAEINVAL** o nome do host é inválido.  
  
- **WSAENETRESET** a conexão deve ser redefinido porque a implementação do Windows Sockets soltou.  
  
- `WSAENOBUFS` A implementação do Windows Sockets informa um travamento de buffer.  
  
- **WSAENOTCONN** o soquete não está conectado ( **SOCK_STREAM** somente).  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
- **WSAEOPNOTSUPP MSG_OOB** foi especificado, mas o soquete não é do tipo **SOCK_STREAM**.  
  
- **WSAESHUTDOWN** o soquete foi desligado, não é possível chamar `SendTo` em um soquete após `ShutDown` foi chamado com `nHow` definido como 1 ou 2.  
  
- **WSAEWOULDBLOCK** o soquete está marcado como não bloqueadas e bloqueia a operação solicitada.  
  
- **WSAEMSGSIZE** o soquete é do tipo **SOCK_DGRAM**, e o datagrama é maior do que o máximo com suporte a implementação do Windows Sockets.  
  
- **WSAECONNABORTED** o circuito virtual foi anulado devido ao tempo limite ou outra falha.  
  
- **WSAECONNRESET** o circuito virtual foi redefinido pelo lado remoto.  
  
- **WSAEADDRNOTAVAIL** o endereço especificado não está disponível no computador local.  
  
- **WSAEAFNOSUPPORT** endereços na família especificada não podem ser usados com este soquete.  
  
- **WSAEDESTADDRREQ** é necessário um endereço de destino.  
  
- **WSAENETUNREACH** a rede não pode ser alcançada através deste host neste momento.  
  
### <a name="remarks"></a>Comentários  
 `SendTo` é usado em soquetes de datagrama ou fluxo e é usada para gravar dados de saída em um soquete. Para soquetes de datagrama, tome cuidado para não exceder o tamanho máximo de pacotes IP das sub-redes subjacentes, que é determinado pelo **iMaxUdpDg** elemento o [WSADATA](../../mfc/reference/wsadata-structure.md) estrutura preenchido por [ AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit). Se os dados são muito longos para passar o protocolo subjacente, o erro atomicamente **WSAEMSGSIZE** for retornado, e nenhum dado é transmitido.  
  
 Observe que a conclusão bem-sucedida de um `SendTo` não indica que os dados foi entregue com êxito.  
  
 `SendTo` é usado somente em um **SOCK_DGRAM** para enviar um datagrama para um soquete específico identificado por soquete de `lpSockAddr` parâmetro.  
  
 Para enviar uma difusão (em um **SOCK_DGRAM** somente), o endereço na `lpSockAddr` parâmetro deve ser construído usando o endereço IP especial **INADDR_BROADCAST** (definido no cabeçalho de Windows Sockets arquivo WINSOCK. H) junto com o número da porta desejada. Ou, se o `lpszHostAddress` parâmetro é **nulo**, o soquete é configurado para transmissão. Não é geralmente recomendável para um difusão datagrama exceda o tamanho no qual poderá ocorrer fragmentação, que significa que a parte de dados do datagrama (excluindo cabeçalhos) não deve exceder 512 bytes.  
  
 Para lidar com endereços IPv6, use [CAsyncSocket::SendToEx](#sendtoex).  
  
##  <a name="sendtoex"></a>  CAsyncSocket::SendToEx  
 Chame essa função de membro para enviar dados para um destino específico (identificadores de endereços IPv6).  
  
```  
int SendToEx(
    const void* lpBuf,  
    int nBufLen,  
    UINT nHostPort,  
    LPCTSTR lpszHostAddress = NULL,  
    int nFlags = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpBuf`  
 Um buffer que contém os dados sejam transmitidos.  
  
 `nBufLen`  
 O comprimento dos dados `lpBuf` em bytes.  
  
 `nHostPort`  
 A porta que identifica o aplicativo de soquete.  
  
 `lpszHostAddress`  
 O endereço de rede do soquete para o qual esse objeto está conectado: um nome de máquina, como "ftp.microsoft.com" ou um número pontilhado, como "128.56.22.8".  
  
 `nFlags`  
 Especifica a maneira na qual a chamada é feita. A semântica dessa função é determinada pelas opções de soquete e `nFlags` parâmetro. O segundo é construído, combinando qualquer um dos seguintes valores com o C++ `OR` operador:  
  
- **MSG_DONTROUTE** Especifica que os dados não devem estar sujeito a roteamento. Um fornecedor de Windows Sockets pode optar por ignorar esse sinalizador.  
  
- **MSG_OOB** enviar dados fora de banda ( **SOCK_STREAM** somente).  
  
### <a name="return-value"></a>Valor de retorno  
 Se nenhum erro ocorrer, `SendToEx` retorna o número total de caracteres enviada. (Observe que isso pode ser menor que o número indicado pelo `nBufLen`.) Caso contrário, um valor de **SOCKET_ERROR** for retornado, e um código de erro específico pode ser recuperado chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEACCES** o endereço solicitado é um endereço de difusão, mas o sinalizador apropriado não foi definido.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAEFAULT** o `lpBuf` ou `lpSockAddr` parâmetros não fazem parte do espaço de endereço do usuário, ou o `lpSockAddr` argumento é muito pequeno (menor que o tamanho de um [SOCKADDR](../../mfc/reference/sockaddr-structure.md) estrutura).  
  
- **WSAEINVAL** o nome do host é inválido.  
  
- **WSAENETRESET** a conexão deve ser redefinido porque a implementação do Windows Sockets soltou.  
  
- `WSAENOBUFS` A implementação do Windows Sockets informa um travamento de buffer.  
  
- **WSAENOTCONN** o soquete não está conectado ( **SOCK_STREAM** somente).  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
- **WSAEOPNOTSUPP MSG_OOB** foi especificado, mas o soquete não é do tipo **SOCK_STREAM**.  
  
- **WSAESHUTDOWN** o soquete foi desligado, não é possível chamar `SendToEx` em um soquete após `ShutDown` foi chamado com `nHow` definido como 1 ou 2.  
  
- **WSAEWOULDBLOCK** o soquete está marcado como não bloqueadas e bloqueia a operação solicitada.  
  
- **WSAEMSGSIZE** o soquete é do tipo **SOCK_DGRAM**, e o datagrama é maior do que o máximo com suporte a implementação do Windows Sockets.  
  
- **WSAECONNABORTED** o circuito virtual foi anulado devido ao tempo limite ou outra falha.  
  
- **WSAECONNRESET** o circuito virtual foi redefinido pelo lado remoto.  
  
- **WSAEADDRNOTAVAIL** o endereço especificado não está disponível no computador local.  
  
- **WSAEAFNOSUPPORT** endereços na família especificada não podem ser usados com este soquete.  
  
- **WSAEDESTADDRREQ** é necessário um endereço de destino.  
  
- **WSAENETUNREACH** a rede não pode ser alcançada através deste host neste momento.  
  
### <a name="remarks"></a>Comentários  
 Esse método é o mesmo que [CAsyncSocket::SendTo](#sendto) exceto que ele trata IPv6 endereços protocolos bem mais antigos.  
  
 `SendToEx` é usado em soquetes de datagrama ou fluxo e é usada para gravar dados de saída em um soquete. Para soquetes de datagrama, tome cuidado para não exceder o tamanho máximo de pacotes IP das sub-redes subjacentes, que é determinado pelo **iMaxUdpDg** elemento o [WSADATA](../../mfc/reference/wsadata-structure.md) estrutura preenchido por [ AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit). Se os dados são muito longos para passar o protocolo subjacente, o erro atomicamente **WSAEMSGSIZE** for retornado, e nenhum dado é transmitido.  
  
 Observe que a conclusão bem-sucedida de um `SendToEx` não indica que os dados foi entregue com êxito.  
  
 `SendToEx` é usado somente em um **SOCK_DGRAM** para enviar um datagrama para um soquete específico identificado por soquete de `lpSockAddr` parâmetro.  
  
 Para enviar uma difusão (em um **SOCK_DGRAM** somente), o endereço na `lpSockAddr` parâmetro deve ser construído usando o endereço IP especial **INADDR_BROADCAST** (definido no cabeçalho de Windows Sockets arquivo WINSOCK. H) junto com o número da porta desejada. Ou, se o `lpszHostAddress` parâmetro é **nulo**, o soquete é configurado para transmissão. Não é geralmente recomendável para um difusão datagrama exceda o tamanho no qual poderá ocorrer fragmentação, que significa que a parte de dados do datagrama (excluindo cabeçalhos) não deve exceder 512 bytes.  
  
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
 `nOptionName`  
 A opção de soquete para o qual o valor será definido.  
  
 `lpOptionValue`  
 Um ponteiro para o buffer no qual o valor para a opção solicitada é fornecido.  
  
 `nOptionLen`  
 O tamanho do `lpOptionValue` buffer em bytes.  
  
 `nLevel`  
 O nível no qual a opção estiver definida; os níveis com suporte somente são **SOL_SOCKET** e **IPPROTO_TCP**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEFAULT** `lpOptionValue` não é parte do espaço de endereço de processo válida.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAEINVAL** `nLevel` não é válido, ou as informações do `lpOptionValue` não é válido.  
  
- **WSAENETRESET** Conexão atingiu o tempo limite quando **SO_KEEPALIVE** está definido.  
  
- **WSAENOPROTOOPT** a opção é desconhecido ou sem suporte. Em particular, **SO_BROADCAST** não tem suporte em soquetes do tipo **SOCK_STREAM**, enquanto **SO_DONTLINGER**, **SO_KEEPALIVE**,  **SO_LINGER**, e **SO_OOBINLINE** não têm suporte em soquetes do tipo **SOCK_DGRAM**.  
  
- **WSAENOTCONN** Conexão foi redefinido quando **SO_KEEPALIVE** está definido.  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
### <a name="remarks"></a>Comentários  
 `SetSockOpt` Define o valor atual de uma opção de soquete associada a um soquete de qualquer tipo, em qualquer estado. Embora as opções podem existir em vários níveis de protocolo, essa especificação define somente opções que existem no nível superior "soquete". Opções afetam as operações de soquete, como se os dados emitidos são recebidos no fluxo de dados normal, se as mensagens de difusão podem ser enviadas no soquete e assim por diante.  
  
 Há dois tipos de opções de soquete: Boolean opções que habilitam ou desabilitam a um recurso ou o comportamento e opções que exigem uma estrutura ou um valor inteiro. Para habilitar uma opção Boolean, `lpOptionValue` aponta para um inteiro diferente de zero. Para desabilitar a opção `lpOptionValue` aponta para um número inteiro igual a zero. `nOptionLen` deve ser igual ao **sizeof(BOOL)** para opções Boolean. Para outras opções, `lpOptionValue` aponta para o inteiro ou uma estrutura que contém o valor desejado para a opção, e `nOptionLen` é o comprimento do número inteiro ou estrutura.  
  
 **SO_LINGER** controla a ação tomada quando não enviados dados que estão enfileirados em um soquete e o **fechar** função é chamada para fechar o soquete.  
  
 Por padrão, não é possível associar um soquete (consulte [associar](#bind)) para um endereço local que já está em uso. Ocasionalmente, no entanto, pode ser desejável "reutilizar" um endereço dessa forma. Desde que cada conexão é identificada exclusivamente pela combinação dos endereços locais e remotos, não há nenhum problema com tenha dois soquetes associados para o mesmo endereço local, como os endereços remotos são diferentes.  
  
 Para informar a implementação do Windows Sockets que um **associar** chamada em um soquete não deve ser desativada porque o endereço desejado já está em uso por outro soquete, o aplicativo deve definir o **SO_REUSEADDR**soquete opção para o soquete antes de emitir o **associar** chamar. Observe que a opção é interpretada somente no momento do **associar** chamar:, portanto, é desnecessário (mas inofensivo) definir a opção em um soquete que não deve ser associado a um endereço existente e configurando ou redefinir a opção após a **Associar** chamada não tem nenhum efeito ou qualquer outro soquete.  
  
 Um aplicativo pode solicitar que a implementação do Windows Sockets permitem o uso de pacotes "keep-alive" em conexões de protocolo de controle de transmissão (TCP) ao ativar o **SO_KEEPALIVE** opção de soquete. Uma implementação de Windows Sockets não precisa de suporte ao uso de keep-alive: em caso afirmativo, a semântica precisa são específicos de implementação, mas deve estar de acordo com a seção 4.2.3.6 da RFC 1122: "requisitos para Hosts da Internet — camadas de comunicação." Se uma conexão é descartada como resultado de "keep-alive" o código de erro **WSAENETRESET** é retornado para todas as chamadas em andamento no soquete, e todas as chamadas subsequentes falharão com **WSAENOTCONN**.  
  
 O **TCP_NODELAY** opção desabilita o algoritmo de Nagle. O algoritmo Nagle é usado para reduzir o número de pacotes pequenos enviada por um host por buffer de dados de envio não confirmadas até que um pacote em tamanho normal pode ser enviado. No entanto, para alguns aplicativos esse algoritmo pode impedir o desempenho, e **TCP_NODELAY** pode ser usado para desativá-lo. Gravadores de aplicativo não devem ser definido **TCP_NODELAY** , a menos que o impacto de fazer isso é bem compreendidos e desejado, desde a configuração **TCP_NODELAY** pode ter um impacto negativo significativo no desempenho da rede . **TCP_NODELAY** é a única opção de soquete que usa o nível de suporte **IPPROTO_TCP**; todas as outras opções usam nível **SOL_SOCKET**.  
  
 Algumas implementações de fornecimento de Windows Sockets gerar informações de depuração se a **SO_DEBUG** opção é definida por um aplicativo.  
  
 As opções a seguir têm suporte para `SetSockOpt`. O tipo identifica o tipo de dados endereçados pela `lpOptionValue`.  
  
|Valor|Tipo|Significado|  
|-----------|----------|-------------|  
|**SO_BROADCAST**|**BOOL**|Permitir transmissão de mensagens de difusão no soquete.|  
|**SO_DEBUG**|**BOOL**|Registre informações de depuração.|  
|**SO_DONTLINGER**|**BOOL**|Não bloquear **fechar** aguardando não enviados dados a serem enviados. A definição dessa opção é equivalente à configuração **SO_LINGER** com **l_onoff** definido como zero.|  
|**SO_DONTROUTE**|**BOOL**|Não encaminhar: enviar diretamente para a interface.|  
|**SO_KEEPALIVE**|**BOOL**|Envie keep-alive.|  
|**SO_LINGER**|**estrutura LINGER**|Ficar **fechar** se não enviados dados estão presentes.|  
|**SO_OOBINLINE**|**BOOL**|Receba dados fora de banda no fluxo de dados normal.|  
|**SO_RCVBUF**|`int`|Especifique o tamanho do buffer para recebe.|  
|**SO_REUSEADDR**|**BOOL**|Permitir que o soquete para ser associado a um endereço que já está em uso. (Consulte [associar](#bind).)|  
|**SO_SNDBUF**|`int`|Especifique o tamanho do buffer de envios.|  
|**TCP_NODELAY**|**BOOL**|Desabilita o algoritmo Nagle para união de envio.|  
  
 Opções de Berkeley Software Distribution (BSD) não tem suportadas para `SetSockOpt` são:  
  
|Valor|Tipo|Significado|  
|-----------|----------|-------------|  
|**SO_ACCEPTCONN**|**BOOL**|Soquete de escuta|  
|**SO_ERROR**|`int`|Obter status de erro e limpar.|  
|**SO_RCVLOWAT**|`int`|Receba a marca d'água.|  
|**SO_RCVTIMEO**|`int`|Tempo limite de recebimento|  
|**SO_SNDLOWAT**|`int`|Envie a marca d'água.|  
|**SO_SNDTIMEO**|`int`|Tempo limite de envio.|  
|**SO_TYPE**|`int`|Tipo de soquete.|  
|**IP_OPTIONS**||Defina o campo de opções no cabeçalho IP.|  
  
##  <a name="shutdown"></a>  CAsyncSocket::ShutDown  
 Chamada desta função de membro para desabilitar a envia, receber, ou ambos no soquete.  
  
```  
BOOL ShutDown(int nHow = sends);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nHow`  
 Um sinalizador que descreve quais tipos de operação não será permitido, usando os seguintes valores enumerados:  
  
- **recebe = 0**  
  
- **envia = 1**  
  
- **tanto = 2**  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperados chamando [GetLastError](#getlasterror). Os erros a seguir se aplicam a essa função de membro:  
  
- **WSANOTINITIALISED** sucesso [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit) deve ocorrer antes de usar essa API.  
  
- **WSAENETDOWN** implementação o Windows Sockets detectou que o subsistema de rede falhou.  
  
- **WSAEINVAL** `nHow` não é válido.  
  
- **WSAEINPROGRESS** uma operação de bloqueio do Windows Sockets está em andamento.  
  
- **WSAENOTCONN** o soquete não está conectado ( **SOCK_STREAM** somente).  
  
- **WSAENOTSOCK** o descritor de não é um soquete.  
  
### <a name="remarks"></a>Comentários  
 `ShutDown` é usado em todos os tipos de soquetes para desabilitar recepção, transmissão ou ambos. Se `nHow` for 0, recebe subsequentes no soquete não será permitido. Isso não tem nenhum efeito nas camadas inferiores do protocolo.  
  
 Para o protocolo de controle de transmissão (TCP), a janela TCP não é alterada e os dados de entrada serão aceitas (mas não confirmada) até que a janela está esgotada. Para o protocolo UDP (User Datagram), datagramas de entrada são aceitos e em fila. Em nenhum caso um pacote de erro ICMP ser gerado. Se `nHow` for 1, envios subsequentes não são permitidos. Para soquetes TCP, um FIN será enviado. Configuração `nHow` 2 desabilita os dois envia e recebe conforme descrito acima.  
  
 Observe que `ShutDown` não fechar o soquete e recursos anexados para o soquete não será liberada até **fechar** é chamado. Um aplicativo não deve depender à reutilização de um soquete depois que ele tiver sido desligado. Em particular, uma implementação de Windows Sockets não é necessário para dar suporte ao uso de **conectar** em tal um soquete.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CAsyncSocket::OnReceive](#onreceive).  
  
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
 `nSocketType`  
 Especifica `SOCK_STREAM` ou `SOCK_DGRAM`.  
  
 `lEvent`  
 Um bitmask que especifica uma combinação de eventos de rede no qual o aplicativo está interessado.  
  
- `FD_READ`: Deseja receber notificações de preparação para leitura.  
  
- `FD_WRITE`: Deseja receber notificações de preparação para gravação.  
  
- `FD_OOB`: Deve receber a notificação de chegada de dados fora de banda.  
  
- `FD_ACCEPT`: Deseja receber notificações de conexões de entrada.  
  
- `FD_CONNECT`: Deseja receber notificação da conexão concluída.  
  
- `FD_CLOSE`: Deseja receber notificações de fechamento de soquete.  
  
 `nProtocolType`  
 Protocolo a ser usado com o soquete que é específico para a família de endereço indicado.  
  
 `nAddressFormat`  
 Especificação da família de endereços.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` em caso de sucesso, `FALSE` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método aloca um identificador de soquete. Ele não chame [CAsyncSocket::Bind](#bind) ligar o soquete para um endereço especificado, portanto você precisa chamar `Bind` posteriormente para ligar o soquete para um endereço especificado. Você pode usar [CAsyncSocket::SetSockOpt](#setsockopt) para definir a opção de soquete antes que ele está associado.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CSocket](../../mfc/reference/csocket-class.md)   
 [Classe CSocketFile](../../mfc/reference/csocketfile-class.md)
