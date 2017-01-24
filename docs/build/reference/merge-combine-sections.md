---
title: "/MERGE (combinar se&#231;&#245;es) | Microsoft Docs"
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
  - "/merge"
  - "VC.Project.VCLinkerTool.MergeSections"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /MERGE"
  - "opção de vinculador MERGE"
  - "opção de vinculador -MERGE"
  - "sections"
  - "sections, combinando"
  - "sections, nomenclatura"
ms.assetid: 10fb20c2-0b3f-4c8d-98a8-f69aedf03d52
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /MERGE (combinar se&#231;&#245;es)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/MERGE:from=to  
```  
  
## Comentários  
 A opção \/MERGE combina a primeira seção \(*de*\) com a segunda seção \(\), nomeando a seção resultante *para*.  Por exemplo, `/merge:.rdata=.text`.  
  
 Se a segunda seção não existir, o LINK renomeia a seção *de* relação do.  
  
 A opção \/MERGE é útil para criar VxDs e substituir os nomes de seção completo gerados.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Avançado** .  
  
4.  Modifique a propriedade de **Mesclar Seções** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MergeSections%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)