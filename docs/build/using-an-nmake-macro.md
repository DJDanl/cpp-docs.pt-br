---
title: Usando uma Macro NMAKE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- macros, NMAKE
- NMAKE macros, using
ms.assetid: 95c87fbc-76e6-48c0-8536-9bfe179f328e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c6bf098a3723aa7b067b8192bf503975998e4e98
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="using-an-nmake-macro"></a>Usando uma macro NMAKE
Para usar uma macro, coloque o seu nome entre parênteses, precedidos por um sinal de cifrão ($), da seguinte maneira.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
$(macroname)  
```  
  
## <a name="remarks"></a>Comentários  
 Não são permitidos espaços. Os parênteses são opcionais se *nomedamacro* é um caractere único. A cadeia de caracteres de definição substitui $(*nomedamacro*); uma macro é substituída por uma cadeia de caracteres nula.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
 [Substituição de macro](../build/macro-substitution.md)  
  
## <a name="see-also"></a>Consulte também  
 [Macros e NMAKE](../build/macros-and-nmake.md)