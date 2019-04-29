---
title: 'Windows Sockets: Sequência de operações'
ms.date: 11/04/2016
helpviewer_keywords:
- Windows Sockets [MFC], operations
- Windows Sockets [MFC], stream sockets
- sockets [MFC], stream sockets
- sockets [MFC], operations
- stream sockets [MFC]
ms.assetid: 43ce76f5-aad3-4247-b8a6-16cc7d012796
ms.openlocfilehash: 0f9fd339fdbdfee9381ea693568f40473c2397e9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62296508"
---
# <a name="windows-sockets-sequence-of-operations"></a>Windows Sockets: Sequência de operações

Este artigo ilustra, lado a lado, a sequência de operações para um soquete de servidor e um soquete de cliente. Como usam os soquetes `CArchive` objetos, eles são necessariamente [soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md).

## <a name="sequence-of-operations-for-a-stream-socket-communication"></a>Sequência de operações para uma comunicação de soquete do Stream

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
|`// construct an archive`<br /><br /> `CArchive arIn(&file, CArchive::load);`<br /><br /> - ou -<br /><br /> `CArchive arOut(&file, CArchive::store);`<br /><br /> - ou ambos-|`// construct an archive`<br /><br /> `CArchive arIn(&file, CArchive::load);`<br /><br /> - ou -<br /><br /> `CArchive arOut(&file, CArchive::store);`<br /><br /> - ou ambos-|
|`// use the archive to pass data:`<br /><br /> `arIn >> dwValue;`<br /><br /> - ou -<br /><br /> `arOut << dwValue;`6|`// use the archive to pass data:`<br /><br /> `arIn >> dwValue;`<br /><br /> - ou -<br /><br /> `arOut << dwValue;`6|

1. Em que *nPort* é um número de porta. Consulte [Windows Sockets: Portas e endereços de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md) para obter detalhes sobre as portas.

2. O servidor sempre deve especificar uma porta para que os clientes possam se conectar. O `Create` chamada às vezes, também especifica um endereço. No lado do cliente, use os parâmetros padrão, que solicitam o MFC para usar qualquer porta disponível.

3. Em que *nPort* é um número de porta e *strAddr* é um endereço de máquina ou um endereço IP (Internet Protocol).

4. Endereços de máquina podem ter diversos formatos: "ftp.microsoft.com", "microsoft.com". Endereços IP usam o formulário "com pingo número", "127.54.67.32". O `Connect` função verifica para ver se o endereço é um número pontilhado (embora ele não verifica para garantir que o número é uma máquina válida na rede). Caso contrário, `Connect` pressupõe um nome de máquina de um dos outros formulários.

5. Quando você chama `Accept` no lado do servidor, você passa uma referência a um novo objeto de soquete. Você deve construir esse objeto pela primeira vez, mas não chame `Create` para ele. Tenha em mente que, se esse objeto de soquete sai do escopo, fecha a conexão. MFC conecta-se o novo objeto para um **soquete** manipular. Você pode construir o soquete na pilha, como mostrado, ou no heap.

6. O arquivo morto e o arquivo de soquete são fechados quando eles saem do escopo. Destruidor do objeto de soquete também chama o [fechar](../mfc/reference/casyncsocket-class.md#close) função de membro para o objeto quando o objeto sai do escopo ou é excluído do soquete.

## <a name="additional-notes-about-the-sequence"></a>Observações adicionais sobre a sequência

A sequência de chamadas mostrada na tabela anterior é para um soquete de fluxo. Soquetes de datagrama, que são sem conexão, não exigem o [CAsyncSocket::Connect](../mfc/reference/casyncsocket-class.md#connect), [escutar](../mfc/reference/casyncsocket-class.md#listen), e [Accept](../mfc/reference/casyncsocket-class.md#accept) chamadas (embora você possa usar opcionalmente `Connect`). Em vez disso, se você estiver usando a classe `CAsyncSocket`, uso de soquetes de datagrama a `CAsyncSocket::SendTo` e `ReceiveFrom` funções de membro. (Se você usar `Connect` com um soquete de datagrama, você deve usar `Send` e `Receive`.) Porque `CArchive` não funciona com datagramas, não use `CSocket` com um arquivo morto se o soquete é um datagrama.

[CSocketFile](../mfc/reference/csocketfile-class.md) não dá suporte a todos os `CFile`da funcionalidade; `CFile` membros como `Seek`, que não fazem sentido para uma comunicação de soquete, não estão disponíveis. Por isso, alguns padrão MFC `Serialize` funções não são compatíveis com `CSocketFile`. Isso é particularmente verdadeiro o `CEditView` classe. Você não deve tentar serializar `CEditView` dados por meio de um `CArchive` objeto anexado a um `CSocketFile` objeto usando `CEditView::SerializeRaw`; usar `CEditView::Serialize` em vez disso (não documentada). O [SerializeRaw](../mfc/reference/ceditview-class.md#serializeraw) função espera que o objeto de arquivo ter funções, como `Seek`, que `CSocketFile` não oferece suporte.

Para obter mais informações, consulte:

- [Windows Sockets: usar soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)

- [Windows Sockets: usar a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: portas e endereços de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md)

- [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)<br/>
[Classe CSocket](../mfc/reference/csocket-class.md)<br/>
[CAsyncSocket::Create](../mfc/reference/casyncsocket-class.md#create)<br/>
[CAsyncSocket::Close](../mfc/reference/casyncsocket-class.md#close)
