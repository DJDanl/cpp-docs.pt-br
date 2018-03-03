---
title: BSCMAKE erro BK1506 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- BK1506
dev_langs:
- C++
helpviewer_keywords:
- BK1506
ms.assetid: f51f8cea-f8fc-4323-bcf2-b7bd119792ee
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0f553646689fd1e703e10f100bca6d989c8f767d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="bscmake-error-bk1506"></a>Erro BK1506 (BSCMAKE)
não é possível abrir o arquivo 'filename' [: motivo]  
  
 BSCMAKE não é possível abrir o arquivo.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Arquivo está bloqueado por outro processo. Se `reason` diz **permissão negada**, o navegador pode estar usando o arquivo. Feche a janela de procura e tente novamente a compilação.  
  
2.  Um disco cheio.  
  
3.  Um erro de hardware.  
  
4.  O arquivo de saída especificado tem o mesmo nome que um subdiretório existente.