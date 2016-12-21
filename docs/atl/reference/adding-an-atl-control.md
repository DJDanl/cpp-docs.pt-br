---
title: "Adicionando um controle de ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Projetos de ATL, adicionando controles"
  - "controles [ATL], adicionando a projetos"
ms.assetid: 10223e7e-fdb7-4163-80c6-44aeafa8e6ce
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando um controle de ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use o assistente para adicionar um objeto de interface do usuário a um projeto que suporta interface para todos os possíveis contêiner.  Para suportar essas interfaces, o projeto deve ter sido criado como um aplicativo de ATL ou como um aplicativo MFC que contém o suporte de ATL.  Você pode usar [Assistente de projeto de ATL](../Topic/ATL%20Project%20Wizard.md) para criar um aplicativo de ATL, ou [adicionar um objeto de ATL ao seu aplicativo MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) implementar o suporte de ATL para um aplicativo MFC.  
  
### Para adicionar um controle de ATL ao seu projeto  
  
1.  Em **Gerenciador de Soluções** ou em [Modo de Exibição de Classe](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique com o botão direito do mouse no nome do projeto ao qual você deseja adicionar o objeto simples de ATL.  
  
2.  Clique **Adicionar** do menu de atalho, clique em **Adicionar Classe**.  
  
3.  Em a caixa de diálogo de [Adicionar Classe](../../ide/add-class-dialog-box.md) , no painel de modelos, clique em **Controle do ATL**, e clique em **Adicionar** para exibir [Assistente de controle de ATL](../../atl/reference/atl-control-wizard.md).  
  
 Usando **Assistente de controle de ATL**, você pode criar um dos três tipos de controles:  
  
-   Um controle padrão  
  
-   Um controle composto  
  
-   Um controle DHTML  
  
 Além de isso, você pode reduzir o tamanho do controle e remover as interfaces que não são usadas pela maioria de contêiner **controle mínimo  \*\*\*** selecionando na página de **Opções** do assistente.  
  
## Consulte também  
 [Adicionando funcionalidade para o controle composto](../../atl/adding-functionality-to-the-composite-control.md)   
 [Fundamentos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [ATLFire Sample](http://msdn.microsoft.com/pt-br/5b2649f1-f45b-4cfb-9c4b-4d9459c26b09)