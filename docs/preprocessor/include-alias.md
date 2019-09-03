---
title: Pragma include_alias
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.include_alias
- include_alias_CPP
helpviewer_keywords:
- pragmas, include_alias
- include_alias pragma
ms.assetid: 3256d589-12b3-4af0-a586-199e96eabacc
ms.openlocfilehash: aa3714186e8f95d4044ba5a3b2bc2d5fcfb1fc9c
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218896"
---
# <a name="include_alias-pragma"></a>Pragma include_alias

Especifica que quando *alias_filename* é encontrado em uma `#include` diretiva, o compilador substitui *actual_filename* em seu lugar.

## <a name="syntax"></a>Sintaxe

<!-- localization note - it's important to have the italic and bold characters immediately adjacent here. -->
> **#pragma include_alias (** "*alias_filename*" **,** "*actual_filename*" **)** \
> **#pragma include_alias (** \< *alias_filename*>  **,** *actual_filename*) \<> 

## <a name="remarks"></a>Comentários

A diretiva pragma **include_alias** permite substituir arquivos que têm nomes ou caminhos diferentes para os nomes de arquivo incluídos pelos arquivos de origem. Por exemplo, alguns sistemas de arquivos permitem nomes de arquivo de cabeçalho mais longos do que o limite do sistema de arquivos FAT 8,3. O compilador não pode apenas truncar os nomes mais longos para 8,3, pois os oito primeiros caracteres dos nomes de um dos cabeçalhos mais longos podem não ser exclusivos. Sempre que o compilador vê a cadeia de caracteres `#include` alias_filename em uma diretiva, ele substitui o nome *actual_filename* em vez disso. Em seguida, ele carrega o arquivo de cabeçalho *actual_filename* . Esse pragma deve aparecer antes das políticas `#include` correspondentes. Por exemplo:

```cpp
// First eight characters of these two files not unique.
#pragma include_alias( "AppleSystemHeaderQuickdraw.h", "quickdra.h" )
#pragma include_alias( "AppleSystemHeaderFruit.h", "fruit.h" )

#pragma include_alias( "GraphicsMenu.h", "gramenu.h" )

#include "AppleSystemHeaderQuickdraw.h"
#include "AppleSystemHeaderFruit.h"
#include "GraphicsMenu.h"
```

O alias a ser pesquisado deve corresponder exatamente à especificação. O caso, a ortografia e o uso de aspas duplas ou colchetes angulares devem corresponder. O pragma **include_alias** faz a correspondência de cadeia de caracteres simples nos nomes de File. Nenhuma outra validação de nome de arquivo é executada. Por exemplo, dadas as seguintes políticas,

```cpp
#pragma include_alias("mymath.h", "math.h")
#include "./mymath.h"
#include "sys/mymath.h"
```

nenhuma substituição de alias foi feita, pois as cadeias de caracteres do arquivo de cabeçalho não correspondem exatamente. Além disso, os `/Yu` `hdrstop` nomes de um cabeçalho usados como argumentos para `/Yc` as opções de compilador e, ou pragma, não são substituídos. Por exemplo, se o arquivo de origem contiver a seguinte política,

```cpp
#include <AppleSystemHeaderStop.h>
```

a opção do compilador correspondente deve ser

> **/YcAppleSystemHeaderStop.h**

Você pode usar o pragma **include_alias** para mapear qualquer nome de arquivo de cabeçalho para outro. Por exemplo:

```cpp
#pragma include_alias( "api.h", "c:\version1.0\api.h" )
#pragma include_alias( <stdio.h>, <newstdio.h> )
#include "api.h"
#include <stdio.h>
```

Não misture nomes de fileentre aspas duplas com nomes de fileentre colchetes angulares. Por exemplo, considerando as duas `#pragma include_alias` diretivas acima, o compilador não faz nenhuma substituição nas seguintes `#include` diretivas:

```cpp
#include <api.h>
#include "stdio.h"
```

Além disso, a política a seguir gera um erro:

```cpp
#pragma include_alias(<header.h>, "header.h")  // Error
```

O nome de arquivo relatado em mensagens de erro ou como o valor da `__FILE__` macro predefinida é o nome do arquivo depois que a substituição é feita. Por exemplo, consulte a saída após as seguintes diretivas:

```cpp
#pragma include_alias( "VERYLONGFILENAME.H", "myfile.h" )
#include "VERYLONGFILENAME.H"
```

Erro em *VERYLONGFILENAME. H* produz a seguinte mensagem de erro:

```Output
myfile.h(15) : error C2059 : syntax error
```

Observe também que a transitividade não tem suporte. Dadas as seguintes políticas,

```cpp
#pragma include_alias( "one.h", "two.h" )
#pragma include_alias( "two.h", "three.h" )
#include "one.h"
```

o compilador pesquisa o arquivo *Two. h* em vez de *três. h*.

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
