---
title: Tarefas de programação da Internet MFC
ms.date: 09/12/2018
helpviewer_keywords:
- Internet applications [MFC], getting started
- Internet applications [MFC], first steps
ms.assetid: 6377e9b8-07c4-4380-b63b-05f5a9061313
ms.openlocfilehash: 6d8a542ada94bc52ee2000bc92ae0457ec87609c
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617956"
---
# <a name="mfc-internet-programming-tasks"></a>Tarefas de programação da Internet MFC

Esta seção contém etapas detalhadas para adicionar suporte à Internet para seus aplicativos. Os tópicos incluem como usar as classes do MFC para habilitar a Internet em seus aplicativos existentes e como adicionar suporte a documentos ativos ao seu componente COM existente. Você deseja criar um documento com Cotações de ações atualizadas, pontuações de futebol de Pittsburgh e a temperatura mais recente na Antártica Microsoft fornece uma série de tecnologias para ajudá-lo a fazer isso pela Internet.

As tecnologias ativas incluem controles ActiveX (anteriormente conhecidos como controles OLE) e documentos ativos; WinInet para recuperar e salvar arquivos com facilidade na Internet; e identificadores assíncronos para download de dados eficiente. O Visual C++ fornece assistentes para ajudá-lo a começar rapidamente com um aplicativo inicial. Para obter uma introdução a essas tecnologias, consulte [noções básicas de programação da Internet do MFC](mfc-internet-programming-basics.md) e com do [MFC](mfc-com.md).

Você sempre quis fazer o FTP de um arquivo, mas não aprendeu o WinSock e os protocolos de programação de rede, as classes WinInet encapsulam esses protocolos, fornecendo um conjunto simples de funções que você pode usar para escrever um aplicativo cliente na Internet para baixar arquivos usando HTTP, FTP e Gopher. Você pode usar o WinInet para pesquisar diretórios no disco rígido ou em todo o mundo. Você pode coletar dados de forma transparente de vários tipos diferentes e apresentá-los ao usuário em uma interface integrada.

Você tem grandes quantidades de dados para baixar monikers assíncronos fornecem uma solução COM (Component Object Model) para renderização progressiva de objetos grandes. O WinInet também pode ser usado de forma assíncrona.

A tabela a seguir descreve algumas das coisas que você pode fazer com essas tecnologias.

|Você tem|Você deseja|Você deve|
|--------------|-----------------|----------------|
|Um servidor Web.|Acompanhe logons e informações detalhadas sobre solicitações de URL.|Escreva um filtro, solicite notificações para eventos de logon e mapeamento de URL.|
|Um navegador da Web.|Fornecer conteúdo dinâmico.|Criar controles ActiveX e documentos ativos.|
|Um aplicativo baseado em documento.|Adicione suporte a um arquivo FTP.|Use o WinInet ou os monikers assíncronos.|

Consulte os tópicos a seguir para obter detalhes para começar:

- [Opções de design do aplicativo](application-design-choices.md)

- [Escrevendo aplicativos MFC](writing-mfc-applications.md)

- [Controles ActiveX na Internet](activex-controls-on-the-internet.md)

- [Atualizando um controle ActiveX existente](upgrading-an-existing-activex-control.md)

- [Monikers assíncronos na Internet](asynchronous-monikers-on-the-internet.md)

- [Testando aplicativos da Internet](testing-internet-applications.md)

- [Segurança da Internet](internet-security-cpp.md)

## <a name="see-also"></a>Consulte também

[Noções básicas de programação na Internet do MFC](mfc-internet-programming-basics.md)<br/>
[Informações da Internet por tarefa](internet-information-by-task.md)
