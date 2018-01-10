---
title: feholdexcept2 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname: feholdexcept
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
- feholdexcept
- fenv/feholdexcept
dev_langs: C++
helpviewer_keywords: feholdexcept function
ms.assetid: 88e512ae-b5d8-452c-afe9-c824cd3ef1d8
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b1455f3b963c2d9faf7c2e96a2d6684e0e412ef8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="feholdexcept"></a>feholdexcept
Salva o ambiente atual de ponto flutuante no objeto especificado, limpa os sinalizadores de status do ponto flutuante e, se possível, coloca o ambiente de ponto flutuante no modo contínuo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int feholdexcept(  
   fenv_t *penv  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `penv`  
 Ponteiro para um objeto `fenv_t` para conter uma cópia do ambiente de ponto flutuante.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna zero se e somente se a função é capaz de ativar o tratamento de exceções de ponto flutuante contínuas com êxito.  
  
## <a name="remarks"></a>Comentários  
 A função `feholdexcept` é usada para armazenar o estado do ambiente de ponto flutuante atual no objeto `fenv_t` apontado por `penv` e para definir o ambiente para não interromper a execução em exceções de ponto flutuante. Isso é conhecido como modo contínuo.  Esse modo continua até que o ambiente seja restaurado usando [fesetenv](fesetenv1.md) ou [feupdateenv](../../c-runtime-library/reference/feupdateenv.md).  
  
 Você pode usar essa função no início de uma sub-rotina que precisa ocultar uma ou mais exceções de ponto flutuante do chamador. Para relatar uma exceção, basta limpar as exceções indesejadas usando [feclearexcept](../../c-runtime-library/reference/feclearexcept1.md) e encerrar o modo contínuo com uma chamada para `feupdateenv`.  
  
 Para usar essa função, você deve desligar otimizações de ponto flutuante que poderiam impedir o acesso usando a diretiva `#pragma fenv_access(on)` antes da chamada. Para obter mais informações, consulte [fenv_access](../../preprocessor/fenv-access.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C++|  
|--------------|--------------|------------------|  
|`feholdexcept`|\<fenv.h>|\<cfenv>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [feclearexcept](../../c-runtime-library/reference/feclearexcept1.md)   
 [fesetenv](fesetenv1.md)   
 [feupdateenv](../../c-runtime-library/reference/feupdateenv.md)