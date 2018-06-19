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
ms.openlocfilehash: 7519fb18ac7f24e79a5f7f664cb35f8eb5b3fd77
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32368922"
---
# <a name="binding-imports"></a>Associando importações
O comportamento de vinculador padrão é criar uma tabela de endereço de importação associável para a DLL carregada com atraso. Se a DLL está associada, a função auxiliar tentará usar as informações associadas em vez de chamar **GetProcAddress** em cada um dos imports referenciado. Se o carimbo de hora ou o endereço preferencial não coincidem com aqueles da DLL carregada, a função auxiliar pressupõem a tabela de endereço associado importação está desatualizada e continuará como se ele não existe.  
  
 Se você nunca pretende associar importações carregadas com atraso da DLL, especificando [/Delay](../../build/reference/delay-delay-load-import-settings.md): nobind na linha de comando do vinculador impedirá que a tabela de endereço associado importação seja gerado e consome espaço no arquivo de imagem.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)