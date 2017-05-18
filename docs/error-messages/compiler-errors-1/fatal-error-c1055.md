---
title: Erro fatal C1055 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1055
dev_langs:
- C++
helpviewer_keywords:
- C1055
ms.assetid: a9fb9190-d7eb-4d5f-b1a2-a41e584a28c1
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ace44f1d16aefd1dd28d7b5e37952948f6b8f32c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1055"></a>Erro fatal C1055
limite do compilador : chaves insuficientes  
  
 O arquivo de origem contém muitos símbolos. O compilador ficou sem chaves de hash para a tabela de símbolos.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir, usando as seguintes soluções possíveis  
  
1.  Divida o arquivo de origem em arquivos menores.  
  
2.  Elimine arquivos de cabeçalho desnecessários.  
  
3.  Reutilize variáveis temporárias e global em vez de criar novos.
