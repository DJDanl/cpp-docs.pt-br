---
title: "Windows Sockets: portas e endere&#231;os de soquete | Microsoft Docs"
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
  - "endereços [C++], soquete"
  - "portas [C++]"
  - "portas [C++], definição"
  - "soquetes [C++], endereços"
  - "soquetes [C++], portas"
  - "Windows Sockets [C++], endereços"
  - "Windows Sockets [C++], portas"
ms.assetid: e050261a-9285-4f31-a1c5-6c8033af5b4a
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Sockets: portas e endere&#231;os de soquete
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica os termos “move” e “tratar” como usado com soquetes do windows.  
  
##  <a name="_core_port"></a> Porta  
 Uma porta identifica um processo exclusivo para um serviço pode ser fornecido.  No contexto atual, uma porta é associada a um aplicativo que da suporte aos soquetes do windows.  A exibição é identificar exclusivamente cada aplicativo de soquetes do windows para que você possa ter mais de uma execução do aplicativo de soquetes do windows em um computador ao mesmo tempo.  
  
 Determinadas portas são reservadas para serviços comuns, como FTP.  Evite usar essas portas a menos que você esteja fornecendo esse tipo de serviço.  A especificação de soquetes do windows detalhes essas portas reservadas.  O arquivo WINSOCK.H também listar\-los.  
  
 Para permitir que os soquetes do windows a DLL seleciona uma porta útil para você, passar 0 como o valor da porta.  O MFC selecionar um decimal de 1.024 maior valor da porta.  Você pode recuperar o valor da porta que o MFC selecionou chamando a função de membro de [CAsyncSocket::GetSockName](../Topic/CAsyncSocket::GetSockName.md) .  
  
##  <a name="_core_socket_address"></a> Endereço de soquete  
 Cada objeto de soquete é associado a um endereço IP \(IP\) na rede.  Normalmente, o endereço é um nome de computador, como “ftp.microsoft.com”, ou um número pontilhado, como “128.56.22.8”.  
  
 Quando você pesquisa para criar um soquete, você normalmente não precisa especificar seu próprio endereço.  
  
> [!NOTE]
>  É possível que o seu computador tiver várias placas de rede \(ou seu aplicativo pode executar um dia nesse computador\), cada um representando uma rede diferente.  Nesse caso, você pode precisar fornecer um endereço para especificar que o cartão de rede o soquete usa.  Tem certeza de que isso será um uso avançado e um possível problema a portabilidade.  
  
 Para obter mais informações, consulte:  
  
-   [Soquetes do windows: Usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
-   [Soquetes do windows: Usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
-   [Soquetes do windows: Como os soquetes com arquivos mortos funcionam](../mfc/windows-sockets-how-sockets-with-archives-work.md)  
  
-   [Soquetes do windows: Soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Soquetes do windows: Soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
## Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)