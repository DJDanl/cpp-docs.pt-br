---
title: 'Windows Sockets: Portas e endereços de soquete | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ports [MFC], definition
- Windows Sockets [MFC], ports
- Windows Sockets [MFC], addresses
- ports [MFC]
- addresses [MFC], socket
- sockets [MFC], addresses
- sockets [MFC], ports
ms.assetid: e050261a-9285-4f31-a1c5-6c8033af5b4a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 42ea9b8a39de8d36ecb621164d98e072a4041211
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="windows-sockets-ports-and-socket-addresses"></a>Windows Sockets: portas e endereços de soquete
Este artigo explica os termos "port" e "address" como usado com o Windows Sockets.  
  
##  <a name="_core_port"></a> Porta  
 Uma porta identifica um processo exclusivo para o qual um serviço pode ser fornecido. No contexto atual, uma porta está associada um aplicativo que dá suporte ao Windows Sockets. A ideia é para identificar exclusivamente a cada aplicativo do Windows Sockets para que você possa ter mais de um aplicativo de Windows Sockets em execução em um computador ao mesmo tempo.  
  
 Determinadas portas são reservadas para serviços comuns, como FTP. Você deve evitar usar essas portas, a menos que você está fornecendo esse tipo de serviço. A especificação de Windows Sockets fornece detalhes sobre essas portas reservadas. O arquivo WINSOCK. H também lista-los.  
  
 Para permitir que a DLL do Windows Sockets selecionar uma porta utilizável para você, passe 0 como o valor da porta. MFC seleciona um valor de porta maior 1.024 decimal. Você pode recuperar o valor de porta selecionado MFC chamando o [CAsyncSocket::GetSockName](../mfc/reference/casyncsocket-class.md#getsockname) função de membro.  
  
##  <a name="_core_socket_address"></a> Endereço de soquete  
 Cada objeto de soquete está associado um endereço IP (Internet Protocol) na rede. Normalmente, o endereço é um nome de máquina, como "ftp.microsoft.com", ou um número pontilhado, como "128.56.22.8".  
  
 Quando você tentar criar um soquete, você normalmente não precisa especificar seu próprio endereço.  
  
> [!NOTE]
>  É possível que sua máquina possui várias placas de rede (ou seu aplicativo pode ser executado um dia em tal uma máquina), cada uma representando uma rede diferente. Nesse caso, você precisará fornecer um endereço para especificar qual placa de rede usará o soquete. Isso é determinado a ser um problema de portabilidade possíveis e um uso avançado.  
  
 Para obter mais informações, consulte:  
  
-   [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
-   [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
-   [Windows Sockets: como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md)  
  
-   [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)  
  
-   [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)

