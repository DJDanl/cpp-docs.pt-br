---
title: C2513 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2513
dev_langs:
- C++
helpviewer_keywords:
- C2513
ms.assetid: ab5b21d3-61e2-4df7-8eea-6f14d6ba8620
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 7eb4e7c63821f449bf9677cb5fe03c448bbbc6ee
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2513"></a>C2513 de erro do compilador
'type': nenhuma variável declarada antes de '='  
  
 O especificador de tipo aparece na declaração com nenhum identificador de variável.  
  
 O exemplo a seguir gera C2513:  
  
```  
// C2513.cpp  
int main() {  
   int = 9;   // C2513  
   int i = 9;   // OK  
}  
```  
  
 Esse erro também pode ser gerado como resultado de um trabalho de conformidade do compilador concluído para Visual Studio .NET 2003: inicialização de um typedef não permitido. A inicialização de um typedef não é permitida por padrão e agora gera um erro do compilador.  
  
```  
// C2513b.cpp  
// compile with: /c  
typedef struct S {  
   int m_i;  
} S = { 1 };   // C2513  
// try the following line instead  
// } S;  
```  
  
 Uma alternativa seria excluir `typedef` definir uma variável com lista de inicializadores de agregação, mas isso não é recomendável porque ele cria uma variável com o mesmo nome como o tipo e ocultar o nome do tipo.
