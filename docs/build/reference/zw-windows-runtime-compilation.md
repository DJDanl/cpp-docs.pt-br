---
title: "/ZW (Compila&#231;&#227;o de Tempo de Execu&#231;&#227;o do Windows) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.CompileAsWinRT"
  - "/zw"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "/ZW"
  - "Opção de compilador /ZW"
  - "Opção de compilador de Tempo de Execução do Windows"
  - "-ZW"
  - "opção do compilador -ZW"
ms.assetid: 0fe362b0-9526-498b-96e0-00d7a965a248
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /ZW (Compila&#231;&#227;o de Tempo de Execu&#231;&#227;o do Windows)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Compila o código\-fonte para permitir o uso de [!INCLUDE[cppwrt](../../build/reference/includes/cppwrt_md.md)] \([!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)]\) na criação de aplicativos da [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  
  
 Ao usar **\/ZW** para compilar, sempre especifique **\/EHsc**.  
  
## Sintaxe  
  
```cpp  
/ZW /EHsc /ZW:nostdlib /EHsc  
```  
  
## Arguments  
 nostdlib  
 Indica que Platform.winmd, Windows.Foundation.winmd e outros arquivos padrão de metadados do Windows \(.winmd\) não são incluídos automaticamente na compilação.  Em vez disso, você deve usar a opção do compilador [\/FU \(Name Forced \#using File\)](../../build/reference/fu-name-forced-hash-using-file.md) para especificar arquivos de metadados do Windows.  
  
## Comentários  
 Quando você especifica a opção **\/ZW**, o compilador permite usar estes recursos:  
  
-   Os arquivos de metadados, namespaces, tipos de dados e funções que o aplicativo requer para executar no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
-   Contagem automática das referências dos objetos do [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)] e descarte automático de objetos quando a contagem das referências for zero.  
  
 Como o vinculador incremental não tem suporte para metadados do Windows incluídos em arquivos .obj usando a opção , a opção **\/Gm** é incompatível com **\/ZW**.  
  
 Para obter mais informações, consulte [Referência da linguagem Visual C\+\+](../Topic/Visual%20C++%20Language%20Reference%20\(C++-CX\).md).  
  
## Requisitos  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)