---
title: "Especificar configura&#231;&#245;es do projeto, Assistente para Criar Novo Projeto de Arquivos de C&#243;digo Existentes | Microsoft Docs"
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
  - "vc.appwiz.importwiz.appsettings"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente para Criar Novo Projeto de Arquivos de Código Existentes, configurações de projeto"
ms.assetid: 9b8860c9-d35f-4f18-9565-2934d3d7f569
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especificar configura&#231;&#245;es do projeto, Assistente para Criar Novo Projeto de Arquivos de C&#243;digo Existentes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use esta página do Assistente para criar novo projeto de arquivos de código existentes para especificar:  
  
-   O ambiente de criação para o novo projeto  
  
-   Criar configurações para coincidir com um tipo específico de um novo projeto para gerar  
  
## Lista de Tarefas  
 [Como criar um projeto do C\+\+ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)  
  
## Lista UIElement  
 **Usar Visual Studio**  
 Especifica o uso de ferramentas de construção que estão incluídas em Visual Studio para a criação de novo projeto.  Esta opção está selecionada por padrão.  
  
 **Tipo de projeto**  
 Especifica o tipo de projeto que o assistente irá gerar.  
  
 **Projeto de aplicativo do Windows**  
 Indica que o assistente irá gerar um projeto para um aplicativo executável do Windows.  Essa opção está disponível a partir do  **Tipo de projeto** caixa de listagem drop\-down.  
  
 **Projeto de aplicativo de console**  
 Indica que o assistente irá gerar um projeto para um aplicativo de console.  Essa opção está disponível a partir do  **Tipo de projeto** caixa de listagem drop\-down.  
  
 **Projeto de biblioteca de vínculos dinâmicos \(DLL\)**  
 Indica que o assistente irá gerar um projeto para um aplicativo de biblioteca de vínculo dinâmico vazio.  Essa opção está disponível a partir do  **Tipo de projeto** caixa de listagem drop\-down.  
  
 **Projeto de biblioteca estática \(LIB\)**  
 Indica que o assistente irá gerar um projeto para um aplicativo de biblioteca estática.  Essa opção está disponível a partir do  **Tipo de projeto** caixa de listagem drop\-down.  
  
 **Adicionar suporte para ATL**  
 Adiciona o suporte ATL ao novo projeto.  
  
 **Adicionar suporte para MFC**  
 Adiciona o suporte do MFC para o novo projeto.  
  
 **Adicionar suporte a Common Language Runtime**  
 Adiciona suporte para o novo projeto de programação do CLR.  
  
 **Common Language Runtime**  
 Especifica o novo projeto para ser compatível com recursos de CLR.  
  
 **Common Language Runtime \(sintaxe antiga\)**  
 Especifica o novo projeto para ser compatível com Managed Extensions for C\+\+ de sintaxe, o que é a sintaxe de programação CLR antes para o Visual C\+\+ 2005.  
  
 **Use o sistema de compilação externo**  
 Especifica o uso de ferramentas de construção que não estão incluídas no Visual Studio para a criação de novo projeto.  Quando essa opção é selecionada, você pode especificar as linhas de comando de compilação na  **Especificar definições de configuração de depuração** e  **Especificar configurações de versão** páginas.  
  
> [!NOTE]
>  Quando o  **Usar sistema de compilação externo** opção estiver marcada, o IDE não cria o novo projeto, assim, a\/D, I, \/FI, \/AI ou \/FU opções não são necessárias para compilação.  No entanto, essas opções devem estar definidas corretamente para que IntelliSense funcionar corretamente.  
  
## Consulte também  
 [Especificar definições de configuração da depuração, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-debug-configuration-settings.md)   
 [Especificar definições de configuração da versão, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-release-configuration.md)