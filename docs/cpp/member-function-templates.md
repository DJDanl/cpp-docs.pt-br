---
title: "Modelos de fun&#231;&#227;o de membro | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "modelos de função, funções de membro"
ms.assetid: 83d51835-6a27-40ed-997c-7d90dc9182d8
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modelos de fun&#231;&#227;o de membro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O modelo de membro do termo se refere aos modelos da função de membro e modelos de classe aninhada.  Os modelos da função de membro são funções de modelo que são membros de uma classe ou de um modelo de classe.  Para obter mais informações, consulte [Modelos de classes aninhadas](../Topic/Nested%20Class%20Templates.md).  
  
 As funções de membro podem ser modelos de função em vários contextos.  Todas as funções de modelos da classe são genéricas, mas não são referidas como modelos de membros ou modelos da função de membro.  Se essas funções de membro usam seus próprios argumentos de modelo, são consideradas modelos da função de membro.  Para obter detalhes, consulte [Funções de membro de classes de modelo](../Topic/Member%20Functions%20of%20Template%20Classes.md).  
  
## Exemplo  
 Os modelos da função de membro de classes nontemplate ou de modelo são declarados como modelos de função com seus parâmetros de modelo.  
  
```  
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
  
## Exemplo  
 O exemplo a seguir mostra um modelo da função de membro de uma classe de modelo.  
  
```  
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
  
## Exemplo  
 Além disso, no Visual Studio .NET. 2003 e versões posteriores, os modelos de membro também podem ser definidos fora de uma classe.  
  
```  
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
  
## Exemplo  
 As classes locais não podem ter modelos de membro.  
  
 As funções de modelo do membro não podem ser funções virtuais e não podem substituir funções virtuais de uma classe base quando são declaradas com o mesmo nome que uma função virtual da classe base.  
  
 O Visual C\+\+ .NET 2003 introduziu o suporte a conversões definidas pelo usuário com modelo.  O exemplo a seguir funciona no Visual C\+\+ .NET 2003 conforme especificado no padrão.  
  
```  
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
  
## Consulte também  
 [Modelos de função](../cpp/function-templates.md)