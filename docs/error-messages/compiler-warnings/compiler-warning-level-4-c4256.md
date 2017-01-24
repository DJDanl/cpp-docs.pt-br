---
title: "Aviso do compilador (n&#237;vel 4) C4256 | Microsoft Docs"
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
  - "C4256"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4256"
ms.assetid: a755a32e-895a-4837-a2b5-4ea06b736798
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4256
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: o construtor da classe com bases virtuais tenha “…;” as chamadas podem não ser compatíveis com versões anteriores do Visual C\+\+  
  
 Incompatibilidade possível.  
  
 Considere o exemplo de código.  Se a definição do construtor S2::S2 \(int, eu… o\) foi compilado com uma versão do compilador do Visual C\+\+ antes da versão 7, mas o exemplo a seguir é compilado com a versão atual, a chamada para o construtor para S3 não funcione corretamente devido a uma alteração de chamada\- convenção maiúsculas de minúsculas.  Se ambos foram compilados usando o Visual C\+\+ 6.0, a chamada não funcionaria suficiente se nenhum, a menos que nenhum parâmetro é transmitido para as reticências.  
  
 Para corrigir esse aviso,  
  
1.  Não use reticências em um construtor.  
  
2.  Verifique se todos os componentes no seu projeto são compilados com a versão atual \(que inclui algumas bibliotecas que possa definir ou referenciam essa classe\), então desabilitar\-se o aviso usando o pragma de [aviso](../../preprocessor/warning.md) .  
  
 O seguinte exemplo gera C4256:  
  
```  
// C4256.cpp  
// compile with: /W4  
// #pragma warning(disable : 4256)  
struct S1  
{  
};  
  
struct S2: virtual public S1  
{  
   S2( int i, ... )    // C4256  
   {  
      i = 0;  
   }  
   /*  
   // try the following line instead  
   S2( int i)  
   {  
      i = 0;  
   }  
   */  
};  
  
void func1()  
{  
   S2 S3( 2, 1, 2 );   // C4256  
   // try the following line instead  
   // S2 S3( 2 );  
}  
  
int main()  
{  
}  
```