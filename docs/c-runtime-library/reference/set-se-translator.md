---
title: _set_se_translator
ms.date: 02/21/2018
api_name:
- _set_se_translator
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _set_se_translator
- set_se_translator
helpviewer_keywords:
- set_se_translator function
- exception handling, changing
- _set_se_translator function
ms.assetid: 280842bc-d72a-468b-a565-2d3db893ae0f
ms.openlocfilehash: f1c9446f9c3f0d637ea53d54584258959677b339
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232411"
---
# <a name="_set_se_translator"></a>_set_se_translator

Defina uma função de retorno de chamada por thread para converter exceções do Win32 (exceções estruturadas C) em exceções tipadas em C++.

## <a name="syntax"></a>Sintaxe

```cpp
_se_translator_function _set_se_translator(
    _se_translator_function seTransFunction
);
```

### <a name="parameters"></a>parâmetros

*seTransFunction*<br/>
Ponteiro para uma função conversora de exceção estruturada de C que você escreve.

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a função de Tradutor anterior registrada por **_set_se_translator**, para que a função anterior possa ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor de retorno poderá ser usado para restaurar o comportamento padrão; Esse valor pode ser **`nullptr`** .

## <a name="remarks"></a>Comentários

A função **_set_se_translator** fornece uma maneira de lidar com exceções Win32 (exceções estruturadas C) como exceções tipadas em C++. Para permitir que cada exceção C seja manipulada por um **`catch`** manipulador de C++, primeiro defina uma classe de wrapper de exceção c que possa ser usada ou derivada de, para atribuir um tipo de classe específico a uma exceção de C. Para usar essa classe, instale uma função personalizada de conversão da exceção de C, chamada pelo mecanismo interno de manipulação de exceção sempre que uma exceção de C é gerada. Dentro de sua função de tradutor, você pode lançar qualquer exceção tipada que possa ser detectada por um manipulador de C++ correspondente **`catch`** .

Você deve usar [/EHA](../../build/reference/eh-exception-handling-model.md) ao usar **_set_se_translator**.

Para especificar uma função de tradução personalizada, chame **_set_se_translator** usando o nome da sua função de tradução como seu argumento. A função do tradutor que você escreve é chamada uma vez para cada invocação de função na pilha que tem **`try`** blocos. Não há nenhuma função conversora padrão.

Sua função conversora não deve fazer nada além de gerar uma exceção tipada C++. Se ela fizer qualquer coisa além de gerar (como gravar em um arquivo de log, por exemplo), seu programa poderá não se comportar conforme o esperado, pois o número de vezes que a função conversora é invocada depende da plataforma.

Em um ambiente multithreaded, funções de conversão são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função conversora. Portanto, cada thread é responsável pela sua própria manipulação de encerramento. **_set_se_translator** é específico para um thread; outra DLL pode instalar uma função de tradução diferente.

A função *seTransFunction* que você escreve deve ser uma função compilada nativamente (não compilada com/CLR). Ele deve pegar um inteiro sem sinal e um ponteiro para uma estrutura de **_EXCEPTION_POINTERS** do Win32 como argumentos. Os argumentos são os valores de retorno de chamadas para as funções **GetExceptionCode** e **GetExceptionInformation** da API do Win32, respectivamente.

```cpp
typedef void (__cdecl *_se_translator_function)(unsigned int, struct _EXCEPTION_POINTERS* );
```

Por **_set_se_translator**, há implicações ao vincular DINAMICAMENTE o CRT; outra DLL no processo pode chamar **_set_se_translator** e substituir seu manipulador por seu próprio.

Ao usar **_set_se_translator** de código gerenciado (código compilado com/CLR) ou código gerenciado e nativo misto, lembre-se de que o tradutor afeta as exceções geradas somente no código nativo. Exceções gerenciadas geradas em código gerenciado (por exemplo, ao gerar `System::Exception`) não são roteadas por meio da função conversora. As exceções geradas no código gerenciado usando a função **RaiseException** do Win32 ou causadas por uma exceção do sistema como uma exceção de divisão por zero são roteadas pelo tradutor.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_se_translator**|\<eh.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este exemplo encapsula as chamadas para definir um tradutor de exceção estruturado e restaurar o antigo em uma classe RAII, `Scoped_SE_Translator` . Essa classe permite introduzir um tradutor específico de escopo como uma única declaração. O destruidor de classe restaura o tradutor original quando o controle sai do escopo.

```cpp
// crt_settrans.cpp
// compile with: cl /W4 /EHa crt_settrans.cpp
#include <stdio.h>
#include <windows.h>
#include <eh.h>
#include <exception>

class SE_Exception : public std::exception
{
private:
    const unsigned int nSE;
public:
    SE_Exception() noexcept : SE_Exception{ 0 } {}
    SE_Exception( unsigned int n ) noexcept : nSE{ n } {}
    unsigned int getSeNumber() const noexcept { return nSE; }
};

class Scoped_SE_Translator
{
private:
    const _se_translator_function old_SE_translator;
public:
    Scoped_SE_Translator( _se_translator_function new_SE_translator ) noexcept
        : old_SE_translator{ _set_se_translator( new_SE_translator ) } {}
    ~Scoped_SE_Translator() noexcept { _set_se_translator( old_SE_translator ); }
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

void trans_func( unsigned int u, EXCEPTION_POINTERS* )
{
    throw SE_Exception( u );
}

int main()
{
    Scoped_SE_Translator scoped_se_translator{ trans_func };
    try
    {
        SEFunc();
    }
    catch( const SE_Exception& e )
    {
        printf( "Caught a __try exception, error %8.8x.\n", e.getSeNumber() );
    }
}
```

```Output
In __try, about to force exception
In __finally
Caught a __try exception, error c0000094.
```

## <a name="example"></a>Exemplo

Embora a funcionalidade fornecida pelo **_set_se_translator** não esteja disponível em código gerenciado, é possível usar esse mapeamento em código nativo, mesmo que o código nativo esteja em uma compilação sob a opção **/CLR** , desde que o código nativo seja indicado usando `#pragma unmanaged` . Se uma exceção estruturada estiver sendo lançada em código gerenciado que será mapeado, o código que gera e manipula a exceção deve ser marcado `#pragma unmanaged` . O código a seguir mostra um uso possível. Para obter mais informações, consulte [Diretivas Pragma e a palavra-chave __Pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md).

```cpp
// crt_set_se_translator_clr.cpp
// compile with: cl /W4 /clr crt_set_se_translator_clr.cpp
#include <windows.h>
#include <eh.h>
#include <stdio.h>
#include <exception>

int thrower_func( int i ) {
   int y = 0;
   int *p = &y;
   *p = i / *p;
   return 0;
}

class SE_Exception : public std::exception
{
private:
    const unsigned int nSE;
public:
    SE_Exception() noexcept : SE_Exception{ 0 } {}
    SE_Exception( unsigned int n ) noexcept : nSE{ n } {}
    unsigned int getSeNumber() const noexcept { return nSE; }
};

class Scoped_SE_Translator
{
private:
    const _se_translator_function old_SE_translator;
public:
    Scoped_SE_Translator( _se_translator_function new_SE_translator ) noexcept
        : old_SE_translator{ _set_se_translator( new_SE_translator ) } {}
    ~Scoped_SE_Translator() noexcept { _set_se_translator( old_SE_translator ); }
};

#pragma unmanaged
void my_trans_func( unsigned int u, PEXCEPTION_POINTERS )
{
    throw SE_Exception( u );
}

void DoTest()
{
    try
    {
        thrower_func( 10 );
    }
    catch( const SE_Exception& e )
    {
        printf( "Caught SE_Exception, error %8.8x\n", e.getSeNumber() );
    }
    catch(...)
    {
        printf( "Caught unexpected SEH exception.\n" );
    }
}
#pragma managed

int main() {
    Scoped_SE_Translator scoped_se_translator{ my_trans_func };

    DoTest();
}
```

```Output
Caught SE_Exception, error c0000094
```

## <a name="see-also"></a>Confira também

[Rotinas de manipulação de exceção](../../c-runtime-library/exception-handling-routines.md)<br/>
[set_terminate](set-terminate-crt.md)<br/>
[set_unexpected](set-unexpected-crt.md)<br/>
[encerrar](terminate-crt.md)<br/>
[previsto](unexpected-crt.md)<br/>
