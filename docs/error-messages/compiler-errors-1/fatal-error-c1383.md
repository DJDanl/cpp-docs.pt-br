---
title: Erro fatal C1383 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1383
dev_langs:
- C++
helpviewer_keywords:
- C1383
ms.assetid: ca224d14-d687-4fd6-80c2-8b82f28924ea
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ae5e16959597e16f25320778be4d4b45ca5950e0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1383"></a>Erro fatal C1383
opção de compilador /GL é incompatível com a versão instalada do common language runtime  
  
 C1383 ocorre quando você estiver usando uma versão anterior do common language runtime com um compilador mais recente, e quando você compilar com **/clr** e **/GL.**  
  
 Para resolver, não use **/GL** com **/clr** ou instale a versão do common language runtime fornecido com o compilador.  
  
 Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) e [/GL (otimização de programa total)](../../build/reference/gl-whole-program-optimization.md).