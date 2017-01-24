---
title: "Erro do Compilador C3862 | Microsoft Docs"
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
  - "C3862"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3862"
ms.assetid: ba547366-4189-4077-8c00-ab45e08a9533
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3862
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: não pode criar uma função não gerenciado com \/clr:pure ou \/clr:safe  
  
 Uma compilação com **\/clr:pure** ou **\/clr:safe** gerará uma imagem de MSIL apenas uma imagem, sem código nativo \(não gerenciado\).  Consequentemente, você não pode usar o pragma de `unmanaged` em uma compilação de **\/clr:pure** ou de **\/clr:safe** .  
  
 Para obter mais informações, consulte [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md) e [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md).  
  
## Exemplo  
 O seguinte exemplo gera C3862:  
  
```  
// C3862.cpp  
// compile with: /clr:pure /c  
#pragma unmanaged  
void f() {}   // C3862  
```