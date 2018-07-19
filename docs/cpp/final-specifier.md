---
title: Especificador final | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- final_CPP
dev_langs:
- C++
helpviewer_keywords:
- final Identifier
ms.assetid: 649866d0-79d4-449f-ab74-f84b911b79a3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 594bc432cb12b63c76172b06ee078d5b0f72de55
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942121"
---
# <a name="final-specifier"></a>especificador final
Você pode usar o **final** palavra-chave para designar funções virtuais que não podem ser substituídas em uma classe derivada. Também é possível usá-la para designar classes que não podem ser herdadas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
function-declaration final;  
class class-name final base-classes  
```  
  
## <a name="remarks"></a>Comentários  
 **final** é contextual e tem um significado especial somente quando ele é usado após uma declaração de função ou nome de classe; caso contrário, ele não é uma palavra-chave reservada.  
  
 Quando **final** é usado em declarações de classe, `base-classes` é uma parte opcional da declaração.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir usa o **final** palavra-chave para especificar que uma função virtual não pode ser substituída.  
  
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
  
 O próximo exemplo usa o **final** palavra-chave para especificar que uma classe não pode ser herdada.  
  
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