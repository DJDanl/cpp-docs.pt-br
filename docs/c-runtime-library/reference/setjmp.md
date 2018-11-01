---
title: setjmp
ms.date: 08/14/2018
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
helpviewer_keywords:
- programs [C++], saving states
- current state
- setjmp function
ms.assetid: 684a8b27-e8eb-455b-b4a8-733ca1cbd7d2
ms.openlocfilehash: 69af720c70393dbcad1e267b58e08876cdc2b77e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50575028"
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

*env*<br/>
Variável em que o ambiente é armazenado.

## <a name="return-value"></a>Valor de retorno

Retorna 0 depois de salvar o ambiente de pilha. Se **setjmp** retorna como resultado de uma `longjmp` chamar, ele retorna o *valor* argumento da `longjmp`, ou se o *valor* argumento de `longjmp` é 0, **setjmp** retorna 1. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

O **setjmp** função salva um ambiente de pilha, você poderá restaurar posteriormente usando `longjmp`. Quando usados juntos, **setjmp** e `longjmp` fornecem uma maneira de executar um não-local **goto**. Normalmente, eles são usados para transmitir o controle de execução para o código de recuperação ou de tratamento de erros em uma rotina anteriormente chamada anteriormente sem usar as convenções normais de chamada ou de retorno.

Uma chamada para **setjmp** salva o atual ambiente de pilha no *env*. Uma chamada subsequente para `longjmp` restaura o ambiente salvo e retorna o controle para o ponto imediatamente após o correspondente **setjmp** chamar. Todas as variáveis (exceto a variáveis de registro) acessíveis para a rotina de recebimento do controle contêm os valores que tinham quando `longjmp` foi chamado.

Não é possível usar **setjmp** para saltar de código nativo para gerenciado.

**Seção específica da Microsoft**

No código do Microsoft C++ no Windows, **longjmp** usa a mesma semântica de desenrolamento de pilha como o código de tratamento de exceção. É seguro usar nos mesmos locais que podem ser geradas exceções do C++. No entanto, esse uso não é portátil e vem com algumas restrições importantes. Para obter detalhes, consulte [longjmp](longjmp.md).

**Fim da seção específica da Microsoft**

> [!NOTE]
> No código C++ portátil, você não pode presumir `setjmp` e `longjmp` oferecer suporte à semântica de objeto C++. Especificamente, uma `setjmp` / `longjmp` chamada par possui comportamento indefinido se substituindo o `setjmp` e `longjmp` pelo **catch** e **lançar** invocaria qualquer destruidores não triviais para todos os objetos automáticos. Em programas C++, é recomendável que você use o mecanismo de tratamento de exceções C++.

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
[longjmp](longjmp.md)
