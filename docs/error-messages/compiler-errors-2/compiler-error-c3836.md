---
title: C3836 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3836
dev_langs:
- C++
helpviewer_keywords:
- C3836
ms.assetid: 254f851b-7b7d-4c34-a740-fcf72f6a636a
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 43f7972efc5e8b930811817f5cef9c415a60cb5d
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3836"></a>C3836 de erro do compilador
construtor estático não pode ter uma lista de inicializador de membro  
  
 Uma classe gerenciada não pode ter um construtor estático que também tem uma lista de inicialização de membro. Construtores de classe estáticos são chamados pelo common language runtime para a classe de inicialização, membros de dados estáticos de inicialização.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3836:  
  
```  
// C3836a.cpp  
// compile with: /clr  
ref class M  
{  
   static int s_i;  
  
public:  
   static M() :  s_i(1234)   // C3836, delete initializer to resolve  
   {  
   }  
};  
  
int main()  
{  
}  
```  

