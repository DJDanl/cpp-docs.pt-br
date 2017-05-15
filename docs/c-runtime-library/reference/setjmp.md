---
title: setjmp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- setjmp
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
apitype: DLLExport
f1_keywords:
- setjmp
dev_langs:
- C++
helpviewer_keywords:
- programs [C++], saving states
- current state
- setjmp function
ms.assetid: 684a8b27-e8eb-455b-b4a8-733ca1cbd7d2
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 602ed9f5b1ff3c809055d9a231f81ee649bab8e8
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="setjmp"></a>setjmp
Salva o estado atual do programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int setjmp(  
   jmp_buf env   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `env`  
 Variável em que o ambiente é armazenado.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna 0 depois de salvar o ambiente de pilha. Se `setjmp` retorna como resultado de uma chamada `longjmp`, ele retorna o argumento `value` de `longjmp` ou, se o argumento `value` de `longjmp` é 0, `setjmp` retorna 1. Nenhum erro é retornado.  
  
## <a name="remarks"></a>Comentários  
 A função `setjmp` salva um ambiente de pilha, que você poderá restaurar posteriormente usando `longjmp`. Quando usados juntos, `setjmp` e `longjmp` fornecem uma maneira de executar um `goto` não local. Normalmente, eles são usados para transmitir o controle de execução para o código de recuperação ou de tratamento de erros em uma rotina anteriormente chamada anteriormente sem usar as convenções normais de chamada ou de retorno.  
  
 Uma chamada para `setjmp` salva o ambiente de pilha atual em `env`. Uma chamada subsequente para `longjmp` restaura o ambiente salvo e retorna o controle para o ponto imediatamente após a chamada `setjmp` correspondente. Todas as variáveis (exceto a variáveis de registro) acessíveis para a rotina de recebimento do controle contêm os valores que tinham quando `longjmp` foi chamado.  
  
 Não é possível usar `setjmp` para saltar de código nativo para gerenciado.  
  
 **Observação** `setjmp` e `longjmp` não dão suporte à semântica de objeto C++. Em programas C++, use o mecanismo de manipulação de exceções C++.  
  
 Para obter mais informações, consulte [Usando o setjmp e o longjmp](../../cpp/using-setjmp-longjmp.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`setjmp`|\<setjmp.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [_fpreset](../../c-runtime-library/reference/fpreset.md).  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [longjmp](../../c-runtime-library/reference/longjmp.md)   
 [_setjmp3](../../c-runtime-library/setjmp3.md)
