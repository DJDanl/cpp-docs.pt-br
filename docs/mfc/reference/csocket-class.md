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
ms.openlocfilehash: 3f0a7a9a90250ede7b112cfbd9bc1ca14d583356
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318187"
---
# <a name="csocket-class"></a>Classe CSocket

Deriva, `CAsyncSocket`herda seu encapsulamento da API do Windows Sockets, e representa um nível `CAsyncSocket` de abstração mais alto do que o de um objeto.

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
|[CSocket::Anexar](#attach)|Anexa uma alça SOCKET `CSocket` a um objeto.|
|[CSocket::Cancelandochamada de bloqueio](#cancelblockingcall)|Cancela uma chamada de bloqueio que está em andamento.|
|[CSocket::Criar](#create)|Cria um soquete.|
|[CSocket::FromHandle](#fromhandle)|Retorna um ponteiro `CSocket` para um objeto, dada uma alça SOCKET.|
|[CSocket::IsBlocking](#isblocking)|Determina se uma chamada de bloqueio está em andamento.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[csocket::OnMessagePending](#onmessagepending)|Chamado para processar mensagens pendentes enquanto aguarda a conclusão de uma chamada de bloqueio.|

## <a name="remarks"></a>Comentários

`CSocket`trabalha com `CSocketFile` `CArchive` classes e para gerenciar o envio e recebimento de dados.

Um `CSocket` objeto também fornece bloqueio, o que é `CArchive`essencial para a operação síncrona de . As funções de `Receive` `Send`bloqueio, tais `Accept` como , `CAsyncSocket`, `ReceiveFrom`, `SendTo`, `WSAEWOULDBLOCK` e (todas herdadas), não retornam um erro em `CSocket`. Em vez disso, essas funções esperam até que a operação seja concluída. Além disso, a chamada original terminará com o `CancelBlockingCall` erro WSAEINTR se for chamada enquanto uma dessas funções estiver bloqueando.

Para usar `CSocket` um objeto, ligue para `Create` o construtor e, em seguida, ligue para criar a alça sOQUEA (tipo SOCKET) subjacente. Os parâmetros `Create` padrão de criar um soquete de `CArchive` fluxo, mas se você não estiver usando o soquete com um objeto, você pode especificar um parâmetro para criar um soquete de datagram ou vincular a uma porta específica para criar um soquete de servidor. Conecte-se a `Connect` um soquete do cliente usando no lado do cliente e `Accept` no lado do servidor. Em seguida, crie um `CSocketFile` `CSocket` objeto e `CSocketFile` associe-o ao objeto da construtora. Em seguida, `CArchive` crie um objeto para envio e outro para `CSocketFile` receber dados `CArchive` (conforme necessário), em seguida, associe-os com o objeto no construtor. Quando as comunicações `CArchive`estiverem `CSocketFile`completas, destrua os objetos e `CSocket` objetos. O tipo de dados SOCKET é descrito no artigo [Soquetes do Windows: Plano de fundo](../../mfc/windows-sockets-background.md).

Quando você `CArchive` `CSocketFile` usa `CSocket`com e , `CSocket::Receive` você pode encontrar `PumpMessages(FD_READ)`uma situação onde entra em um loop (por ) esperando a quantidade solicitada de bytes. Isso porque os soquetes do Windows permitem `CSocketFile` `CSocket` apenas uma chamada de recv por notificação FD_READ, mas e permitem várias chamadas de recv por FD_READ. Se você receber uma FD_READ quando não há dados para ler, o aplicativo é travado. Se você nunca tiver outra FD_READ, o aplicativo pára de se comunicar sobre o soquete.

Você pode resolver este problema da seguinte forma. No `OnReceive` método da sua classe `CAsyncSocket::IOCtl(FIONREAD, ...)` de soquete, ligue antes de chamar o `Serialize` método da sua classe de mensagem quando os dados esperados a serem lidos na tomada excedem o tamanho de um pacote TCP (unidade de transmissão máxima do meio de rede, geralmente pelo menos 1096 bytes). Se o tamanho dos dados disponíveis for menor do que o necessário, aguarde que todos os dados sejam recebidos e, em seguida, inicie a operação de leitura.

No exemplo a `m_dwExpected` seguir, está o número aproximado de bytes que o usuário espera receber. Presume-se que você o declare em outro lugar em seu código.

[!code-cpp[NVC_MFCSocketThread#4](../../mfc/reference/codesnippet/cpp/csocket-class_1.cpp)]

> [!NOTE]
> Ao usar soquetes MFC em segmentos secundários em `AfxSocketInit` um aplicativo MFC estático ligado, você deve chamar em cada segmento que usa soquetes para inicializar as bibliotecas de soquetes. Por padrão, `AfxSocketInit` é chamado apenas no segmento principal.

Para obter mais informações, consulte [Soquetes do Windows em MFC,](../../mfc/windows-sockets-in-mfc.md) [Soquetes do Windows: Usando Soquetes com Arquivos,](../../mfc/windows-sockets-using-sockets-with-archives.md) [Soquetes do Windows: Como Soquetes com Arquivos, Como Soquetes com Arquivos, Como Soquetes com Arquivos,](../../mfc/windows-sockets-how-sockets-with-archives-work.md) [Soquetes do Windows: Seqüência de Operações,](../../mfc/windows-sockets-sequence-of-operations.md) [Soquetes do Windows: Exemplo de Soquetes Usando Arquivos](../../mfc/windows-sockets-example-of-sockets-using-archives.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Casyncsocket](../../mfc/reference/casyncsocket-class.md)

`CSocket`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxsock.h

## <a name="csocketattach"></a><a name="attach"></a>CSocket::Anexar

Ligue esta função de `hSocket` membro `CSocket` para anexar a alça a um objeto.

```
BOOL Attach(SOCKET hSocket);
```

### <a name="parameters"></a>Parâmetros

*hSocket*<br/>
Contém uma alça em um soquete.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida.

### <a name="remarks"></a>Comentários

A alça SOCKET é armazenada no membro [de dados m_hSocket](../../mfc/reference/casyncsocket-class.md#m_hsocket) do objeto.

Para obter mais informações, consulte [Soquetes do Windows: Usando soquetes com arquivos](../../mfc/windows-sockets-using-sockets-with-archives.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCSocketThread#1](../../mfc/reference/codesnippet/cpp/csocket-class_2.h)]

[!code-cpp[NVC_MFCSocketThread#2](../../mfc/reference/codesnippet/cpp/csocket-class_3.cpp)]

[!code-cpp[NVC_MFCSocketThread#3](../../mfc/reference/codesnippet/cpp/csocket-class_4.cpp)]

## <a name="csocketcancelblockingcall"></a><a name="cancelblockingcall"></a>CSocket::Cancelandochamada de bloqueio

Ligue para esta função de membro para cancelar uma chamada de bloqueio atualmente em andamento.

```
void CancelBlockingCall();
```

### <a name="remarks"></a>Comentários

Esta função cancela qualquer operação de bloqueio pendente para este soquete. A chamada de bloqueio original terminará o mais rápido possível com o erro WSAEINTR.

No caso de `Connect` uma operação de bloqueio, a implementação do Windows Sockets encerrará a chamada de bloqueio o mais rápido possível, mas pode não ser possível que os recursos do soquete sejam liberados até que a conexão tenha sido concluída (e depois redefinida) ou programada. Isso só será perceptível se o aplicativo tentar imediatamente abrir um novo soquete (se não houver soquetes disponíveis) ou se conectar ao mesmo correspondente.

Cancelar qualquer operação `Accept` que não seja pode deixar o soquete em estado indeterminado. Se um aplicativo cancelar uma operação de bloqueio em um soquete, a única operação `Close`que o aplicativo pode depender de ser capaz de executar no soquete é uma chamada para, embora outras operações possam funcionar em algumas implementações do Windows Sockets. Se você deseja a portabilidade máxima para o seu aplicativo, você deve ter cuidado para não depender da realização de operações após um cancelamento.

Para obter mais informações, consulte [Soquetes do Windows: Usando soquetes com arquivos](../../mfc/windows-sockets-using-sockets-with-archives.md).

## <a name="csocketcreate"></a><a name="create"></a>CSocket::Criar

Ligue para a função **Criar** membro depois de construir um objeto de soquete para criar o soquete do Windows e anexá-lo.

```
BOOL Create(
    UINT nSocketPort = 0,
    int nSocketType = SOCK_STREAM,
    LPCTSTR lpszSocketAddress = NULL);
```

### <a name="parameters"></a>Parâmetros

*nSocketPort*<br/>
Uma porta específica a ser usada com o soquete, ou 0 se você quiser que o MFC selecione uma porta.

*nSocketType*<br/>
SOCK_STREAM ou SOCK_DGRAM.

*lpszSocketAddress*<br/>
Um ponteiro para uma seqüência contendo o endereço de rede do soquete conectado, um número pontilhado como "128.56.22.8". Passar a seqüência NULL `CSocket` para este parâmetro indica que a instância deve ouvir a atividade do cliente em todas as interfaces de rede.

### <a name="return-value"></a>Valor retornado

Não zero se a função for bem sucedida; caso contrário 0, e um código de `GetLastError`erro específico pode ser recuperado chamando .

### <a name="remarks"></a>Comentários

`Create`em `Bind` seguida, chama para vincular o soquete ao endereço especificado. Os seguintes tipos de soquete são suportados:

- SOCK_STREAM fornece fluxos de bytes seqüenciados, confiáveis, bidirecionais baseados em conexão. Usa o TCP (Transmission Control Protocol, protocolo de controle de transmissão) para a família de endereços da Internet.

- SOCK_DGRAM suporta datagramas, que são buffers não confiáveis e sem conexão de um comprimento máximo fixo (tipicamente pequeno). Usa o User Datagram Protocol (UDP) para a família de endereços da Internet. Para usar esta opção, você não `CArchive` deve usar o soquete com um objeto.

    > [!NOTE]
    >  A `Accept` função membro tem como parâmetro `CSocket` uma referência a um objeto novo e vazio. Você deve construir este `Accept`objeto antes de chamar. Tenha em mente que se este objeto de soquete sair do escopo, a conexão se fecha. Não chame `Create` por este novo objeto de soquete.

Para obter mais informações sobre soquetes de fluxo e datagram, consulte os artigos [Soquetes do Windows: Fundo,](../../mfc/windows-sockets-background.md) [Soquetes do Windows: Portas e Soquetes](../../mfc/windows-sockets-ports-and-socket-addresses.md)e [Soquetes do Windows: Usando Soquetes com Arquivos](../../mfc/windows-sockets-using-sockets-with-archives.md).

## <a name="csocketcsocket"></a><a name="csocket"></a>CSocket::CSocket

Constrói um objeto `CSocket`.

```
CSocket();
```

### <a name="remarks"></a>Comentários

Após a construção, `Create` você deve chamar a função de membro.

Para obter mais informações, consulte [Soquetes do Windows: Usando soquetes com arquivos](../../mfc/windows-sockets-using-sockets-with-archives.md).

## <a name="csocketfromhandle"></a><a name="fromhandle"></a>CSocket::FromHandle

Retorna um ponteiro `CSocket` para um objeto.

```
static CSocket* PASCAL FromHandle(SOCKET hSocket);
```

### <a name="parameters"></a>Parâmetros

*hSocket*<br/>
Contém uma alça em um soquete.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CSocket` para um objeto ou `CSocket` NULL se não houver nenhum objeto conectado ao *hSocket*.

### <a name="remarks"></a>Comentários

Quando dado um cabo `CSocket` SOCKET, se um objeto não estiver conectado à alça, a função do membro retorna NULL e não cria um objeto temporário.

Para obter mais informações, consulte [Soquetes do Windows: Usando soquetes com arquivos](../../mfc/windows-sockets-using-sockets-with-archives.md).

## <a name="csocketisblocking"></a><a name="isblocking"></a>CSocket::IsBlocking

Ligue para esta função de membro para determinar se uma chamada de bloqueio está em andamento.

```
BOOL IsBlocking();
```

### <a name="return-value"></a>Valor retornado

Não zero se o soquete estiver bloqueando; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Soquetes do Windows: Usando soquetes com arquivos](../../mfc/windows-sockets-using-sockets-with-archives.md).

## <a name="csocketonmessagepending"></a><a name="onmessagepending"></a>csocket::OnMessagePending

Anular esta função de membro para procurar mensagens específicas do Windows e respondê-las em seu soquete.

```
virtual BOOL OnMessagePending();
```

### <a name="return-value"></a>Valor retornado

Não zero se a mensagem foi tratada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este é um avançado super-rididável.

A estrutura `OnMessagePending` chama enquanto o soquete está bombeando mensagens do Windows para lhe dar a oportunidade de lidar com mensagens de interesse para o seu aplicativo. Para exemplos de como `OnMessagePending`você pode usar, consulte o artigo [Soquetes do Windows: Derivado de Classes de Soquete](../../mfc/windows-sockets-deriving-from-socket-classes.md).

Para obter mais informações, consulte [Soquetes do Windows: Usando soquetes com arquivos](../../mfc/windows-sockets-using-sockets-with-archives.md).

## <a name="see-also"></a>Confira também

[Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)<br/>
[Classe CSocketFile](../../mfc/reference/csocketfile-class.md)
