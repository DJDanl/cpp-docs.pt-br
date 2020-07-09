---
title: '#Diretiva line (C/C++)'
description: 'Descreve a diretiva #line, usada para definir o número de linha e o nome do arquivo relatado por macros de pré-processador.'
ms.date: 07/06/2020
f1_keywords:
- '#line'
helpviewer_keywords:
- preprocessor, directives
- line directive (#line)
- '#line directive'
ms.assetid: 585c1dc4-5184-4f01-98f4-80c1909744d7
ms.openlocfilehash: 7b671cfdf5d5ce43024ac3e038c214396ac8679c
ms.sourcegitcommit: 85d96eeb1ce41d9e1dea947f65ded672e146238b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/07/2020
ms.locfileid: "86058614"
---
# <a name="line-directive-cc"></a>Diretiva de #line (C/C++)

A diretiva **#line** informa ao pré-processador para definir os valores relatados do compilador para o número de linha e o nome de arquivo para um determinado número de linha e nome de arquivo.

## <a name="syntax"></a>Sintaxe

> **`#line`***sequência de dígitos* ["*filename*"]

## <a name="remarks"></a>Comentários

O compilador usa o número de linha e o nome de arquivo opcional para fazer referência aos erros que encontra durante a compilação. O número de linha geralmente se refere à linha de entrada atual, e o nome de arquivo se refere ao arquivo de entrada atual. O número de linha é incrementado depois que cada linha é processada.

O valor da *sequência de dígitos* pode ser qualquer constante inteira. A substituição de macro pode ser usada em tokens de pré-processamento, mas o resultado deve ser avaliado como a sintaxe correta. O *nome do arquivo* pode ser qualquer combinação de caracteres e deve ser colocado entre aspas duplas ( `" "` ). Se *filename* for omitido, o nome de arquivo anterior permanecerá inalterado.

Você pode alterar o número da linha de origem e o nome do arquivo escrevendo uma **`#line`** diretiva. A **`#line`** diretiva define o valor para a linha que segue imediatamente a diretiva no arquivo de origem. O tradutor usa o número de linha e o nome de arquivo para determinar os valores das macros predefinidas `__FILE__` e `__LINE__` . Você pode usar essas macros para inserir mensagens de erro autodescritivas no texto do programa. Para obter mais informações sobre essas macros predefinidas, consulte [macros predefinidas](../preprocessor/predefined-macros.md).

A `__FILE__` macro se expande para uma cadeia de caracteres cujo conteúdo é o nome de arquivo, entre aspas duplas ( `" "` ).

Se você alterar o número de linha e o nome de arquivo, o compilador irá ignorar os valores anteriores e continuar o processamento com os novos valores. A diretiva de **#line** normalmente é usada por geradores de programa. Ele é usado para fazer com que as mensagens de erro se refiram ao arquivo de origem original, em vez de ao programa gerado.

## <a name="example"></a>Exemplo

Os exemplos a seguir ilustram **`#line`** e as `__LINE__` `__FILE__` macros e.

No primeiro exemplo, o número da linha é definido como 10 e, em seguida, 20, e o nome do arquivo é alterado para *Hello. cpp*.

```cpp
// line_directive.cpp
// Compile by using: cl /W4 /EHsc line_directive.cpp
#include <stdio.h>

int main()
{
    printf( "This code is on line %d, in file %s\n", __LINE__, __FILE__ );
#line 10
    printf( "This code is on line %d, in file %s\n", __LINE__, __FILE__ );
#line 20 "hello.cpp"
    printf( "This code is on line %d, in file %s\n", __LINE__, __FILE__ );
    printf( "This code is on line %d, in file %s\n", __LINE__, __FILE__ );
}
```

```Output
This code is on line 7, in file line_directive.cpp
This code is on line 10, in file line_directive.cpp
This code is on line 20, in file hello.cpp
This code is on line 21, in file hello.cpp
```

Neste exemplo, a macro `ASSERT` usa as macros predefinidas `__LINE__` e `__FILE__` para imprimir uma mensagem de erro sobre o arquivo de origem se uma determinada declaração não for verdadeira.

```C
#define ASSERT(cond) if( !(cond) )\
{printf( "assertion error line %d, file(%s)\n", \
__LINE__, __FILE__ );}
```

## <a name="see-also"></a>Confira também

[Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)
