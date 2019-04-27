---
title: Operador stringizing (#)
ms.date: 11/04/2016
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
ms.openlocfilehash: 4f23eea017197ae1f984e097bb3967c1228fef09
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62179640"
---
# <a name="stringizing-operator-"></a>Operador stringizing (#)

O sinal de número ou o operador "stringizing" (**#**) converte parâmetros de macro em literais de cadeia de caracteres sem expandir a definição do parâmetro. É usado apenas com macros que aceitam argumentos. Se ele preceder um parâmetro formal na definição da macro, o argumento real passado por invocação de macro é colocado entre em aspas e tratado como literal de cadeia de caracteres. O literal da cadeia de caracteres substitui cada ocorrência de uma combinação do operador stringizing e do parâmetro formal na definição da macro.

> [!NOTE]
> A extensão do Microsoft C (versões 6.0 e anteriores) para o padrão ANSI C, que anteriormente expandia os argumentos formais de macro que apareciam em literais de cadeias de caracteres e constantes de caracteres, não tem mais suporte. Código que usava esta extensão deve ser reescrito usando o stringizing (**#**) operador.

O espaço em branco que precede o primeiro token do argumento real e depois do último token do argumento real é ignorado. Todo o espaço em branco entre os tokens no argumento real é reduzido a um único espaço em branco no literal de cadeia de caracteres resultante. Assim, se um comentário ocorrer entre dois tokens no argumento real, ele será reduzido a um único espaço em branco. O literal de cadeia de caracteres resultante é concatenada automaticamente com os literais de cadeia de caracteres adjacentes dos quais ele esteja separado apenas por espaço em branco.

Além disso, se um caractere contido no argumento geralmente requer uma sequência de escape quando usado em uma cadeia de caracteres literal (por exemplo, a marca de aspas (**"**) ou barra invertida (**\\**) caracteres), o barra invertida de escape necessária é automaticamente inserida antes do caractere.

O operador stringizing do Visual C++ não funcionar corretamente quando ele é usado com cadeias de caracteres que incluem as sequências de escape. Nessa situação, o compilador gera [erro do compilador C2017](../error-messages/compiler-errors-1/compiler-error-c2017.md).

## <a name="examples"></a>Exemplos

O exemplo a seguir mostra uma definição macro que inclui o operador stringizing e uma função main que invoca a macro:

Essas invocações seriam expandidas durante o pré-processamento, gerando o seguinte código:

```cpp
int main() {
   printf_s( "In quotes in the printf function call\n" "\n" );
   printf_s( "\"In quotes when printed to the screen\"\n" "\n" );
   printf_s( "\"This: \\\" prints an escaped double quote\"" "\n" );
}
```

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