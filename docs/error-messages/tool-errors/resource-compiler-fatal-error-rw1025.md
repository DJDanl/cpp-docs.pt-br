---
title: RW1025 de Erro Fatal do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RW1025
dev_langs:
- C++
helpviewer_keywords:
- RW1025
ms.assetid: 561a02af-e7e0-442a-8ad3-a00b2ca1b62e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2bf7bdeed320c004ffb75fa1d25d9b89147b0c13
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46117394"
---
# <a name="resource-compiler-fatal-error-rw1025"></a>Erro fatal RW1025 (compilador de recurso)

Falta de memória de heap distante

Verifique se há software residente na memória que pode ser ocupando muito espaço. Use o programa CHKDSK para descobrir quanta memória você tiver.

Se você estiver criando um arquivo de recursos grandes, dividir o script de recurso em dois arquivos. Depois de criar dois arquivos. res, use a linha de comando do MS-DOS para reuni-las:

```
copy first.res /b + second.res /b full.res
```