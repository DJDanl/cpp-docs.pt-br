---
title: Iteradores | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- iterator conventions
- C++ Standard Library, iterator conventions
ms.assetid: 2f746be7-b37d-4bfc-bf05-be4336ca982f
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: c0a9b850100d78a18e39e5cc552cb8461b3726a0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="iterators"></a>Iteradores
Um iterador é um objeto que pode iterar em elementos em um contêiner da Biblioteca Padrão do C++ e fornecer acesso a elementos individuais. Os contêineres da Biblioteca Padrão do C++ fornecem iteradores de modo que todos os algoritmos possam acessar seus elementos de maneira padrão sem precisar se preocupar com o tipo do contêiner em que os elementos estão armazenados.  
  
 Você pode usar iteradores explicitamente usando funções membro e globais, como begin() e end(), e operadores, como ++ e --, para avançar ou retroceder. Também é possível usar iteradores implicitamente com um loop range-for ou (para alguns tipos de iterador) o operador subscrito [].  
  
 Na Biblioteca Padrão do C++, o início de uma sequência ou intervalo é o primeiro elemento. O final de uma sequência ou intervalo sempre é definido como um após o último elemento. As funções globais começam e terminam iteradores de retorno para um contêiner especificado. O loop do iterador explícito típico sobre todos os elementos em um contêiner tem esta aparência:  
  
```  
 
vector<int> vec{ 0,1,2,3,4 };  
for (auto it = begin(vec);

it != end(vec);

it++)  
{  // Access element using dereference operator
    cout <<*it <<" ";  
}  
```  
  
 A mesma coisa pode ser feita de forma mais simples com um intervalo range-for:  
  
```  
for (auto num : vec)  
 {  // no deference operator
    cout <<num <<" ";  
 }  
```  
  
 Há cinco categorias de iteradores. Em ordem crescente de potência, as categorias são:  
  
- **Saída**. Um iterador de saída `X` pode iterar para frente em uma sequência usando o operador ++, e pode gravar um elemento apenas uma vez, usando o operador *.  
  
- **Entrada**. Um iterador de entrada `X` pode iterar para frente em uma sequência usando o operador ++, e pode ler um elemento quantas vezes forem necessárias usando o operador *. É possível comparar iteradores de entrada usando os operadores ++ e !=. Depois de você incrementar qualquer cópia de um iterador de entrada, nenhuma das outras cópias pode ser comparada, cancelada ou incrementada com segurança.  
  
- **Avanço**. Um iterador de avanço `X` pode iterar para frente em uma sequência usando o operador ++, e pode ler qualquer elemento ou gravar elementos não constantes quantas vezes forem necessárias usando o operador *. É possível acessar os membros do elemento usando o operador -> e comparar iteradores de avanço usando os operadores == e !=. Você pode fazer várias cópias de um iterador de avanço, cada uma das quais pode ser desreferenciada e incrementada de forma independente. Um iterador de avanço inicializado sem referência a nenhum contêiner é chamado de iterador de avanço nulo. Iteradores de avanço nulos sempre são comparados como iguais.  
  
-   Bidirecional. Um iterador bidirecional `X` pode tomar o lugar de um iterador de avanço. Você também pode, no entanto, decrementar um iterador bidirecional, como em --`X`, `X`-- ou (`V` = *`X`--). É possível acessar membros do elemento e comparar iteradores bidirecionais da mesma forma que ocorre com iteradores de avanço.  
  
- **Acesso aleatório**. Um iterador de acesso aleatório `X` pode tomar o lugar de um iterador bidirecional. Com um iterador de acesso aleatório, você pode usar o operador subscrito [] para acessar elementos. É possível usar os operadores +, -, += e -= para avançar ou retroceder um número especificado de elementos e para calcular a distância entre iteradores. Você pode comparar iteradores bidirecionais usando ==, !=, \<, >, \<= e >=.  
  
 Todos os iteradores podem ser atribuídos ou copiados. Eles são considerados objetos leves e geralmente são passados e retornados por valor, não por referência. Observe também que nenhuma das operações descritas anteriormente pode gerar uma exceção quando executada em um iterador válido.  
  
 A hierarquia das categorias de iterador pode ser resumida mostrando três sequências. Para acesso somente gravação a uma sequência, você pode usar qualquer um entre:  
  
```  
output iterator  
 -> forward iterator  
 -> bidirectional iterator  
 -> random-access iterator  
```  
  
 A seta para a direita significa "pode ser substituído por". Qualquer algoritmo que chama um iterador de saída deve funcionar bem com um iterador de avanço, por exemplo, mas *não* o oposto.  
  
 Para acesso somente leitura a uma sequência, você pode usar qualquer um entre:  
  
```  
input iterator  
 -> forward iterator  
 -> bidirectional iterator  
 -> random-access iterator  
```  
  
 Um iterador de entrada é a mais fraca de todas as categorias, nesse caso.  
  
 Por fim, para acesso de leitura/gravação a uma sequência, você pode usar qualquer um entre:  
  
```  
forward iterator  
 -> bidirectional iterator  
 -> random-access iterator  
```  
  
 Um ponteiro de objeto sempre pode servir como um iterador de acesso aleatório, de modo que ele pode servir como qualquer categoria de iterador se der suporte para o acesso de leitura/gravação adequado para a sequência que designa.  
  
 Um iterador `Iterator` diferente de um ponteiro de objeto também deve definir os tipos de membro exigidos pela especialização `iterator_traits<Iterator>`. Observe que esses requisitos podem ser atendidos derivando `Iterator` da classe base pública [iterator](../standard-library/iterator-struct.md).  
  
 É importante compreender as promessas e limitações de cada categoria de iterador para ver como os iteradores são usados por contêineres e algoritmos na Biblioteca Padrão do C++.  
  
> [!NOTE]
>  É possível evitar o uso de iteradores explicitamente usando loops range-for. Para obter mais informações, consulte [Loops (C++ moderno)](http://msdn.microsoft.com/en-us/b1b2779c-750e-4576-a514-a84178eae9da).  
  
 Visual C++ agora oferece iteradores verificados e depuração de iteradores para garantir que você não substituir os limites de seu contêiner. Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md) e [Suporte para iterador de depuração](../standard-library/debug-iterator-support.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

