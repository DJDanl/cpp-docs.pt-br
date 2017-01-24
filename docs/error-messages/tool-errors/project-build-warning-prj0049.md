---
title: "Aviso PRJ0049 (compila&#231;&#227;o de projeto) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0049"
ms.assetid: 8b38afa1-e080-4efd-ae89-776cfd044413
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso PRJ0049 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A referência de destino '\<referenciada\>' requer o .NET \<Framework MinFrameworkVersion\> e não executará na estrutura de destino do projeto  
  
 Os aplicativos criados usando [!INCLUDE[vs_orcas_long](../../atl/reference/includes/vs_orcas_long_md.md)] podem especificar que a versão de [!INCLUDE[dnprdnshort](../Token/dnprdnshort_md.md)] ele deve ter como destino.  Se você adicionar uma referência a um assembly projeto do ou do que depende de uma versão de [!INCLUDE[dnprdnshort](../Token/dnprdnshort_md.md)] que é posterior à versão de destino, você obterá esse aviso em tempo de compilação.  
  
### Para corrigir esse aviso  
  
1.  Escolha uma das seguintes opções:  
  
    -   Alterar a estrutura de destino na caixa de diálogo de **Páginas de Propriedades** de projeto de maneira que seja posterior do que ou igual à versão mínima da estrutura de todos os assemblies referenciados e projetos.  Para obter mais informações, consulte [Adicionando referências](../../ide/adding-references-in-visual-cpp-projects.md).  
  
    -   Remover a referência ao assembly ou projeto que tem uma versão mínima da estrutura que é posterior à estrutura de destino.  Esses itens serão marcados com um ícone de aviso em **Páginas de Propriedades**do projeto.  
  
## Consulte também  
 [Erros e avisos de compilação do projeto \(PRJxxxx\)](../../error-messages/tool-errors/project-build-errors-and-warnings-prjxxxx.md)