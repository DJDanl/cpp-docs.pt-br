---
title: "Adicionando uma classe do MFC | Microsoft Docs"
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
  - "vc.codewiz.classes.adding.mfc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes [C++], adicionando MFC"
  - "MFC, adicionando classes"
ms.assetid: 9a96b67f-40bf-43d4-8872-2f8dfc5404f1
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando uma classe do MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para adicionar classes derivadas do Microsoft foundation classes de biblioteca de classes \(MFC\) ao seu projeto, use o comando de **Adicionar Classe** disponível de [Classifica a exibição](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925).  Especifique o nome da nova classe, selecione a classe base, e selecione o ID da caixa de diálogo com associada \(se houver\).  O assistente de código cria um arquivo de cabeçalho e um arquivo de implementação e adicionar ao seu projeto.  
  
> [!NOTE]
>  Você pode adicionar classes de MFC a um aplicativo de ATL COM se você inicialmente [criar o aplicativo com suporte MFC](../../atl/reference/mfc-support-in-atl-projects.md).  Você também pode adicionar classes de MFC para projetos do Win32 que têm o suporte de MFC.  
  
### Para adicionar um MFC classifica ao seu projeto  
  
1.  Em vez da classe, clique com o botão direito do mouse no nome do projeto.  Clique **Adicionar** e clique em **Adicionar Classe** para abrir a caixa de diálogo de [Adicione a classe](../../ide/add-class-dialog-box.md) .  
  
2.  No painel modelos, **Classe do MFC** selecione e pressionar o botão de **Adicionar** .  
  
3.  Define as configurações para a nova classe na caixa de diálogo de [Assistente da classe de MFC](../../mfc/reference/mfc-add-class-wizard.md) .  
  
4.  Clique **Concluir** para fechar o assistente e para exibir a nova classe na exibição da classe.  Você também pode exibir os arquivos criados pelo assistente em **Gerenciador de Soluções**.  
  
## Consulte também  
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Visão geral da classe](../../mfc/class-library-overview.md)