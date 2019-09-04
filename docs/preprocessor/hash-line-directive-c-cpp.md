---
title: '#Diretiva line (C/C++)'
ms.date: 08/29/2019
f1_keywords:
- '#line'
helpviewer_keywords:
- preprocessor, directives
- line directive (#line)
- '#line directive'
ms.assetid: 585c1dc4-5184-4f01-98f4-80c1909744d7
ms.openlocfilehash: 35bee779ebf059c20d4a46e27b5ad4cbfb3ce5f3
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220229"
---
# <a name="line-directive-cc"></a>Diretiva de #line (CC++/)

A diretiva **#line** informa ao pré-processador para alterar o número de linha armazenado internamente do compilador e o nome do arquivo para um determinado número de linha e nome de arquivo.

## <a name="syntax"></a>Sintaxe

> **#line** *digit-sequence* ["*filename*"]

## <a name="remarks"></a>Comentários

O compilador usa o número de linha e o nome de arquivo opcional para fazer referência aos erros que encontra durante a compilação. O número de linha geralmente se refere à linha de entrada atual, e o nome de arquivo se refere ao arquivo de entrada atual. O número de linha é incrementado depois que cada linha é processada.

O valor da *sequência de dígitos* pode ser qualquer constante inteira. É possível executar a substituição de macro nos tokens de pré-processamento, mas o resultado deve ser avaliado com a sintaxe correta. O *nome do arquivo* pode ser qualquer combinação de caracteres e deve ser colocado entre aspas duplas (`" "`). Se *filename* for omitido, o nome de arquivo anterior permanecerá inalterado.

Você pode alterar o número da linha de origem e o nome do arquivo escrevendo uma diretiva de **#line** . O tradutor usa o número de linha e o nome de arquivo para determinar os valores `__FILE__` das `__LINE__`macros predefinidas e. Você pode usar essas macros para inserir mensagens de erro autodescritivas no texto do programa. Para obter mais informações sobre essas macros predefinidas, consulte [macros](../preprocessor/predefined-macros.md)predefinidas.

A `__FILE__` macro se expande para uma cadeia de caracteres cujo conteúdo é o nome de arquivo, entre`" "`aspas duplas ().

Se você alterar o número de linha e o nome de arquivo, o compilador irá ignorar os valores anteriores e continuar o processamento com os novos valores. A diretiva de **#line** normalmente é usada por geradores de programa para fazer com que as mensagens de erro se refiram ao arquivo de origem original, e não ao programa gerado.

Os exemplos a seguir ilustram #line `__LINE__` e `__FILE__` as macros e.

Nesta instrução, o número de linha armazenado internamente é definido como 151 e o nome de arquivo é alterado para Copy. c.

```C
#line 151 "copy.c"
```

Neste exemplo, a macro `ASSERT` usa as macros `__LINE__` predefinidas e `__FILE__` para imprimir uma mensagem de erro sobre o arquivo de origem se uma determinada declaração não for verdadeira.

```C
#define ASSERT(cond) if( !(cond) )\
{printf( "assertion error line %d, file(%s)\n", \
__LINE__, __FILE__ );}
```

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)
