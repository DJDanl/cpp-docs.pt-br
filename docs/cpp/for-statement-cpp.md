---
title: "Instru&#231;&#227;o for (C++) | Microsoft Docs"
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
  - "palavra-chave for [C++]"
ms.assetid: 6c7d01b3-c4c1-4c6a-aa58-e2d198f33d4a
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o for (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Executa uma instrução repetidamente até que a condição se torne falsa.  Para obter informações sobre a instrução for com base em intervalo, consulte [Instrução for com base em intervalo \(C\+\+\)](../Topic/Range-based%20for%20Statement%20\(C++\).md).  
  
## Sintaxe  
  
```  
for ( init-expression ; cond-expression ; loop-expression )   
    statement;  
```  
  
## Comentários  
 Use a instrução `for` para construir loops que devem ser executados um número especificado de vezes.  
  
 A instrução `for` consiste em três partes opcionais, conforme mostrado na tabela a seguir.  
  
### Elementos loop "for"  
  
|Nome da sintaxe|Quando executado|Descrição|  
|---------------------|----------------------|---------------|  
|`init-expression`|Antes de qualquer outro elemento da instrução **for**, `init-expression` é executada apenas uma vez.  O controle passa para `cond-expression`.|Muitas vezes usado para inicializar índices de loop.  Ele pode conter expressões ou declarações.|  
|`cond-expression`|Antes da execução de cada iteração de `statement`, incluindo a primeira iteração.  `statement` será executado apenas se `cond-expression` for avaliado como verdadeiro \(diferente de zero\).|Uma expressão que é avaliada para um tipo integral ou um tipo de classe que tem uma conversão ambígua para um tipo integral.  Geralmente usado para testar critérios de encerramento de loop.|  
|`loop-expression`|No fim de cada iteração de `statement`.  Depois que `loop-expression` é executado, `cond-expression` é avaliado.|Geralmente usado para incrementar índices de loop.|  
  
 Os exemplos a seguir mostram diferentes maneiras de usar a instrução `for`.  
  
```cpp  
#include <iostream>  
using namespace std;  
  
int main() {  
    // The counter variable can be declared in the init-expression.  
    for (int i = 0; i < 2; i++ ){   
       cout << i;  
    }  
    // Output: 01  
    // The counter variable can be declared outside the for loop.  
    int i;  
    for (i = 0; i < 2; i++){  
        cout << i;  
    }  
    // Output: 01  
    // These for loops are the equivalent of a while loop.  
    i = 0;  
    while (i < 2){  
        cout << i++;  
    }  
}  
    // Output: 012  
```  
  
 `init-expression` e `loop-expression` podem conter várias instruções separadas por vírgulas.  Por exemplo:  
  
```cpp  
#include <iostream>  
using namespace std;  
  
int main(){  
    int i, j;  
    for ( i = 5, j = 10 ; i + j < 20; i++, j++ ) {  
        cout << "i + j = " << (i + j) << '\n';  
    }  
}  
    // Output:  
    i + j = 15  
    i + j = 17  
    i + j = 19  
```  
  
 `loop-expression` pode ser incrementado ou diminuído, ou modificado de outras maneiras.  
  
```cpp  
#include <iostream>  
using namespace std;  
  
int main(){  
for (int i = 10; i > 0; i--) {  
        cout << i << ' ';  
    }  
    // Output: 10 9 8 7 6 5 4 3 2 1  
    for (int i = 10; i < 20; i = i+2) {  
        cout << i << ' ';  
    }  
    // Output: 10 12 14 16 18  
```  
  
 Um loop `for` é finalizado quando um [break](../cpp/break-statement-cpp.md), [return](../Topic/return%20Statement%20\(C++\).md) ou [goto](../cpp/goto-statement-cpp.md) \(para uma instrução rotulada fora do loop **for**\) dentro de `statement` é executado.  Uma instrução [continue](../cpp/continue-statement-cpp.md) em um loop `for` finaliza apenas a iteração atual.  
  
 Se `cond-expression` for omitido, ele será considerado verdadeiro e o loop **for** não será finalizado sem um `break`, `return` ou `goto` dentro de `statement`.  
  
 Embora os três campos da instrução `for` normalmente sejam usados para inicialização, teste para finalização e incrementação, eles não são restritos a esses usos.  Por exemplo, o código a seguir imprime os número de 0 a 4.  Nesse caso, `statement` é a instrução null:  
  
```cpp  
#include <iostream>  
using namespace std;  
  
int main()  
{  
    int i;  
    for( i = 0; i < 5; cout << i << '\n', i++){  
        ;  
    }  
}  
```  
  
## para loops e o padrão C\+\+  
 O padrão C\+\+ informa que uma variável declarada em um loop `for` deverá sair do escopo depois que o loop `for` for encerrado.  Por exemplo:  
  
```cpp  
for (int i = 0 ; i < 5 ; i++) {  
   // do something  
}  
// i is now out of scope under /Za or /Zc:forScope  
```  
  
 Por padrão, em [\/Ze](../build/reference/za-ze-disable-language-extensions.md), uma variável declarada em um loop `for` permanece no escopo até que o escopo delimitador do loop `for` seja encerrado.  
  
 [\/Zc:forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) habilita o comportamento padrão de variáveis declaradas em loops for sem precisar especificar \/Za.  
  
 Também é possível usar as diferenças de escopo do loop `for` para declarar variáveis novamente em \/Ze, como se segue:  
  
```cpp  
// for_statement5.cpp  
int main(){  
   int i = 0;   // hidden by var with same name declared in for loop  
   for ( int i = 0 ; i < 3; i++ ) {}  
  
   for ( int i = 0 ; i < 3; i++ ) {}  
}  
```  
  
 Isso imita de modo mais aproximado o comportamento padrão de uma variável declarada em um loop `for`, que exige que as variáveis declaradas em um loop `for` saiam do escopo depois que o loop é realizado.  Quando uma variável é declarada em um loop `for`, o compilador a promove internamente a uma variável local no escopo delimitador do loop `for`, mesmo se já houver uma variável local com o mesmo nome.  
  
## Consulte também  
 [Instruções de iteração](../cpp/iteration-statements-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Instrução while \(C\+\+\)](../cpp/while-statement-cpp.md)   
 [Instrução do\-while \(C\+\+\)](../cpp/do-while-statement-cpp.md)   
 [Instrução for com base em intervalo \(C\+\+\)](../Topic/Range-based%20for%20Statement%20\(C++\).md)