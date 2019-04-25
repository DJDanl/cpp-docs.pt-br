---
title: Classe CSocket
ms.date: 11/04/2016
f1_keywords:
- CSocket
- AFXSOCK/CSocket
- AFXSOCK/CSocket::CSocket
- AFXSOCK/CSocket::Attach
- AFXSOCK/CSocket::CancelBlockingCall
- AFXSOCK/CSocket::Create
- AFXSOCK/CSocket::FromHandle
- AFXSOCK/CSocket::IsBlocking
- AFXSOCK/CSocket::OnMessagePending
helpviewer_keywords:
- CSocket [MFC], CSocket
- CSocket [MFC], Attach
- CSocket [MFC], CancelBlockingCall
- CSocket [MFC], Create
- CSocket [MFC], FromHandle
- CSocket [MFC], IsBlocking
- CSocket [MFC], OnMessagePending
ms.assetid: 7f23c081-d24d-42e3-b511-8053ca53d729
ms.openlocfilehash: a861e557b7368d13d615aaf796faded93c72b040
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62323954"
---
# <a name="csocket-class"></a>Classe CSocket

Deriva `CAsyncSocket`herda seu encapsulamento da API do Windows Sockets e representa um nível mais alto de abstração do que um `CAsyncSocket` objeto.

## <a name="syntax"></a>Sintaxe

```
class CSocket : public CAsyncSocket
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSocket::CSocket](#csocket)|Constrói um objeto `CSocket`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSocket::Attach](#attach)|Anexa um identificador de soquete para um `CSocket` objeto.|
|[CSocket::CancelBlockingCall](#cancelblockingcall)|Cancela uma chamada de bloqueio que está atualmente em andamento.|
|[CSocket::Create](#create)|Cria um soquete.|
|[CSocket::FromHandle](#fromhandle)|Retorna um ponteiro para um `CSocket` objeto, dado um identificador de soquete.|
|[CSocket::IsBlocking](#isblocking)|Determina se uma chamada de bloqueio está em andamento.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CSocket::OnMessagePending](#onmessagepending)|Chamado para processar as mensagens pendentes enquanto aguarda a conclusão de uma chamada de bloqueio.|

## <a name="remarks"></a>Comentários

`CSocket` funciona com classes `CSocketFile` e `CArchive` para gerenciar o envio e recebimento de dados.

Um `CSocket` objeto também fornece o bloqueio, que é essencial para a operação síncrona de `CArchive`. Bloqueio de funções, tais como `Receive`, `Send`, `ReceiveFrom`, `SendTo`, e `Accept` (todas as herdadas de `CAsyncSocket`), não retornam um `WSAEWOULDBLOCK` erro no `CSocket`. Em vez disso, essas funções Aguarde a conclusão da operação. Além disso, a chamada original será encerrado com o erro WSAEINTR se `CancelBlockingCall` é chamado durante uma dessas funções está bloqueando.

Para usar um `CSocket` de objeto, chame o construtor, em seguida, chame `Create` para criar o identificador de soquete subjacente (tipo de soquete). Os parâmetros padrão `Create` criar um soquete de fluxo, mas se você não estiver usando o soquete com um `CArchive` objeto, você pode especificar um parâmetro para criar um soquete de datagrama em vez disso, ou vincular a uma porta específica para criar um soquete de servidor. Conectar-se a um soquete de cliente usando `Connect` no lado do cliente e `Accept` no lado do servidor. Em seguida, crie um `CSocketFile` do objeto e associá-la para o `CSocket` do objeto no `CSocketFile` construtor. Em seguida, crie uma `CArchive` objeto para o envio e outra para recebimento de dados (conforme necessário), em seguida, associá-los com o `CSocketFile` do objeto no `CArchive` construtor. Quando as comunicações são concluídas, destrua o `CArchive`, `CSocketFile`, e `CSocket` objetos. O tipo de dados do soquete é descrito no artigo [Windows Sockets: Background](../../mfc/windows-sockets-background.md).

Quando você usa `CArchive` com `CSocketFile` e `CSocket`, você pode encontrar uma situação em que `CSocket::Receive` entra em um loop (por `PumpMessages(FD_READ)`) aguardando a quantidade solicitada de bytes. Isso ocorre porque soquetes do Windows permitem que apenas uma chamada de recebimento por notificação FD_READ, mas `CSocketFile` e `CSocket` permitir várias chamadas de recebimento por FD_READ. Se você receber um FD_READ quando não há nenhum dado a ser lido, o aplicativo para de responder. Se você nunca receber outra FD_READ, o aplicativo para se comunicar por soquete.

Você pode resolver esse problema, da seguinte maneira. No `OnReceive` método de sua classe socket, chamada `CAsyncSocket::IOCtl(FIONREAD, ...)` antes de chamar o `Serialize` método de sua classe de mensagem quando os dados esperados sejam lidos a partir do soquete excedem o tamanho de um pacote TCP (unidade máxima de transmissão de mídia de rede Normalmente, pelo menos 1096 bytes). Se o tamanho dos dados disponíveis é menor que o necessário, aguarde a todos os dados a ser recebida e só então começa a operação de leitura.

No exemplo a seguir, `m_dwExpected` é o número aproximado de bytes que o usuário espera receber. Supõe-se que você declare-o em outro lugar no seu código.

[!code-cpp[NVC_MFCSocketThread#4](../../mfc/reference/codesnippet/cpp/csocket-class_1.cpp)]

> [!NOTE]
>  Ao usar soquetes MFC em threads secundários em um aplicativo MFC vinculado estaticamente, você deve chamar `AfxSocketInit` em cada thread que usa soquetes para inicializar as bibliotecas de soquete. Por padrão, `AfxSocketInit` é chamado somente no thread primário.

Para obter mais informações, consulte [Windows Sockets em MFC](../../mfc/windows-sockets-in-mfc.md), [Windows Sockets: Usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md), [Windows Sockets: Como funcionam soquetes com arquivos mortos](../../mfc/windows-sockets-how-sockets-with-archives-work.md), [Windows Sockets: Sequência de operações](../../mfc/windows-sockets-sequence-of-operations.md), [Windows Sockets: Exemplo de soquetes que usam arquivos mortos](../../mfc/windows-sockets-example-of-sockets-using-archives.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CAsyncSocket](../../mfc/reference/casyncsocket-class.md)

`CSocket`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxsock.h

##  <a name="attach"></a>  CSocket::Attach

Chame essa função de membro para anexar a `hSocket` identificador para um `CSocket` objeto.

```
BOOL Attach(SOCKET hSocket);
```

### <a name="parameters"></a>Parâmetros

*hSocket*<br/>
Contém um identificador para um soquete.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida.

### <a name="remarks"></a>Comentários

O identificador de soquete é armazenado no objeto de [m_hSocket](../../mfc/reference/casyncsocket-class.md#m_hsocket) membro de dados.

Para obter mais informações, consulte [Windows Sockets: Usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSocketThread#1](../../mfc/reference/codesnippet/cpp/csocket-class_2.h)]

[!code-cpp[NVC_MFCSocketThread#2](../../mfc/reference/codesnippet/cpp/csocket-class_3.cpp)]

[!code-cpp[NVC_MFCSocketThread#3](../../mfc/reference/codesnippet/cpp/csocket-class_4.cpp)]

##  <a name="cancelblockingcall"></a>  CSocket::CancelBlockingCall

Chame essa função de membro para cancelar uma chamada de bloqueio atualmente em andamento.

```
void CancelBlockingCall();
```

### <a name="remarks"></a>Comentários

Essa função cancela qualquer operação pendente de bloqueio para esse soquete. A chamada de bloqueio original será encerrado assim que possível com o erro WSAEINTR.

No caso de um bloqueio `Connect` operação, a implementação do Windows Sockets encerrará a chamada de bloqueio, assim que possível, mas ele pode não ser possível para os recursos de soquete a ser liberado até que a conexão foi concluída (e, em seguida, foi redefinida) ou atingiu o tempo limite. Isso é provavelmente será percebido somente se o aplicativo imediatamente tenta abrir um novo soquete (se não há soquetes disponíveis) ou para conectar-se para o mesmo peer.

Cancelar qualquer operação diferente de `Accept` pode deixar o soquete em um estado indeterminado. Se um aplicativo cancela uma operação de bloqueio em um soquete, a única operação que o aplicativo pode depender sendo capaz de executar no soquete é uma chamada para `Close`, embora outras operações podem funcionar em algumas implementações de Windows Sockets. Se desejar portabilidade máxima para o seu aplicativo, tenha cuidado para não depender da execução de operações após um cancelamento.

Para obter mais informações, consulte [Windows Sockets: Usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).

##  <a name="create"></a>  CSocket::Create

Chame o **criar** função de membro depois de construir um objeto de soquete para criar o soquete do Windows e anexá-lo.

```
BOOL Create(
    UINT nSocketPort = 0,
    int nSocketType = SOCK_STREAM,
    LPCTSTR lpszSocketAddress = NULL);
```

### <a name="parameters"></a>Parâmetros

*nSocketPort*<br/>
Uma porta específica a ser usado com o soquete, ou 0 se desejar que o MFC para selecionar uma porta.

*nSocketType*<br/>
SOCK_STREAM ou SOCK_DGRAM.

*lpszSocketAddress*<br/>
Um ponteiro para uma cadeia de caracteres que contém o endereço de rede do soquete conectado, um número pontilhado, como "128.56.22.8". Passando o nulo de cadeia de caracteres para esse parâmetro indica o `CSocket` instância deve escutar para a atividade do cliente em todas as interfaces de rede.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperado chamando `GetLastError`.

### <a name="remarks"></a>Comentários

`Create` em seguida, chama `Bind` ligar o soquete para o endereço especificado. Há suporte para os seguintes tipos de soquete:

- SOCK_STREAM fornece sequenciado, fluxos de bytes bidirecionais, confiáveis com base em conexão. Usa o protocolo TCP (Transmission Control) para a família de endereços da Internet.

- Suporta SOCK_DGRAM datagramas, buffers sem conexão e não confiáveis de comprimento máximo fixo (normalmente pequeno). Usa o protocolo UDP (User Datagram) para a família de endereços da Internet. Para usar essa opção, você não deve usar o soquete com um `CArchive` objeto.

    > [!NOTE]
    >  O `Accept` função de membro usa uma referência a um novo e vazio `CSocket` objeto como seu parâmetro. Você deve construir esse objeto antes de chamar `Accept`. Tenha em mente que, se esse objeto de soquete sai do escopo, fecha a conexão. Não chame `Create` para esse novo objeto de soquete.

Para obter mais informações sobre os soquetes de datagrama e de fluxo, consulte os artigos [Windows Sockets: Background](../../mfc/windows-sockets-background.md), [Windows Sockets: Portas e endereços de soquete](../../mfc/windows-sockets-ports-and-socket-addresses.md), e [Windows Sockets: Usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).

##  <a name="csocket"></a>  CSocket::CSocket

Constrói um objeto `CSocket`.

```
CSocket();
```

### <a name="remarks"></a>Comentários

Após a compilação, você deve chamar o `Create` função de membro.

Para obter mais informações, consulte [Windows Sockets: Usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).

##  <a name="fromhandle"></a>  CSocket::FromHandle

Retorna um ponteiro para um `CSocket` objeto.

```
static CSocket* PASCAL FromHandle(SOCKET hSocket);
```

### <a name="parameters"></a>Parâmetros

*hSocket*<br/>
Contém um identificador para um soquete.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CSocket` do objeto ou nulo se não houver nenhum `CSocket` objeto associado *hSocket*.

### <a name="remarks"></a>Comentários

Quando é fornecido um identificador de soquete, se um `CSocket` objeto não está anexado ao identificador, a função de membro retorna NULL e não cria um objeto temporário.

Para obter mais informações, consulte [Windows Sockets: Usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).

##  <a name="isblocking"></a>  CSocket::IsBlocking

Chame essa função de membro para determinar se uma chamada de bloqueio está em andamento.

```
BOOL IsBlocking();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o soquete está bloqueando; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Windows Sockets: Usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).

##  <a name="onmessagepending"></a>  CSocket::OnMessagePending

Substitua essa função de membro para procurar mensagens específicas do Windows e respondê-los em seu soquete.

```
virtual BOOL OnMessagePending();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a mensagem foi tratada; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso é um avançado substituível.

A estrutura chama `OnMessagePending` enquanto o soquete está bombeando mensagens do Windows para lhe dar uma oportunidade de lidar com mensagens de interesse para seu aplicativo. Para obter exemplos de como você pode usar `OnMessagePending`, consulte o artigo [Windows Sockets: Derivando de Classes de soquete](../../mfc/windows-sockets-deriving-from-socket-classes.md).

Para obter mais informações, consulte [Windows Sockets: Usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).

## <a name="see-also"></a>Consulte também

[Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)<br/>
[Classe CSocketFile](../../mfc/reference/csocketfile-class.md)
