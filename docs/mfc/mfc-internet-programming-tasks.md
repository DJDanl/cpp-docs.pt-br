---
title: Tarefas de programação da Internet MFC
ms.date: 09/12/2018
helpviewer_keywords:
- Internet applications [MFC], getting started
- Internet applications [MFC], first steps
ms.assetid: 6377e9b8-07c4-4380-b63b-05f5a9061313
ms.openlocfilehash: 1b0a8696e25054099cdbf208dd5a1f713bfbe6d3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62164950"
---
# <a name="mfc-internet-programming-tasks"></a>Tarefas de programação da Internet MFC

Esta seção contém etapas detalhadas para a adição de suporte da Internet para seus aplicativos. Os tópicos incluem como usar as classes MFC para habilitar a Internet para seus aplicativos existentes e como adicionar suporte do documento ativo para o componente COM existente. Você deseja criar um documento com cotações de ações minuto a minuto, pontuações de futebol da Pittsburgh, e a temperatura mais recente em Microsoft Antártica fornece uma série de tecnologias para ajudá-lo a fazer isso pela Internet.

Tecnologias do Active Directory incluem controles ActiveX (anteriormente conhecido como controles OLE) e documentos ativos; WinInet para facilmente recuperar e salvar arquivos com a Internet; e monikers assíncronos para o download de dados eficiente. Visual C++ fornece assistentes para ajudar você a se familiarizar rapidamente com um aplicativo de início. Para obter uma introdução para essas tecnologias, consulte [Noções básicas de programação do MFC da Internet](../mfc/mfc-internet-programming-basics.md) e [COM MFC](../mfc/mfc-com.md).

Você sempre quis FTP um arquivo, mas ainda não tiver aprendido WinSock e programação classes WinInet de protocolos de rede encapsular esses protocolos, fornecendo a você um conjunto simples de funções que você pode usar para escrever um aplicativo cliente na Internet para baixar arquivos usando HTTP, FTP e gopher. Você pode usar o WinInet para procurar diretórios na unidade de disco rígido ou em todo o mundo. Modo transparente, você pode coletar dados de vários tipos diferentes e apresentá-lo para o usuário em uma interface integrada.

Você tem grandes quantidades de dados para fazer o download assíncrono monikers fornecem uma solução de COM (Component Object Model) para renderização progressiva de objetos grandes. O WinInet também pode ser usado de forma assíncrona.

A tabela a seguir descreve algumas das coisas que você pode fazer com essas tecnologias.

|Você tem|Você deseja|Você deve|
|--------------|-----------------|----------------|
|Um servidor Web.|Controlar logons e informações detalhadas sobre solicitações de URL.|Grave um filtro, as notificações de solicitação para eventos de logon e o mapeamento de URL.|
|Um navegador da Web.|Fornece conteúdo dinâmico.|Crie documentos ativos e controles ActiveX.|
|Um aplicativo baseado em documento.|Adicione suporte ao FTP um arquivo.|Use o WinInet ou monikers assíncronos.|

Consulte os tópicos a seguir para obter os detalhes para você começar:

- [Opções de design do aplicativo](../mfc/application-design-choices.md)

- [Escrevendo aplicativos MFC](../mfc/writing-mfc-applications.md)

- [Controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md)

- [Atualizando um controle ActiveX existente](../mfc/upgrading-an-existing-activex-control.md)

- [Monikers assíncronos na Internet](../mfc/asynchronous-monikers-on-the-internet.md)

- [Testando aplicativos da Internet](../mfc/testing-internet-applications.md)

- [Segurança da Internet](../mfc/internet-security-cpp.md)

## <a name="see-also"></a>Consulte também

[Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)<br/>
[Informações da Internet por tarefa](../mfc/internet-information-by-task.md)
