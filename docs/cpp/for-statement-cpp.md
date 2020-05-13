---
title: Instrução for (C++)
description: Referência ao Standard C++ para declaração no Microsoft Visual Studio C++.
f1_keywords:
- for_cpp
ms.date: 04/14/2020
helpviewer_keywords:
- for keyword [C++]
ms.assetid: 6c7d01b3-c4c1-4c6a-aa58-e2d198f33d4a
ms.openlocfilehash: 92f7ae4b1f2fbaaf710cd5a8739b78cb98a0accb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375392"
---
# <a name="for-statement-c"></a>Instrução for (C++)

Executa uma instrução repetidamente até que a condição se torne falsa. Para obter informações sobre a declaração baseada em intervalo, consulte ['C++' baseado em intervalo (C++)](../cpp/range-based-for-statement-cpp.md).

## <a name="syntax"></a>Sintaxe

> **`for (`***init-expression* **`;`** *cond-expression* **`;`** *loop-expression***`)`**\
> &nbsp;&nbsp;&nbsp;&nbsp;_Declaração_**`;`**

## <a name="remarks"></a>Comentários

Use a **declaração para** construir loops que devem executar um número especificado de vezes.

A **declaração para** declaração consiste em três partes opcionais, conforme mostrado na tabela a seguir.

### <a name="for-loop-elements"></a>Elementos loop "for"

|Nome da sintaxe|Quando executado|Descrição|
|-----------------|-------------------|-----------------|
|`init-expression`|Antes de qualquer outro elemento `init-expression` **da** declaração, é executado apenas uma vez. O controle passa para `cond-expression`.|Muitas vezes usado para inicializar índices de loop. Ele pode conter expressões ou declarações.|
|`cond-expression`|Antes da execução de cada iteração de `statement`, incluindo a primeira iteração. `statement` será executado apenas se `cond-expression` for avaliado como verdadeiro (diferente de zero).|Uma expressão que é avaliada para um tipo integral ou um tipo de classe que tem uma conversão ambígua para um tipo integral. Geralmente usado para testar critérios de encerramento de loop.|
|`loop-expression`|No fim de cada iteração de `statement`. Depois que `loop-expression` é executado, `cond-expression` é avaliado.|Geralmente usado para incrementar índices de loop.|

Os exemplos a seguir mostram maneiras diferentes de usar a **declaração.**

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

Um **loop para** termina quando uma [pausa,](../cpp/break-statement-cpp.md) [retorno](../cpp/return-statement-cpp.md)ou [goto](../cpp/goto-statement-cpp.md) (para uma `statement` declaração rotulada fora do loop **for)** dentro é executado. Uma declaração [de continuidade](../cpp/continue-statement-cpp.md) em um **loop** termina apenas a iteração atual.

Se `cond-expression` for omitido, `true`é considerado , e o loop **for** não terminará `statement`sem uma **pausa**, **retorno**ou **goto** dentro .

Embora os três campos da **declaração** sejam normalmente usados para inicialização, testes para rescisão e incrementamento, eles não estão restritos a esses usos. Por exemplo, o código a seguir imprime os número de 0 a 4. Nesse caso, `statement` é a instrução null:

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

O padrão C++ diz que uma variável declarada em um **loop para** obter deve sair do escopo após o término do loop **para.** Por exemplo:

```cpp
for (int i = 0 ; i < 5 ; i++) {
   // do something
}
// i is now out of scope under /Za or /Zc:forScope
```

Por padrão, em [/Ze](../build/reference/za-ze-disable-language-extensions.md), uma variável declarada em um **loop para** permanece no escopo até que o escopo de fechamento do loop **para** terminar.

[/Zc:forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) permite o comportamento padrão das variáveis declaradas em `/Za`loops sem a necessidade de especificar .

Também é possível usar as diferenças de **for** escopo do loop para `/Ze` redeclarar variáveis sob o seguinte:

```cpp
// for_statement5.cpp
int main(){
   int i = 0;   // hidden by var with same name declared in for loop
   for ( int i = 0 ; i < 3; i++ ) {}

   for ( int i = 0 ; i < 3; i++ ) {}
}
```

Esse comportamento imita mais de perto o comportamento padrão de uma variável declarada em um **loop para for,** que requer variáveis declaradas em um **loop para** sair do escopo após o loop ser feito. Quando uma variável é declarada em um loop **para** for, o compilador promove-a internamente a uma variável local no escopo de fechamento do loop **for.** É promovido mesmo que já haja uma variável local com o mesmo nome.

## <a name="see-also"></a>Confira também

[Instruções de iteração](../cpp/iteration-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[enquanto declaração (C++)](../cpp/while-statement-cpp.md)<br/>
[Instrução do-while (C++)](../cpp/do-while-statement-cpp.md)<br/>
[Instrução for com base em intervalo (C++)](../cpp/range-based-for-statement-cpp.md)
