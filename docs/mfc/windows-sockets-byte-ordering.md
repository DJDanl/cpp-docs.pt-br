---
title: 'Windows Sockets: A ordem de bytes'
ms.date: 11/04/2016
helpviewer_keywords:
- byte order issues in sockets programming
- sockets [MFC], byte order issues
- Windows Sockets [MFC], byte order issues
ms.assetid: 8a787a65-f9f4-4002-a02f-ac25a5dace5d
ms.openlocfilehash: ca572ad32a9a46756cacf0221d80b2953b710723
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57278087"
---
# <a name="windows-sockets-byte-ordering"></a>Windows Sockets: A ordem de bytes

Este artigo e dois artigos complementares explicam vários problemas na programação do Windows Sockets. Este artigo aborda a ordem de bytes. Os outros problemas são abordados nos artigos: [Windows Sockets: Bloqueando](../mfc/windows-sockets-blocking.md) e [Windows Sockets: Convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md).

Se você usar ou derivar da classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md), você precisará gerenciar esses problemas por conta própria. Se você usar ou derivar da classe [CSocket](../mfc/reference/csocket-class.md), gerencia MFC-los para você.

## <a name="byte-ordering"></a>A ordem de bytes

Arquiteturas diferentes, às vezes, armazenam dados usando ordens de byte. Por exemplo, os computadores baseados em Intel armazenam dados na ordem inversa de computadores Macintosh (Motorola). A ordem de byte da Intel, chamada "little-Endian" também é o inverso da ordem padrão de "big-Endian" de rede. A tabela a seguir explica esses termos.

### <a name="big--and-little-endian-byte-ordering"></a>A ordem de Byte big - e Little-Endian

|A ordem de bytes|Significado|
|-------------------|-------------|
|Big-Endian|O byte mais significativo é na extremidade esquerda de uma palavra.|
|Little-Endian|O byte mais significativo é na extremidade direita de uma palavra.|

Normalmente, você não precisa se preocupar sobre a conversão de ordem de byte para os dados que você envia e recebe pela rede, mas há situações em que você deve converter ordens de byte.

## <a name="when-you-must-convert-byte-orders"></a>Quando você deve converter ordens de Byte

Você precisa converter as ordens de byte nas seguintes situações:

- Você está transmitindo informações que precisam ser interpretado por rede, em vez dos dados que você está enviando a outra máquina. Por exemplo, você pode passar as portas e endereços, que a rede deve entender.

- O aplicativo de servidor com o qual você está se comunicando não é um aplicativo MFC (e você não tiver o código-fonte para ele). Isso chama para conversões de ordem de byte se as duas máquinas não compartilham a mesma ordenação de bytes.

## <a name="when-you-do-not-have-to-convert-byte-orders"></a>Quando você não precisa converter ordens de Byte

Você pode evitar o trabalho de conversão de ordens de byte nas seguintes situações:

- As máquinas em ambas as extremidades podem concorda em não troca os bytes, e ambos os computadores usam a mesma ordem de byte.

- O servidor com que estão se comunicando é um aplicativo do MFC.

- Você tem código-fonte para o servidor que você está se comunicando, portanto, você pode informar explicitamente se você deve converter ordens de byte ou não.

- Você pode portar o servidor ao MFC. Isso é muito fácil de fazer, e o resultado geralmente é código menor e mais rápido.

Trabalhando com [CAsyncSocket](../mfc/reference/casyncsocket-class.md), você deve gerenciar as conversões necessárias de ordem de byte. Windows Sockets padroniza o modelo de ordem de bytes "big-Endian" e fornece funções para converter entre essa ordem e outros. [CArchive](../mfc/reference/carchive-class.md), no entanto, que você pode usar com [CSocket](../mfc/reference/csocket-class.md), usa a ordem oposta ("little-Endian"), mas `CArchive` cuida dos detalhes de conversões de ordem de byte para você. Usando esse padrão de ordenação em seus aplicativos, ou usando funções de conversão de ordem de byte de soquetes do Windows, você pode tornar seu código mais portátil.

O caso ideal para usar soquetes MFC é quando você estiver escrevendo ambas as extremidades da comunicação: usando MFC em ambas as extremidades. Se você estiver escrevendo um aplicativo que irá se comunicar com aplicativos não MFC, como um servidor FTP, você provavelmente precisará gerenciar troca de bytes por conta própria antes de passar dados para o objeto de arquivo morto, usando as rotinas de conversão de Windows Sockets **ntohs**, **ntohl**, **htons**, e **htonl**. Um exemplo de como essas funções usadas na comunicação com um aplicativo MFC não aparece mais adiante neste artigo.

> [!NOTE]
>  Quando a outra extremidade da comunicação não é um aplicativo do MFC, você também deve evitar streaming objetos C++ derivados de `CObject` em seu arquivo porque o receptor não será capaz de lidar com eles. Consulte a Observação [Windows Sockets: Usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md).

Para obter mais informações sobre ordens de byte, consulte a especificação de soquetes do Windows, disponível no SDK do Windows.

## <a name="a-byte-order-conversion-example"></a>Um exemplo de conversão de ordem de Byte

O exemplo a seguir mostra uma função de serialização para um `CSocket` objeto que usa um arquivo morto. Ele também ilustra usando as funções de conversão de ordem de byte na API do Windows Sockets.

Este exemplo apresenta um cenário no qual você está escrevendo um cliente que se comunica com um aplicativo de servidor não MFC para os quais você não tem acesso ao código-fonte. Nesse cenário, você deve presumir que o servidor não MFC usa a ordem de byte de rede padrão. Em contraste, o aplicativo de cliente do MFC usa um `CArchive` do objeto com um `CSocket` objeto, e `CArchive` usa a ordem de byte "little-Endian", o oposto da rede padrão.

Suponha que o servidor não MFC com o qual você pretende se comunicar tem um protocolo estabelecido para um pacote de mensagem semelhante à seguinte:

[!code-cpp[NVC_MFCSimpleSocket#5](../mfc/codesnippet/cpp/windows-sockets-byte-ordering_1.cpp)]

Em termos MFC, isso seria expressa da seguinte maneira:

[!code-cpp[NVC_MFCSimpleSocket#6](../mfc/codesnippet/cpp/windows-sockets-byte-ordering_2.cpp)]

No C++, uma **struct** é essencialmente a mesma coisa que uma classe. O `Message` estrutura pode ter funções de membro, como o `Serialize` função de membro declarado acima. O `Serialize` função de membro pode ter esta aparência:

[!code-cpp[NVC_MFCSimpleSocket#7](../mfc/codesnippet/cpp/windows-sockets-byte-ordering_3.cpp)]

Este exemplo chama para conversões de ordem de byte de dados porque não há uma diferença clara entre a ordem dos bytes do aplicativo para servidores não MFC em uma extremidade e o `CArchive` usado em seu aplicativo de cliente do MFC na outra extremidade. O exemplo ilustra várias das funções de conversão de ordem de byte que soquetes do Windows fornece. A tabela a seguir descreve essas funções.

### <a name="windows-sockets-byte-order-conversion-functions"></a>Funções de conversão de ordem de Byte de soquetes do Windows

|Função|Finalidade|
|--------------|-------------|
|**ntohs**|Converta uma quantidade de 16 bits de ordem de byte de rede em ordem de byte de host (big-Endian para little-Endian).|
|**ntohl**|Converta uma quantidade de 32 bits de ordem de byte de rede em ordem de byte de host (big-Endian para little-Endian).|
|**Htons**|Converta uma quantidade de 16 bits de ordem de byte de host em ordem de byte de rede (little-Endian para big-Endian).|
|**Htonl**|Converta uma quantidade de 32 bits de ordem de byte de host em ordem de byte de rede (little-Endian para big-Endian).|

Outro ponto deste exemplo é que, quando o aplicativo de soquete na outra extremidade da comunicação é um aplicativo não MFC, você deve evitar fazer algo semelhante ao seguinte:

`ar << pMsg;`

em que `pMsg` é um ponteiro para um objeto C++ derivado da classe `CObject`. Isso enviará informações extras de MFC associadas a objetos e o servidor não entenderão, como se fosse um aplicativo do MFC.

Para obter mais informações, consulte:

- [Windows Sockets: Usando classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: Background](../mfc/windows-sockets-background.md)

- [Windows Sockets: Stream Sockets](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: Soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)
