---
title: Macros de recursão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, recursion macros
- recursion macros
- macros, recursion
ms.assetid: c53e5ae7-619e-46b1-bdc2-86d8c7798b1d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2759deaff6014cbba40c97f9d627baf6a800732f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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