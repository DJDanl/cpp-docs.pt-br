---
title: Especificador final | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- final_CPP
dev_langs:
- C++
helpviewer_keywords:
- final Identifier
ms.assetid: 649866d0-79d4-449f-ab74-f84b911b79a3
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: c9f0a638707466778e75a3eabfe838c84b0355d7
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="final-specifier"></a>especificador final
Você pode usar a palavra-chave `final` para designar funções virtuais que não podem ser substituídas em uma classe derivada. Também é possível usá-la para designar classes que não podem ser herdadas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
function-declaration final;  
```  
  
```  
  
class class-name final base-classes  
```  
  
## <a name="remarks"></a>Comentários  
 `final` é contextual e tem um significado especial somente quando é usada após uma declaração de função ou um nome de classe; caso contrário, não é uma palavra-chave reservada.  
  
 Quando `final` é usada em declarações de classe, `base-classes` é uma parte opcional da declaração.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir usa a palavra-chave `final` para especificar que uma função virtual não pode ser substituída.  
  
```cpp  
class BaseClass  
{  
    virtual void func() final;  
};  
  
class DerivedClass: public BaseClass  
{  
    virtual void func(); // compiler error: attempting to   
                         // override a final function  
};  
```  
  
 Para obter informações sobre como especificar que as funções de membro podem ser substituídas, consulte [especificador de substituição](../cpp/override-specifier.md).  
  
 O exemplo a seguir usa a palavra-chave `final` para especificar que uma classe não pode ser herdada.  
  
```cpp  
class BaseClass final   
{  
};  
  
class DerivedClass: public BaseClass // compiler error: BaseClass is   
                                     // marked as non-inheritable  
{  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Especificador override](../cpp/override-specifier.md)
