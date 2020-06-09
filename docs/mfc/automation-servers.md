---
title: Servidores de automação
ms.date: 11/04/2016
helpviewer_keywords:
- Automation servers
- COM components, Automation servers
- dispatch maps [MFC], Automation servers
- servers, Automation
ms.assetid: 523fd155-51ce-4f91-b986-b74bdbdd7d92
ms.openlocfilehash: 4c2ef77e20b7dccfa8cd6830c090111601331642
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619412"
---
# <a name="automation-servers"></a>Servidores de automação

A automação possibilita que seu aplicativo manipule objetos implementados em outro aplicativo ou expor objetos para que possam ser manipulados. Um servidor de automação é um aplicativo que expõe objetos programáveis (chamados de objetos de automação) a outros aplicativos (chamados de [clientes de automação](automation-clients.md)). Os servidores de automação às vezes são chamados de componentes de automação.

A exposição de objetos de automação permite que os clientes automatizem determinados procedimentos acessando diretamente os objetos e a funcionalidade disponibilizados pelo servidor. Expor objetos dessa maneira é benéfico quando os aplicativos fornecem funcionalidade útil para outros aplicativos. Por exemplo, um processador de texto pode expor sua funcionalidade de verificação ortográfica para que outros programas possam usá-la. A exposição de objetos, portanto, permite que os fornecedores aprimorem a funcionalidade dos aplicativos usando a funcionalidade pronta de outros aplicativos.

Esses objetos de automação têm propriedades e métodos como sua interface externa. As propriedades são atributos nomeados do objeto Automation. As propriedades são como os membros de dados de uma classe C++. Os métodos são funções que funcionam em objetos de automação. Os métodos são como as funções membro público de uma classe C++.

> [!NOTE]
> Embora as propriedades sejam como membros de dados do C++, elas não são acessíveis diretamente. Para fornecer acesso transparente, configure uma variável interna no objeto Automation com um par de funções membro get/set para acessá-las.

Expondo a funcionalidade do aplicativo por meio de uma interface comum e bem definida, a automação possibilita a criação de aplicativos em uma única linguagem de programação geral, como a Microsoft Visual Basic, em vez de diversas linguagens de macro específicas do aplicativo.

## <a name="support-for-automation-servers"></a><a name="_core_support_for_automation_servers"></a>Suporte para servidores de automação

Visual C++ e a estrutura MFC fornecem amplo suporte para servidores de automação. Eles lidam com grande parte da sobrecarga envolvida na criação de um servidor de automação, para que você possa concentrar seus esforços na funcionalidade do seu aplicativo.

O mecanismo principal da estrutura para dar suporte à automação é o mapa de expedição, um conjunto de macros que se expande para as declarações e chamadas necessárias para expor métodos e propriedades para OLE. Um mapa de expedição típico é semelhante ao seguinte:

[!code-cpp[NVC_MFCAutomation#1](codesnippet/cpp/automation-servers_1.cpp)]

O [Assistente de classe](reference/mfc-class-wizard.md) e modo de exibição de classe auxiliar na manutenção de mapas de expedição. Quando você adiciona um novo método ou propriedade a uma classe, o Visual Studio adiciona uma `DISP_FUNCTION` macro ou um correspondente `DISP_PROPERTY` com parâmetros que indicam o nome da classe, os nomes externos e internos do método ou da propriedade e os tipos de dados.

A caixa de diálogo **Adicionar classe** também simplifica a declaração de classes de automação e o gerenciamento de suas propriedades e operações. Quando você usa a caixa de diálogo Adicionar classe para adicionar uma classe ao seu projeto, você especifica sua classe base. Se a classe base permitir a automação, a caixa de diálogo Adicionar classe exibirá os controles que você usa para especificar se a nova classe deve dar suporte à automação, se é "OLE creatable" (ou seja, se os objetos da classe podem ser criados em uma solicitação de um cliente COM) e o nome externo do cliente COM a ser usado.

Em seguida, a caixa de diálogo **Adicionar classe** cria uma declaração de classe, incluindo as macros apropriadas para os recursos OLE que você especificou. Ele também adiciona o código esqueleto para implementação das funções de membro da classe.

O assistente de aplicativo do MFC simplifica as etapas envolvidas na obtenção do aplicativo de servidor de automação fora do chão. Se você marcar a caixa de seleção **automação** na página **recursos avançados** , o assistente de aplicativo do MFC adicionará à `InitInstance` função do aplicativo as chamadas necessárias para registrar seus objetos de automação e executar seu aplicativo como um servidor de automação.

### <a name="what-do-you-want-to-do"></a>O que você deseja fazer

- [Saiba mais sobre clientes de automação](automation-clients.md)

- [Saiba mais sobre a classe CCmdTarget](reference/ccmdtarget-class.md)

- [Saiba mais sobre a classe COleDispatchDriver](reference/coledispatchdriver-class.md)

## <a name="see-also"></a>Consulte também

[Automação](automation.md)<br/>
[Assistente de aplicativo do MFC](reference/mfc-application-wizard.md)
