---
title: "Aviso LNK4086 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4086"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4086"
ms.assetid: ea1eecbb-ba2c-41bb-9a4f-fa0808a4b92d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4086 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o entrypoint “function” não é \_\_stdcall com “bytes do número de argumentos;” a imagem não pode executar  
  
 O ponto de entrada para uma DLL deve ser `__stdcall`.  Recompilar a função com a opção de [\/Gz](../../build/reference/gd-gr-gv-gz-calling-convention.md) ou especificar `__stdcall` ou WINAPI quando você define a função.