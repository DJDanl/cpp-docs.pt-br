---
title: assert Macro, _assert, _wassert
description: Os efeitos das macros Assert e funções no tempo de execução C.
ms.date: 11/04/2016
api_name:
- assert
- _assert
- _wassert
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
- api-ms-win-crt-runtime-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- assert
- _assert
- _wassert
- assert/_wassert
helpviewer_keywords:
- aborting programs
- assert function
- assert macro
ms.assetid: a9ca031a-648b-47a6-bdf1-65fc7399dd40
ms.openlocfilehash: 071424f2201ceda43438fe1056801811fe444a01
ms.sourcegitcommit: 0df2b7ab4e81284c5248e4584767591dcc1950c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/09/2020
ms.locfileid: "89609080"
---
# <a name="assert-macro-_assert-_wassert"></a>assert Macro, _assert, _wassert

Avalia uma expressão e, quando o resultado é **`false`** , imprime uma mensagem de diagnóstico e anula o programa.

## <a name="syntax"></a>Sintaxe

```C
assert(
   expression
);
void _assert(
   char const* message,
   char const* filename,
   unsigned line
);
void _wassert(
   wchar_t const* message,
   wchar_t const* filename,
   unsigned line
);
```

### <a name="parameters"></a>parâmetros

*expressão*<br/>
Uma expressão escalar (incluindo expressões de ponteiro) que é avaliada como zero ( **`true`** ) ou 0 ( **`false`** ).

*message*<br/>
A mensagem a ser exibida.

*nome do arquivo*<br/>
O nome do arquivo de origem no qual a declaração falhou.

*line*<br/>
O número de linha no arquivo de origem da declaração com falha.

## <a name="remarks"></a>Comentários

A macro `assert` normalmente é usada para identificar erros de lógica durante o desenvolvimento do programa. Use-o para interromper a execução do programa quando condições inesperadas ocorrerem implementando o argumento *expression* para avaliar **`false`** somente quando o programa estiver operando incorretamente. As verificações de asserção podem ser desativadas no momento da compilação definindo a macro **NDEBUG**. Você pode desligar a macro `assert` sem modificar os arquivos de origem usando uma opção de linha de comando **/DNDEBUG**. Você pode desativar a `assert` macro em seu código-fonte usando uma `#define NDEBUG` diretiva antes que o \<assert.h> seja incluído.

A `assert` macro imprime uma mensagem de diagnóstico quando a *expressão* é avaliada como **`false`** (0) e chama [`abort`](abort.md) para parar a execução do programa. Nenhuma ação será tomada se a *expressão* for **`true`** (diferente de zero). A mensagem de diagnóstico inclui a expressão com falha, o nome do número de arquivo e o número de linha em que a declaração falhou.

A mensagem de diagnóstico é impressa em caracteres largos ( `wchar_t` ). Portanto, ele funcionará como esperado, mesmo se houver caracteres Unicode na expressão.

O destino da mensagem de diagnóstico depende do tipo de aplicativo que chamou a rotina. Os aplicativos de console recebem a mensagem por meio de **stderr**. Em um aplicativo baseado no Windows, `assert` o chama a função [MessageBox](/windows/win32/api/winuser/nf-winuser-messagebox) do Windows para criar uma caixa de mensagem para exibir a mensagem com três botões: **abortar**, **repetir**e **ignorar**. Se o usuário clicar em **Anular**, o programa será anulado imediatamente. Se o usuário clicar em **Tentar Novamente**, o depurador será chamado e o usuário poderá depurar o programa se a depuração JIT (Just-In-Time) estiver habilitada. Se o usuário clicar em **ignorar**, o programa continuará com a execução normal. Clicar em **ignorar** quando houver uma condição de erro pode resultar em um comportamento indefinido, já que as pré-condições do código de chamada não foram atendidas.

Para substituir o comportamento de saída padrão independentemente do tipo de aplicativo, chame [`_set_error_mode`](set-error-mode.md) para Select entre o comportamento de entrada-para-stderr e caixa de diálogo de exibição.

Depois que `assert` o exibe sua mensagem, ele chama [`abort`](abort.md) , que exibe uma caixa de diálogo com os botões  **abortar**, **repetir**e **ignorar** . [`abort`](abort.md) Sai do programa, portanto, o botão **repetir** e **ignorar** não reiniciará a execução do programa após a `assert` chamada. Se for `assert` exibida uma caixa de diálogo, a [`abort`](abort.md) caixa de diálogo não será mostrada. A única vez em que a [`abort`](abort.md) caixa de diálogo é mostrada é quando o `assert` envia sua saída para stderr.

Como consequência do comportamento acima, uma caixa de diálogo é sempre exibida após uma `assert` chamada no modo de depuração. O comportamento de cada botão é capturado na tabela abaixo.

|Modo de erro|Saída para stderr (console/_OUT_TO_STDERR)|Caixa de diálogo de exibição (Windows/_OUT_TO_MSGBOX)|
|----------|----------------|------------------|
|Anular|Sair imediatamente com o código de saída 3|Sair imediatamente com o código de saída 3|
|Repetir|Interromper no depurador durante `abort`|Interromper no depurador durante `assert`|
|Ignorar|Concluir a saída via `abort`|Continuar programa como se o Assert não fosse acionado (pode resultar em comportamento indefinido, já que as pré-condições do código de chamada não foram atendidas)|

Para obter mais informações sobre depuração de CRT, consulte [Técnicas de Depuração CRT](/visualstudio/debugger/crt-debugging-techniques).

As funções `_assert` e `_wassert` são funções CRT internas. Elas ajudam a minimizar o código necessário em seus arquivos de objeto para dar suporte a declarações. Não recomendamos que você chame essas funções diretamente.

A `assert` macro é habilitada nas versões de lançamento e de depuração das bibliotecas de tempo de execução do C quando **NDEBUG** não está definido. Quando **NDEBUG** é definido, a macro está disponível, mas não avalia seu argumento e não tem nenhum efeito. Quando habilitada, a `assert` macro é chamada `_wassert` para sua implementação. Outras macros de declaração, [_ASSERT](assert-asserte-assert-expr-macros.md), [_ASSERTE](assert-asserte-assert-expr-macros.md) e [_ASSERT_EXPR](assert-asserte-assert-expr-macros.md), também estão disponíveis, mas somente avaliam as expressões passadas a elas quando a macro [_DEBUG](../../c-runtime-library/debug.md) tiver sido definida e quando estiverem em código vinculado à versão de depuração das bibliotecas de tempo de execução C.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`assert`, `_wassert`|\<assert.h>|

A assinatura da `_assert` função não está disponível em um arquivo de cabeçalho. A assinatura da `_wassert` função está disponível somente quando a macro **NDEBUG** não está definida.

## <a name="example"></a>Exemplo

Neste programa, a função **analyze_string** usa a `assert` macro para testar várias condições relacionadas à cadeia de caracteres e ao comprimento. Se qualquer uma das condições falhar, o programa imprimirá uma mensagem indicando o que causou a falha.

```C
// crt_assert.c
// compile by using: cl /W4 crt_assert.c
#include <stdio.h>
#include <assert.h>
#include <string.h>

void analyze_string( char *string );   // Prototype

int main( void )
{
   char  test1[] = "abc", *test2 = NULL, test3[] = "";

   printf ( "Analyzing string '%s'\n", test1 ); fflush( stdout );
   analyze_string( test1 );
   printf ( "Analyzing string '%s'\n", test2 ); fflush( stdout );
   analyze_string( test2 );
   printf ( "Analyzing string '%s'\n", test3 ); fflush( stdout );
   analyze_string( test3 );
}

// Tests a string to see if it is NULL,
// empty, or longer than 0 characters.
void analyze_string( char * string )
{
   assert( string != NULL );        // Cannot be NULL
   assert( *string != '\0' );       // Cannot be empty
   assert( strlen( string ) > 2 );  // Length must exceed 2
}
```

O programa gera esta saída:

```Output
Analyzing string 'abc'
Analyzing string '(null)'
Assertion failed: string != NULL, file crt_assert.c, line 25
```

Após a falha de asserção, dependendo da versão do sistema operacional e da biblioteca de tempo de execução, você poderá ver uma caixa de mensagem que contém algo semelhante a:

```Output
A problem caused the program to stop working correctly. Windows will close the program and notify you if a solution is available.
```

Se um depurador estiver instalado, escolha o botão **Depurar** para iniciar o depurador ou **Fechar programa** para sair.

## <a name="see-also"></a>Confira também

[Tratamento de erro](../../c-runtime-library/error-handling-crt.md)<br/>
[Controle de processo e ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[anular](abort.md)<br/>
[gera](raise.md)<br/>
[signal](signal.md)<br/>
[_ASSERT, _ASSERTE, _ASSERT_EXPR macros](assert-asserte-assert-expr-macros.md)<br/>
[_DEBUG](../../c-runtime-library/debug.md)<br/>
