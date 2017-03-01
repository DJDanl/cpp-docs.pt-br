---
title: fesetexceptflag2 | Microsoft Docs
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
- fesetexceptflag
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
- fesetexceptflag
- fenv/fesetexceptflag
dev_langs:
- C++
helpviewer_keywords:
- fesetexceptflag function
ms.assetid: 2f7dad77-9e54-4097-a3e3-35176ace4de5
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: e03e1a12b27eb5401a31f7096ae46d8a779d4a70
ms.lasthandoff: 02/25/2017

---
# <a name="fesetexceptflag"></a>fesetexceptflag
Define os sinalizadores de status de ponto flutuante especificados no ambiente atual de ponto flutuante.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int fesetexceptflag(  
     const fexcept_t *pstatus,  
     int excepts  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pstatus`  
 Ponteiro para um objeto `fexcept_t` que contém os valores para definição dos sinalizadores de status de exceção. O objeto pode ser definido por uma chamada anterior a [fegetexceptflag](http://msdn.microsoft.com/Library/5031bc1a-9834-4573-9113-160a55eb9654).  
  
 `excepts`  
 Os sinalizadores do status de exceção de ponto flutuante que serão definidos.  
  
## <a name="return-value"></a>Valor de retorno  
 Se todos os sinalizadores de status de exceção especificados forem definidos com êxito, retornará 0. Caso contrário, retornará um valor diferente de zero.  
  
## <a name="remarks"></a>Comentários  
 A função `fesetexceptflag` define o estado dos sinalizadores de status de exceção de ponto flutuante especificados por `excepts` para os valores correspondentes definidos no objeto `fexcept_t` apontado por `pstatus`.  Ela não gera exceções. O ponteiro `pstatus` deverá apontar para um objeto `fexcept_t` válido ou o comportamento subsequente será indefinido. A função `fesetexceptflag` dá suporte a esses valores de macros de exceção em `excepts`, definidos \<fenv.h>:  
  
|Macro de exceção|Descrição|  
|---------------------|-----------------|  
|FE_DIVBYZERO|Ocorreu um erro de polo ou singularidade em uma operação de ponto flutuante anterior. Um valor infinito foi criado.|  
|FE_INEXACT|A função foi forçada a arredondar o resultado armazenado de uma operação de ponto flutuante anterior.|  
|FE_INVALID|Ocorreu um erro de domínio em uma operação de ponto flutuante anterior.|  
|FE_OVERFLOW|Ocorreu um erro de intervalo. O resultado de uma operação de ponto flutuante anterior era muito grande para ser representado.|  
|FE_UNDERFLOW|O resultado de uma operação de ponto flutuante anterior era muito pequeno para ser representado na precisão total. Um valor de denormal foi criado.|  
|FE_ALLEXCEPT|O OR bit a bit de todas as exceções de ponto flutuante com suporte.|  
  
 O argumento `excepts` pode ser zero, uma das macros de exceção de ponto flutuante com suporte ou OR bit a bit de duas ou mais das macros. O efeito de qualquer outro valor de argumento é indefinido.  
  
 Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C++|  
|--------------|--------------|------------------|  
|`fesetexceptflag`|\<fenv.h>|\<cfenv>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência da Função Alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [fegetexceptflag](../../c-runtime-library/reference/fegetexceptflag2.md)
