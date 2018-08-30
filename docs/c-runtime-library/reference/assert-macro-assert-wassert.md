---
title: Macro assert, _assert, _wassert | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- aborting programs
- assert function
- assert macro
ms.assetid: a9ca031a-648b-47a6-bdf1-65fc7399dd40
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c1d2bef607e80e2e972915bd8a8b0517b7c6e5eb
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43200661"
---
# <a name="assert-macro-assert-wassert"></a>assert Macro, _assert, _wassert

Avalia uma expressão e, quando o resultado será **falsos**, imprime uma mensagem de diagnóstico e anula o programa.

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

*expressão* uma expressão escalar (incluindo expressões de ponteiro) avaliada como não zero (**verdadeira**) ou 0 (**falso**).

*mensagem* a mensagem a ser exibida.

*nome do arquivo* o nome da fonte de arquivo Falha na asserção.

*linha* o número de linha no arquivo de origem da asserção com falha.

## <a name="remarks"></a>Comentários

O **assert** macro normalmente é usada para identificar erros de lógica durante o desenvolvimento do programa. Use-o para interromper a execução do programa quando ocorrerem condições inesperadas Implementando o *expressão* argumento a ser avaliada como **falso** somente quando o programa estiver funcionando incorretamente. Verificações de declaração podem ser desativadas no momento da compilação definindo a macro **NDEBUG**. Você pode desativar a **assert** macro sem modificar seus arquivos de origem usando uma **/DNDEBUG** opção de linha de comando. Você pode desativar a **assert** macro em seu código-fonte usando uma `#define NDEBUG` diretiva antes \<Assert > está incluído.

O **assert** imprime macro uma mensagem de diagnóstico quando *expressão* for avaliada como **falso** (0) e chamadas [anular](abort.md) para encerrar o programa execução. Nenhuma ação é executada se *expressão* é **verdadeiro** (diferente de zero). A mensagem de diagnóstico inclui a expressão com falha, o nome do número de arquivo e o número de linha em que a declaração falhou.

A mensagem de diagnóstico é impressa em caracteres largos. Dessa forma, ela funcionará conforme o esperado, mesmo que haja caracteres Unicode na expressão.

O destino da mensagem de diagnóstico depende do tipo de aplicativo que chamou a rotina. Aplicativos de console sempre recebem a mensagem por meio **stderr**. Em um aplicativo baseado em Windows, **assert** chama o Windows [MessageBox](/windows/desktop/api/winuser/nf-winuser-messagebox) função para criar uma caixa de mensagem para exibir a mensagem junto com um **Okey** botão. Quando o usuário clica em **OK**, o programa é anulado imediatamente.

Quando o aplicativo estiver vinculado a uma versão de depuração das bibliotecas do tempo de execução, **assert** cria uma caixa de mensagem com três botões: **anular**, **repetir**e **Ignorar**. Se o usuário clicar em **Anular**, o programa será anulado imediatamente. Se o usuário clicar em **Tentar Novamente**, o depurador será chamado e o usuário poderá depurar o programa se a depuração JIT (Just-In-Time) estiver habilitada. Se o usuário clica **Ignore**, **assert** continua com sua execução normal: Criando a caixa de mensagem com o **Okey** botão. Observe que clicar em **Ignorar** quando há uma condição de erro pode resultar em comportamento indefinido.

Para obter mais informações sobre depuração de CRT, consulte [Técnicas de Depuração CRT](/visualstudio/debugger/crt-debugging-techniques).

O **macros Assert** e **wassert** funções são funções CRT internas. Elas ajudam a minimizar o código necessário em seus arquivos de objeto para dar suporte a declarações. Não recomendamos chamar essas funções diretamente.

O **assert** macro está habilitada em ambas as versões de lançamento e de depuração das bibliotecas de tempo de execução C quando **NDEBUG** não está definido. Quando **NDEBUG** é definido, a macro está disponível, mas não avalia seu argumento e não tem nenhum efeito. Quando habilitada, o **assert** chamadas macro **wassert** para sua implementação. Outras macros de declaração, [_ASSERT](assert-asserte-assert-expr-macros.md), [_ASSERTE](assert-asserte-assert-expr-macros.md) e [_ASSERT_EXPR](assert-asserte-assert-expr-macros.md), também estão disponíveis, mas somente avaliam as expressões passadas a elas quando a macro [_DEBUG](../../c-runtime-library/debug.md) tiver sido definida e quando estiverem em código vinculado à versão de depuração das bibliotecas de tempo de execução C.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**Assert**, **wassert**|\<assert.h>|

A assinatura do **macros Assert** função não está disponível em um arquivo de cabeçalho. A assinatura do **wassert** função está disponível apenas quando o **NDEBUG** macro não está definida.

## <a name="example"></a>Exemplo

Neste programa, o **analyze_string** função usa o **assert** macro para testar várias condições relacionadas a cadeia de caracteres e comprimento. Se qualquer uma das condições falhar, o programa imprimirá uma mensagem indicando o que causou a falha.

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
