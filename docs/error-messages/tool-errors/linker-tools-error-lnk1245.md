---
title: Ferramentas de vinculador LNK1245 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1245
dev_langs:
- C++
helpviewer_keywords:
- LNK1245
ms.assetid: 179c8165-ffbb-44cd-9f24-5250f29577cc
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 11b00a11f617f8ee5eb17e53510b6f97300298fa
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1245"></a>Erro das Ferramentas de Vinculador LNK1245
subsistema inválido 'subsistema' especificado. / O subsistema deve ser WINDOWS, WINDOWSCE ou CONSOLE  
  
 [/CLR](../../build/reference/clr-common-language-runtime-compilation.md) foram usados para compilar o objeto e uma das seguintes condições era true:  
  
-   Um ponto de entrada personalizado foi definido ([/ENTRY](../../build/reference/entry-entry-point-symbol.md)), de modo que o vinculador não foi possível inferir um subsistema.  
  
-   Um valor passado para o [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) opção de vinculador que não é válida para /clr objetos.  
  
 Para ambas as situações, a resolução é especificar um valor válido para a opção de vinculador /SUBSYSTEM.
