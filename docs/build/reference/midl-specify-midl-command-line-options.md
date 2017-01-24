---
title: "/MIDL (especificar op&#231;&#245;es de linha de comando MIDL) | Microsoft Docs"
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
  - "/midl"
  - "VC.Project.VCLinkerTool.MidlCommandFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /MIDL"
  - "MIDL"
  - "opção de vinculador MIDL"
  - "opção de vinculador -MIDL"
  - "MIDL, opções de linha de comando"
ms.assetid: 22dc259e-b34c-4ed3-a380-4beb734482c1
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /MIDL (especificar op&#231;&#245;es de linha de comando MIDL)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/MIDL:@file  
```  
  
## Comentários  
 onde:  
  
 `file`  
 O nome do arquivo que contém [Opções de linha de comando de MIDL](http://msdn.microsoft.com/library/windows/desktop/aa366839).  
  
## Comentários  
 Todas as opções para a conversão de um arquivo de IDL a um arquivo de TLB devem ser fornecidas em `file`; As opções de linha de comando de MIDL não podem ser especificadas na linha de comando do vinculador.  \/MIDL Se não for especificado, o compilador de MIDL será invocado apenas com o nome do arquivo de IDL e nenhuma outras opções.  
  
 O arquivo deve conter uma opção de linha de comando de MIDL por linha.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **IDL Inserida** .  
  
4.  Modifique a propriedade de **Comandos de MIDL** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MidlCommandFile%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)   
 [\/IDLOUT \(nomear arquivos de saída MIDL\)](../Topic/-IDLOUT%20\(Name%20MIDL%20Output%20Files\).md)   
 [\/IGNOREIDL \(não processar atributos em MIDL\)](../../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)   
 [\/TLBOUT \(nomear arquivo .TLB\)](../../build/reference/tlbout-name-dot-tlb-file.md)   
 [Building an Attributed Program](../../windows/building-an-attributed-program.md)