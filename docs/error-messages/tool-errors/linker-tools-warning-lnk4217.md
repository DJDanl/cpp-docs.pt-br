---
title: "Aviso LNK4217 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4217"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4217"
ms.assetid: 280dc03e-5933-4e8d-bb8c-891fbe788738
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4217 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

símbolo localmente definida “símbolo” importado na função “function”  
  
 [\_\_declspec \(dllimport\)](../../cpp/dllexport-dllimport.md) foi especificado para um símbolo mesmo que o símbolo é definido localmente.  Remova o modificador de `__declspec` para resolver esse aviso.  
  
 `symbol` é o nome de símbolo que é definido dentro da imagem.  `function` é a função que está importando o símbolo.  
  
 Esse aviso não aparecerá quando você compila usando a opção [\/clr](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 LNK4217 também pode ocorrer se você tentar vincular dois módulos, quando por isso você deve criar o segundo módulo com a biblioteca de importação do primeiro módulo.  
  
```  
// LNK4217.cpp  
// compile with: /LD  
#include "windows.h"  
__declspec(dllexport) void func(unsigned short*) {}  
```  
  
 Em seguida, e  
  
```  
// LNK4217b.cpp  
// compile with: /c  
#include "windows.h"  
__declspec(dllexport) void func(unsigned short*) {}  
```  
  
 Tentar vincular esses dois módulos resultará em LNK4217, criar o segundo exemplo com a biblioteca de importação do primeiro exemplo a ser resolvido.