---
title: Erro de linha de comando D8045 | Documentos do Microsoft
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
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 7884f2fac6df867c51fa4c3cb3cd6f6c56ee2594
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="command-line-error-d8045"></a>Erro D8045 (linha de comando)
não é possível compilar o arquivo C 'file' com a opção /clr  
  
 Apenas C++ arquivos de código fonte podem ser passados para uma compilação que usa **/clr**.  Use **/TP** para compilar um arquivo. c como um arquivo. cpp; consulte [/Tc, /Tp, /TC, /TP (especificar o tipo de arquivo de origem)](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) para obter mais informações.  
  
 Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 D8045 também pode ocorrer se você compilar um aplicativo ATL usando o Visual C++. Consulte [como: migrar para /clr](../../dotnet/how-to-migrate-to-clr.md) para obter mais informações.
