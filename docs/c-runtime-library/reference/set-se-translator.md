---
title: _set_se_translator | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
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
ms.openlocfilehash: df4705972f45fd129462f5a3f131c72135254620
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="setsetranslator"></a>_set_se_translator
Trata exceções do Win32 (exceções C estruturadas) como exceções C++.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_se_translator_function _set_se_translator(  
   _se_translator_function seTransFunction  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `seTransFunction`  
 Ponteiro para uma função conversora de exceção estruturada de C que você escreve.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a função conversora anterior registrada por `_set_se_translator`, de modo que a função anterior possa ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor retornado poderá ser usado para restaurar o comportamento padrão; esse valor pode ser NULL.  
  
## <a name="remarks"></a>Comentários  
 A função `_set_se_translator` fornece um meio para manipular exceções do Win32 (exceções C estruturadas) como exceções tipadas C++. Para permitir que cada exceção de C seja manipulada por um manipulador `catch` C++, primeiro defina uma classe wrapper de exceção de C que possa ser usada – ou da qual seja possível obter uma classe derivada – para atribuir um tipo de classe específico a uma exceção de C. Para usar essa classe, instale uma função personalizada de conversão da exceção de C, chamada pelo mecanismo interno de manipulação de exceção sempre que uma exceção de C é gerada. Dentro de sua função translator, você pode gerar qualquer exceção tipada que pode ser capturada por um manipulador `catch` C++ correspondente.  
  
 Você deve usar [/EHa](../../build/reference/eh-exception-handling-model.md) ao usar `_set_se_translator`.  
  
 Para especificar uma função de conversão personalizada, chame `_set_se_translator` com o nome da função de conversão como seu único argumento. A função de conversão que você grava é chamada uma vez para cada invocação de função na pilha que tem blocos `try`. Não há nenhuma função conversora padrão.  
  
 Sua função conversora não deve fazer nada além de gerar uma exceção tipada C++. Se ela fizer qualquer coisa além de gerar (como gravar em um arquivo de log, por exemplo), seu programa poderá não se comportar conforme o esperado, pois o número de vezes que a função conversora é invocada depende da plataforma.  
  
 Em um ambiente multithreaded, funções de conversão são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função conversora. Portanto, cada thread é responsável pela sua própria manipulação de encerramento. `_set_se_translator` é específico para um thread; outra DLL pode instalar uma função de conversão diferente.  
  
 A função `seTransFunction` que você escreve deve ser uma função compilada de modo nativo (não compilada com /clr). Ela precisa levar como argumentos um inteiro sem sinal e um ponteiro para uma estrutura `_EXCEPTION_POINTERS` Win32. Os argumentos são os valores retornados das chamadas às funções `GetExceptionCode` e `GetExceptionInformation` de API do Win32, respectivamente.  
  
```  
typedef void (*_se_translator_function)(unsigned int, struct _EXCEPTION_POINTERS* );  
```  
  
 Para `_set_se_translator`, há implicações ao vincular dinamicamente ao CRT; outra DLL no processo pode chamar `_set_se_translator` e substituir o manipulador usado por você pelo manipulador da própria DLL.  
  
 Ao usar `_set_se_translator` do código gerenciado (código compilado com /clr) ou do código misto gerenciado e nativo, esteja ciente de que a conversora afeta somente as exceções geradas em código nativo. Exceções gerenciadas geradas em código gerenciado (por exemplo, ao gerar `System::Exception`) não são roteadas por meio da função conversora. Exceções geradas em código gerenciado usando a função `RaiseException` Win32 ou causadas por uma exceção do sistema como uma exceção de divisão por zero são roteadas por meio da conversora.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_set_se_translator`|\<eh.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_settrans.cpp  
// compile with: /EHa  
#include <stdio.h>  
#include <windows.h>  
#include <eh.h>  
  
void SEFunc();  
void trans_func( unsigned int, EXCEPTION_POINTERS* );  
  
class SE_Exception  
{  
private:  
    unsigned int nSE;  
public:  
    SE_Exception() {}  
    SE_Exception( unsigned int n ) : nSE( n ) {}  
    ~SE_Exception() {}  
    unsigned int getSeNumber() { return nSE; }  
};  
int main( void )  
{  
    try  
    {  
        _set_se_translator( trans_func );  
        SEFunc();  
    }  
    catch( SE_Exception e )  
    {  
        printf( "Caught a __try exception with SE_Exception.\n" );  
    }  
}  
void SEFunc()  
{  
    __try  
    {  
        int x, y=0;  
        x = 5 / y;  
    }  
    __finally  
    {  
        printf( "In finally\n" );  
    }  
}  
void trans_func( unsigned int u, EXCEPTION_POINTERS* pExp )  
{  
    printf( "In trans_func.\n" );  
    throw SE_Exception();  
}  
```  
  
```Output  
In trans_func.  
In finally  
Caught a __try exception with SE_Exception.  
```  
  
## <a name="example"></a>Exemplo  
 Embora a funcionalidade fornecida pelo `_set_se_translator` não esteja disponível em código gerenciado, é possível usar esse mapeamento em código nativo, mesmo que o código nativo esteja em uma compilação no comutador `/clr`, desde que o código nativo seja indicado usando `#pragma unmanaged`. Se uma exceção estruturada está sendo lançada em código gerenciado que deve ser mapeado, o código que gera e manipula a exceção deve ser marcado com o `pragma`. O código a seguir mostra um uso possível. Para obter mais informações, consulte [Diretivas Pragma e a palavra-chave __Pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md).  
  
```  
// crt_set_se_translator_clr.cpp  
// compile with: /clr  
#include <windows.h>  
#include <eh.h>  
#include <assert.h>  
#include <stdio.h>  
  
int thrower_func(int i) {  
   int j = i/0;  
  return 0;  
}  
  
class CMyException{  
};  
  
#pragma unmanaged  
void my_trans_func(unsigned int u, PEXCEPTION_POINTERS pExp )  
{  
printf("Translating the structured exception to a C++"  
             " exception.\n");  
throw CMyException();  
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
  
int main(int argc, char** argv) {  
    _set_se_translator(my_trans_func);  
    DoTest();  
    return 0;  
}  
```  
  
```Output  
Translating the structured exception to a C++ exception.  
Caught CMyException.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)   
 [set_terminate](../../c-runtime-library/reference/set-terminate-crt.md)   
 [set_unexpected](../../c-runtime-library/reference/set-unexpected-crt.md)   
 [terminate](../../c-runtime-library/reference/terminate-crt.md)   
 [unexpected](../../c-runtime-library/reference/unexpected-crt.md)
