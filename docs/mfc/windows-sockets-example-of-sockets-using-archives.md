---
title: 'Windows Sockets: Exemplo de soquetes que usam arquivos mortos'
ms.date: 11/04/2016
helpviewer_keywords:
- sockets [MFC], with archives
- examples [MFC], Windows Sockets
- Windows Sockets [MFC], with archives
ms.assetid: 2e3c9bb2-7e7b-4f28-8dc5-6cb7a484edac
ms.openlocfilehash: 4ea1e2911b156066360da09993fa7302db79f12b
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57295247"
---
# <a name="windows-sockets-example-of-sockets-using-archives"></a>Windows Sockets: Exemplo de soquetes que usam arquivos mortos

Este artigo apresenta um exemplo de como usar a classe [CSocket](../mfc/reference/csocket-class.md). O exemplo utiliza `CArchive` objetos para serializar os dados por meio de um soquete. Observe que isso não é a serialização de documento para ou de um arquivo.

O exemplo a seguir ilustra como usar o arquivo morto para enviar e receber dados por meio de `CSocket` objetos. O exemplo foi projetado para que os dados do exchange de duas instâncias do aplicativo (na mesma máquina ou em máquinas diferentes na rede). Uma instância envia dados, o que a outra instância recebe e reconhece. Qualquer um dos aplicativos pode iniciar uma troca e qualquer um pode agir como servidor ou cliente para o outro aplicativo. A função a seguir é definida na classe de exibição do aplicativo:

[!code-cpp[NVC_MFCSimpleSocket#1](../mfc/codesnippet/cpp/windows-sockets-example-of-sockets-using-archives_1.cpp)]

A coisa mais importante sobre este exemplo é que sua estrutura é comparável à de um MFC `Serialize` função. O `PacketSerialize` função de membro consiste em um **se** instrução com um **else** cláusula. A função recebe duas [CArchive](../mfc/reference/carchive-class.md) referências como parâmetros: *arData* e *arAck*. Se o *arData* objeto de arquivo morto é definido para armazenar (envio), o **se** ramificação é executado; caso contrário, se *arData* é definido para o carregamento (recebimento), a função usa o **else** branch. Para obter mais informações sobre a serialização no MFC, consulte [serialização](../mfc/how-to-make-a-type-safe-collection.md).

> [!NOTE]
>  O *arAck* é considerado para ser o oposto do objeto de arquivo morto *arData*. Se *arData* é enviar, *arAck* recebe, e o inverso é verdadeiro.

Para enviar, a função de exemplo faz um loop para um número especificado de vezes, cada vez que gera alguns dados aleatórios para fins de demonstração. Seu aplicativo obteria dados reais de alguma fonte, como um arquivo. O *arData* operador de inserção do arquivo morto (**<<**) é usado para enviar uma transmissão de três partes consecutivos de dados:

- Um "cabeçalho" que especifica a natureza dos dados (nesse caso, o valor da *bValue* variável e quantas cópias serão enviadas).

   Os dois itens são gerados aleatoriamente para este exemplo.

- O número especificado de cópias dos dados.

   Interno **para** loop envia *bValue* o número de vezes especificado.

- Uma cadeia de caracteres chamado *strText* que o receptor exibe ao usuário.

Para recebimento, a função opera da mesma forma, exceto que ele usa o operador de extração do arquivo morto (**>>**) para obter dados de arquivo morto. O aplicativo de recebimento verifica os dados que recebe, exibe a mensagem de "Recebimento" final e, em seguida, envia de volta uma mensagem que diz "Enviados" para o aplicativo de envio exibir.

Nesse modelo de comunicação, a palavra "Recebimento", a mensagem enviada na *strText* variável, é para exibição na outra extremidade da comunicação, portanto, ele especifica para o usuário que um determinado número de pacotes de dados tenha sido recebido. O receptor responde com uma cadeia de caracteres semelhante que diz "Enviado", para exibição na tela do remetente original. Recebimento de ambas as cadeias de caracteres indica que a comunicação bem-sucedida ocorreu.

> [!CAUTION]
>  Se você estiver escrevendo um programa de cliente do MFC para se comunicar com servidores estabelecida (não MFC), não envie objetos C++ por meio do arquivo morto. A menos que o servidor for um aplicativo do MFC que compreende os tipos de objetos que você deseja enviar, ele não será capaz de receber e desserializar os seus objetos. Um exemplo no artigo [Windows Sockets: Ordenação de bytes](../mfc/windows-sockets-byte-ordering.md) mostra uma comunicação desse tipo.

Para obter mais informações, consulte a especificação do Windows Sockets: **htonl**, **htons**, **ntohl**, **ntohs**. Além disso, para obter mais informações, consulte:

- [Windows Sockets: Derivando de Classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)

- [Windows Sockets: Como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md)

- [Windows Sockets: Background](../mfc/windows-sockets-background.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)<br/>
[CArchive::IsStoring](../mfc/reference/carchive-class.md#isstoring)<br/>
[CArchive::operator <<](../mfc/reference/carchive-class.md#operator_lt_lt)<br/>
[CArchive::operator >>](../mfc/reference/carchive-class.md#operator_lt_lt)<br/>
[CArchive::Flush](../mfc/reference/carchive-class.md#flush)<br/>
[CObject::Serialize](../mfc/reference/cobject-class.md#serialize)
