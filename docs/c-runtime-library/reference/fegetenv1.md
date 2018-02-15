---
title: fegetenv1 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- fetegenv
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
- ucrtbase.dll
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- fegetenv
- fenv/fegetenv
dev_langs:
- C++
helpviewer_keywords:
- fetegenv function
ms.assetid: 68962421-6978-4b27-8e4c-ad1577830cf6
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 025b934ec6a2d9bc98d46cabbd13b93e263cd777
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="fegetenv"></a>fegetenv
Armazena o ambiente atual de ponto flutuante no objeto especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int fegetenv(  
   fenv_t *penv  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `penv`  
 Ponteiro para um objeto `fenv_t` para conter os valores de ponto flutuante do ambiente atual.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna 0 se o ambiente de ponto flutuante foi armazenado com êxito em `penv`. Caso contrário, retornará um valor diferente de zero.  
  
## <a name="remarks"></a>Comentários  
 A função `fegetenv` armazena o ambiente atual de ponto flutuante no objeto apontado por `penv`. O ambiente de ponto flutuante é o conjunto de sinalizadores de status e modos de controle que afetam os cálculos de pontos flutuantes. Isso inclui o modo de direção de arredondamento e os sinalizadores de status para exceções de ponto flutuante.  Se `penv` não aponta para um objeto `fenv_t` válido, o comportamento subsequente é indefinido.  
  
 Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C++|  
|--------------|--------------|------------------|  
|`fegetenv`|\<fenv.h>|\<cfenv>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [fesetenv](../../c-runtime-library/reference/fesetenv1.md)