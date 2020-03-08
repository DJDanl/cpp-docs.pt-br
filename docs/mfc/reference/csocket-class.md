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
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78855673"
---
# <a name="csocket-class"></a>Classe CSocket

Deriva de `CAsyncSocket`, herda seu encapsulamento da API do Windows Sockets e representa um nível mais alto de abstração do que de um objeto `CAsyncSocket`.

## <a name="syntax"></a>Sintaxe

```
class CSocket : public CAsyncSocket
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CSocket::CSocket](#csocket)|Constrói um objeto `CSocket`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CSocket:: Attach](#attach)|Anexa um identificador de soquete a um objeto `CSocket`.|
|[CSocket::CancelBlockingCall](#cancelblockingcall)|Cancela uma chamada de bloqueio que está em andamento no momento.|
|[CSocket:: criar](#create)|Cria um soquete.|
|[CSocket:: FromHandle](#fromhandle)|Retorna um ponteiro para um objeto `CSocket`, dado um identificador de soquete.|
|[CSocket:: isblocking](#isblocking)|Determina se uma chamada de bloqueio está em andamento.|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CSocket::OnMessagePending](#onmessagepending)|Chamado para processar mensagens pendentes enquanto aguarda a conclusão de uma chamada de bloqueio.|

## <a name="remarks"></a>Comentários

`CSocket` funciona com classes `CSocketFile` e `CArchive` para gerenciar o envio e recebimento de dados.

Um objeto `CSocket` também fornece bloqueio, que é essencial para a operação síncrona do `CArchive`. As funções de bloqueio, como `Receive`, `Send`, `ReceiveFrom`, `SendTo`e `Accept` (todas herdadas de `CAsyncSocket`), não retornam um erro de `WSAEWOULDBLOCK` no `CSocket`. Em vez disso, essas funções esperam até que a operação seja concluída. Além disso, a chamada original será encerrada com o erro WSAEINTR se `CancelBlockingCall` for chamado enquanto uma dessas funções estiver bloqueando.

Para usar um objeto `CSocket`, chame o construtor e, em seguida, chame `Create` para criar o identificador de soquete subjacente (soquete de tipo). Os parâmetros padrão de `Create` criar um soquete de fluxo, mas se você não estiver usando o soquete com um objeto `CArchive`, poderá especificar um parâmetro para criar um soquete de datagrama ou associar a uma porta específica para criar um soquete de servidor. Conecte-se a um soquete de cliente usando `Connect` no lado do cliente e `Accept` no lado do servidor. Em seguida, crie um objeto `CSocketFile` e associe-o ao objeto `CSocket` no Construtor `CSocketFile`. Em seguida, crie um objeto `CArchive` para enviar e um para o recebimento de dados (conforme necessário) e, em seguida, associe-os ao objeto `CSocketFile` no Construtor `CArchive`. Quando as comunicações forem concluídas, destrua os objetos `CArchive`, `CSocketFile`e `CSocket`. O tipo de dados SOCKET é descrito no artigo [Windows Sockets: Background](../../mfc/windows-sockets-background.md).

Ao usar `CArchive` com `CSocketFile` e `CSocket`, você pode encontrar uma situação em que `CSocket::Receive` entra em um loop (por `PumpMessages(FD_READ)`) aguardando a quantidade solicitada de bytes. Isso ocorre porque os soquetes do Windows permitem apenas uma chamada de recv por notificação FD_READ, mas `CSocketFile` e `CSocket` permitem várias chamadas de recebimento por FD_READ. Se você receber uma FD_READ quando não houver dados a serem lidos, o aplicativo será interrompido. Se você nunca receber outra FD_READ, o aplicativo deixará de se comunicar no soquete.

Você pode resolver esse problema da seguinte maneira. No método `OnReceive` da sua classe Socket, chame `CAsyncSocket::IOCtl(FIONREAD, ...)` antes de chamar o método `Serialize` da sua classe Message quando os dados esperados a serem lidos do soquete excederem o tamanho de um pacote TCP (unidade de transmissão máxima da mídia de rede, geralmente pelo menos 1096 bytes). Se o tamanho dos dados disponíveis for menor que o necessário, aguarde até que todos os dados sejam recebidos e, em seguida, inicie a operação de leitura.

No exemplo a seguir, `m_dwExpected` é o número aproximado de bytes que o usuário espera receber. Supõe-se que você o declare em outro lugar em seu código.

[!code-cpp[NVC_MFCSocketThread#4](../../mfc/reference/codesnippet/cpp/csocket-class_1.cpp)]

> [!NOTE]
>  Ao usar soquetes do MFC em threads secundários em um aplicativo MFC vinculado estaticamente, você deve chamar `AfxSocketInit` em cada thread que usa soquetes para inicializar as bibliotecas de soquete. Por padrão, `AfxSocketInit` é chamado apenas no thread principal.

Para obter mais informações, consulte [Windows Sockets in MFC](../../mfc/windows-sockets-in-mfc.md), [Windows Sockets: usando soquetes com arquivos](../../mfc/windows-sockets-using-sockets-with-archives.md), [Windows Sockets: como os soquetes com arquivos funcionam](../../mfc/windows-sockets-how-sockets-with-archives-work.md), [Windows Sockets: sequência de operações](../../mfc/windows-sockets-sequence-of-operations.md), [Windows Sockets: exemplo de soquetes usando arquivos mortos](../../mfc/windows-sockets-example-of-sockets-using-archives.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CAsyncSocket](../../mfc/reference/casyncsocket-class.md)

`CSocket`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** AfxSock. h

##  <a name="attach"></a>CSocket:: Attach

Chame essa função de membro para anexar o identificador de `hSocket` a um objeto `CSocket`.

```
BOOL Attach(SOCKET hSocket);
```

### <a name="parameters"></a>Parâmetros

*hSocket*<br/>
Contém um identificador para um soquete.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida.

### <a name="remarks"></a>Comentários

O identificador de soquete é armazenado no membro de dados de [m_hSocket](../../mfc/reference/casyncsocket-class.md#m_hsocket) do objeto.

Para obter mais informações, consulte [Windows Sockets: using Sockets with arquivamentos](../../mfc/windows-sockets-using-sockets-with-archives.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCSocketThread#1](../../mfc/reference/codesnippet/cpp/csocket-class_2.h)]

[!code-cpp[NVC_MFCSocketThread#2](../../mfc/reference/codesnippet/cpp/csocket-class_3.cpp)]

[!code-cpp[NVC_MFCSocketThread#3](../../mfc/reference/codesnippet/cpp/csocket-class_4.cpp)]

##  <a name="cancelblockingcall"></a>CSocket::CancelBlockingCall

Chame essa função de membro para cancelar uma chamada de bloqueio atualmente em andamento.

```
void CancelBlockingCall();
```

### <a name="remarks"></a>Comentários

Essa função cancela qualquer operação de bloqueio pendente para este Soquete. A chamada de bloqueio original será encerrada assim que possível com o erro WSAEINTR.

No caso de uma operação de `Connect` de bloqueio, a implementação do Windows Sockets encerrará a chamada de bloqueio assim que possível, mas talvez não seja possível que os recursos de soquete sejam liberados até que a conexão seja concluída (e, em seguida, redefinida) ou tenha atingido o tempo limite. Isso provavelmente será perceptível apenas se o aplicativo tentar abrir imediatamente um novo soquete (se nenhum soquete estiver disponível) ou se conectar ao mesmo par.

Cancelar qualquer operação que não seja `Accept` pode deixar o soquete em um estado indeterminado. Se um aplicativo cancelar uma operação de bloqueio em um soquete, a única operação que o aplicativo pode depender de ser capaz de executar no soquete é uma chamada para `Close`, embora outras operações possam funcionar em algumas implementações do Windows Sockets. Se você quiser portabilidade máxima para seu aplicativo, deverá ter cuidado para não depender da execução de operações após um cancelamento.

Para obter mais informações, consulte [Windows Sockets: using Sockets with arquivamentos](../../mfc/windows-sockets-using-sockets-with-archives.md).

##  <a name="create"></a>CSocket:: criar

Chame a função **criar** membro depois de construir um objeto de soquete para criar o soquete do Windows e anexá-lo.

```
BOOL Create(
    UINT nSocketPort = 0,
    int nSocketType = SOCK_STREAM,
    LPCTSTR lpszSocketAddress = NULL);
```

### <a name="parameters"></a>Parâmetros

*nSocketPort*<br/>
Uma porta específica a ser usada com o soquete ou 0 se você quiser que o MFC selecione uma porta.

*nSocketType*<br/>
SOCK_STREAM ou SOCK_DGRAM.

*lpszSocketAddress*<br/>
Um ponteiro para uma cadeia de caracteres que contém o endereço de rede do Soquete conectado, um número pontilhado, como "128.56.22.8". Passar a cadeia de caracteres nula para esse parâmetro indica que a instância de `CSocket` deve escutar a atividade do cliente em todas as interfaces de rede.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0, e um código de erro específico pode ser recuperado chamando `GetLastError`.

### <a name="remarks"></a>Comentários

`Create`, em seguida, chama `Bind` para associar o soquete ao endereço especificado. Há suporte para os seguintes tipos de soquete:

- O SOCK_STREAM fornece fluxos de bytes seqüenciais, confiáveis e bidirecionais baseados em conexão. Usa o protocolo TCP para a família de endereços da Internet.

- O SOCK_DGRAM dá suporte a datagramas, que são buffers sem conexão e não confiáveis de um tamanho máximo fixo (normalmente pequeno). Usa UDP (User Datagram Protocol) para a família de endereços da Internet. Para usar essa opção, você não deve usar o soquete com um objeto `CArchive`.

    > [!NOTE]
    >  A função membro `Accept` usa uma referência a um objeto de `CSocket` novo e vazio como seu parâmetro. Você deve construir esse objeto antes de chamar `Accept`. Tenha em mente que, se esse objeto de soquete sair do escopo, a conexão será fechada. Não chame `Create` para este novo objeto de soquete.

Para obter mais informações sobre Stream e soquetes de datagrama, consulte os artigos [Windows Sockets: Background](../../mfc/windows-sockets-background.md), [Windows Sockets: ports and socket Addresses](../../mfc/windows-sockets-ports-and-socket-addresses.md)e [Windows Sockets: using Sockets with arquivos](../../mfc/windows-sockets-using-sockets-with-archives.md).

##  <a name="csocket"></a>CSocket::CSocket

Constrói um objeto `CSocket`.

```
CSocket();
```

### <a name="remarks"></a>Comentários

Após a construção, você deve chamar a função de membro `Create`.

Para obter mais informações, consulte [Windows Sockets: using Sockets with arquivamentos](../../mfc/windows-sockets-using-sockets-with-archives.md).

##  <a name="fromhandle"></a>CSocket:: FromHandle

Retorna um ponteiro para um objeto `CSocket`.

```
static CSocket* PASCAL FromHandle(SOCKET hSocket);
```

### <a name="parameters"></a>Parâmetros

*hSocket*<br/>
Contém um identificador para um soquete.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CSocket` ou NULL se não houver nenhum objeto `CSocket` anexado a *hSocket*.

### <a name="remarks"></a>Comentários

Quando um identificador de soquete é fornecido, se um objeto de `CSocket` não estiver anexado ao identificador, a função de membro retornará NULL e não criará um objeto temporário.

Para obter mais informações, consulte [Windows Sockets: using Sockets with arquivamentos](../../mfc/windows-sockets-using-sockets-with-archives.md).

##  <a name="isblocking"></a>CSocket:: isblocking

Chame essa função de membro para determinar se uma chamada de bloqueio está em andamento.

```
BOOL IsBlocking();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o soquete estiver bloqueando; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Windows Sockets: using Sockets with arquivamentos](../../mfc/windows-sockets-using-sockets-with-archives.md).

##  <a name="onmessagepending"></a>CSocket::OnMessagePending

Substitua essa função de membro para procurar mensagens específicas do Windows e respondê-las em seu soquete.

```
virtual BOOL OnMessagePending();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a mensagem foi tratada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse é um substituível avançado.

A estrutura chama `OnMessagePending` enquanto o soquete está bombeando mensagens do Windows para dar a você uma oportunidade de lidar com mensagens de interesse em seu aplicativo. Para obter exemplos de como você pode usar `OnMessagePending`, consulte o artigo [Windows Sockets: derivando de classes de soquete](../../mfc/windows-sockets-deriving-from-socket-classes.md).

Para obter mais informações, consulte [Windows Sockets: using Sockets with arquivamentos](../../mfc/windows-sockets-using-sockets-with-archives.md).

## <a name="see-also"></a>Consulte também

[Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)<br/>
[Classe CSocketFile](../../mfc/reference/csocketfile-class.md)
