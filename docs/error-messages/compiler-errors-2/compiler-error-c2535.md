---
title: C2535 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2535
dev_langs: C++
helpviewer_keywords: C2535
ms.assetid: a958f83e-e2bf-4a59-b44b-d406ec325d7e
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 0af3ce8f0f3fe89d8e2f120f1b9b16383f11ef6a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c2535"></a>C2535 de erro do compilador
'Identificador': função de membro já definida ou declarada  
  
 Esse erro pode ser causado por usando a mesma lista de parâmetros formais em mais de uma definição ou declaração de uma função sobrecarregada.  
  
 Se você receber C2535 devido a função Dispose, consulte [destruidores e finalizadores](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers) para obter mais informações.  
  
 Se você estiver compilando um projeto de ATL, consulte o artigo da Base de dados de Conhecimento Q241852.  
  
 O exemplo a seguir gera C2535:  
  
```  
// C2535.cpp  
// compile with: /c  
class C {  
public:  
   void func();   // forward declaration  
   void func() {}   // C2535  
};  
```