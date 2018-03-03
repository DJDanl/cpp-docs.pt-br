---
title: "CXX0033 de erro do avaliador de expressão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CXX0033
dev_langs:
- C++
helpviewer_keywords:
- CAN0033
- CXX0033
ms.assetid: 0bd62c5b-de89-481f-9b12-88fe84805afe
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 49f2b6221d385587fa5e62af51d37eb7d3b78872
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="expression-evaluator-error-cxx0033"></a>Erro CXX0033 (avaliador de expressão)
Erro ao obter informações do tipo OMF  
  
 O arquivo executável não tinha um formato de módulo de objeto válido (OMF) para depuração.  
  
 Esse erro é idêntico ao CAN0033.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  O arquivo executável não foi criado com o vinculador lançado com essa versão do Visual C++. Vincular novamente o código de objeto usando a versão atual do LINK.exe.  
  
2.  O arquivo .exe pode ter sido corrompido. Recompilar e vincular novamente o programa.