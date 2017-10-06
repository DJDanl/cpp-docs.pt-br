---
title: void (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- void_cpp
dev_langs:
- C++
helpviewer_keywords:
- void keyword [C++]
- functions [C++], void
- pointers, void
ms.assetid: d203edba-38e6-4056-8b89-011437351057
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: dea06f16979fab9aa4494b172d6d95193a9f3727
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="void-c"></a>void (C++)
Quando usado como um tipo de retorno da função, a palavra-chave `void` especifica que a função não retorna um valor. Quando usado para a lista de parâmetros de uma função, um item nulo especifica que a função não usa parâmetros. Quando usado em declaração de um ponteiro nulo, especifica que o ponteiro é “universal”.  
  
 Se o tipo do ponteiro é **void \* **, o ponteiro pode apontar para qualquer variável que não é declarada com o **const** ou `volatile` palavra-chave. Um ponteiro nulo não pode ter a referência removida a menos que seja convertido para outro tipo. Um ponteiro nulo pode ser convertido em outro tipo de ponteiro de dados.  
  
 Um ponteiro nulo pode apontar para uma função, mas não para um membro da classe em C++.  
  
 Você não pode declarar uma variável de tipo nulo.  
  
## <a name="example"></a>Exemplo  
  
```  
// void.cpp  
void vobject;   // C2182  
void *pv;   // okay  
int *pint; int i;  
int main() {  
   pv = &i;  
   // Cast optional in C required in C++  
   pint = (int *)pv;  
}   
```  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Tipos fundamentais](../cpp/fundamental-types-cpp.md)
