---
title: 'Windows Sockets: Usando classe CAsyncSocket'
ms.date: 11/04/2016
f1_keywords:
- CAsyncSocket
helpviewer_keywords:
- CAsyncSocket class [MFC], programming model
- Windows Sockets [MFC], asynchronous
- sockets [MFC], converting between Unicode and MBCS strings
- SOCKET handle
- sockets [MFC], asynchronous operation
- Windows Sockets [MFC], converting Unicode and MBCS strings
ms.assetid: 825dae17-7c1b-4b86-8d6c-da7f1afb5d8d
ms.openlocfilehash: 51274791393d95517bd8de5ae7248dc634018037
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57263098"
---
# <a name="windows-sockets-using-class-casyncsocket"></a>Windows Sockets: Usando classe CAsyncSocket

Este artigo explica como usar a classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md). Lembre-se de que essa classe encapsula a API de soquetes do Windows em um nível muito baixo. `CAsyncSocket` é para uso por programadores que souber as comunicações de rede em detalhes, mas deseja a conveniência de retornos de chamada para notificação de eventos de rede. Com base nessa suposição, este artigo fornece apenas a instrução básica. Você provavelmente deve considerar usar `CAsyncSocket` se você quiser facilitar a lidar com vários protocolos de rede em um aplicativo MFC dos soquetes do Windows, mas não deseja sacrificar a flexibilidade. Você também pode achar que você pode obter o melhor eficiência por programação as comunicações mais diretamente por conta própria, que você poderia usando o modelo de alternativo mais geral da classe `CSocket`.

`CAsyncSocket` está documentado na *referência da MFC*. Visual C++ também fornece a especificação de soquetes do Windows, localizada no SDK do Windows. Os detalhes são deixados para você. Visual C++ não fornece um aplicativo de exemplo para `CAsyncSocket`.

Se você não tiver altamente conhecimentos sobre comunicações de rede e quer uma solução simple, use a classe [CSocket](../mfc/reference/csocket-class.md) com um `CArchive` objeto. Consulte [Windows Sockets: Usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md) para obter mais informações.

Este artigo aborda:

- Criando e usando um `CAsyncSocket` objeto.

- [Suas responsabilidades com CAsyncSocket](#_core_your_responsibilities_with_casyncsocket).

##  <a name="_core_creating_and_using_a_casyncsocket_object"></a> Criando e usando um objeto CAsyncSocket

#### <a name="to-use-casyncsocket"></a>Usar CAsyncSocket

1. Construir uma [CAsyncSocket](../mfc/reference/casyncsocket-class.md) do objeto e usar o objeto para criar subjacente **soquete** manipular.

   Criação de um soquete segue o padrão MFC da construção de dois estágios.

   Por exemplo:

   [!code-cpp[NVC_MFCSimpleSocket#3](../mfc/codesnippet/cpp/windows-sockets-using-class-casyncsocket_1.cpp)]

     -ou-

   [!code-cpp[NVC_MFCSimpleSocket#4](../mfc/codesnippet/cpp/windows-sockets-using-class-casyncsocket_2.cpp)]

   O primeiro construtor acima cria um `CAsyncSocket` objeto na pilha. O segundo construtor cria um `CAsyncSocket` no heap. A primeira [criar](../mfc/reference/casyncsocket-class.md#create) chamada acima usa os parâmetros padrão para criar um soquete de fluxo. O segundo `Create` chamada cria um soquete de datagrama com uma porta especificada e o endereço. (Você pode usar o `Create` versão com qualquer um dos métodos de construção.)

   Os parâmetros a serem `Create` são:

   - Uma "porta": um inteiro curto.

         For a server socket, you must specify a port. For a client socket, you typically accept the default value for this parameter, which lets Windows Sockets select a port.

   - Um tipo de soquete: **SOCK_STREAM** (o padrão) ou **SOCK_DGRAM**.

   - Um soquete "address" como "ftp.microsoft.com" ou "128.56.22.8".

         This is your Internet Protocol (IP) address on the network. You will probably always rely on the default value for this parameter.

   Os termos "port" e "endereço de soquete" é explicado em [Windows Sockets: Portas e endereços de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md).

1. Se o soquete é um cliente, conecte-se o objeto de soquete para um servidor de soquete, usando [CAsyncSocket::Connect](../mfc/reference/casyncsocket-class.md#connect).

     -ou-

   Se o soquete é um servidor, defina o soquete no qual começar a escutar (com [CAsyncSocket::Listen](../mfc/reference/casyncsocket-class.md#listen)) para conectar-se as tentativas de um cliente. Ao receber uma solicitação de conexão, aceite-o com [CAsyncSocket::Accept](../mfc/reference/casyncsocket-class.md#accept).

   Depois de aceitar uma conexão, você pode executar tarefas como a validação de senhas.

    > [!NOTE]
    >  O `Accept` função de membro usa uma referência a um novo e vazio `CSocket` objeto como seu parâmetro. Você deve construir esse objeto antes de chamar `Accept`. Se esse objeto de soquete sai do escopo, a conexão será fechada. Não chame `Create` para esse novo objeto de soquete. Para obter um exemplo, consulte o artigo [Windows Sockets: Sequência de operações](../mfc/windows-sockets-sequence-of-operations.md).

1. Executar as comunicações com os outros soquetes chamando o `CAsyncSocket` funções de membro do objeto que encapsulam as funções de API do Windows Sockets.

   Consulte a especificação de soquetes do Windows e a classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md) na *referência da MFC*.

1. Destruir o `CAsyncSocket` objeto.

   Se você criou o objeto de soquete na pilha, seu destruidor é chamado quando a função contendo sai do escopo. Se você criou o objeto de soquete no heap, usando o **novos** operador, você é responsável por usar o **excluir** operador para destruir o objeto.

   O destruidor chama o objeto [fechar](../mfc/reference/casyncsocket-class.md#close) função de membro antes de destruir o objeto.

Para obter um exemplo dessa sequência no código (na verdade, para um `CSocket` objeto), consulte [Windows Sockets: Sequência de operações](../mfc/windows-sockets-sequence-of-operations.md).

##  <a name="_core_your_responsibilities_with_casyncsocket"></a> Suas responsabilidades com CAsyncSocket

Quando você cria um objeto da classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md), o objeto encapsula um Windows **soquete** manipular e fornece operações nesse identificador. Quando você usa `CAsyncSocket`, você deve lidar com todos os problemas que você poderá enfrentar se usando a API diretamente. Por exemplo:

- Cenários de "Bloqueio".

- Diferenças de ordem de byte entre o envio e recebimento máquinas.

- Convertendo entre Unicode e multibyte character definir cadeias de caracteres (MBCS).

Para obter definições desses termos e informações adicionais, consulte [Windows Sockets: Bloqueando](../mfc/windows-sockets-blocking.md), [Windows Sockets: A ordem de bytes](../mfc/windows-sockets-byte-ordering.md), [Windows Sockets: Convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md).

Apesar desses problemas, classe `CAsycnSocket` pode ser a escolha certa para você, se seu aplicativo requer toda a flexibilidade e controle, você pode obter. Se não, você deve considerar o uso de classe `CSocket` em vez disso. `CSocket` oculta muitos detalhes de você: it bombeia mensagens durante chamadas de bloqueio de Windows e lhe dá acesso a `CArchive`, que gerencia as diferenças de ordem de byte e conversão de cadeia de caracteres para você.

Para obter mais informações, consulte:

- [Windows Sockets: Background](../mfc/windows-sockets-background.md)

- [Windows Sockets: Stream Sockets](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: Soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)
