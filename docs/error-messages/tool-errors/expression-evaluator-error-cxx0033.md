---
title: "CXX0033 de erro do avaliador de expressão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
caps.latest.revision: 6
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
ms.openlocfilehash: 3df60f5eed5a5018fd5dade69d10e1302db868f1
ms.lasthandoff: 02/25/2017

---
# <a name="expression-evaluator-error-cxx0033"></a>Erro CXX0033 (avaliador de expressão)
erro em informações do tipo OMF  
  
 O arquivo executável não tinha um formato de módulo de objeto válido (OMF) para depuração.  
  
 Esse erro é idêntico ao CAN0033.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  O arquivo executável não foi criado com o vinculador lançado com essa versão do Visual C++. Vincular novamente o código de objeto usando a versão atual do LINK.exe.  
  
2.  O arquivo .exe pode ter sido corrompido. Recompilar e vincular novamente o programa.
