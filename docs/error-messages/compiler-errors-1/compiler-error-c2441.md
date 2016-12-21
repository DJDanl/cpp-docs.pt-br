---
title: "Erro do Compilador C2441 | Microsoft Docs"
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
  - "C2441"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2441"
ms.assetid: ffbd6573-777a-48dd-892f-5cf4a758dcab
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2441
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“variable”: um símbolo declarado com \_\_declspec \(processo\) deve ser const no modo de \/clr:pure  
  
 Por padrão, as variáveis são pelo domínio do aplicativo em **\/clr:pure**.  `__declspec(process)` marcado variável em **\/clr:pure** é susceptível a erros alteradas em um domínio de aplicativo e ler em outro.  
  
 Em virtude disso, o compilador imposta por variáveis de processo é `const` em **\/clr:pure**, tornando\-os somente leitura em todos os domínios de aplicativo.  
  
 Para obter mais informações, consulte [process](../../cpp/process.md) e [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
## Exemplo  
 O exemplo a seguir produz C2441.  
  
```  
// C2441.cpp  
// compile with: /clr:pure /c  
__declspec(process) int i;   // C2441  
__declspec(process) const int j = 0;   // OK  
```