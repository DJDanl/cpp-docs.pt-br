---
title: Aviso LNK4105 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4105
helpviewer_keywords:
- LNK4105
ms.assetid: 6c7bebf4-4ea6-4533-a6ed-e563d43abbd7
ms.openlocfilehash: 655a6dfde77984cd0c941ec0d8abb0c4d099c80f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183287"
---
# <a name="linker-tools-warning-lnk4105"></a>Aviso LNK4105 (Ferramentas de Vinculador)

nenhum argumento especificado com a opção ' Option '; ignorando a opção

Esse aviso ocorre somente quando a opção [/LIBPATH](../../build/reference/libpath-additional-libpath.md) está definida. Se nenhum diretório for especificado com essa opção, o vinculador ignorará a opção e gerará essa mensagem de aviso.

Se você não precisar substituir as configurações da biblioteca ambiental existente, remova a opção/LIBPATH da linha de comando do vinculador. Se você quiser usar um caminho de pesquisa alternativo para bibliotecas, especifique o caminho alternativo após a opção/LIBPATH.

## <a name="example"></a>Exemplo

```
link /libpath:c:\filepath\lib bar.obj
```

instruiria o vinculador a pesquisar as bibliotecas necessárias em `c:\filepath\lib` antes de Pesquisar nos locais padrão.
