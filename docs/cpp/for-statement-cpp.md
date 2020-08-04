---
title: instrução for (C++)
description: Referência à instrução C++ for Standard em Microsoft Visual Studio C++.
f1_keywords:
- for_cpp
ms.date: 07/31/2020
helpviewer_keywords:
- for keyword [C++]
ms.assetid: 6c7d01b3-c4c1-4c6a-aa58-e2d198f33d4a
ms.openlocfilehash: b32a50e376113f9f9d550d4984d05fc8c675f14d
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87520843"
---
# <a name="for-statement-c"></a>`for`instrução (C++)

Executa uma instrução repetidamente até que a condição se torne falsa. Para obter informações sobre a instrução baseada em intervalo **`for`** , consulte [demonstrativo baseado em intervalo `for` (C++)](../cpp/range-based-for-statement-cpp.md).

## <a name="syntax"></a>Sintaxe

> **`for (`** *`init-expression`* **`;`** *`cond-expression`* **`;`** *`loop-expression`* **`)`**\
> &emsp;*`statement`*

## <a name="remarks"></a>Comentários

Use a **`for`** instrução para construir loops que devem executar um número de vezes especificado.

A **`for`** instrução consiste em três partes opcionais, conforme mostrado na tabela a seguir.

### <a name="for-loop-elements"></a>elementos de loop for

| Nome da sintaxe | Quando executado | Descrição |
|--|--|--|
| *`init-expression`* | Antes de qualquer outro elemento da **`for`** instrução, *`init-expression`* é executado apenas uma vez. Em seguida, o controle passa para *`cond-expression`* . | Muitas vezes usado para inicializar índices de loop. Ele pode conter expressões ou declarações. |
| *`cond-expression`* | Antes da execução de cada iteração de *`statement`* , incluindo a primeira iteração. *`statement`* será executado somente se *`cond-expression`* for avaliado como true (diferente de zero). | Uma expressão que é avaliada para um tipo integral ou um tipo de classe que tem uma conversão ambígua para um tipo integral. Geralmente usado para testar critérios de encerramento de loop. |
| *`loop-expression`* | No final de cada iteração de *`statement`* . Após *`loop-expression`* ser executado, *`cond-expression`* é avaliado. | Geralmente usado para incrementar índices de loop. |

Os exemplos a seguir mostram diferentes maneiras de usar a **`for`** instrução.

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
    // Output: 01
}
```

*`init-expression`* e *`loop-expression`* pode conter várias instruções separadas por vírgulas. Por exemplo:

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

*`loop-expression`* pode ser incrementado ou diminuído ou modificado de outras maneiras.

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

Um **`for`** loop termina quando um [`break`](../cpp/break-statement-cpp.md) , [Return](../cpp/return-statement-cpp.md)ou [`goto`](../cpp/goto-statement-cpp.md) (para uma instrução rotulada fora do **`for`** loop) dentro *`statement`* é executado. Uma [`continue`](../cpp/continue-statement-cpp.md) instrução em um **`for`** loop encerra apenas a iteração atual.

Se *`cond-expression`* for omitido, ele será considerado **`true`** e o **`for`** loop não terminará sem um **`break`** , **`return`** ou **`goto`** dentro de *`statement`* .

Embora os três campos da **`for`** instrução sejam normalmente usados para inicialização, teste para encerramento e incrementos, eles não estão restritos a esses usos. Por exemplo, o código a seguir imprime os número de 0 a 4. Nesse caso, *`statement`* é a instrução NULL:

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

## <a name="for-loops-and-the-c-standard"></a>`for`loops e o C++ padrão

O padrão C++ diz que uma variável declarada em um **`for`** loop deve sair do escopo depois que o **`for`** loop termina. Por exemplo:

```cpp
for (int i = 0 ; i < 5 ; i++) {
   // do something
}
// i is now out of scope under /Za or /Zc:forScope
```

Por padrão, em [/ze](../build/reference/za-ze-disable-language-extensions.md), uma variável declarada em um **`for`** loop permanece no escopo até que o **`for`** escopo de delimitação do loop seja encerrado.

[/Zc: forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) habilita o comportamento padrão de variáveis declaradas em loops for sem a necessidade de especificar `/Za` .

Também é possível usar as diferenças de escopo do **`for`** loop para redeclarar as variáveis abaixo da seguinte `/Ze` maneira:

```cpp
// for_statement5.cpp
int main(){
   int i = 0;   // hidden by var with same name declared in for loop
   for ( int i = 0 ; i < 3; i++ ) {}

   for ( int i = 0 ; i < 3; i++ ) {}
}
```

Esse comportamento imita mais de forma semelhante o comportamento padrão de uma variável declarada em um **`for`** loop, que requer variáveis declaradas em um **`for`** loop para sair do escopo após a conclusão do loop. Quando uma variável é declarada em um **`for`** loop, o compilador a promove internamente a uma variável local no **`for`** escopo de delimitação do loop. Ele é promovido mesmo que já exista uma variável local com o mesmo nome.

## <a name="see-also"></a>Consulte também

[Instruções de iteração](../cpp/iteration-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[instrução while (C++)](../cpp/while-statement-cpp.md)<br/>
[instrução do-while (C++)](../cpp/do-while-statement-cpp.md)<br/>
[Instrução for com base em intervalo (C++)](../cpp/range-based-for-statement-cpp.md)
