---
title: Operador de caracterização (#@) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- '#@'
dev_langs:
- C++
helpviewer_keywords:
- preprocessor, operators
- charizing operator
- '#@ preprocessor operator'
ms.assetid: dee03314-d27c-4063-965c-64756efbef22
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d86c49c8d7d0cda91ba2415167cc79c810a96b3d
ms.sourcegitcommit: d10a2382832373b900b1780e1190ab104175397f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2018
ms.locfileid: "43895299"
---
# <a name="charizing-operator-"></a>Operador de caracterização (#@)
**Seção específica da Microsoft**

O operador de charizing pode usado apenas com os argumentos das macros. Se `#@` preceder um parâmetro formal na definição da macro, o argumento real é colocado entre aspas simples e tratado como um caractere quando a macro é expandida. Por exemplo:

```
#define makechar(x)  #@x
```

faz com que a instrução

```
a = makechar(b);
```

seja expandida para

```
a = 'b';
```

O caractere de aspas simples não pode ser usado com o operador de charizing.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Operadores de pré-processador](../preprocessor/preprocessor-operators.md)