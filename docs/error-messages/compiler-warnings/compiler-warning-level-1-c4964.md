---
title: "Aviso do compilador (n&#237;vel 1) C4964 | Microsoft Docs"
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
  - "C4964"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4964"
ms.assetid: b89c9274-8a92-4b7c-aa30-3fbb1b68ac73
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4964
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Nenhuma opção de otimização foi especificada; as informações de perfil não serão coletadas  
  
 [\/GL](../../build/reference/gl-whole-program-optimization.md) e [\/LTCG](../../build/reference/ltcg-link-time-code-generation.md) foram especificados, mas nenhuma otimização foi solicitada, de modo que nenhum arquivo de .pgc será gerado e, consequentemente, nenhuma otimização perfil\- orientada será possível.  
  
 Se você quiser que os arquivos de .pgc a serem gerados quando você executa seu aplicativo, especifique uma das opções do compilador de [\/O](../../build/reference/o-options-optimize-code.md) .  
  
 O seguinte exemplo gera C4964:  
  
```  
// C4964.cpp  
// compile with: /W1 /GL /link /ltcg:pgi  
// C4964 expected  
// Add /O2, for example, to the command line to resolve this warning.  
int main() {  
   int i;  
}  
```