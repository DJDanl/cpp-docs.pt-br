---
title: "Classe function | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "functional/std::tr1::function"
  - "std.tr1.function"
  - "std::tr1::function"
  - "function"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe function [TR1]"
ms.assetid: 7b5ca76b-9ca3-4d89-8fcf-cad70a4aeae6
caps.latest.revision: 26
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe function
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Wrapper para um objeto acessível.  
  
## Sintaxe  
  
```cpp  
template<class Fty>  
   class function  // Fty of type Ret(T1, T2, ..., TN)  
   : public unary_function<T1, Ret>       // when Fty is Ret(T1)  
   : public binary_function<T1, T2, Ret>  // when Fty is Ret(T1, T2)  
   {  
public:  
   typedef Ret result_type;  
  
   function();  
   function(nullptr_t);  
   function(const function& _Right);  
   template<class Fty2>  
      function(Fty2 fn);  
   template<class Fty2, class Alloc>  
       function (reference_wrapper<Fty2>, const Alloc& _Ax);  
   template<class Fty2, class Alloc>  
       void assign (Fty2, const Alloc& _Ax);  
   template<class Fty2, class Alloc>  
       assign (reference_wrapper<Fty2>, const Alloc& _Ax);  
```  
  
```cpp  
function& operator=(nullptr_t);  
function& operator=(const function&);  
template<class Fty2>  
   function& operator=(Fty2);  
template<class Fty2>  
   function& operator=(reference_wrapper<Fty2>);  
void swap(function&);  
  
explicit operator bool() const;  
result_type operator()(T1, T2, ....., TN) const;  
  
const std::type_info& target_type() const;  
template<class Fty2>  
   Fty2 *target();  
template<class Fty2>  
   const Fty2 *target() const;  
```  
  
```cpp  
   template<class Fty2>  
      void operator==(const Fty2&) const = delete;  
   template<class Fty2>  
      void operator!=(const Fty2&) const = delete;  
};  
```  
  
#### Parâmetros  
 `Fty`  
 O tipo de função a quebra de texto.  
  
 `_Ax`  
 A função do alocador.  
  
## Comentários  
 A classe do modelo é um wrapper de chamada cuja assinatura de chamada seja `Ret(T1, T2, ..., TN)`.  Use\-a para incluir uma variedade de objetos acessíveis em um wrapper uniforme.  
  
 Algumas funções de membro aceitam um operando que o nome do objeto de destino desejado.  Você pode especificar tal operando em várias formas:  
  
 `fn` \-\- o objeto acessível `fn`; depois da chamada do objeto `function` mantém uma cópia de `fn`  
  
 `fnref` \-\- o objeto acessível nomeada por `fnref.get()`; depois da chamada de `function` o objeto contém uma referência a `fnref.get()`  
  
 `right` \-\- o objeto acessível, se houver, mantido pelo objeto `right`de `function`  
  
 `npc` \-\- um ponteiro nulo; depois da chamada do objeto `function` está vazia  
  
 Em todos os casos, `INVOKE(f, t1, t2, ..., tN)`, onde é `f` o objeto acessível e `t1, t2, ..., tN` é lvalues dos tipos `T1, T2, ..., TN` respectivamente, deve bem formada e, se `Ret` não é nulo, convertido em `Ret`.  
  
 Um objeto vazio de `function` não mantém um objeto acessível ou uma referência a um objeto acessível.  
  
### Construtores  
  
|||  
|-|-|  
|[function::function](../Topic/function::function.md)|Constrói um wrapper que está vazio ou armazena um objeto acessível de tipo arbitrário com uma assinatura fixa.|  
  
### Typedefs  
  
|||  
|-|-|  
|[function::result\_type](../Topic/function::result_type.md)|O tipo de retorno do objeto acessível armazenado.|  
  
### Funções de membro  
  
|||  
|-|-|  
|[function::assign](../Topic/function::assign.md)|Atribui um objeto acessível para este objeto de função.|  
|[function::swap](../Topic/function::swap.md)|Troca dois objetos acessíveis.|  
|[function::target](../Topic/function::target.md)|Testa se o objeto acessível armazenado é acessível como especificado.|  
|[function::target\_type](../Topic/function::target_type.md)|Obtém as informações de tipo no objeto acessível.|  
  
### Operadores  
  
|||  
|-|-|  
|[function::operador não especificado](../Topic/function::operator%20unspecified.md)|Testa se o objeto acessível armazenado existir.|  
|[function::operator\(\)](../Topic/function::operator\(\).md)|Chama um objeto acessível.|  
|[function::operator\=](../Topic/function::operator=.md)|Substitui o objeto acessível armazenado.|  
  
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Função mem\_fn](../Topic/mem_fn%20Function.md)   
 [Classe reference\_wrapper](../Topic/reference_wrapper%20Class.md)