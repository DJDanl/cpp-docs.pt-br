---
title: Servidores de automação
ms.date: 11/04/2016
helpviewer_keywords:
- Automation servers
- COM components, Automation servers
- dispatch maps [MFC], Automation servers
- servers, Automation
ms.assetid: 523fd155-51ce-4f91-b986-b74bdbdd7d92
ms.openlocfilehash: 391cb2f6ff5673296f40e21113e3a6510f71d475
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370832"
---
# <a name="automation-servers"></a>Servidores de automação

A automação permite que seu aplicativo manipule objetos implementados em outro aplicativo ou exponha objetos para que possam ser manipulados. Um servidor de automação é um aplicativo que expõe objetos programáveis (chamados objetos de automação) a outros aplicativos (chamados [clientes de automação](../mfc/automation-clients.md)). Os servidores de automação às vezes são chamados de componentes de automação.

Expor objetos de Automação permite que os clientes automatizem certos procedimentos acessando diretamente os objetos e funcionalidades que o servidor disponibiliza. Expor objetos dessa forma é benéfico quando os aplicativos fornecem funcionalidades úteis para outros aplicativos. Por exemplo, um processador de texto pode expor sua funcionalidade de verificação ortopedia para que outros programas possam usá-lo. A exposição de objetos permite, assim, que os fornecedores melhorem a funcionalidade de seus aplicativos usando a funcionalidade pronta de outros aplicativos.

Esses objetos de Automação têm propriedades e métodos como sua interface externa. As propriedades são denominadas atributos do objeto Automação. As propriedades são como os membros de dados de uma classe C++. Métodos são funções que funcionam em objetos de automação. Os métodos são como as funções de membros públicos de uma classe C++.

> [!NOTE]
> Embora as propriedades sejam como membros de dados C++, elas não são diretamente acessíveis. Para fornecer acesso transparente, configure uma variável interna no objeto Automação com um par de funções get/set para acessá-las.

Ao expor a funcionalidade do aplicativo através de uma interface comum e bem definida, a Automação permite criar aplicativos em uma única linguagem de programação geral, como o Microsoft Visual Basic, em vez de em linguagens macro diversas e específicas para aplicativos.

## <a name="support-for-automation-servers"></a><a name="_core_support_for_automation_servers"></a>Suporte para servidores de automação

O Visual C++ e a estrutura MFC fornecem amplo suporte para servidores de automação. Eles lidam com grande parte das despesas gerais envolvidas na criação de um servidor de Automação, para que você possa concentrar seus esforços na funcionalidade do seu aplicativo.

O principal mecanismo do framework para apoiar a Automação é o mapa de despacho, um conjunto de macros que se expande para as declarações e chamadas necessárias para expor métodos e propriedades para OLE. Um mapa típico de despacho se parece com isso:

[!code-cpp[NVC_MFCAutomation#1](../mfc/codesnippet/cpp/automation-servers_1.cpp)]

O [Assistente de Classe](reference/mfc-class-wizard.md) e a Exibição de Classe auxiliam na manutenção de mapas de despacho. Quando você adiciona um novo método ou propriedade a `DISP_FUNCTION` `DISP_PROPERTY` uma classe, o Visual Studio adiciona um correspondente ou macro com parâmetros que indicam o nome da classe, nomes externos e internos do método ou propriedade e tipos de dados.

A caixa de diálogo **Adicionar classe** também simplifica a declaração das classes de Automação e o gerenciamento de suas propriedades e operações. Quando você usa a caixa de diálogo Adicionar classe para adicionar uma classe ao seu projeto, você especifica sua classe base. Se a classe base permitir automação, a caixa de diálogo Adicionar classe exibe controles usados para especificar se a nova classe deve suportar automação, se é "creatable OLE" (ou seja, se objetos da classe podem ser criados a partir de uma solicitação de um cliente COM) e o nome externo para o cliente COM usar.

A caixa de diálogo **Adicionar classe** cria então uma declaração de classe, incluindo as macros apropriadas para os recursos oLE especificados. Ele também adiciona o código esqueleto para a implementação das funções de membro da sua classe.

O MFC Application Wizard simplifica as etapas envolvidas para tirar o aplicativo do servidor de automação do chão. Se você selecionar a caixa de seleção **automação** na página Recursos `InitInstance` **Avançados,** o Assistente de Aplicativo do MFC adicionará à função do aplicativo as chamadas necessárias para registrar seus objetos de automação e executar seu aplicativo como um servidor de automação.

### <a name="what-do-you-want-to-do"></a>O que você quer fazer?

- [Conheça os clientes de Automação](../mfc/automation-clients.md)

- [Saiba mais sobre a classe CCmdTarget](../mfc/reference/ccmdtarget-class.md)

- [Saiba mais sobre a classe COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md)

## <a name="see-also"></a>Confira também

[Automação](../mfc/automation.md)<br/>
[Assistente de aplicativo do MFC](../mfc/reference/mfc-application-wizard.md)
