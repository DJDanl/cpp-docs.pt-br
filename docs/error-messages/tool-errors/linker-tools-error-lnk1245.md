---
title: Ferramentas de vinculador LNK1245 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1245
dev_langs:
- C++
helpviewer_keywords:
- LNK1245
ms.assetid: 179c8165-ffbb-44cd-9f24-5250f29577cc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 47a1c2e5f7bf66946dcc5816d7a20fd485b59b45
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-error-lnk1245"></a>Erro das Ferramentas de Vinculador LNK1245
subsistema inválido 'subsistema' especificado. / O subsistema deve ser WINDOWS, WINDOWSCE ou CONSOLE  
  
 [/CLR](../../build/reference/clr-common-language-runtime-compilation.md) foi usado para compilar o objeto e uma das condições a seguir foi verdadeira:  
  
-   Um ponto de entrada personalizado foi definido ([/ENTRY](../../build/reference/entry-entry-point-symbol.md)), de modo que o vinculador não foi possível deduzir um subsistema.  
  
-   Foi passado um valor para o [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) opção de vinculador que não é válida para /clr objetos.  
  
 Para ambas as situações, a resolução é especificar um valor válido para a opção de vinculador /SUBSYSTEM.