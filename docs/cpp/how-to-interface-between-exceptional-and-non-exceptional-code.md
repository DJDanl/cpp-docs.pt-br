---
title: 'Como: Interface entre códigos excepcional e não excepcional | Microsoft Docs'
ms.custom: how-to
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: fd5bb4af-5665-46a1-a321-614b48d4061e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f2cf2216ba75912520f744f0f0331a50520aa895
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="how-to-interface-between-exceptional-and-non-exceptional-code"></a>Como realizar a interface entre códigos excepcional e não excepcional
Este artigo descreve como implementar o tratamento de exceção consistente em um módulo de C++ e também como converter essas exceções em códigos de erro em limites de exceção.  
  
 Às vezes, um módulo de C++ tem a interface com o código que não use exceções (código não excepcional). Tal interface é conhecido como um *limite de exceção*. Por exemplo, você talvez queira chamar a função Win32 `CreateFile` no seu programa C++. `CreateFile` não gerar exceções; em vez disso, ele define os códigos de erro que podem ser recuperados pelo `GetLastError` função. Se seu programa C++ não trivial, em seguida, nele provavelmente preferir tem uma política de tratamento de erros com base em exceção consistente. E você provavelmente não deseja abandonar exceções apenas porque a interface com código não excepcional e não deseja mesclar políticas com base em exceção e não no exceção Erro em seu módulo C++.  
  
## <a name="calling-non-exceptional-functions-from-c"></a>Chamando funções não excepcional de C++  
 Quando você chama uma função não excepcional de C++, a ideia é encapsular essa função em uma função C++ que detecta erros e, em seguida, possivelmente lançará uma exceção. Quando você cria uma função de wrapper, primeiro decida que tipo de garantia de exceção para fornecer: não-throw, forte ou básica. Em seguida, crie a função para que todos os recursos, por exemplo, os identificadores de arquivos, são lançados corretamente se uma exceção for lançada. Normalmente, isso significa que você use ponteiros inteligentes ou gerenciadores de recursos semelhantes possua os recursos. Para obter mais informações sobre considerações de design, consulte [como: Design para segurança de exceção](../cpp/how-to-design-for-exception-safety.md).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra as funções de C++ que usam o Win32 `CreateFile` e `ReadFile` funções internamente para abrir e ler os dois arquivos.  O `File` classe é uma aquisição de recursos é o wrapper de inicialização (RAII) para os identificadores de arquivos. Detecta uma condição de "arquivo não encontrado" de seu construtor e lançará uma exceção para propagar o erro a pilha de chamadas do módulo C++ (neste exemplo, o `main()` função). Se uma exceção for lançada após um `File` objeto totalmente é construído, o destrutor chama automaticamente `CloseHandle` para liberar o identificador de arquivo. (Se você preferir, você pode usar a biblioteca de modelo ativa (ATL) `CHandle` classe para essa finalidade, o mesmo ou um `unique_ptr` junto com um deleter personalizado.) As funções que chamam Win32 e APIs de CRT detectar erros e, em seguida, gerar exceções de C++ usando o definidos localmente `ThrowLastErrorIf` função, que por sua vez utiliza o `Win32Exception` classe derivada o `runtime_error` classe. Todas as funções neste exemplo fornecem uma garantia de exceção forte; Se uma exceção será lançada em qualquer ponto essas funções, nenhum recurso seja perdido, e nenhum estado do programa é modificado.  
  
```cpp  
// compile with: /EHsc  
#include <Windows.h>  
#include <stdlib.h>  
#include <vector>  
#include <iostream>  
#include <string>  
#include <limits>  
#include <stdexcept>  
  
using namespace std;  
  
string FormatErrorMessage(DWORD error, const string& msg)  
{  
    static const int BUFFERLENGTH = 1024;  
    vector<char> buf(BUFFERLENGTH);  
    FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, 0, error, 0, buf.data(),   
        BUFFERLENGTH - 1, 0);   
    return string(buf.data()) + "   ("  + msg  + ")";  
}  
  
class Win32Exception : public runtime_error  
{      
private:  
    DWORD m_error;  
public:  
    Win32Exception(DWORD error, const string& msg)  
        : runtime_error(FormatErrorMessage(error, msg)), m_error(error) { }  
  
    DWORD GetErrorCode() const { return m_error; }  
};  
  
void ThrowLastErrorIf(bool expression, const string& msg)   
{   
    if (expression) {   
        throw Win32Exception(GetLastError(), msg);   
    }   
}   
  
class File  
{  
private:  
    HANDLE m_handle;  
  
    // Declared but not defined, to avoid double closing.  
    File& operator=(const File&);  
    File(const File&);  
public:  
    explicit File(const string& filename)   
    {  
        m_handle = CreateFileA(filename.c_str(), GENERIC_READ, FILE_SHARE_READ,   
            nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, nullptr);  
        ThrowLastErrorIf(m_handle == INVALID_HANDLE_VALUE,   
            "CreateFile call failed on file named " + filename);  
    }  
  
    ~File() { CloseHandle(m_handle); }  
  
    HANDLE GetHandle() { return m_handle; }  
};  
  
size_t GetFileSizeSafe(const string& filename)  
{  
    File fobj(filename);  
    LARGE_INTEGER filesize;  
  
    BOOL result = GetFileSizeEx(fobj.GetHandle(), &filesize);  
    ThrowLastErrorIf(result == FALSE, "GetFileSizeEx failed: " + filename);  
  
    if (filesize.QuadPart < (numeric_limits<size_t>::max)()) {  
        return filesize.QuadPart;  
    } else {  
        throw;   
    }  
}  
  
vector<char> ReadFileVector(const string& filename)  
{  
    File fobj(filename);  
    size_t filesize = GetFileSizeSafe(filename);  
    DWORD bytesRead = 0;  
  
    vector<char> readbuffer(filesize);  
  
    BOOL result = ReadFile(fobj.GetHandle(), readbuffer.data(), readbuffer.size(),   
        &bytesRead, nullptr);  
    ThrowLastErrorIf(result == FALSE, "ReadFile failed: " + filename);  
  
    cout << filename << " file size: " << filesize << ", bytesRead: "   
        << bytesRead << endl;  
  
    return readbuffer;  
}  
  
bool IsFileDiff(const string& filename1, const string& filename2)   
{  
    return ReadFileVector(filename1) != ReadFileVector(filename2);  
}   
  
#include <iomanip>  
  
int main ( int argc, char* argv[] )  
{  
    string filename1("file1.txt");  
    string filename2("file2.txt");  
  
    try  
    {  
        if(argc > 2) {  
            filename1 = argv[1];  
            filename2 = argv[2];  
        }   
  
        cout << "Using file names " << filename1 << " and " << filename2 << endl;  
  
        if (IsFileDiff(filename1, filename2)) {  
            cout << "*** Files are different." << endl;  
        } else {  
            cout<< "*** Files match." << endl;  
        }  
    }  
    catch(const Win32Exception& e)  
    {          
        ios state(nullptr);  
        state.copyfmt(cout);  
        cout << e.what() << endl;  
        cout << "Error code: 0x" << hex << uppercase << setw(8) << setfill('0')   
            << e.GetErrorCode() << endl;  
        cout.copyfmt(state); // restore previous formatting  
    }  
}  
  
```  
  
## <a name="calling-exceptional-code-from-non-exceptional-code"></a>Chamando código excepcional de código não excepcional  
 Funções C++ que são declaradas como "extern do C" pode ser chamado por programas C. Servidores COM C++ podem ser consumidos pelo código escrito em qualquer um dos vários idiomas diferentes. Quando você implementa funções de reconhecimento de exceção públicas em C++ a ser chamado pelo código não excepcional, a função C++ não deve permitir todas as exceções sejam propagadas de volta para o chamador. Portanto, a função C++ especificamente deve capturar todas as exceções que ele sabe como tratar e, se apropriado, converta a exceção a um código de erro que entende o chamador. Se nem todas as exceções potenciais são conhecidas, a função C++ deve ter um `catch(...)` bloco como o último manipulador. Nesse caso, é melhor relatar um erro fatal ao chamador, porque seu programa pode estar em um estado desconhecido.  
  
 O exemplo a seguir mostra uma função que pressupõe que qualquer exceção que pode ser gerada é um Win32Exception ou um tipo de exceção derivado de `std::exception`. A função de captura qualquer exceção desses tipos e propaga as informações de erro como um código de erro do Win32 para o chamador.  
  
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
  
 Quando você converter de exceções para códigos de erro, um possível problema é que os códigos de erro geralmente não contêm a riqueza de informações que pode armazenar uma exceção. Para resolver isso, você pode fornecer um `catch` bloco para cada tipo de exceção específico que pode ser gerado e executar o registro em log para registrar os detalhes da exceção antes de ser convertido para um código de erro. Essa abordagem pode criar um lote de repetição de código se todas as várias funções, usem o mesmo conjunto de `catch` blocos. É uma boa maneira de evitar a repetição de código pela refatoração os blocos em uma função de utilitário privada que implementa o `try` e `catch` bloqueia e aceita um objeto de função que é chamado o `try` bloco. Cada função pública, passe o código para a função de utilitário como uma expressão lambda.  
  
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
  
 O exemplo a seguir mostra como escrever a expressão lambda que define o functor. Quando um functor é definido "inline" usando uma expressão lambda, geralmente é mais fácil de ler do que seria se tivesse sido escrito como um objeto de função nomeada.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Erros e tratamento de exceção](../cpp/errors-and-exception-handling-modern-cpp.md)   
 [Como projetar tendo em vista a segurança de exceção](../cpp/how-to-design-for-exception-safety.md)