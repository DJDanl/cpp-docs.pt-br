---
title: Compilador (nível 1) de aviso C4274 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4274
dev_langs:
- C++
helpviewer_keywords:
- C4274
ms.assetid: 5a948680-7ed1-469f-978d-ae99d154e161
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 39b941fc0cb32e268e33d3b0e1ae66079e8decaf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4274"></a>Compilador C4274 de aviso (nível 1)
\#ident ignorado; Consulte a documentação para #pragma comment (exestr, 'string')  
  
 O `#ident` diretiva, que insere uma cadeia de caracteres especificada pelo usuário no objeto ou arquivo executável, foi preterida. Consequentemente, o compilador ignora a diretiva.  
  
> [!CAUTION]
>  Aviso C4274 aconselha a usar o [#pragma comment (exestr, 'string')](../../preprocessor/comment-c-cpp.md) diretiva. No entanto, esse aviso é preterido e será revisado em uma versão futura do compilador. Se você usar o `#pragma` diretiva, a ferramenta do vinculador (LINK.exe) ignora o produzido pela diretiva de registro de comentário e emite o aviso [LNK4229](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md). Em vez da `#ident` diretiva, é recomendável que você use uma cadeia de caracteres de recurso de versão do arquivo em seu aplicativo.  
  
## <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Remover o `#ident "` *cadeia de caracteres* `"` diretiva.  
  
## <a name="see-also"></a>Consulte também  
 [comentário (C/C++)](../../preprocessor/comment-c-cpp.md)   
 [Aviso LNK4229 ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md)   
 [Trabalhando com arquivos de recurso](../../windows/working-with-resource-files.md)