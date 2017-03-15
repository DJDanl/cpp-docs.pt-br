---
title: "Building an Attributed Program | Microsoft Docs"
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
  - "tlb files"
  - "MIDL"
  - "MIDL, linker output"
  - "IDL files"
  - "tlb files, building attributed programs"
  - ".tlb files, building attributed programs"
  - "IDL files, building"
  - "attributes [C++], building type libraries and .idl files"
  - ".tlb files"
  - ".idl files, building"
  - "type libraries, linker options for building"
ms.assetid: 04997b5f-bf2c-46ec-b868-c4adebbef5f4
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Building an Attributed Program
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Depois de colocar os atributos de Visual C\+\+ em seu código\-fonte, convém o compilador do Visual C\+\+ para produzir um arquivo de biblioteca e. idl do tipo para você.  O vinculador seguinte opções ajudam você cria arquivos. tlb e. idl:  
  
-   [\/ IDLOUT](../Topic/-IDLOUT%20\(Name%20MIDL%20Output%20Files\).md)  
  
-   [\/ \/IGNOREIDL](../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)  
  
-   [\/ MIDL](../build/reference/midl-specify-midl-command-line-options.md)  
  
-   [\/ TLBOUT](../build/reference/tlbout-name-dot-tlb-file.md)  
  
 Alguns projetos contêm vários arquivos. idl independentes.  Eles são usados para produzir dois ou mais arquivos. tlb e opcionalmente ligá\-los no bloco de recurso.  Atualmente, esse cenário não é suportado no Visual C\+\+.  
  
 Além disso, o vinculador do Visual C\+\+ saída de todas as informações de atributo relacionado a IDL para um único arquivo MIDL.  Não haverá nenhuma maneira de gerar duas bibliotecas de tipos a partir de um único projeto.  
  
## Consulte também  
 [Concepts](../windows/attributed-programming-concepts.md)