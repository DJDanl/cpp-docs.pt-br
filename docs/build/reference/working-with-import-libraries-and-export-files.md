---
title: "Trabalhando com bibliotecas de importa&#231;&#227;o e arquivos de exporta&#231;&#227;o | Microsoft Docs"
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
  - "exportar arquivos"
  - "importar bibliotecas"
  - "importar bibliotecas, criando"
  - "LIB [C++], Opção /DEF"
  - "LIB [C++], importar bibliotecas e exportar arquivos"
ms.assetid: d8175596-9773-4c2f-959d-b05b065a5161
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Trabalhando com bibliotecas de importa&#231;&#227;o e arquivos de exporta&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode usar o LIB com a opção \/DEF criar uma biblioteca de importação e um arquivo de exportação.  O LINK usa o arquivo de exportação para criar um programa que contém a exportações \(normalmente \(DLL\) uma biblioteca de vínculo dinâmico\), e usa a biblioteca de importação para referências de resolução 2 essas seguinte exporta em outros programas.  
  
 Observe que se você criar sua biblioteca de importação em uma etapa preliminar, antes de criar seu .dll, você deve transmitir o mesmo conjunto de arquivos de objeto ao criar o .dll, como é passada para criar a biblioteca de importação.  
  
 Na maioria das situações, não é necessário usar o LIB para criar sua biblioteca de importação.  Quando você vincula um programa \(um arquivo executável ou DLL\) que contém a exportações, o LINK cria automaticamente uma biblioteca de importação que descreve as exportações.  Posteriormente, quando você vincula um programa que faz referência a essas exportações, especifique a biblioteca de importação.  
  
 No entanto, quando uma DLL exportar para um programa que também importar, se direta ou indiretamente, você deve usar o LIB para criar uma das bibliotecas de importação.  Quando o LIB cria uma biblioteca de importação, o também cria um arquivo de exportação.  Você deve usar o arquivo de exportação ao vincular um da DLL.  
  
## Consulte também  
 [Referência LIB](../../build/reference/lib-reference.md)