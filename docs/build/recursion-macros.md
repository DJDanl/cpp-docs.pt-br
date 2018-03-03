---
title: "Macros de recursão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, recursion macros
- recursion macros
- macros, recursion
ms.assetid: c53e5ae7-619e-46b1-bdc2-86d8c7798b1d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e8d9ef7f194151fb3259712759d0c29ed157d564
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="recursion-macros"></a>Macros de recursão
Use macros de recursão para chamar NMAKE recursivamente. Sessões recursiva herdam macros de variável de ambiente e de linha de comando e Tools.ini informações. Eles não herdam a regras de inferência definido makefile ou **. SUFIXOS** e **. PRECIOSOS** especificações. Para passar a uma sessão NMAKE recursiva macros, definir uma variável de ambiente com definida antes da chamada recursiva, definir uma macro no comando para a chamada recursiva ou definir uma macro em Tools.ini.  
  
|Macro|Definição|  
|-----------|----------------|  
|**FAZER**|Comando usado originalmente para invocar NMAKE.<br /><br /> A macro $(MAKE) fornece o caminho completo para nmake.exe.|  
|**MAKEDIR**|Diretório atual quando NMAKE foi invocado.|  
|**MAKEFLAGS**|Opções atualmente em vigor. Usar como `/$(MAKEFLAGS)`.  Observe que /F não está incluído.|  
  
## <a name="see-also"></a>Consulte também  
 [Macros NMAKE especiais](../build/special-nmake-macros.md)