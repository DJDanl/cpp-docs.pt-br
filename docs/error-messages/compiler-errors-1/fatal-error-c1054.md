---
title: Erro fatal C1054 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1054
dev_langs:
- C++
helpviewer_keywords:
- C1054
ms.assetid: 9cfb7307-b22a-4418-b7c0-2621b0ab5b1b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a9daac4944c57dbf08fe0ebcbc95993a97838585
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1054"></a>Erro fatal C1054
limite do compilador: inicializadores com aninhamento muito profundo  
  
 O código excede o limite de aninhamento em inicializadores (níveis de 10 a 15, dependendo da combinação de tipos está sendo inicializado).  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Simplifica os tipos de dados que está sendo inicializados para reduzir o aninhamento.  
  
2.  Inicialize variáveis em instruções separadas após a declaração.