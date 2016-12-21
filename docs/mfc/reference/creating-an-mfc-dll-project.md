---
title: "Criando um projeto DLL MFC | Microsoft Docs"
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
  - "vc.appwiz.mfcdll.project"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DLLs [C++], criando"
  - "DLLs [C++], MFC"
  - "DLLs MFC [C++], criando projetos"
  - "projetos [C++], criando"
ms.assetid: 05540b93-4781-4a90-aadf-55158313f5b2
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um projeto DLL MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma DLL MFC é um arquivo binário que atue como uma biblioteca compartilhada das funções que podem ser usados simultaneamente por vários aplicativos.  A maneira mais fácil de criar um projeto da DLL MFC é usar o assistente da DLL MFC.  
  
> [!NOTE]
>  A aparência dos recursos no IDE pode depender de sua configurações ou edição ativa, e podem ser diferentes de aquelas descritas na ajuda.  Para alterar as configurações, escolha **Importar e exportar configurações** no menu **Ferramentas**.  Para obter mais informações, consulte [Customizing Development Settings in Visual Studio](http://msdn.microsoft.com/pt-br/22c4debb-4e31-47a8-8f19-16f328d7dcd3).  
  
### Para criar uma DLL MFC projeto usando o assistente da DLL MFC  
  
1.  Siga as instruções no tópico da ajuda [Criando um projeto com um assistente de aplicativo Visual C\+\+](../../ide/creating-desktop-projects-by-using-application-wizards.md).  
  
 **Observação** No **Novo Projeto** a caixa de diálogo, selecione `MFC DLL` ícone no painel modelos para abrir o assistente da DLL MFC.  
  
1.  Defina as configurações de aplicativo usando a página de [configurações de aplicativo](../../mfc/reference/application-settings-mfc-dll-wizard.md) de [Assistente da DLL MFC](../../mfc/reference/mfc-dll-wizard.md).  
  
    > [!NOTE]
    >  Ignore esta etapa para manter as configurações padrão do assistente.  
  
2.  Clique **Concluir** para fechar o assistente e para abrir o novo projeto em **Gerenciador de Soluções**.  
  
 Uma vez que seu projeto é criado, você pode exibir os arquivos criados no Solution Explorer.  Para obter mais informações sobre arquivos que o assistente cria para seu projeto, consulte o arquivo gerado pelo projeto ReadMe.txt.  Para obter mais informações sobre os tipos de arquivo, consulte [Tipos de arquivo criados para projetos do Visual C\+\+](../../ide/file-types-created-for-visual-cpp-projects.md).  
  
## Consulte também  
 [Tipos de projeto do Visual C\+\+](../Topic/Debugging%20Preparation:%20Visual%20C++%20Project%20Types.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Páginas de propriedade](../../ide/property-pages-visual-cpp.md)   
 [Deploying Applications](http://msdn.microsoft.com/pt-br/4ff8881d-0daf-47e7-bfe7-774c625031b4)