---
title: "/INCLUDE (for&#231;ar refer&#234;ncias de s&#237;mbolo) | Microsoft Docs"
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
  - "/include"
  - "VC.Project.VCLinkerTool.ForceSymbolReferences"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /INCLUDE"
  - "opção de vinculador forçar referências de símbolo"
  - "opção de vinculador INCLUDE"
  - "opção de vinculador -INCLUDE"
  - "força de vinculador de referências de símbolo"
  - "símbolos, adicionar à tabela de símbolos"
ms.assetid: 4a039677-360a-480f-bd0b-448e239b449c
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /INCLUDE (for&#231;ar refer&#234;ncias de s&#237;mbolo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/INCLUDE:symbol  
```  
  
## Comentários  
 onde:  
  
 `symbol`  
 Especifica um símbolo a ser adicionado à tabela de símbolo.  
  
## Comentários  
 A opção \/INCLUDE diz o vinculador para adicionar um símbolo especificado na tabela de símbolo.  
  
 Para especificar várias símbolos, digite uma vírgula \(,\), ponto\-e\-vírgula \(;\), ou um espaço entre os nomes de símbolo.  Na linha de comando, especifique \/INCLUDE:`symbol` uma vez para cada símbolo.  
  
 O vinculador resolve `symbol` adicionando o objeto que contém a definição do símbolo para o programa.  Este recurso é útil para incluir um objeto da biblioteca que não seja vinculado de outra forma ao programa.  
  
 Especificando um símbolo essa opção substitui a remoção desse símbolo por [\/OPT: Referência](../../build/reference/opt-optimizations.md).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Entrada** .  
  
4.  Modifique a propriedade de **Forçar Referências de Símbolo** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ForceSymbolReferences%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)