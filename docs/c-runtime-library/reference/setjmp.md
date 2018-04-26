---
title: setjmp | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
ms.workload:
- cplusplus
ms.openlocfilehash: dc01f80aa4521ff3588cca14ceabbf5447338cca
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="setjmp"></a>setjmp

Salva o estado atual do programa.

## <a name="syntax"></a>Sintaxe

```C
int setjmp(
   jmp_buf env
);
```

### <a name="parameters"></a>Parâmetros

*Env*<br/>
Variável em que o ambiente é armazenado.

## <a name="return-value"></a>Valor de retorno

Retorna 0 depois de salvar o ambiente de pilha. Se **setjmp** retorna como resultado de uma **longjmp** chamar, ele retorna o **valor** argumento de **longjmp**, ou se o **valor**  argumento de **longjmp** é 0, **setjmp** retorna 1. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

O **setjmp** função salva um ambiente de pilha, você pode restaurar posteriormente, usando **longjmp**. Quando usados juntos, **setjmp** e **longjmp** fornecem uma maneira de executar um local não **goto**. Normalmente, eles são usados para transmitir o controle de execução para o código de recuperação ou de tratamento de erros em uma rotina anteriormente chamada anteriormente sem usar as convenções normais de chamada ou de retorno.

Uma chamada para **setjmp** salva o atual ambiente de pilha em *env*. Uma chamada subsequente para **longjmp** restaura o ambiente salvo e retorna o controle para o ponto depois correspondente **setjmp** chamar. Todas as variáveis (exceto as variáveis de registro) acessíveis para a rotina de recebimento do controle contêm os valores que tinham quando **longjmp** foi chamado.

Não é possível usar **setjmp** para saltar de nativo para código gerenciado.

**Observação** **setjmp** e **longjmp** não oferecem suporte a semântica de objeto C++. Em programas C++, use o mecanismo de manipulação de exceções C++.

Para obter mais informações, consulte [Usando o setjmp e o longjmp](../../cpp/using-setjmp-longjmp.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**setjmp**|\<setjmp.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_fpreset](fpreset.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[longjmp](longjmp.md)<br/>
[_setjmp3](../../c-runtime-library/setjmp3.md)<br/>
