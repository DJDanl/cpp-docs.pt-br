---
title: fegetround, fesetround2 | Microsoft Docs
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
- fegetround
- fesetround
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
- fegetround
- fesetround
- fenv/fegetround
- fenv/fesetround
dev_langs:
- C++
helpviewer_keywords:
- fegetround function
- fesetround function
ms.assetid: 596af00b-be2f-4f57-b2f5-460485f9ff0b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bf50371c781a5ade76f3f35de8fc760331d72a20
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="fegetround-fesetround"></a>fegetround, fesetround
Obtém ou define o modo de arredondamento de ponto flutuante atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int fegetround(void);  
  
int fesetround(  
   int round_mode  
);   
```  
  
#### <a name="parameters"></a>Parâmetros  
 `round_mode`  
 O modo de arredondamento a ser definido, como as macros de arredondamento de ponto flutuante. Se o valor não for igual a uma das macros de arredondamento de ponto flutuante, o modo de arredondamento não será alterado.  
  
## <a name="return-value"></a>Valor de retorno  
 Em caso de sucesso, `fegetround` retorna o modo de arredondamento como um dos valores de macro de arredondamento de ponto flutuante. Ele retornará um valor negativo se o modo de arredondamento atual não puder ser determinado.  
  
 Em caso de sucesso, `fesetround` retorna 0. Caso contrário, será retornado um valor diferente de zero.  
  
## <a name="remarks"></a>Comentários  
 As operações de ponto flutuante podem usar um dos vários modos de arredondamento. Elas controlam a direção em que os resultados de operações de ponto flutuante são arredondados quando os resultados são armazenados. Esses são os nomes e os comportamentos das macros de arredondamento de ponto flutuante definidas em \<fenv.h>:  
  
|Macro|Descrição|  
|-----------|-----------------|  
|FE_DOWNWARD|Arredondar para o infinito negativo.|  
|FE_TONEAREST|Arredondar para o mais próximo.|  
|FE_TOWARDZERO|Arredondar para zero.|  
|FE_UPWARD|Arredondar para o infinito positivo.|  
  
 O comportamento padrão de FE_TONEAREST é arredondar resultados entre valores representáveis para obter o valor mais próximo com um bit menos significativo (0).  
  
 O modo de arredondamento atual afeta essas operações:  
  
-   Conversões de cadeia de caracteres.  
  
-   Os resultados de operadores aritméticos de ponto flutuante fora das expressões constantes.  
  
-   As funções de arredondamento da bibliotecas, como `rint` e `nearbyint`.  
  
-   Valores de retorno de funções matemáticas da biblioteca padrão.  
  
 O modo de arredondamento atual não afeta essas operações:  
  
-   As funções de biblioteca `trunc`, `ceil`, `floor` e `lround`.  
  
-   Ponto flutuante para conversões e transmissões implícitas de inteiro, que sempre arredondam em direção a zero.  
  
-   Os resultados dos operadores aritméticos de ponto flutuante em expressões de constante, que sempre são arredondados para o valor mais próximo.  
  
 Para usar essas funções, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C++|  
|--------------|--------------|------------------|  
|`fegetround`,                `fesetround`|\<fenv.h>|\<cfenv>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [nearbyint, nearbyintf, nearbyintl](../../c-runtime-library/reference/nearbyint-nearbyintf-nearbyintl1.md)   
 [rint, rintf, rintl](../../c-runtime-library/reference/rint-rintf-rintl.md)   
 [lrint, lrintf, lrintl, llrint, llrintf, llrintl](../../c-runtime-library/reference/lrint-lrintf-lrintl-llrint-llrintf-llrintl.md)