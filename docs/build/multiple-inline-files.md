---
title: Vários arquivos embutidos
ms.date: 11/04/2016
helpviewer_keywords:
- inline files, multiple NMAKE
- multiple inline files
- NMAKE program, inline files
ms.assetid: 6d381dcf-0ed8-45d1-8df3-b4598d860b99
ms.openlocfilehash: ec531e5716098725782010927201ef57e2a8aa24
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50558152"
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

[Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)