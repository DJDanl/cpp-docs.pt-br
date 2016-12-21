---
title: "Erro das Ferramentas de Vinculador LNK1306 | Microsoft Docs"
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
  - "LNK1306"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1306"
ms.assetid: fad1df6a-0bd9-412f-b0d1-7c9bc749c584
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1306
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A função do ponto de entrada da DLL não pode ser gerenciada; ao criar nativo  
  
 DllMain não pode ser compilado a MSIL; deve ser compilado em código nativo.  
  
 Para resolver,  
  
-   Cria o arquivo que contém o ponto de entrada sem **\/clr**.  
  
-   Posicione o ponto de entrada em uma seção de `#pragma unmanaged` .  
  
-   Para obter mais informações, consulte  
  
-   [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md)  
  
-   [Inicialização de assemblies mistos](../Topic/Initialization%20of%20Mixed%20Assemblies.md)  
  
-   [Comportamento da biblioteca em tempo de execução](../../build/run-time-library-behavior.md)  
  
## Exemplo  
 O exemplo a seguir produz LNK1306.  
  
```  
// LNK1306.cpp  
// compile with: /clr /link /dll /entry:NewDllMain  
// LNK1306 error expected  
#include <windows.h>  
int __stdcall NewDllMain( HINSTANCE h, ULONG ulReason, PVOID pvReserved ) {  
   return 1;  
}  
```