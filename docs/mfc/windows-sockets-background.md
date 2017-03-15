---
title: "Windows Sockets: plano de fundo | Microsoft Docs"
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
  - "comunicações [C++], domínio"
  - "tipos de dados [C++], soquete"
  - "soquetes de datagrama [C++]"
  - "email [C++]"
  - "email [C++], programação para"
  - "Internet Protocol Suite"
  - "email [C++]"
  - "email [C++], programação para"
  - "dados orientados a registros [C++]"
  - "fluxo de dados em sequência"
  - "Identificador SOCKET"
  - "soquetes [C++], soquetes de fluxo"
  - "soquetes de fluxo [C++]"
  - "Windows Sockets [C++], soquetes de fluxo"
  - "servidores X Window"
ms.assetid: f60d4ed2-bf23-4a0e-98d2-fee77e8473dd
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Sockets: plano de fundo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica a natureza e a finalidade de soquetes do windows.  O artigo também:  
  
-   [Define o termo “soquete”](#_core_definition_of_a_socket).  
  
-   [Descreve o tipo de dados do identificador de SOQUETE](#_core_the_socket_data_type).  
  
-   [Descreve usos para soquetes](#_core_uses_for_sockets).  
  
 A especificação de soquetes do windows define uma interface de programação binário correspondente de rede do Microsoft Windows.  Soquetes do windows baseiam\-se na implementação de soquetes do UNIX em Berkeley Software Distribution \(DEB, versão 4,3\) de Universidade de California em Berkeley.  A especificação inclui as rotinas e extensões de soquete de DEB\- estilo específicas do windows.  Usar soquetes do windows permite seu aplicativo se comunicar por meio de toda a rede que se conformar a soquetes apis do windows.  No Win32, soquetes do windows preveem a segurança de thread.  
  
 Muitos provedores de software de rede oferecem suporte a soquetes do windows nos protocolos de rede que incluem o protocolo TCP\/IP, o Xerox Network System \(XNS\), protocolo de DECnet de Digital Equipment Corporation, o Exchange pacote\/Exchange empacotado colocado em sequência IPX\/SPX \(\), e outro da Internet de Novell Corporation.  Embora a especificação atual de soquetes do windows define a abstração de soquetes de TCP\/IP, qualquer protocolo de rede pode estar de acordo com os soquetes do windows fornecendo sua própria \(DLL\) versão da biblioteca de vínculo dinâmico\) que implementa os soquetes do windows.  Exemplos de aplicativos comerciais gravados com soquetes do windows incluem servidores windows X, emuladores terminais, e sistemas de email eletrônicos.  
  
> [!NOTE]
>  A finalidade de soquetes do windows é acionado abstrair a rede subjacente de modo que não seja necessário conhecer a rede e assim que seu aplicativo pode executar em qualquer rede que ofereça suporte a soquetes.  Em virtude disso, esta documentação não discute os detalhes de protocolos de rede.  
  
 A programação da suporte à biblioteca de classes do Microsoft \(MFC\) com os soquetes apis do windows fornecendo duas classes.  Uma dessas classes, `CSocket`, o fornece um nível alto de abstração para simplificar sua programação de comunicações de rede.  
  
 Soquetes especificação do windows, soquetes do windows: Uma interface aberta para a computação da rede no Microsoft Windows, agora na versão 1,1, foi desenvolvida como um padrão aberto do sistema de rede por um grupo grande de indivíduos e de corporaçõs na comunidade TCP\/IP e livremente está disponível para uso.  Soquetes o modelo de programação dão suporte a um domínio “comunicação” atualmente, usando o pacote do protocolo IP.  A especificação está disponível em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
> [!TIP]
>  Como os soquetes usam o pacote do protocolo IP, são a rota preferida para os aplicativos que dão suporte à comunicação da Internet “na informações de estrada.”  
  
##  <a name="_core_definition_of_a_socket"></a> Definição de um soquete  
 Um soquete é um ponto de extremidade de comunicação — um objeto através do qual um aplicativo de soquetes do windows envia ou recebe pacotes de dados por meio de uma rede.  Um soquete tem um tipo e é associado a um processo em execução, e pode ter um nome.  Atualmente, de soquetes troca de dados geralmente apenas com outros soquetes no mesmo domínio de uma comunicação “,” usando o pacote do protocolo IP.  
  
 Ambos os tipos de soquetes são bidirecionais; são fluxos de dados que podem ser comunicados em ambas as direções simultaneamente \(completa frente e verso\).  
  
 Dois tipos de soquete estão disponíveis:  
  
-   Soquetes de fluxo  
  
     Soquetes de fluxo preveem um fluxo de dados sem limites do registro: um fluxo de bytes.  Os fluxos são certamente entregue corretamente e para ser colocados em sequência e unduplicated.  
  
-   Soquetes de datagrama  
  
     Soquetes de datagrama oferecem suporte a um fluxo de dados orientado interfaces que não é garantido para ser entregue e não podem ser colocados em sequência como enviado ou unduplicated.  
  
 “Colocado em sequência” significa que os pacotes são entregues na ordem enviado. “Unduplicated” significa que você obtém um pacote específico apenas uma vez.  
  
> [!NOTE]
>  Em alguns protocolos de rede, como o XNS, os fluxos podem ser orientada registro, como fluxos de registros em vez de fluxos de bytes.  No protocolo TCP\/IP mais comum, no entanto, os fluxos são fluxos de byte.  Soquetes do windows fornecem um nível de independente de abstração de protocolo subjacente.  
  
 Para obter informações sobre estes tipos e que tipo de soquete a usar em que situações, consulte [Soquetes do windows: Soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md) e [Soquetes do windows: Soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md).  
  
##  <a name="_core_the_socket_data_type"></a> O tipo de dados de SOQUETE  
 Cada objeto de soquete MFC encapsula um identificador para um objeto de soquetes do windows.  O tipo de dados desse identificador é **SOCKET**.  Um identificador de **SOCKET** equivale a `HWND` para uma janela.  As classes de soquete MFC fornecem operações encapsuladas no identificador.  
  
 O tipo de dados de **SOCKET** é descrito em detalhes em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  Consulte “o tipo de dados soquete e avalia o erro” nos soquetes do windows.  
  
##  <a name="_core_uses_for_sockets"></a> Usa para soquetes  
 Soquetes são altamente úteis em pelo menos três contextos de comunicações:  
  
-   Modelos cliente\/servidor.  
  
-   Cenários ponto a ponto, como aplicativos de mensagem.  
  
-   Fazendo chamadas de procedimento remoto \(RPC\) com o aplicativo receptor interprete uma mensagem como uma chamada de função.  
  
> [!TIP]
>  Os argumentos ideais para usar soquetes de MFC é quando você estiver gravando as duas extremindades de comunicação: usando o MFC em ambas as extremidades.  Para obter mais informações sobre esse tópico, inclusive como gerenciar os casos quando você estiver se comunicando com os aplicativos não MFC, consulte [Soquetes do windows: A ordenação de bytes](../mfc/windows-sockets-byte-ordering.md).  
  
 Especificação de soquetes do windows de Para obter mais informações, consulte: **ntohs**, **ntohl**, **htons**, **htonl**.  Além disso, consulte os seguintes tópicos:  
  
-   [Soquetes do windows: Usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
-   [Soquetes do windows: Exemplo de soquetes usando arquivos mortos](../mfc/windows-sockets-example-of-sockets-using-archives.md)  
  
-   [Soquetes do windows: Usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
## Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)