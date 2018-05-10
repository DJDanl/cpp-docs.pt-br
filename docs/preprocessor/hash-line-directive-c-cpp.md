---
title: '#linha de diretiva (C/C++) | Microsoft Docs'
ms.custom: ''
ms.date: 10/18/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- '#line'
dev_langs:
- C++
helpviewer_keywords:
- preprocessor, directives
- line directive (#line)
- '#line directive'
ms.assetid: 585c1dc4-5184-4f01-98f4-80c1909744d7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3ebbcea7432b27e9269b5041d90d14534a77b812
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="line-directive-cc"></a>Diretiva #line (C/C++)

A política `#line` instrui o pré-processador a alterar o número de linha e nome de arquivo do compilador armazenados internamente para um dado número de linha e nome de arquivo.

## <a name="syntax"></a>Sintaxe

> **#line** *digit-sequence* ["*filename*"]

## <a name="remarks"></a>Comentários

O compilador usa o número de linha e o nome de arquivo opcional para fazer referência aos erros que encontra durante a compilação. O número de linha geralmente se refere à linha de entrada atual, e o nome de arquivo se refere ao arquivo de entrada atual. O número de linha é incrementado depois que cada linha é processada.

O *sequência de dígitos* valor pode ser uma constante inteira. É possível executar a substituição de macro nos tokens de pré-processamento, mas o resultado deve ser avaliado com a sintaxe correta. O *filename* pode ser qualquer combinação de caracteres e devem ser colocados entre aspas duplas (**""**). Se *filename* for omitido, o nome do arquivo anterior permanecerá inalterado.

Você pode alterar o número de linha e o nome de arquivo de origem escrevendo uma política `#line`. O conversor usa o número de linha e o nome de arquivo para determinar os valores de macros predefinidas **&#95; &#95;arquivo&#95; &#95;** e **&#95; &#95;linha&#95; &#95;**. Você pode usar essas macros para inserir mensagens de erro autodescritivas no texto do programa. Para obter mais informações sobre essas macros predefinidas, consulte [Macros predefinidas](../preprocessor/predefined-macros.md).

O **&#95; &#95;arquivo&#95; &#95;** macro se expande para uma cadeia de caracteres cujo conteúdo é o nome de arquivo entre aspas duplas (**""**).

Se você alterar o número de linha e o nome de arquivo, o compilador irá ignorar os valores anteriores e continuar o processamento com os novos valores. Em geral, a política `#line` é usada por geradores de programas para fazer com que as mensagens de erro se refiram ao arquivo de origem original em vez de ao programa gerado.

Os exemplos a seguir ilustram `#line` e **&#95; &#95;linha&#95; &#95;** e **&#95; &#95;arquivo&#95; &#95;** macros.

Nesta instrução, o número da linha armazenadas internamente é definido como 151 e o nome do arquivo é alterado para copy.c.

```cpp
#line 151 "copy.c"
```

 Neste exemplo, a macro `ASSERT` usa as macros predefinidas **&#95; &#95;linha&#95; &#95;** e **&#95; &#95;arquivo&#95; &#95;** para imprimir um mensagem de erro sobre o arquivo de origem se um determinado asserção não for verdadeira.

```cpp
#define ASSERT(cond) if( !(cond) )\
{printf( "assertion error line %d, file(%s)\n", \
__LINE__, __FILE__ );}
```

## <a name="see-also"></a>Consulte também

[Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)