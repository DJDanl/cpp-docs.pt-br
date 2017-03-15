---
title: "make_public | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc-pragma.make_public"
  - "make_public_CPP"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "make_public (pragma)"
  - "pragmas, make_public"
ms.assetid: c3665f4d-268a-4932-9661-c37c8ae6a341
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# make_public
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica que um tipo nativo deve ter a acessibilidade pública de assembly.  
  
## Sintaxe  
  
```  
#pragma make_public(type)  
```  
  
#### Parâmetros  
 `type` é o nome do tipo ao qual você deseja ter a acessibilidade pública de assembly.  
  
## Comentários  
 `make_public` é útil quando o tipo nativo que você deseja referenciar é de um arquivo .h que você não pode alterar.  Se você desejar usar o tipo nativo na assinatura de uma função pública em um tipo com visibilidade pública de assembly, o tipo nativo também deve ter a acessibilidade pública do assembly. Caso contrário, o compilador emitirá um aviso.  
  
 `make_public` deve ser especificado no escopo global e é aplicado apenas ao ponto em que é declarado até ao final do arquivo de código\-fonte.  
  
 O tipo nativo pode ser implicitamente ou explicitamente particular; consulte [Visibilidade de tipo](../Topic/Type%20Visibility.md) para obter mais informações.  
  
## Exemplo  
 O exemplo a seguir é o conteúdo de um arquivo .h que contém as definições para duas estruturas nativas.  
  
```  
// make_public_pragma.h  
struct Native_Struct_1 { int i; };  
struct Native_Struct_2 { int i; };  
```  
  
## Exemplo  
 O exemplo de código a seguir consome o arquivo de cabeçalho e mostra que, a menos que você marque explicitamente as estruturas nativas como públicas usando `make_public`, o compilador gerará um aviso quando você tentar usar as estruturas nativas na assinatura da função pública em um tipo gerenciado público.  
  
```  
// make_public_pragma.cpp  
// compile with: /c /clr /W1  
#pragma warning (default : 4692)  
#include "make_public_pragma.h"  
#pragma make_public(Native_Struct_1)  
  
public ref struct A {  
   void Test(Native_Struct_1 u) {u.i = 0;}   // OK  
   void Test(Native_Struct_2 u) {u.i = 0;}   // C4692  
};  
```  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)