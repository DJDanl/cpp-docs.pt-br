---
title: "Criando um aplicativo MFC | Microsoft Docs"
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
  - "aplicativos [MFC]"
  - "Criando aplicativos da MFC [C++]"
  - "Aplicativos MFC"
ms.assetid: b8b8aa08-9c49-404c-8078-b42079ac18f0
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um aplicativo MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um aplicativo do MFC é um aplicativo executável do Windows que é baseado na Microsoft Foundation Class \(MFC\) Library.  A maneira mais fácil de criar um aplicativo MFC é usar o Assistente de Aplicativo MFC.  
  
> [!IMPORTANT]
>  Os projetos MFC não têm suporte nas edições do Visual Studio Express.  
  
 Executáveis MFC geralmente se enquadram em cinco tipos: aplicativos do Windows padrão, caixas de diálogo, aplicativos baseados em formulários, aplicativos do estilo Explorer e aplicativos de estilo de navegador da Web.  Para obter mais informações, consulte:  
  
-   [Usando as classes para escrever aplicativos do Windows](../Topic/Using%20the%20Classes%20to%20Write%20Applications%20for%20Windows.md)  
  
-   [Criando e exibindo caixas de diálogo](../../mfc/creating-and-displaying-dialog-boxes.md)  
  
-   [Criando um aplicativo MFC baseado no Forms](../Topic/Creating%20a%20Forms-Based%20MFC%20Application.md)  
  
-   [Criando um aplicativo MFC do estilo Explorador de Arquivo](../../mfc/reference/creating-a-file-explorer-style-mfc-application.md)  
  
-   [Criando um aplicativo MFC do estilo Navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)  
  
 O Assistente de Aplicativo do MFC gera as classes e os arquivos apropriados para qualquer um desses tipos de aplicativos, dependendo das opções selecionadas no assistente.  
  
### Para criar um aplicativo do MFC usando o Assistente do Aplicativo do MFC  
  
1.  Siga as instruções no tópico da ajuda [Criando um projeto com um assistente de aplicativo Visual C\+\+](../../ide/creating-desktop-projects-by-using-application-wizards.md).  
  
2.  Na caixa de diálogo **Novo Projeto**, selecione **Aplicativo do MFC** no painel Modelos para abrir o assistente.  
  
3.  Defina suas configurações de aplicativo usando o [Assistente para Aplicativo do MFC](../Topic/MFC%20Application%20Wizard.md).  
  
    > [!NOTE]
    >  Ignore esta etapa para manter as configurações padrão do assistente.  
  
4.  Clique em **Concluir** para fechar o assistente e abra o novo projeto no ambiente de desenvolvimento.  
  
 Assim que seu projeto for criado, você poderá exibir os arquivos criados no **Gerenciador de Soluções**.  Para obter mais informações sobre arquivos que o assistente cria para seu projeto, consulte o arquivo gerado pelo projeto ReadMe.txt.  Para obter mais informações sobre os tipos de arquivo, consulte [Tipos de arquivo criados para projetos do Visual C\+\+](../../ide/file-types-created-for-visual-cpp-projects.md).  
  
## Consulte também  
 [Debugging Preparation: Visual C\+\+ Windows Applications](http://msdn.microsoft.com/pt-br/a8bc54de-41a3-464d-9a12-db9bdcbc1ad5)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Páginas de propriedade](../../ide/property-pages-visual-cpp.md)   
 [Deploying Applications](http://msdn.microsoft.com/pt-br/4ff8881d-0daf-47e7-bfe7-774c625031b4)