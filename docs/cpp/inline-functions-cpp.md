---
title: "Funções embutidas (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __forceinline_cpp
- __inline_cpp
- inline_cpp
dev_langs:
- C++
helpviewer_keywords:
- inline functions [C++], class members
ms.assetid: 355f120c-2847-4608-ac04-8dda18ffe10c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: de370d8dbff1f1340539adc825f7f5316c59a468
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="inline-functions-c"></a>Funções embutidas (C++)
Uma função definida no corpo de uma declaração de classe é uma função embutida.  
  
## <a name="example"></a>Exemplo  
 Na seguinte declaração de classe, o construtor `Account` é uma função embutida. As funções de membro `GetBalance`, `Deposit`, e `Withdraw` não são especificados como **embutido** , mas podem ser implementados como funções embutidas.  
  
```  
// Inline_Member_Functions.cpp  
class Account  
{  
public:  
    Account(double initial_balance) { balance = initial_balance; }  
    double GetBalance();  
    double Deposit( double Amount );  
    double Withdraw( double Amount );  
private:  
    double balance;  
};  
  
inline double Account::GetBalance()  
{  
    return balance;  
}  
  
inline double Account::Deposit( double Amount )  
{  
    return ( balance += Amount );  
}  
  
inline double Account::Withdraw( double Amount )  
{  
    return ( balance -= Amount );  
}  
int main()  
{  
}  
```  
  
> [!NOTE]
>  Na declaração da classe, as funções foram declaradas sem o **embutido** palavra-chave. O **embutido** palavra-chave pode ser especificada na declaração da classe; o resultado é o mesmo.  
  
 Uma determinada função de membro embutida deve ser declarada da mesma maneira em cada unidade de compilação. Essa restrição faz com que as funções embutidas se comportem como se fossem funções instanciadas. Além disso, deve haver exatamente uma definição de uma função embutida.  
  
 Uma função de membro de classe padrão será a ligação externa, a menos que uma definição para essa função contém o **embutido** especificador. O exemplo anterior mostra que essas funções precisam não ser declaradas explicitamente com o **embutido** especificador; usando **embutido** na função de definição faz com que ele seja uma função embutida. No entanto, não é possível declarar novamente uma função como **embutido** após uma chamada para essa função.  
  
## <a name="inline-inline-and-forceinline"></a>Inline, inline, e \__forceinline  
 Os especificadores `inline` e `__inline` instruem o compilador a inserir uma cópia do corpo da função em cada local em que a função é chamada.  
  
 A inserção (chamada de expansão embutida ou inlining) só ocorrerá se a análise de custo/benefício do compilador demonstrar que ela será lucrativa. A expansão embutida reduz a sobrecarga da chamada de função sobre os possíveis custos de um código maior.  
  
 A palavra-chave `__forceinline` substitui a análise de custo/benefício e, em vez disso, se baseia na opinião do programador. Tenha cuidado ao usar `__forceinline`. A utilização indiscriminada de `__forceinline` pode resultar em código maior com ganhos de desempenho marginais apenas ou, em alguns casos, mesmo perdas de desempenho (devido ao aumento de paginação de um executável maior, por exemplo).  
  
 O uso das funções embutidas pode fazer com que seu programa seja mais rápido porque ele elimina a sobrecarga associada às chamadas de função. As funções com expansão embutida estão sujeitas a otimizações de código não disponíveis às funções normais.  
  
 O compilador trata as opções de expansão embutida e as palavras-chave como sugestões. Não há garantia de que as funções serão embutidas. Você não pode forçar o compilador a embutir uma função específica, mesmo com a palavra-chave `__forceinline`. Ao compilar com **/clr**, o compilador será não embutida uma função se houver atributos de segurança aplicados para a função.  
  
 O **embutido** palavra-chave está disponível somente em C++. As palavras-chave de `__inline` e `__forceinline` estão disponíveis em C e C++. Para compatibilidade com versões anteriores, **_inline** é um sinônimo para `__inline`.  
  
 O **embutido** palavra-chave informa ao compilador que a expressão embutida é preferencial. No entanto, o compilador pode criar uma instância separada da função (uma instância) e criar vínculos de chamada padrão em vez de inserir o código embutido. Os dois casos em que isso pode acontecer são:  
  
-   Funções recursivas.  
  
-   Funções às quais são feita referência por meio de um ponteiro em outro lugar na unidade de tradução.  
  
 Esses motivos podem interferir com inlining, *como talvez outros*, a critério do compilador; você não deve depender de **embutido** especificador para fazer com que uma função a ser embutido.  
  
 Como ocorre com funções normais, não há ordem definida de avaliação dos argumentos para uma função embutida. De fato, ela pode ser diferente da ordem na qual os argumentos são avaliados quando passados usando o protocolo comum de chamada de função.  
  
 O [/Ob](../build/reference/ob-inline-function-expansion.md) opção do compilador otimização ajuda a determinar se a expressão de função embutida realmente ocorre.  
  
 [/LTCG](../build/reference/ltcg-link-time-code-generation.md) executa entre módulos cruzados, independentemente se ele foi solicitado no código-fonte.  
  
### <a name="example-1"></a>Exemplo 1  
  
```  
// inline_keyword1.cpp  
// compile with: /c  
inline int max( int a , int b ) {  
   if( a > b )   
      return a;  
   return b;  
}  
```  
  
 Funções de membro da classe podem ser declaradas em linha usando o **embutido** palavra-chave ou colocando-se a definição da função na definição de classe.  
  
### <a name="example-2"></a>Exemplo 2  
  
```  
// inline_keyword2.cpp  
// compile with: /EHsc /c  
#include <iostream>  
using namespace std;  
  
class MyClass {  
public:  
   void print() { cout << i << ' '; }   // Implicitly inline  
private:  
   int i;  
};  
```  
  
### <a name="microsoft-specific"></a>Específico da Microsoft  
 O `__inline` palavra-chave é equivalente a **embutido**.  
  
 Mesmo com `__forceinline`, o compilador não pode embutir código em todas as circunstâncias. O compilador não pode embutir uma função se:  
  
-   A função ou o chamador forem compilados com /Ob0 (a opção padrão para compilações de depuração).  
  
-   A função e o chamador usam tipos diferentes de manipulação de exceções (manipulação de exceções do C++ em uma, manipulação de exceções estruturada no outro).  
  
-   A função tem uma lista de argumentos variável.  
  
-   A função usa o assembly embutido, a menos que compilada com /Og, /Ox, /O1 ou /O2.  
  
-   A função é recursiva e não são acompanhados por **#pragma inline_recursion(on)**. Com o pragma, as funções recursivas são embutidas em uma profundidade padrão de 16 chamadas. Para reduzir a profundidade de inlining, use [inline_depth](../preprocessor/inline-depth.md) pragma.  
  
-   A função é virtual e é chamada virtualmente. Chamadas diretas à funções virtuais podem ser embutidas.  
  
-   O programa usa o endereço da função e a chamada à função é feita pelo ponteiro. Chamadas diretas a funções que tiveram o endereço removido podem ser embutidas.  
  
-   A função também está marcada com o [naked](../cpp/naked-cpp.md) [declspec](../cpp/declspec.md) modificador.  
  
 Se o compilador não pode embutido uma função declarada com `__forceinline`, ele gera um aviso de nível 1, exceto quando:
  
-   A função é compilada usando /Od ou /Ob0. Não inlining é esperado nesses casos.     
  
-   A função é definida externamente, em uma biblioteca incluída ou outra unidade de tradução, ou é um destino de chamada virtual ou o destino de chamada indireta. O compilador não pode identificar o código não embutida que não foi encontrado na unidade de tradução atual.  
  
 Funções recursivas podem ser substituída embutida para uma profundidade especificada pelo [inline_depth](../preprocessor/inline-depth.md) pragma, até um máximo de 16 chamadas. Após essa profundidade, as chamadas de função recursivas são tratadas como chamadas a uma instância da função.  A profundidade até a qual as funções recursivas são examinadas por heurística embutida não pode exceder 16. O [inline_recursion](../preprocessor/inline-recursion.md) pragma controla a expansão embutida de uma função atualmente em expansão. Consulte o [expansão de função embutida](../build/reference/ob-inline-function-expansion.md) (/ Ob) a opção de compilador para obter informações relacionadas.  
  
**Fim da seção específica da Microsoft**  
 Para obter mais informações sobre como usar o **embutido** especificador, consulte:  
  
-   [Funções de membro de classe embutida](../cpp/inline-functions-cpp.md)  
  
-   [Definindo funções C++ embutidas com dllexport e dllimport](../cpp/defining-inline-cpp-functions-with-dllexport-and-dllimport.md)  
  
## <a name="when-to-use-inline-functions"></a>Quando usar funções embutidas  
 As funções embutidas são usadas da melhor forma para funções pequenas, como acessar membros de dados particulares. A principal finalidade dessas funções de acesso de uma ou duas linhas é retornar informações de estado sobre objetos; as funções curtas são sensíveis à sobrecarga das chamadas de função. As funções mais longas proporcionalmente passam menos tempo na sequência de chamadas/retornos e se beneficiam menos do processo de embutir.  
  
 Um `Point` classe pode ser definida da seguinte maneira:  
  
```  
// when_to_use_inline_functions.cpp  
class Point  
{  
public:  
    // Define "accessor" functions as  
    //  reference types.  
    unsigned& x();  
    unsigned& y();  
private:  
    unsigned _x;  
    unsigned _y;  
};  
  
inline unsigned& Point::x()  
{  
    return _x;  
}  
inline unsigned& Point::y()  
{  
    return _y;  
}  
int main()  
{  
}  
```  
  
 Supondo que a manipulação de coordenadas é uma operação relativamente comum em um cliente de tal classe, especificando as duas funções do acessador (`x` e `y` no exemplo anterior) como **embutido** normalmente salva o sobrecarga em:  
  
-   Chamadas de função (inclusive passagem de parâmetros e colocação do endereço do objeto na pilha)  
  
-   Preservação do registro de ativação do chamador  
  
-   Configuração do novo registro de ativação  
  
-   Comunicação do valor de retorno  
  
-   Restauração do registro de ativação antigo  
  
-   Valor de  
  
## <a name="inline-functions-vs-macros"></a>Funções embutidas versus macros  
 Embora as funções integradas sejam semelhantes a macros (porque o código da função é expandido no ponto de chamada em tempo de compilação), as funções integradas são analisadas pelo compilador, enquanto que as macros são expandidas pelo pré-processador. Como resultado, há várias diferenças importantes:  
  
-   As funções integradas seguem todos os protocolos de segurança de tipo impostos em funções normais.  
  
-   Funções embutidas são especificadas usando a mesma sintaxe como qualquer outra função, exceto pelo fato de que elas incluam o **embutido** palavra-chave na declaração da função.  
  
-   As expressões transmitidas como argumentos para as funções integradas são avaliadas uma única vez. Em alguns casos, as expressões transmitidas como argumentos para macros podem ser avaliadas mais de uma vez.  
  
 O exemplo a seguir mostra uma macro que converte letras minúsculas em maiúsculas:  
  
```  
// inline_functions_macro.c  
#include <stdio.h>  
#include <conio.h>  
  
#define toupper(a) ((a) >= 'a' && ((a) <= 'z') ? ((a)-('a'-'A')):(a))  
  
int main() {  
   char ch;  
   printf_s("Enter a character: ");  
   ch = toupper( getc(stdin) );  
   printf_s( "%c", ch );  
}  
//  Sample Input:  xyz  
// Sample Output:  Z  
  
```  
  
 A intenção da expressão `toupper(getc(stdin))` que um caractere deve ser lido a partir do dispositivo do console (`stdin`) e, se necessário, convertida em maiusculas.  
  
 Devido à implementação da macro, `getc` é executado uma vez para determinar se o caractere é maior que ou igual a "a" e para determinar uma vez se ele é menor ou igual a "Z". Se estiver nesse intervalo, `getc` será executado novamente para converter o caractere para letras maiúsculas. Isso significa que o programa espera por dois ou três caracteres quando, de modo ideal, ele deve esperar apenas um.  
  
 As funções integradas corrigem o problema descrito anteriormente:  
  
```  
// inline_functions_inline.cpp  
#include <stdio.h>  
#include <conio.h>  
  
inline char toupper( char a ) {  
   return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );  
}  
  
int main() {  
   printf_s("Enter a character: ");  
   char ch = toupper( getc(stdin) );  
   printf_s( "%c", ch );  
}  
```  
  
```Output  
Sample Input: a  
Sample Output: A  
```  
  
## <a name="see-also"></a>Consulte também  
 [noinline](../cpp/noinline.md)   
 [auto_inline](../preprocessor/auto-inline.md)