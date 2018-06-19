---
title: Criando arquivo embutido texto | Microsoft Docs
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
ms.openlocfilehash: 3ab1154935ac4eb8b0595c84ba8d75a9ca13e4d3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32367492"
---
# <a name="creating-inline-file-text"></a>Criando texto de arquivo embutido
Arquivos embutidos são temporária ou permanente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      inlinetext  
.  
.  
.  
<<[KEEP | NOKEEP]  
```  
  
## <a name="remarks"></a>Comentários  
 Especifique *inlinetext* na primeira linha após o comando. Marcar o fim com colchetes duplos (<<) no início de uma linha separada. O arquivo contém todos os *inlinetext* antes dos colchetes de delimitação. O *inlinetext* pode ter expansões de macro e substituições, mas não as diretivas ou comentários de makefile. Espaços, tabulações e caracteres de nova linha são tratados literalmente.  
  
 Um arquivo temporário existe para a duração da sessão e pode ser reutilizado por outros comandos. Especifique **manter** após os colchetes de fechamento para reter o arquivo após a sessão NMAKE; um arquivo sem nome é preservado no disco com o nome de arquivo gerado. Especifique **NOKEEP** ou nada para um arquivo temporário. **Manter** e **NOKEEP** não diferenciam maiusculas de minúsculas.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)