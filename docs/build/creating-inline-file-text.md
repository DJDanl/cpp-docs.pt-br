---
title: Criando texto de arquivo embutido | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- inline files, creating text
- NMAKE program, inline files
- text, inline file
ms.assetid: b8a332ed-8244-4ff8-89e6-029d7f659725
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ce0a345c6c2f48d3d5c2e6fb9d9cfc2a5c03e4ed
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45720909"
---
# <a name="creating-inline-file-text"></a>Criando texto de arquivo embutido

Arquivos embutidos estão temporária ou permanente.

## <a name="syntax"></a>Sintaxe

```
inlinetext
.
.
.
<<[KEEP | NOKEEP]
```

## <a name="remarks"></a>Comentários

Especificar *inlinetext* na primeira linha após o comando. Marcar o final com colchetes duplos (<<) no início de uma linha separada. O arquivo contém todos os *inlinetext* antes dos colchetes de delimitação. O *inlinetext* pode ter expansões de macro e substituições, mas não as diretivas ou comentários de makefile. Espaços, tabulações e caracteres de nova linha são tratados literalmente.

Um arquivo temporário existe pela duração da sessão e pode ser reutilizado por outros comandos. Especificar **manter** após os colchetes de fechamento para reter o arquivo após a sessão NMAKE; um arquivo sem nome é preservado no disco com o nome do arquivo gerado. Especificar **NOKEEP** ou nada para um arquivo temporário. **Manter** e **NOKEEP** não diferenciam maiusculas de minúsculas.

## <a name="see-also"></a>Consulte também

[Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)