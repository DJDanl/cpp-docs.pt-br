---
title: Literal de cadeia de caracteres | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- string literals
- strings [C++], string literals
ms.assetid: 6d1fc3f8-0d58-4d68-9678-16b4f6dc4766
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 41f1996cd4f4caf24ac08d09b05e636cb09f7eed
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46415259"
---
# <a name="string-literal"></a>Literal da cadeia de caracteres

A manipulação de literais de cadeia de caracteres foi alterado de extensões gerenciadas para C++ para Visual C++.

Nas extensões gerenciadas para design de linguagem C++, um literal de cadeia gerenciada foi indicado ao preceder a cadeia de caracteres literal com um `S`. Por exemplo:

```
String *ps1 = "hello";
String *ps2 = S"goodbye";
```

O desempenho sobrecarga entre as duas inicializações acaba sendo triviais, como a seguir CIL representação demonstra como visto pelo **ildasm**:

```
// String *ps1 = "hello";
ldsflda    valuetype $ArrayType$0xd61117dd
     modopt([Microsoft.VisualC]Microsoft.VisualC.IsConstModifier)
     '?A0xbdde7aca.unnamed-global-0'

newobj instance void [mscorlib]System.String::.ctor(int8*)
stloc.0

// String *ps2 = S"goodbye";
ldstr      "goodbye"
stloc.0
```

Que é uma economia notável para apenas lembrando (ou aprendizado) para uma cadeia de caracteres literal de prefixo com um `S`. Na nova sintaxe, a manipulação de literais de cadeia de caracteres é feita transparente, determinado pelo contexto de uso. O `S` não precisa ser especificado.

O que dizer sobre casos em que precisamos explicitamente direcionam o compilador a interpretação de um ou outro? Nesses casos, podemos aplicar uma conversão explícita. Por exemplo:

```
f( safe_cast<String^>("ABC") );
```

Além disso, o literal de cadeia de caracteres agora corresponde um `String` com uma conversão simple em vez de uma conversão padrão. Embora isso talvez não pareça muito ele altera a resolução de conjuntos de função sobrecarregada que incluem uma `String` e um `const char*` como concorrentes parâmetros formais. A resolução de uma vez é resolvido para um `const char*` instância agora está marcada como ambígua. Por exemplo:

```
ref struct R {
   void f(const char*);
   void f(String^);
};

int main () {
   R r;
   // old syntax: f( const char* );
   // new syntax: error: ambiguous
   r.f("ABC"); 
}
```

Por que há uma diferença? Desde que mais de uma instância nomeada `f` existe dentro do programa, isso requer que o algoritmo de resolução de sobrecarga de função a ser aplicado à chamada. A resolução formal de uma função de sobrecarga envolve três etapas.

1. A coleção das funções de candidato. As funções de candidato são os métodos dentro do escopo que lexicalmente corresponder ao nome da função que está sendo invocado. Por exemplo, desde `f()` é invocado por meio de uma instância do `R`, todas as funções nomeadas `f` que não são membros de `R` (ou de sua hierarquia de classe base) não são funções candidatas. Em nosso exemplo, há duas funções de candidato. Essas são as duas funções membro de `R` chamado `f`. Uma chamada falha durante essa fase se o conjunto de funções de candidato está vazio.

1. O conjunto de funções viáveis dentre as funções de candidato. Uma função viável é aquele que pode ser chamado com os argumentos especificados na chamada, dado o número de argumentos e seus tipos. Em nosso exemplo, ambas as funções de candidato também são funções viáveis. Uma chamada falha durante essa fase se o conjunto de funções viável estiver vazio.

1. Selecione a função que representa a melhor correspondência da chamada. Isso é feito por classificação as conversões de aplicado para transformar os argumentos para o tipo dos parâmetros de função viável. Isso é relativamente simples com uma função de parâmetro único; ele se torna um pouco mais complexo quando houver vários parâmetros. Uma chamada falha durante essa fase se não houver nenhuma correspondência melhor. Ou seja, se as conversões necessárias para transformar o tipo do argumento real para o tipo do parâmetro formal são igualmente boas. A chamada é sinalizada como ambígua.

Nas extensões gerenciadas, a resolução dessa chamada invocado o `const char*` instância como a melhor correspondência. Na nova sintaxe, a conversão necessária corresponder `"abc"` à `const char*` e `String^` agora são equivalentes – ou seja, igualmente bom - e, portanto, a chamada é sinalizada como inválida - ou seja, como ambígua.

Isso nos leva a duas perguntas:

- Qual é o tipo do argumento real, `"abc"`?

- O que é o algoritmo para determinar quando uma conversão de tipos é melhor do que o outro?

O tipo de cadeia de caracteres literal `"abc"` é `const char[4]` -Lembre-se de que há um caractere de terminação nulo implícito no final de cada cadeia de caracteres literal.

O algoritmo para determinar quando uma conversão de tipos é melhor do que o outro envolve colocar as conversões de tipo possíveis em uma hierarquia. Aqui está minha compreensão dessa hierarquia - essas conversões, é claro, são implícitas. Usar uma notação de conversão explícita substitui a hierarquia de forma semelhante a como parênteses substitui a precedência de operador normal de uma expressão.

1. Uma correspondência exata é melhor. Surpreendentemente, para um argumento para ser uma correspondência exata, ele não precisa corresponder exatamente ao tipo de parâmetro; ele precisa ser próxima o suficiente. Esta é a chave para entender o que está acontecendo neste exemplo, e como o idioma foi alterada.

1. Uma promoção é melhor do que uma conversão padrão. Por exemplo, promover uma `short int` para um `int` é melhor do que a conversão de um `int` em um `double`.

1. Uma conversão padrão é melhor do que uma conversão boxing. Por exemplo, converter um `int` em um `double` é melhor que, conversão boxing um `int` em um `Object`.

1. Uma conversão boxing é melhor do que uma conversão implícita definidas pelo usuário. Por exemplo, conversão boxing de um `int` em um `Object` é melhor do que a aplicação de um operador de conversão de um `SmallInt` classe de valor.

1. Uma conversão implícita definida pelo usuário é melhor do que nenhuma conversão. Uma conversão implícita definida pelo usuário é a última instrução de saída antes do erro (com a ressalva de que a assinatura formal pode conter uma matriz de parâmetros ou reticências naquela posição).

Portanto, o que significa dizer que uma correspondência exata não é necessariamente exatamente uma correspondência? Por exemplo, `const char[4]` corresponder exatamente a um `const char*` ou `String^`, e ainda a ambiguidade de nosso exemplo é entre duas correspondências exatas conflitantes!

Uma correspondência exata, quando isso acontece, inclui um número de conversões triviais. Há quatro conversões triviais em ISO-c que podem ser aplicadas e ainda são válidas como uma correspondência exata. Três são chamados de transformações de lvalue. Um quarto tipo é chamado de uma conversão de qualificação. As três transformações de lvalue são tratadas como uma melhor correspondência exata de uma necessidade de uma conversão de qualificação.

Uma forma de transformação lvalue é a conversão de matriz nativa de ponteiro. Esse é o que está envolvido na correspondência de uma `const char[4]` para `const char*`. Portanto, a correspondência de `f("abc")` para `f(const char*)` é uma correspondência exata. As versões anteriores da nossa linguagem, fui a melhor correspondência, de fato.

Para o compilador sinalizar a chamada como ambígua, portanto, requer que a conversão de um `const char[4]` para um `String^` também ser uma correspondência exata por meio de uma conversão trivial. Essa é a alteração que foi introduzida na nova versão de idioma. E é por isso a chamada agora está marcada como ambíguo.

## <a name="see-also"></a>Consulte também

[Alterações gerais na linguagem (C++/CLI)](../dotnet/general-language-changes-cpp-cli.md)<br/>
[Cadeia de caracteres](../windows/string-cpp-component-extensions.md)