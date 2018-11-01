---
title: Aviso LNK4105 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4105
helpviewer_keywords:
- LNK4105
ms.assetid: 6c7bebf4-4ea6-4533-a6ed-e563d43abbd7
ms.openlocfilehash: 880c8519a530f492d0c322575a1386af8a7d0187
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50475577"
---
# <a name="linker-tools-warning-lnk4105"></a>Aviso LNK4105 (Ferramentas de Vinculador)

nenhum argumento especificado com a opção 'option'; Ignorando opção

Este aviso ocorre apenas quando o [/LIBPATH](../../build/reference/libpath-additional-libpath.md) opção está definida. Se nenhum diretório for especificado com essa opção, o vinculador ignora a opção e gera essa mensagem de aviso.

Se você não precisar substituir as configurações existentes da biblioteca ambiental, remova a opção /LIBPATH da linha de comando do vinculador. Se você quiser usar um caminho de pesquisa alternativas para as bibliotecas, especifique um caminho alternativo após a opção /LIBPATH.

## <a name="example"></a>Exemplo

```
link /libpath:c:\filepath\lib bar.obj
```

direcionará o vinculador para procurar as bibliotecas necessárias no `c:\filepath\lib` antes de pesquisar nos locais padrão.