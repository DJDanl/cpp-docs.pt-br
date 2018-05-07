---
title: C2220 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2220
dev_langs:
- C++
helpviewer_keywords:
- C2220
ms.assetid: d610802c-64d7-40ad-a2a6-0ed0b6815a6c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d23476de35e0af45b46a775683ba8673b4959346
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2220"></a>C2220 de erro do compilador
Aviso tratado como erro - nenhum arquivo de objeto gerado  
  
 [/WX](../../build/reference/compiler-option-warning-level.md) informa ao compilador trate todos os avisos como erros. Porque ocorreu um erro, nenhum objeto ou arquivo executável foi gerado.  
  
 Esse erro aparece somente quando o **/WX** sinalizador é definido e ocorrer um aviso durante a compilação. Para corrigir esse erro, você deve eliminar cada aviso em seu projeto.  
  
### <a name="to-fix-use-one-of-the-following-techniques"></a>Para corrigir, use uma das seguintes técnicas  
  
-   Corrija os problemas que causam avisos em seu projeto.  
  
-   Em um nível inferior do aviso de compilação — por exemplo, use **/W3** em vez de **/W4**.  
  
-   Use um [aviso](../../preprocessor/warning.md) pragma para desabilitar ou suprimir um aviso específico.  
  
-   Não use **/WX** para compilar.