---
title: "_set_se_translator | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_set_se_translator"
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
apitype: "DLLExport"
f1_keywords: 
  - "_set_se_translator"
  - "set_se_translator"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _set_se_translator"
  - "tratamento de exceção, alterando"
  - "Função set_se_translator"
ms.assetid: 280842bc-d72a-468b-a565-2d3db893ae0f
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _set_se_translator
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As exceções do Win32 de identificadores \(exceções estruturado de 2.0 C\) como C\+\+ digitaram exceções.  
  
## Sintaxe  
  
```  
_se_translator_function _set_se_translator(  
   _se_translator_function seTransFunction  
);  
```  
  
#### Parâmetros  
 `seTransFunction`  
 Ponteiro para a função é estruturada c de tradutor de exceção que você criou.  
  
## Valor de retorno  
 Retorna um ponteiro para a função anterior de tradutor registrada por `_set_se_translator`, de forma que a função anterior pode ser restaurados posteriormente.  Se nenhuma função anterior foi definida, o valor de retorno pode ser usado para restaurar o comportamento padrão; esse valor pode ser NULL.  
  
## Comentários  
 A função de `_set_se_translator` fornece uma maneira de tratar exceções do Win32 \(exceções estruturado de 2.0 C\) como exceções digitadas C\+\+.  Para permitir que cada um uma exceção C seja tratada pelo manipulador c criando `catch` , primeiro defina a classe de invólucro de exceção de c que pode ser usado, ou derivada, para atribuir um tipo específico da classe com exceção de c.  Para usar essa classe, instale uma função personalizada de tradutor da exceção de 2.0 C que é chamado pela exceção interna c do mecanismo de manipulação de exceções gerais será emitido cada vez.  Dentro da função de tradutor, você pode gerar qualquer exceção com tipo que possa ser capturada por um manipulador de correspondência C\+\+ `catch` .  
  
 Você deve usar [\/EHa](../../build/reference/eh-exception-handling-model.md) ao usar `_set_se_translator`.  
  
 Para especificar uma função personalizada de tradução, chame `_set_se_translator` com o nome da função de conversão como seu argumento.  A função de tradutor que você gravação é chamado uma vez para cada invocação de função na pilha que tem blocos de `try` .  Não há nenhuma função padrão de tradutor.  
  
 A função de tradutor deve fazer não mais do que gerou a exceção digitada c. criando  Se faz nada além do kit \(como gravar um arquivo de log, por exemplo\) seu programa não podem se comportar como esperado, como o número de vezes que a função de tradutor é chamada é dependente de plataforma.  
  
 Em um ambiente multithread, as funções de tradutor são mantidas separadamente para cada thread.  Necessidades de cada thread de instalar novos sua própria função de tradutor.  Assim, cada thread é responsável de sua própria manipulação de tradução para o.  `_set_se_translator` é específico a um thread; outro DLL pode instalar uma função diferente da conversão.  
  
 A função de `seTransFunction` que você gravação deve ser uma função compilada nativo \(não criada com \/clr\).  Deve ser um número inteiro sem sinal e um ponteiro para uma estrutura do Win32 `_EXCEPTION_POINTERS` como argumentos.  Os argumentos são os valores de retorno de chamadas à API do Win32 `GetExceptionCode` e funções de `GetExceptionInformation` , respectivamente.  
  
```  
typedef void (*_se_translator_function)(unsigned int, struct _EXCEPTION_POINTERS* );  
```  
  
 Para `_set_se_translator`, as implicações dinamicamente ao vincular a CRT; outro DLL do processo pode chamar `_set_se_translator` e substituir o manipulador com seus próprios.  
  
 Ao usar `_set_se_translator` de código gerenciado \(código compilado com \/clr\) ou nativo misto e código gerenciado, lembre\-se de que o tradutor afeta as exceções geradas em código nativo.  Nenhuma exceções gerenciado gerada no código gerenciado \(como aumentar `System::Exception`\) não são roteadas através da função de tradutor.  As exceções geradas em código gerenciado usando a função `RaiseException` do Win32 ou causadas por uma exceção do sistema como uma exceção divisão por zero são roteadas através de tradutor.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_set_se_translator`|\<eh.h\>|  
  
 A funcionalidade fornecida por `_set_se_translator` não está disponível no código compilado com a opção do compilador de [\/clr: puro](../../build/reference/clr-common-language-runtime-compilation.md) .  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
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
  
  **No trans\_func.**  
**Em finalmente**  
**Capturar uma exceção \_\_try com SE\_Exception.**   
## Exemplo  
 Embora a funcionalidade fornecida por `_set_se_translator` não está disponível no código gerenciado, é possível usar esse mapeamento em código nativo, mesmo se esse código nativo está em uma compilação na opção de `/clr` , contanto que o código nativo é indicado usando `#pragma unmanaged`.  Se uma exceção estruturado está sendo gerada em código gerenciado que deve ser mapeado, o código que gerencia e os identificadores a exceção devem ser marcados com `pragma`.  O código a seguir mostra um uso possível.  Para obter mais informações, consulte [Diretivas Pragma e a palavra\-chave \_\_Pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md).  
  
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
  
  **Traduzindo a exceção estruturado com exceção de c. criando**  
**CMyException capturado.**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas do tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)   
 [set\_terminate](../../c-runtime-library/reference/set-terminate-crt.md)   
 [set\_unexpected](../../c-runtime-library/reference/set-unexpected-crt.md)   
 [terminate](../../c-runtime-library/reference/terminate-crt.md)   
 [unexpected](../Topic/unexpected%20\(CRT\).md)