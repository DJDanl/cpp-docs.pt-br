---
title: 'Windows Sockets: usando classe CAsyncSocket'
ms.date: 11/04/2016
helpviewer_keywords:
- CAsyncSocket class [MFC], programming model
- Windows Sockets [MFC], asynchronous
- sockets [MFC], converting between Unicode and MBCS strings
- SOCKET handle
- sockets [MFC], asynchronous operation
- Windows Sockets [MFC], converting Unicode and MBCS strings
ms.assetid: 825dae17-7c1b-4b86-8d6c-da7f1afb5d8d
ms.openlocfilehash: d3fc32d9da54d9cf8c79e9e5de45b81c2ef64a6e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371963"
---
# <a name="windows-sockets-using-class-casyncsocket"></a>Windows Sockets: usando classe CAsyncSocket

Este artigo explica como usar a classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md). Esteja ciente de que esta classe encapsula a API do Windows Sockets em um nível muito baixo. `CAsyncSocket`é para uso por programadores que conhecem as comunicações de rede em detalhes, mas querem a conveniência de retornos de chamadas para notificação de eventos de rede. Com base nesse pressuposto, este artigo fornece apenas instruções básicas. Você provavelmente `CAsyncSocket` deve considerar o uso se quiser a facilidade do Windows Sockets de lidar com vários protocolos de rede em um aplicativo MFC, mas não quer sacrificar a flexibilidade. Você também pode sentir que pode obter melhor eficiência programando as comunicações mais diretamente `CSocket`do que você poderia usando o modelo alternativo mais geral de classe .

`CAsyncSocket`está documentado no *MFC Reference*. O Visual C++ também fornece a especificação do Windows Sockets, localizado no Windows SDK. Os detalhes são deixados para você. Visual C++ não fornece um `CAsyncSocket`aplicativo de amostra para .

Se você não tiver muito conhecimento sobre comunicações de rede e `CArchive` quiser uma solução simples, use [csocket](../mfc/reference/csocket-class.md) de classe com um objeto. Consulte [soquetes do Windows: Usando soquetes com arquivos](../mfc/windows-sockets-using-sockets-with-archives.md) para obter mais informações.

Este artigo cobre:

- Criando e `CAsyncSocket` usando um objeto.

- [Suas responsabilidades com CAsyncSocket](#_core_your_responsibilities_with_casyncsocket).

## <a name="creating-and-using-a-casyncsocket-object"></a><a name="_core_creating_and_using_a_casyncsocket_object"></a>Criando e usando um objeto CAsyncSocket

#### <a name="to-use-casyncsocket"></a>Para usar casyncSocket

1. Construa um objeto [CAsyncSocket](../mfc/reference/casyncsocket-class.md) e use o objeto para criar a alça **SOQUE.**

   A criação de um soquete segue o padrão MFC de construção em dois estágios.

   Por exemplo:

   [!code-cpp[NVC_MFCSimpleSocket#3](../mfc/codesnippet/cpp/windows-sockets-using-class-casyncsocket_1.cpp)]

     -ou-

   [!code-cpp[NVC_MFCSimpleSocket#4](../mfc/codesnippet/cpp/windows-sockets-using-class-casyncsocket_2.cpp)]

   O primeiro construtor acima `CAsyncSocket` cria um objeto na pilha. O segundo construtor `CAsyncSocket` cria um na pilha. A primeira [chamada Criar](../mfc/reference/casyncsocket-class.md#create) acima usa os parâmetros padrão para criar um soquete de fluxo. A `Create` segunda chamada cria um soquete de datagrama com uma porta e endereço especificados. (Você pode `Create` usar qualquer versão com qualquer método de construção.)

   Os parâmetros são: `Create`

   - Um "porto": um inteiro curto.

      Para um soquete de servidor, você deve especificar uma porta. Para um soquete de cliente, você normalmente aceita o valor padrão para este parâmetro, que permite que os Soquetes do Windows selecionem uma porta.

   - Um tipo de soquete: **SOCK_STREAM** (o padrão) ou **SOCK_DGRAM**.

   - Um soquete "endereço", como "ftp.microsoft.com" ou "128.56.22.8".

      Este é o endereço IP (Internet Protocol) na rede. Você provavelmente sempre vai confiar no valor padrão para este parâmetro.

   Os termos "porta" e "endereço do soquete" são explicados em [Soquetes do Windows: Portas e Endereços de Soquete](../mfc/windows-sockets-ports-and-socket-addresses.md).

1. Se o soquete for um cliente, conecte o objeto do soquete a um soquete do servidor, usando [CAsyncSocket::Connect](../mfc/reference/casyncsocket-class.md#connect).

     -ou-

   Se o soquete for um servidor, defina o soquete para começar a ouvir (com [CAsyncSocket::Listen](../mfc/reference/casyncsocket-class.md#listen)) para tentativas de conexão de um cliente. Ao receber uma solicitação de conexão, aceite-a com [CAsyncSocket:::Aceitar](../mfc/reference/casyncsocket-class.md#accept).

   Depois de aceitar uma conexão, você pode executar tarefas como validar senhas.

    > [!NOTE]
    >  A `Accept` função membro tem como parâmetro `CSocket` uma referência a um objeto novo e vazio. Você deve construir este `Accept`objeto antes de chamar. Se este objeto de soquete sair do escopo, a conexão será fechada. Não chame `Create` por este novo objeto de soquete. Por exemplo, consulte o artigo [Soquetes do Windows: Seqüência de Operações](../mfc/windows-sockets-sequence-of-operations.md).

1. Realize comunicações com outros soquetes chamando as `CAsyncSocket` funções de membro do objeto que encapsulam as funções de API do Windows Sockets.

   Consulte a especificação do Soquete do Windows e a classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md) na *referência do MFC*.

1. Destrua o `CAsyncSocket` objeto.

   Se você criou o objeto de soquete na pilha, seu destructor é chamado quando a função de contenção sai do escopo. Se você criou o objeto de soquete no heap, usando o **novo** operador, você será responsável por usar o operador **de exclusão** para destruir o objeto.

   O destruidor chama a função de membro [próximo](../mfc/reference/casyncsocket-class.md#close) do objeto antes de destruir o objeto.

Para um exemplo desta seqüência `CSocket` em código (na verdade para um objeto), consulte [Soquetes do Windows: Seqüência de Operações](../mfc/windows-sockets-sequence-of-operations.md).

## <a name="your-responsibilities-with-casyncsocket"></a><a name="_core_your_responsibilities_with_casyncsocket"></a>Suas responsabilidades com CAsyncSocket

Quando você cria um objeto de classe [CAsyncSocket,](../mfc/reference/casyncsocket-class.md)o objeto encapsula uma alça do Windows **SOCKET** e fornece as operações nessa alça. Quando você `CAsyncSocket`usa, você deve lidar com todos os problemas que você pode enfrentar se usar a API diretamente. Por exemplo:

- Cenários de "bloqueio".

- Byte ordena diferenças entre as máquinas de envio e recepção.

- Convertendo entre as strings Unicode e multibyte character set (MBCS).

Para definições destes termos e informações adicionais, consulte [Soquetes do Windows: Bloqueio,](../mfc/windows-sockets-blocking.md) [Soquetes do Windows: Pedido de Byte,](../mfc/windows-sockets-byte-ordering.md) [Soquetes do Windows: Conversão de cordas](../mfc/windows-sockets-converting-strings.md).

Apesar desses problemas, a classe `CAsycnSocket` pode ser a escolha certa para você se sua aplicação exigir toda a flexibilidade e controle que você pode obter. Se não, você deve `CSocket` considerar usar a classe em vez disso. `CSocket`esconde muitos detalhes de você: ele bombeia mensagens do `CArchive`Windows durante o bloqueio de chamadas e lhe dá acesso, o que gerencia diferenças de ordem de byte e conversão de strings para você.

Para obter mais informações, consulte:

- [Windows Sockets: plano de fundo](../mfc/windows-sockets-background.md)

- [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Confira também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)
