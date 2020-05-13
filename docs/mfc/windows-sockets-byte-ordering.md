---
title: 'Windows Sockets: ordenação de bytes'
ms.date: 11/04/2016
helpviewer_keywords:
- byte order issues in sockets programming
- sockets [MFC], byte order issues
- Windows Sockets [MFC], byte order issues
ms.assetid: 8a787a65-f9f4-4002-a02f-ac25a5dace5d
ms.openlocfilehash: 50548202483c4d9d4471ad2c600270c4df4503e7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371062"
---
# <a name="windows-sockets-byte-ordering"></a>Windows Sockets: ordenação de bytes

Este artigo e dois artigos complementares explicam vários problemas na programação do Windows Sockets. Este artigo abrange o pedido de byte. Os outros problemas estão cobertos nos artigos: [Soquetes do Windows: Bloqueio](../mfc/windows-sockets-blocking.md) e [Soquetes do Windows: Conversão de cordas](../mfc/windows-sockets-converting-strings.md).

Se você usar ou derivar da classe [CAsyncSocket,](../mfc/reference/casyncsocket-class.md)você precisará gerenciar esses problemas você mesmo. Se você usar ou derivar da classe [CSocket,](../mfc/reference/csocket-class.md)o MFC os gerenciará para você.

## <a name="byte-ordering"></a>ordenação da regra

Diferentes arquiteturas de máquinas às vezes armazenam dados usando ordens de bytes diferentes. Por exemplo, máquinas baseadas em Intel armazenam dados na ordem inversa das máquinas Macintosh (Motorola). A ordem de byte intel, chamada "little-Endian", também é o inverso da ordem padrão de rede "big-Endian". A tabela a seguir explica estes termos.

### <a name="big--and-little-endian-byte-ordering"></a>Encomenda de byte grande e pouco-endiana

|ordenação de byte|Significado|
|-------------------|-------------|
|Grande-Endian|O byte mais significativo está na ponta esquerda de uma palavra.|
|Pequeno Endian|O byte mais significativo está no lado direito de uma palavra.|

Normalmente, você não precisa se preocupar com a conversão de byte-order para dados que você envia e recebe pela rede, mas há situações em que você deve converter pedidos de byte.

## <a name="when-you-must-convert-byte-orders"></a>Quando você deve converter ordens de byte

Você precisa converter ordens de byte nas seguintes situações:

- Você está passando informações que precisam ser interpretadas pela rede, ao contrário dos dados que você está enviando para outra máquina. Por exemplo, você pode passar por portas e endereços, que a rede deve entender.

- O aplicativo do servidor com o qual você está se comunicando não é um aplicativo MFC (e você não tem código fonte para ele). Isso exige conversões de pedidos de byte se as duas máquinas não compartilharem o mesmo pedido de byte.

## <a name="when-you-do-not-have-to-convert-byte-orders"></a>Quando você não tem que converter ordens de byte

Você pode evitar o trabalho de conversão de ordens de byte nas seguintes situações:

- As máquinas em ambas as extremidades podem concordar em não trocar bytes, e ambas as máquinas usam a mesma ordem de byte.

- O servidor com o que você está se comunicando é um aplicativo MFC.

- Você tem código fonte para o servidor com o qual está se comunicando, então você pode dizer explicitamente se você deve converter ordens de byte ou não.

- Você pode portar o servidor para MFC. Isso é bastante fácil de fazer, e o resultado geralmente é menor, código mais rápido.

Trabalhando com [CAsyncSocket,](../mfc/reference/casyncsocket-class.md)você deve gerenciar as conversões necessárias por ordem de byte. O Windows Sockets padroniza o modelo de ordem de byte "big-Endian" e fornece funções para converter entre esta ordem e outras. [CArchive](../mfc/reference/carchive-class.md), no entanto, que você usa com [CSocket,](../mfc/reference/csocket-class.md)usa a `CArchive` ordem oposta ("little-Endian"), mas cuida dos detalhes das conversões de pedidos de byte para você. Usando este pedido padrão em seus aplicativos, ou usando funções de conversão de byte-order do Windows Sockets, você pode tornar seu código mais portátil.

O caso ideal para o uso de soquetes MFC é quando você está escrevendo ambas as extremidades da comunicação: usando MFC em ambas as extremidades. Se você estiver escrevendo um aplicativo que se comunicará com aplicativos não-MFC, como um servidor FTP, provavelmente precisará gerenciar a troca de bytes antes de passar dados para o objeto de arquivamento, usando as rotinas de conversão do Windows Sockets **ntohs,** **ntohl,** **htons**e **htonl**. Um exemplo dessas funções usadas na comunicação com um aplicativo não-MFC aparece mais tarde neste artigo.

> [!NOTE]
> Quando a outra extremidade da comunicação não é um aplicativo MFC, você `CObject` também deve evitar transmitir objetos C++ derivados do seu arquivo porque o receptor não será capaz de manuseá-los. Veja a nota em [Soquetes do Windows: Usando soquetes com arquivos](../mfc/windows-sockets-using-sockets-with-archives.md).

Para obter mais informações sobre pedidos de byte, consulte a especificação do Windows Sockets, disponível no SDK do Windows.

## <a name="a-byte-order-conversion-example"></a>Um exemplo de conversão de pedido de byte

O exemplo a seguir mostra `CSocket` uma função de serialização para um objeto que usa um arquivo. Ele também ilustra o uso das funções de conversão de ordem de byte na API do Windows Sockets.

Este exemplo apresenta um cenário no qual você está escrevendo um cliente que se comunica com um aplicativo de servidor não-MFC para o qual você não tem acesso ao código-fonte. Neste cenário, você deve assumir que o servidor não-MFC usa ordem de byte de rede padrão. Em contraste, seu aplicativo cliente `CArchive` MFC `CSocket` usa `CArchive` um objeto com um objeto e usa ordem de byte "little-Endian", o oposto do padrão de rede.

Suponha que o servidor não-MFC com o qual você planeja se comunicar tenha um protocolo estabelecido para um pacote de mensagens como o seguinte:

[!code-cpp[NVC_MFCSimpleSocket#5](../mfc/codesnippet/cpp/windows-sockets-byte-ordering_1.cpp)]

Em termos de MFC, isso seria expresso da seguinte forma:

[!code-cpp[NVC_MFCSimpleSocket#6](../mfc/codesnippet/cpp/windows-sockets-byte-ordering_2.cpp)]

Em C++, uma **estrutura** é essencialmente a mesma coisa que uma classe. A `Message` estrutura pode ter funções `Serialize` de membro, como a função de membro declarada acima. A `Serialize` função do membro pode ser assim:

[!code-cpp[NVC_MFCSimpleSocket#7](../mfc/codesnippet/cpp/windows-sockets-byte-ordering_3.cpp)]

Este exemplo exige conversões de dados por ordem de byte porque há uma clara incompatibilidade entre o pedido `CArchive` de byte do aplicativo de servidor não-MFC em uma extremidade e o usado em seu aplicativo cliente MFC na outra extremidade. O exemplo ilustra várias das funções de conversão de ordem de byte que o Windows Sockets fornece. A tabela a seguir descreve essas funções.

### <a name="windows-sockets-byte-order-conversion-functions"></a>Funções de conversão byte-order do Windows Sockets

|Função|Finalidade|
|--------------|-------------|
|**Ntohs**|Converta uma quantidade de 16 bits da ordem de byte de rede para a ordem de byte de host (grande-endian a little-Endian).|
|**Ntohl**|Converta uma quantidade de 32 bits da ordem de byte de rede para a ordem de byte de host (grande-endian a little-Endian).|
|**Htons**|Converta uma quantidade de 16 bits da ordem de byte do host para a ordem de byte de rede (little-Endian para big-Endian).|
|**Htonl**|Converta uma quantidade de 32 bits da ordem de byte do host para a ordem de byte de rede (little-Endian para big-Endian).|

Outro ponto deste exemplo é que quando a aplicação do soquete na outra extremidade da comunicação é um aplicativo não-MFC, você deve evitar fazer algo como o seguinte:

`ar << pMsg;`

onde `pMsg` está um ponteiro para um objeto `CObject`C++ derivado da classe . Isso enviará informações extras de MFC associadas a objetos e o servidor não entenderá, como seria se fosse um aplicativo MFC.

Para obter mais informações, consulte:

- [Windows Sockets: usando classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: plano de fundo](../mfc/windows-sockets-background.md)

- [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Confira também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)
