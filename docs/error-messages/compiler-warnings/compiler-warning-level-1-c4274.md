---
title: "Compilador aviso (nível 1) C4274 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4274
dev_langs:
- C++
helpviewer_keywords:
- C4274
ms.assetid: 5a948680-7ed1-469f-978d-ae99d154e161
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: Machine Translation
ms.sourcegitcommit: 4fafe461008e3545243d693e0d9e34acd57163e0
ms.openlocfilehash: fbba1e6dde180e77afe7ed8960849ee8cc0fd108
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4274"></a>Compilador C4274 de aviso (nível 1)
\#ident ignorado; Consulte a documentação para #pragma comentário (exestr, 'string')  
  
 A `#ident` diretiva, que insere uma cadeia de caracteres especificada pelo usuário no objeto ou arquivo executável, foi preterida. Consequentemente, o compilador ignora a diretiva.  
  
> [!CAUTION]
>  Aviso C4274 aconselham a usar o [#pragma comentário (exestr, 'string')](../../preprocessor/comment-c-cpp.md) diretiva. No entanto, esse conselho é preterido e será revisado em uma versão futura do compilador. Se você usar o `#pragma` diretiva, a ferramenta do vinculador (LINK.exe) ignora o registro de comentário produzido pela diretiva e emite um aviso [LNK4229](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md). Em vez da `#ident` diretiva, é recomendável que você use uma cadeia de caracteres do recurso de versão do arquivo em seu aplicativo.  
  
## <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Remover o `#ident "` *sequência* `"` diretiva.  
  
## <a name="see-also"></a>Consulte também  
 [comentário (C/C++)](../../preprocessor/comment-c-cpp.md)   
 [Aviso LNK4229 ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-warning-lnk4229.md)   
 [Trabalhando com arquivos de recurso](../../windows/working-with-resource-files.md)
