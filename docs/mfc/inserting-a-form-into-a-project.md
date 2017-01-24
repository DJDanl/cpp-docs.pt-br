---
title: "Inserindo um formul&#225;rio em um projeto | Microsoft Docs"
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
  - "formulários, adicionando a projetos"
  - "caixa de diálogo Inserir Novo"
  - "inserindo formulários"
ms.assetid: f3bd2998-3ce2-496d-ac5c-57ca70eec7cb
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Inserindo um formul&#225;rio em um projeto
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os formulários fornecem um contêiner conveniente para controles.  Você pode facilmente inserir um formulário MFC\- com base em seu aplicativo enquanto o aplicativo oferece suporte às bibliotecas MFC.  
  
### Para inserir um formulário em seu projeto  
  
1.  Em vez da classe, selecione o projeto ao qual deseja adicionar o formulário, e clique no botão direito do mouse em.  
  
2.  No menu de atalho, clique **Adicionar** e clique em **Adicionar Classe**.  
  
     Se o comando de **New Form** não estiver disponível, seu projeto pode ser baseado na biblioteca ativa \(ATL\) do modelo.  Para adicionar um formulário em um projeto de ATL, você deve [especificar certas configurações](../Topic/Application%20Settings,%20ATL%20Project%20Wizard.md) ao primeiro criar o projeto.  
  
3.  A pasta de **MFC** , clique em **Classe do MFC**.  
  
4.  Usando o assistente da classe de MFC, faça a nova classe derivar de [CFormView](../mfc/reference/cformview-class.md).  
  
 Visual C\+\+ adiciona o formulário para o seu aplicativo, a abertura do no editor da caixa de diálogo para que você possa começar a adicionar controles e trabalhar em seu design total.  
  
 Talvez você queira executar as seguintes etapas adicionais \(não aplicável para aplicativos baseados diálogo\-\):  
  
1.  Substitua a função de membro de `OnUpdate` .  
  
2.  Implementar uma função de membro para mover dados da exibição no documento.  
  
3.  Crie uma função de membro de `OnPrint` .  
  
## Consulte também  
 [Exibições de formulário](../Topic/Form%20Views%20\(MFC\).md)