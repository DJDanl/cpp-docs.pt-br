---
title: set_unexpected (CRT) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- set_unexpected
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
- set_unexpected
dev_langs:
- C++
helpviewer_keywords:
- set_unexpected function
- unexpected function
- exception handling, termination
ms.assetid: ebcef032-4771-48e5-88aa-2a1ab8750aa6
caps.latest.revision: 11
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: f71fbabf28c9e196a8cc0985e04bb2b39ab7ad93
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="setunexpected-crt"></a>set_unexpected (CRT)
Instala sua própria função de terminação a ser chamada por `unexpected`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unexpected_function set_unexpected(  
   unexpected_function unexpFunction   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `unexpFunction`  
 Ponteiro para uma função que você escreve para substituir a função `unexpected`.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a função de terminação anterior registrada por `_set_unexpected`, de modo que a função anterior possa ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor retornado poderá ser usado para restaurar o comportamento padrão; esse valor pode ser NULL.  
  
## <a name="remarks"></a>Comentários  
 A função `set_unexpected` instala `unexpFunction` como a função chamada por `unexpected`. `unexpected` não é usado na implementação atual de manipulação de exceção C++. O tipo `unexpected_function` é definido em EH.H como um ponteiro para uma função inesperada definida pelo usuário, `unexpFunction`, que retorna `void`. Sua função `unexpFunction` personalizada não deve retornar a seu chamador.  
  
```  
typedef void ( *unexpected_function )( );  
```  
  
 `unexpected` chama `terminate` por padrão. Você pode alterar esse comportamento padrão escrevendo sua própria função de encerramento e chamar `set_unexpected` com o nome da sua função como seu argumento. `unexpected` chama a última função fornecida como um argumento para `set_unexpected`.  
  
 Diferentemente da função de encerramento personalizada instalada por uma chamada a `set_terminate`, uma exceção pode ser gerada do interior de `unexpFunction`.  
  
 Em um ambiente multithreaded, funções inesperadas são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função inesperada. Portanto, cada thread é responsável por sua própria manipulação de evento inesperado.  
  
 Na implementação atual da Microsoft de manipulação de exceções do C++, `unexpected` chama `terminate` por padrão e nunca é chamado pela biblioteca em tempo de execução de manipulação de exceção. Não há nenhuma vantagem particular em chamar `unexpected` em vez de `terminate`.  
  
 Há um único manipulador `set_unexpected` para todas as DLLs ou EXEs vinculados dinamicamente; mesmo que você chame `set_unexpected`, o manipulador poderá ser substituído por outro caso você esteja substituindo um manipulador definido por outra DLL ou EXE.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`set_unexpected`|\<eh.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [_get_unexpected](../../c-runtime-library/reference/get-unexpected.md)   
 [set_terminate](../../c-runtime-library/reference/set-terminate-crt.md)   
 [terminate](../../c-runtime-library/reference/terminate-crt.md)   
 [unexpected](../../c-runtime-library/reference/unexpected-crt.md)
