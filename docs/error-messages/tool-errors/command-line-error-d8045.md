---
title: Erro de linha de comando D8045 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- D8045
dev_langs:
- C++
helpviewer_keywords:
- D8045
ms.assetid: 01c8808c-bac1-4b4d-8a90-b595f95e9318
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4cf1248c072374cbe65d74136dfd1a8680e483b0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33297083"
---
# <a name="command-line-error-d8045"></a>Erro D8045 (linha de comando)
não é possível compilar arquivo C 'file' com a opção /clr  
  
 Apenas C++ arquivos de código fonte podem ser passados para uma compilação que usa **/clr**.  Use **/TP** para compilar um arquivo. c como um arquivo. cpp; consulte [/Tc, /Tp, /TC, /TP (especificar o tipo de arquivo de origem)](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) para obter mais informações.  
  
 Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 D8045 também poderá ocorrer se você compilar um aplicativo ATL usando o Visual C++. Consulte [como: migrar para /clr](../../dotnet/how-to-migrate-to-clr.md) para obter mais informações.