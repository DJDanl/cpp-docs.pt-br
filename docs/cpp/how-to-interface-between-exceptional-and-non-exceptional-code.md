---
title: Como realizar a interface entre códigos excepcional e não excepcional
ms.custom: how-to
ms.date: 11/04/2016
ms.topic: conceptual
ms.assetid: fd5bb4af-5665-46a1-a321-614b48d4061e
ms.openlocfilehash: b6da1142ee04668033a516f2c20c4a2354ff5598
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50576677"
---
# <a name="how-to-interface-between-exceptional-and-non-exceptional-code"></a>Como realizar a interface entre códigos excepcional e não excepcional

Este artigo descreve como implementar o tratamento de exceções consistente em um módulo de C++ e também como converter bidirecionalmente essas exceções em códigos de erro nos limites da exceção.

Às vezes, um módulo do C++ tem a interface com um código que não usa exceções (código não excepcional). Uma interface desse tipo é conhecida como um *limite de exceção*. Por exemplo, você talvez queira chamar a função Win32 `CreateFile` no seu programa C++. `CreateFile` não lança exceções; em vez disso, ele define os códigos de erro que podem ser recuperados pelo `GetLastError` função. Se seu programa de C++ é não trivial, em seguida, ele provavelmente preferir que a uma política de tratamento de erros consistente baseada em exceções. E você provavelmente não deseja abandonar as exceções só porque você interage com código não excepcional, e nenhum deles você deseja combinar políticas com base em exceção e não baseado em exceção de erro em seu módulo C++.

## <a name="calling-non-exceptional-functions-from-c"></a>Chamando funções não excepcionais de C++

Quando você chama uma função não excepcional de C++, a ideia é envolver essa função em uma função de C++ que detecta erros e, em seguida, possivelmente gera uma exceção. Quando você cria uma função wrapper, primeiro decida qual tipo de garantia de exceção para fornecer: não-throw, strong ou basic. Em seguida, crie a função para que todos os recursos, por exemplo, identificadores de arquivos, sejam liberados corretamente se uma exceção é lançada. Normalmente, isso significa que você use ponteiros inteligentes ou gerentes de recurso semelhantes para os próprios recursos. Para obter mais informações sobre considerações de design, consulte [como: Design para segurança de exceção](../cpp/how-to-design-for-exception-safety.md).

### <a name="example"></a>Exemplo

O exemplo a seguir mostra funções C++ que usam o Win32 `CreateFile` e `ReadFile` funções internamente para abrir e ler dois arquivos.  O `File` classe é uma aquisição de recurso é um wrapper de inicialização (RAII) para os identificadores de arquivos. Seu construtor detecta uma condição de "arquivo não encontrado" e gera uma exceção para propagar o erro até a pilha de chamadas do módulo C++ (neste exemplo, o `main()` função). Se uma exceção for lançada após um `File` objeto está totalmente construído, o destrutor automaticamente chama `CloseHandle` para liberar o identificador de arquivo. (Se você preferir, você pode usar a biblioteca ATL (Active Template) `CHandle` classe para essa mesma finalidade, ou um `unique_ptr` junto com um deletor personalizado.) As funções que chamam o Win32 e APIs de CRT detectam erros e, em seguida, gerar exceções de C++ usando o definido localmente `ThrowLastErrorIf` função, que por sua vez usa a `Win32Exception` classe que deriva de `runtime_error` classe. Todas as funções neste exemplo fornecem uma garantia de exceção forte; Se uma exceção for lançada em qualquer momento nessas funções, nenhum recurso será liberado e nenhum estado de programa é modificado.

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
            cout << "+++ Files are different." << endl;
        } else {
            cout<< "=== Files match." << endl;
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

Funções de C++ que são declaradas como "extern C" pode ser chamado por programas C. Os servidores C++ COM podem ser consumidos pelo código escrito em qualquer um dos vários idiomas diferentes. Quando você implementa funções de reconhecimento de exceção públicas em C++ a ser chamado pelo código não excepcional, a função de C++ não deve permitir todas as exceções sejam propagadas de volta para o chamador. Portanto, a função C++ deve especificamente capturar cada exceção que ele sabe como manipular e, se apropriado, converta a exceção em um código de erro que o chamador entende. Se nem todas as possíveis exceções forem conhecidas, a função de C++ deve ter um `catch(...)` bloco como o último manipulador. Nesse caso, é melhor relatar um erro fatal ao chamador, porque seu programa pode estar em um estado desconhecido.

O exemplo a seguir mostra uma função que assume que qualquer exceção que pode ser gerada é uma Win32Exception ou um tipo de exceção derivada de `std::exception`. A função captura qualquer exceção desses tipos e propaga as informações de erro como um código de erro do Win32 para o chamador.

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

Quando você converte de exceções para códigos de erro, um problema potencial é que os códigos de erro frequentemente não contêm a riqueza de informações que uma exceção pode armazenar. Para resolver isso, você pode fornecer um **catch** bloco para cada tipo de exceção específica que pode ser gerado e executar o log para registrar os detalhes da exceção antes que ele é convertido em um código de erro. Essa abordagem poderá criar muitas repetições de código se várias funções usarem o mesmo conjunto de **catch** blocos. Uma boa maneira de evitar a repetição de código é refatorar esses blocos em uma função particular de utilitário que implementa o **tente** e **catch** bloqueia e aceita um objeto de função é invocado no **tente** bloco. Em cada função pública, passe o código para a função de utilitário como uma expressão lambda.

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

O exemplo a seguir mostra como escrever a expressão lambda que define o functor. Quando um funtor é definido como "embutido" usando uma expressão lambda, geralmente é mais fácil de ler do que seria se tivesse sido escrito como um objeto de função nomeada.

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

[Erros e tratamento de exceções](../cpp/errors-and-exception-handling-modern-cpp.md)<br/>
[Como projetar tendo em vista a segurança de exceção](../cpp/how-to-design-for-exception-safety.md)<br/>
