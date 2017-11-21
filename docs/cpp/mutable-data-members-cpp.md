---
title: "Membros de dados mutáveis (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: mutable_cpp
dev_langs: C++
helpviewer_keywords: mutable keyword [C++]
ms.assetid: ebe89746-3d36-43a8-8d69-f426af23f551
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: a3c960c5fcf5a73d339b7565cd0bec38dba98f12
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="mutable-data-members-c"></a>Membros de dados mutáveis (C++)
Essa palavra-chave só pode ser aplicada aos membros de dados não estáticas e não constantes de uma classe. Se um membro de dados for declarado `mutable`, e em seguida, é permitido atribuir um valor para este membro de dados de um **const** função de membro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
mutable member-variable-declaration;  
```  
  
## <a name="remarks"></a>Comentários  
 Por exemplo, o código a seguir será compilado sem erros porque `m_accessCount` foi declarado como `mutable` e, consequentemente, pode ser alterado por `GetFlag`, mesmo que `GetFlag` seja uma função de membro constante.  
  
```  
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