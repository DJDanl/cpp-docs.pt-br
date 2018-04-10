---
title: Acesso de membro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- member-selection operators [C++]
- pointers, smart
- member access, overloaded operators
- operator overloading [C++], member access operators
- smart pointers, definition
- smart pointers
ms.assetid: 8c7b2c43-eb92-4d42-9a8e-61aa37d71333
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 18348c3d59457b7920f7902687f0220121c30e2c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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