---
title: Erro fatal C1055 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1055
dev_langs:
- C++
helpviewer_keywords:
- C1055
ms.assetid: a9fb9190-d7eb-4d5f-b1a2-a41e584a28c1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 07f0dc0e8dca08e8b0de47b73516d3fdfa21435b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1055"></a>Erro fatal C1055
limite do compilador: sem chaves  
  
 O arquivo de origem contém um número excessivo de símbolos. O compilador insuficiente de chaves de hash para a tabela de símbolos.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Divida o arquivo de origem em arquivos menores.  
  
2.  Elimine arquivos de cabeçalho desnecessários.  
  
3.  Reutilize variáveis globais e temporários em vez de criar novos.