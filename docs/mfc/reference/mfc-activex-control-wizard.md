---
title: "Assistente de controle ActiveX MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.appwiz.mfc.ctl.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX [C++], MFC"
  - "Assistente de controle ActiveX MFC"
  - "Controles ActiveX MFC [C++], assistentes"
  - "Controles OLE [C++]"
  - "Controles OLE [C++], criando"
ms.assetid: f19d698c-bdc3-4c74-af97-3d6ccb441b75
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente de controle ActiveX MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um controle ActiveX é um tipo específico de [servidor de automação](../../mfc/automation-servers.md); é um componente reutilizável.  O aplicativo que hospeda o controle ActiveX é [cliente de automação](../../mfc/automation-clients.md) do controle.  Se seu objetivo é criar um componente tão reutilizável, use este assistente para criar seu controle.  Consulte [Controles ActiveX MFC](../../mfc/mfc-activex-controls.md) para obter mais informações.  
  
 Como alternativa, você pode criar um aplicativo de MFC do servidor de automação usando [Assistente do aplicativo MFC](../Topic/MFC%20Application%20Wizard.md).  
  
 Um controle ActiveX criado com esse assistente pode ter uma interface do usuário, ou pode ser invisível.  Você pode indicar essa opção na página de [Controle configurações](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) no assistente.  Um controle de timer é um exemplo de um controle ActiveX que você deseja ser invisível.  
  
 Os controles ActiveX podem ter uma interface do usuário complexa.  Alguns controles podem ser encapsuladas como formulários: um único controle que contém muitos campos, cada um controle do windows em seus próprios direitos.  Por exemplo, um objeto de peças de automóvel implementado como um controle ActiveX de MFC pode experimentar a autenticação como a interface do usuário por meio dos quais os usuários podem ler e editar o número de peça, o nome da parte, e outras informações.  Consulte [Controles ActiveX MFC](../../mfc/mfc-activex-controls.md) para obter mais informações.  
  
 Se você precisar criar um contêiner para seus objetos ActiveX, consulte [Crie um contêiner do controle ActiveX](../../mfc/reference/creating-an-mfc-activex-control-container.md).  
  
 O programa do acionador de partida MFC inclui arquivos de origem do C\+\+ \(.cpp\), arquivos de recursos \(.rc\), e um arquivo de projeto \(.vcxproj\).  O código gerado nesses arquivos do acionador de partida é baseado em MFC.  
  
 A seguinte lista de exemplo a seguir mostra tipos de tarefas e aprimoramentos para o controle ActiveX:  
  
-   [Otimizando um controle ActiveX](../../mfc/mfc-activex-controls-optimization.md)  
  
-   [Para adicionar os eventos de estoque a um controle ActiveX](../Topic/MFC%20ActiveX%20Controls:%20Adding%20Stock%20Events%20to%20an%20ActiveX%20Control.md)  
  
-   [Adicionando eventos personalizados](../Topic/MFC%20ActiveX%20Controls:%20Adding%20Custom%20Events.md)  
  
-   [Adicionando os métodos de estoque](../../mfc/mfc-activex-controls-adding-stock-methods.md)  
  
-   [Adicionando métodos personalizados](../../mfc/mfc-activex-controls-adding-custom-methods.md)  
  
-   [Adicionando as propriedades de estoque](../Topic/MFC%20ActiveX%20Controls:%20Adding%20Stock%20Properties.md)  
  
-   [Adicionando propriedades personalizadas](../../mfc/mfc-activex-controls-adding-custom-properties.md)  
  
-   [Controles ActiveX de programação em um contêiner do controle ActiveX](../../mfc/programming-activex-controls-in-a-activex-control-container.md)  
  
## Visão Geral  
 Esta página do assistente descreve as configurações de aplicativo atuais para o projeto de controle ActiveX de MFC você está criando.  Por padrão, o assistente criará um projeto como segue:  
  
-   O projeto padrão não gerencia nenhum licença do tempo de execução ou arquivo de ajuda.  Você pode alterar essas configurações padrão na página de [Configurações de aplicativo](../../mfc/reference/application-settings-mfc-activex-control-wizard.md) .  Somente as seleções feitas nesta página do assistente do controle ActiveX são refletidas na página de **Visão geral** .  
  
-   O projeto inclui uma classe de controle e uma classe de página de propriedades, com base no nome do projeto.  Você pode editar os nomes de seu projeto e nomes de arquivo na página de [Controle nomes](../../mfc/reference/control-names-mfc-activex-control-wizard.md) .  
  
-   O controle é baseado em nenhum controle existente do windows, ativas quando se torna visível, se tem uma interface do usuário, e inclui uma caixa de diálogo de **Sobre** .  Você pode alterar essas configurações padrão na página de [Controle configurações](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) .  
  
## Consulte também  
 [Criando e gerenciando projetos do Visual C\+\+](../../ide/creating-and-managing-visual-cpp-projects.md)   
 [Tipos de projeto do Visual C\+\+](../../ide/visual-cpp-project-types.md)   
 [Conceitos](../../atl/active-template-library-atl-concepts.md)