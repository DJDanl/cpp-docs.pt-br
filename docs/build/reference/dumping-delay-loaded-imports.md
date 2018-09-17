---
title: Despejando importações carregadas com atraso com | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- delay-loaded imports, dumping
- imports (delay-loaded)
- delay-loaded imports
ms.assetid: f766acf4-9df8-4b85-8cf6-0be3ffc4c124
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 29f2faecb29da93729b0be0f40c00c18b82f6344
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45720870"
---
# <a name="dumping-delay-loaded-imports"></a>Despejando importações carregadas com atraso

Importações carregadas com atraso podem ser despejadas usando [/imports (DUMPBIN)](../../build/reference/imports-dumpbin.md) e aparecer com informações ligeiramente diferentes, que importa padrão. Eles são separados em sua própria seção do /imports despejar e explicitamente são rotulados como importações carregadas com atraso. Se não houver descarregar as informações presentes na imagem, que é indicada. Se não houver informações de ligação presentes, o carimbo de data/hora do destino da DLL é observado juntamente com os endereços associados de importações.

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)