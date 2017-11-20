---
title: Onde definir Macros | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- defining macros
- macros, NMAKE
- NMAKE program, defining macros
ms.assetid: 0fc59ec5-5f58-4644-b7da-7b021f7001af
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: cfb17f531df5c232f1f376cd003acb7bf5a62206
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="where-to-define-macros"></a>Onde definir macros
Defina macros em uma linha de comando, arquivo de comando, makefile ou o arquivo Tools.ini.  
  
 Em um makefile ou o arquivo Tools.ini, cada definição de macro deve aparecer em uma linha separada e não pode começar com um espaço ou tabulação. Guias em torno do sinal de igual ou espaços são ignorados. Todos os [cadeia de caracteres](../build/defining-an-nmake-macro.md) são literais, incluindo ao redor de aspas e espaços inseridos.  
  
 Em uma linha de comando ou arquivo de comando, espaços e guias delimitam argumentos em não é possível colocar o sinal de igual. Se `string` tem inseridos espaços ou guias, coloque a cadeia de caracteres ou a macro inteira entre aspas duplas ("").  
  
## <a name="see-also"></a>Consulte também  
 [Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)