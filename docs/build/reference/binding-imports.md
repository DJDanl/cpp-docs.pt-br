---
title: "Associando importações | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- /DELAY:NOBIND linker option
- DELAY:NOBIND linker option
ms.assetid: bb766038-deb1-41b1-bcbc-29a30e8c1e2a
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: cd9bee6423c0eea98941331dcff86c002dd4ef9d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="binding-imports"></a>Associando importações
O comportamento de vinculador padrão é criar uma tabela de endereço de importação associável para a DLL carregada com atraso. Se a DLL está associada, a função auxiliar tentará usar as informações associadas em vez de chamar **GetProcAddress** em cada um dos imports referenciado. Se o carimbo de hora ou o endereço preferencial não coincidem com aqueles da DLL carregada, a função auxiliar pressupõem a tabela de endereço associado importação está desatualizada e continuará como se ele não existe.  
  
 Se você nunca pretende associar importações carregadas com atraso da DLL, especificando [/Delay](../../build/reference/delay-delay-load-import-settings.md): nobind na linha de comando do vinculador impedirá que a tabela de endereço associado importação seja gerado e consome espaço no arquivo de imagem.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)