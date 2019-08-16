---
title: assert Macro, _assert, _wassert
ms.date: 11/04/2016
apiname:
- assert
- _assert
- _wassert
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
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
ms.openlocfilehash: a2cc780fbc93aa66bd7fd613c3e155cda27eb7f9
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69500330"
---
# <a name="assert-macro-_assert-_wassert"></a>assert Macro, _assert, _wassert

Avalia uma expressão e, quando o resultado é **false**, imprime uma mensagem de diagnóstico e anula o programa.

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

### <a name="parameters"></a>Parâmetros

*expression*<br/>
Uma expressão escalar (incluindo expressões de ponteiro) que é avaliada como zero (**true**) ou 0 (**false**).

*message*<br/>
A mensagem a ser exibida.

*filename*<br/>
O nome do arquivo de origem no qual a declaração falhou.

*descritos*<br/>
O número de linha no arquivo de origem da declaração com falha.

## <a name="remarks"></a>Comentários

A macro **Assert** normalmente é usada para identificar erros lógicos durante o desenvolvimento do programa. Use-o para interromper a execução do programa quando condições inesperadas ocorrerem implementando o argumento *expression* para avaliar como **false** somente quando o programa estiver operando incorretamente. As verificações de asserção podem ser desativadas no momento da compilação definindo a macro **NDEBUG**. Você pode desativar a macro **Assert** sem modificar os arquivos de origem usando uma opção de linha de comando **/DNDEBUG** . Você pode desativar a macro **Assert** em seu código-fonte usando uma diretiva `#define NDEBUG` antes \<de Assert. h > é incluída.

A macro **Assert** imprime uma mensagem de diagnóstico quando a *expressão* é avaliada como **false** (0) e chama [Abort](abort.md) para encerrar a execução do programa. Nenhuma ação será tomada se a *expressão* for **true** (diferente de zero). A mensagem de diagnóstico inclui a expressão com falha, o nome do número de arquivo e o número de linha em que a declaração falhou.

A mensagem de diagnóstico é impressa em caracteres largos. Dessa forma, ela funcionará conforme o esperado, mesmo que haja caracteres Unicode na expressão.

O destino da mensagem de diagnóstico depende do tipo de aplicativo que chamou a rotina. Os aplicativos de console sempre recebem a mensagem por meio de **stderr**. Em um aplicativo baseado no Windows, **Assert** chama a função [MessageBox](/windows/win32/api/winuser/nf-winuser-messagebox) do Windows para criar uma caixa de mensagem para exibir a mensagem junto com um botão **OK** . Quando o usuário clica em **OK**, o programa é anulado imediatamente.

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução, **Assert** cria uma caixa de mensagem com três botões: **Anular**, **repetir**e **ignorar**. Se o usuário clicar em **Anular**, o programa será anulado imediatamente. Se o usuário clicar em **Tentar Novamente**, o depurador será chamado e o usuário poderá depurar o programa se a depuração JIT (Just-In-Time) estiver habilitada. Se o usuário clicar em **ignorar**, **Assert** continuará com sua execução normal: criando a caixa de mensagem com o botão **OK** . Observe que clicar em **Ignorar** quando há uma condição de erro pode resultar em comportamento indefinido.

Para obter mais informações sobre depuração de CRT, consulte [Técnicas de Depuração CRT](/visualstudio/debugger/crt-debugging-techniques).

As funções **_assert** e **_WASSERT** são funções CRT internas. Elas ajudam a minimizar o código necessário em seus arquivos de objeto para dar suporte a declarações. Não recomendamos chamar essas funções diretamente.

A macro **Assert** é habilitada nas versões de lançamento e de depuração das bibliotecas de tempo de execução do C quando **NDEBUG** não está definido. Quando **NDEBUG** é definido, a macro está disponível, mas não avalia seu argumento e não tem nenhum efeito. Quando habilitada, a macro **Assert** chama **_wassert** para sua implementação. Outras macros de declaração, [_ASSERT](assert-asserte-assert-expr-macros.md), [_ASSERTE](assert-asserte-assert-expr-macros.md) e [_ASSERT_EXPR](assert-asserte-assert-expr-macros.md), também estão disponíveis, mas somente avaliam as expressões passadas a elas quando a macro [_DEBUG](../../c-runtime-library/debug.md) tiver sido definida e quando estiverem em código vinculado à versão de depuração das bibliotecas de tempo de execução C.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**assert**, **_wassert**|\<assert.h>|

A assinatura da função **_assert** não está disponível em um arquivo de cabeçalho. A assinatura da função **_wassert** só estará disponível quando a macro **NDEBUG** não estiver definida.

## <a name="example"></a>Exemplo

Neste programa, a função **analyze_string** usa a macro **Assert** para testar várias condições relacionadas à cadeia de caracteres e ao comprimento. Se qualquer uma das condições falhar, o programa imprimirá uma mensagem indicando o que causou a falha.

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

Após a falha de asserção, dependendo da versão do sistema operacional e da biblioteca em tempo de execução, você poderá ver uma caixa de mensagem que contém algo semelhante ao seguinte:

```Output
A problem caused the program to stop working correctly. Windows will close the program and notify you if a solution is available.
```

Se um depurador estiver instalado, escolha o botão **Depurar** para iniciar o depurador ou **Fechar programa** para sair.

## <a name="see-also"></a>Consulte também

[Tratamento de erro](../../c-runtime-library/error-handling-crt.md)<br/>
[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[abort](abort.md)<br/>
[raise](raise.md)<br/>
[signal](signal.md)<br/>
[Macros _ASSERT, _ASSERTE, _ASSERT_EXPR](assert-asserte-assert-expr-macros.md)<br/>
[_DEBUG](../../c-runtime-library/debug.md)<br/>
