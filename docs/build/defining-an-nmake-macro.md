---
title: Definindo uma Macro NMAKE | Microsoft Docs
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
- macros, NMAKE
- defining NMAKE macros
- NMAKE macros, defining
ms.assetid: 45aae451-9d33-4a3d-8799-2e0cae17070d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 96799bbd10d442c50d66ac4e84169864b9b989ea
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="defining-an-nmake-macro"></a>Definindo uma macro NMAKE
## <a name="syntax"></a>Sintaxe  
  
```  
  
macroname=string  
```  
  
## <a name="remarks"></a>Comentários  
 O *nomedamacro* é uma combinação de letras, dígitos e sublinhados (_) até 1.024 caracteres e diferencia maiusculas. O *nomedamacro* pode conter uma macro invocada. Se *nomedamacro* consiste inteiramente de uma macro invocada, a macro que está sendo invocada não pode ser nulo ou indefinido.  
  
 O `string` pode ser qualquer sequência de zero ou mais caracteres. Uma cadeia de caracteres nula contém zero caracteres ou apenas espaços ou guias. O `string` pode conter uma chamada de macro.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
 [Caracteres especiais em macros](../build/special-characters-in-macros.md)  
  
 [Macros nulas e indefinidas](../build/null-and-undefined-macros.md)  
  
 [Onde definir macros](../build/where-to-define-macros.md)  
  
 [Precedência em definições de macro](../build/precedence-in-macro-definitions.md)  
  
## <a name="see-also"></a>Consulte também  
 [Macros e NMAKE](../build/macros-and-nmake.md)