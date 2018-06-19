---
title: Macros de comando e opções | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- options macros
- command macros in NMAKE
- macros, options macros
- macros, command macros
ms.assetid: 50dff03c-0dc3-4a8a-9a17-57e0e4ea9bac
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ab8b1d61c2c4f6ae9125b8eefaf05f791f57b259
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32367353"
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