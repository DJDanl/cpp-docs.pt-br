---
title: Compilador aviso (nível 3) C4192 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4192
dev_langs:
- C++
helpviewer_keywords:
- C4192
ms.assetid: ea5f91fa-8c96-4f3f-ac42-0c8a86d4e5df
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3bae9b7af95de94b8f667cb09710af21044f8b80
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33291408"
---
# <a name="compiler-warning-level-3-c4192"></a>Compilador C4192 de aviso (nível 3)
excluindo automaticamente 'name' durante a importação de biblioteca de tipos 'library'  
  
 Um `#import` biblioteca contém um item, *nome*, que é também definido nos cabeçalhos de sistema do Win32. Devido às limitações das bibliotecas de tipo, nomes, como **IUnknown** ou GUID geralmente são definidas em uma biblioteca de tipos, duplicar a definição de cabeçalhos de sistema. `#import` detectará esses itens e recusar incorporá-las nos arquivos de cabeçalho. TLH e .tli.  
  
 Para substituir esse comportamento, use `#import` atributos [no_auto_exclude](../../preprocessor/no-auto-exclude.md) e [include()](../../preprocessor/include-parens.md).