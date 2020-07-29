---
title: setjmp
ms.date: 08/14/2018
api_name:
- setjmp
api_location:
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
- ntoskrnl.exe
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- setjmp
helpviewer_keywords:
- programs [C++], saving states
- current state
- setjmp function
ms.assetid: 684a8b27-e8eb-455b-b4a8-733ca1cbd7d2
ms.openlocfilehash: beaf56a03c1bd157257d604bfd0ebefb219d0225
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226145"
---
# <a name="setjmp"></a>setjmp

Salva o estado atual do programa.

## <a name="syntax"></a>Sintaxe

```C
int setjmp(
   jmp_buf env
);
```

### <a name="parameters"></a>parâmetros

*variável*<br/>
Variável em que o ambiente é armazenado.

## <a name="return-value"></a>Valor retornado

Retorna 0 depois de salvar o ambiente de pilha. Se **setjmp** retornar como resultado de uma `longjmp` chamada, ele retornará o argumento de *valor* de `longjmp` , ou se o argumento de *valor* de `longjmp` for 0, **setjmp** retornará 1. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

A função **setjmp** salva um ambiente de pilha, que pode ser restaurado posteriormente, usando `longjmp` . Quando usado em conjunto, **setjmp** e `longjmp` fornece uma maneira de executar um não local **`goto`** . Normalmente, eles são usados para transmitir o controle de execução para o código de recuperação ou de tratamento de erros em uma rotina anteriormente chamada anteriormente sem usar as convenções normais de chamada ou de retorno.

Uma chamada para **setjmp** salva o ambiente de pilha atual em *env*. Uma chamada subsequente para `longjmp` restaura o ambiente salvo e retorna o controle para o ponto logo após a chamada **setjmp** correspondente. Todas as variáveis (exceto a variáveis de registro) acessíveis para a rotina de recebimento do controle contêm os valores que tinham quando `longjmp` foi chamado.

Não é possível usar **setjmp** para saltar do código nativo para o gerenciado.

**Específico da Microsoft**

No código do Microsoft C++ no Windows, **longjmp** usa a mesma semântica de desenrolamento de pilha como código de tratamento de exceção. É seguro usar nos mesmos locais em que as exceções do C++ podem ser geradas. No entanto, esse uso não é portátil e vem com algumas advertências importantes. Para obter detalhes, consulte [longjmp](longjmp.md).

**FINAL específico da Microsoft**

> [!NOTE]
> No código C++ portátil, você não pode supor `setjmp` e `longjmp` dar suporte a semântica de objeto c++. Especificamente, um `setjmp` / `longjmp` par de chamadas tem um comportamento indefinido se substituir `setjmp` e `longjmp` por **`catch`** e **`throw`** chamaria quaisquer destruidores não triviais para objetos automáticos. Em programas em C++, recomendamos que você use o mecanismo de manipulação de exceções do C++.

Para obter mais informações, consulte [Usando o setjmp e o longjmp](../../cpp/using-setjmp-longjmp.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**setjmp**|\<setjmp.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_fpreset](fpreset.md).

## <a name="see-also"></a>Confira também

[Controle de processo e ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[longjmp](longjmp.md)
