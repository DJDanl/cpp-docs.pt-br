---
title: "público (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- public
dev_langs:
- C++
helpviewer_keywords:
- public keyword [C++]
ms.assetid: f3e10a59-39f6-4bcd-827e-3e99f8f89497
caps.latest.revision: 10
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
ms.openlocfilehash: 7ce4262b3f32f48b61e6f4e273ce74c8334f8f0c
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="public-c"></a>public (C++)
## <a name="syntax"></a>Sintaxe  
  
```  
public:  
   [member-list]  
public base-class  
```  
  
## <a name="remarks"></a>Comentários  
 Quando precede uma lista de membros de classe, o **pública** palavra-chave especifica que os membros são acessíveis de qualquer função. Isso se aplica a todos os membros declarados até o especificador seguinte do acesso ou ao final da classe.  
  
 Quando precede o nome de uma classe base, o **pública** palavra-chave especifica que os membros protegidos e públicos da classe base são públicos e protegidos membros, respectivamente, da classe derivada.  
  
 O acesso padrão dos membros em um classe é particular. O acesso padrão dos membros em uma estrutura ou união é público.  
  
 O acesso padrão de uma classe base é particular para classes e público para estruturas. Uniões não podem ter classes base.  
  
 Para obter mais informações, consulte [privada](../cpp/private-cpp.md), [protegido](../cpp/protected-cpp.md), [friend](../cpp/friend-cpp.md)e a tabela de acesso de membro na [controlando o acesso a membros de classe](member-access-control-cpp.md) .  
  
## <a name="clr-specific"></a>Específico do /clr  
 Em tipos CLR, o C++ acessar palavras-chave do especificador (**pública**, `private`, e `protected`) podem afetar a visibilidade de tipos e métodos em relação a assemblies. Para obter mais informações, consulte [controle de acesso de membro](member-access-control-cpp.md).  
  
> [!NOTE]
>  Arquivos compilados com [/LN](../build/reference/ln-create-msil-module.md) não são afetados por esse comportamento. Nesse caso, todas as classes gerenciadas (públicas ou particulares) serão visíveis.  
  
## <a name="end-clr-specific"></a>Específico de END /clr  
  
## <a name="example"></a>Exemplo  
  
```  
// keyword_public.cpp  
class BaseClass {  
public:  
   int pubFunc() { return 0; }  
};  
  
class DerivedClass : public BaseClass {};  
  
int main() {  
   BaseClass aBase;  
   DerivedClass aDerived;  
   aBase.pubFunc();       // pubFunc() is accessible   
                          //    from any function  
   aDerived.pubFunc();    // pubFunc() is still public in   
                          //    derived class  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Controlando o acesso a membros de classe](member-access-control-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
