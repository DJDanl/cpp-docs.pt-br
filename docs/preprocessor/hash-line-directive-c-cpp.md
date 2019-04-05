---
title: '#linha de diretiva (C/C++)'
ms.date: 10/18/2017
f1_keywords:
- '#line'
helpviewer_keywords:
- preprocessor, directives
- line directive (#line)
- '#line directive'
ms.assetid: 585c1dc4-5184-4f01-98f4-80c1909744d7
ms.openlocfilehash: ad0fe1514e89b861bab046652b1768862cc8045b
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59023731"
---
# <a name="line-directive-cc"></a>Diretiva #line (C/C++)

O **#line** diretiva informa o pré-processador para alterar o número de linha armazenado internamente do compilador e o nome de arquivo para um dado número de linha e o nome do arquivo.

## <a name="syntax"></a>Sintaxe

> **#line** *digit-sequence* ["*filename*"]

## <a name="remarks"></a>Comentários

O compilador usa o número de linha e o nome de arquivo opcional para fazer referência aos erros que encontra durante a compilação. O número de linha geralmente se refere à linha de entrada atual, e o nome de arquivo se refere ao arquivo de entrada atual. O número de linha é incrementado depois que cada linha é processada.

O *sequência de dígitos* valor pode ser qualquer constante inteira. É possível executar a substituição de macro nos tokens de pré-processamento, mas o resultado deve ser avaliado com a sintaxe correta. O *filename* pode ser qualquer combinação de caracteres e deve ser colocado entre aspas duplas (**""**). Se *filename* é omitido, o nome do arquivo anterior permanecerá inalterado.

Você pode alterar o número de linha de código-fonte e o nome do arquivo, escrevendo uma **#line** diretiva. O conversor usa o número de linha e o nome de arquivo para determinar os valores das macros predefinidas `__FILE__` e `__LINE__`. Você pode usar essas macros para inserir mensagens de erro autodescritivas no texto do programa. Para obter mais informações sobre essas macros predefinidas, consulte [Macros predefinidas](../preprocessor/predefined-macros.md).

O `__FILE__` macro se expande para uma cadeia de caracteres cujo conteúdo é o nome do arquivo, cercada por aspas duplas (**""**).

Se você alterar o número de linha e o nome de arquivo, o compilador irá ignorar os valores anteriores e continuar o processamento com os novos valores. O **#line** diretiva é normalmente usada por geradores de programas para gerar mensagens de erro, consulte o arquivo de origem original em vez de ao programa gerado.

Os exemplos a seguir ilustram **#line** e o `__LINE__` e `__FILE__` macros.

Nesta instrução, o número de linha armazenado internamente é definido como 151 e o nome do arquivo é alterado para copy.c.

```cpp
#line 151 "copy.c"
```

Neste exemplo, a macro `ASSERT` usa as macros predefinidas `__LINE__` e `__FILE__` para imprimir uma mensagem de erro sobre o arquivo de origem, se uma asserção de determinado não for verdadeira.

```cpp
#define ASSERT(cond) if( !(cond) )\
{printf( "assertion error line %d, file(%s)\n", \
__LINE__, __FILE__ );}
```

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)