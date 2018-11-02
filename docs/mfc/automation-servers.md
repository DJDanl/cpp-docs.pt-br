---
title: Servidores de automação
ms.date: 11/04/2016
helpviewer_keywords:
- Automation servers
- COM components, Automation servers
- dispatch maps [MFC], Automation servers
- servers, Automation
ms.assetid: 523fd155-51ce-4f91-b986-b74bdbdd7d92
ms.openlocfilehash: 0c7f3a3bd37c5f7f5696de363aa646f5376f4e75
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50468790"
---
# <a name="automation-servers"></a>Servidores de automação

Automação torna possível para seu aplicativo para manipular objetos implementados em outro aplicativo ou para expor objetos para que eles podem ser manipulados. Um servidor de automação é um aplicativo que expõe objetos programáveis (chamados de objetos de automação) para outros aplicativos (chamado [clientes de automação](../mfc/automation-clients.md)). Servidores de automação, às vezes, são chamados de componentes de automação.

Expor objetos de automação permite que os clientes automatizar certos procedimentos, acessando diretamente os objetos e funcionalidade de servidor torna-se disponível. Expondo objetos dessa maneira é benéfico quando os aplicativos fornecem funcionalidade que é útil para outros aplicativos. Por exemplo, um processador de texto pode expor sua funcionalidade de verificação ortográfica para que outros programas podem usá-lo. Exposição de objetos, portanto, permite que os fornecedores melhorar a funcionalidade de seus aplicativos usando a funcionalidade prontas para uso de outros aplicativos.

Esses objetos de automação têm propriedades e métodos, como a interface externa. Propriedades são chamadas de atributos do objeto de automação. As propriedades são como os membros de dados de uma classe C++. Métodos são funções que funcionam em objetos de automação. Métodos são como as funções de membro público de uma classe C++.

> [!NOTE]
>  Embora as propriedades são como membros de dados do C++, eles não são diretamente acessíveis. Para fornecer acesso transparente, configure uma variável interna no objeto de automação com um par de funções de membro get/set para acessá-los.

Expondo a funcionalidade do aplicativo por meio de uma interface comum e bem definida, automação torna possível a criação de aplicativos em um único geral linguagem de programação, como o Microsoft Visual Basic, em vez de em macro diversificada, específicos do aplicativo Idiomas.

##  <a name="_core_support_for_automation_servers"></a> Suporte para servidores de automação

Visual C++ e a estrutura MFC fornecem suporte extensivo para servidores de automação. Eles manipulam muita sobrecarga envolvida na tomada de um servidor de automação, para que você possa concentrar seus esforços na funcionalidade do seu aplicativo.

Mecanismo de entidade de segurança do framework para dar suporte a automação é o mapa de expedição, um conjunto de macros que expande em declarações e chamadas necessárias para expor métodos e propriedades para OLE. Um mapa de expedição típico tem esta aparência:

[!code-cpp[NVC_MFCAutomation#1](../mfc/codesnippet/cpp/automation-servers_1.cpp)]

A janela de propriedades e o modo de exibição de classe auxiliam na manutenção de mapas de expedição. Quando você adiciona um novo método ou propriedade a uma classe, o Visual C++ adiciona um correspondente `DISP_FUNCTION` ou `DISP_PROPERTY` macro com parâmetros que indica o nome de classe, os nomes internos e externos dos método ou propriedade e tipos de dados.

O **Adicionar classe** caixa de diálogo também simplifica a declaração de classes de automação e o gerenciamento de suas propriedades e operações. Quando você usa a caixa de diálogo Adicionar classe para adicionar uma classe ao seu projeto, você pode especificar sua classe base. Se a classe base permite a automação, a caixa de diálogo Adicionar classe exibe controles usados para especificar se a nova classe deve dar suporte a automação, se ele é o "OLE que pode ser criado" (ou seja, se os objetos da classe podem ser criados em uma solicitação de um cliente COM) e o nome externo para o cliente de COM usar.

O **Adicionar classe** caixa de diálogo, em seguida, cria uma declaração de classe, incluindo as macros apropriadas para o OLE recursos que você especificou. Ele também adiciona o código de esqueleto para implementação da sua classe funções de membro.

O Assistente de aplicativo do MFC simplifica as etapas envolvidas na obtenção de seu aplicativo de servidor de automação o plano. Se você selecionar o **automação** caixa de seleção do **recursos avançados** página de Assistente de aplicativo MFC adiciona ao seu aplicativo `InitInstance` as chamadas necessárias para registrar sua automação de função objetos e executar seu aplicativo como um servidor de automação.

### <a name="what-do-you-want-to-do"></a>O que você deseja fazer

- [Saiba mais sobre os clientes de automação](../mfc/automation-clients.md)

- [Saiba mais sobre a classe CCmdTarget](../mfc/reference/ccmdtarget-class.md)

- [Saiba mais sobre a classe COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md)

## <a name="see-also"></a>Consulte também

[Automação](../mfc/automation.md)<br/>
[Assistente de aplicativo do MFC](../mfc/reference/mfc-application-wizard.md)

