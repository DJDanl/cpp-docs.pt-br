---
title: longjmp | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- longjmp
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
- longjmp
dev_langs:
- C++
helpviewer_keywords:
- restoring stack environment and execution locale
- longjmp function
ms.assetid: 0e13670a-5130-45c1-ad69-6862505b7a2f
caps.latest.revision: 9
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 8d6ae9f6207bc0cc42ec2a0749ddfb6253c496f6
ms.lasthandoff: 02/25/2017

---
# <a name="longjmp"></a>longjmp
Restaura o ambiente da pilha e a localidade de execução.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void longjmp(  
   jmp_buf env,  
   int value   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `env`  
 Variável em que o ambiente é armazenado.  
  
 *value*  
 Valor a ser retornado para `setjmp` chamar.  
  
## <a name="remarks"></a>Comentários  
 A função `longjmp` restaura um ambiente de pilha e a localidade de execução salvos anteriormente em `env` por `setjmp`. `setjmp` e `longjmp` proporcionam uma maneira de executar um `goto` não local; normalmente, eles são usados para transmitir o controle de execução para o código de recuperação ou de tratamento de erros em uma rotina anteriormente chamada anteriormente sem usar as convenções normais de chamada e retorno.  
  
 Uma chamada para `setjmp` faz com que o ambiente de pilha atual seja salvo em `env`. Uma chamada subsequente para `longjmp` restaura o ambiente salvo e retorna o controle para o ponto imediatamente após a chamada do `setjmp` correspondente. A execução será retomada como se o *valor* tivesse sido retornado pela chamada `setjmp`. Os valores de todas as variáveis (exceto a variáveis de registro) acessíveis para a rotina de recebimento do controle contêm os valores que tinham quando `longjmp` foi chamado. Os valores das variáveis de registro são imprevisíveis. O valor retornado por `setjmp` deve ser diferente de zero. Se o *valor* for passado como 0, o valor 1 será substituído no retorno real.  
  
 Chame `longjmp` antes da função que chamou `setjmp` retornar; caso contrário, os resultados serão imprevisíveis.  
  
 Observe as seguintes restrições ao usar `longjmp`:  
  
-   Não presuma que os valores das variáveis de registro permanecerão os mesmos. Os valores das variáveis de registro da chamada de rotina `setjmp` não podem ser restaurados para os valores adequados após a execução de `longjmp`.  
  
-   Não use `longjmp` para transferir o controle para fora de uma rotina de manipulação de interrupção, a menos que a interrupção seja causada por uma exceção de ponto flutuante. Nesse caso, um programa poderá retornar de um manipulador de interrupção via `longjmp`, se ele reinicializar primeiro o pacote de matemática de ponto flutuante chamando `_fpreset`.  
  
     **Observação** Tenha cuidado ao usar `setjmp` e `longjmp` em programas C++. Como essas funções não oferecem suporte a semântica de objeto C++, é mais seguro usar o mecanismo de tratamento de exceções C++.  
  
 Para obter mais informações, consulte [Usando o setjmp e o longjmp](../../cpp/using-setjmp-longjmp.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`longjmp`|\<setjmp.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [_fpreset](../../c-runtime-library/reference/fpreset.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [setjmp](../../c-runtime-library/reference/setjmp.md)
