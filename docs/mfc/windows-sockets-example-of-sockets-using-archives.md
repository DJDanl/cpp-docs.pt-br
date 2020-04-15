---
title: 'Windows Sockets: exemplo de soquetes que usam arquivos mortos'
ms.date: 11/04/2016
helpviewer_keywords:
- sockets [MFC], with archives
- examples [MFC], Windows Sockets
- Windows Sockets [MFC], with archives
ms.assetid: 2e3c9bb2-7e7b-4f28-8dc5-6cb7a484edac
ms.openlocfilehash: 253a65430ae230fbc4deeb9bd5288f28237310d2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371081"
---
# <a name="windows-sockets-example-of-sockets-using-archives"></a>Windows Sockets: exemplo de soquetes que usam arquivos mortos

Este artigo apresenta um exemplo de uso da classe [CSocket](../mfc/reference/csocket-class.md). O exemplo `CArchive` emprega objetos para serializar dados através de um soquete. Observe que isso não é serialização de documentos para ou a partir de um arquivo.

O exemplo a seguir ilustra como você usa `CSocket` o arquivo para enviar e receber dados através de objetos. O exemplo é projetado para que duas instâncias da aplicação (na mesma máquina ou em máquinas diferentes na rede) troquem dados. Uma instância envia dados, que a outra instância recebe e reconhece. Qualquer aplicativo pode iniciar uma troca, e pode atuar como servidor ou como cliente para o outro aplicativo. A seguinte função é definida na classe de exibição do aplicativo:

[!code-cpp[NVC_MFCSimpleSocket#1](../mfc/codesnippet/cpp/windows-sockets-example-of-sockets-using-archives_1.cpp)]

A coisa mais importante sobre este exemplo é que `Serialize` sua estrutura paralela à de uma função MFC. A `PacketSerialize` função de membro consiste em uma **declaração if** com uma **cláusula else.** A função recebe duas referências [do CArchive](../mfc/reference/carchive-class.md) como parâmetros: *arData* e *arAck*. Se o objeto de arquivamento *arData* estiver definido para armazenar (envio), o ramo **se** for executado; caso contrário, se *arData* estiver definido para carregar (recebendo) a função assumirá o **ramo de outra** forma. Para obter mais informações sobre serialização em MFC, consulte [Serialização](../mfc/how-to-make-a-type-safe-collection.md).

> [!NOTE]
> Presume-se que o objeto de arquivo *arAck* seja o oposto de *arData*. Se *arData* é para envio, *arAck* recebe, e o inverso é verdadeiro.

Para enviar, o exemplo faz loops de função para um número especificado de vezes, cada vez gerando alguns dados aleatórios para fins de demonstração. Seu aplicativo obteria dados reais de alguma fonte, como um arquivo. O operador de inserção**<<** do arquivo *arData* ( ) é usado para enviar um fluxo de três blocos consecutivos de dados:

- Um "cabeçalho" que especifica a natureza dos dados (neste caso, o valor da variável *bValue* e quantas cópias serão enviadas).

   Ambos os itens são gerados aleatoriamente para este exemplo.

- O número especificado de cópias dos dados.

   O loop interno **para** *enviar bValorize* o número especificado de vezes.

- Uma string chamada *strText* que o receptor exibe ao usuário.

Para receber, a função funciona de forma semelhante, exceto**>>** que usa o operador de extração do arquivo ( ) para obter dados do arquivo. O aplicativo receptor verifica os dados que recebe, exibe a mensagem final "Recebida" e, em seguida, envia de volta uma mensagem que diz "Enviado" para o aplicativo de envio ser exibido.

Neste modelo de comunicação, a palavra "Recebido", a mensagem enviada na variável *strText,* é para exibição na outra extremidade da comunicação, por isso especifica ao usuário receptor que um determinado número de pacotes de dados foram recebidos. O receptor responde com uma seqüência semelhante que diz "Sent", para exibição na tela do remetente original. O recebimento de ambas as cordas indica que ocorreu uma comunicação bem sucedida.

> [!CAUTION]
> Se você estiver escrevendo um programa cliente MFC para se comunicar com servidores estabelecidos (não-MFC), não envie objetos C++ através do arquivo. A menos que o servidor seja um aplicativo MFC que entenda os tipos de objetos que você deseja enviar, ele não será capaz de receber e desserializar seus objetos. Um exemplo no artigo [Soquetes do Windows: Byte Ordering](../mfc/windows-sockets-byte-ordering.md) mostra uma comunicação deste tipo.

Para obter mais informações, consulte a especificação do Soquete do Windows: **htonl,** **htons,** **ntohl,** **ntohs**. Além disso, para obter mais informações, consulte:

- [Windows Sockets: derivando de classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)

- [Windows Sockets: como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md)

- [Windows Sockets: plano de fundo](../mfc/windows-sockets-background.md)

## <a name="see-also"></a>Confira também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)<br/>
[CArchive::IsStoring](../mfc/reference/carchive-class.md#isstoring)<br/>
[CArchive:: <<do operador](../mfc/reference/carchive-class.md#operator_lt_lt)<br/>
[CArchive:: >>do operador](../mfc/reference/carchive-class.md#operator_lt_lt)<br/>
[CArchive::Flush](../mfc/reference/carchive-class.md#flush)<br/>
[CObject::Serialize](../mfc/reference/cobject-class.md#serialize)
