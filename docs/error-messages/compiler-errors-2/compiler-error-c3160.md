---
title: C3160 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3160
dev_langs:
- C++
helpviewer_keywords:
- C3160
ms.assetid: a250c433-8adf-43b9-8dee-c3794e09b0a5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 670dd386be82b4356262cb59442d36fb1d6f646b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33249236"
---
# <a name="compiler-error-c3160"></a>C3160 de erro do compilador
'ponteiro': uma classe de WinRT ou um membro de dados de um gerenciado não pode ter esse tipo  
  
 Ponteiros de coleta de lixo interior podem apontar para o interior de um serviço ou a classe do WinRT. Porque eles são mais lentos do que os ponteiros do objeto inteiro e exigem tratamento especial pelo coletor de lixo, você não pode declarar ponteiros gerenciados internos como membros de uma classe.  
  
 O exemplo a seguir gera C3160:  
  
```  
// C3160.cpp  
// compile with: /clr  
ref struct A {  
   // cannot create interior pointers inside a class  
   interior_ptr<int> pg;   // C3160  
   int g;   // OK  
   int* pg2;   // OK  
};  
  
int main() {  
   interior_ptr<int> pg2;   // OK  
}  
```  
