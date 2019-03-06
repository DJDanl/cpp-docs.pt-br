---
title: Comentários em makefile
ms.date: 11/04/2016
helpviewer_keywords:
- makefiles, comments
ms.assetid: 76fd9e3d-5966-47f4-a091-c9e80b232b49
ms.openlocfilehash: 08720e2f7db1e32f8762126f4e090cf50b61dbc5
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57426675"
---
# <a name="comments-in-a-makefile"></a>Comentários em makefile

Preceder um comentário com um sinal numérico (#). NMAKE ignora o texto do sinal de número para o próximo caractere de nova linha. Exemplos:

```
# Comment on line by itself
OPTIONS = /MAP  # Comment on macro definition line

all.exe : one.obj two.obj  # Comment on dependency line
    link one.obj two.obj
# Comment in commands block
#   copy *.obj \objects  # Command turned into comment
    copy one.exe \release

.obj.exe:  # Comment on inference rule line
    link $<

my.exe : my.obj ; link my.obj  # Err: cannot comment this
# Error: # must be the first character
.obj.exe: ; link $<  # Error: cannot comment this
```

Para especificar um sinal numérico literal, preceda-o com um acento circunflexo (**^**), da seguinte maneira:

```
DEF = ^#define  #Macro for a C preprocessing directive
```

## <a name="see-also"></a>Consulte também

[Conteúdo de um makefile](../build/contents-of-a-makefile.md)
