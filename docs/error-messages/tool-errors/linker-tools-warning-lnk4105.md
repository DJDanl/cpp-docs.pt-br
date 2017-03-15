---
title: Aviso LNK4105 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4105
dev_langs:
- C++
helpviewer_keywords:
- LNK4105
ms.assetid: 6c7bebf4-4ea6-4533-a6ed-e563d43abbd7
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f7d0a4e956ec78dfdac7f54895405025bdb11559
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4105"></a>Aviso LNK4105 (Ferramentas de Vinculador)
nenhum argumento especificado com a opção ''; Ignorando opção  
  
 Este aviso ocorre apenas quando o [/LIBPATH](../../build/reference/libpath-additional-libpath.md) opção é definida. Se nenhuma pasta for especificada com esta opção, o vinculador ignora a opção e gera essa mensagem de aviso.  
  
 Se você não precisar substituir as configurações de biblioteca ambiental existente, remova a opção /LIBPATH da linha de comando do vinculador. Se você quiser usar um caminho de pesquisa alternativos para bibliotecas, especifique o caminho alternativo após a opção /LIBPATH.  
  
## <a name="example"></a>Exemplo  
  
```  
link /libpath:c:\filepath\lib bar.obj  
```  
  
 direcionará o vinculador procure as bibliotecas necessárias no `c:\filepath\lib` antes de pesquisar nos locais padrão.
