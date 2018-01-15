---
title: include_alias | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc-pragma.include_alias
- include_alias_CPP
dev_langs: C++
helpviewer_keywords:
- pragmas, include_alias
- include_alias pragma
ms.assetid: 3256d589-12b3-4af0-a586-199e96eabacc
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a45dce64ce0dfb2f5112b22c7577c7174effc12b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="includealias"></a>include_alias

Especifica que *short_filename* deve ser usado como um alias para *long_filename*.

## <a name="syntax"></a>Sintaxe

> #<a name="pragma-includealiaslongfilename-shortfilename"></a>pragma include_alias ("*long_filename*","*short_filename*")  
> #<a name="pragma-includealiaslongfilename-shortfilename"></a>pragma include_alias (*long_filename*, *short_filename*)

## <a name="remarks"></a>Comentários

Alguns sistemas de arquivos permitem nomes de arquivo de cabeçalho mais longos do que o limite do sistema de arquivos FAT 8.3. O compilador não pode simplesmente truncar nomes mais longos para 8.3, pois os primeiros oito caracteres dos nomes de arquivos de cabeçalho mais longos podem não ser exclusivos. Sempre que o compilador encontra o *long_filename* cadeia de caracteres, ele substitui *short_filename*e procura o arquivo de cabeçalho *short_filename* em vez disso. Esse pragma deve aparecer antes das políticas `#include` correspondentes. Por exemplo:

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

nenhuma criação de alias (substituição) é executada, pois as cadeias de caracteres do arquivo de cabeçalho não correspondem exatamente. Além disso, os nomes de cabeçalho usados como argumentos para as opções de compilador /Yu e /Yc, ou o **hdrstop** pragma, não são substituídos. Por exemplo, se o arquivo de origem contiver a seguinte política,
  
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

Não misture nomes de arquivos incluídos entre aspas duplas com nomes de arquivos entre colchetes angulares. Por exemplo, considerando os dois acima **#pragma include_alias** diretivas, o compilador não executa nenhuma substituição no seguinte `#include` diretivas:

```cpp
#include <api.h>
#include "stdio.h"
```

Além disso, a política a seguir gera um erro:

```cpp
#pragma include_alias(<header.h>, "header.h")  // Error
```

Observe que o nome do arquivo relatado nas mensagens de erro, ou como o valor de predefinida **&#95; &#95; ARQUIVO &#95; &#95;**  macro, é o nome do arquivo após a substituição foi executada. Por exemplo, consulte a saída após as diretivas a seguir:

```cpp
#pragma include_alias( "VeryLongFileName.H", "myfile.h" )
#include "VeryLongFileName.H"
```

Um erro no VERYLONGFILENAME. H produz a seguinte mensagem de erro:

```Output
myfile.h(15) : error C2059 : syntax error
```

Observe também que a transitividade não tem suporte. Dadas as seguintes políticas,

```cpp
#pragma include_alias( "one.h", "two.h" )
#pragma include_alias( "two.h", "three.h" )
#include "one.h"
```

o compilador procura pelo arquivo TWO.H em vez de THREE.H.  

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)