---
title: _purecall | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _purecall
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ntoskrnl.exe
- ucrtbase.dll
apitype: DLLExport
f1_keywords:
- purecall
- _purecall
dev_langs:
- C++
helpviewer_keywords:
- _purecall function
- purecall function
ms.assetid: 56135d9b-3403-4e22-822d-e714523801cc
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
translationtype: Machine Translation
ms.sourcegitcommit: d18aa1a4b5c5616e02b67b50d2e6e6c9e55b7a8d
ms.openlocfilehash: 21bccf888776bea1d4a01020a8ca07d9cc91e421
ms.lasthandoff: 02/25/2017

---
# <a name="purecall"></a>_purecall
O manipulador de erro de chamada de função pura virtual padrão. O compilador gera código para chamar esta função quando uma função membro pura virtual é chamada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
extern "C" int __cdecl _purecall();  
```  
  
## <a name="remarks"></a>Comentários  
 A função `_purecall` é um detalhe de implementação específico da Microsoft do compilador do Microsoft Visual C++. Essa função não se destina a ser chamada diretamente pelo seu código e não tem nenhuma declaração de cabeçalho público. Ela está documentada aqui porque é uma exportação pública da Biblioteca de Tempo de Execução C.  
  
 Uma chamada para uma função virtual pura é um erro porque não tem nenhuma implementação. O compilador gera código para invocar a função do manipulador de erro `_purecall` quando uma função membro pura virtual é chamada. Por padrão, `_purecall` termina o programa. Antes de terminar, a função `_purecall` invoca um a função `_purecall_handler` se uma tiver sido definida para o processo de função. Você pode instalar sua própria função de manipulador de erro para chamadas de função pura virtual, para capturá-las para fins de depuração ou relatório. Para usar seu próprio manipulador de erro, crie uma função que tenha a assinatura `_purecall_handler` e use [_set_purecall_handler](../../c-runtime-library/reference/get-purecall-handler-set-purecall-handler.md) para torná-lo o manipulador atual.  
  
## <a name="requirements"></a>Requisitos  
 A função `_purecall` não tem uma declaração de cabeçalho. O typedef `_purecall_handler` é definido em \<stdlib.h>.  
  
## <a name="see-also"></a>Consulte também  
 [Referência da Função Alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [_get_purecall_handler, _set_purecall_handler](../../c-runtime-library/reference/get-purecall-handler-set-purecall-handler.md)
