---
title: Ferramentas de vinculador LNK1245 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1245
dev_langs:
- C++
helpviewer_keywords:
- LNK1245
ms.assetid: 179c8165-ffbb-44cd-9f24-5250f29577cc
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 142d88489748f30308395d64f3db78178a9b856f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1245"></a>Erro das Ferramentas de Vinculador LNK1245
subsistema inválido 'subsistema' especificado. / O subsistema deve ser WINDOWS, WINDOWSCE ou CONSOLE  
  
 [/CLR](../../build/reference/clr-common-language-runtime-compilation.md) foi usado para compilar o objeto e uma das condições a seguir foi verdadeira:  
  
-   Um ponto de entrada personalizado foi definido ([/ENTRY](../../build/reference/entry-entry-point-symbol.md)), de modo que o vinculador não foi possível deduzir um subsistema.  
  
-   Foi passado um valor para o [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) opção de vinculador que não é válida para /clr objetos.  
  
 Para ambas as situações, a resolução é especificar um valor válido para a opção de vinculador /SUBSYSTEM.