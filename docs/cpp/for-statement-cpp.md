---
title: Instrução for (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- for keyword [C++]
ms.assetid: 6c7d01b3-c4c1-4c6a-aa58-e2d198f33d4a
ms.openlocfilehash: a6b1823fe93c45abd8dabbd22116924e0a64f19a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62154211"
---
# <a name="for-statement-c"></a>Instrução for (C++)

Executa uma instrução repetidamente até que a condição se torne falsa. Para obter informações sobre baseado em intervalo para a instrução, consulte [de instrução (C++) baseado em intervalo](../cpp/range-based-for-statement-cpp.md).

## <a name="syntax"></a>Sintaxe

```
for ( init-expression ; cond-expression ; loop-expression )
    statement;
```

## <a name="remarks"></a>Comentários

Use o **para** instrução para construir loops que devem ser executados um número de vezes especificado.

O **para** instrução consiste em três partes opcionais, conforme mostrado na tabela a seguir.

### <a name="for-loop-elements"></a>Elementos loop "for"

|Nome da sintaxe|Quando executado|Descrição|
|-----------------|-------------------|-----------------|
|`init-expression`|Antes de qualquer outro elemento do **para** instrução, `init-expression` é executado apenas uma vez. O controle passa para `cond-expression`.|Muitas vezes usado para inicializar índices de loop. Ele pode conter expressões ou declarações.|
|`cond-expression`|Antes da execução de cada iteração de `statement`, incluindo a primeira iteração. `statement` será executado apenas se `cond-expression` for avaliado como verdadeiro (diferente de zero).|Uma expressão que é avaliada para um tipo integral ou um tipo de classe que tem uma conversão ambígua para um tipo integral. Geralmente usado para testar critérios de encerramento de loop.|
|`loop-expression`|No fim de cada iteração de `statement`. Depois que `loop-expression` é executado, `cond-expression` é avaliado.|Geralmente usado para incrementar índices de loop.|

Os exemplos a seguir mostram diferentes maneiras de usar o **para** instrução.

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

Um **para** loop termina quando um [quebra](../cpp/break-statement-cpp.md), [retornar](../cpp/return-statement-cpp.md), ou [goto](../cpp/goto-statement-cpp.md) (para uma instrução rotulada fora o **para**loop) dentro do `statement` é executado. Um [continue](../cpp/continue-statement-cpp.md) instrução em um **para** loop termina apenas a iteração atual.

Se `cond-expression` for omitido, ele será considerado verdadeiro e o **para** loop não será encerrado sem um **quebra**, **retornar**, ou **goto** dentro do `statement`.

Embora os três campos do **para** instrução normalmente são usadas para inicialização, teste para finalização, e aumentando, eles não são restritos a esses usos. Por exemplo, o código a seguir imprime os número de 0 a 4. Nesse caso, `statement` é a instrução null:

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

O padrão C++ informa que uma variável declarada em um **para** loop deverá sair do escopo após a **para** loop termina. Por exemplo:

```cpp
for (int i = 0 ; i < 5 ; i++) {
   // do something
}
// i is now out of scope under /Za or /Zc:forScope
```

Por padrão, sob [/Ze](../build/reference/za-ze-disable-language-extensions.md), uma variável declarada em um **para** loop permanece no escopo até que o **para** término do escopo delimitador do loop.

[/ZC: forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) habilita o comportamento padrão de variáveis declaradas em loops for sem a necessidade de especificar `/Za`.

Também é possível usar as diferenças de escopo a **para** loop para declarar variáveis novamente em `/Ze` da seguinte maneira:

```cpp
// for_statement5.cpp
int main(){
   int i = 0;   // hidden by var with same name declared in for loop
   for ( int i = 0 ; i < 3; i++ ) {}

   for ( int i = 0 ; i < 3; i++ ) {}
}
```

Isso mais de perto imita o comportamento padrão de uma variável declarada em um **para** loop, o que exige que as variáveis declaradas em um **para** loop para sair do escopo depois que o loop é realizado. Quando uma variável é declarada em um **para** loop, o compilador a promove internamente a uma variável local na **para** escopo delimitador do loop, mesmo se já houver uma variável local com o mesmo nome.

## <a name="see-also"></a>Consulte também

[Instruções de iteração](../cpp/iteration-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução while (C++)](../cpp/while-statement-cpp.md)<br/>
[Instrução do-while (C++)](../cpp/do-while-statement-cpp.md)<br/>
[Instrução for baseada intervalo (C++)](../cpp/range-based-for-statement-cpp.md)