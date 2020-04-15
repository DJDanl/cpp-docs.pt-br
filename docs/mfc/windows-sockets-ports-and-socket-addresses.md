---
title: 'Windows Sockets: portas e endereços de soquete'
ms.date: 11/04/2016
helpviewer_keywords:
- ports [MFC], definition
- Windows Sockets [MFC], ports
- Windows Sockets [MFC], addresses
- ports [MFC]
- addresses [MFC], socket
- sockets [MFC], addresses
- sockets [MFC], ports
ms.assetid: e050261a-9285-4f31-a1c5-6c8033af5b4a
ms.openlocfilehash: 791bf07c927e80e65e0fda79fae8a50235bc2def
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371039"
---
# <a name="windows-sockets-ports-and-socket-addresses"></a>Windows Sockets: portas e endereços de soquete

Este artigo explica os termos "porta" e "endereço" usados com soquetes do Windows.

## <a name="port"></a><a name="_core_port"></a>Porta

Uma porta identifica um processo único para o qual um serviço pode ser fornecido. No contexto atual, uma porta está associada a um aplicativo que suporta soquetes do Windows. A ideia é identificar cada aplicativo do Windows Sockets de forma única para que você possa ter mais de um aplicativo do Windows Sockets em execução em uma máquina ao mesmo tempo.

Certos portos são reservados para serviços comuns, como ftp. Você deve evitar usar essas portas a menos que você esteja fornecendo esse tipo de serviço. A especificação do Windows Sockets detalha essas portas reservadas. O arquivo WINSOCK. H também lista-los.

Para permitir que o Windows Sockets DLL selecione uma porta utilizável para você, passe 0 como o valor da porta. O MFC seleciona um valor de porta superior a 1.024 decimais. Você pode recuperar o valor da porta que o MFC selecionou chamando a função de membro [CAsyncSocket::GetSockName.](../mfc/reference/casyncsocket-class.md#getsockname)

## <a name="socket-address"></a><a name="_core_socket_address"></a>Endereço do soquete

Cada objeto de soquete está associado a um endereço IP (Internet Protocol) na rede. Normalmente, o endereço é um nome de máquina, como "ftp.microsoft.com", ou um número pontilhado, como "128.56.22.8".

Quando você procura criar um soquete, você normalmente não precisa especificar seu próprio endereço.

> [!NOTE]
> É possível que sua máquina tenha várias placas de rede (ou seu aplicativo pode um dia ser executado em tal máquina), cada uma representando uma rede diferente. Se assim for, você pode precisar dar um endereço para especificar qual cartão de rede o soquete usará. Este é certamente um uso avançado e um possível problema de portabilidade.

Para obter mais informações, consulte:

- [Windows Sockets: usando classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

- [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)

- [Windows Sockets: como funcionam soquetes com arquivos mortos](../mfc/windows-sockets-how-sockets-with-archives-work.md)

- [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md)

- [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md)

## <a name="see-also"></a>Confira também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)
