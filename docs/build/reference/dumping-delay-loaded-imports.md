---
title: "Despejando importações carregadas com atraso | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- delay-loaded imports, dumping
- imports (delay-loaded)
- delay-loaded imports
ms.assetid: f766acf4-9df8-4b85-8cf6-0be3ffc4c124
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3800d4863bc1aa3e3c847ff0cea886be2fede985
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dumping-delay-loaded-imports"></a>Despejando importações carregadas com atraso
Importações carregadas com atraso podem ser despejadas usando [dumpbin /imports](../../build/reference/imports-dumpbin.md) e mostram informações ligeiramente diferentes que importa padrão. Elas são separadas em sua própria seção do /imports despejar e explicitamente são rotuladas como importações carregadas com atraso. Se houver descarregar informações presentes na imagem, que está disponível. Se não houver informações de associação presentes, o carimbo de data/hora do destino da DLL é registrado junto com os endereços associados de imports.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)