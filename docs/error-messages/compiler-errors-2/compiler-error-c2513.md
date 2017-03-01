---
title: C2513 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f7a51320b46172c277df6a6b308fe4ceea69aeb6
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2513"></a>C2513 de erro do compilador
'type': nenhuma variável declarada antes de '='  
  
 O especificador de tipo aparece na declaração sem nenhum identificador de variável.  
  
 O exemplo a seguir gera C2513:  
  
```  
// C2513.cpp  
int main() {  
   int = 9;   // C2513  
   int i = 9;   // OK  
}  
```  
  
 Esse erro também pode ser gerado como resultado de uma trabalho conformidade compilador do Visual Studio .NET 2003: inicialização de um typedef não permitido. A inicialização de um typedef não é permitida por padrão e agora gera um erro do compilador.  
  
```  
// C2513b.cpp  
// compile with: /c  
typedef struct S {  
   int m_i;  
} S = { 1 };   // C2513  
// try the following line instead  
// } S;  
```  
  
 Uma alternativa seria excluir `typedef` definir uma variável de lista do inicializador de agregação, mas isso não é recomendado porque ele será criar uma variável com o mesmo nome que o tipo e ocultar o nome do tipo.
