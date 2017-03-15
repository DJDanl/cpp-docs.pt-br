---
title: Erro fatal C1126 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1126
dev_langs:
- C++
helpviewer_keywords:
- C1126
ms.assetid: f22b26a6-8ad7-47cf-a237-196c8ea60aca
caps.latest.revision: 7
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
ms.openlocfilehash: 1a8d09dd9edb21dd0986d1a45f56804069204848
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1126"></a>Erro fatal C1126
'identifier': a alocação automática de excede o tamanho  
  
 Espaço alocado para variáveis locais de uma função (mais uma quantidade limitada de espaço usado pelo compilador, como um extra de 20 bytes para funções swap) excede o limite.  
  
 Para corrigir esse erro, use `malloc` ou `new` para alocar uma grande quantidade de dados.
