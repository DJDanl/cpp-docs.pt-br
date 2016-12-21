---
title: "/IGNOREIDL (n&#227;o processar atributos em MIDL) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.IgnoreEmbeddedIDL"
  - "/ignoreidl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /IGNOREIDL"
  - "opção de vinculador IGNOREIDL"
  - "opção de vinculador -IGNOREIDL"
ms.assetid: 29514098-6a1c-4317-af2f-1dc268972780
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /IGNOREIDL (n&#227;o processar atributos em MIDL)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/IGNOREIDL  
```  
  
## Comentários  
 A opção \/IGNOREIDL especifica que nenhum [Atributos de IDL](../../windows/idl-attributes.md) no código\-fonte não deve ser processado em um arquivo de .idl.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **IDL Inserida** .  
  
4.  Modifique a propriedade de **Ignorar IDL Incorporado** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreEmbeddedIDL%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)   
 [\/IDLOUT \(nomear arquivos de saída MIDL\)](../Topic/-IDLOUT%20\(Name%20MIDL%20Output%20Files\).md)   
 [\/TLBOUT \(nomear arquivo .TLB\)](../../build/reference/tlbout-name-dot-tlb-file.md)   
 [\/MIDL \(especificar opções de linha de comando MIDL\)](../../build/reference/midl-specify-midl-command-line-options.md)   
 [Building an Attributed Program](../../windows/building-an-attributed-program.md)