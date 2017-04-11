---
title: Tratamento de erro (CRT) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.errors
dev_langs:
- C++
helpviewer_keywords:
- error handling, C routines for
- logic errors
- error handling, library routines
- testing, for program errors
ms.assetid: 125ac697-9eb0-4152-a440-b7842f23d97f
caps.latest.revision: 8
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
translationtype: Human Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: ad3844e5d57081b1a9638e197231479b7a03a337
ms.lasthandoff: 03/30/2017

---
# <a name="error-handling-crt"></a>Tratamento de erros (CRT)
Use estas rotinas para tratar erros de programa.  
  
### <a name="error-handling-routines"></a>Rotinas de tratamento de erros  
  
|Rotina|Uso|  
|-------------|---------|  
|[assert](../c-runtime-library/reference/assert-macro-assert-wassert.md) macro|Teste para erros de lógica de programação; disponível nas versões de lançamento e de depuração da biblioteca em tempo de execução.|  
|Macros [_ASSERT, _ASSERTE](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md)|Similar a `assert`, mas disponível apenas nas versões de depuração da biblioteca em tempo de execução.|  
|[clearerr](../c-runtime-library/reference/clearerr.md)|Redefina o indicador de erro. Chamando `rewind` ou fechar um fluxo também redefine o indicador de erro.|  
|[_eof](../c-runtime-library/reference/eof.md)|Verifique o fim do arquivo em E/S de baixo nível.|  
|[feof](../c-runtime-library/reference/feof.md)|Teste para o final do arquivo. Final do arquivo também é indicado quando `_read` retorna 0.|  
|[ferror](../c-runtime-library/reference/ferror.md)|Teste se há erros de E/S de fluxo.|  
|Macros [_RPT, _RPTF](../c-runtime-library/reference/rpt-rptf-rptw-rptfw-macros.md)|Gera um relatório similar a `printf`, mas disponível apenas nas versões de depuração da biblioteca em tempo de execução.|  
|[_set_error_mode](../c-runtime-library/reference/set-error-mode.md)|Modifica `__error_mode` para determinar um local não padrão em que o tempo de execução C grava uma mensagem de erro para um erro que finalizará possivelmente o programa.|  
|[_set_purecall_handler](../c-runtime-library/reference/get-purecall-handler-set-purecall-handler.md)|Define o manipulador para uma chamada de função virtual pura.|  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)
