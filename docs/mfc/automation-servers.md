---
title: "Servidores de automação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Automation servers
- COM components, Automation servers
- dispatch maps [MFC], Automation servers
- servers, Automation
ms.assetid: 523fd155-51ce-4f91-b986-b74bdbdd7d92
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a33cf8113825804ac831b518e371c4150f2620ad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="automation-servers"></a>Servidores de automação
Automação torna possível para o seu aplicativo para manipular objetos implementados em outro aplicativo ou para expor os objetos para que eles podem ser manipulados. Um servidor de automação é um aplicativo que expõe objetos programáveis (chamados de objetos de automação) para outros aplicativos (chamado [clientes de automação](../mfc/automation-clients.md)). Servidores de automação são chamados de componentes de automação.  
  
 Expondo objetos de automação permite que os clientes automatizar certos procedimentos acessando diretamente os objetos e funcionalidade de servidor torna-se disponível. Expondo objetos dessa maneira é benéfico quando os aplicativos fornecem funcionalidade que é útil para outros aplicativos. Por exemplo, um processador de texto pode expor sua funcionalidade de verificação ortográfica para que outros programas podem usá-lo. Exposição de objetos, portanto, permite que fornecedores melhorar a funcionalidade de seus aplicativos usando a funcionalidade pronta de outros aplicativos.  
  
 Esses objetos de automação com propriedades e métodos, como a interface externa. Propriedades são chamadas de atributos de objeto de automação. As propriedades são como os membros de dados de uma classe do C++. Os métodos são funções que funcionam em objetos de automação. Métodos são como as funções de membro público de uma classe do C++.  
  
> [!NOTE]
>  Embora as propriedades são como os membros de dados C++, não são diretamente acessíveis. Para fornecer acesso transparente, configure uma variável interna do objeto de automação com um par de funções de membro de get/set para acessá-los.  
  
 Expondo a funcionalidade do aplicativo por meio de uma interface comum e bem definida, automação, é possível criar aplicativos em um único geral linguagem de programação como o Microsoft Visual Basic, em vez de macro diferentes, específicos do aplicativo Idiomas.  
  
##  <a name="_core_support_for_automation_servers"></a>Suporte para servidores de automação  
 Visual C++ e a estrutura MFC fornecem amplo suporte para servidores de automação. Tratam grande parte da sobrecarga envolvida na criação de um servidor de automação, para que você possa concentrar seus esforços na funcionalidade de seu aplicativo.  
  
 Mecanismo de principal do framework para oferecer suporte a automação é o mapa de expedição, um conjunto de macros que expande as declarações e chamadas necessárias expor métodos e propriedades para OLE. Um mapa de expedição típico tem esta aparência:  
  
 [!code-cpp[NVC_MFCAutomation#1](../mfc/codesnippet/cpp/automation-servers_1.cpp)]  
  
 A janela Propriedades e a exibição de classe auxiliar na manutenção de mapas de expedição. Quando você adiciona um novo método ou propriedade a uma classe, o Visual C++ adiciona correspondente `DISP_FUNCTION` ou `DISP_PROPERTY` macro com parâmetros que indica o nome de classe, os nomes internos e externos dos método ou propriedade e tipos de dados.  
  
 O **Adicionar classe** caixa de diálogo também simplifica a declaração de classes de automação e gerenciamento de suas propriedades e operações. Quando você usar a caixa de diálogo Adicionar classe para adicionar uma classe ao seu projeto, você pode especificar sua classe base. Se a classe base permite a automação, a caixa de diálogo Adicionar classe exibe controles usados para especificar se a nova classe deve dar suporte a automação, se ele é "OLE instanciável" (ou seja, se os objetos da classe podem ser criados em uma solicitação de um cliente COM) e o nome externo para o cliente COM a ser usado.  
  
 O **Adicionar classe** caixa de diálogo, em seguida, cria uma declaração de classe, incluindo as macros apropriadas para o OLE recursos que você especificou. Ele também adiciona o código esqueleto para implementação de funções de membro da classe.  
  
 O Assistente de aplicativo MFC simplifica as etapas envolvidas na obtenção de seu aplicativo de servidor de automação o plano. Se você selecionar o **automação** caixa de seleção de **recursos avançados** página, o Assistente de aplicativo MFC adiciona ao seu aplicativo `InitInstance` as necessária para registrar a automação de chamadas de função objetos e executar o aplicativo como um servidor de automação.  
  
### <a name="what-do-you-want-to-do"></a>O que você deseja fazer  
  
-   [Saiba mais sobre os clientes de automação](../mfc/automation-clients.md)  
  
-   [Saiba mais sobre a classe CCmdTarget](../mfc/reference/ccmdtarget-class.md)  
  
-   [Saiba mais sobre a classe COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md)  
  
## <a name="see-also"></a>Consulte também  
 [Automação](../mfc/automation.md)   
 [Assistente de aplicativo do MFC](../mfc/reference/mfc-application-wizard.md)

