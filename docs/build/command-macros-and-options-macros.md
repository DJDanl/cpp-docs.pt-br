---
title: "Macros de comando e opções | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- options macros
- command macros in NMAKE
- macros, options macros
- macros, command macros
ms.assetid: 50dff03c-0dc3-4a8a-9a17-57e0e4ea9bac
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 06f5d48395c0395a85c90096bf2dbad8627ac41a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="command-macros-and-options-macros"></a>Macros de comando e opções
Macros de comando são predefinidas para produtos da Microsoft. Macros de opção representam opções para esses produtos e não são definidas por padrão. Ambos são usados em regras de inferência predefinidos e podem ser usados em blocos de descrição ou regras de inferência de tipos definidos pelo usuário. Macros de comando podem ser redefinidas para representar a parte ou toda uma linha de comando, incluindo as opções. Macros de opção geram uma cadeia de caracteres nula se esquerda indefinido.  
  
|Produto da Microsoft|Macro de comando|Definido como|Macro de opções|  
|-----------------------|-------------------|----------------|-------------------|  
|Macro Assembler|**COMO**|ml|**AFLAGS**|  
|Compilador básico|**CONTINUIDADE DE NEGÓCIOS**|continuidade de negócios|**BFLAGS**|  
|Compilador C|**CC**|Cl|**CFLAGS**|  
|Compilador C++|**CPP**|Cl|**CPPFLAGS**|  
|Compilador C++|**CXX**|Cl|**CXXFLAGS**|  
|Compilador de Recurso|**RC**|RC|**RFLAGS**|  
  
## <a name="see-also"></a>Consulte também  
 [Macros NMAKE especiais](../build/special-nmake-macros.md)