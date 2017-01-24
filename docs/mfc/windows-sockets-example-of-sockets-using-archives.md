---
title: "Windows Sockets: exemplo de soquetes que usam arquivos mortos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "exemplos [MFC], Windows Sockets"
  - "soquetes [C++], com arquivamentos"
  - "Windows Sockets [C++], com arquivamentos"
ms.assetid: 2e3c9bb2-7e7b-4f28-8dc5-6cb7a484edac
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Sockets: exemplo de soquetes que usam arquivos mortos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo apresenta um exemplo de como usar a classe [CSocket](../mfc/reference/csocket-class.md).  O exemplo utiliza objetos de `CArchive` para serializar dados por meio de um soquete.  Observe que esta não é serialização do documento para ou de um arquivo.  
  
 O exemplo a seguir ilustra como você usa o arquivo morto para enviar e receber dados entre objetos de `CSocket` .  O exemplo é criado para que duas instâncias de troca de dados do aplicativo \(no mesmo computador ou em computadores diferentes na rede\).  Uma instância enviará os dados, que a outra instância recebe e reconhece.  Um ou outro aplicativo pode iniciar uma troca, e qualquer pessoa pode atuar como o servidor ou como o cliente ao outro aplicativo.  A seguinte função é definida na classe de exibição de aplicativo:  
  
 [!CODE [NVC_MFCSimpleSocket#1](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCSimpleSocket#1)]  
  
 A é a mais importante sobre este exemplo é que suas paralelas da estrutura de MFC um `Serialize` funcione.  A função de membro de **PacketSerialize** consiste em uma instrução de **if** com uma cláusula de **else** .  A função recebe duas referências de [CArchive](../mfc/reference/carchive-class.md) como parâmetros: `arData` e `arAck`.  Se o objeto de arquivo de `arData` está definido para enviar \(\), a ramificação de **if** é executado; caso contrário, se `arData` está definido para a carga \(pull\) a função usa a ramificação de **else** .  Para obter mais informações sobre a serialização MFC no, consulte [Serialização](../mfc/how-to-make-a-type-safe-collection.md).  
  
> [!NOTE]
>  O objeto de arquivo de `arAck` é considerado como o oposto de `arData`.  Se `arData` está enviando, `arAck` receber, e o inverso é true.  
  
 Para enviar, a função de exemplo de looping para um número especificado de vezes, gerando sempre alguns dados aleatórios para demonstração propósitos.  Obtém ao seu aplicativo dados reais de alguma origem, como um arquivo.  O operador insert de arquivo de `arData` \(**\<\<**\) é usado para enviar um fluxo de três partes sucessivas de dados:  
  
-   “Um” cabeçalho que especifiquem a natureza de dados \(nesse caso, o valor da variável de `bValue` e quantas cópias sejam enviadas\).  
  
     Ambos os itens são gerados aleatoriamente para este exemplo.  
  
-   O número especificado de cópias de dados.  
  
     O loop interno de **for** envia `bValue` o número especificado de vezes.  
  
-   Uma cadeia de caracteres chamou `strText` que o destinatário exibe ao usuário.  
  
 Para receber, a função opera de maneira semelhante, exceto que usa o operador de extração de arquivo morto**\>\>**\(\) para obter dados de arquivo morto.  O aplicativo receptor verifica os dados que recebe, exibe a mensagem “recebida” final, e envia de volta uma mensagem que diz “enviado” para que o aplicativo que envia exibe.  
  
 As comunicações neste modelo, a palavra “recebidas”, a mensagem enviada na variável de `strText` , são para exibição em outro extremamente de comunicação, assim que especifica o usuário receptor que um determinado número de pacotes de dados foram recebidos.  O destinatário responder com uma cadeia de caracteres semelhante que diz “enviado”, para exibição na tela original do remetente.  O recebimento de ambas as cadeias de caracteres indica que a comunicação com êxito ocorreu.  
  
> [!CAUTION]
>  Se você estiver escrevendo um programa cliente MFC para se comunicar com os servidores \(não\) MFC estabelecidas, não enviar objetos C\+\+ por meio do arquivo morto.  A menos que o servidor é um aplicativo de MFC que compreende os tipos de objetos você deseja enviar, não poderá receber e desserializar seus objetos.  Um exemplo no artigo [Soquetes do windows: A ordenação de bytes](../mfc/windows-sockets-byte-ordering.md) mostra a comunicação desse tipo.  
  
 Especificação de soquetes do windows de Para obter mais informações, consulte: **htonl**, **htons**, **ntohl**, **ntohs**.  Além disso, para obter mais informações, consulte:  
  
-   [Soquetes do windows: Derivação das classes de soquete](../mfc/windows-sockets-deriving-from-socket-classes.md)  
  
-   [Soquetes do windows: Como os soquetes com arquivos mortos funcionam](../mfc/windows-sockets-how-sockets-with-archives-work.md)  
  
-   [Soquetes do windows: Plano de fundo](../mfc/windows-sockets-background.md)  
  
## Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)   
 [CArchive::IsStoring](../Topic/CArchive::IsStoring.md)   
 [CArchive::operator \<\<](../Topic/CArchive::operator%20%3C%3C.md)   
 [CArchive::operator \>\>](../Topic/CArchive::operator%20%3E%3E.md)   
 [CArchive::Flush](../Topic/CArchive::Flush.md)   
 [CObject::Serialize](../Topic/CObject::Serialize.md)