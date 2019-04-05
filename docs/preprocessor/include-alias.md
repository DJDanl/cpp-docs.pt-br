---
title: include_alias
ms.date: 12/16/2018
f1_keywords:
- vc-pragma.include_alias
- include_alias_CPP
helpviewer_keywords:
- pragmas, include_alias
- include_alias pragma
ms.assetid: 3256d589-12b3-4af0-a586-199e96eabacc
ms.openlocfilehash: 187fa94f7c2a5457df655081b87a7f49d38adfa2
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59024095"
---
# <a name="includealias"></a>include_alias

Especifica que, quando *alias_filename* for encontrado em um `#include` diretiva, o compilador substitui *actual_filename* em seu lugar.

## <a name="syntax"></a>Sintaxe

> #<a name="pragma-includealiasaliasfilename-actualfilename"></a>pragma include_alias("*alias_filename*", "*actual_filename*")
> #<a name="pragma-includealiasaliasfilename-actualfilename"></a>pragma include_alias (\<*alias_filename*>, \< *actual_filename*>)

## <a name="remarks"></a>Comentários

O **include_alias** diretiva de pragma permite a substituição de arquivos que têm nomes diferentes ou caminhos para os nomes dos arquivos incluídos por arquivos de origem. Por exemplo, alguns sistemas de arquivos permitem nomes de arquivo de cabeçalho mais do que o limite do sistema de arquivos FAT 8.3. O compilador não pode simplesmente truncar nomes mais longos para 8.3, pois os primeiros oito caracteres dos nomes de arquivos de cabeçalho mais longos podem não ser exclusivos. Sempre que o compilador encontra a *alias_filename* cadeia de caracteres, ele substitui *actual_filename*e procura o arquivo de cabeçalho *actual_filename* em vez disso. Esse pragma deve aparecer antes das políticas `#include` correspondentes. Por exemplo:

```cpp
// First eight characters of these two files not unique.
#pragma include_alias( "AppleSystemHeaderQuickdraw.h", "quickdra.h" )
#pragma include_alias( "AppleSystemHeaderFruit.h", "fruit.h" )

#pragma include_alias( "GraphicsMenu.h", "gramenu.h" )

#include "AppleSystemHeaderQuickdraw.h"
#include "AppleSystemHeaderFruit.h"
#include "GraphicsMenu.h"
```

O alias que está sendo pesquisado deve corresponder exatamente a especificação, na ortografia e no uso de aspas duplas ou colchetes angulares. O **include_alias** pragma executa a correspondência de nomes de arquivo da cadeia de caracteres simple; nenhuma outra validação de nome de arquivo é executada. Por exemplo, dadas as seguintes políticas,

```cpp
#pragma include_alias("mymath.h", "math.h")
#include "./mymath.h"
#include "sys/mymath.h"
```

nenhuma criação de alias (substituição) é executada, pois as cadeias de caracteres do arquivo de cabeçalho não correspondem exatamente. Além disso, os nomes de cabeçalho usados como argumentos para o `/Yu` e `/Yc` opções do compilador, ou o `hdrstop` pragma, não são substituídos. Por exemplo, se o arquivo de origem contiver a seguinte política,

```cpp
#include <AppleSystemHeaderStop.h>
```

a opção do compilador correspondente deve ser

> /YcAppleSystemHeaderStop.h

Você pode usar o **include_alias** pragma para mapear qualquer nome de arquivo de cabeçalho para outro. Por exemplo:

```cpp
#pragma include_alias( "api.h", "c:\version1.0\api.h" )
#pragma include_alias( <stdio.h>, <newstdio.h> )
#include "api.h"
#include <stdio.h>
```

Não misture nomes de arquivos incluídos entre aspas duplas com nomes de arquivos entre colchetes angulares. Por exemplo, considerando os dois acima `#pragma include_alias` diretivas, o compilador não executa nenhuma substituição nas seguintes `#include` diretivas:

```cpp
#include <api.h>
#include "stdio.h"
```

Além disso, a política a seguir gera um erro:

```cpp
#pragma include_alias(<header.h>, "header.h")  // Error
```

Observe que o nome do arquivo relatado nas mensagens de erro ou como o valor do predefinido `__FILE__` macro, é o nome do arquivo após a substituição foi executada. Por exemplo, consulte a saída após as seguintes políticas:

```cpp
#pragma include_alias( "VERYLONGFILENAME.H", "myfile.h" )
#include "VERYLONGFILENAME.H"
```

Um erro em VERYLONGFILENAME. H produz a seguinte mensagem de erro:

```Output
myfile.h(15) : error C2059 : syntax error
```

Observe também que a transitividade não tem suporte. Dadas as seguintes políticas,

```cpp
#pragma include_alias( "one.h", "two.h" )
#pragma include_alias( "two.h", "three.h" )
#include "one.h"
```

o compilador procura pelo arquivo em vez de Three.

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
