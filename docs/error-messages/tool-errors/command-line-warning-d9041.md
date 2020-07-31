---
title: Aviso D9041 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D9041
helpviewer_keywords:
- D9041
ms.assetid: ada8815f-4246-4e25-b57d-a7f16fa107cc
ms.openlocfilehash: e685e9bd0ffb58065f20f466131f8894baaf359f
ms.sourcegitcommit: 6e55aeb538b1c39af754f82d6f7738a18f5aa031
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/29/2020
ms.locfileid: "87389721"
---
# <a name="command-line-warning-d9041"></a>Aviso D9041 (linha de comando)

> valor inválido '*option-value*' para '/*Option-Name*'; assumindo '*pressuposto-Value*'; Adicionar '/ANALYZE ' às opções de linha de comando ao especificar este aviso

Um número de aviso da análise de código foi adicionado à **`/wd`** opção de linha de comando,, **`/we`** **`/wo`** ou **`/wl`** sem especificar também a **`/analyze`** opção de linha de comando. Para corrigir esse erro, adicione a **`/analyze`** opção de linha de comando ou remova o número de aviso inválido da **`/w`** opção de linha de comando apropriada.

## <a name="example"></a>Exemplo

O exemplo de linha de comando a seguir gera o aviso D9041:

```cmd
cl /EHsc /LD /wd6001 filename.cpp
```

Para corrigir o aviso, adicione a **`/analyze`** opção de linha de comando. Se o **`/analyze`** não tiver suporte em sua versão do compilador, remova o número de aviso inválido da **`/wd`** opção.

## <a name="see-also"></a>Confira também

[Erros de linha de comando D8000 até D9999](../../error-messages/tool-errors/command-line-errors-d8000-through-d9999.md)<br/>
[Opções do compilador MSVC](../../build/reference/compiler-options.md)
