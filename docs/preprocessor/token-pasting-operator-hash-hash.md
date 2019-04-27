---
title: Operador de colagem de token (##)
ms.date: 11/04/2016
f1_keywords:
- '##'
helpviewer_keywords:
- preprocessor, operators
- '## preprocessor operator'
ms.assetid: 4f173503-990f-4bff-aef3-ec4d1f1458ef
ms.openlocfilehash: dab4da5fd65fc280d2061256a580a015917d24b6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62179588"
---
# <a name="token-pasting-operator-"></a>Operador de colagem de token (##)

O operador double-number-sign ou "token-pasting" (**##**), às vezes chamado de operador "merging", é usado em macros do tipo função e do tipo de objeto. Ele permite que tokens separados sejam agrupados em um único token e, portanto, não pode ser o primeiro ou último o token na definição da macro.

Se um parâmetro formal em uma definição de macro é precedido ou seguido pelo operador token-pasting, o parâmetro formal é substituído imediatamente pelo argumento real não expandido. A expansão da macro não é executada no argumento antes da substituição.

Em seguida, cada ocorrência do operador token-pasting na *token de cadeia de caracteres* for removido, e os tokens que precedem e seguem são concatenados. O token resultante deve ser um token válido. Nesse caso, o token será verificado para uma possível substituição se representar o nome de uma macro. O identificador representa o nome pelo qual os tokens concatenados serão conhecidos no programa antes da substituição. Cada token representa um token definido em outro lugar, no programa ou na linha de comando do compilador. O espaço em branco que precede ou segue o operador é opcional.

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