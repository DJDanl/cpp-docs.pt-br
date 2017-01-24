---
title: "Literal da cadeia de caracteres | Microsoft Docs"
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
  - "literais String"
  - "cadeias de caracteres [C++], literais String"
ms.assetid: 6d1fc3f8-0d58-4d68-9678-16b4f6dc4766
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Literal da cadeia de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A manipulação de cadeias de caracteres literais foi alterada de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 Nas extensões gerenciadas para o design de linguagem C\+\+, uma literal de cadeia de caracteres gerenciada foi declarado prefaciando o literal da cadeia de caracteres com `S`.  Por exemplo:  
  
```  
String *ps1 = "hello";  
String *ps2 = S"goodbye";  
```  
  
 A sobrecarga de desempenho entre as duas inicializações de despejos não ser trivial, pois a representação de CIL seguir demonstra como **ildasm**completamente considerados:  
  
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
  
 Isso é aumento notáveis apenas para saber se lembrar de \(ou\) prefixar uma cadeia de caracteres literal com `S`.  Na nova sintaxe, manipulação de cadeias de caracteres literais é feita de maneira transparente, determinados pelo contexto de uso.  `S` não precisa ser especificado.  
  
 Que sobre os casos em que precisamos de direcionar explicitamente ao compilador uma interpretação ou outra?  Nesses casos, é aplicamos uma conversão explícita.  Por exemplo:  
  
```  
f( safe_cast<String^>("ABC") );  
```  
  
 Além disso, a cadeia literal agora corresponde a `String` com uma conversão simples em vez de uma conversão padrão.  Quando isso não pode soar como muito alterar a resolução dos conjuntos sobrecarregados de função que incluem `String` e `const char*` como parâmetros formais concorrentes.  A resolução que tiver resolvido uma vez a `const char*` uma instância é sinalizada agora como ambígua.  Por exemplo:  
  
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
  
 Por que há uma diferença?  Desde que mais de um `f` instância nomeada existe no programa, isso requer o algoritmo de resolução de sobrecarga da função ser aplicado à chamada.  A resolução formal de uma função de sobrecarga envolve três etapas.  
  
1.  A coleção de funções de candidato.  As funções de candidato são os métodos no escopo que correspondem léxica o nome da função que está sendo invocada.  Por exemplo, desde que `f()` é invocado por uma instância de `R`, todas as funções `f` nomeados que não são membros de `R` \(ou sua hierarquia da classe base\) não são candidato função.  Em nosso exemplo, há duas funções de candidato.  Estas são as duas funções de membro de `R` denominado `f`.  Uma chamada falha nessa fase se o conjunto da função de candidato está vazia.  
  
2.  O conjunto de funções entre viáveis de candidato funções.  Uma função é viável uma que pode ser invocada com os argumentos especificados na chamada, dado o número de argumentos e seus tipos.  Em nosso exemplo, ambas as funções de candidato também são funções viáveis.  Uma chamada falha nessa fase se o conjunto viável da função está vazia.  
  
3.  Selecione a função que representa a melhor correspondência de chamada.  Isso é feito para classificar as conversões aplicadas para transformar os argumentos para o tipo dos parâmetros viáveis da função.  Isso é relativamente simples com uma única função de parâmetro; se torna um pouco mais complexo quando há vários parâmetros.  Uma chamada falha nessa fase se não houver nenhuma melhor correspondência.  Ou seja, se as conversões necessárias para transformar o tipo de argumento real para o tipo do parâmetro formal são igualmente boas.  A chamada será sinalizada como ambígua.  
  
 Em extensões gerenciadas, a resolução dessa chamada invocou a instância de `const char*` como a melhor correspondência.  Na nova sintaxe, a conversão necessária para corresponder `"abc"` a `const char*` e `String^` agora são equivalentes \- ou seja, igualmente bom – e assim que a chamada será sinalizada como o ruim \- isto é, como ambígua.  
  
 Isso conduz\-nos a duas perguntas:  
  
-   Qual é o tipo de argumento real, `"abc"`?  
  
-   Que é o algoritmo para determinar quando uma conversão de tipo é melhor do que outra?  
  
 O tipo de literal de cadeia de caracteres `"abc"` é `const char[4]` – lembre\-se, há um caractere terminador nulo implícito ao final de cada cadeia literal.  
  
 O algoritmo para determinar quando uma conversão de tipo é melhor do que outra envolve colocar as conversões de tipos possíveis em uma hierarquia.  Eis uma compreensão dessa hierarquia – todas essas conversões, naturalmente, são implícitas.  Usando uma notação convertido explícita substitui a hierarquia semelhante ao modo como os parênteses substituem a precedência de operador habitual de uma expressão.  
  
1.  Uma correspondência exata é melhor.  Surpreendentemente, para que um argumento é uma correspondência exata, ele não precisa corresponder exatamente ao tipo de parâmetro; precisa apenas de ser bastante próximo.  Esta é a chave para entender o que está alternando adiante neste exemplo, e como o idioma foi alterado.  
  
2.  Uma promoção é melhor do que uma conversão padrão.  Por exemplo, promover `short int` a `int` é melhor que convertendo `int` em `double`.  
  
3.  Uma conversão padrão é melhor do que uma conversão de boxing.  Por exemplo, converter `int` em `double` é melhor que encaixotando `int` em `Object`.  
  
4.  Uma conversão de boxing é melhor do que uma conversão implícita definido pelo usuário.  Por exemplo, caso `int` em `Object` é melhor que aplicando um operador de conversão de uma classe do valor de `SmallInt` .  
  
5.  Uma conversão implícita definido pelo usuário é melhor que nenhuma conversão de todo.  Uma conversão implícita é definido pelo usuário a saída a última antes de erro \(aviso com a qual a assinatura formal pode conter uma matriz ou um sinal de reticências de param nessa posição.\)  
  
 Assim, o que significa saber que uma correspondência exata não é necessariamente uma correspondência exata?  Por exemplo, `const char[4]` não corresponder exatamente `const char*` ou `String^`no entanto, a ambiguidade de nosso exemplo está entre conflitantes dois correspondências exatas\!  
  
 Uma correspondência exata, como acontece, inclui um número de conversões triviais.  Há quatro conversões triviais em ISO\-C\+\+ que pode ser aplicado e ainda qualificado como uma correspondência exata.  Três são referenciados como transformações de lvalue.  Um quarto tipo é chamado uma conversão de qualificação.  As três transformações de lvalue são tratadas como um exato \- melhor correspondência que uma que requer uma conversão de qualificação.  
  
 Uma forma de transformação lvalue é a conversão de nativo\-matriz\-à\- ponteiro.  Este é o que está envolvido em correspondente `const char[4]` a `const char*`.  Consequentemente, a correspondência de `f("abc")` a `f(const char*)` é uma correspondência exata.  Em encarnações anteriores do nosso idioma, esta era a melhor correspondência, de fato.  
  
 Para que o compilador sinalize a chamada como ambígua, consequentemente, requer que a conversão de `const char[4]` a `String^` também é uma correspondência exata com uma conversão trivial.  Esta é a alteração que foi introduzida na nova versão do idioma.  E é por isso que a chamada será sinalizada agora como ambígua.  
  
## Consulte também  
 [Alteração geral em linguagens](../Topic/General%20Language%20Changes%20\(C++-CLI\).md)   
 [String](../windows/string-cpp-component-extensions.md)