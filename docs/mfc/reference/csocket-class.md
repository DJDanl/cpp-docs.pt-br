---
title: "Classe de CSocket | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CSocket"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSocket"
  - "Identificador de SOQUETE"
  - "classes de soquetes"
  - "Classe de CSocket de Winsock"
ms.assetid: 7f23c081-d24d-42e3-b511-8053ca53d729
caps.latest.revision: 30
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSocket
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Deriva de `CAsyncSocket`, herda\-se o encapsulamento da API do windows, e representa\-se um nível mais alto de abstração do que a de um objeto de `CAsyncSocket` .  
  
## Sintaxe  
  
```  
class CSocket : public CAsyncSocket  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSocket::CSocket](../Topic/CSocket::CSocket.md)|constrói um objeto de `CSocket` .|  
  
### métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSocket::Attach](../Topic/CSocket::Attach.md)|Anexa um tratador de **SOCKET** a um objeto de `CSocket` .|  
|[CSocket::CancelBlockingCall](../Topic/CSocket::CancelBlockingCall.md)|Cancela uma chamada de bloqueio que está atualmente em andamento.|  
|[CSocket::Create](../Topic/CSocket::Create.md)|cria um soquete.|  
|[CSocket::FromHandle](../Topic/CSocket::FromHandle.md)|Retorna um ponteiro para um objeto de `CSocket` , dado um identificador de **SOCKET** .|  
|[CSocket::IsBlocking](../Topic/CSocket::IsBlocking.md)|Determina se uma chamada de bloqueio está em andamento.|  
  
### métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSocket::OnMessagePending](../Topic/CSocket::OnMessagePending.md)|Chamado para processar mensagens enquanto espera durante uma chamada de bloqueio para concluir.|  
  
## Comentários  
 `CSocket` trabalha com classes `CSocketFile` e `CArchive` para gerenciar enviar e receber os dados.  
  
 Um objeto de `CSocket` também fornece o bloqueio, que é essencial para a operação de `CArchive`síncrona.  O bloqueio funciona, como `Receive`, `Send`, `ReceiveFrom`, `SendTo`, e `Accept` qualquer `CAsyncSocket`\(herdadas de\), não retorna um erro de `WSAEWOULDBLOCK` em `CSocket`.  Em vez de isso, essas funções espera até que a operação seja concluído.  Além de isso, a chamada original terminará com o erro `WSAEINTR` se `CancelBlockingCall` é chamado quando uma de essas funções bloquear.  
  
 Para usar um objeto de `CSocket` , chamar o construtor, então a chamada `Create` para criar o identificador de tipo subjacente `SOCKET` \( `SOCKET`\).  Os parâmetros padrão de `Create` criam um soquete de fluxo, mas se você não estiver usando o soquete com um objeto de `CArchive` , você pode especificar um parâmetro para criar vez de um soquete de datagrama, ou associação a uma porta específica para criar um soquete do servidor.  Se conectar a um soquete de cliente usando `Connect` no lado do cliente e `Accept` no lado do servidor.  Então criar um objeto de `CSocketFile` e associá\-lo ao objeto de `CSocket` no construtor de `CSocketFile` .  Em seguida, cria um objeto de `CArchive` para enviar e um para receber dados \(quando necessário\), e associá\-los ao objeto de `CSocketFile` no construtor de `CArchive` .  Quando as comunicações está concluída, destrua `CArchive`, `CSocketFile`, e objetos de `CSocket` .  O tipo de dados de `SOCKET` é descrito no artigo [Soquetes do windows: plano de fundo](../../mfc/windows-sockets-background.md).  
  
 Quando você usa `CArchive` com `CSocketFile` e `CSocket`, você pode encontrar uma situação onde `CSocket::Receive` incorpora um loop \(por `PumpMessages(FD_READ)`\) que espera a quantidade solicitada de bytes.  Isso ocorre porque os soquetes do windows permitem apenas uma chamada de recv por notificação de FD\_READ, mas `CSocketFile` e `CSocket` permitem várias chamadas de recv por FD\_READ.  Se você obtém um FD\_READ quando não há nenhum dados para ler, o aplicativo pendura.  Se você nunca é outro FD\_READ, o aplicativo pára de se comunicar sobre o soquete.  
  
 Você pode resolver esse problema como segue.  Em o método de `OnReceive` de sua classe de soquete, chamada `CAsyncSocket::IOCtl(FIONREAD, ...)` antes de chamar o método de `Serialize` da classe de mensagem quando os dados esperados a ser lidos de soquete excederem o tamanho de um pacote TCP \(Maximum Transmission Unit do meio de rede, geralmente pelo menos de 1096 bytes\).  Se o tamanho dos dados disponíveis é menos que necessário, espere todos os dados a ser recebidos e apenas iniciar a operação de leitura.  
  
 Em o exemplo, `m_dwExpected` é o número de bytes próximo que o usuário receber espera.  Assume\-se que você o declara em qualquer lugar no seu código.  
  
 [!CODE [NVC_MFCSocketThread#4](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCSocketThread#4)]  
  
> [!NOTE]
>  A o usar os soquetes MFC em segmentos secundários em um aplicativo MFC estaticamente associado, você deve chamar `AfxSocketInit` em cada segmento que usa os soquetes para inicializar as bibliotecas de soquete.  Por padrão, `AfxSocketInit` é chamado somente no segmento principal.  
  
 Para obter mais informações, consulte [Soquetes do windows no MFC](../../mfc/windows-sockets-in-mfc.md), [Soquetes do windows: usando os soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md), [Soquetes do windows: Como os arquivos mortos funcionam com soquetes](../../mfc/windows-sockets-how-sockets-with-archives-work.md), [Soquetes do windows: Seqüência das operações](../Topic/Windows%20Sockets:%20Sequence%20of%20Operations.md), [Soquetes do windows: Exemplo da usando arquivos mortos](../../mfc/windows-sockets-example-of-sockets-using-archives.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CAsyncSocket](../Topic/CAsyncSocket%20Class.md)  
  
 `CSocket`  
  
## Requisitos  
 **Cabeçalho:** afxsock.h  
  
## Consulte também  
 [Classe de CAsyncSocket](../Topic/CAsyncSocket%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CAsyncSocket](../Topic/CAsyncSocket%20Class.md)   
 [Classe de CSocketFile](../Topic/CSocketFile%20Class.md)