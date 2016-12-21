---
title: "Macro Assert, _wassert de declara&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "assert"
  - "_assert"
  - "_wassert"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "assert"
  - "_assert"
  - "_wassert"
  - "assert/_wassert"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "anulando programas"
  - "Função assert"
  - "macros de declaração"
ms.assetid: a9ca031a-648b-47a6-bdf1-65fc7399dd40
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Macro Assert, _wassert de declara&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Avalia uma expressão e, quando o resultado é `false`, imprime uma mensagem de diagnóstico e anula o programa.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `expression`  
 Uma expressão escalar \(incluindo expressões de ponteiro\) que é avaliada como zero \(`true`\) ou 0 \(`false`\).  
  
 `message`  
 A mensagem a ser exibida.  
  
 `filename`  
 O nome do arquivo de origem da falha de asserção em.  
  
 `line`  
 O número da linha no arquivo de origem da asserção com falha.  
  
## Comentários  
 O `assert` macro normalmente é usada para identificar erros de lógica durante o desenvolvimento do programa. Usá\-lo para interromper a execução do programa quando ocorrem condições inesperadas Implementando o `expression` argumento a ser avaliada como `false` apenas quando o programa estiver funcionando incorretamente. Verificações de asserção podem ser desabilitadas no momento da compilação definindo a macro `NDEBUG`. Você pode desativar o `assert` macro sem modificar os arquivos de origem usando um **\/DNDEBUG** opção de linha de comando. Você pode desativar o `assert` macro em seu código\-fonte usando um `#define NDEBUG` diretiva antes de \< Assert \> está incluído.  
  
 O `assert` imprime macro um diagnóstico mensagem quando `expression` for avaliada como `false` \(0\) e chamadas [anular](../../c-runtime-library/reference/abort.md) para finalizar a execução do programa. Nenhuma ação é executada se `expression` é `true` \(diferente de zero\). A mensagem de diagnóstico inclui a expressão com falha, o nome do que o número de arquivo e a linha de origem onde a asserção falha.  
  
 A mensagem de diagnóstico é impresso em caracteres largos. Dessa forma, ele funcionará conforme o esperado, mesmo se houver caracteres Unicode na expressão.  
  
 O destino da mensagem de diagnóstico depende do tipo de aplicativo que chamou a rotina. Aplicativos de console sempre recebem a mensagem por meio de `stderr`. Em um aplicativo baseado no Windows, `assert` chama o Windows [MessageBox](http://msdn.microsoft.com/library/windows/desktop/ms645505) função para criar uma caixa de mensagem para exibir a mensagem junto com um **OK** botão. Quando o usuário clica **OK**, o programa anula imediatamente.  
  
 Quando o aplicativo está vinculado a uma versão de depuração das bibliotecas de tempo de execução, `assert` cria uma caixa de mensagem com três botões: **anular**, **novamente**, e **Ignorar**. Se o usuário clicar **anular**, o programa anula imediatamente. Se o usuário clicar **novamente**, o depurador é chamado e o usuário pode depurar o programa se a depuração just\-in\-time \(JIT\) está habilitada. Se o usuário clicar **Ignorar**, `assert` continua com sua execução normal: criar a caixa de mensagem com o **OK** botão. Observe que clicar em **Ignorar** quando existe uma condição de erro pode resultar em um comportamento indefinido.  
  
 Para obter mais informações sobre depuração de CRT, consulte [técnicas de depuração CRT](../Topic/CRT%20Debugging%20Techniques.md).  
  
 O `_assert` e `_wassert` funções são funções de CRT internas. Elas ajudam a minimizar o código necessário em seus arquivos de objeto para dar suporte a declarações. Não recomendamos que você chamar essas funções diretamente.  
  
 O `assert` macro é habilitada em ambas as versões de lançamento e de depuração das bibliotecas de tempo de execução do C quando `NDEBUG` não está definido. Quando `NDEBUG` é definida, a macro está disponível, mas não avalia seu argumento e não tem nenhum efeito. Quando habilitada, o `assert` chamadas macro `_wassert` para sua implementação. Outras macros de declaração, [Assert](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md), [asserte](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md) e [\_ASSERT\_EXPR](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md), também estão disponíveis, mas eles só avaliação as expressões passadas a eles quando o [Debug](../Topic/_DEBUG.md) macro tiver sido definida e quando estão em código vinculado com a versão de depuração das bibliotecas de tempo de execução do C.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`assert`, `_wassert`|\< Assert \>|  
  
 A assinatura de `_assert` função não está disponível em um arquivo de cabeçalho. A assinatura do `_wassert` função está disponível somente quando o `NDEBUG` macro não está definida.  
  
## Exemplo  
 Neste programa, o `analyze_string` função usa o `assert` macro para testar várias condições relacionadas a cadeia de caracteres e comprimento. Se qualquer uma das condições falhar, o programa imprime uma mensagem indicando o que causou a falha.  
  
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
Analisar a cadeia de caracteres 'abc' analisar cadeia de caracteres '(null)' Assertion failed: cadeia de caracteres! = NULL, o arquivo crt_assert.c, linha 25  
```  
  
 Após a falha de asserção, dependendo da versão do sistema operacional e da biblioteca de tempo de execução, você verá uma caixa de mensagem que contém algo semelhante ao seguinte:  
  
```Output  
Um problema causado o programa pare de funcionar corretamente. O Windows fechar o programa e notificá-lo se houver uma solução disponível.  
```  
  
 Se um depurador estiver instalado, escolha o **Depurar** botão para iniciar o depurador, ou **Close program** para sair.  
  
## Equivalência do .NET Framework  
 [System::Diagnostics::Debug:: Assert](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.assert.aspx)  
  
## Consulte também  
 [Tratamento de erros](../../c-runtime-library/error-handling-crt.md)   
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [raise](../../c-runtime-library/reference/raise.md)   
 [signal](../../c-runtime-library/reference/signal.md)   
 [Assert, asserte, \_ASSERT\_EXPR macros](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md)   
 [\_DEBUG](../Topic/_DEBUG.md)