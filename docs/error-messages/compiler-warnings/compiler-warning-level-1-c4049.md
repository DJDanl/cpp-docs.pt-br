---
title: Compilador (nível 1) de aviso C4049 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4049
dev_langs:
- C++
helpviewer_keywords:
- C4049
ms.assetid: d11c1870-bcfc-4d71-8945-b87ec6ec3514
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1eea293ff64ed8fe2bf4bf0d38d897eb82223802
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33276823"
---
# <a name="compiler-warning-level-1-c4049"></a>Compilador C4049 de aviso (nível 1)
limite do compilador: encerrando emissão de número de linha  
  
 O arquivo contém mais de 16.777.215 (2<sup>24</sup>-1) linhas de origem. O compilador para de numeração em 16.777.215.  
  
 Para o código após a linha 16.777.215:  
  
-   A imagem não conterá nenhuma informação de depuração para números de linha.  
  
-   Alguns diagnósticos podem ser relatados com números de linha incorreta.  
  
-   listagens. ASM (/ FAs) pode ter números de linha incorreta.