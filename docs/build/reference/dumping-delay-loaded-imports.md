---
title: Despejando importações carregadas com atraso
ms.date: 11/04/2016
helpviewer_keywords:
- delay-loaded imports, dumping
- imports (delay-loaded)
- delay-loaded imports
ms.assetid: f766acf4-9df8-4b85-8cf6-0be3ffc4c124
ms.openlocfilehash: 368c6b851340dd2a39df9a758f15d52ff5104479
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57809906"
---
# <a name="dumping-delay-loaded-imports"></a>Despejando importações carregadas com atraso

Importações carregadas com atraso podem ser despejadas usando [/imports (DUMPBIN)](imports-dumpbin.md) e aparecer com informações ligeiramente diferentes, que importa padrão. Eles são separados em sua própria seção do /imports despejar e explicitamente são rotulados como importações carregadas com atraso. Se não houver descarregar as informações presentes na imagem, que é indicada. Se não houver informações de ligação presentes, o carimbo de data/hora do destino da DLL é observado juntamente com os endereços associados de importações.

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](linker-support-for-delay-loaded-dlls.md)
