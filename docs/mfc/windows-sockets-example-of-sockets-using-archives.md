---
title: 'Windows Sockets: Exemplo de soquetes que usam arquivos mortos | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- sockets [MFC], with archives
- examples [MFC], Windows Sockets
- Windows Sockets [MFC], with archives
ms.assetid: 2e3c9bb2-7e7b-4f28-8dc5-6cb7a484edac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 02cd74a20f0ccc54a366c1a62d913ee30e72471a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="windows-sockets-example-of-sockets-using-archives"></a>Windows Sockets: exemplo de soquetes que usam arquivos mortos
Este artigo apresenta um exemplo de como usar a classe [CSocket](../mfc/reference/csocket-class.md). O exemplo utiliza `CArchive` objetos para serializar os dados por meio de um soquete. Observe que isso não é a serialização de documentos para ou de um arquivo.  
  
 O exemplo a seguir ilustra como usar o arquivo para enviar e receber dados por meio de `CSocket` objetos. O exemplo foi desenvolvido para que os dados do exchange de duas instâncias do aplicativo (na mesma máquina ou em máquinas diferentes na rede). Uma instância envia dados, que a outra instância recebe e reconhece. O aplicativo pode iniciar uma troca e qualquer um pode agir como servidor ou cliente para o outro aplicativo. A função a seguir é definida na classe de exibição do aplicativo:  
  
 [!code-cpp[NVC_MFCSimpleSocket#1](../mfc/codesnippet/cpp/windows-sockets-example-of-sockets-using-archives_1.cpp)]  
  
 O mais importante sobre este exemplo é sua estrutura comparável ao que um MFC `Serialize` função. O **PacketSerialize** função de membro consiste em uma **se** instrução com uma **else** cláusula. A função recebe dois [CArchive](../mfc/reference/carchive-class.md) referências como parâmetros: `arData` e `arAck`. Se o `arData` arquivo objeto é definido para armazenar (envio), o **se** ramificação executa; caso contrário, se `arData` está definido para carregar (recebimento) usa a função a **else** ramificação. Para obter mais informações sobre serialização em MFC, consulte [serialização](../mfc/how-to-make-a-type-safe-collection.md).  
  
> [!NOTE]
>  O `arAck` objeto do arquivo é considerado como o oposto do `arData`. Se `arData` para enviar, `arAck` recebe, e o inverso é verdadeiro.  
  
 Para enviar, a função de exemplo executa um loop para um número especificado de vezes, sempre gerar alguns dados aleatórios para fins de demonstração. Seu aplicativo deve obter dados reais de origem, como um arquivo. O `arData` operador de inserção do arquivamento (**<<**) é usado para enviar um fluxo de três partes consecutivos de dados:  
  
-   Um "cabeçalho" que especifica a natureza dos dados (nesse caso, o valor da `bValue` variável e quantas cópias serão enviadas).  
  
     Os dois itens são gerados aleatoriamente para este exemplo.  
  
-   O número de cópias de dados especificado.  
  
     Interna **para** loop envia `bValue` o número de vezes especificado.  
  
-   Uma cadeia de caracteres chamado `strText` que o receptor exibe ao usuário.  
  
 Para recebimento, a função funciona da mesma forma, exceto que ele usa o operador de extração do arquivo (**>>**) para obter dados do arquivo morto. O aplicativo de recebimento verifica os dados que recebe, exibe a mensagem "Recebidos" final e, em seguida, envia uma mensagem que diz "Enviados" para o aplicativo de envio exibir.  
  
 Nesse modelo de comunicação, a palavra "Recebidos", a mensagem enviada no `strText` variável, é para exibição na outra extremidade de comunicação, portanto, ele especifica para o usuário que um determinado número de pacotes de dados foram recebidos. O receptor responde com uma cadeia de caracteres semelhante que diz "Enviados" para exibição na tela do remetente original. Recebimento de ambas as cadeias de caracteres indica que houve comunicação bem-sucedida.  
  
> [!CAUTION]
>  Se você estiver escrevendo um programa de cliente do MFC para se comunicar com servidores estabelecida não-MFC (), não envie objetos C++ por meio do arquivo morto. A menos que o servidor for um aplicativo MFC que compreende os tipos de objetos que você deseja enviar, ele não será capaz de receber e desserializar objetos. Um exemplo no artigo [Windows Sockets: ordenação de bytes](../mfc/windows-sockets-byte-ordering.md) mostra uma comunicação desse tipo.  
  
 Para obter mais informações, consulte a especificação do Windows Sockets: **htonl**, **htons**, **ntohl**, **ntohs**. Além disso, para obter mais informações, consulte:  
  
-   [Windows Sockets: derivando de classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)  
  
-   [Windows Sockets: como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md)  
  
-   [Windows Sockets: tela de fundo](../mfc/windows-sockets-background.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)   
 [CArchive::IsStoring](../mfc/reference/carchive-class.md#isstoring)   
 [CArchive::operator <<](../mfc/reference/carchive-class.md#operator_lt_lt)   
 [CArchive::operator >>](../mfc/reference/carchive-class.md#operator_lt_lt)   
 [CArchive::Flush](../mfc/reference/carchive-class.md#flush)   
 [CObject::Serialize](../mfc/reference/cobject-class.md#serialize)

