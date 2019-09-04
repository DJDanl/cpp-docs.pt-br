---
title: Pragma hdrstop
ms.date: 08/29/2019
f1_keywords:
- hdrstop_CPP
- vc-pragma.hdrstop
helpviewer_keywords:
- hdrstop pragma
- pragmas, hdrstop
ms.assetid: 5ea8370a-10d1-4538-ade6-4c841185da0e
ms.openlocfilehash: f540f0f01fe654213af15afa8fbf5cbd94e4b7e2
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70221021"
---
# <a name="hdrstop-pragma"></a>Pragma hdrstop

Fornece controle adicional sobre nomes de arquivo de pré-compilação e sobre o local no qual o estado de compilação é salvo.

## <a name="syntax"></a>Sintaxe

> **#pragma hdrstop** [("*filename*")]

## <a name="remarks"></a>Comentários

O *filename* é o nome do arquivo de cabeçalho pré-compilado a ser usado ou criado (dependendo de se [/Yu](../build/reference/yu-use-precompiled-header-file.md) ou [/YC](../build/reference/yc-create-precompiled-header-file.md) está especificado). Se o *nome* do arquivo não contiver uma especificação de caminho, o arquivo de cabeçalho pré-compilado será considerado no mesmo diretório que o arquivo de origem.

Se um C ou C++ arquivo contiver um pragma **hdrstop** quando compilado `/Yc`com, o compilador salvará o estado da compilação até o local do pragma. O estado compilado de qualquer código que siga o pragma não é salvo.

Use *nome* de arquivo para nomear o arquivo de cabeçalho pré-compilado no qual o estado compilado é salvo. Um espaço entre **hdrstop** e *filename* é opcional. O nome de arquivo especificado no pragma **hdrstop** é uma cadeia de caracteres e, portanto, está sujeito às restrições de C++ qualquer C ou cadeia de caracteres. Em particular, você deve colocá-lo entre aspas e usar o caractere de escape (barra invertida) para especificar nomes de diretório. Por exemplo:

```C
#pragma hdrstop( "c:\\projects\\include\\myinc.pch" )
```

O nome do arquivo de cabeçalho pré-compilado é determinado de acordo com as regras a seguir, em ordem de precedência:

1. O argumento para a `/Fp` opção do compilador

2. O argumento *filename* para`#pragma hdrstop`

3. O nome base do arquivo de origem com a extensão .PCH

Para as `/Yc` opções `/Yu` e, se nenhuma das duas opções de compilação nem o pragma **hdrstop** especifica um nome de arquivo, o nome base do arquivo de origem é usado como o nome base do arquivo de cabeçalho pré-compilado.

Você também pode usar comandos de pré-processamento para executar a substituição de macros, da seguinte maneira:

```C
#define INCLUDE_PATH "c:\\progra~`1\\devstsu~1\\vc\\include\\"
#define PCH_FNAME "PROG.PCH"
.
.
.
#pragma hdrstop( INCLUDE_PATH PCH_FNAME )
```

As regras a seguir regem onde o pragma **hdrstop** pode ser posicionado:

- Deve aparecer fora de qualquer declaração ou definição de dados ou de função.

- Deve ser especificado no arquivo de origem, e não em um arquivo de cabeçalho.

## <a name="example"></a>Exemplo

```C
#include <windows.h>                 // Include several files
#include "myhdr.h"

__inline Disp( char *szToDisplay )   // Define an inline function
{
    // ...                           // Some code to display string
}
#pragma hdrstop
```

Neste exemplo, o pragma **hdrstop** aparece depois que dois arquivos foram incluídos e uma função embutida foi definida. Esse local pode, à primeira, parecer ser um posicionamento estranho para o pragma. No entanto, considere que usar as opções `/Yc` de pré-compilação manual e `/Yu`, com o **hdrstop** pragma, possibilita que você compile arquivos de origem inteiros — mesmo código embutido. Com o compilador da Microsoft, você não está limitado a pré-compilar somente declarações de dados.

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
