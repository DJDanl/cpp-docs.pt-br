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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 62c55a1a6eb093d4ef6921f6d0f8b7c50683ff8d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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