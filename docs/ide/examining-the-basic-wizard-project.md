---
title: "Examinando o projeto de assistente b&#225;sico | Microsoft Docs"
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
  - "assistentes personalizados, arquivos criados"
  - "assistentes personalizados, projetos de assistente"
ms.assetid: c6423e3c-ddb0-43e0-b8e5-9e3a98a7908c
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Examinando o projeto de assistente b&#225;sico
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Após usar o  [Assistente personalizada](../ide/creating-a-custom-wizard.md) para criar o projeto básico, examine os arquivos que ele criou para você.  
  
1.  Em  **Solution Explorer**, expanda o projeto e examinar  [os arquivos](../ide/files-created-for-your-wizard.md) o assistente criado para o projeto.  
  
2.  Clique duas vezes em Default. js para abrir o projeto  [arquivo de JScript](../ide/jscript-file.md) no editor de código.  Este arquivo contém funções de JScript que criar o projeto quando o usuário clica  **Concluir** no assistente.  Examine as funções e os comentários TODO neste arquivo.  
  
3.  Se o projeto tiver uma interface de usuário, procure na pasta denominada  [Arquivos HTML](../ide/html-files.md) e observe que você tem como. htm muitos arquivos, você, como especificado no  [As configurações do aplicativo](../Topic/Application%20Settings,%20Custom%20Wizard.md) página do assistente personalizado.  Clique duas vezes em Default. htm para abrir a página do projeto principal HTML no  [o designer HTML](../Topic/HTML%20Designer.md).  Você pode exibir o HTML em [Modo de design](../Topic/Design%20View1.md) ou no modo de exibição HTML, como  [marcação HTML](http://msdn.microsoft.com/pt-br/7bb90672-b36a-4cf9-9bbc-677c9b956318).  Alterne para o modo de marcação HTML e examine a marcação HTML.  Clique no  **Modo somente Script** botão \(localizado no canto superior direito da janela de edição de modo de exibição de HTML, ao lado da  **eventos** lista drop\-down\) e examine o JScript no arquivo. htm.  Por padrão, esse arquivo contém as funções de JScript que inicializar e carregar o assistente e fornece o comportamento padrão para o  **IVCWizCtrlUI**  interface.  Consulte o coclass <xref:Microsoft.VisualStudio.VsWizard.VCWizCtl> o objeto para obter mais informações.  
  
4.  Salve e feche o projeto de assistente.  
  
5.  Abra o Visual Studio  **Novo projeto** caixa de diálogo caixa e localizar o ícone do assistente.  Clique duas vezes no ícone para exibir o seu assistente.  Você pode examinar as páginas do assistente básica que o assistente personalizada criado para você.  Observe que a primeira página contém alguns controles HTML de exemplo e o padrão  **Concluir**,  **Cancelar**, e  **Help** botões.  
  
6.  Clique em  **Concluir** para criar um novo projeto com seu assistente.  Por padrão, o assistente cria dois arquivos de texto: Readme. txt e exemplo. txt.  Esses arquivos descrevem o projeto que seu assistente criado.  Este projeto de fechar e reabrir o projeto do assistente.  
  
7.  Leitura  [examinando a mecânica de um assistente](../Topic/Examining%20the%20Mechanics%20of%20a%20Wizard.md) para obter uma compreensão clara de como o ambiente de Visual Studio e o mecanismo de Assistente do Visual C\+\+ criou o projeto que você criou quando você executou o assistente.  
  
 Você está pronto para iniciar  [Personalizando seu assistente personalizado](../ide/customizing-your-wizard.md).  
  
## Consulte também  
 [Assistente Personalizado](../ide/custom-wizard.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Etapas para projetar um assistente](../ide/steps-to-designing-a-wizard.md)   
 [Arquivos criados para o assistente](../ide/files-created-for-your-wizard.md)   
 [Fornecendo ajuda contextual](../ide/providing-context-sensitive-help.md)   
 [Personalizando o assistente](../ide/customizing-your-wizard.md)