---
title: longjmp | Microsoft Docs
ms.custom: ''
ms.date: 08/14/2018
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
ms.openlocfilehash: 857fae2e9c38dfe2c5cd468c6d1b50c6fdd2f317
ms.sourcegitcommit: b92ca0b74f0b00372709e81333885750ba91f90e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/16/2018
ms.locfileid: "42571458"
---
# <a name="longjmp"></a>longjmp

Restaura a localidade de execução e o ambiente de pilha definida por um `setjmp` chamar.

## <a name="syntax"></a>Sintaxe

```C
void longjmp(
   jmp_buf env,
   int value
);
```

### <a name="parameters"></a>Parâmetros

*Env*  
Variável em que o ambiente é armazenado.

*value*  
Valor a ser retornado para `setjmp` chamar.

## <a name="remarks"></a>Comentários

O **longjmp** função restaura uma localidade de execução e o ambiente de pilha salva anteriormente em *env* por `setjmp`. `setjmp` e **longjmp** fornecem uma maneira de executar uma não locais **goto**; eles normalmente são usados para transmitir o controle de execução para o código de tratamento de erros ou recuperação em uma rotina anteriormente chamada anteriormente sem usar a chamada normal e retorne as convenções.

Uma chamada para `setjmp` faz com que o ambiente de pilha atual seja salvo em *env*. Uma chamada subsequente para **longjmp** restaura o ambiente salvo e retorna o controle para o ponto imediatamente após o correspondente `setjmp` chamar. A execução será retomada como se o *valor* tivesse sido retornado pela chamada `setjmp`. Os valores de todas as variáveis (exceto a variáveis de registro) acessíveis para a rotina de recebimento do controle contêm os valores que tinham quando **longjmp** foi chamado. Os valores das variáveis de registro são imprevisíveis. O valor retornado por `setjmp` deve ser diferente de zero. Se o *valor* for passado como 0, o valor 1 será substituído no retorno real.

**Seção específica da Microsoft**

No código do Microsoft C++ no Windows, **longjmp** usa a mesma semântica de desenrolamento de pilha como o código de tratamento de exceção. É seguro usar nos mesmos locais que podem ser geradas exceções do C++. No entanto, esse uso não é portátil e vem com algumas restrições importantes.

Apenas chame **longjmp** antes da função que chamou `setjmp` retorna; caso contrário, os resultados serão imprevisíveis.

Observe as seguintes restrições ao usar **longjmp**:

- Não presuma que os valores das variáveis de registro permanecerão os mesmos. Os valores das variáveis de registro chamada de rotina `setjmp` não podem ser restaurados para os valores adequados após **longjmp** é executado.

- Não use **longjmp** para transferir o controle para fora de uma rotina de manipulação de interrupção, a menos que a interrupção seja causada por uma exceção de ponto flutuante. Nesse caso, um programa poderá retornar de um manipulador de interrupção via **longjmp** se ele reinicializar primeiro o pacote de matemática de ponto flutuante chamando [fpreset](fpreset.md).

- Não use **longjmp** para transferir o controle de uma rotina de retorno de chamada invocada diretamente ou indiretamente pelo código do Windows.

- Se o código é compilado usando **/EHs** ou **/EHsc** e a função que contém o **longjmp** chamada é **noexcept** objetos locais, em seguida, nessa função pode não ser destruída durante o desenrolamento de pilha.

**Fim da seção específica da Microsoft**

> [!NOTE]  
> No código C++ portátil, você não pode presumir `setjmp` e `longjmp` oferecer suporte à semântica de objeto C++. Especificamente, uma `setjmp` / `longjmp` chamada par possui comportamento indefinido se substituindo o `setjmp` e `longjmp` pelo **catch** e **lançar** invocaria qualquer destruidores não triviais para todos os objetos automáticos. Em programas C++, é recomendável que você use o mecanismo de tratamento de exceções C++.

Para obter mais informações, consulte [Usando o setjmp e o longjmp](../../cpp/using-setjmp-longjmp.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**longjmp**|\<setjmp.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_fpreset](fpreset.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)  
[setjmp](setjmp.md)  
