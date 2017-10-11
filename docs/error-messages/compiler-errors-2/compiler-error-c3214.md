---
title: C3214 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3214
dev_langs:
- C++
helpviewer_keywords:
- C3214
ms.assetid: 49ee4a9a-2549-4adb-9d3a-38e154303c2e
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 6d280f500368ac7ac6ad0a987b987e1f9e57b6a5
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3214"></a>C3214 de erro do compilador
'type': argumento de tipo inválido para parâmetro de generic 'generic_type' do parâmetro genérico não atender a restrição 'restrição'  
  
 O tipo foi especificado para uma instanciação de uma classe genérica que não satisfaz a restrição da classe genérica.  
  
 O exemplo a seguir gera C3214:  
  
```  
// C3214.cpp  
// compile with: /clr  
interface struct A {};  
  
generic <class T>   
where T : A  
ref class C {};  
  
ref class X : public A {};  
  
int main() {  
   C<int>^ c = new C<int>;   // C3214  
   C<X ^> ^ c2 = new C<X^>;   // OK  
}  
```
