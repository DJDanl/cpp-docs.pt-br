---
title: Operador stringizing (#)
ms.date: 08/29/2019
f1_keywords:
- '#'
helpviewer_keywords:
- preprocessor, operators
- arguments [C++], converting to strings
- stringizing operator
- preprocessor
- string literals, converting macro parameters to
- macros [C++], converting parameters to strings
- '# preprocessor operator'
ms.assetid: 1175dd19-4538-43b3-ad97-a008ab80e7b1
ms.openlocfilehash: 5a1b43198e59bc1e69cdf1b56db56be75719fe46
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216544"
---
# <a name="stringizing-operator-"></a>Operador stringizing (#)

O operador número-sinal ou "cadeia de caracteres" **#** () converte parâmetros de macro em literais de cadeia de caracteres sem expandir a definição de parâmetro. Ele é usado somente com macros que usam argumentos. Se ele preceder um parâmetro formal na definição da macro, o argumento real passado por invocação de macro é colocado entre em aspas e tratado como literal de cadeia de caracteres. O literal da cadeia de caracteres substitui cada ocorrência de uma combinação do operador stringizing e do parâmetro formal na definição da macro.

> [!NOTE]
> A extensão do Microsoft C (versões 6.0 e anteriores) para o padrão ANSI C, que anteriormente expandia os argumentos formais de macro que apareciam em literais de cadeias de caracteres e constantes de caracteres, não tem mais suporte. O código que dependa dessa extensão deve ser reescrito usando o operador de cadeia **#** de caracteres ().

O espaço em branco que precede o primeiro token e segue o último token do argumento real é ignorado. Todo o espaço em branco entre os tokens no argumento real é reduzido a um único espaço em branco no literal de cadeia de caracteres resultante. Portanto, se ocorrer um comentário entre dois tokens no argumento real, ele será reduzido para um único espaço em branco. O literal de cadeia de caracteres resultante é concatenado automaticamente com quaisquer literais de cadeia de caracteres adjacentes que são separados somente por espaços em branco.

Além disso, se um caractere contido no argumento geralmente exigir uma sequência de escape quando usado em um literal de cadeia de caracteres, por exemplo,`"`o caractere de aspas (`\`) ou de barra invertida (), a barra invertida de escape necessária será automaticamente inserido antes do caractere.

O operador C++ de cadeia de caracteres da Microsoft não se comporta corretamente quando é usado com cadeias de caracteres que incluem sequências de escape. Nessa situação, o compilador gera o [erro do compilador C2017](../error-messages/compiler-errors-1/compiler-error-c2017.md).

## <a name="examples"></a>Exemplos

O exemplo a seguir mostra uma definição de macro que inclui o operador de cadeia de caracteres e uma função principal que invoca a macro:

```cpp
// stringizer.cpp
#include <stdio.h>
#define stringer( x ) printf_s( #x "\n" )
int main() {
   stringer( In quotes in the printf function call );
   stringer( "In quotes when printed to the screen" );
   stringer( "This: \"  prints an escaped double quote" );
}
```

As `stringer` macros são expandidas durante o pré-processamento, produzindo o seguinte código:

```cpp
int main() {
   printf_s( "In quotes in the printf function call" "\n" );
   printf_s( "\"In quotes when printed to the screen\"" "\n" );
   printf_s( "\"This: \\\" prints an escaped double quote\"" "\n" );
}
```

```Output
In quotes in the printf function call
"In quotes when printed to the screen"
"This: \"  prints an escaped double quote"
```

O exemplo a seguir mostra como você pode expandir um parâmetro de macro:

```cpp
// stringizer_2.cpp
// compile with: /E
#define F abc
#define B def
#define FB(arg) #arg
#define FB1(arg) FB(arg)
FB(F B)
FB1(F B)
```

## <a name="see-also"></a>Consulte também

[Operadores de pré-processador](../preprocessor/preprocessor-operators.md)
