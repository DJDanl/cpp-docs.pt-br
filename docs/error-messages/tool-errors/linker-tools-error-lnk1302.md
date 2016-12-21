---
title: "Erro das Ferramentas de Vinculador LNK1302 | Microsoft Docs"
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
  - "LNK1302"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1302"
ms.assetid: aea3c753-c2c4-4249-bbc3-f2d4f0164b5e
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1302
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

somente suporte que vincula .netmodules segura; não é possível ler o arquivo de vínculo .netmodule  
  
 Um .netmodule \(compilado com **\/LN**\) foi passado ao vinculador em uma tentativa de usuário de invocar vincular de MSIL.  O módulo criando c é válida para MSIL que vincula se for compilado com **\/clr:safe**.  
  
 Para corrigir esse erro, compilar com **\/clr:safe** para habilitar MSIL que vincula, ou passe o arquivo de **\/clr** ou de **\/clr:pure** .obj ao vinculador em vez do módulo.  
  
 Para obter mais informações, consulte  
  
-   [\/LN \(criar módulo MSIL\)](../../build/reference/ln-create-msil-module.md)  
  
-   [Arquivos .netmodule como entrada de vinculador](../Topic/.netmodule%20Files%20as%20Linker%20Input.md)