---
title: C2220 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2220
dev_langs: C++
helpviewer_keywords: C2220
ms.assetid: d610802c-64d7-40ad-a2a6-0ed0b6815a6c
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 14da9ea0905f2aa7aa67c2b7524314a4af74246b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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