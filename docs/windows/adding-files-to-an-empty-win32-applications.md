---
title: "Adicionando arquivos a aplicativos Win32 vazios | Microsoft Docs"
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
  - "projetos vazios, adicionando arquivos"
  - "projetos [C++], adicionando itens"
  - "projetos em branco"
  - "arquivos [C++], adicionando a projetos"
ms.assetid: 070098e8-0396-49fe-a697-3daa2f1be6de
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando arquivos a aplicativos Win32 vazios
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

### Para adicionar os arquivos para um aplicativo de desktop Windows vazio  
  
1.  Selecione o diretório no **Solution Explorer**.  
  
2.  Clique no nome do diretório, clique em **Add** o menu de atalho e clique **Item existente**.  
  
3.  No **caixa de diálogo Add Existing Item**, navegue até os arquivos que você deseja adicionar ao seu projeto.  
  
4.  Clique em **OK**.  
  
 Para adicionar arquivos que não são fonte, cabeçalho ou arquivos de recursos ao seu projeto, clique com botão direito no nó solução em Solution Explorer e adicione os arquivos ao projeto da mesma maneira. Uma pasta diversos será criada para manter os outros arquivos no seu projeto.  
  
> [!NOTE]
>  Antes de compilar seu projeto, você precisará especificar opções de compilação para esses arquivos para que sejam incluídos corretamente em seu aplicativo terminar. Para obter mais informações, consulte [especificando configurações de projeto com páginas de propriedade](../ide/property-pages-visual-cpp.md) e [Criando um programa em C\/C\+\+](../build/building-c-cpp-programs.md).  
  
## Consulte também  
 [Criando um aplicativo de Desktop do Windows vazio](../windows/creating-an-empty-windows-desktop-application.md)   
 [Deploying Applications](http://msdn.microsoft.com/pt-br/4ff8881d-0daf-47e7-bfe7-774c625031b4)