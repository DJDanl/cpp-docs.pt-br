---
title: "Servidores de automa&#231;&#227;o | Microsoft Docs"
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
  - "Servidores de automação"
  - "componentes COM, Servidores de automação"
  - "mapas de envios, Servidores de automação"
  - "servidores, Automação"
ms.assetid: 523fd155-51ce-4f91-b986-b74bdbdd7d92
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Servidores de automa&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A automação possibilita para que seu aplicativo manipule os objetos implementados em outro aplicativo, ou expõe objetos para que possam ser manipulados.  Um servidor de automação é um aplicativo que expõe objetos programáveis \(chamados objetos de Automação\) para outros aplicativos \( [Clientes de automação](../mfc/automation-clients.md)chamado\).  Os servidores de automação às vezes são chamados de componentes de Automação.  
  
 Expor objetos de automação permite que clientes para automatizar determinados procedimentos diretamente acessando os objetos e funcionalidades que o servidor faz disponível.  Expor os objetos desse modo é benéfica quando os aplicativos fornecem a funcionalidade que é útil para outros aplicativos.  Por exemplo, um tratamento de textos pode expor a funcionalidade de spellchecking de forma que outros programas possam usá\-lo.  A exposição de objetos habilita para fornecedores para melhorar a funcionalidade dos aplicativos usando a funcionalidade pré\-feito de outros aplicativos.  
  
 Esses objetos de automação têm propriedades e métodos como sua interface externo.  As propriedades são denominadas atributos do objeto de automação.  As propriedades são como os membros de dados da classe c. criando  Os métodos são funções que trabalham em objetos de automação.  Os métodos são como as funções de membro públicas da classe c. criando  
  
> [!NOTE]
>  Embora elas sejam como membros de dados C\+\+, não são diretamente acessíveis.  Para fornecer acesso transparente, configure uma variável interno no objeto de automação com um par de obtém ou define as funções de membro para acessá\-los a partir.  
  
 Expõe a funcionalidade do aplicativo por meio de uma interface comum, bem definida, automação torna possível criar aplicativos em uma única linguagem de programação geral como o Microsoft Visual Basic em vez de em várias linguagens de macro, específicos do aplicativo.  
  
##  <a name="_core_support_for_automation_servers"></a> Suporte para servidores de automação  
 Visual C\+\+ e a estrutura de MFC fornecem amplo suporte para servidores de automação.  Tratam muito da sobrecarga envolvida na criação de um servidor de automação, para que você possa se concentre seus esforços sobre a funcionalidade de seu aplicativo.  
  
 O mecanismo principal da estrutura para a automação de suporte é o mapa de distribuição, um conjunto de macros que se expanda em declarações e chama necessário para expor métodos e propriedades de OLE.  Os aspectos comuns de um mapa de distribuição tem a seguinte aparência:  
  
 [!code-cpp[NVC_MFCAutomation#1](../mfc/codesnippet/CPP/automation-servers_1.cpp)]  
  
 Assistência à exibição da janela Propriedades e da classe em mapas de manutenção de distribuição.  Quando você adiciona um novo método ou esta propriedade em uma classe, Visual C\+\+ adiciona `DISP_FUNCTION` ou uma macro correspondente de `DISP_PROPERTY` com os parâmetros que indicam os nomes do nome da classe, os externos e os internos do método ou a propriedade, e tipos de dados.  
  
 A caixa de diálogo de **Adicionar Classe** também simplifica a declaração de classes de automação e o gerenciamento de suas propriedades e operações.  Quando você usa a caixa de diálogo da classe para adicionar adicione uma classe ao seu projeto, você especifica sua classe base.  Se a classe base permite a automação, os controles da caixa de diálogo é exibida da classe adicionar você usa para especificar se a nova classe deve oferecer suporte à automação, se for “creatable OLE” \(isto é, se os objetos da classe podem ser criados em uma solicitação de um cliente COM\), e o nome externo para o cliente da usa.  
  
 A caixa de diálogo de **Adicionar Classe** cria uma declaração de classe, incluindo as macros apropriados para os recursos do que você especificou.  Também adiciona o código do esqueleto para a implementação das funções de membro da classe.  
  
 O assistente de aplicativo MFC simplifica as etapas envolvidas em obter seu aplicativo de servidor de automação fora da terra.  Se você marcar a caixa de seleção de **Automação** da página de **Recursos Avançados** , o assistente de aplicativo MFC adiciona à função de `InitInstance` do seu aplicativo chama necessário registrar os objetos de automação e execute o aplicativo como um servidor de automação.  
  
### O que você deseja fazer?  
  
-   [Saiba sobre clientes de automação](../mfc/automation-clients.md)  
  
-   [Saber mais sobre a classe CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
-   [Saber mais sobre a classe COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md)  
  
## Consulte também  
 [Automação](../mfc/automation.md)   
 [Assistente de aplicativo MFC](../Topic/MFC%20Application%20Wizard.md)