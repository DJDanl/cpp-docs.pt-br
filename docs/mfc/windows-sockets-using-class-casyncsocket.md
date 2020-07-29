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
ms.openlocfilehash: 6a3b3469b908eaf6f8062b8db7fc4287606b7f02
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228499"
---
# <a name="windows-sockets-using-class-casyncsocket"></a>Windows Sockets: usando classe CAsyncSocket

Este artigo explica como usar a classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md). Lembre-se de que essa classe encapsula a API do Windows Sockets em um nível muito baixo. `CAsyncSocket`é para uso por programadores que conhecem comunicações de rede em detalhes, mas que desejam a conveniência de retornos de chamada para notificação de eventos de rede. Com base nessa suposição, este artigo fornece apenas instruções básicas. Você provavelmente deve considerar o uso `CAsyncSocket` do se quiser que o Windows Sockets facilite a facilidade de lidar com vários protocolos de rede em um aplicativo MFC, mas não deseja sacrificar a flexibilidade. Você também pode sentir que pode obter melhor eficiência ao programar as comunicações mais diretamente do que poderia usar o modelo alternativo mais geral da classe `CSocket` .

`CAsyncSocket`está documentado na *referência do MFC*. O Visual C++ também fornece a especificação do Windows Sockets, localizada na SDK do Windows. Os detalhes são deixados para você. Visual C++ não fornece um aplicativo de exemplo para o `CAsyncSocket` .

Se você não estiver altamente experiente em relação às comunicações de rede e quiser uma solução simples, use a classe [CSocket](../mfc/reference/csocket-class.md) com um `CArchive` objeto. Consulte [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md) para obter mais informações.

Este artigo cobre:

- Criando e usando um `CAsyncSocket` objeto.

- [Suas responsabilidades com o CAsyncSocket](#_core_your_responsibilities_with_casyncsocket).

## <a name="creating-and-using-a-casyncsocket-object"></a><a name="_core_creating_and_using_a_casyncsocket_object"></a>Criando e usando um objeto CAsyncSocket

#### <a name="to-use-casyncsocket"></a>Para usar o CAsyncSocket

1. Construa um objeto [CAsyncSocket](../mfc/reference/casyncsocket-class.md) e use o objeto para criar o identificador de **soquete** subjacente.

   A criação de um soquete segue o padrão MFC de construção de dois estágios.

   Por exemplo:

   [!code-cpp[NVC_MFCSimpleSocket#3](../mfc/codesnippet/cpp/windows-sockets-using-class-casyncsocket_1.cpp)]

     -ou-

   [!code-cpp[NVC_MFCSimpleSocket#4](../mfc/codesnippet/cpp/windows-sockets-using-class-casyncsocket_2.cpp)]

   O primeiro Construtor acima cria um `CAsyncSocket` objeto na pilha. O segundo construtor cria um `CAsyncSocket` no heap. A primeira chamada [Create](../mfc/reference/casyncsocket-class.md#create) acima usa os parâmetros padrão para criar um soquete de fluxo. A segunda `Create` chamada cria um soquete de datagrama com uma porta e um endereço especificados. (Você pode usar qualquer `Create` versão com o método de construção.)

   Os parâmetros para `Create` são:

   - Uma "porta": um inteiro curto.

      Para um soquete de servidor, você deve especificar uma porta. Para um soquete de cliente, você normalmente aceita o valor padrão para esse parâmetro, que permite que o Windows Sockets selecione uma porta.

   - Um tipo de soquete: **SOCK_STREAM** (o padrão) ou **SOCK_DGRAM**.

   - Um soquete "address", como "ftp.microsoft.com" ou "128.56.22.8".

      Esse é o endereço IP (Internet Protocol) na rede. Provavelmente, você sempre dependerá do valor padrão para esse parâmetro.

   Os termos "porta" e "endereço de soquete" são explicados em [Windows Sockets: portas e endereços de soquete](../mfc/windows-sockets-ports-and-socket-addresses.md).

1. Se o soquete for um cliente, conecte o objeto de soquete a um soquete de servidor, usando [CAsyncSocket:: Connect](../mfc/reference/casyncsocket-class.md#connect).

     -ou-

   Se o soquete for um servidor, defina o soquete para começar a escutar (com [CAsyncSocket:: Listen](../mfc/reference/casyncsocket-class.md#listen)) para tentativas de conexão de um cliente. Após receber uma solicitação de conexão, aceite-a com [CAsyncSocket:: Accept](../mfc/reference/casyncsocket-class.md#accept).

   Depois de aceitar uma conexão, você pode executar tarefas como validar senhas.

    > [!NOTE]
    >  A `Accept` função member usa uma referência a um novo objeto vazio `CSocket` como seu parâmetro. Você deve construir esse objeto antes de chamar `Accept` . Se esse objeto de soquete sair do escopo, a conexão será fechada. Não chame `Create` esse novo objeto de soquete. Para obter um exemplo, consulte o artigo [Windows Sockets: Sequence of Operations](../mfc/windows-sockets-sequence-of-operations.md).

1. Realize comunicações com outros soquetes chamando as `CAsyncSocket` funções de membro do objeto que encapsulam as funções da API do Windows Sockets.

   Consulte a especificação do Windows Sockets e a classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md) na *referência do MFC*.

1. Destrua o `CAsyncSocket` objeto.

   Se você criou o objeto Socket na pilha, seu destruidor será chamado quando a função que a contém sair do escopo. Se você criou o objeto Socket no heap, usando o **`new`** operador, você é responsável por usar o **`delete`** operador para destruir o objeto.

   O destruidor chama a função de membro [Close](../mfc/reference/casyncsocket-class.md#close) do objeto antes de destruir o objeto.

Para obter um exemplo dessa sequência no código (na verdade, para um `CSocket` objeto), consulte [Windows Sockets: Sequence of Operations](../mfc/windows-sockets-sequence-of-operations.md).

## <a name="your-responsibilities-with-casyncsocket"></a><a name="_core_your_responsibilities_with_casyncsocket"></a>Suas responsabilidades com o CAsyncSocket

Quando você cria um objeto da classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md), o objeto encapsula um identificador de **soquete** do Windows e fornece operações nesse identificador. Ao usar `CAsyncSocket` o, você deve lidar com todos os problemas que pode enfrentar se estiver usando a API diretamente. Por exemplo:

- Cenários de "bloqueio".

- Diferenças de ordem de byte entre os computadores de envio e de recebimento.

- Conversão entre cadeias de caracteres de configuração Unicode e de bytes de multibyte (MBCS).

Para obter definições desses termos e informações adicionais, consulte [Windows Sockets: blocking](../mfc/windows-sockets-blocking.md), [Windows Sockets: Order](../mfc/windows-sockets-byte-ordering.md) [restring, Windows Sockets: convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md).

Apesar desses problemas, `CAsycnSocket` a classe pode ser a escolha certa para você se seu aplicativo exigir toda a flexibilidade e o controle que você pode obter. Caso contrário, você deve considerar o uso da classe `CSocket` em vez disso. `CSocket`oculta muitos detalhes de você: ele bombas mensagens do Windows durante chamadas de bloqueio e concede a você acesso `CArchive` , que gerencia diferenças de ordem de byte e conversão de cadeia de caracteres para você.

Para obter mais informações, consulte:

- [Windows Sockets: Informações preliminares](../mfc/windows-sockets-background.md)

- [Windows Sockets: Stream Sockets](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Confira também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)
