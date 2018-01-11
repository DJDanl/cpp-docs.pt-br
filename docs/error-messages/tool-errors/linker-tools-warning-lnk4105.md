---
title: Aviso LNK4105 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4105
dev_langs: C++
helpviewer_keywords: LNK4105
ms.assetid: 6c7bebf4-4ea6-4533-a6ed-e563d43abbd7
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 913a6da056908def8df5aab1c2425ef9a187c1e2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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