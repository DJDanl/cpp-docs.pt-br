---
title: C3852 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3852
dev_langs: C++
helpviewer_keywords: C3852
ms.assetid: 194e5c5e-0dfb-414e-86db-791c11eb610c
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 51a2fb508b63f3b6381c03e674ffaf019d6f24e2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3852"></a>C3852 de erro do compilador
'member' com tipo 'type': inicialização de agregação não foi possível inicializar este membro  
  
 Foi feita uma tentativa para atribuir uma inicialização padrão como parte de uma inicialização de agregação para um membro de dados que não é possível receber a inicialização de um padrão em uma inicialização de agregação.  
  
 Os exemplos a seguir geram C3852:  
  
```  
// C3852.cpp  
struct S  
{  
   short s;  
};  
  
struct S1  
{  
   int i;  
   const S s;  
};  
  
struct S2  
{  
   int i;  
   char & rc;  
};  
  
int main()  
{  
   S1 s1 = { 1 };   // C3852 const member   
   // try the following line instead  
   // S1 s1 = { 1, 2 };  
  
   S2 s2 = { 2 };   // C3852 reference member  
   // try the following line instead  
   // char c = 'a';  
   S2 s2 = { 2, c };  
}  
```