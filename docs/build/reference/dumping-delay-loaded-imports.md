---
title: Despejando importações carregadas com atraso | Microsoft Docs
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
ms.openlocfilehash: 13f832f0ea7aaf7b766141ce7df4f83f21e1cdca
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32372861"
---
# <a name="dumping-delay-loaded-imports"></a>Despejando importações carregadas com atraso
Importações carregadas com atraso podem ser despejadas usando [dumpbin /imports](../../build/reference/imports-dumpbin.md) e mostram informações ligeiramente diferentes que importa padrão. Elas são separadas em sua própria seção do /imports despejar e explicitamente são rotuladas como importações carregadas com atraso. Se houver descarregar informações presentes na imagem, que está disponível. Se não houver informações de associação presentes, o carimbo de data/hora do destino da DLL é registrado junto com os endereços associados de imports.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)