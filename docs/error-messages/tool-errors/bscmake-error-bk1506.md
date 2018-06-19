---
title: BSCMAKE erro BK1506 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- BK1506
dev_langs:
- C++
helpviewer_keywords:
- BK1506
ms.assetid: f51f8cea-f8fc-4323-bcf2-b7bd119792ee
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e19ec77818c8017387519b03e400c09d47021bc5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33300417"
---
# <a name="bscmake-error-bk1506"></a>Erro BK1506 (BSCMAKE)
não é possível abrir o arquivo 'filename' [: motivo]  
  
 BSCMAKE não é possível abrir o arquivo.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Arquivo está bloqueado por outro processo. Se `reason` diz **permissão negada**, o navegador pode estar usando o arquivo. Feche a janela de procura e tente novamente a compilação.  
  
2.  Um disco cheio.  
  
3.  Um erro de hardware.  
  
4.  O arquivo de saída especificado tem o mesmo nome que um subdiretório existente.