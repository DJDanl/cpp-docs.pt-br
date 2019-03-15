---
title: Vários arquivos embutidos
ms.date: 11/04/2016
helpviewer_keywords:
- inline files, multiple NMAKE
- multiple inline files
- NMAKE program, inline files
ms.assetid: 6d381dcf-0ed8-45d1-8df3-b4598d860b99
ms.openlocfilehash: 71f17ff6717e717693facb21b4a4341a040b14c1
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824428"
---
# <a name="multiple-inline-files"></a>Vários arquivos embutidos

Um comando pode criar mais de um arquivo embutido.

## <a name="syntax"></a>Sintaxe

```
command << <<
inlinetext
<<[KEEP | NOKEEP]
inlinetext
<<[KEEP | NOKEEP]
```

## <a name="remarks"></a>Comentários

Para cada arquivo, especifique uma ou mais linhas de texto embutido seguido por uma que contém o delimitador de linha de fechamento. Comece o texto do segundo arquivo na linha após a linha de delimitação para o primeiro arquivo.

## <a name="see-also"></a>Consulte também

[Arquivos embutidos em um makefile](inline-files-in-a-makefile.md)
