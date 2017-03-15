---
title: "Retic&#234;ncias e modelos variadic | Microsoft Docs"
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
ms.assetid: f20967d9-c967-4fd2-b902-2bb1d5ed87e3
caps.latest.revision: 17
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Retic&#234;ncias e modelos variadic
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo mostra como usar reticências \(`...`\) com modelos variadic de C\+\+.  As reticências tiveram [muitos usos](../misc/ellipsis-dot-dot-dot.md) em C e C\+\+.  Eles incluem listas de argumentos variáveis para funções.  A função `printf()` da Biblioteca em Tempo de Execução C é um dos exemplos mais conhecidos.  
  
 Um *modelo variadic* é um modelo de classe ou função que oferece suporte a um número arbitrário de argumentos.  Esse mecanismo é útil principalmente para os desenvolvedores de biblioteca C\+\+, pois você pode aplicá\-lo a modelos de classe e modelos de função e, dessa forma, fornecer uma ampla variedade de funcionalidades e flexibilidade fortemente tipadas e não triviais.  
  
## Sintaxe  
 As reticências são usadas em duas maneiras por modelos variadic.  À esquerda do nome de parâmetro, elas significam um *pacote de parâmetros*, e à direita do nome de parâmetro, expandem os pacotes de parâmetro em nomes separados.  
  
 Eis um exemplo básico de sintaxe de definição de *classe de modelo variadic*:  
  
```cpp  
template<typename... Arguments> class classname;  
```  
  
 Para pacotes e expansões do parâmetro, você pode acrescentar espaço em branco em torno de reticências, com base em sua preferência, conforme mostrado nestes exemplos:  
  
```cpp  
template<typename ...Arguments> class classname;  
```  
  
 Ou isto:  
  
```cpp  
template<typename ... Arguments> class classname;  
```  
  
 Observe que este artigo usa a convenção que é mostrada no primeiro exemplo \(as reticências estão anexadas a `typename`\).  
  
 Nos exemplos anteriores, `Arguments` é um pacote de parâmetros.  A classe `classname` pode aceitar um número variável de argumentos, como nestes exemplos:  
  
```cpp  
  
template<typename... Arguments> class vtclass;  
  
vtclass< > vtinstance1;  
vtclass<int> vtinstance2;  
vtclass<float, bool> vtinstance3;  
vtclass<long, std::vector<int>, std::string> vtinstance4;  
  
```  
  
 Ao usar uma definição de classe de modelo variadic, você também pode requisitar pelo menos um parâmetro:  
  
```cpp  
template <typename First, typename... Rest> class classname;  
  
```  
  
 Eis um exemplo básico de sintaxe de *função de modelo variadic*:  
  
```cpp  
template <typename... Arguments> returntype functionname(Arguments... args);  
```  
  
 Então, o pacote de parâmetros `Arguments` é expandido para ser usado, conforme mostrado na próxima seção, **Compreensão dos modelos variadic**.  
  
 Outras formas de sintaxe de função de modelo variadic são possíveis, incluindo, mas não limitado a, esses exemplos:  
  
```cpp  
template <typename... Arguments> returntype functionname(Arguments&... args);   
template <typename... Arguments> returntype functionname(Arguments&&... args);  
template <typename... Arguments> returntype functionname(Arguments*... args);  
```  
  
 Especificadores como `const` também são permitidos:  
  
```cpp  
template <typename... Arguments> returntype functionname(const Arguments&... args);  
  
```  
  
 Tal como as definições de classe de modelo variadic, você pode criar funções que exigem ao menos um parâmetro:  
  
```cpp  
template <typename First, typename... Rest> returntype functionname(const First& first, const Rest&... args);  
  
```  
  
 Os modelos Variadic usam o operador `sizeof...()` \(não relacionado ao operador mais antigo `sizeof()`\):  
  
```cpp  
template<typename... Arguments>  
void tfunc(const Arguments&... args)  
{  
    const unsigned numargs = sizeof...(Arguments);  
  
    X xobj[numargs]; // array of some previously defined type X  
  
    helper_func(xobj, args...);  
}  
  
```  
  
## Mais sobre o posicionamento das reticências  
 Anteriormente, esse artigo descreveu a colocação de reticências que define pacotes e expansões de parâmetros como “à esquerda do nome do parâmetro, significa um pacote de parâmetros, e à direita do nome do parâmetro, expande os pacotes de parâmetros em nomes separados”.  Isso é tecnicamente verdade, mas pode ser uma tradução confusa do código.  Considere:  
  
-   Em a template\-parameter\-list \(`template <parameter-list>`\), `typename...` apresenta um pacote de parâmetros do modelo.  
  
-   Em uma parameter\-declaration\-clause \(`func(parameter-list)`\), as reticências “de nível superior” apresentam um pacote de parâmetro da função, e o posicionamento de reticências é importante:  
  
    ```cpp  
  
    // v1 is NOT a function parameter pack:  
    template <typename... Types> void func1(std::vector<Types...> v1);   
  
    // v2 IS a function parameter pack:  
    template <typename... Types> void func2(std::vector<Types>... v2);   
    ```  
  
-   Onde as reticências aparecem imediatamente após o nome de parâmetro, você tem uma expansão do pacote de parâmetros.  
  
## Exemplo  
 Uma boa maneira de ilustrar o mecanismo de função do modelo variadic é usá\-lo em uma reescritura de algumas das funcionalidades de `printf`:  
  
```cpp  
#include <iostream>  
  
using namespace std;  
  
void print() {  
    cout << endl;  
}  
  
template <typename T> void print(const T& t) {  
    cout << t << endl;  
}  
  
template <typename First, typename... Rest> void print(const First& first, const Rest&... rest) {  
    cout << first << ", ";  
    print(rest...); // recursive call using pack expansion syntax  
}  
  
int main()  
{  
    print(); // calls first overload, outputting only a newline  
    print(1); // calls second overload  
  
    // these call the third overload, the variadic template,   
    // which uses recursion as needed.  
    print(10, 20);  
    print(100, 200, 300);  
    print("first", 2, "third", 3.14159);  
}  
  
```  
  
## Saída  
  
```  
  
1  
10, 20  
100, 200, 300  
first, 2, third, 3.14159  
```  
  
> [!NOTE]
>  A maioria das implementações que incorporam funções de modelo variadic usa recursão de alguma maneira, mas ela é ligeiramente diferente da recursão tradicional. A recursão tradicional envolve uma função que chama a ela mesma usando a mesma assinatura. \(Ela pode ser sobrecarregada ou personalizada, mas a mesma assinatura é escolhida sempre.\) A recursão variadic envolve chamar um modelo de função variadic usando números diferentes \(quase sempre diminuindo\) de argumentos, e assim carimbando uma assinatura diferente todas as vezes.  Um “caso base” ainda é necessário, mas a natureza de recursão é diferente.  
  
## Consulte também  
 [Reticências \(...\)](../misc/ellipsis-dot-dot-dot.md)