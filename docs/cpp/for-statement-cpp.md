---
title: Instrução for (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- for keyword [C++]
ms.assetid: 6c7d01b3-c4c1-4c6a-aa58-e2d198f33d4a
ms.openlocfilehash: e3dfdb45bdf8a508eca9d29e90b3f7c05e7b147d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179907"
---
# <a name="for-statement-c"></a>Instrução for (C++)

Executa uma instrução repetidamente até que a condição se torne falsa. Para obter informações sobre a instrução for baseada em intervalo, consulte [instrução for com base emC++intervalo ()](../cpp/range-based-for-statement-cpp.md).

## <a name="syntax"></a>Sintaxe

```
for ( init-expression ; cond-expression ; loop-expression )
    statement;
```

## <a name="remarks"></a>Comentários

Use a instrução **for** para construir loops que devem executar um número de vezes especificado.

A instrução **for** consiste em três partes opcionais, conforme mostrado na tabela a seguir.

### <a name="for-loop-elements"></a>Elementos loop "for"

|Nome da sintaxe|Quando executado|DESCRIÇÃO|
|-----------------|-------------------|-----------------|
|`init-expression`|Antes de qualquer outro elemento da instrução **for** , `init-expression` é executado apenas uma vez. O controle passa para `cond-expression`.|Muitas vezes usado para inicializar índices de loop. Ele pode conter expressões ou declarações.|
|`cond-expression`|Antes da execução de cada iteração de `statement`, incluindo a primeira iteração. `statement` será executado apenas se `cond-expression` for avaliado como verdadeiro (diferente de zero).|Uma expressão que é avaliada para um tipo integral ou um tipo de classe que tem uma conversão ambígua para um tipo integral. Geralmente usado para testar critérios de encerramento de loop.|
|`loop-expression`|No fim de cada iteração de `statement`. Depois que `loop-expression` é executado, `cond-expression` é avaliado.|Geralmente usado para incrementar índices de loop.|

Os exemplos a seguir mostram diferentes maneiras de usar a instrução **for** .

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

Um loop **for** termina quando um [Break](../cpp/break-statement-cpp.md), [Return](../cpp/return-statement-cpp.md)ou [goto](../cpp/goto-statement-cpp.md) (para uma instrução rotulada fora do loop **for** ) dentro de `statement` é executado. Uma instrução [continue](../cpp/continue-statement-cpp.md) em um loop **for** encerra apenas a iteração atual.

Se `cond-expression` for omitido, ele será considerado true e o loop **for** não será encerrado sem um **Break**, **return**ou **goto** dentro de `statement`.

Embora os três campos da instrução **for** normalmente são usados para inicialização, teste para encerramento e incrementos, eles não são restritos a esses usos. Por exemplo, o código a seguir imprime os número de 0 a 4. Nesse caso, `statement` é a instrução null:

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

O C++ padrão diz que uma variável declarada em um loop **for** deve sair do escopo depois que o loop **for** termina. Por exemplo:

```cpp
for (int i = 0 ; i < 5 ; i++) {
   // do something
}
// i is now out of scope under /Za or /Zc:forScope
```

Por padrão, em [/ze](../build/reference/za-ze-disable-language-extensions.md), uma variável declarada em um loop **for** permanece no escopo até o final do escopo de delimitação do loop **for** .

[/Zc: o forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) habilita o comportamento padrão das variáveis declaradas nos loops for sem a necessidade de especificar `/Za`.

Também é possível usar as diferenças de escopo do loop **for** para redeclarar variáveis em `/Ze` da seguinte maneira:

```cpp
// for_statement5.cpp
int main(){
   int i = 0;   // hidden by var with same name declared in for loop
   for ( int i = 0 ; i < 3; i++ ) {}

   for ( int i = 0 ; i < 3; i++ ) {}
}
```

Isso imita mais de forma semelhante o comportamento padrão de uma variável declarada em um loop **for** , que requer variáveis declaradas em um loop **for** para sair do escopo após a conclusão do loop. Quando uma variável é declarada em um loop **for** , o compilador a promove internamente a uma variável local no escopo de delimitação do loop **for** , mesmo que já exista uma variável local com o mesmo nome.

## <a name="see-also"></a>Confira também

[Instruções de iteração](../cpp/iteration-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução while (C++)](../cpp/while-statement-cpp.md)<br/>
[Instrução do-while (C++)](../cpp/do-while-statement-cpp.md)<br/>
[Instrução for baseada intervalo (C++)](../cpp/range-based-for-statement-cpp.md)
