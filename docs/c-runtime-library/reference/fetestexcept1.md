---
title: fetestexcept1 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname: fetestexcept
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
- fetestexcept
- fenv/fetestexcept
dev_langs: C++
helpviewer_keywords: fetestexept function
ms.assetid: ca4dc43f-5573-440d-bc19-ead7571b13dc
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 78eb884950e2175815caf2ac645dc0e70c262566
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fetestexcept"></a>fetestexcept
Determina qual dos sinalizadores de status de exceção de ponto flutuante especificados estão definidos no momento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int fetestexcept(  
   int excepts  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `excepts`  
 Um OR bit a bit dos sinalizadores de status de ponto flutuante para testar.  
  
## <a name="return-value"></a>Valor de retorno  
 Em caso de sucesso, retorna uma bitmask contendo um OR bit a bit das macros de exceção de ponto flutuante que correspondem aos sinalizadores de status de exceção atualmente definidos. Retorna 0 se nenhuma das exceções for definida.  
  
## <a name="remarks"></a>Comentários  
 Use a função fetestexcept para determinar quais exceções foram geradas pela operação de ponto flutuante. Use o parâmetro `excepts` para especificar quais sinalizadores de status de exceção serão testados. A função `fetestexcept` usa essas macros de exceção definidas em \<fenv.h> in `excepts` e o valor retornado:  
  
|Macro de exceção|Descrição|  
|---------------------|-----------------|  
|FE_DIVBYZERO|Ocorreu um erro de polo ou singularidade em uma operação de ponto flutuante anterior. Um valor infinito foi criado.|  
|FE_INEXACT|A função foi forçada a arredondar o resultado armazenado de uma operação de ponto flutuante anterior.|  
|FE_INVALID|Ocorreu um erro de domínio em uma operação de ponto flutuante anterior.|  
|FE_OVERFLOW|Ocorreu um erro de intervalo. O resultado de uma operação de ponto flutuante anterior era muito grande para ser representado.|  
|FE_UNDERFLOW|O resultado de uma operação de ponto flutuante anterior era muito pequeno para ser representado na precisão total. Um valor de denormal foi criado.|  
|FE_ALLEXCEPT|O OR bit a bit de todas as exceções de ponto flutuante com suporte.|  
  
 O argumento `excepts` especificado pode ser 0, uma das macros de exceção de ponto flutuante com suporte ou OR bit a bit de duas ou mais das macros. O efeito de qualquer outro valor de argumento `excepts` é indefinido.  
  
 Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C++|  
|--------------|--------------|------------------|  
|`fetestexcept`|\<fenv.h>|\<cfenv>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [feclearexcept](../../c-runtime-library/reference/feclearexcept1.md)   
 [feraiseexcept](../../c-runtime-library/reference/feraiseexcept.md)