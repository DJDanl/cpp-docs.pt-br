---
title: "C4394 de aviso do compilador | Microsoft Docs"
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
  - "C4394"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4394"
ms.assetid: 5de94de0-17e3-4e7c-92f4-5c3c1b825120
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C4394 de aviso do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: o símbolo de Appdomain por não deve ser marcado com o \_\_declspec \(dllexport\)  
  
 Uma função marcada com o modificador de [appdomain](../Topic/appdomain.md)`__declspec` é compilada a MSIL \(não o nativo\), as tabelas e de exportação \(modificador de[export](../../windows/export.md)`__declspec` \) não têm suporte para funções gerenciadas.  
  
 Você pode declarar uma função gerenciada para ter a acessibilidade pública.  Para obter mais informações, consulte [Visibilidade do tipo](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) e [Visibilidade do membro](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Member_visibility).  
  
 C4394 é emitido sempre como um erro.  Você pode desativar esse aviso com `#pragma warning` ou **\/wd**; consulte [warning](../../preprocessor/warning.md) ou [\/w, \/W0, \/W1, \/W2, \/W3, \/W4, \/w1, \/w2, \/w3, \/w4, \/Wall, \/wd, \/, \/wo, \/Wv, \/WX \(nível de aviso\)](../../build/reference/compiler-option-warning-level.md) para obter mais informações.  
  
## Exemplo  
 O exemplo a seguir produz C4394.  
  
```  
// C4394.cpp  
// compile with: /clr /c  
__declspec(dllexport) __declspec(appdomain) int g1 = 0;   // C4394  
__declspec(dllexport) int g2 = 0;   // OK  
```