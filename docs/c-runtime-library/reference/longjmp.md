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
ms.openlocfilehash: b4527a29475f9e393dc5abf19b866d926bec2ccc
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70953138"
---
# <a name="longjmp"></a>longjmp

Restaura o ambiente de pilha e a localidade de execução definida por `setjmp` uma chamada.

## <a name="syntax"></a>Sintaxe

```C
void longjmp(
   jmp_buf env,
   int value
);
```

### <a name="parameters"></a>Parâmetros

*env*<br/>
Variável em que o ambiente é armazenado.

*value*<br/>
Valor a ser retornado para `setjmp` chamar.

## <a name="remarks"></a>Comentários

A função **longjmp** restaura um ambiente de pilha e a localidade de execução salva anteriormente em *env* by `setjmp`. `setjmp`e o **longjmp** fornecem uma maneira de executar um **goto**não local; Normalmente, eles são usados para passar o controle de execução para tratamento de erros ou código de recuperação em uma rotina chamada anteriormente sem usar a chamada normal e as convenções de retorno.

Uma chamada para `setjmp` faz com que o ambiente de pilha atual seja salvo em *env*. Uma chamada subsequente para **longjmp** restaura o ambiente salvo e retorna o controle para o ponto imediatamente após a chamada correspondente `setjmp` . A execução será retomada como se o *valor* tivesse sido retornado pela chamada `setjmp`. Os valores de todas as variáveis (exceto as variáveis de registro) que são acessíveis para o controle de recebimento de rotina contêm os valores que eles tinham quando **longjmp** foi chamado. Os valores das variáveis de registro são imprevisíveis. O valor retornado por `setjmp` deve ser diferente de zero. Se o *valor* for passado como 0, o valor 1 será substituído no retorno real.

**Seção específica da Microsoft**

No código C++ da Microsoft no Windows, o **longjmp** usa a mesma semântica de desenrolamento de pilha como código de tratamento de exceção. É seguro usar nos mesmos locais em que C++ as exceções podem ser geradas. No entanto, esse uso não é portátil e vem com algumas advertências importantes.

Chame **longjmp** antes da função que chamou `setjmp` retornos; caso contrário, os resultados serão imprevisíveis.

Observe as seguintes restrições ao usar o **longjmp**:

- Não presuma que os valores das variáveis de registro permanecerão os mesmos. Os valores das variáveis de registro na rotina de `setjmp` chamada podem não ser restaurados para os valores apropriados depois que **longjmp** é executado.

- Não use **longjmp** para transferir o controle de uma rotina de tratamento de interrupção, a menos que a interrupção seja causada por uma exceção de ponto flutuante. Nesse caso, um programa pode retornar de um manipulador de interrupção por meio de **longjmp** se ele primeiro reinicializa o pacote de matemática de ponto flutuante chamando [_fpreset](fpreset.md).

- Não use **longjmp** para transferir o controle de uma rotina de retorno de chamada chamada direta ou indiretamente pelo código do Windows.

- Se o código for compilado usando **o/EHS** ou **/EHsc** e a função que contém a chamada **longjmp** for **noexcept** , os objetos locais nessa função não poderão ser destruídos durante o desenrolamento da pilha.

**Fim da seção específica da Microsoft**

> [!NOTE]
> No código C++ portátil, você não pode `setjmp` supor `longjmp` e C++ dar suporte à semântica do objeto. Especificamente, um `setjmp` / `longjmp` `longjmp` pardechamadastemumcomportamentoindefinidosesubstituireporcatchethrowinvocariaqualquerdestruidornãotrivialparaobjetosautomáticos`setjmp` . Em C++ programas, recomendamos que você use C++ o mecanismo de tratamento de exceções.

Para obter mais informações, consulte [Usando o setjmp e o longjmp](../../cpp/using-setjmp-longjmp.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**longjmp**|\<setjmp.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_fpreset](fpreset.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[setjmp](setjmp.md)
