---
title: Erro de linha de comando D8045 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- D8045
dev_langs:
- C++
helpviewer_keywords:
- D8045
ms.assetid: 01c8808c-bac1-4b4d-8a90-b595f95e9318
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9489535e0a1f9873d2c299ae8a9766bcbb5035dc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="command-line-error-d8045"></a>Erro D8045 (linha de comando)
não é possível compilar arquivo C 'file' com a opção /clr  
  
 Apenas C++ arquivos de código fonte podem ser passados para uma compilação que usa **/clr**.  Use **/TP** para compilar um arquivo. c como um arquivo. cpp; consulte [/Tc, /Tp, /TC, /TP (especificar o tipo de arquivo de origem)](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) para obter mais informações.  
  
 Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 D8045 também poderá ocorrer se você compilar um aplicativo ATL usando o Visual C++. Consulte [como: migrar para /clr](../../dotnet/how-to-migrate-to-clr.md) para obter mais informações.