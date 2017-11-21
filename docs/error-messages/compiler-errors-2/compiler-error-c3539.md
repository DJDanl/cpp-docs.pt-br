---
title: C3539 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3539
dev_langs: C++
helpviewer_keywords: C3539
ms.assetid: 34a33a0f-d1b6-498f-b312-ffad2d4799b3
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 03283217be6aabbf216e2e60ad47abfc01a961d6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3539"></a>C3539 de erro do compilador
'type': um argumento de template não pode ser um tipo que contenha 'auto'  
  
 O tipo de argumento de modelo indicado não pode conter um uso do `auto` palavra-chave.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Não especifique o argumento de modelo com o `auto` palavra-chave.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3539.  
  
```  
// C3539.cpp  
// Compile with /Zc:auto  
template<class T> class C{};  
int main()  
{  
   C<auto> c;   // C3539  
   return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Palavra-chave auto](../../cpp/auto-keyword.md)