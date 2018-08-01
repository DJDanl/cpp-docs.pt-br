---
title: Modelos de função de membro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- function templates, member functions
ms.assetid: 83d51835-6a27-40ed-997c-7d90dc9182d8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7767b833fb80926e425e14a209c3d97a778e72b5
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39404220"
---
# <a name="member-function-templates"></a>Modelos de função de membro

O modelo de membro do termo se refere aos modelos da função de membro e modelos de classe aninhada. Os modelos da função de membro são funções de modelo que são membros de uma classe ou de um modelo de classe.  
  
 As funções de membro podem ser modelos de função em vários contextos. Todas as funções de modelos da classe são genéricas, mas não são referidas como modelos de membros ou modelos da função de membro. Se essas funções de membro usam seus próprios argumentos de modelo, são consideradas modelos da função de membro.  
  
## <a name="example"></a>Exemplo

 Os modelos da função de membro de classes nontemplate ou de modelo são declarados como modelos de função com seus parâmetros de modelo.  
  
```cpp
// member_function_templates.cpp  
struct X  
{  
   template <class T> void mf(T* t) {}  
};  
  
int main()  
{  
   int i;  
   X* x = new X();  
   x->mf(&i);  
}  
```  
  
## <a name="example"></a>Exemplo

 O exemplo a seguir mostra um modelo da função de membro de uma classe de modelo.  
  
```cpp
// member_function_templates2.cpp  
template<typename T>  
class X  
{  
public:  
   template<typename U>  
   void mf(const U &u)  
   {  
   }  
};  
  
int main()  
{  
}  
```  
  
## <a name="example"></a>Exemplo
  
```cpp
// defining_member_templates_outside_class.cpp  
template<typename T>  
class X  
{  
public:  
   template<typename U>  
   void mf(const U &u);  
};  
  
template<typename T> template <typename U>  
void X<T>::mf(const U &u)  
{  
}  
  
int main()  
{  
}  
```  
  
## <a name="example"></a>Exemplo

 As classes locais não podem ter modelos de membro.  
  
 As funções de modelo do membro não podem ser funções virtuais e não podem substituir funções virtuais de uma classe base quando são declaradas com o mesmo nome que uma função virtual da classe base.  
  
O exemplo a seguir mostra uma conversão de definida pelo usuário com modelo:  
  
```cpp
// templated_user_defined_conversions.cpp  
template <class T>  
struct S  
{  
   template <class U> operator S<U>()  
   {  
      return S<U>();  
   }  
};  
  
int main()  
{  
   S<int> s1;  
   S<long> s2 = s1;  // Convert s1 using UDC and copy constructs S<long>.  
}  
```  
  
## <a name="see-also"></a>Consulte também
 [Modelos de função](../cpp/function-templates.md)