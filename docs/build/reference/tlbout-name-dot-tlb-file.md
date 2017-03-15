---
title: "/TLBOUT (nomear arquivo .TLB) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.TypeLibraryFile"
  - "/tlbout"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .tlb, renomeando"
  - "Opção de vinculador /TLBOUT"
  - "arquivos tlb, renomeando"
  - "opção de vinculador TLBOUT"
  - "opção de vinculador -TLBOUT"
ms.assetid: 0df6d078-2e48-46c9-a1a5-02674d85dce8
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /TLBOUT (nomear arquivo .TLB)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/TLBOUT:[path\]filename  
```  
  
## Comentários  
 onde:  
  
 *caminho*  
 Um absoluta ou uma especificação de caminho relativo para onde o arquivo de .tlb deve ser criado.  
  
 *filename*  
 Especifica o nome do arquivo de .tlb criado pelo compilador de MIDL.  Nenhuma extensão de arquivo é assumida; especifique *filename.tlb*se você quiser uma extensão de .tlb.  
  
## Comentários  
 A opção \/TLBOUT especifica o nome e extensão do arquivo de .tlb.  
  
 O compilador de MIDL é chamado pelo vinculador Visual C\+\+ ao vincular os projetos que têm o atributo de [módulo](../../windows/module-cpp.md) .  
  
 \/TLBOUT Se não for especificado, o arquivo de .tlb obterá o nome*de arquivo* de [\/IDLOUT](../Topic/-IDLOUT%20\(Name%20MIDL%20Output%20Files\).md).  \/IDLOUT Se não for especificado, o arquivo de .tlb será chamado vc70.tlb.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **IDL Inserida** .  
  
4.  Modifique a propriedade de **Biblioteca de Tipos** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TypeLibraryFile%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)   
 [\/IGNOREIDL \(não processar atributos em MIDL\)](../../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)   
 [\/MIDL \(especificar opções de linha de comando MIDL\)](../../build/reference/midl-specify-midl-command-line-options.md)   
 [Building an Attributed Program](../../windows/building-an-attributed-program.md)