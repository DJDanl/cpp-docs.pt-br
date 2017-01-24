---
title: "Como realizar a interface entre c&#243;digos excepcional e n&#227;o excepcional | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: fd5bb4af-5665-46a1-a321-614b48d4061e
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar a interface entre c&#243;digos excepcional e n&#227;o excepcional
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve como implementar o tratamento de exceções consistente em um módulo do C\+\+ e também como converter bidirecionalmente essas exceções em códigos de erro nos limites da exceção.  
  
 Às vezes, o módulo C\+\+ tem que fazer interface com um código que não usam exceções \(código não excepcional\).  Tal interface é conhecida como um *limite de exceção*.  Por exemplo, você pode chamar a função `CreateFile` Win32 em seu programa de C\+\+.  `CreateFile` não lança exceções; em vez disso, define os códigos de erro que podem ser recuperados pela função de `GetLastError`.  Se seu programa de C\+\+ não for trivial, você provavelmente irá preferir ter uma política de tratamento de erros consistente baseada em exceções.  Provavelmente, você não quer abandonar as exceções só porque interage com código não excepcional, e nem quer misturar as políticas de erros baseadas em exceção e baseadas em não\-exceção no módulo de C\+\+.  
  
## Chamando funções não excepcionais de C\+\+  
 Quando você chama uma função não excepcional de C\+\+, a ideia é envolver essa função em uma função de C\+\+ que detecta todos os erros e, então, possivelmente gerar uma exceção.  Quando você cria uma função wrapper, primeiro decida qual tipo de garantia de exceção será fornecida: no\-throw, strong ou basic.  Em seguida, crie a função de modo que todos os recursos, por exemplo, identificadores de arquivo, sejam liberados corretamente se uma exceção for gerada.  Normalmente, isso significa que você usa ponteiros inteligentes ou gerentes de recurso semelhantes para os próprios recursos.  Para obter mais informações sobre considerações de design, consulte [Como projetar tendo em vista a segurança da exceção](../cpp/how-to-design-for-exception-safety.md).  
  
### Exemplo  
 O exemplo a seguir mostra as funções C\+\+ que usam as funções Win32 `CreateFile` e `ReadFile` internamente para abrir e ler dois arquivos.  A classe `File` é um wrapper RAII \(Aquisição de Recurso É Inicialização\) para os identificadores de arquivo.  O construtor detecta de uma condição de “arquivo não encontrado” e gera uma exceção para propagar o erro até a pilha de chamadas do módulo de C\+\+ \(neste exemplo, a função de `main()`\).  Se uma exceção for lançada após um objeto de `File` ser construído totalmente, o destrutor automaticamente chama `CloseHandle` para liberar o manipulador de arquivo. \(Se preferir, você pode usar a classe de `CHandle` do Active Template Library \(ATL\), para essa mesma finalidade, ou um `unique_ptr` junto com um deletor personalizado.\) As funções que chamam o Win32 e as APIs de CRT detectam erros e geram exceções C\+\+ usando a função `ThrowLastErrorIf` definida localmente, que por sua vez usa a classe `Win32Exception` derivada da classe `runtime_error`.  Todas as funções nesse exemplo fornecem uma forte garantia de exceção; se uma exceção for lançada em algum momento nessas funções, nenhum recurso será liberado e nenhum estado de programa será alterado.  
  
```cpp  
// compile with: /EHsc  
#include <Windows.h>  
#include <stdlib.h>  
#include <vector>  
#include <iostream>  
#include <string>  
#include <limits>  
#include <stdexcept>  
  
using namespace std;  
  
string FormatErrorMessage(DWORD error, const string& msg)  
{  
    static const int BUFFERLENGTH = 1024;  
    vector<char> buf(BUFFERLENGTH);  
    FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, 0, error, 0, buf.data(),   
        BUFFERLENGTH - 1, 0);   
    return string(buf.data()) + "   ("  + msg  + ")";  
}  
  
class Win32Exception : public runtime_error  
{      
private:  
    DWORD m_error;  
public:  
    Win32Exception(DWORD error, const string& msg)  
        : runtime_error(FormatErrorMessage(error, msg)), m_error(error) { }  
  
    DWORD GetErrorCode() const { return m_error; }  
};  
  
void ThrowLastErrorIf(bool expression, const string& msg)   
{   
    if (expression) {   
        throw Win32Exception(GetLastError(), msg);   
    }   
}   
  
class File  
{  
private:  
    HANDLE m_handle;  
  
    // Declared but not defined, to avoid double closing.  
    File& operator=(const File&);  
    File(const File&);  
public:  
    explicit File(const string& filename)   
    {  
        m_handle = CreateFileA(filename.c_str(), GENERIC_READ, FILE_SHARE_READ,   
            nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, nullptr);  
        ThrowLastErrorIf(m_handle == INVALID_HANDLE_VALUE,   
            "CreateFile call failed on file named " + filename);  
    }  
  
    ~File() { CloseHandle(m_handle); }  
  
    HANDLE GetHandle() { return m_handle; }  
};  
  
size_t GetFileSizeSafe(const string& filename)  
{  
    File fobj(filename);  
    LARGE_INTEGER filesize;  
  
    BOOL result = GetFileSizeEx(fobj.GetHandle(), &filesize);  
    ThrowLastErrorIf(result == FALSE, "GetFileSizeEx failed: " + filename);  
  
    if (filesize.QuadPart < (numeric_limits<size_t>::max)()) {  
        return filesize.QuadPart;  
    } else {  
        throw;   
    }  
}  
  
vector<char> ReadFileVector(const string& filename)  
{  
    File fobj(filename);  
    size_t filesize = GetFileSizeSafe(filename);  
    DWORD bytesRead = 0;  
  
    vector<char> readbuffer(filesize);  
  
    BOOL result = ReadFile(fobj.GetHandle(), readbuffer.data(), readbuffer.size(),   
        &bytesRead, nullptr);  
    ThrowLastErrorIf(result == FALSE, "ReadFile failed: " + filename);  
  
    cout << filename << " file size: " << filesize << ", bytesRead: "   
        << bytesRead << endl;  
  
    return readbuffer;  
}  
  
bool IsFileDiff(const string& filename1, const string& filename2)   
{  
    return ReadFileVector(filename1) != ReadFileVector(filename2);  
}   
  
#include <iomanip>  
  
int main ( int argc, char* argv[] )  
{  
    string filename1("file1.txt");  
    string filename2("file2.txt");  
  
    try  
    {  
        if(argc > 2) {  
            filename1 = argv[1];  
            filename2 = argv[2];  
        }   
  
        cout << "Using file names " << filename1 << " and " << filename2 << endl;  
  
        if (IsFileDiff(filename1, filename2)) {  
            cout << "*** Files are different." << endl;  
        } else {  
            cout<< "*** Files match." << endl;  
        }  
    }  
    catch(const Win32Exception& e)  
    {          
        ios state(nullptr);  
        state.copyfmt(cout);  
        cout << e.what() << endl;  
        cout << "Error code: 0x" << hex << uppercase << setw(8) << setfill('0')   
            << e.GetErrorCode() << endl;  
        cout.copyfmt(state); // restore previous formatting  
    }  
}  
  
```  
  
## Chamando código excepcional de código não excepcional  
 As funções do C\+\+ declaradas como "extern C" podem ser chamadas por programas C.  Os servidores C\+\+ COM podem ser consumidos pelo código gravado em qualquer uma da série de diferentes idiomas.  Quando você implementa funções de exceção públicas em C\+\+ para serem chamadas pelo código não excepcional, a função de C\+\+ não deve permitir que qualquer exceção se propague novamente para o chamador.  Portanto, a função C\+\+ deve especificamente capturar cada exceção que ela sabe como manipular e, se apropriado, converter a exceção em um código de erro que o chamador entende.  Se nem todas as possíveis exceções forem conhecidas, a função de C\+\+ deve ter um bloco de `catch(…)` como manipulador mais recente.  Em tais casos, é melhor relatar um erro fatal ao chamador, porque seu programa pode estar em um estado desconhecido.  
  
 O exemplo a seguir mostra uma função que assume que qualquer exceção que possa ser gerada é uma Win32Exception ou um tipo de exceção derivado de `std::exception`.  A função captura qualquer exceção desses tipos e propaga as informações de erro como um código de erro do Win32 para o chamador.  
  
```cpp  
BOOL DiffFiles2(const string& file1, const string& file2)   
{   
    try   
    {   
        File f1(file1);   
        File f2(file2);   
        if (IsTextFileDiff(f1, f2))   
        {   
            SetLastError(MY_APPLICATION_ERROR_FILE_MISMATCH);   
            return FALSE;   
        }   
        return TRUE;   
    }   
    catch(Win32Exception& e)   
    {   
        SetLastError(e.GetErrorCode());   
    }  
  
    catch(std::exception& e)   
    {   
        SetLastError(MY_APPLICATION_GENERAL_ERROR);   
    }   
    return FALSE;   
}  
  
```  
  
 Quando você converte de exceções para códigos de erro, um problema em potencial é que os códigos de erro frequentemente não contêm a riqueza de informações que uma exceção pode armazenar.  Para resolver isso, você pode fornecer um bloco `catch` para cada tipo de exceção específico que pode ser lançado e executar o log para registrar os detalhes da exceção antes de ser convertido em um código de erro.  Essa abordagem poderá criar muitas repetições de código se várias funções usarem o mesmo conjunto de blocos `catch`.  Uma boa maneira para evitar a repetição de código é refatorar esses blocos em uma função particular de utilitário, que implementa os blocos de `try` e `catch` e aceita um objeto de função que é chamado no bloco de `try`.  Em cada função pública, passe o código para a função de utilitário como uma expressão lambda.  
  
```cpp  
template<typename Func>   
bool Win32ExceptionBoundary(Func&& f)   
{   
    try   
    {   
        return f();   
    }   
    catch(Win32Exception& e)   
    {   
        SetLastError(e.GetErrorCode());   
    }   
    catch(const std::exception& e)   
    {   
        SetLastError(MY_APPLICATION_GENERAL_ERROR);   
    }   
    return false;   
}  
  
```  
  
 O exemplo a seguir mostra como escrever a expressão lambda que define o functor.  Quando um funtor é definido como "embutido" usando uma expressão lambda, frequentemente é mais fácil ler do que se ele fosse gravado como um objeto chamado de função.  
  
```cpp  
bool DiffFiles3(const string& file1, const string& file2)   
{   
    return Win32ExceptionBoundary([&]() -> bool  
    {   
        File f1(file1);   
        File f2(file2);   
        if (IsTextFileDiff(f1, f2))   
        {   
            SetLastError(MY_APPLICATION_ERROR_FILE_MISMATCH);   
            return false;   
        }   
        return true;   
    });   
}  
  
```  
  
 Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../cpp/lambda-expressions-in-cpp.md).  
  
## Consulte também  
 [Erros e tratamento de exceções](../cpp/errors-and-exception-handling-modern-cpp.md)   
 [Como projetar tendo em vista a segurança da exceção](../cpp/how-to-design-for-exception-safety.md)