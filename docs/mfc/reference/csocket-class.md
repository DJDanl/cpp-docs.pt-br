---
title: Classe CSocket | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- WinSock CSocket class
- CSocket class
- SOCKET handle
- sockets classes
ms.assetid: 7f23c081-d24d-42e3-b511-8053ca53d729
caps.latest.revision: 30
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 451ea100dbf02e365204fe4fdf1c380e855d8231
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="csocket-class"></a>Classe CSocket
Deriva de `CAsyncSocket`, herda o encapsulamento de API do Windows Sockets e representa um nível mais alto de abstração do que uma `CAsyncSocket` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSocket : public CAsyncSocket  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSocket::CSocket](#csocket)|Constrói um objeto `CSocket`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSocket::Attach](#attach)|Anexa uma **soquete** identificador para uma `CSocket` objeto.|  
|[CSocket::CancelBlockingCall](#cancelblockingcall)|Cancela uma chamada de bloqueio está em andamento.|  
|[CSocket::Create](#create)|Cria um soquete.|  
|[CSocket::FromHandle](#fromhandle)|Retorna um ponteiro para um `CSocket` objeto, dado um **soquete** tratar.|  
|[CSocket::IsBlocking](#isblocking)|Determina se uma chamada de bloqueio está em andamento.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSocket::OnMessagePending](#onmessagepending)|Chamado para processar as mensagens pendentes enquanto aguarda a conclusão de uma chamada de bloqueio.|  
  
## <a name="remarks"></a>Comentários  
 `CSocket`funciona com classes `CSocketFile` e `CArchive` para gerenciar o envio e recebimento de dados.  
  
 A `CSocket` objeto também fornece o bloqueio, que é essencial para a operação síncrona de `CArchive`. Bloqueio de funções, como `Receive`, `Send`, `ReceiveFrom`, `SendTo`, e `Accept` (todas as herdadas de `CAsyncSocket`), não retornam um `WSAEWOULDBLOCK` erro na `CSocket`. Em vez disso, essas funções Aguarde até que a operação seja concluída. Além disso, a chamada original será encerrado com o erro `WSAEINTR` se `CancelBlockingCall` é chamado quando uma dessas funções está bloqueando.  
  
 Para usar um `CSocket` de objeto, chame o construtor chame `Create` criar subjacente `SOCKET` tratar (tipo `SOCKET`). Os parâmetros padrão de `Create` criar um soquete de fluxo, mas se você não estiver usando o soquete com uma `CArchive` objeto, você pode especificar um parâmetro para criar um soquete de datagrama em vez disso, ou vincular a uma porta específica para criar um servidor de soquete. Conectar-se a um soquete de cliente usando `Connect` no lado do cliente e `Accept` no lado do servidor. Crie um `CSocketFile` do objeto e associá-la para o `CSocket` o objeto no `CSocketFile` construtor. Em seguida, crie um `CArchive` objeto para o envio e outra para receber dados (conforme necessário), em seguida, associá-los com o `CSocketFile` objeto o `CArchive` construtor. Quando as comunicações forem concluídas, destruir o `CArchive`, `CSocketFile`, e `CSocket` objetos. O `SOCKET` tipo de dados é descrito no artigo [Windows Sockets: plano de fundo](../../mfc/windows-sockets-background.md).  
  
 Quando você usa `CArchive` com `CSocketFile` e `CSocket`, você pode encontrar uma situação onde `CSocket::Receive` entra em um loop (pelo `PumpMessages(FD_READ)`) aguardando a quantidade de bytes solicitada. Isso ocorre porque o Windows sockets permite somente uma chamada de recebimento por notificação FD_READ, mas `CSocketFile` e `CSocket` permitir várias chamadas de recebimento por FD_READ. Se você receber um FD_READ quando não há nenhum dado a ser lido, o aplicativo trava. Se você nunca receber outra FD_READ, o aplicativo para se comunicar por soquete.  
  
 Você pode resolver esse problema, da seguinte maneira. No `OnReceive` método da classe do soquete, chamada `CAsyncSocket::IOCtl(FIONREAD, ...)` antes de chamar o `Serialize` método de sua classe de mensagem quando os dados esperados para leitura a partir do soquete excedem o tamanho de um pacote TCP (unidade máxima de transmissão de mídia de rede geralmente pelo menos 1096 bytes). Se o tamanho dos dados disponíveis é menor que o necessário, aguarde todos os dados recebidos e apenas iniciar a operação de leitura.  
  
 No exemplo a seguir, `m_dwExpected` é o número aproximado de bytes que o usuário espera receber. Supõe-se que você declare-o em outro lugar no seu código.  
  
 [!code-cpp[NVC_MFCSocketThread n º&4;](../../mfc/reference/codesnippet/cpp/csocket-class_1.cpp)]  
  
> [!NOTE]
>  Ao usar soquetes MFC em threads secundários em um aplicativo MFC vinculado estaticamente, você deve chamar `AfxSocketInit` em cada thread que usa soquetes para inicializar as bibliotecas de soquete. Por padrão, `AfxSocketInit` é chamado somente no thread primário.  
  
 Para obter mais informações, consulte [Windows Sockets em MFC](../../mfc/windows-sockets-in-mfc.md), [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md), [Windows Sockets: como soquetes com arquivos mortos trabalho](../../mfc/windows-sockets-how-sockets-with-archives-work.md), [Windows Sockets: sequência de operações](../../mfc/windows-sockets-sequence-of-operations.md), [Windows Sockets: exemplo de soquetes usando arquivos](../../mfc/windows-sockets-example-of-sockets-using-archives.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CAsyncSocket](../../mfc/reference/casyncsocket-class.md)  
  
 `CSocket`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxsock.h  
  
##  <a name="attach"></a>CSocket::Attach  
 Chame essa função de membro para anexar o `hSocket` identificador para uma `CSocket` objeto.  
  
```  
BOOL Attach(SOCKET hSocket);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hSocket`  
 Contém um identificador para um soquete.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O **soquete** identificador é armazenado no objeto de [m_hSocket](../../mfc/reference/casyncsocket-class.md#m_hsocket) membro de dados.  
  
 Para obter mais informações, consulte [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCSocketThread n º&1;](../../mfc/reference/codesnippet/cpp/csocket-class_2.h)]  
  
 [!code-cpp[NVC_MFCSocketThread n º&2;](../../mfc/reference/codesnippet/cpp/csocket-class_3.cpp)]  
  
 [!code-cpp[NVC_MFCSocketThread n º&3;](../../mfc/reference/codesnippet/cpp/csocket-class_4.cpp)]  
  
##  <a name="cancelblockingcall"></a>CSocket::CancelBlockingCall  
 Chame essa função de membro para cancelar uma chamada de bloqueio atualmente em andamento.  
  
```  
void CancelBlockingCall();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função cancela qualquer operação pendente de bloqueio para esse soquete. A chamada de bloqueio original será encerrado assim que possível com o erro **WSAEINTR**.  
  
 No caso de um bloqueio **conectar** operação, a implementação do Windows Sockets encerrará a chamada de bloqueio assim que possível, mas ele pode não ser possível para os recursos de soquete ser liberado até que a conexão foi concluída (e, em seguida, foi redefinida) ou atingiu o tempo limite. Isso é provavelmente será percebido somente se o aplicativo imediatamente tenta abrir um soquete novo (se nenhum soquetes disponíveis), ou para se conectar ao mesmo ponto.  
  
 Cancelar qualquer operação que **aceitar** pode deixar o soquete em um estado indeterminado. Se um aplicativo cancela uma operação em um soquete de bloqueio, a única operação que o aplicativo pode depender de poder executar no soquete é uma chamada para **fechar**, embora outras operações podem funcionar em algumas implementações de Windows Sockets. Se você desejar portabilidade máximo para o seu aplicativo, você deve ser cuidado para não dependem de executar operações após um cancelamento.  
  
 Para obter mais informações, consulte [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).  
  
##  <a name="create"></a>CSocket::Create  
 Chamar o **criar** função de membro depois de criar um objeto de soquete para criar o soquete do Windows e anexá-lo.  
  
```  
BOOL Create(
    UINT nSocketPort = 0,  
    int nSocketType = SOCK_STREAM,  
    LPCTSTR lpszSocketAddress = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSocketPort`  
 Uma porta específica a ser usada com o soquete ou 0 se desejar que o MFC para selecionar uma porta.  
  
 `nSocketType`  
 **SOCK_STREAM** ou **SOCK_DGRAM**.  
  
 `lpszSocketAddress`  
 Um ponteiro para uma cadeia de caracteres que contém o endereço de rede do soquete conectado, um número pontilhado, como "128.56.22.8". Passando o **nulo** cadeia de caracteres para esse parâmetro indica o **CSocket** instância deve ouvir para atividade de cliente em todas as interfaces de rede.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0 e um código de erro específico podem ser recuperada chamando `GetLastError`.  
  
### <a name="remarks"></a>Comentários  
 **Criar** , em seguida, chama **ligar** ligar o soquete para o endereço especificado. Os seguintes tipos de soquete são suportados:  
  
- **SOCK_STREAM** fornece sequenciado, fluxos de bytes bidirecionais, confiável e baseada em conexão. Usa o protocolo de controle de transmissão (TCP) para a família de endereço de Internet.  
  
- **SOCK_DGRAM** suporta datagramas, que são buffers sem conexão e não confiáveis de comprimento máximo fixo (normalmente pequeno). Usa o protocolo de datagrama de usuário (UDP) para a família de endereço de Internet. Para usar essa opção, você não deve usar o soquete com uma `CArchive` objeto.  
  
    > [!NOTE]
    >  O **aceitar** função de membro pega uma referência para um novo e vazio `CSocket` objeto como seu parâmetro. Você deve construir esse objeto antes de chamar **aceitar**. Tenha em mente que, se esse objeto de soquete sai do escopo, fecha a conexão. Não chame **criar** para esse novo objeto de soquete.  
  
 Para obter mais informações sobre os soquetes de datagrama e de fluxo, consulte os artigos [Windows Sockets: plano de fundo](../../mfc/windows-sockets-background.md), [Windows Sockets: portas e endereços de soquete](../../mfc/windows-sockets-ports-and-socket-addresses.md), e [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).  
  
##  <a name="csocket"></a>CSocket::CSocket  
 Constrói um objeto `CSocket`.  
  
```  
CSocket();
```  
  
### <a name="remarks"></a>Comentários  
 Após a compilação, você deve chamar o **criar** função de membro.  
  
 Para obter mais informações, consulte [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).  
  
##  <a name="fromhandle"></a>CSocket::FromHandle  
 Retorna um ponteiro para um `CSocket` objeto.  
  
```  
static CSocket* PASCAL FromHandle(SOCKET hSocket);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hSocket`  
 Contém um identificador para um soquete.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CSocket` objeto, ou **nulo** se não houver nenhum `CSocket` objeto anexado a `hSocket`.  
  
### <a name="remarks"></a>Comentários  
 Quando é atribuído um **soquete** tratar, se um `CSocket` objeto não está anexado ao identificador, retorna a função de membro **nulo** e não cria um objeto temporário.  
  
 Para obter mais informações, consulte [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).  
  
##  <a name="isblocking"></a>CSocket::IsBlocking  
 Chame essa função de membro para determinar se uma chamada de bloqueio está em andamento.  
  
```  
BOOL IsBlocking();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o bloqueio de soquete; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).  
  
##  <a name="onmessagepending"></a>CSocket::OnMessagePending  
 Substitua essa função de membro para procurar mensagens específicas do Windows e respondê-los em seu soquete.  
  
```  
virtual BOOL OnMessagePending();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a mensagem foi tratada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Isso é uma avançada substituível.  
  
 O framework chama `OnMessagePending` enquanto o soquete está bombeando mensagens do Windows para lhe dar uma oportunidade para lidar com mensagens de interesse para o seu aplicativo. Para obter exemplos de como você pode usar `OnMessagePending`, consulte o artigo [Windows Sockets: derivando de Classes de soquete](../../mfc/windows-sockets-deriving-from-socket-classes.md).  
  
 Para obter mais informações, consulte [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)   
 [Classe CSocketFile](../../mfc/reference/csocketfile-class.md)

