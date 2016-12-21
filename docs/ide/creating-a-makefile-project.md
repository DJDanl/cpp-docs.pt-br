---
title: "Criando um projeto de makefile | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.appwiz.makefile.project"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "projetos Makefile, criando"
  - "arquivos de projeto [C++], projetos Makefile"
ms.assetid: dd077af3-97a8-48fb-baaa-cf7e07ddef61
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um projeto de makefile
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você tiver um projeto compilado na linha de comando com um makefile, o ambiente de desenvolvimento do Visual Studio não reconhecerá seu projeto.  Para abrir e criar seu projeto usando o [!INCLUDE[vsUltShort](../ide/includes/vsultshort_md.md)], o [!INCLUDE[vsPro](../ide/includes/vspro_md.md)] ou o Visual Studio Express para Windows Desktop, crie primeiro um projeto vazio selecionando o modelo de projeto MakeFile.  Você pode usar esse projeto para compilar seu projeto no ambiente de desenvolvimento do Visual Studio.  
  
 O projeto não mostra arquivos no Gerenciador de Soluções.  O projeto especifica as configurações de compilação, que são refletidas na página de propriedades do projeto.  
  
 O arquivo de saída que você especifica no projeto não tem efeito no nome que o script de compilação gera; ele declara apenas uma intenção.  
  
### Para criar um projeto Makefile  
  
1.  Siga as instruções no tópico da ajuda [Criando um projeto com um assistente de aplicativo do Visual C\+\+](../ide/creating-desktop-projects-by-using-application-wizards.md).  
  
2.  Na caixa de diálogo **Novo Projeto**, selecione **Projeto Makefile** no painel Modelos para abrir o assistente.  
  
3.  Na página [Configurações do Aplicativo](../ide/application-settings-makefile-project-wizard.md), forneça as informações de comando, saída, limpeza e recompilação.  
  
4.  Clique em **Concluir** para fechar o assistente e abrir o projeto recém\-criado no **Gerenciador de Soluções**.  
  
 Você pode ver e editar as propriedades do projeto em sua página de propriedades.  Consulte [Definindo propriedades do projeto do Visual C\+\+](../ide/working-with-project-properties.md) para obter informações sobre a exibição da página de propriedades.  
  
## Consulte também  
 [Assistente de Projeto Makefile](../ide/makefile-project-wizard.md)   
 [Caracteres especiais em um makefile](../build/special-characters-in-a-makefile.md)   
 [Conteúdo de um makefile](../build/contents-of-a-makefile.md)