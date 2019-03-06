---
title: Despejando importações carregadas com atraso
ms.date: 11/04/2016
helpviewer_keywords:
- delay-loaded imports, dumping
- imports (delay-loaded)
- delay-loaded imports
ms.assetid: f766acf4-9df8-4b85-8cf6-0be3ffc4c124
ms.openlocfilehash: 208be91d9ee873bd181bdb6c7880a6f9032e0d90
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57423944"
---
# <a name="dumping-delay-loaded-imports"></a>Despejando importações carregadas com atraso

Importações carregadas com atraso podem ser despejadas usando [/imports (DUMPBIN)](../../build/reference/imports-dumpbin.md) e aparecer com informações ligeiramente diferentes, que importa padrão. Eles são separados em sua própria seção do /imports despejar e explicitamente são rotulados como importações carregadas com atraso. Se não houver descarregar as informações presentes na imagem, que é indicada. Se não houver informações de ligação presentes, o carimbo de data/hora do destino da DLL é observado juntamente com os endereços associados de importações.

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)
