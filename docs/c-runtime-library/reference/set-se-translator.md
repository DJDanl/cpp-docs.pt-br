---
title: _set_se_translator
ms.date: 02/21/2018
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
helpviewer_keywords:
- set_se_translator function
- exception handling, changing
- _set_se_translator function
ms.assetid: 280842bc-d72a-468b-a565-2d3db893ae0f
ms.openlocfilehash: 18ee500d7b884d1934c29dc91d9bcb03d507680d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62356544"
---
# <a name="setsetranslator"></a>_set_se_translator

Defina uma função de retorno de chamada por thread para converter exceções do Win32 (exceções C estruturadas) em C++ digitado exceções.

## <a name="syntax"></a>Sintaxe

```cpp
_se_translator_function _set_se_translator(
    _se_translator_function seTransFunction
);
```

### <a name="parameters"></a>Parâmetros

*seTransFunction*<br/>
Ponteiro para uma função conversora de exceção estruturada de C que você escreve.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a função conversora anterior registrado por **set_se_translator**, de modo que a função anterior possa ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor de retorno pode ser usado para restaurar o comportamento padrão; Esse valor pode ser **nullptr**.

## <a name="remarks"></a>Comentários

O **set_se_translator** função fornece uma maneira de lidar com exceções do Win32 (exceções C estruturadas) como C++ exceções. Para permitir que cada exceção de C a serem manipuladas por um C++ **catch** manipulador, primeiro defina uma classe de wrapper de exceção de C que pode ser usada ou derivada, para atribuir um tipo de classe específico a uma exceção de C. Para usar essa classe, instale uma função personalizada de conversão da exceção de C, chamada pelo mecanismo interno de manipulação de exceção sempre que uma exceção de C é gerada. Dentro de sua função translator, você pode gerar qualquer exceção tipada que pode ser capturada por um C++ correspondente **catch** manipulador.

Você deve usar [/EHa](../../build/reference/eh-exception-handling-model.md) ao usar **set_se_translator**.

Para especificar uma função personalizada de tradução, chame **set_se_translator** usando o nome da sua função de conversão como seu argumento. A função de tradução que você escreve é chamada uma vez para cada invocação de função na pilha que tem **tente** blocos. Não há nenhuma função conversora padrão.

Sua função conversora não deve fazer nada além de gerar uma exceção tipada C++. Se ela fizer qualquer coisa além de gerar (como gravar em um arquivo de log, por exemplo), seu programa poderá não se comportar conforme o esperado, pois o número de vezes que a função conversora é invocada depende da plataforma.

Em um ambiente multithreaded, funções de conversão são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função conversora. Portanto, cada thread é responsável pela sua própria manipulação de encerramento. **set_se_translator** é específico para um thread; outra DLL pode instalar uma função de conversão diferentes.

O *seTransFunction* função que você escreve deve ser uma função nativo compilado (não compilada com /clr). Ele deve levar um inteiro sem sinal e um ponteiro para um Win32 **exception_pointers** estrutura como argumentos. Os argumentos são os valores de retorno de chamadas à API do Win32 **GetExceptionCode** e **GetExceptionInformation** funções, respectivamente.

```cpp
typedef void (__cdecl *_se_translator_function)(unsigned int, struct _EXCEPTION_POINTERS* );
```

Para **set_se_translator**, há implicações ao vincular dinamicamente ao CRT; outra DLL no processo pode chamar **set_se_translator** e substituir o manipulador com seu próprio.

Ao usar **set_se_translator** do código gerenciado (código compilado com /clr) ou misto de código gerenciado e nativo, esteja ciente de que a conversora afeta as exceções geradas em código nativo somente. Exceções gerenciadas geradas em código gerenciado (por exemplo, ao gerar `System::Exception`) não são roteadas por meio da função conversora. As exceções geradas em código gerenciado usando a função Win32 **RaiseException** ou causado por uma exceção do sistema como uma divisão por zero exceção são roteadas por meio da conversora.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_se_translator**|\<eh.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

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

Embora a funcionalidade fornecida pela **set_se_translator** é não está disponível no código gerenciado, é possível usar esse mapeamento em código nativo, mesmo que o código nativo está em uma compilação na **/clr** Alternar, desde que o código nativo seja indicado usando `#pragma unmanaged`. Se uma exceção estruturada está sendo lançada em código gerenciado que deve ser mapeado, o código que gera e manipula a exceção deve ser marcado `#pragma unmanaged`. O código a seguir mostra um uso possível. Para obter mais informações, consulte [Diretivas Pragma e a palavra-chave __Pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md).

```cpp
// crt_set_se_translator_clr.cpp
// compile with: cl /W4 /clr crt_set_se_translator_clr.cpp
#include <windows.h>
#include <eh.h>
#include <assert.h>
#include <stdio.h>
#include <exception>

int thrower_func(int i) {
   int y = 0;
   int *p = &y;
   *p = i / *p;
   return 0;
}

class SE_Exception : public std::exception {
private:
    unsigned int nSE;
public:
    SE_Exception() : nSE{ 0 } {}
    SE_Exception(unsigned int n) : nSE{ n } {}
    unsigned int getSeNumber() { return nSE; }
};

#pragma unmanaged
void my_trans_func(unsigned int u, PEXCEPTION_POINTERS)
{
    throw SE_Exception(u);
}

void DoTest()
{
    try
    {
        thrower_func(10);
    }
    catch(SE_Exception& e)
    {
        printf("Caught SE_Exception, error %8.8x\n", e.getSeNumber());
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
Caught SE_Exception, error c0000094
```

## <a name="see-also"></a>Consulte também

[Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)<br/>
[set_terminate](set-terminate-crt.md)<br/>
[set_unexpected](set-unexpected-crt.md)<br/>
[terminate](terminate-crt.md)<br/>
[unexpected](unexpected-crt.md)<br/>
