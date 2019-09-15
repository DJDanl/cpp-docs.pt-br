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
ms.openlocfilehash: 4a88467f5b94ceae4281a35f1486380a877be2e5
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70948231"
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

Retorna 0 depois de salvar o ambiente de pilha. Se **setjmp** retornar como `longjmp` resultado de uma chamada, ele retornará o argumento *de valor* de `longjmp`, ou se o argumento de *valor* de `longjmp` for 0, **setjmp** retornará 1. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

A função **setjmp** salva um ambiente de pilha, que pode ser restaurado posteriormente `longjmp`, usando. Quando usado em conjunto , setjmp `longjmp` e fornece uma maneira de executar um **goto**não local. Normalmente, eles são usados para transmitir o controle de execução para o código de recuperação ou de tratamento de erros em uma rotina anteriormente chamada anteriormente sem usar as convenções normais de chamada ou de retorno.

Uma chamada para **setjmp** salva o ambiente de pilha atual em *env*. Uma chamada subsequente para `longjmp` restaura o ambiente salvo e retorna o controle para o ponto logo após a chamada **setjmp** correspondente. Todas as variáveis (exceto a variáveis de registro) acessíveis para a rotina de recebimento do controle contêm os valores que tinham quando `longjmp` foi chamado.

Não é possível usar **setjmp** para saltar do código nativo para o gerenciado.

**Seção específica da Microsoft**

No código C++ da Microsoft no Windows, o **longjmp** usa a mesma semântica de desenrolamento de pilha como código de tratamento de exceção. É seguro usar nos mesmos locais em que C++ as exceções podem ser geradas. No entanto, esse uso não é portátil e vem com algumas advertências importantes. Para obter detalhes, consulte [longjmp](longjmp.md).

**Fim da seção específica da Microsoft**

> [!NOTE]
> No código C++ portátil, você não pode `setjmp` supor `longjmp` e C++ dar suporte à semântica do objeto. Especificamente, um `setjmp` / `longjmp` `longjmp` pardechamadastemumcomportamentoindefinidosesubstituireporcatchethrowinvocariaqualquerdestruidornãotrivialparaobjetosautomáticos`setjmp` . Em C++ programas, recomendamos que você use C++ o mecanismo de tratamento de exceções.

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
