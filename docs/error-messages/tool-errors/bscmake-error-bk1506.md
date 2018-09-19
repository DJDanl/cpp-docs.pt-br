---
title: Erro de BSCMAKE BK1506 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- BK1506
dev_langs:
- C++
helpviewer_keywords:
- BK1506
ms.assetid: f51f8cea-f8fc-4323-bcf2-b7bd119792ee
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 26201a894212701cca19ab2192676b37a69e8b57
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088690"
---
# <a name="bscmake-error-bk1506"></a>Erro BK1506 (BSCMAKE)

não é possível abrir o arquivo 'filename' [: motivo]

BSCMAKE não é possível abrir o arquivo.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Arquivo bloqueado por outro processo. Se `reason` diz **permissão negada**, o navegador pode estar usando o arquivo. Feche a janela de procura e tente novamente a compilação.

1. Um disco cheio.

1. Um erro de hardware.

1. O arquivo de saída especificado tem o mesmo nome que um subdiretório existente.