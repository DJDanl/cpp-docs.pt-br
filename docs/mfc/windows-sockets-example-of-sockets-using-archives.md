---
title: 'Windows Sockets: exemplo de soquetes que usam arquivos mortos'
ms.date: 11/04/2016
helpviewer_keywords:
- sockets [MFC], with archives
- examples [MFC], Windows Sockets
- Windows Sockets [MFC], with archives
ms.assetid: 2e3c9bb2-7e7b-4f28-8dc5-6cb7a484edac
ms.openlocfilehash: 275a6c274648225fedcec9d42c280f77af68158e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226770"
---
# <a name="windows-sockets-example-of-sockets-using-archives"></a>Windows Sockets: exemplo de soquetes que usam arquivos mortos

Este artigo apresenta um exemplo de como usar a classe [CSocket](../mfc/reference/csocket-class.md). O exemplo emprega `CArchive` objetos para serializar dados por meio de um soquete. Observe que essa não é a serialização de documentos de ou para um arquivo.

O exemplo a seguir ilustra como você usa o arquivo morto para enviar e receber dados por meio de `CSocket` objetos. O exemplo foi projetado para que duas instâncias do aplicativo (no mesmo computador ou em máquinas diferentes na rede) troquem dados. Uma instância envia dados, que a outra instância recebe e reconhece. Qualquer aplicativo pode iniciar uma troca e pode atuar como servidor ou como cliente para o outro aplicativo. A função a seguir é definida na classe de exibição do aplicativo:

[!code-cpp[NVC_MFCSimpleSocket#1](../mfc/codesnippet/cpp/windows-sockets-example-of-sockets-using-archives_1.cpp)]

A coisa mais importante sobre esse exemplo é que sua estrutura paralela a de uma função do MFC `Serialize` . A `PacketSerialize` função member consiste em uma **`if`** instrução com uma **`else`** cláusula. A função recebe duas referências de [CArchive](../mfc/reference/carchive-class.md) como parâmetros: *arData* e *arAck*. Se o objeto de arquivo morto *arData* for definido para armazenamento (envio), a **`if`** ramificação será executada; caso contrário, se *arData* for definido para carregamento (recebendo) a função usará a **`else`** ramificação. Para obter mais informações sobre serialização no MFC, consulte [serialização](../mfc/how-to-make-a-type-safe-collection.md).

> [!NOTE]
> O objeto *arAck* Archive é considerado o oposto de *arData*. Se *arData* for Send, *arAck* receives e o inverso será true.

Para enviar, os loops de função de exemplo para um número especificado de vezes, cada vez gerando alguns dados aleatórios para fins de demonstração. Seu aplicativo obteria dados reais de alguma fonte, como um arquivo. O operador de inserção do arquivo *arData* ( **<<** ) é usado para enviar um fluxo de três partes consecutivas de dados:

- Um "cabeçalho" que especifica a natureza dos dados (nesse caso, o valor da variável *bValue* e quantas cópias serão enviadas).

   Ambos os itens são gerados aleatoriamente para este exemplo.

- O número especificado de cópias dos dados.

   O **`for`** loop interno envia *bValue* o número de vezes especificado.

- Uma cadeia de caracteres chamada *strText* que o receptor exibe para seu usuário.

Para receber, a função funciona da mesma forma, exceto pelo fato de que ela usa o operador de extração do arquivo morto ( **>>** ) para obter dados do arquivo. O aplicativo de recebimento verifica os dados recebidos, exibe a mensagem final "recebido" e envia de volta uma mensagem que diz "enviado" para que o aplicativo de envio seja exibido.

Nesse modelo de comunicações, a palavra "received", a mensagem enviada na variável *strText* , é para exibição na outra extremidade da comunicação, portanto, ela especifica para o usuário receptor que um determinado número de pacotes de dados foi recebido. O receptor responde com uma cadeia de caracteres semelhante que diz "sent", para exibição na tela do remetente original. O recebimento de ambas as cadeias de caracteres indica que a comunicação bem-sucedida ocorreu.

> [!CAUTION]
> Se você estiver escrevendo um programa de cliente MFC para se comunicar com servidores estabelecidos (não MFC), não envie objetos C++ por meio do arquivo morto. A menos que o servidor seja um aplicativo MFC que entenda os tipos de objetos que você deseja enviar, ele não poderá receber e desserializar seus objetos. Um exemplo no artigo [Windows Sockets: reordenação de bytes](../mfc/windows-sockets-byte-ordering.md) mostra uma comunicação desse tipo.

Para obter mais informações, consulte Windows Sockets Specification: **htonl**, **htons**, **ntohl**, **ntohs**. Além disso, para obter mais informações, consulte:

- [Windows Sockets: derivando de classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)

- [Windows Sockets: como funcionam os soquetes com arquivos](../mfc/windows-sockets-how-sockets-with-archives-work.md)

- [Windows Sockets: Informações preliminares](../mfc/windows-sockets-background.md)

## <a name="see-also"></a>Confira também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)<br/>
[CArchive:: isarmazening](../mfc/reference/carchive-class.md#isstoring)<br/>
[Operador CArchive:: Operator <<](../mfc/reference/carchive-class.md#operator_lt_lt)<br/>
[Operador CArchive:: Operator >>](../mfc/reference/carchive-class.md#operator_lt_lt)<br/>
[CArchive:: flush](../mfc/reference/carchive-class.md#flush)<br/>
[CObject:: Serialize](../mfc/reference/cobject-class.md#serialize)
