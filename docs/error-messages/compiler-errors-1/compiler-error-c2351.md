---
title: C2351 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2351
dev_langs: C++
helpviewer_keywords: C2351
ms.assetid: 5439ccf6-66f6-4859-964c-c73f5eddfc1b
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 97b6c52436d2850cfaaa1685692b7d974a6d8cad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2351"></a>C2351 de erro do compilador
sintaxe de inicialização de construtor de C++ obsoleta  
  
 Em uma lista de inicialização de novo estilo para um construtor, você deve nomear explicitamente cada classe base direta, mesmo se ela é a classe base somente.  
  
 O exemplo a seguir gera C2351:  
  
```  
// C2351.cpp  
// compile with: /c  
class B {  
public:   
   B() : () {}   // C2351  
   B() {}   // OK  
};  
```