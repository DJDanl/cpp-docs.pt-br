---
title: longjmp | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f6c26cae9a3fe83012387c93e31c4005d5614d97
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32401715"
---
# <a name="longjmp"></a>longjmp

Restaura o ambiente da pilha e a localidade de execução.

## <a name="syntax"></a>Sintaxe

```C
void longjmp(
   jmp_buf env,
   int value
);
```

### <a name="parameters"></a>Parâmetros

*Env* variável na qual ambiente será armazenado.

*valor* valor a ser retornado para **setjmp** chamar.

## <a name="remarks"></a>Comentários

O **longjmp** função restaura uma localidade de ambiente e a execução de pilha salva anteriormente em *env* por **setjmp**. **setjmp** e **longjmp** fornecem uma maneira de executar uma não locais **goto**; normalmente são usadas para passar o controle de execução para o código de tratamento de erros ou de recuperação em uma rotina chamado anteriormente sem usando a chamada normal e convenções de retorno.

Uma chamada para **setjmp** faz com que o ambiente de pilha atual seja salvo no *env*. Uma chamada subsequente para **longjmp** restaura o ambiente salvo e retorna o controle para o ponto imediatamente após o correspondente **setjmp** chamar. Retoma a execução como se *valor* apenas tinha sido retornado pelo **setjmp** chamar. Os valores de todas as variáveis (exceto a variáveis de registro) que são acessíveis para a rotina de recebimento do controle contêm os valores que tinham quando **longjmp** foi chamado. Os valores das variáveis de registro são imprevisíveis. O valor retornado por **setjmp** deve ser diferente de zero. Se o *valor* for passado como 0, o valor 1 será substituído no retorno real.

Chamar **longjmp** antes da função que chamou **setjmp** retorna; caso contrário, os resultados são imprevisíveis.

Observe as seguintes restrições ao usar **longjmp**:

- Não presuma que os valores das variáveis de registro permanecerão os mesmos. Os valores das variáveis de registro ao chamar a rotina **setjmp** não podem ser restauradas para os valores apropriados após **longjmp** é executado.

- Não use **longjmp** para transferir controle fora de uma rotina de tratamento de interrupção, a menos que a interrupção é causada por uma exceção de ponto flutuante. Nesse caso, um programa pode retornar um manipulador de interrupção por meio de **longjmp** se primeiro reinicializa o pacote de matemática de ponto flutuante chamando **fpreset**.

     **Observação** cuidado ao usar **setjmp** e **longjmp** em programas C++. Como essas funções não oferecem suporte a semântica de objeto C++, é mais seguro usar o mecanismo de tratamento de exceções C++.

Para obter mais informações, consulte [Usando o setjmp e o longjmp](../../cpp/using-setjmp-longjmp.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**longjmp**|\<setjmp.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_fpreset](fpreset.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[setjmp](setjmp.md)<br/>
