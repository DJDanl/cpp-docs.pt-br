---
title: CXX0033 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0033
dev_langs:
- C++
helpviewer_keywords:
- CAN0033
- CXX0033
ms.assetid: 0bd62c5b-de89-481f-9b12-88fe84805afe
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 720b1aec6c9be16879119bc0e8148a301507577a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33299494"
---
# <a name="expression-evaluator-error-cxx0033"></a>Erro CXX0033 (avaliador de expressão)
Erro ao obter informações do tipo OMF  
  
 O arquivo executável não tinha um formato de módulo de objeto válido (OMF) para depuração.  
  
 Esse erro é idêntico ao CAN0033.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  O arquivo executável não foi criado com o vinculador lançado com essa versão do Visual C++. Vincular novamente o código de objeto usando a versão atual do LINK.exe.  
  
2.  O arquivo .exe pode ter sido corrompido. Recompilar e vincular novamente o programa.