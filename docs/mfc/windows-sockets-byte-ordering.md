---
title: 'Windows Sockets: ordenação de bytes'
ms.date: 11/04/2016
helpviewer_keywords:
- byte order issues in sockets programming
- sockets [MFC], byte order issues
- Windows Sockets [MFC], byte order issues
ms.assetid: 8a787a65-f9f4-4002-a02f-ac25a5dace5d
ms.openlocfilehash: f00936f3de07df8c1e4d9df1c678b2cfd5f3e3ad
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226796"
---
# <a name="windows-sockets-byte-ordering"></a>Windows Sockets: ordenação de bytes

Este artigo e dois artigos complementares explicam vários problemas na programação do Windows Sockets. Este artigo aborda a ordenação de bytes. Os outros problemas são abordados nos artigos: [Windows Sockets: blocking](../mfc/windows-sockets-blocking.md) and [Windows Sockets: convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md).

Se você usar ou derivar da classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md), será necessário gerenciar esses problemas por conta própria. Se você usar ou derivar da classe [CSocket](../mfc/reference/csocket-class.md), o MFC as gerenciará para você.

## <a name="byte-ordering"></a>ordenação da regra

Arquiteturas de computador diferentes às vezes armazenam dados usando diferentes ordens de byte. Por exemplo, as máquinas baseadas em Intel armazenam dados na ordem inversa de computadores Macintosh (Motorola). A ordem de bytes da Intel, chamada "little-endian", também é o inverso da ordem "big-endian" padrão da rede. A tabela a seguir explica esses termos.

### <a name="big--and-little-endian-byte-ordering"></a>Ordenação de bytes Big-e little-endian

|ordenação de byte|Significado|
|-------------------|-------------|
|Big endian|O byte mais significativo está na extremidade esquerda de uma palavra.|
|Little-endian|O byte mais significativo está na extremidade direita de uma palavra.|

Normalmente, você não precisa se preocupar com a conversão de ordem de byte para dados que você envia e recebe pela rede, mas há situações em que você deve converter pedidos de byte.

## <a name="when-you-must-convert-byte-orders"></a>Quando você deve converter pedidos de bytes

Você precisa converter os pedidos de bytes nas seguintes situações:

- Você está passando informações que precisam ser interpretadas pela rede, em oposição aos dados que você está enviando para outra máquina. Por exemplo, você pode passar portas e endereços que a rede deve entender.

- O aplicativo de servidor com o qual você está se comunicando não é um aplicativo MFC (e você não tem código-fonte para ele). Isso chamará as conversões de ordem de byte se as duas máquinas não compartilharem a mesma ordenação de bytes.

## <a name="when-you-do-not-have-to-convert-byte-orders"></a>Quando você não precisa converter pedidos de bytes

Você pode evitar o trabalho de converter ordens de byte nas seguintes situações:

- Os computadores em ambas as extremidades podem concordar em não trocar bytes e os dois computadores usam a mesma ordem de byte.

- O servidor com o qual você está se comunicando é um aplicativo do MFC.

- Você tem código-fonte para o servidor com o qual está se comunicando, para que você possa dizer explicitamente se deve converter ordens de byte ou não.

- Você pode portar o servidor para o MFC. Isso é razoavelmente fácil de fazer, e o resultado é geralmente menor, com um código mais rápido.

Trabalhando com [CAsyncSocket](../mfc/reference/casyncsocket-class.md), você deve gerenciar todas as conversões de ordem de byte necessárias por conta própria. O Windows Sockets padroniza o modelo de ordem de byte "big-endian" e fornece funções a serem convertidas entre essa ordem e outras. O [CArchive](../mfc/reference/carchive-class.md), no entanto, que você usa com o [CSocket](../mfc/reference/csocket-class.md), usa a ordem oposta ("little-endian"), mas cuida `CArchive` dos detalhes das conversões de ordem de byte para você. Usando essa ordenação padrão em seus aplicativos ou usando funções de conversão de ordem de byte do Windows Sockets, você pode tornar seu código mais portátil.

O caso ideal para usar os soquetes do MFC é quando você está escrevendo ambas as extremidades da comunicação: usando o MFC em ambas as extremidades. Se você estiver escrevendo um aplicativo que se comunicará com aplicativos não MFC, como um servidor FTP, provavelmente precisará gerenciar a troca de bytes por conta própria antes de passar os dados para o objeto de arquivo morto, usando as rotinas de conversão **ntohs**, **ntohl**, **htons**e **htonl**do Windows Sockets. Um exemplo dessas funções usadas na comunicação com um aplicativo não MFC aparece mais adiante neste artigo.

> [!NOTE]
> Quando a outra extremidade da comunicação não é um aplicativo MFC, você também deve evitar transmitir objetos C++ derivados de `CObject` em seu arquivo, pois o receptor não poderá tratá-los. Consulte a observação no [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md).

Para obter mais informações sobre pedidos de bytes, consulte a especificação do Windows Sockets, disponível na SDK do Windows.

## <a name="a-byte-order-conversion-example"></a>Um exemplo de conversão de ordem de byte

O exemplo a seguir mostra uma função de serialização para um `CSocket` objeto que usa um arquivo morto. Ele também ilustra o uso das funções de conversão de ordem de byte na API do Windows Sockets.

Este exemplo apresenta um cenário no qual você está escrevendo um cliente que se comunica com um aplicativo de servidor não MFC para o qual você não tem acesso ao código-fonte. Nesse cenário, você deve supor que o servidor não MFC usa a ordem de bytes de rede padrão. Por outro lado, o aplicativo do cliente MFC usa um `CArchive` objeto com um `CSocket` objeto e `CArchive` usa a ordem de byte "little-endian", o oposto do padrão de rede.

Suponha que o servidor não MFC com o qual você planeja se comunicar tenha um protocolo estabelecido para um pacote de mensagem semelhante ao seguinte:

[!code-cpp[NVC_MFCSimpleSocket#5](../mfc/codesnippet/cpp/windows-sockets-byte-ordering_1.cpp)]

Nos termos do MFC, isso seria expresso da seguinte maneira:

[!code-cpp[NVC_MFCSimpleSocket#6](../mfc/codesnippet/cpp/windows-sockets-byte-ordering_2.cpp)]

Em C++, um **`struct`** é essencialmente a mesma coisa que uma classe. A `Message` estrutura pode ter funções de membro, como a `Serialize` função de membro declarada acima. A `Serialize` função de membro pode ser assim:

[!code-cpp[NVC_MFCSimpleSocket#7](../mfc/codesnippet/cpp/windows-sockets-byte-ordering_3.cpp)]

Este exemplo chama conversões de ordem de byte de dados porque há uma incompatibilidade clara entre a ordem de bytes do aplicativo de servidor não MFC em uma extremidade e a `CArchive` usada em seu aplicativo cliente MFC no outro final. O exemplo ilustra várias das funções de conversão de ordem de byte que o Windows Sockets fornece. A tabela a seguir descreve essas funções.

### <a name="windows-sockets-byte-order-conversion-functions"></a>Funções de conversão de ordem de byte do Windows Sockets

|Função|Finalidade|
|--------------|-------------|
|**ntohs**|Converta uma quantidade de 16 bits da ordem de bytes de rede para a ordem de bytes do host (big-endian para little-endian).|
|**ntohl**|Converta uma quantidade de 32 bits da ordem de bytes da rede para a ordem de bytes do host (big-endian para little-endian).|
|**Htons**|Converta uma quantidade de 16 bits da ordem de bytes do host para a ordem de bytes da rede (little-endian para big-endian).|
|**Htonl**|Converta uma quantidade de 32 bits da ordem de bytes do host para a ordem de bytes da rede (little-endian para big-endian).|

Outro ponto desse exemplo é que, quando o aplicativo de soquete na outra extremidade da comunicação é um aplicativo não MFC, você deve evitar fazer algo semelhante ao seguinte:

`ar << pMsg;`

onde `pMsg` é um ponteiro para um objeto C++ derivado da classe `CObject` . Isso enviará informações adicionais do MFC associadas a objetos e o servidor não o entenderá, como seria se fosse um aplicativo MFC.

Para obter mais informações, consulte:

- [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: Informações preliminares](../mfc/windows-sockets-background.md)

- [Windows Sockets: Stream Sockets](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Confira também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)
