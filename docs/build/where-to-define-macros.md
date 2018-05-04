---
title: Onde definir Macros | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- defining macros
- macros, NMAKE
- NMAKE program, defining macros
ms.assetid: 0fc59ec5-5f58-4644-b7da-7b021f7001af
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9cf3e87a50362c770d45f00c4dc17ac3d264f611
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="where-to-define-macros"></a>Onde definir macros
Defina macros em uma linha de comando, arquivo de comando, makefile ou o arquivo Tools.ini.  
  
 Em um makefile ou o arquivo Tools.ini, cada definição de macro deve aparecer em uma linha separada e não pode começar com um espaço ou tabulação. Guias em torno do sinal de igual ou espaços são ignorados. Todos os [cadeia de caracteres](../build/defining-an-nmake-macro.md) são literais, incluindo ao redor de aspas e espaços inseridos.  
  
 Em uma linha de comando ou arquivo de comando, espaços e guias delimitam argumentos em não é possível colocar o sinal de igual. Se `string` tem inseridos espaços ou guias, coloque a cadeia de caracteres ou a macro inteira entre aspas duplas ("").  
  
## <a name="see-also"></a>Consulte também  
 [Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)