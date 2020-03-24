---
title: Erro fatal RW1025 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RW1025
helpviewer_keywords:
- RW1025
ms.assetid: 561a02af-e7e0-442a-8ad3-a00b2ca1b62e
ms.openlocfilehash: 9b6697dff0a445cc342f30d08bd79822b02df7b8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80172718"
---
# <a name="resource-compiler-fatal-error-rw1025"></a>Erro fatal RW1025 (compilador de recurso)

Sem memória de heap distante

Verifique se há softwares residentes na memória que possam estar ocupando muito espaço. Use o programa CHKDSK para descobrir a quantidade de memória que você tem.

Se você estiver criando um arquivo de recurso grande, divida o script de recurso em dois arquivos. Depois de criar dois arquivos. res, use a linha de comando do MS-DOS para associá-los:

```
copy first.res /b + second.res /b full.res
```
