---
title: Erro fatal RW1025 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RW1025
helpviewer_keywords:
- RW1025
ms.assetid: 561a02af-e7e0-442a-8ad3-a00b2ca1b62e
ms.openlocfilehash: 8ecfc11f5cc991294d966a4b6c75d8da6669d5b1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50575676"
---
# <a name="resource-compiler-fatal-error-rw1025"></a>Erro fatal RW1025 (compilador de recurso)

Falta de memória de heap distante

Verifique se há software residente na memória que pode ser ocupando muito espaço. Use o programa CHKDSK para descobrir quanta memória você tiver.

Se você estiver criando um arquivo de recursos grandes, dividir o script de recurso em dois arquivos. Depois de criar dois arquivos. res, use a linha de comando do MS-DOS para reuni-las:

```
copy first.res /b + second.res /b full.res
```