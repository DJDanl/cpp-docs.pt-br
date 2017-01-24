---
title: "Assistente de aplicativo Win32 | Microsoft Docs"
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
  - "vc.appwiz.win32.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de aplicativo Win32"
  - "Assistente de Projeto Win32"
ms.assetid: 5d7b3a5e-8461-479a-969a-67b7883725b9
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente de aplicativo Win32
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O Visual C\+\+ Win32 Application Wizard permite que você crie qualquer um dos quatro tipos de projetos \(listados no título na tabela abaixo\). Em cada caso, você pode especificar opções adicionais que são apropriadas para o tipo de projeto que é aberto. A tabela a seguir indica quais opções estão disponíveis para cada tipo de aplicativo.  
  
|Tipo de suporte|Aplicativo de console|Aplicativo executável \(Windows\)|Biblioteca de vínculo dinâmico|Biblioteca estática|  
|---------------------|---------------------------|---------------------------------------|------------------------------------|-------------------------|  
|**Projeto vazio**|Sim|Sim|Sim|Não|  
|**Exportar símbolos**|Não|Não|Sim|Não|  
|**Cabeçalho pré\-compilado**|Não|Não|Não|Sim|  
|**Suporte ATL**|Sim|Não|Não|Não|  
|**Suporte MFC**|Sim|Não|Não|Sim|  
  
## Visão Geral  
 Esta página do assistente descreve as configurações do projeto atual para o aplicativo do Win32 que você está criando. Por padrão, as seguintes opções estão definidas:  
  
-   O projeto é um aplicativo do Windows.  
  
-   O projeto não está vazio.  
  
-   O projeto não contém símbolos nenhuma exportação.  
  
-   O projeto não usa um arquivo de cabeçalho pré\-compilado \(essa opção está disponível para projetos de biblioteca estática somente\).  
  
-   O projeto inclui suporte para MFC nem ATL.  
  
 Para alterar esses padrões, clique o [configurações do aplicativo](../Topic/Application%20Settings,%20Win%2032%20Project%20Wizard.md) guia na coluna à esquerda do assistente e faça as alterações desejadas.  
  
 Depois de criar um aplicativo de área de trabalho do Windows, você pode adicionar classes genéricas do C\+\+ usando o [genérico](../ide/generic-cpp-class-wizard.md) Assistente de código. Você pode adicionar outros itens, como arquivos HTML, arquivos de cabeçalho, recursos ou arquivos de texto.  
  
> [!NOTE]
>  Não é possível adicionar classes ATL, e você pode adicionar classes MFC apenas para esses tipos de aplicativo de desktop do Windows que oferecem suporte a MFC \(consulte a tabela anterior\).  
  
 Você pode exibir os arquivos que o assistente cria para seu projeto no **Solution Explorer**. Para obter mais informações sobre os arquivos que o assistente cria para seu projeto, consulte o arquivo de projeto gerado Readme. txt. Para obter mais informações sobre os tipos de arquivo, [tipos de arquivo criados para projetos do Visual C\+\+](../ide/file-types-created-for-visual-cpp-projects.md).  
  
## Consulte também  
 [Criando um aplicativo de Desktop do Windows vazio](../windows/creating-an-empty-windows-desktop-application.md)   
 [Tipos de projeto do Visual C\+\+](../ide/visual-cpp-project-types.md)