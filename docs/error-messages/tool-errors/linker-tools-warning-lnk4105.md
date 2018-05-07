---
title: Aviso LNK4105 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4105
dev_langs:
- C++
helpviewer_keywords:
- LNK4105
ms.assetid: 6c7bebf4-4ea6-4533-a6ed-e563d43abbd7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0ffdd8953e08f38d36bdfc2e68ad6cb8e06fb85b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4105"></a>Aviso LNK4105 (Ferramentas de Vinculador)
nenhum argumento especificado com a opção 'option'; Ignorando a opção  
  
 Este aviso ocorre apenas quando o [/LIBPATH](../../build/reference/libpath-additional-libpath.md) opção é definida. Se nenhuma pasta for especificada com essa opção, o vinculador ignora a opção e gera essa mensagem de aviso.  
  
 Se você não precisar substituir as configurações da biblioteca ambiental existente, remova a opção /LIBPATH da linha de comando do vinculador. Se você quiser usar um caminho de pesquisa alternativas para bibliotecas, especifique um caminho alternativo após a opção /LIBPATH.  
  
## <a name="example"></a>Exemplo  
  
```  
link /libpath:c:\filepath\lib bar.obj  
```  
  
 direcionará o vinculador para pesquisar as bibliotecas necessárias no `c:\filepath\lib` antes de pesquisar nos locais padrão.