---
title: "público (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: public_cpp
dev_langs: C++
helpviewer_keywords: public keyword [C++]
ms.assetid: f3e10a59-39f6-4bcd-827e-3e99f8f89497
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0ff41d2b12f43deabd82538a3e2fb10eb35ead16
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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