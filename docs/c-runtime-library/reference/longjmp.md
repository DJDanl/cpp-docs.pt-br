---
title: longjmp
ms.date: 08/14/2018
api_name:
- longjmp
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
- longjmp
helpviewer_keywords:
- restoring stack environment and execution locale
- longjmp function
ms.assetid: 0e13670a-5130-45c1-ad69-6862505b7a2f
ms.openlocfilehash: 4f737818afe7136262362e4fe996745064568758
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218553"
---
# <a name="longjmp"></a>longjmp

Restaura o ambiente de pilha e a localidade de execução definida por uma `setjmp` chamada.

## <a name="syntax"></a>Sintaxe

```C
void longjmp(
   jmp_buf env,
   int value
);
```

### <a name="parameters"></a>parâmetros

*variável*<br/>
Variável em que o ambiente é armazenado.

*value*<br/>
Valor a ser retornado para `setjmp` chamar.

## <a name="remarks"></a>Comentários

A função **longjmp** restaura um ambiente de pilha e a localidade de execução salva anteriormente em *env* by `setjmp` . `setjmp`e o **longjmp** fornecem uma maneira de executar um não local **`goto`** ; eles são normalmente usados para passar o controle de execução para tratamento de erros ou código de recuperação em uma rotina chamada anteriormente sem usar as convenções de chamada e de retorno normais.

Uma chamada para `setjmp` faz com que o ambiente de pilha atual seja salvo em *env*. Uma chamada subsequente para **longjmp** restaura o ambiente salvo e retorna o controle para o ponto imediatamente após a chamada correspondente `setjmp` . A execução será retomada como se o *valor* tivesse sido retornado pela chamada `setjmp`. Os valores de todas as variáveis (exceto as variáveis de registro) que são acessíveis para o controle de recebimento de rotina contêm os valores que eles tinham quando **longjmp** foi chamado. Os valores das variáveis de registro são imprevisíveis. O valor retornado por `setjmp` deve ser diferente de zero. Se o *valor* for passado como 0, o valor 1 será substituído no retorno real.

**Específico da Microsoft**

No código do Microsoft C++ no Windows, **longjmp** usa a mesma semântica de desenrolamento de pilha como código de tratamento de exceção. É seguro usar nos mesmos locais em que as exceções do C++ podem ser geradas. No entanto, esse uso não é portátil e vem com algumas advertências importantes.

Chame **longjmp** antes da função que chamou `setjmp` retornos; caso contrário, os resultados serão imprevisíveis.

Observe as seguintes restrições ao usar o **longjmp**:

- Não presuma que os valores das variáveis de registro permanecerão os mesmos. Os valores das variáveis de registro na rotina de chamada `setjmp` podem não ser restaurados para os valores apropriados depois que **longjmp** é executado.

- Não use **longjmp** para transferir o controle de uma rotina de tratamento de interrupção, a menos que a interrupção seja causada por uma exceção de ponto flutuante. Nesse caso, um programa pode retornar de um manipulador de interrupção por meio de **longjmp** se ele primeiro reinicializa o pacote de matemática de ponto flutuante chamando [_fpreset](fpreset.md).

- Não use **longjmp** para transferir o controle de uma rotina de retorno de chamada chamada direta ou indiretamente pelo código do Windows.

- Se o código for compilado usando **o/EHS** ou **/EHsc** e a função que contém a chamada **longjmp** for **`noexcept`** , os objetos locais nessa função não poderão ser destruídos durante o desenrolamento da pilha.

**FINAL específico da Microsoft**

> [!NOTE]
> No código C++ portátil, você não pode supor `setjmp` e `longjmp` dar suporte a semântica de objeto c++. Especificamente, um `setjmp` / `longjmp` par de chamadas tem um comportamento indefinido se substituir `setjmp` e `longjmp` por **`catch`** e **`throw`** chamaria quaisquer destruidores não triviais para objetos automáticos. Em programas em C++, recomendamos que você use o mecanismo de manipulação de exceções do C++.

Para obter mais informações, consulte [Usando o setjmp e o longjmp](../../cpp/using-setjmp-longjmp.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**longjmp**|\<setjmp.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_fpreset](fpreset.md).

## <a name="see-also"></a>Confira também

[Controle de processo e ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[setjmp](setjmp.md)
