---
title: Literal de cadeia de caracteres | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- string literals
- strings [C++], string literals
ms.assetid: 6d1fc3f8-0d58-4d68-9678-16b4f6dc4766
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: dd62f85b87473d1371daf2d2fa009d8620e59b57
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="string-literal"></a>Literal da cadeia de caracteres
A manipulação de cadeias de caracteres literais foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 Nas extensões gerenciadas para design de linguagem do C++, um literal de cadeia gerenciado foi indicado precedida a cadeia de caracteres literal com um `S`. Por exemplo:  
  
```  
String *ps1 = "hello";  
String *ps2 = S"goodbye";  
```  
  
 O desempenho de sobrecarga entre duas inicializações se torna não trivial, como a seguir CIL representação demonstra como visto pelo **ildasm**:  
  
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
  
 Que é um aumento notável apenas Lembre-se (ou aprendizado) para uma cadeia de caracteres literal de prefixo com um `S`. A nova sintaxe, a manipulação de literais de cadeia de caracteres é feita transparente, determinado pelo contexto de uso. O `S` não precisa ser especificado.  
  
 Como os casos em que precisamos explicitamente direcionam o compilador para interpretação de um ou outro? Nesses casos, podemos aplicar uma conversão explícita. Por exemplo:  
  
```  
f( safe_cast<String^>("ABC") );  
```  
  
 Além disso, a cadeia de caracteres literal agora corresponde a um `String` com uma conversão simple em vez de uma conversão padrão. Enquanto isso talvez não pareça muito altera a resolução de conjuntos de função sobrecarregada que incluem um `String` e um `const char*` como parâmetros formais concorrentes. A resolução de uma vez resolvido para um `const char*` instância agora está marcada como ambígua. Por exemplo:  
  
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
  
1.  A coleção de funções de candidato. As funções de candidato são os métodos de dentro do escopo que lexicalmente correspondem ao nome da função que está sendo invocado. Por exemplo, desde `f()` é invocado por meio de uma instância do `R`, todas as funções de chamada `f` que não são membros de `R` (ou de sua hierarquia de classe base) não são funções de candidato. Em nosso exemplo, há duas funções de candidato. Estas são as funções de membro de dois de `R` chamado `f`. Uma chamada falhar durante essa fase, se o conjunto de funções de candidato está vazio.  
  
2.  O conjunto de funções viáveis dentre as funções de candidato. Uma função viável é aquele que pode ser chamado com os argumentos especificados na chamada, dado o número de argumentos e seus tipos. Em nosso exemplo, ambas as funções de candidato também são funções viáveis. Uma chamada falhará durante essa fase, se o conjunto de funções viável está vazio.  
  
3.  Selecione a função que representa a melhor correspondência da chamada. Isso é feito pela classificação as conversões aplicadas para transformar os argumentos para o tipo dos parâmetros de função viável. Isso é relativamente simples com uma função de parâmetro único; ele se torna um pouco mais complexo quando há vários parâmetros. Uma chamada falhar durante essa fase, se não houver nenhuma correspondência melhor. Ou seja, se as conversões necessárias para transformar o tipo do argumento real para o tipo do parâmetro formal são igualmente boas. A chamada será sinalizada como ambígua.  
  
 No Managed Extensions, a resolução dessa chamada invocado o `const char*` instância como a melhor correspondência. Na sintaxe de novo, a conversão necessária corresponder `"abc"` para `const char*` e `String^` agora são equivalentes - ou seja, igualmente bom - e, portanto, a chamada será sinalizada como inválida - ou seja, como ambígua.  
  
 Isso nos leva a duas perguntas:  
  
-   O que é o tipo de argumento real, `"abc"`?  
  
-   O que é o algoritmo para determinar quando uma conversão de tipo é melhor do que outro?  
  
 O tipo de cadeia de caracteres literal `"abc"` é `const char[4]` -Lembre-se de que há um caractere de terminação nulo implícito ao final de cada cadeia de caracteres literal.  
  
 O algoritmo para determinar quando uma conversão de tipo é melhor do que outro envolve colocar as conversões de tipo possíveis em uma hierarquia. Aqui está o entendimento da hierarquia - essas conversões, obviamente, serão implícita. Usar uma notação de conversão explícita substitui a hierarquia semelhante ao modo parênteses substitui a precedência de operador normal de uma expressão.  
  
1.  Uma correspondência exata é melhor. Surpreendentemente, para um argumento para ser uma correspondência exata, ele não precisa corresponder exatamente ao tipo de parâmetro; ele só precisa ser o suficiente. Esta é a chave de entender o que está acontecendo neste exemplo e como o idioma foi alterado.  
  
2.  Uma promoção é melhor do que uma conversão padrão. Por exemplo, promovendo um `short int` para um `int` é melhor do que a conversão de um `int` em um `double`.  
  
3.  Uma conversão padrão é melhor do que uma conversão boxing. Por exemplo, converter um `int` em uma `double` é melhor boxing um `int` em um `Object`.  
  
4.  Uma conversão boxing é melhor do que uma conversão implícita definido pelo usuário. Por exemplo, conversão boxing um `int` em uma `Object` é melhor do que a aplicação de um operador de conversão de um `SmallInt` classe de valor.  
  
5.  Uma conversão implícita definida pelo usuário é melhor que nenhuma conversão. Uma conversão implícita definida pelo usuário é a última instrução de saída antes do erro (com a ressalva de que a assinatura formal pode conter uma matriz de parâmetro ou reticências naquela posição).  
  
 Portanto, o que significa dizer que uma correspondência exata não é necessariamente exatamente uma correspondência? Por exemplo, `const char[4]` corresponder exatamente a `const char*` ou `String^`, e ainda a ambiguidade do nosso exemplo entre duas correspondências exatas conflitantes!  
  
 Uma correspondência exata, quando isso acontece, inclui um número de conversões triviais. Há quatro conversões triviais em C++ ISO que podem ser aplicadas e ainda se qualificam como uma correspondência exata. Três são chamadas de transformações lvalue. Um quarto tipo é chamado de uma conversão de qualificação. As três transformações de lvalue são tratadas como uma melhor correspondência exata de uma necessidade de uma conversão de qualificação.  
  
 Uma forma de transformação lvalue é a conversão de matriz nativa de ponteiro. Este é o que está envolvido na correspondência de uma `const char[4]` para `const char*`. Portanto, a correspondência de `f("abc")` para `f(const char*)` é uma correspondência exata. A encarnação anteriores do nosso idioma, isso era a melhor correspondência, de fato.  
  
 Para o compilador sinalizador à chamada ambígua, portanto, requer que a conversão de um `const char[4]` para um `String^` também ser uma correspondência exata por meio de uma conversão trivial. Isso é a alteração que foi introduzida na nova versão de idioma. E é por isso a chamada agora está marcada como ambíguo.  
  
## <a name="see-also"></a>Consulte também  
 [Alterações gerais em linguagens (C + + CLI)](../dotnet/general-language-changes-cpp-cli.md)   
 [Cadeia de caracteres](../windows/string-cpp-component-extensions.md)