---
title: "/DYNAMICBASE (usar aleatoriza&#231;&#227;o do layout de espa&#231;o do endere&#231;o) | Microsoft Docs"
ms.custom: ""
ms.date: "12/10/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCLinkerTool.RandomizedBaseAddress"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /DYNAMICBASE"
  - "opção de vinculador DYNAMICBASE"
  - "opção de vinculador -DYNAMICBASE"
ms.assetid: 6c0ced8e-fe9c-4b63-b956-eb8a55fbceb2
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /DYNAMICBASE (usar aleatoriza&#231;&#227;o do layout de espa&#231;o do endere&#231;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica se deve produzir uma imagem executável que pode ser rebased aleatoriamente no tempo de carregamento usando o recurso \(ASLR\) de randomization de layout do espaço de endereço de [!INCLUDE[windowsver](../Token/windowsver_md.md)].  
  
## Sintaxe  
  
```  
/DYNAMICBASE[:NO]  
```  
  
## Comentários  
 Por padrão, \/DYNAMICBASE está ativado.  
  
 Esta opção altera o cabeçalho de um executável para indicar se o aplicativo deve ser rebased aleatoriamente no tempo de carregamento.  
  
 O randomization de layout do espaço de endereço tem suporte em [!INCLUDE[windowsver](../Token/windowsver_md.md)].  
  
### Para definir essa opção de vinculador no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **Vinculador**.  
  
4.  Selecione a página de propriedades **Avançadas**.  
  
5.  Modifique a propriedade de **Endereço Base Aleatório** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.RandomizedBaseAddress%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)