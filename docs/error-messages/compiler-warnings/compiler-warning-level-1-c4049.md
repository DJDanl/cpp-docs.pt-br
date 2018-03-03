---
title: "Compilador (nível 1) de aviso C4049 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4049
dev_langs:
- C++
helpviewer_keywords:
- C4049
ms.assetid: d11c1870-bcfc-4d71-8945-b87ec6ec3514
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 15d76be8cdf9855435094d02be5bc28fe27fe89a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4049"></a>Compilador C4049 de aviso (nível 1)
limite do compilador: encerrando emissão de número de linha  
  
 O arquivo contém mais de 16.777.215 (2<sup>24</sup>-1) linhas de origem. O compilador para de numeração em 16.777.215.  
  
 Para o código após a linha 16.777.215:  
  
-   A imagem não conterá nenhuma informação de depuração para números de linha.  
  
-   Alguns diagnósticos podem ser relatados com números de linha incorreta.  
  
-   listagens. ASM (/ FAs) pode ter números de linha incorreta.