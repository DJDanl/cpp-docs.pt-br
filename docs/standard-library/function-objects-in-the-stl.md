---
title: "Objetos de fun&#231;&#227;o no STL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "functores"
  - "Biblioteca C++ padrão, functors"
  - "Biblioteca C++ padrão, objetos de função"
  - "objetos de função"
ms.assetid: 85f8a735-2c7b-4f10-9c4d-95c666ec4192
caps.latest.revision: 6
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Objetos de fun&#231;&#227;o no STL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um *o objeto de função*, ou *functor*, é qualquer tipo que implementa Operator \(\). Esse operador é conhecido como o *operador de chamada* ou, às vezes, o *operador aplicativos*. A Standard Template Library usa objetos de função principalmente como critérios para contêineres e algoritmos de classificação.  
  
 Objetos de função fornecem duas vantagens principais em uma chamada de função diretamente. A primeira é que um objeto de função pode conter o estado. O segundo é que um objeto de função é um tipo e, portanto, pode ser usado como um parâmetro de modelo.  
  
## Criando um objeto de função  
 Para criar um objeto de função, crie um tipo e implemente Operator \(\), como:  
  
```  
class Functor  
{  
public:  
    int operator()(int a, int b)  
    {  
        return a < b;  
    }  
};  
  
int main()  
{  
    Functor f;  
    int a = 5;  
    int b = 7;  
    int ans = f(a, b);  
}  
```  
  
 A última linha do `main` função mostra como chamar o objeto de função. Essa chamada parece com uma chamada para uma função, mas na verdade está chamando Operator \(\) do tipo Functor. Essa semelhança entre um objeto de função e uma função de chamada é como o objeto de função do termo foi criado.  
  
## Contêineres e objetos de função  
 A Standard Template Library contém vários objetos de função no [\<functional\>](../standard-library/functional.md) arquivo de cabeçalho. Um uso desses objetos de função é como um critério de classificação para contêineres. Por exemplo, o `set` contêiner é declarado da seguinte maneira:  
  
```  
template <  
    class Key,  
    class Traits=less<Key>,  
    class Allocator=allocator<Key> >  
class set  
```  
  
 O segundo argumento de modelo é o objeto de função `less`. Esse objeto de função retorna `true` se o primeiro parâmetro passado para ele é menor que o segundo parâmetro passado. Como alguns contêineres classificam seus elementos, o contêiner precisa de uma forma de comparar dois elementos, e isso é feito usando o objeto de função. Você pode definir seus próprios critérios para contêineres de classificação criando um objeto de função e especificá\-la na lista de modelos para o contêiner.  
  
## Algoritmos e objetos de função  
 Outro uso de objetos funcionais é em algoritmos. Por exemplo, o `remove_if` algoritmo é declarado da seguinte maneira:  
  
```  
template<class ForwardIterator, class Predicate>  
    ForwardIterator remove_if(  
        ForwardIterator _First,  
        ForwardIterator _Last,  
        Predicate _Pred  
    );  
```  
  
 O último argumento para `remove_if` é um objeto de função que retorna um valor booliano \(um *predicado*\). Se o resultado do objeto de função for `true`, o elemento será removido do contêiner que está sendo acessado pelos iteradores `_First` e `_Last`. Você pode usar qualquer um dos objetos de função declarados no [\<functional\>](../standard-library/functional.md) cabeçalho para o argumento `_Pred` ou você pode criar seus próprios.  
  
## Consulte também  
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)