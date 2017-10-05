---
title: Acesso de membro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- member-selection operators
- pointers, smart
- member access, overloaded operators
- operator overloading, member access operators
- smart pointers, definition
- smart pointers
ms.assetid: 8c7b2c43-eb92-4d42-9a8e-61aa37d71333
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
ms.openlocfilehash: 21cdc3de990a8b23645bb09f9f093fb0f2498254
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="member-access"></a>Acesso de membro
Acesso de membro de classe pode ser controlado pelo sobrecarregar o operador de acesso de membro (**->**). Esse operador é considerado um operador unário nesse uso, e a função sobrecarregada do operador deve ser uma função de membro da classe. Portanto, a declaração dessa função é:  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
class-type *operator->()  
```  
  
## <a name="remarks"></a>Comentários  
 onde *tipo de classe* é o nome da classe à qual pertence este operador. A função do operador de acesso do membro deve ser uma função de membro não estático.  
  
 Esse operador é usado (frequentemente em conjunto com o operador de desreferência de ponteiro) para implementar "ponteiros inteligentes" que validam os ponteiros antes da desreferência ou do uso da contagem.  
  
 O elemento de linguagem **.** operador de acesso de membro não pode ser sobrecarregado.  
  
## <a name="see-also"></a>Consulte também  
 [Sobrecarga de Operador](../cpp/operator-overloading.md)
