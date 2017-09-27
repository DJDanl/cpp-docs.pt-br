---
title: privada (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- private_cpp
- private
dev_langs:
- C++
helpviewer_keywords:
- private keyword [C++]
ms.assetid: 94e99983-46a5-4e21-800c-28f8a7c6a8ff
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
ms.openlocfilehash: ec12850b2d2059c2824c0585edee21cb3fd1a7f7
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="private-c"></a>private (C++)
## <a name="syntax"></a>Sintaxe  
  
```  
private:  
   [member-list]  
private base-class  
```  
  
## <a name="remarks"></a>Comentários  
 Quando precede uma lista de membros de classe, a palavra-chave `private` especifica que esses membros podem ser acessados somente de funções de membros e friends da classe. Isso se aplica a todos os membros declarados até o especificador seguinte do acesso ou ao final da classe.  
  
 Para preceder o nome de uma classe base, a palavra-chave `private` especifica que os membros públicos e protegidos da classe base são membros particulares da classe derivada.  
  
 O acesso padrão dos membros em um classe é particular. O acesso padrão dos membros em uma estrutura ou união é público.  
  
 O acesso padrão de uma classe base é particular para classes e público para estruturas. Uniões não podem ter classes base.  
  
 Para obter informações relacionadas, consulte [friend](../cpp/friend-cpp.md), [pública](../cpp/public-cpp.md), [protegido](../cpp/protected-cpp.md)e a tabela de acesso de membro no [controlando o acesso a membros de classe](member-access-control-cpp.md).  
  
## <a name="clr-specific"></a>Específico do /clr  
 Em tipos CLR, o C++ acessar palavras-chave do especificador (**pública**, `private`, e `protected`) podem afetar a visibilidade de tipos e métodos em relação a assemblies. Para obter mais informações, consulte [controle de acesso de membro](member-access-control-cpp.md).  
  
> [!NOTE]
>  Arquivos compilados com [/LN](../build/reference/ln-create-msil-module.md) não são afetados por esse comportamento. Nesse caso, todas as classes gerenciadas (públicas ou particulares) serão visíveis.  
  
## <a name="end-clr-specific"></a>Específico de END /clr  
  
## <a name="example"></a>Exemplo  
  
```  
// keyword_private.cpp  
class BaseClass {  
public:  
   // privMem accessible from member function  
   int pubFunc() { return privMem; }  
private:  
   void privMem;  
};  
  
class DerivedClass : public BaseClass {  
public:  
   void usePrivate( int i )  
      { privMem = i; }   // C2248: privMem not accessible  
                         // from derived class  
};  
  
class DerivedClass2 : private BaseClass {  
public:  
   // pubFunc() accessible from derived class  
   int usePublic() { return pubFunc(); }  
};  
  
int main() {  
   BaseClass aBase;  
   DerivedClass aDerived;  
   DerivedClass2 aDerived2;  
   aBase.privMem = 1;     // C2248: privMem not accessible  
   aDerived.privMem = 1;  // C2248: privMem not accessible  
                          //    in derived class  
   aDerived2.pubFunc();   // C2247: pubFunc() is private in  
                          //    derived class  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Controlando o acesso a membros de classe](member-access-control-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
