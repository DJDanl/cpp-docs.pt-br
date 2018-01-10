---
title: auto_inline | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- auto_inline_CPP
- vc-pragma.auto_inline
dev_langs: C++
helpviewer_keywords:
- pragmas, auto_inline
- auto_inline pragma
ms.assetid: f7624cd1-be76-429a-881c-65c9040acf43
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 46a1ca697e12a5abe9745a558abf20b73fef8184
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="autoinline"></a>auto_inline
Exclui todas as funções definidas dentro do intervalo em que **off** especificado a partir do sendo considerados candidatos para expansão inline automática.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma auto_inline( [{on | off}] )  
```  
  
## <a name="remarks"></a>Comentários  
 Para usar o **auto_inline** pragma, coloque-o imediatamente antes e depois (não no) uma definição de função. O pragma entra em vigor na primeira definição de função, após a consideração do pragma.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)