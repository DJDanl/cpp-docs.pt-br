---
title: Membros de dados mutáveis (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- mutable_cpp
dev_langs:
- C++
helpviewer_keywords:
- mutable keyword [C++]
ms.assetid: ebe89746-3d36-43a8-8d69-f426af23f551
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 65d2fc42021a01a1260b57f9516e53c439c8e604
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942332"
---
# <a name="mutable-data-members-c"></a>Membros de dados mutáveis (C++)
Essa palavra-chave só pode ser aplicada aos membros de dados não estáticas e não constantes de uma classe. Se um membro de dados for declarado **mutável**, então é válido para atribuir um valor para este membro de dados de uma **const** função de membro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
mutable member-variable-declaration;  
```  
  
## <a name="remarks"></a>Comentários  
 Por exemplo, o código a seguir será compilado sem erros porque `m_accessCount` tenha sido declarado **mutável**e, portanto, pode ser modificado por `GetFlag` Embora `GetFlag` é uma função de membro const.  
  
```cpp 
// mutable.cpp  
class X  
{  
public:  
   bool GetFlag() const  
   {  
      m_accessCount++;  
      return m_flag;  
   }  
private:  
   bool m_flag;  
   mutable int m_accessCount;  
};  
  
int main()  
{  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)