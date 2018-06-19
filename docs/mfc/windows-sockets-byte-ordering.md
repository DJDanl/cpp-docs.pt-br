---
title: 'Windows Sockets: Ordenação de bytes | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- byte order issues in sockets programming
- sockets [MFC], byte order issues
- Windows Sockets [MFC], byte order issues
ms.assetid: 8a787a65-f9f4-4002-a02f-ac25a5dace5d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 18fc3f586c7fc8861bfc29dade7b62e741bb0ffc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33385151"
---
# <a name="windows-sockets-byte-ordering"></a>Windows Sockets: ordenação de bytes
Este artigo e dois artigos complementar explicam vários problemas na programação do Windows Sockets. Este artigo aborda a ordem de bytes. Os outros problemas são abordados nos artigos: [Windows Sockets: bloqueando](../mfc/windows-sockets-blocking.md) e [Windows Sockets: Convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md).  
  
 Se você usar ou derivar da classe [CAsyncSocket](../mfc/reference/casyncsocket-class.md), você precisará gerenciar esses problemas por conta própria. Se você usar ou derivar da classe [CSocket](../mfc/reference/csocket-class.md), gerencia MFC-los para você.  
  
## <a name="byte-ordering"></a>A ordem de bytes  
 Arquiteturas de máquina diferentes, às vezes, armazenam dados usando ordens de byte. Por exemplo, computadores baseados no Intel armazenam dados na ordem inversa de computadores Macintosh (Motorola). A ordem de byte Intel, chamada "little-Endian" também é o inverso da ordem de "big-Endian" padrão de rede. A tabela a seguir explica esses termos.  
  
### <a name="big--and-little-endian-byte-ordering"></a>A ordem de bytes big e Little-Endian  
  
|A ordem de bytes|Significado|  
|-------------------|-------------|  
|Big-Endian.|O byte mais significativo está no final de uma palavra à esquerda.|  
|Little-Endian|É o byte mais significativo na extremidade direita de uma palavra.|  
  
 Normalmente, você não precisa se preocupar sobre conversão de ordem de bytes de dados que você envia e recebe pela rede, mas há situações em que você deve converter ordens de byte.  
  
## <a name="when-you-must-convert-byte-orders"></a>Quando você deve converter ordens de Byte  
 É necessário converter ordens de byte nas seguintes situações:  
  
-   Você está transmitindo informações que precisam ser interpretada por rede, em vez dos dados que você está enviando a outra máquina. Por exemplo, você pode passar portas e endereços, que a rede deve entender.  
  
-   O aplicativo de servidor com o qual você está se comunicando não é um aplicativo MFC (e você não tem o código-fonte para ele). Isso chama para conversões de ordem de byte se as duas máquinas não compartilham a mesma ordem de bytes.  
  
## <a name="when-you-do-not-have-to-convert-byte-orders"></a>Quando você não precisar converter ordens de Byte  
 Você pode evitar o trabalho de conversão de ordens de byte nas seguintes situações:  
  
-   As máquinas em ambas as extremidades podem concorda não trocar bytes e os computadores usam a mesma ordem de byte.  
  
-   O servidor que você está se comunicando com é um aplicativo MFC.  
  
-   Você tem o código-fonte para o servidor que você está se comunicando, para que você possa perceber explicitamente se você deve converter bytes pedidos ou não.  
  
-   Você pode porta o servidor a MFC. Isso é bastante simples, e o resultado é geralmente menor, mais rápido de código.  
  
 Trabalhando com [CAsyncSocket](../mfc/reference/casyncsocket-class.md), você deve gerenciar qualquer conversão necessária de ordem de byte. Windows Sockets padroniza o modelo de ordem de bytes "big-Endian" e fornece funções para converter entre essa ordem e outros. [CArchive](../mfc/reference/carchive-class.md), no entanto, que você pode usar com [CSocket](../mfc/reference/csocket-class.md), usa a ordem oposta ("little-Endian"), mas `CArchive` cuida dos detalhes de conversões de ordem de byte para você. Usando essa ordenação padrão em seus aplicativos, ou usando funções de conversão de ordem de byte do Windows Sockets, você pode tornar seu código mais portáteis.  
  
 O caso ideal para usar soquetes MFC é quando você está escrevendo ambas as extremidades da comunicação: usando MFC em ambas as extremidades. Se você estiver escrevendo um aplicativo que irá se comunicar com aplicativos não MFC, como um servidor FTP, você provavelmente precisará gerenciar troca de bytes por conta própria antes de passar dados para o objeto de arquivo, usando as rotinas de conversão de Windows Sockets **ntohs**, **ntohl**, **htons**, e **htonl**. Um exemplo de como essas funções usadas na comunicação com um aplicativo MFC não aparece mais tarde neste artigo.  
  
> [!NOTE]
>  Quando a outra extremidade da comunicação não é um aplicativo MFC, você também deve evitar streaming objetos C++ derivados de `CObject` em seu arquivo porque o receptor não será capaz de lidar com eles. Consulte a observação na [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md).  
  
 Para obter mais informações sobre ordens de byte, consulte a especificação de Windows Sockets, disponível no SDK do Windows.  
  
## <a name="a-byte-order-conversion-example"></a>Um exemplo de conversão de ordem de Byte  
 O exemplo a seguir mostra uma função de serialização para um `CSocket` objeto que usa um arquivo morto. Ele também ilustra usando as funções de conversão de ordem de byte na API do Windows Sockets.  
  
 Este exemplo apresenta um cenário no qual você está escrevendo um cliente que se comunica com um aplicativo de servidor não MFC para os quais você não tem acesso ao código-fonte. Nesse cenário, você deve presumir que o servidor não MFC usa a ordem de bytes de rede padrão. Em contraste, o aplicativo cliente MFC usa um `CArchive` do objeto com um `CSocket` objeto, e `CArchive` usa a ordem de bytes de "little-Endian", o oposto da rede padrão.  
  
 Suponha que o servidor não MFC com a qual você pretende se comunicar tem um protocolo estabelecido para um pacote de mensagem semelhante à seguinte:  
  
 [!code-cpp[NVC_MFCSimpleSocket#5](../mfc/codesnippet/cpp/windows-sockets-byte-ordering_1.cpp)]  
  
 Em termos MFC, isso seria expressa da seguinte maneira:  
  
 [!code-cpp[NVC_MFCSimpleSocket#6](../mfc/codesnippet/cpp/windows-sockets-byte-ordering_2.cpp)]  
  
 Em C++, um `struct` é essencialmente o mesmo que uma classe. O `Message` estrutura pode ter funções de membro, como o `Serialize` função de membro declaradas acima. O `Serialize` função de membro pode ter esta aparência:  
  
 [!code-cpp[NVC_MFCSimpleSocket#7](../mfc/codesnippet/cpp/windows-sockets-byte-ordering_3.cpp)]  
  
 Este exemplo chama para conversões de ordem de bytes de dados porque há uma incompatibilidade clara entre a ordenação de bytes do aplicativo de servidor não MFC em uma extremidade e o `CArchive` usado em seu aplicativo de cliente MFC na outra extremidade. O exemplo ilustra várias das funções de conversão de ordem de byte fornecida pelo Windows Sockets. A tabela a seguir descreve essas funções.  
  
### <a name="windows-sockets-byte-order-conversion-functions"></a>Funções de conversão de ordem de Byte de Windows Sockets  
  
|Função|Finalidade|  
|--------------|-------------|  
|**ntohs**|Converta uma quantidade de 16 bits de ordem de bytes de rede em ordem de byte do host (big-Endian para little Endian).|  
|**ntohl**|Converta uma quantidade de 32 bits de ordem de bytes de rede em ordem de byte do host (big-Endian para little Endian).|  
|**Htons**|Converta uma quantidade de 16 bits de ordem de byte do host para a ordem de bytes de rede (little Endian para big-Endian).|  
|**Htonl**|Converta uma quantidade de 32 bits de ordem de byte do host para a ordem de bytes de rede (little Endian para big-Endian).|  
  
 Outro ponto deste exemplo é que, quando o aplicativo de soquete na outra extremidade da comunicação é um aplicativo não MFC, você deve evitar fazer algo semelhante ao seguinte:  
  
 `ar << pMsg;`  
  
 onde `pMsg` é um ponteiro para um objeto C++ derivado da classe `CObject`. Isso enviará informações extras de MFC associadas a objetos e o servidor não entenda, como se fosse um aplicativo MFC.  
  
 Para obter mais informações, consulte:  
  
-   [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
-   [Windows Sockets: tela de fundo](../mfc/windows-sockets-background.md)  
  
-   [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)

