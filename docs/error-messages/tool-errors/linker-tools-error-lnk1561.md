---
title: "Erro das Ferramentas de Vinculador LNK1561 | Microsoft Docs"
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
  - "LNK1561"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1561"
ms.assetid: cb0b709b-7c9c-4496-8a4e-9e1e4aefe447
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1561
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o ponto de entrada deve ser definido  
  
 O vinculador não encontrou um ponto de entrada.  Você pode ter planejado como vincular uma DLL, nesse caso você vincular com a opção de [\/DLL](../../build/reference/dll-build-a-dll.md) .  Você também pode ter esquecido especificar o nome do ponto de entrada; link com a opção de [\/ENTRY](../../build/reference/entry-entry-point-symbol.md) .  
  
 Se não, você deve incluir um main, um wmain, um WinMain, ou uma função de wMain em seu código.  
  
 Se você estiver usando [LIB](../../build/reference/lib-reference.md) e pretende criar um nome, um motivo para esse erro é que você forneceu um arquivo .def.  Nesse caso, remova o arquivo .def de compilação.  
  
 O seguinte exemplo gera LNK1561:  
  
```  
// LNK1561.cpp  
// LNK1561 expected  
int i;  
// add a main function to resolve this error  
```