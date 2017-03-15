---
title: "Editando uma interface COM | Microsoft Docs"
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
  - "vc.codewiz.com.editing.interfaces"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interfaces COM, edição"
  - "métodos [C++], adicionando a interfaces COM"
  - "propriedades [C++], adicionando a interfaces COM"
ms.assetid: 6c2909e0-af2d-4a37-bb39-ed372e6129cf
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Editando uma interface COM
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Usando comandos no menu de atalho do modo de exibição de classe, você pode definir novos métodos e propriedades para as interfaces COM em seus projetos Visual C\+\+.  Além disso, na caixa de ferramentas, você pode definir eventos nos controles de ActiveX.  
  
 Para ATL e MFC\-baseada COM classes de objeto, você pode editar a implementação da classe ao mesmo tempo que você edite a interface.  
  
> [!NOTE]
>  Para interfaces que você tenha definido fora da  **Add Class** caixa de diálogo, Visual C\+\+ adiciona os métodos ou propriedades ao arquivo. idl e adicionou stubs para as classes que implementam os métodos, mesmo quando as interfaces são adicionadas manualmente.  
  
 Os três assistentes a seguir o ajudarão a personalizar interfaces existentes.  Eles estão disponíveis no modo de exibição de classe:  
  
|Assistente|Tipo de Projeto|  
|----------------|---------------------|  
|[Adicionar Assistente de propriedade](../ide/names-add-property-wizard.md)|Projetos ATL ou MFC suporte ATL.  A interface à qual você deseja adicionar a propriedade de atalho.<br /><br /> Visual C\+\+ detecta o tipo de projeto e modifica as opções do Assistente para adicionar propriedade de acordo:<br /><br /> -   Para dispinterfaces em projetos criados usando o  [MFC Application Wizard](../Topic/MFC%20Application%20Wizard.md), invocar o Assistente para adicionar propriedade fornece opções específicas ao MFC.<br />-   Para interfaces de controle de ActiveX do MFC, o Assistente para adicionar propriedade fornece uma lista de ações métodos e propriedades que você pode usar conforme fornecido ou personalizar para seu controle.<br />-   Para todas as outras interfaces, os assistentes de propriedade adicionar fornecem opções úteis na maioria das situações.|  
|[Adicionar Assistente de método](../ide/add-method-wizard.md)|Projetos ATL ou MFC suporte ATL.  A interface à qual você deseja adicionar o método de atalho.<br /><br /> Visual C\+\+ detecta o tipo de projeto e modifica as opções do Assistente para Adicionar método adequadamente:<br /><br /> -   Para dispinterfaces em projetos criados usando o  [MFC Application Wizard](../Topic/MFC%20Application%20Wizard.md), chamar o método Add Wizard fornece opções específicas ao MFC.<br />-   Para interfaces de controle de ActiveX do MFC, o Assistente para Adicionar método fornece uma lista de ações métodos e propriedades que você pode usar conforme fornecido ou personalizar para seu controle.<br />-   Para todas as outras interfaces, o  **Adicionar método** assistentes fornecem opções úteis na maioria das situações.|  
  
 Além disso, você pode implementar novas interfaces em seu controle COM clicando com o botão direito na classe do objeto de controle no modo de exibição de classe e clicando em  [Implementar a Interface](../Topic/Implement%20Interface%20Wizard.md).  
  
## Consulte também  
 [Trabalhando com arquivos de recurso](../mfc/working-with-resource-files.md)   
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Tipos de projeto do Visual C\+\+](../ide/visual-cpp-project-types.md)