---
title: "Adicionando um objeto simples de ATL | Microsoft Docs"
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
  - "vc.codewiz.classes.adding.atl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Projetos de ATL, adicionando objetos"
  - "ATL, objetos simples"
  - "objetos [ATL]"
ms.assetid: 9c57d2ef-0447-4c84-8982-3304b8e49847
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando um objeto simples de ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para adicionar um objeto de ATL ativo \(biblioteca de modelo\) ao seu projeto, seu projeto deve ter sido criado como um aplicativo de ATL ou como um aplicativo MFC que contém o suporte de ATL.  Você pode usar [Assistente de projeto de ATL](../Topic/ATL%20Project%20Wizard.md) para criar um aplicativo de ATL, ou [adicionar um objeto de ATL ao seu aplicativo MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) implementar o suporte de ATL para um aplicativo MFC.  
  
 Você pode definir as interfaces COM para seu novo objeto de ATL quando você o cria primeiro, ou adicioná\-los posteriormente usando o comando de [Interface de implementam](../Topic/Implement%20Interface%20Wizard.md) do menu de atalho do modo da classe.  
  
### Para adicionar um objeto simples de ATL ao seu projeto COM ATL  
  
1.  Em **Gerenciador de Soluções** ou em [Modo de Exibição de Classe](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique com o botão direito do mouse no nome do projeto ao qual você deseja adicionar o objeto simples de ATL.  
  
2.  Em o menu de atalho, clique **Adicionar**, clique em **Adicionar Classe**.  
  
3.  Em a caixa de diálogo de [Adicionar Classe](../../ide/add-class-dialog-box.md) , no painel de modelos, clique em **Objeto Simples do ATL**, e clique em **Abrir** para exibir [Assistente simples de objeto de ATL](../../atl/reference/atl-simple-object-wizard.md).  
  
4.  Opções adicionais definidas para seu projeto na página de [Opções](../../atl/reference/options-atl-simple-object-wizard.md) do assistente simples de objeto de ATL.  
  
5.  Clique **Concluir** para adicionar o objeto ao seu projeto.  
  
## Consulte também  
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Adicionar uma nova interface em um projeto ATL](../Topic/Adding%20a%20New%20Interface%20in%20an%20ATL%20Project.md)   
 [Adicionando pontos de conexão a um objeto](../../atl/adding-connection-points-to-an-object.md)   
 [Adicionando um método](../../ide/adding-a-method-visual-cpp.md)   
 [MFC Class](../../mfc/reference/adding-an-mfc-class.md)   
 [Adicionando uma classe do C\+\+ genérica](../../ide/adding-a-generic-cpp-class.md)