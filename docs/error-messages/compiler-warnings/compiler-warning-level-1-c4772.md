---
title: "Aviso do compilador (n&#237;vel 1) C4772 | Microsoft Docs"
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
  - "C4772"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4772"
ms.assetid: dafe6fd8-9faf-41f5-9d66-a55838742c14
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4772
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o \#import que fez referência a um tipo de uma biblioteca ausente do tipo; “missing\_type” usado como espaço reservado  
  
 Uma biblioteca de tipos foi referenciada com a política de [\#import](../Topic/%23import%20Directive%20\(C++\).md) .  No entanto, a biblioteca de tipos continha uma referência a outra biblioteca de tipos que não foi referenciada com `#import`.  Esse outro arquivo de .tlb não foi encontrado pelo compilador.  
  
 Observe que o compilador não localizará bibliotecas de tipo em diretórios diferentes se você usar a opção do compilador de [\/I \(diretórios de inclusão adicionais\)](../../build/reference/i-additional-include-directories.md) especificar esses diretórios.  Se você quiser que o compilador para localizar bibliotecas de tipo em diretórios diferentes, adicionar esses diretórios para a variável de ambiente PATH.  
  
 Esse aviso é emitido, por padrão como um erro.  C4772 não pode ser suprimido com \/W0.  
  
## Exemplo  
 Esta é a primeira biblioteca de tipos necessária para reproduzir C4772.  
  
```  
// c4772a.idl  
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12b")]  
library C4772aLib  
{  
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c100")]  
   enum E_C4772a  
   {  
      one, two, three  
   };  
};  
```  
  
## Exemplo  
 Esta é a segunda biblioteca de tipos necessária para reproduzir C4772.  
  
```  
// c4772b.idl  
// post-build command: del /f C4772a.tlb  
// C4772a.tlb is available when c4772b.tlb is built  
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12d")]  
library C4772bLib  
{  
   importlib ("c4772a.tlb");  
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12e")]  
   struct S_C4772b  
   {  
      enum E_C4772a e;  
   };  
};  
```  
  
## Exemplo  
 O seguinte exemplo gera C4772:  
  
```  
// C4772.cpp  
// assumes that C4772a.tlb is not available to the compiler  
// #import "C4772a.tlb"  
#import "C4772b.tlb"   // C4772 uncomment previous line to resolve  
                       // and make sure c4772a.tlb is on disk  
```