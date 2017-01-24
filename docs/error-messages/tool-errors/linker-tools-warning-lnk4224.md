---
title: "Aviso LNK4224 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4224"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4224"
ms.assetid: 8624b70e-0b93-43cf-b457-834d38632d0b
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4224 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a opção não tem mais suporte; ignorado  
  
 Uma opção inválido, obsoleta do vinculador foi especificada e ignorada.  
  
 Por exemplo, LNK4224 pode ocorrer se uma política de \/comment aparece em .obj.  A política de \/comment será adicionada pelo pragma de [comment](../../preprocessor/comment-c-cpp.md) , usando a opção de exestr substituído.  O dumpbin [\/ALL](../../build/reference/all.md) de uso para exibir as políticas do vinculador em um .obj arquivos.  
  
 Se possível, modifique a origem para o .obj e remover o pragma.  Se você ignorar esse aviso, é possível que um .executable compilado com **\/clr:pure** não serão executados como esperado.  
  
## Exemplo  
 O exemplo a seguir produz LNK4224.  
  
```  
// LNK4224.cpp  
// compile with: /c /Zi  
// post-build command: link LNK4224.obj /debug /debugtype:map  
int main () {  
   return 0;  
}  
```