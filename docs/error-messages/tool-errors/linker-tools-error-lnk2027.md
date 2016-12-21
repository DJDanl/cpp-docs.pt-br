---
title: "Erro das Ferramentas de Vinculador LNK2027 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK2027"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK2027"
ms.assetid: e2f857a8-8e8a-4697-bbff-12ccb84a35c1
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK2027
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

referência não resolvida “módulo” do módulo  
  
 Um arquivo passado ao vinculador tem uma dependência em um módulo que não é especificado com **\/ASSEMBLYMODULE** ou passado diretamente ao vinculador.  
  
 Para resolver LNK2027, siga um destes procedimentos:  
  
-   Não passar para o vinculador o arquivo que tem a dependência do módulo.  
  
-   Especifique o módulo com **\/ASSEMBLYMODULE**.  
  
-   Se o módulo é um .netmodule seguro, o módulo diretamente ao vinculador.  
  
 Para obter mais informações, consulte [\/ASSEMBLYMODULE \(adicionar um módulo MSIL ao assembly\)](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md) e [Arquivos .netmodule como entrada de vinculador](../Topic/.netmodule%20Files%20as%20Linker%20Input.md).