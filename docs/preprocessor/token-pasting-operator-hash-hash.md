---
title: Operador token-pasting (##)
ms.date: 08/29/2019
f1_keywords:
- '##'
helpviewer_keywords:
- preprocessor, operators
- '## preprocessor operator'
ms.assetid: 4f173503-990f-4bff-aef3-ec4d1f1458ef
ms.openlocfilehash: 4bf1b8c8f56ab9375503c9e8fb6a906706fc70bb
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218108"
---
# <a name="token-pasting-operator-"></a>Operador token-pasting (##)

O sinal de número duplo ou operador *de colagem* de tokens ( **##** ), que às vezes é chamado de operador de *mesclagem* ou de *combinação* , é usado em macros semelhantes ao objeto e à função. Ele permite que tokens separados sejam Unidos em um único token e, portanto, não podem ser o primeiro ou o último token na definição de macro.

Se um parâmetro formal em uma definição de macro é precedido ou seguido pelo operador token-pasting, o parâmetro formal é substituído imediatamente pelo argumento real não expandido. A expansão da macro não é executada no argumento antes da substituição.

Em seguida, cada ocorrência do operador token-colando na *cadeia de caracteres de token* é removida e os tokens anteriores e depois dele são concatenados. O token resultante deve ser um token válido. Nesse caso, o token será verificado para uma possível substituição se representar o nome de uma macro. O identificador representa o nome pelo qual os tokens concatenados serão conhecidos no programa antes da substituição. Cada token representa um token definido em outro lugar, no programa ou na linha de comando do compilador. O espaço em branco que precede ou segue o operador é opcional.

Este exemplo ilustra o uso de operadores stringizing em token-pasting na especificação da saída do programa:

```cpp
#define paster( n ) printf_s( "token" #n " = %d", token##n )
int token9 = 9;
```

Se uma macro é chamada com um argumento numérico como

```cpp
paster( 9 );
```

a macro gera

```cpp
printf_s( "token" "9" " = %d", token9 );
```

que se torna

```cpp
printf_s( "token9 = %d", token9 );
```

## <a name="example"></a>Exemplo

```cpp
// preprocessor_token_pasting.cpp
#include <stdio.h>
#define paster( n ) printf_s( "token" #n " = %d", token##n )
int token9 = 9;

int main()
{
   paster(9);
}
```

```Output
token9 = 9
```

## <a name="see-also"></a>Consulte também

[Operadores de pré-processador](../preprocessor/preprocessor-operators.md)
