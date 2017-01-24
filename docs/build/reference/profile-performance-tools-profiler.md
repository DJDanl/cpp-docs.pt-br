---
title: "/PROFILE (criador de perfil das ferramentas de desempenho) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.Profile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /PROFILE"
  - "opção de vinculador -PROFILE"
ms.assetid: e676baa1-5063-47a3-a357-ba0d1f0d1699
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /PROFILE (criador de perfil das ferramentas de desempenho)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Produz um arquivo de saída que possa ser usado com o criador de perfis Ferramentas de Desempenho.  
  
## Sintaxe  
  
```  
/PROFILE  
```  
  
## Comentários  
 \/PROFILE indica as seguintes opções do vinculador:  
  
-   [\/OPT:REF](../../build/reference/opt-optimizations.md)  
  
-   \/OPT:NOICF  
  
-   [\/INCREMENTAL:NO](../../build/reference/incremental-link-incrementally.md)  
  
-   [\/FIXED:NO](../../build/reference/fixed-fixed-base-address.md)  
  
 \/PROFILE faz com que o vinculador gerencia uma seção de realocação na imagem do programa.  Uma seção de realocação permite que o profiler torna a imagem de programa para obter dados do perfil.  
  
 **\/PROFILE** só está disponível em versões do enterprise \(desenvolvimento de equipe\).  Para obter mais informações sobre do PREfast, consulte [Análise de código para visão geral do C\/C\+\+](../Topic/Code%20Analysis%20for%20C-C++%20Overview.md).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **Vinculador**.  
  
4.  Selecione a página de propriedades **Avançadas**.  
  
5.  Modifique a propriedade de **Perfil** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.Profile%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)