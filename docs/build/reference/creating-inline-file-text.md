---
title: Criando texto de arquivo embutido
ms.date: 11/04/2016
helpviewer_keywords:
- inline files, creating text
- NMAKE program, inline files
- text, inline file
ms.assetid: b8a332ed-8244-4ff8-89e6-029d7f659725
ms.openlocfilehash: a45aa526ca99af93cda86a2a8e0580d4d036ca6d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62272315"
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

[Arquivos embutidos em um makefile](inline-files-in-a-makefile.md)
