---
title: C2220 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2220
dev_langs:
- C++
helpviewer_keywords:
- C2220
ms.assetid: d610802c-64d7-40ad-a2a6-0ed0b6815a6c
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: dc31519b2153c66ea9bab42f536ba7c6be5b2a10
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

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
