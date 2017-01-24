---
title: "Adicionando objetos e controles a um projeto ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "vc.appwiz.ATL.controls"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de Controle ATL"
  - "projetos ATL, adicionando controles"
  - "projetos ATL, adicionando objetos"
  - "controles [ATL], adicionando a projetos"
  - "objetos [C++], adicionando a projetos ATL"
  - "assistentes [C++], projetos ATL"
ms.assetid: c0adcbd0-07fe-4c55-a8fd-8c2c65ecdaad
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando objetos e controles a um projeto ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode usar um dos assistentes de código de ATL para adicionar um objeto ou um controle para os projetos de ATL\- ou MFC\- base.  Para cada objeto COM ou controle adicionam, o assistente gera arquivos de .cpp e de .h, bem como um arquivo de .rgs para suporte a escrita com base do Registro.  Os seguintes assistentes de código de ATL estão disponíveis no Visual Studio:  
  
||||  
|-|-|-|  
|[objeto simples de ATL](../../atl/reference/atl-simple-object-wizard.md)|[caixa de diálogo de ATL](../../atl/reference/atl-dialog-wizard.md)|[Controle ATL](../../atl/reference/atl-control-wizard.md)|  
|[página de propriedades de ATL](../../atl/reference/atl-property-page-wizard.md)|[Componente da página de ATL Active Server](../../atl/reference/atl-active-server-page-component-wizard.md)|[Consumidor de ATL o OLE DB](../../atl/reference/atl-ole-db-consumer-wizard.md)|  
|[Adicionar suporte de para o ATL MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md)|[Assistente do componente de ATL COM\+ 1,0](../../atl/reference/atl-com-plus-1-0-component-wizard.md)|[Provedor do OLE DB de ATL](../../atl/reference/atl-ole-db-provider-wizard.md)|  
  
> [!NOTE]
>  Antes de adicionar um objeto de ATL ao seu projeto, você deve examinar os detalhes e os requisitos do objeto em seus tópicos da Ajuda relacionados.  
  
### Para adicionar um objeto ou um controle que usa o controle ATL o assistente  
  
1.  Em o solution Explorer, clique com o botão direito do mouse no nó de projeto e clique **Adicionar** do menu de atalho.  Clique **Adicionar Classe**.  
  
     a caixa de diálogo de [Adicionar Classe](../../ide/add-class-dialog-box.md) aparece.  
  
2.  Com a pasta de ATL selecionada no painel de categorias, selecione um objeto inserção do painel de modelos.  Clique em **Abrir**.  O assistente de código para o objeto selecionado aparece.  
  
    > [!NOTE]
    >  Se você deseja adicionar um objeto de ATL a um projeto MFC, você deve adicionar suporte de ATL ao projeto existente.  Você pode fazer isso seguindo as instruções em [Adicionando o suporte de ATL ao seu projeto MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md).  
  
     Como alternativa, se você tentar adicionar um objeto de ATL ao seu projeto MFC sem anteriormente adicionar suporte de ATL, o Visual Studio solicita que você especifique se você deseja que o suporte de ATL adicionado ao seu projeto.  Clique **Sim** para adicionar suporte de ATL ao projeto e para abrir o assistente de ATL selecionado.  
  
## Consulte também  
 [Assistente de Projeto ATL](../Topic/ATL%20Project%20Wizard.md)   
 [Tipos de projeto do Visual C\+\+](../../ide/visual-cpp-project-types.md)   
 [Criando projetos para desktop com Assistentes de Aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Fundamentos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [Programando com código de tempo de execução ATL e C](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Configurações padrão do projeto ATL](../../atl/reference/default-atl-project-configurations.md)