---
title: Macro assert, _assert, _wassert | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 23
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 97bdb002953c07aba3bf7951a6f94a058c977f9d
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="assert-macro-assert-wassert"></a>assert Macro, _assert, _wassert
Avalia uma expressão e, quando o resultado é `false`, imprime uma mensagem de diagnóstico e anula o programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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
  
#### <a name="parameters"></a>Parâmetros  
 `expression`  
 Uma expressão escalar (incluindo expressões de ponteiro) avaliada como não zero (`true`) ou 0 (`false`).  
  
 `message`  
 A mensagem a ser exibida.  
  
 `filename`  
 O nome do arquivo de origem no qual a declaração falhou.  
  
 `line`  
 O número de linha no arquivo de origem da declaração com falha.  
  
## <a name="remarks"></a>Comentários  
 A macro `assert` normalmente é usada para identificar erros de lógica durante o desenvolvimento do programa. Use-a para interromper a execução do programa quando ocorrerem condições inesperadas implementando o argumento `expression` para avaliá-la como `false` apenas quando o programa estiver funcionando incorretamente. As verificações de declaração podem ser desativadas no tempo de compilação definindo a macro `NDEBUG`. Você pode desligar a macro `assert` sem modificar os arquivos de origem usando uma opção de linha de comando **/DNDEBUG**. Você pode desligar a macro `assert` em seu código-fonte usando uma diretiva `#define NDEBUG` antes de \<assert.h> ser incluída.  
  
 A macro `assert` imprime uma mensagem de diagnóstico quando `expression` é avaliada como `false` (0) e chama [anular](../../c-runtime-library/reference/abort.md) para finalizar a execução do programa. Nenhuma ação será executada se `expression` for `true` (diferente de zero). A mensagem de diagnóstico inclui a expressão com falha, o nome do número de arquivo e o número de linha em que a declaração falhou.  
  
 A mensagem de diagnóstico é impressa em caracteres largos. Dessa forma, ela funcionará conforme o esperado, mesmo que haja caracteres Unicode na expressão.  
  
 O destino da mensagem de diagnóstico depende do tipo de aplicativo que chamou a rotina. Aplicativos de console sempre recebem a mensagem por meio de `stderr`. Em um aplicativo baseado no Windows, `assert` chama a função [MessageBox](http://msdn.microsoft.com/library/windows/desktop/ms645505) do Windows para criar uma caixa de mensagem para exibir a mensagem junto com o botão **OK**. Quando o usuário clica em **OK**, o programa é anulado imediatamente.  
  
 Quando o aplicativo está vinculado a uma versão de depuração das bibliotecas de tempo de execução, `assert` cria uma caixa de mensagem com três botões: **Anular**, **Tentar Novamente** e **Ignorar**. Se o usuário clicar em **Anular**, o programa será anulado imediatamente. Se o usuário clicar em **Tentar Novamente**, o depurador será chamado e o usuário poderá depurar o programa se a depuração JIT (Just-In-Time) estiver habilitada. Se o usuário clicar em **Ignorar**, `assert` continuará com sua execução normal: criando a caixa de mensagem com o botão **OK**. Observe que clicar em **Ignorar** quando há uma condição de erro pode resultar em comportamento indefinido.  
  
 Para obter mais informações sobre depuração de CRT, consulte [Técnicas de Depuração CRT](/visualstudio/debugger/crt-debugging-techniques).  
  
 As funções `_assert` e `_wassert` são funções CRT internas. Elas ajudam a minimizar o código necessário em seus arquivos de objeto para dar suporte a declarações. Não recomendamos chamar essas funções diretamente.  
  
 A macro `assert` é habilitada nas versões de liberação e depuração das bibliotecas de tempo de execução C quando `NDEBUG` não está definido. Quando `NDEBUG` está definido, a macro está disponível, mas não avalia seu argumento e não tem nenhum efeito. Quando habilitada, a macro `assert` chama `_wassert` para sua implementação. Outras macros de declaração, [_ASSERT](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md), [_ASSERTE](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) e [_ASSERT_EXPR](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md), também estão disponíveis, mas somente avaliam as expressões passadas a elas quando a macro [_DEBUG](../../c-runtime-library/debug.md) tiver sido definida e quando estiverem em código vinculado à versão de depuração das bibliotecas de tempo de execução C.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`assert`, `_wassert`|\<assert.h>|  
  
 A assinatura da função `_assert` não está disponível em um arquivo de cabeçalho. A assinatura da função `_wassert` está disponível somente quando a macro `NDEBUG` não está definida.  
  
## <a name="example"></a>Exemplo  
 Neste programa, a função `analyze_string` usa a macro `assert` para testar várias condições relacionadas à cadeia de caracteres e ao comprimento. Se qualquer uma das condições falhar, o programa imprimirá uma mensagem indicando o que causou a falha.  
  
```  
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
 [Tratamento de erro](../../c-runtime-library/error-handling-crt.md)   
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [raise](../../c-runtime-library/reference/raise.md)   
 [signal](../../c-runtime-library/reference/signal.md)   
 [Macros _ASSERT, _ASSERTE, _ASSERT_EXPR](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md)   
 [_DEBUG](../../c-runtime-library/debug.md)
