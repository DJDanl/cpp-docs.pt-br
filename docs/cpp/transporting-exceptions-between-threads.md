---
title: "Transportando exceções entre Threads | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- std::current_exception
- transporting exceptions between threads
- std::copy_exception
- exception_ptr
- std::exception_ptr
- std::rethrow_exception
- current_exception
- transport exceptions between threads
- copy_exception
- rethrow_exception
- move exceptions between threads
ms.assetid: 5c95d57b-acf5-491f-8122-57c5df0edd98
caps.latest.revision: "24"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 1ccbda062d28cdbdaafcbae68793b6583f31a3be
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="transporting-exceptions-between-threads"></a>Transportando exceções entre threads
Visual C++ dá suporte a *transportar uma exceção* de um thread para outro. O transporte de exceções permite que você capture uma exceção em um thread e faça parecer que ela tenha sido lançada em outro thread. Você pode usar esse recurso, por exemplo, para gravar um aplicativo multi-threaded em que o thread primário trata todas as exceções lançadas por seus threads secundários. O transporte de exceções é útil para a maioria dos desenvolvedores que cria bibliotecas ou sistemas de programação paralela. Para implementar transportar exceções, Visual C++ fornece o [exception_ptr](../standard-library/exception-typedefs.md#exception_ptr) tipo e o [current_exception](../standard-library/exception-functions.md#current_exception), [rethrow_exception](../standard-library/exception-functions.md#rethrow_exception), e [make_ exception_ptr](../standard-library/exception-functions.md#make_exception_ptr) funções.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace std   
{  
   typedef unspecified exception_ptr;   
   exception_ptr current_exception();  
   void rethrow_exception(exception_ptr p);  
   template<class E>   
       exception_ptr make_exception_ptr(E e) noexcept;  
}  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`unspecified`|Uma classe interna não especificada que é usada para implementar o tipo `exception_ptr`.|  
|`p`|Um objeto `exception_ptr` que faz referência a uma exceção.|  
|`E`|Uma classe que representa uma exceção.|  
|`e`|Uma instância da classe `E` do parâmetro.|  
  
## <a name="return-value"></a>Valor de retorno  
 A função `current_exception` retorna um objeto `exception_ptr` que faz referência à exceção que está atualmente em andamento. Se nenhuma exceção estiver em andamento, a função retornará um objeto `exception_ptr` que não esteja associado a nenhuma exceção.  
  
 A função `make_exception_ptr` retorna um objeto `exception_ptr` que faz referência à exceção especificada pelo parâmetro `e`.  
  
## <a name="remarks"></a>Comentários  
  
## <a name="scenario"></a>Cenário  
 Imagine que você deseja criar um aplicativo que possa ser dimensionado para lidar com uma quantidade variável de trabalho. Para atingir esse objetivo, você projeta um aplicativo multi-threaded em que um thread primário inicial cria o número de threads secundários necessários para que o trabalho possa ser realizado. Os threads secundários ajudam o thread primário a gerenciar recursos, balancear as cargas e aprimorar o rendimento. Ao distribuir o trabalho, o aplicativo multi-threaded apresenta melhor desempenho do que um aplicativo single-threaded.  
  
 No entanto, se um thread secundário lançar uma exceção, você quer que o thread primário trate dela. Isso porque você deseja que o aplicativo trate das exceções de maneira consistente e unificada, independentemente do número de threads secundários.  
  
## <a name="solution"></a>Solução  
 Para atender ao objetivo do cenário anterior, o C++ Standard oferece suporte ao transporte de uma exceção entre threads. Se um thread secundário lança uma exceção, essa exceção se torna o *exceção atual*. Por analogia para o mundo real, a exceção atual será considerada *em trânsito*. A exceção atual estará em voo do momento em que é lançada até o momento em que o manipulador de exceção que a captura retorne.  
  
 O thread secundário pode capturar a exceção atual em um bloco `catch` e chamar a função `current_exception` para armazenar a exceção em um objeto `exception_ptr`. O objeto `exception_ptr` deve estar disponível para o thread secundário e o thread primário. Por exemplo, o objeto `exception_ptr` pode ser uma variável global cujo acesso é controlado por um mutex. O termo *uma exceção de transporte* significa que uma exceção em um thread pode ser convertida em um formulário que pode ser acessado por outro thread.  
  
 Em seguida, o thread primário chama a função `rethrow_exception`, que o extrai e lança a exceção do objeto `exception_ptr`. Quando a exceção é lançada, ela se torna a exceção atual no thread primário. Isto é, ela parece se originar no thread primário.  
  
 Por fim, o thread primário pode capturar a exceção atual em um bloco `catch` e processá-la ou lançá-la em um manipulador de exceção de nível mais alto. Ou, o thread primário pode ignorar a exceção e permitir que o processo seja encerrado.  
  
 A maioria dos aplicativos não precisa transportar exceções entre os threads. No entanto, esse recurso é útil em um sistema de computação paralela, pois o sistema pode dividir o trabalho entre os threads secundários, processadores ou núcleos. Em um ambiente de computação paralela, um thread único e dedicado pode tratar todas as exceções dos threads secundários, além de poder apresentar um modelo de tratamento de exceções consistente para qualquer aplicativo.  
  
 Para obter mais informações sobre a proposta da comissão do C++ Standard, procure na Internet pelo número de documento N2179, denominado "Language Support for Transporting Exceptions between Threads".  
  
## <a name="exception-handling-models-and-compiler-options"></a>Opções de compilador e modelos de tratamento de exceções  
 O modelo de tratamento de exceções do seu aplicativo determina se ele pode capturar e transportar uma exceção. O Visual C++ oferece suporte a três modelos que podem tratar de exceções do C++, exceções SEH (tratamento de exceções estruturadas) e exceções CLR (common language runtime). Use o [/EH](../build/reference/eh-exception-handling-model.md) e [/clr](../build/reference/clr-common-language-runtime-compilation.md) opções do compilador para especificar o modelo de tratamento de exceção do aplicativo.  
  
 Somente as opções de combinação de compiladores e as instruções de programação a seguir podem transportar uma exceção. Outras combinações, ou não podem capturar exceções, ou podem capturá-las, mas não podem transportá-las.  
  
-   O **/EHa** opção de compilador e o `catch` instrução pode transportar exceções SEH e C++.  
  
-   O **/EHa**, **/EHs**, e **/EHsc** opções do compilador e o `catch` instrução pode transportar exceções do C++.  
  
-   O **/CLR** ou **/CLR: pure** opção de compilador e o `catch` instrução pode transportar exceções do C++. O **/CLR** opções do compilador implicam a especificação da **/EHa** opção. Observe que o compilador não oferece suporte ao transporte de exceções gerenciadas. Isso ocorre porque gerenciados exceções, que são derivadas do [classe System. Exception](../standard-library/exception-class.md), já são objetos que podem ser movidos entre threads, usando os recursos de tempo de execução languange comuns.  
  
    > [!IMPORTANT]
    >  Recomendamos que você especifique o **/EHsc** opção de compilador e captura somente exceções do C++. Você se expõe a ameaças de segurança se você usar o **/EHa** ou **/CLR** opção de compilador e uma **catch** instrução com reticências  *declaração de exceção* (`catch(...)`). Provavelmente, você pretende usar a instrução `catch` para capturar algumas exceções específicas. No entanto, a instrução `catch(...)` captura todas as exceções C++ e SEH, incluindo as inesperadas que devem fatais. Se você ignorar ou tratar incorretamente uma exceção inesperada, o código mal-intencionado poderá aproveitar essa oportunidade para destruir a segurança do seu programa.  
  
## <a name="usage"></a>Uso  
 As seções a seguir descrevem como transporte exceções usando o `exception_ptr` tipo e o `current_exception`, `rethrow_exception`, e `make_exception_ptr` funções.  
  
### <a name="exceptionptr-type"></a>Tipo exception_ptr  
 Use um objeto `exception_ptr` para fazer referência à exceção atual ou a uma instância de uma exceção especificada pelo usuário. Na implementação da Microsoft, uma exceção é representada por uma estrutura [EXCEPTION_RECORD](http://msdn.microsoft.com/library/windows/desktop/aa363082). Cada objeto `exception_ptr` inclui um campo de referência de exceção que aponta para uma cópia da estrutura `EXCEPTION_RECORD` que representa a exceção.  
  
 Quando você declara uma variável `exception_ptr`, ela não é associada a nenhuma exceção. Isto é, o campo de referência de exceção é NULL. Esse objeto `exception_ptr` é chamado de *null exception_ptr*.  
  
 Use a função `current_exception` ou `make_exception_ptr` para atribuir uma exceção a um objeto `exception_ptr`. Quando você atribui uma exceção a uma variável `exception_ptr`, o campo de referência de exceção da variável aponta para uma cópia da exceção. Se não houver memória suficiente para copiar a exceção, o campo de referência de exceção apontará para uma cópia de uma exceção [std::bad_alloc](../standard-library/bad-alloc-class.md). Se o `current_exception` ou `make_exception_ptr` função não é possível copiar a exceção para qualquer outro motivo, a função chama o [encerrar](../c-runtime-library/reference/terminate-crt.md) função para sair do processo atual.  
  
 Apesar do nome, um objeto `exception_ptr` não é, em si, um ponteiro. Ele não obedece à semântica do ponteiro e não pode ser usado com o acesso do membro do ponteiro (`->`) ou operadores (*) de indireção. O objeto `exception_ptr` não tem membros de dados públicos ou funções de membro.  
  
 **Comparações:**  
  
 Você pode usar os operadores igual (`==`) e diferente (`!=`) para comparar dois objetos `exception_ptr`. Os operadores não comparam o valor binário (padrão de bit) das estruturas `EXCEPTION_RECORD` que representam as exceções. Em vez disso, os operadores comparam os endereços no campo de referência de exceção dos objetos `exception_ptr`. Consequentemente, um `exception_ptr` nulo e o valor NULL são comparados como iguais.  
  
### <a name="currentexception-function"></a>Função current_exception  
 Chame a função `current_exception` em um bloco `catch`. Se uma exceção estiver em voo e o bloco `catch` puder capturar a exceção, a função `current_exception` retornará um objeto `exception_ptr` que faz referência à exceção. Caso contrário, a função retornará um objeto `exception_ptr` nulo.  
  
 **Detalhes:**  
  
 A função `current_exception` captura a exceção que está em voo, independentemente de a instrução `catch` especificar uma instrução [exception-declaration](../cpp/try-throw-and-catch-statements-cpp.md).  
  
 O destruidor da exceção atual será chamado no fim do bloco `catch` se você não puder relançar a exceção. No entanto, mesmo que você chame a função `current_exception` no destruidor, a função retornará um objeto `exception_ptr` que faz referência à exceção atual.  
  
 As chamadas sucessivas à função `current_exception` retornam objetos `exception_ptr` que se referem a diferentes cópias da exceção atual. Consequentemente, os objetos são comparados como diferentes, pois se referem a diferentes cópias, mesmo quando as cópias têm o mesmo valor binário.  
  
 **Exceções de SEH:**  
  
 Se você usar o **/EHa** opção de compilador, você pode capturar uma exceção SEH em um C++ `catch` bloco. A função `current_exception` retorna um objeto `exception_ptr` que faz referência à exceção SEH. E o `rethrow_exception` função lança a exceção SEH chamá-lo com thetransported `exception_ptr` objeto como seu argumento.  
  
 A função `current_exception` retornará um `exception_ptr` nulo se você o chamar em um manipulador de encerramento `__finally`, um manipulador de exceções `__except` ou a expressão de filtro `__except` do SEH.  
  
 Uma exceção transportada não oferece suporte a exceções aninhadas. Uma exceção aninhada ocorrerá se outra exceção for lançada enquanto uma exceção estiver sendo tratada. Se você capturar uma exceção aninhada, o membro de dados `EXCEPTION_RECORD.ExceptionRecord` apontará para uma cadeia de estruturas `EXCEPTION_RECORD` que descreve as exceções associadas. A função `current_exception` não oferece suporte a exceções aninhadas, pois ela retorna um objeto `exception_ptr` cujo membro de dados `ExceptionRecord` é zerado.  
  
 Se você capturar uma exceção SEH, será preciso gerenciar a memória referenciada por qualquer ponteiro na matriz de membros de dados `EXCEPTION_RECORD.ExceptionInformation`. É preciso garantir que a memória seja válida durante o tempo de vida do objeto `exception_ptr` correspondente e que seja alimentada quando o objeto `exception_ptr` for excluído.  
  
 É possível usar funções de conversão de SE (exceção estruturada) juntamente com o recurso de transporte de exceções. Se uma exceção SEH for convertida em uma exceção C++, a função `current_exception` retornará um `exception_ptr` que fará referência à exceção convertida, e não à exceção SEH original. A função `rethrow_exception` lança subsequentemente a exceção convertida, não a exceção original. Para obter mais informações sobre as funções SE conversor, consulte [set_se_translator](../c-runtime-library/reference/set-se-translator.md).  
  
### <a name="rethrowexception-function"></a>Função rethrow_exception  
 Depois de armazenar uma exceção capturada em um objeto `exception_ptr`, o thread primário poderá processar o objeto. Em seu thread primário, chame a função `rethrow_exception` juntamente com o objeto `exception_ptr` como seu argumento. A função `rethrow_exception` extrai a exceção do objeto `exception_ptr` e a lança no contexto do thread primário. Se o `p` parâmetro o `rethrow_exception` função é um valor nulo `exception_ptr`, a função gera [std::bad_exception](../standard-library/bad-exception-class.md).  
  
 A exceção extraída agora é a exceção atual no thread primário, e você pode tratá-la como faria com qualquer outra exceção. Se você capturar a exceção, será possível tratá-la imediatamente ou usar uma instrução `throw` para enviá-la a um manipulador de exceção de nível mais alto. Caso contrário, não faça nada e deixe o manipulador padrão de exceção do sistema encerrar o processo.  
  
### <a name="makeexceptionptr-function"></a>Função make_exception_ptr  
 A função `make_exception_ptr` usa uma instância de uma classe como seu argumento e retorna um `exception_ptr` que faz referência à instância. Normalmente, você especifica um objeto de [classe de exceção](../standard-library/exception-class.md) como o argumento para a função `make_exception_ptr`, embora qualquer objeto de classe possa ser o argumento.  
  
 Chamar a função `make_exception_ptr` é equivalente a lançar uma exceção C++, capturá-la em um bloco `catch` e chamar a função `current_exception` para retornar um objeto `exception_ptr` que faça referência à exceção. A implementação da função `make_exception_ptr` da Microsoft é mais eficiente do que lançar e depois capturar uma exceção.  
  
 Geralmente, um aplicativo não exige a função `make_exception_ptr` e não recomendamos seu uso.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir transporta uma exceção padrão C++ e uma exceção C++ personalizada de um thread para outro.  
  
```  
// transport_exception.cpp  
// compile with: /EHsc /MD  
#include <windows.h>  
#include <stdio.h>   
#include <exception>  
#include <stdexcept>  
  
using namespace std;  
  
// Define thread-specific information.  
#define THREADCOUNT 2  
exception_ptr aException[THREADCOUNT];   
int           aArg[THREADCOUNT];  
  
DWORD WINAPI ThrowExceptions( LPVOID );   
  
// Specify a user-defined, custom exception.   
// As a best practice, derive your exception   
// directly or indirectly from std::exception.   
class myException : public std::exception {   
};  
int main()  
{  
    HANDLE aThread[THREADCOUNT];  
    DWORD ThreadID;  
  
    // Create secondary threads.  
    for( int i=0; i < THREADCOUNT; i++ )  
    {  
        aArg[i] = i;  
        aThread[i] = CreateThread(   
            NULL,       // Default security attributes.  
            0,          // Default stack size.  
            (LPTHREAD_START_ROUTINE) ThrowExceptions,   
            (LPVOID) &aArg[i], // Thread function argument.  
            0,          // Default creation flags.  
            &ThreadID); // Receives thread identifier.  
        if( aThread[i] == NULL )  
        {  
            printf("CreateThread error: %d\n", GetLastError());  
            return -1;  
        }  
    }   
  
    // Wait for all threads to terminate.  
    WaitForMultipleObjects(THREADCOUNT, aThread, TRUE, INFINITE);   
    // Close thread handles.  
    for( int i=0; i < THREADCOUNT; i++ ) {  
        CloseHandle(aThread[i]);   
    }  
  
    // Rethrow and catch the transported exceptions.  
    for ( int i = 0; i < THREADCOUNT; i++ ) {  
        try {  
            if (aException[i] == NULL) {  
                printf("exception_ptr %d: No exception was transported.\n", i);  
            }  
            else {  
                rethrow_exception( aException[i] );  
            }    
        }  
        catch( const invalid_argument & ) {  
            printf("exception_ptr %d: Caught an invalid_argument exception.\n", i);  
        }  
        catch( const myException & ) {  
            printf("exception_ptr %d: Caught a  myException exception.\n", i);  
        }  
    }  
}   
// Each thread throws an exception depending on its thread   
// function argument, and then ends.   
DWORD WINAPI ThrowExceptions( LPVOID lpParam )   
{   
    int x = *((int*)lpParam);  
    if (x == 0) {  
        try {  
            // Standard C++ exception.  
            // This example explicitly throws invalid_argument exception.   
            // In practice, your application performs an operation that   
            // implicitly throws an exception.  
            throw invalid_argument("A C++ exception.");  
        }    
        catch ( const invalid_argument & ) {   
            aException[x] = current_exception();  
        }   
    }  
    else {  
        // User-defined exception.  
        aException[x] = make_exception_ptr( myException() );   
    }  
    return TRUE;   
}  
```  
  
```Output  
exception_ptr 0: Caught an invalid_argument exception.  
exception_ptr 1: Caught a  myException exception.  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<exception>  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções](../cpp/exception-handling-in-visual-cpp.md)     
 [/EH (modelo de tratamento de exceções)](../build/reference/eh-exception-handling-model.md)   
 [/CLR (common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md)