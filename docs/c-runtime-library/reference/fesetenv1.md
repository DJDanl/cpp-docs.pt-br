---
title: fesetenv1 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- fesetenv
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
- fesetenv
- fenv/fesetenv
dev_langs:
- C++
helpviewer_keywords:
- fesetenv function
ms.assetid: ffc64fff-8ea7-4d59-9e04-ff96ef8cd012
caps.latest.revision: 6
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 40e20a2c6a3f3c22b9206ce078146b44bb841f68
ms.lasthandoff: 02/25/2017

---
# <a name="fesetenv"></a>fesetenv
Define o ambiente atual de ponto flutuante.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int fesetenv(  
   const fenv_t *penv  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `penv`  
 Ponteiro para um objeto `fenv_t` que contém um ambiente de ponto flutuante conforme definido por uma chamada a [fegetenv](http://msdn.microsoft.com/Library/61df848d-6ba8-4c6e-be35-216436fe7736) ou [feholdexcept](http://msdn.microsoft.com/Library/c286ace3-ec39-482a-be8b-f998d31003d9). Você também pode especificar o ambiente de ponto flutuante de inicialização padrão usando a macro FE_DFL_ENV.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna 0 se o ambiente foi definido com êxito.        Caso contrário, retornará um valor diferente de zero.  
  
## <a name="remarks"></a>Comentários  
 A função `fesetenv` define o ambiente atual de ponto flutuante dos valores armazenados no objeto `fenv_t` apontado por `penv`. O ambiente de ponto flutuante é o conjunto de sinalizadores de status e modos de controle que afetam os cálculos de pontos flutuantes. Isso inclui o modo de arredondamento e os sinalizadores de status para exceções de ponto flutuante.  Se `penv` não for FE_DFL_ENV ou não apontar para um objeto `fenv_t` válido, o comportamento subsequente será indefinido.  
  
 Uma chamada para essa função define os sinalizadores de status da exceção que estão no objeto `penv`, mas não geram essas exceções.  
  
 Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C++|  
|--------------|--------------|------------------|  
|`fesetenv`|\<fenv.h>|\<cfenv>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência da Função Alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [fegetenv](../../c-runtime-library/reference/fegetenv1.md)   
 [feclearexcept](../../c-runtime-library/reference/feclearexcept1.md)   
 [feholdexcept](../../c-runtime-library/reference/feholdexcept2.md)   
 [fesetexceptflag](../../c-runtime-library/reference/fesetexceptflag2.md)
