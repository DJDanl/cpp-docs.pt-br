---
title: "Compilador aviso (nível 4) C4032 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4032
dev_langs:
- C++
helpviewer_keywords:
- C4032
ms.assetid: 70dd0c85-0239-43f9-bb06-507f6a57d206
caps.latest.revision: 7
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
ms.openlocfilehash: c2d01f957513a004c17e4f245bdf866186348c17
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4032"></a>Compilador C4032 de aviso (nível 4)
o parâmetro formal 'number' tem tipo diferente quando promovido  
  
 O tipo de parâmetro não é compatível, por meio de promoções padrão, com o tipo em uma declaração anterior.  
  
 Este é um erro em ANSI C ([/Za](../../build/reference/za-ze-disable-language-extensions.md)) e um aviso de extensões da Microsoft (/Ze).  
  
## <a name="example"></a>Exemplo  
  
```  
// C4032.c  
// compile with: /W4  
void func();  
void func(char);   // C4032, char promotes to int  
  
int main()  
{  
}  
```
