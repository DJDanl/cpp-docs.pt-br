---
title: _set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler
ms.date: 11/04/2016
api_name:
- _set_invalid_parameter_handler
- _set_thread_local_invalid_parameter_handler
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
- set_invalid_parameter_handler
- _set_invalid_parameter_handler
- _set_thread_local_invalid_parameter_handler
helpviewer_keywords:
- invalid parameter handler
- set_invalid_parameter_handler function
- _set_invalid_parameter_handler function
- _set_thread_local_invalid_parameter_handler function
ms.assetid: c0e67934-1a41-4016-ad8e-972828f3ac11
ms.openlocfilehash: d2e8dab92c70189533656bac359c794de2ad8002
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857769"
---
# <a name="_set_invalid_parameter_handler-_set_thread_local_invalid_parameter_handler"></a>_set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler

Define a função a ser chamada quando o CRT detecta um argumento inválido.

## <a name="syntax"></a>Sintaxe

```C
_invalid_parameter_handler _set_invalid_parameter_handler(
   _invalid_parameter_handler pNew
);
_invalid_parameter_handler _set_thread_local_invalid_parameter_handler(
   _invalid_parameter_handler pNew
);
```

### <a name="parameters"></a>Parâmetros

*pNew*<br/>
O ponteiro de função para o novo manipulador de parâmetro inválido.

## <a name="return-value"></a>Valor retornado

Um ponteiro para o manipulador de parâmetro inválido antes da chamada.

## <a name="remarks"></a>Comentários

Muitas funções em runtime C verificam a validade dos argumentos passados para elas. Se um argumento inválido for passado, a função poderá definir o número de erro **errno** ou retornar um código de erro. Nesses casos, o manipulador de parâmetro inválido também é chamado. O runtime C fornece um manipulador de parâmetro inválido global padrão que encerra o programa e exibe uma mensagem de erro de runtime. Você pode usar a **_set_invalid_parameter_handler** para definir sua própria função como o manipulador de parâmetro global inválido. O runtime C também dá suporte a um manipulador de parâmetro inválido local de thread. Se um manipulador de parâmetro de local de thread for definido em um thread usando **_set_thread_local_invalid_parameter_handler**, as funções de tempo de execução C chamadas do thread usarão esse manipulador em vez do manipulador global. Apenas uma função por vez pode ser especificada como o manipulador de argumento inválido global. Apenas uma função por thread pode ser especificada como o manipulador de argumento inválido local de thread, mas threads diferentes podem ter diferentes manipuladores locais de thread. Isso permite que você altere o manipulador usado em uma parte do seu código sem afetar o comportamento de outros threads.

Quando o runtime chama a função de parâmetro inválido, isso normalmente significa que ocorreu um erro irrecuperável. A função de manipulador de parâmetro inválido fornecida por você deve salvar todos os dados que puder e, em seguida, anular. Ela não deve retornar o controle para a função principal a menos que você tenha certeza de que o erro é recuperável.

A função de manipulador de parâmetro inválido deve ter o seguinte protótipo:

```C
void _invalid_parameter(
   const wchar_t * expression,
   const wchar_t * function,
   const wchar_t * file,
   unsigned int line,
   uintptr_t pReserved
);
```

O argumento *expression* é uma representação de cadeia de caracteres larga da expressão de argumento que gerou o erro. O argumento da *função* é o nome da função CRT que recebeu o argumento inválido. O argumento *File* é o nome do arquivo de origem do CRT que contém a função. O argumento de *linha* é o número de linha nesse arquivo. O último argumento é reservado. Todos os parâmetros têm o valor **NULL** , a menos que uma versão de depuração da biblioteca CRT seja usada.

## <a name="requirements"></a>Requisitos do

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_invalid_parameter_handler**, **_set_thread_local_invalid_parameter_handler**|C: \<stdlib.h><br /><br /> C++: \<cstdlib> ou \<stdlib.h>|

As funções **_set_invalid_parameter_handler** e **_set_thread_local_invalid_parameter_handler** são específicas da Microsoft. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

No exemplo a seguir, um manipulador de erro de parâmetro inválido é usado para imprimir a função que recebeu o parâmetro inválido e o arquivo e a linha em fontes de CRT. Quando a biblioteca de depuração CRT é usada, erros de parâmetro inválido também geram uma asserção, que é desabilitada neste exemplo usando [CrtSetReportMode](crtsetreportmode.md).

```C
// crt_set_invalid_parameter_handler.c
// compile with: /Zi /MTd
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>  // For _CrtSetReportMode

void myInvalidParameterHandler(const wchar_t* expression,
   const wchar_t* function,
   const wchar_t* file,
   unsigned int line,
   uintptr_t pReserved)
{
   wprintf(L"Invalid parameter detected in function %s."
            L" File: %s Line: %d\n", function, file, line);
   wprintf(L"Expression: %s\n", expression);
   abort();
}

int main( )
{
   char* formatString;

   _invalid_parameter_handler oldHandler, newHandler;
   newHandler = myInvalidParameterHandler;
   oldHandler = _set_invalid_parameter_handler(newHandler);

   // Disable the message box for assertions.
   _CrtSetReportMode(_CRT_ASSERT, 0);

   // Call printf_s with invalid parameters.

   formatString = NULL;
   printf(formatString);
}
```

```Output
Invalid parameter detected in function common_vfprintf. File: minkernel\crts\ucrt\src\appcrt\stdio\output.cpp Line: 32
Expression: format != nullptr
```

## <a name="see-also"></a>Consulte também

[_get_invalid_parameter_handler, _get_thread_local_invalid_parameter_handler](get-invalid-parameter-handler-get-thread-local-invalid-parameter-handler.md)<br/>
[Versões de funções CRT com segurança aprimorada](../../c-runtime-library/security-enhanced-versions-of-crt-functions.md)<br/>
[errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)<br/>
