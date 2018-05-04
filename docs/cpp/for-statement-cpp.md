---
title: Instrução for (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- for keyword [C++]
ms.assetid: 6c7d01b3-c4c1-4c6a-aa58-e2d198f33d4a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 38181a43134c35c4db1db3d78a79d3338934b7d2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="for-statement-c"></a>Instrução for (C++)
Executa uma instrução repetidamente até que a condição se torne falsa. Para obter informações sobre o intervalo baseado em instrução, consulte [com base em intervalo de instrução (C++)](../cpp/range-based-for-statement-cpp.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
for ( init-expression ; cond-expression ; loop-expression )   
    statement;  
```  
  
## <a name="remarks"></a>Comentários  
 Use a instrução `for` para construir loops que devem ser executados um número especificado de vezes.  
  
 A instrução `for` consiste em três partes opcionais, conforme mostrado na tabela a seguir.  
  
### <a name="for-loop-elements"></a>Elementos loop "for"  
  
|Nome da sintaxe|Quando executado|Descrição|  
|-----------------|-------------------|-----------------|  
|`init-expression`|Antes de qualquer outro elemento do **para** instrução, `init-expression` é executado apenas uma vez. O controle passa para `cond-expression`.|Muitas vezes usado para inicializar índices de loop. Ele pode conter expressões ou declarações.|  
|`cond-expression`|Antes da execução de cada iteração de `statement`, incluindo a primeira iteração. `statement` será executado apenas se `cond-expression` for avaliado como verdadeiro (diferente de zero).|Uma expressão que é avaliada para um tipo integral ou um tipo de classe que tem uma conversão ambígua para um tipo integral. Geralmente usado para testar critérios de encerramento de loop.|  
|`loop-expression`|No fim de cada iteração de `statement`. Depois que `loop-expression` é executado, `cond-expression` é avaliado.|Geralmente usado para incrementar índices de loop.|  
  
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
  
 `init-expression` e `loop-expression` podem conter várias instruções separadas por vírgulas. Por exemplo:  
  
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
  
 Um `for` loop será encerrado quando uma [quebra](../cpp/break-statement-cpp.md), [retornar](../cpp/return-statement-cpp.md), ou [goto](../cpp/goto-statement-cpp.md) (para uma instrução rotulada fora o **para** loop) em `statement` é executado. Um [continuar](../cpp/continue-statement-cpp.md) instrução em um `for` loop finaliza somente a iteração atual.  
  
 Se `cond-expression` é omitido, ele será considerado true e o **para** loop não será encerrado sem um `break`, `return`, ou `goto` em `statement`.  
  
 Embora os três campos da instrução `for` normalmente sejam usados para inicialização, teste para finalização e incrementação, eles não são restritos a esses usos. Por exemplo, o código a seguir imprime os número de 0 a 4. Nesse caso, `statement` é a instrução null:  
  
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
  
## <a name="for-loops-and-the-c-standard"></a>para loops e o padrão C++  
 O padrão C++ informa que uma variável declarada em um loop `for` deverá sair do escopo depois que o loop `for` for encerrado. Por exemplo:  
  
```cpp  
for (int i = 0 ; i < 5 ; i++) {  
   // do something  
}  
// i is now out of scope under /Za or /Zc:forScope  
```  
  
 Por padrão, em [/Ze](../build/reference/za-ze-disable-language-extensions.md), uma variável declarada em um `for` loop permanece em escopo até que o `for` loop do delimitador escopo termina.  
  
 [/ZC: forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) permite que o comportamento padrão de variáveis declaradas em loops sem a necessidade de especificar /Za.  
  
 Também é possível usar as diferenças de escopo do loop `for` para declarar variáveis novamente em /Ze, como se segue:  
  
```cpp  
// for_statement5.cpp  
int main(){  
   int i = 0;   // hidden by var with same name declared in for loop  
   for ( int i = 0 ; i < 3; i++ ) {}  
  
   for ( int i = 0 ; i < 3; i++ ) {}  
}  
```  
  
 Isso imita de modo mais aproximado o comportamento padrão de uma variável declarada em um loop `for`, que exige que as variáveis declaradas em um loop `for` saiam do escopo depois que o loop é realizado. Quando uma variável é declarada em um loop `for`, o compilador a promove internamente a uma variável local no escopo delimitador do loop `for`, mesmo se já houver uma variável local com o mesmo nome.  
  
## <a name="see-also"></a>Consulte também  
 [Instruções de Iteração](../cpp/iteration-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Instrução while (C++)](../cpp/while-statement-cpp.md)   
 [Instrução do-while (C++)](../cpp/do-while-statement-cpp.md)   
 [Instrução for baseada intervalo (C++)](../cpp/range-based-for-statement-cpp.md)