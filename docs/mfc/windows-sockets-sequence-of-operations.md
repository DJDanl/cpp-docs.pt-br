---
title: 'Windows Sockets: Sequência de operações | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Windows Sockets [MFC], operations
- Windows Sockets [MFC], stream sockets
- sockets [MFC], stream sockets
- sockets [MFC], operations
- stream sockets [MFC]
ms.assetid: 43ce76f5-aad3-4247-b8a6-16cc7d012796
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 93fe2221e25951a53340d5da97f7d5c48ce477cf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33385252"
---
# <a name="windows-sockets-sequence-of-operations"></a>Windows Sockets: sequência de operações
Este artigo ilustra, lado a lado, a sequência de operações para um soquete de servidor e um soquete do cliente. Como usam os soquetes `CArchive` objetos, eles são necessariamente [soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md).  
  
## <a name="sequence-of-operations-for-a-stream-socket-communication"></a>Sequência de operações para uma comunicação de soquete de fluxo  
 Até o ponto de construir um `CSocketFile` do objeto, a sequência a seguir é precisa (com algumas diferenças de parâmetro) para ambos `CAsyncSocket` e `CSocket`. Daí em diante, a sequência é estritamente para `CSocket`. A tabela a seguir ilustra a sequência de operações para configurar a comunicação entre um cliente e um servidor.  
  
### <a name="setting-up-communication-between-a-server-and-a-client"></a>Configurando a comunicação entre um servidor e um cliente  
  
|Servidor|Cliente|  
|------------|------------|  
|`// construct a socket`<br /><br /> `CSocket sockSrvr;`|`// construct a socket`<br /><br /> `CSocket sockClient;`|  
|`// create the SOCKET`<br /><br /> `sockSrvr.Create(nPort);`1,2|`// create the SOCKET`<br /><br /> `sockClient.Create( );`2|  
|`// start listening`<br /><br /> `sockSrvr.Listen( );`||  
||`// seek a connection`<br /><br /> `sockClient.Connect(strAddr, nPort);`3,4|  
|`// construct a new, empty socket`<br /><br /> `CSocket sockRecv;`<br /><br /> `// accept connection`<br /><br /> `sockSrvr.Accept( sockRecv );` 5||  
|`// construct file object`<br /><br /> `CSocketFile file(&sockRecv);`|`// construct file object`<br /><br /> `CSocketFile file(&sockClient);`|  
|`// construct an archive`<br /><br /> `CArchive arIn(&file, CArchive::load);`<br /><br /> -ou-<br /><br /> `CArchive arOut(&file, CArchive::store);`<br /><br /> - ou ambos-|`// construct an archive`<br /><br /> `CArchive arIn(&file, CArchive::load);`<br /><br /> -ou-<br /><br /> `CArchive arOut(&file, CArchive::store);`<br /><br /> - ou ambos-|  
|`// use the archive to pass data:`<br /><br /> `arIn >> dwValue;`<br /><br /> -ou-<br /><br /> `arOut << dwValue;`6|`// use the archive to pass data:`<br /><br /> `arIn >> dwValue;`<br /><br /> -ou-<br /><br /> `arOut << dwValue;`6|  
  
 1. Onde `nPort` é um número de porta. Consulte [Windows Sockets: portas e endereços de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md) para obter detalhes sobre portas.  
  
 2. O servidor sempre deve especificar uma porta para que os clientes possam se conectar. O **criar** chamada às vezes também especifica um endereço. No lado do cliente, use os parâmetros padrão, que peça MFC para usar qualquer porta disponível.  
  
 3. Onde `nPort` é um número de porta e *strAddr* é um endereço de máquina ou um endereço IP (Internet Protocol).  
  
 4. Endereços da máquina podem levar vários formulários: "ftp.microsoft.com", "microsoft.com". Endereços IP usam o formulário "pontilhado número" "127.54.67.32". O **conectar** função verifica se o endereço é um número pontilhado (embora ele não verifica para garantir que o número é uma máquina válida na rede). Caso contrário, **conectar** assume um nome de computador de uma das outras formas.  
  
 5. Quando você chama **aceitar** no lado do servidor, você passa uma referência para um novo objeto de soquete. Você deve construir esse objeto pela primeira vez, mas não chame **criar** para ele. Tenha em mente que, se esse objeto de soquete sai do escopo, fecha a conexão. MFC conecta o novo objeto para um **soquete** tratar. Você pode construir o soquete na pilha, conforme mostrado, ou na pilha.  
  
 6. O arquivo e o arquivo de soquete são fechados quando saem do escopo. Destruidor do objeto de soquete também chama o [fechar](../mfc/reference/casyncsocket-class.md#close) função de membro para o objeto de soquete quando o objeto sai do escopo ou é excluído.  
  
## <a name="additional-notes-about-the-sequence"></a>Observações adicionais sobre a sequência  
 A sequência de chamadas mostrado na tabela anterior é para um soquete de fluxo. Soquetes de datagrama, que não têm conexão, não requerem o [CAsyncSocket::Connect](../mfc/reference/casyncsocket-class.md#connect), [escutar](../mfc/reference/casyncsocket-class.md#listen), e [aceitar](../mfc/reference/casyncsocket-class.md#accept) chamadas (embora você possa usar opcionalmente **Conectar**). Em vez disso, se você estiver usando a classe `CAsyncSocket`, soquetes de datagrama usam o `CAsyncSocket::SendTo` e `ReceiveFrom` funções de membro. (Se você usar **conectar** com um soquete de datagrama, você deve usar **enviar** e **Receive**.) Porque `CArchive` não funciona com datagramas, não use `CSocket` com um arquivo se o soquete é um datagrama.  
  
 [CSocketFile](../mfc/reference/csocketfile-class.md) não dá suporte a todos os `CFile`da funcionalidade; `CFile` membros como `Seek`, que não fazem sentido para uma comunicação de soquete, não estão disponíveis. Por isso, alguns padrão MFC `Serialize` funções não são compatíveis com `CSocketFile`. Isso é particularmente verdadeiro a `CEditView` classe. Você não deve tentar serializar `CEditView` dados por meio de um `CArchive` objeto anexado a um `CSocketFile` objeto usando `CEditView::SerializeRaw`; use **CEditView::Serialize** em vez disso, (não documentado). O [SerializeRaw](../mfc/reference/ceditview-class.md#serializeraw) a função espera o objeto de arquivo com funções, como `Seek`, que `CSocketFile` não oferece suporte.  
  
 Para obter mais informações, consulte:  
  
-   [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
-   [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
-   [Windows Sockets: portas e endereços de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md)  
  
-   [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)   
 [Classe CSocket](../mfc/reference/csocket-class.md)   
 [CAsyncSocket::Create](../mfc/reference/casyncsocket-class.md#create)   
 [CAsyncSocket::Close](../mfc/reference/casyncsocket-class.md#close)

