---
title: Ferramentas de vinculador LNK4105 aviso | Microsoft Docs
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
ms.openlocfilehash: 4411421741cf8bf7c714a6322d58bd177e7e7270
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46024977"
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