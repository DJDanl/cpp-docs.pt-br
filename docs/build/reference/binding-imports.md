---
title: Associando importações | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- /DELAY:NOBIND linker option
- DELAY:NOBIND linker option
ms.assetid: bb766038-deb1-41b1-bcbc-29a30e8c1e2a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 551028999d11379c06d3319f01e882a33ad57936
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45705192"
---
# <a name="binding-imports"></a>Associando importações

O comportamento do vinculador padrão é criar uma tabela de endereço de importação associável para a DLL carregadas com atraso. Se a DLL estiver associada, a função auxiliar tentará usar as informações associadas em vez de chamar **GetProcAddress** em cada um das importações mencionadas. Se o carimbo de hora ou o endereço preferido não coincidem com aqueles da DLL carregada, a função auxiliar assumirá que a tabela de endereços de importação associada está desatualizada e continuará como se ele não existe.

Caso não pretenda associar importações carregadas com atraso da DLL, especificando [/Delay](../../build/reference/delay-delay-load-import-settings.md): nobind na linha de comando do vinculador impedirá que a tabela de endereços de importação associado seja gerado e consome espaço no arquivo de imagem.

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)