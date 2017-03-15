---
title: "Windows Sockets: ordena&#231;&#227;o de bytes | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "problemas de ordem de bytes na programação de soquetes"
  - "soquetes [C++], problemas de ordem de bytes"
  - "Windows Sockets [C++], problemas de ordem de bytes"
ms.assetid: 8a787a65-f9f4-4002-a02f-ac25a5dace5d
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Sockets: ordena&#231;&#227;o de bytes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo e dois artigos complementares explicam vários problemas na programação de soquetes do windows.  Este artigo abrange a ordenação de bytes.  Outros problemas são abordados em artigos: [Soquetes do windows: Bloqueio](../Topic/Windows%20Sockets:%20Blocking.md) e [Soquetes do windows: Convertendo cadeias de caracteres](../mfc/windows-sockets-converting-strings.md).  
  
 Se você usar ou se deriva da classe [CAsyncSocket](../Topic/CAsyncSocket%20Class.md), você precisará gerenciar esses problemas você mesmo.  Se você usar ou se deriva da classe [CSocket](../mfc/reference/csocket-class.md), o MFC gerenciá\-los para você.  
  
## A ordenação de bytes  
 Dados diferentes do repositório das arquiteturas do computador às vezes usando ordens diferentes de byte.  Por exemplo, dados com base no processador intel de computadores na ordem inversa de computadores Macintosh \(Motorola\).  A ordem de bytes Intel, “little\-endian chamado”, também é o oposto de pedidos “grande Endian” de rede padrão.  A tabela a seguir explica esses termos.  
  
### Ordenação grande e little\-endian de byte  
  
|A ordenação de bytes|Significado|  
|--------------------------|-----------------|  
|Grande Endian|O byte mais significativo o estiver na extremidade esquerda de uma palavra.|  
|Little\-endian|O byte mais significativo o estiver na extremidade direita de uma palavra.|  
  
 Normalmente, você não precisa se preocupar sobre a conversão de byte\- ordem dos dados que você envia e recebe pela rede, mas há situações em que você deve converter pedidos de byte.  
  
## Quando você deverá converter pedidos de byte  
 Você precisa converter pedidos de bytes nas seguintes situações:  
  
-   O transmitir informações que precisa ser interpretada pela rede, ao contrário dos dados que você está enviando para outro computador.  Por exemplo, você pode passar as portas e os endereços, que deve entender a rede.  
  
-   O aplicativo de servidor com a qual você estiver se comunicando não é um aplicativo \(MFC e você não tenha o código\-fonte para ele.\)  Este chama para o byte de regras conversões se os dois computadores não compartilham a mesma ordenação de bytes.  
  
## Quando você não tenha que converter pedidos de byte  
 Você pode evitar o trabalho da conversão de pedidos de bytes nas seguintes situações:  
  
-   Os computadores em ambas as extremidades concordar não podem alternar bytes, e ambos os computadores usam a mesma ordem de byte.  
  
-   O servidor que você estiver se comunicando com o é um aplicativo de MFC.  
  
-   Você tem a origem para o servidor que você estiver se comunicando com essa forma, você pode informar explicitamente se você deve converter pedidos de bytes ou não.  
  
-   Você pode mover o servidor a. MFC  Isso é razoavelmente fácil de fazer, e o resultado é geralmente código menor, mais rápido.  
  
 Trabalhando com [CAsyncSocket](../Topic/CAsyncSocket%20Class.md), você deve gerenciar todas as conversões necessárias de byte\- ordem que você mesmo.  Soquetes do windows padronizam o modelo “grande Endian” de byte\- ordem e fornece funções para converter entre essa ordem e outros.  [CArchive](../mfc/reference/carchive-class.md), entretanto, que você usa com [CSocket](../mfc/reference/csocket-class.md), usa \(“little\-endian”\) a ordem inversa, mas `CArchive` usa os detalhes de conversões de byte\- ordem para você.  Usando esse padrão de ordenação em seus aplicativos, ou usando funções de conversão de byte\- ordem de soquetes do windows, você poderá fazer seu código mais portátil.  
  
 Os argumentos ideais para usar soquetes de MFC é quando você estiver gravando as duas extremindades de comunicação: usando o MFC em ambas as extremidades.  Se você estiver escrevendo um aplicativo que se comunicam com os aplicativos não MFC, como um servidor de FTP, você provavelmente precisará de gerenciar byte\- alternar\-se antes que você transmita dados ao objeto de arquivo, usando as rotinas de conversão **ntohs**de soquetes do windows, **ntohl**, **htons**, e **htonl**.  Um exemplo dessas funções usadas na comunicação com um aplicativo não MFC é exibida posteriormente neste artigo.  
  
> [!NOTE]
>  Quando o outro fim de comunicação não é um aplicativo de MFC, você também deve evitar transmitir os objetos C\+\+ derivados de `CObject` em seu arquivo morto porque o receptor não poderá controlar os.  Consulte a observação em [Soquetes do windows: Usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md).  
  
 Para obter mais informações sobre pedidos de byte, consulte a especificação de soquetes do windows, disponível em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Um exemplo de conversão de Byte\- ordem  
 O exemplo a seguir mostra uma função de serialização de um objeto de `CSocket` que use um arquivo morto.  Também ilustra a utilização das funções de conversão de byte\- ordem nos soquetes apis do windows.  
  
 Este exemplo apresenta um cenário em que você estiver escrevendo um cliente que se comunicam com um aplicativo de servidor não MFC para que você não tiver acesso ao código\-fonte.  Neste cenário, você deve pressupor que o servidor não MFC usa a ordem padrão de bytes de rede.  Em contraste, o aplicativo cliente MFC usa um objeto de `CArchive` com um objeto de `CSocket` , e a ordem “little\-endian” de bytes de `CArchive` , o oposto do padrão de rede.  
  
 Suponha que o servidor não MFC com a qual você planeja se comunicar tem um protocolo definido para um pacote de mensagem como o seguinte:  
  
 [!CODE [NVC_MFCSimpleSocket#5](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCSimpleSocket#5)]  
  
 Em termos de MFC, seria expresso como segue:  
  
 [!CODE [NVC_MFCSimpleSocket#6](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCSimpleSocket#6)]  
  
 Em C\+\+, `struct` é basicamente a mesma coisa que uma classe.  A estrutura de `Message` pode ter funções de membro, como a função de membro de `Serialize` declarada anteriormente.  A função de membro de `Serialize` poderia se parecer com:  
  
 [!CODE [NVC_MFCSimpleSocket#7](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCSimpleSocket#7)]  
  
 As chamadas neste exemplo para conversões de byte\- ordem dos dados porque existe uma incompatibilidade clara entre a ordenação de bytes de aplicativo de servidor não MFC em uma extremidade e `CArchive` usado no aplicativo cliente MFC em outro termina.  O exemplo a seguir ilustra várias de conversão de byte\- ordem funções que usam fontes de soquetes do windows.  A tabela a seguir descreve essas funções.  
  
### Funções de conversão de Byte\- ordem de soquetes do windows  
  
|Função|Finalidade|  
|------------|----------------|  
|**ntohs**|Converter um valor de 16 bits de ordem de byte de rede hospedar a ordem de byte \(grande Endian a little\-endian.\)|  
|**ntohl**|Converter um valor de 32 bits de ordem de byte de rede hospedar a ordem de byte \(grande Endian a little\-endian.\)|  
|**Htons**|Converter um valor de 16 bits de ordem de byte de host para o ordem de byte de rede \(little\-endian a grande Endian\).|  
|**Htonl**|Converter um valor de 32 bits de ordem de byte de host para o ordem de byte de rede \(little\-endian a grande Endian\).|  
  
 Outro ponto deste exemplo é que enquanto o aplicativo de soquete na outra extremidade da comunicação é um aplicativo não MFC, evite fazer algo como:  
  
 `ar << pMsg;`  
  
 onde `pMsg` é um ponteiro para o objeto c criando derivado da classe `CObject`.  Isso enviará informações adicionais de MFC associada aos objetos e não a integrará, como se fosse um aplicativo MFC.  
  
 Para obter mais informações, consulte:  
  
-   [Soquetes do windows: Usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
-   [Soquetes do windows: Plano de fundo](../mfc/windows-sockets-background.md)  
  
-   [Soquetes do windows: Soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Soquetes do windows: Soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
## Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)