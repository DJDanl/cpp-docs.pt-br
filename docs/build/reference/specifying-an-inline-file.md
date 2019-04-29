---
title: Especificando um arquivo embutido
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, inline files
- inline files [C++], specifying NMAKE
- files [C++], inline
ms.assetid: 393eccfb-3fc9-4bac-a30c-8ac8d221cca3
ms.openlocfilehash: 7eb123ef3f2115df5c65d266630bded8cb54baae
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62318524"
---
# <a name="specifying-an-inline-file"></a>Especificando um arquivo embutido

Especificar dois colchetes angulares (<<) no comando onde *filename* deve ser exibido. Os colchetes angulares não pode ser uma expansão de macro.

## <a name="syntax"></a>Sintaxe

```
<<[filename]
```

## <a name="remarks"></a>Comentários

Quando o comando é executado, os colchetes angulares são substituídos por *filename*, se especificado, ou por um nome exclusivo gerado pelo NMAKE. Se especificado, *filename* deve seguir sem um espaço ou tabulação colchetes angulares. Um caminho é permitido. Nenhuma extensão é necessária ou supõe-se. Se *filename* for especificado, o arquivo é criado no atual ou o diretório especificado, substituindo qualquer arquivo com esse nome; caso contrário, ele é criado no diretório TMP (ou o diretório atual, se a variável de ambiente TMP não é definido). Se um anterior *filename* é reutilizado, NMAKE substituirá o arquivo anterior.

## <a name="see-also"></a>Consulte também

[Arquivos embutidos em um makefile](inline-files-in-a-makefile.md)
