---
title: set_terminate (CRT) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- set_terminate
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
- set_terminate
dev_langs:
- C++
helpviewer_keywords:
- set_terminate function
- terminate function
- exception handling, termination
ms.assetid: 3ff1456a-7898-44bc-9266-a328a80b6006
caps.latest.revision: 13
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
translationtype: Machine Translation
ms.sourcegitcommit: cc82b83860786ffc3f0aee73ede18ecadef16a7a
ms.openlocfilehash: 657c03ebed8e077e3a6c2eac96eae264f4a19998
ms.lasthandoff: 02/25/2017

---
# <a name="setterminate-crt"></a>set_terminate (CRT)
Instala sua própria rotina de terminação a ser chamada por `terminate`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
terminate_function set_terminate(  
   terminate_function termFunction  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `termFunction`  
 Ponteiro para uma função de encerramento que você escreve.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a função anterior registrada por `set_terminate`, de modo que a função anterior possa ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor retornado poderá ser usado para restaurar o comportamento padrão; esse valor pode ser NULL.  
  
## <a name="remarks"></a>Comentários  
 A função `set_terminate` instala `termFunction` como a função chamada por `terminate`. `set_terminate` é usado com o manipulação de exceções C++ e pode ser chamado a qualquer momento em seu programa antes que a exceção seja lançada. `terminate` chama `abort` por padrão. Você pode alterar esse padrão escrevendo sua própria função de encerramento e chamar `set_terminate` com o nome da sua função como seu argumento. `terminate` chama a última função fornecida como um argumento para `set_terminate`. Depois de executar quaisquer tarefas de limpeza desejadas, `termFunction` deve sair do programa. Caso contrário (se ela retornar para seu chamador), `abort` será chamado.  
  
 Em um ambiente multithreaded, funções de encerramento são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função de encerramento. Portanto, cada thread é responsável por sua própria manipulação de encerramento.  
  
 O tipo `terminate_function` é definido em EH.H como um ponteiro para uma função de encerramento definida pelo usuário, `termFunction`, que retorna `void`. A função personalizada `termFunction` não pode levar argumentos e não deve retornar a seu chamador. Se isso acontecer, `abort` será chamado. Uma exceção não pode ser lançada de dentro de `termFunction`.  
  
```  
typedef void ( *terminate_function )( );  
```  
  
> [!NOTE]
>  A função `set_terminate` só funciona fora do depurador.  
  
 Há um único manipulador `set_terminate` para todas as DLLs ou EXEs vinculados dinamicamente; mesmo que você chame `set_terminate`, o manipulador poderá ser substituído por outro caso você esteja substituindo um manipulador definido por outra DLL ou EXE.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`set_terminate`|\<eh.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [terminate](../../c-runtime-library/reference/terminate-crt.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [_get_terminate](../../c-runtime-library/reference/get-terminate.md)   
 [set_unexpected](../../c-runtime-library/reference/set-unexpected-crt.md)   
 [terminate](../../c-runtime-library/reference/terminate-crt.md)   
 [unexpected](../../c-runtime-library/reference/unexpected-crt.md)
