---
title: Associando importações
ms.date: 11/04/2016
helpviewer_keywords:
- /DELAY:NOBIND linker option
- DELAY:NOBIND linker option
ms.assetid: bb766038-deb1-41b1-bcbc-29a30e8c1e2a
ms.openlocfilehash: 4058d738b87b69a73e8f18d977be8435a7d96a14
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62272917"
---
# <a name="binding-imports"></a>Associando importações

O comportamento do vinculador padrão é criar uma tabela de endereço de importação associável para a DLL carregadas com atraso. Se a DLL estiver associada, a função auxiliar tentará usar as informações associadas em vez de chamar **GetProcAddress** em cada um das importações mencionadas. Se o carimbo de hora ou o endereço preferido não coincidem com aqueles da DLL carregada, a função auxiliar assumirá que a tabela de endereços de importação associada está desatualizada e continuará como se ele não existe.

Caso não pretenda associar importações carregadas com atraso da DLL, especificando [/Delay](delay-delay-load-import-settings.md): nobind na linha de comando do vinculador impedirá que a tabela de endereços de importação associado seja gerado e consome espaço no arquivo de imagem.

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](linker-support-for-delay-loaded-dlls.md)
