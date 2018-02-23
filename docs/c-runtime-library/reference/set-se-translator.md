---
title: _set_se_translator | Microsoft Docs
ms.custom: 
ms.date: 02/21/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _set_se_translator
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
- _set_se_translator
- set_se_translator
dev_langs:
- C++
helpviewer_keywords:
- set_se_translator function
- exception handling, changing
- _set_se_translator function
ms.assetid: 280842bc-d72a-468b-a565-2d3db893ae0f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5b5eec59acfe65189368a9b0555c3065b7159aae
ms.sourcegitcommit: a5a69d2dc3513261e9e28320e4e067aaf40d2ef2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/21/2018
---
# <a name="setsetranslator"></a>_set_se_translator

Defina uma função de retorno de chamada por thread para traduzir Win32 exceções (C estruturado de exceções) em C++ digitado exceções.

## <a name="syntax"></a>Sintaxe

```cpp
_se_translator_function _set_se_translator(
    _se_translator_function seTransFunction
);
```

### <a name="parameters"></a>Parâmetros

*seTransFunction*  
Ponteiro para uma função conversora de exceção estruturada de C que você escreve.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a função conversora anterior registrada por `_set_se_translator`, de modo que a função anterior possa ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor de retorno pode ser usado para restaurar o comportamento padrão; Esse valor pode ser **nullptr**.

## <a name="remarks"></a>Comentários

A função `_set_se_translator` fornece um meio para manipular exceções do Win32 (exceções C estruturadas) como exceções tipadas C++. Para permitir que cada exceção de C seja manipulada por um manipulador `catch` C++, primeiro defina uma classe wrapper de exceção de C que possa ser usada – ou da qual seja possível obter uma classe derivada – para atribuir um tipo de classe específico a uma exceção de C. Para usar essa classe, instale uma função personalizada de conversão da exceção de C, chamada pelo mecanismo interno de manipulação de exceção sempre que uma exceção de C é gerada. Dentro de sua função translator, você pode gerar qualquer exceção tipada que pode ser capturada por um manipulador `catch` C++ correspondente.

Você deve usar [/EHa](../../build/reference/eh-exception-handling-model.md) ao usar `_set_se_translator`.

Para especificar uma função de conversão personalizado, chame `_set_se_translator` usando o nome da sua função de conversão como seu argumento. A função de conversão que você grava é chamada uma vez para cada invocação de função na pilha que tem blocos `try`. Não há nenhuma função conversora padrão.

Sua função conversora não deve fazer nada além de gerar uma exceção tipada C++. Se ela fizer qualquer coisa além de gerar (como gravar em um arquivo de log, por exemplo), seu programa poderá não se comportar conforme o esperado, pois o número de vezes que a função conversora é invocada depende da plataforma.

Em um ambiente multithreaded, funções de conversão são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função conversora. Portanto, cada thread é responsável pela sua própria manipulação de encerramento. `_set_se_translator` é específico para um thread; outra DLL pode instalar uma função de conversão diferente.

O *seTransFunction* função que você escreve deve ser uma função nativo compilado (não compilada com /clr). Ela precisa levar como argumentos um inteiro sem sinal e um ponteiro para uma estrutura `_EXCEPTION_POINTERS` Win32. Os argumentos são os valores retornados das chamadas às funções `GetExceptionCode` e `GetExceptionInformation` de API do Win32, respectivamente.

```cpp
typedef void (__cdecl *_se_translator_function)(unsigned int, struct _EXCEPTION_POINTERS* );
```

Para `_set_se_translator`, há implicações ao vincular dinamicamente ao CRT; outra DLL no processo pode chamar `_set_se_translator` e substituir o manipulador usado por você pelo manipulador da própria DLL.

Ao usar `_set_se_translator` do código gerenciado (código compilado com /clr) ou do código misto gerenciado e nativo, esteja ciente de que a conversora afeta somente as exceções geradas em código nativo. Exceções gerenciadas geradas em código gerenciado (por exemplo, ao gerar `System::Exception`) não são roteadas por meio da função conversora. Exceções geradas em código gerenciado usando a função `RaiseException` Win32 ou causadas por uma exceção do sistema como uma exceção de divisão por zero são roteadas por meio da conversora.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`_set_se_translator`|\<eh.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```cpp
// crt_settrans.cpp
// compile with: cl /W4 /EHa crt_settrans.cpp
#include <stdio.h>
#include <windows.h>
#include <eh.h>

class SE_Exception
{
private:
    unsigned int nSE;
public:
    SE_Exception() : nSE{ 0 } {}
    SE_Exception( unsigned int n ) : nSE{ n } {}
    unsigned int getSeNumber() { return nSE; }
};

void SEFunc()
{
    __try
    {
        printf( "In __try, about to force exception\n" );
        int x = 5;
        int y = 0;
        int *p = &y;
        *p = x / *p;
    }
    __finally
    {
        printf( "In __finally\n" );
    }
}

void trans_func(unsigned int u, EXCEPTION_POINTERS*)
{
    throw SE_Exception(u);
}

int main()
{
    auto original = _set_se_translator(trans_func); 
    try
    {
        SEFunc();
    }
    catch(SE_Exception& e)
    {
        printf("Caught a __try exception, error %8.8x.\n", e.getSeNumber());
    }
    _set_se_translator(original);
}
```

```Output
In __try, about to force exception
In __finally
Caught a __try exception, error c0000094.
```

## <a name="example"></a>Exemplo

Embora a funcionalidade fornecida pelo `_set_se_translator` não esteja disponível em código gerenciado, é possível usar esse mapeamento em código nativo, mesmo que o código nativo esteja em uma compilação no comutador `/clr`, desde que o código nativo seja indicado usando `#pragma unmanaged`. Se uma exceção estruturada está sendo lançada em código gerenciado que deve ser mapeado, o código que gera e manipula a exceção deve ser marcado `#pragma unmanaged`. O código a seguir mostra um uso possível. Para obter mais informações, consulte [Diretivas Pragma e a palavra-chave __Pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md).

```cpp
// crt_set_se_translator_clr.cpp
// compile with: cl /W4 /clr crt_set_se_translator_clr.cpp
#include <windows.h>
#include <eh.h>
#include <assert.h>
#include <stdio.h>

int thrower_func(int i) {
   int y = 0;
   int *p = &y;
   *p = i / *p;
   return 0;
}

class CMyException{
private:
    unsigned int nSE;
public:
    CMyException() : nSE{ 0 } {}
    CMyException(unsigned int n) : nSE{ n } {}
    unsigned int getSeNumber() { return nSE; }
};

#pragma unmanaged
void my_trans_func(unsigned int u, PEXCEPTION_POINTERS)
{
    throw CMyException(u);
}

void DoTest()
{
    try
    {
        thrower_func(10);
    }
    catch(CMyException e)
    {
        printf("Caught CMyException.\n");
    }
    catch(...)
    {
        printf("Caught unexpected SEH exception.\n");
    }
}
#pragma managed

int main() {
    auto original = _set_se_translator(my_trans_func);
    DoTest();
    _set_se_translator(original);
}
```

```Output
Caught CMyException, error c0000094
```

## <a name="see-also"></a>Consulte também

[Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)  
[set_terminate](../../c-runtime-library/reference/set-terminate-crt.md)  
[set_unexpected](../../c-runtime-library/reference/set-unexpected-crt.md)  
[terminate](../../c-runtime-library/reference/terminate-crt.md)  
[unexpected](../../c-runtime-library/reference/unexpected-crt.md)  
