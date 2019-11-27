---
title: 'Como: interface entre códigos excepcionais e não excepcionais'
ms.custom: how-to
ms.date: 11/19/2019
ms.topic: conceptual
ms.assetid: fd5bb4af-5665-46a1-a321-614b48d4061e
ms.openlocfilehash: fccc40302ab7bd43b3e6b2f87eef488c7813c9be
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74245615"
---
# <a name="how-to-interface-between-exceptional-and-non-exceptional-code"></a>Como: interface entre códigos excepcionais e não excepcionais

Este artigo descreve como implementar o tratamento de exceção consistente em um C++ módulo e também como converter essas exceções de e para códigos de erro nos limites de exceção.

Às vezes C++ , um módulo tem de se fazer interface com código que não usa exceções (código não excepcional). Essa interface é conhecida como limite de *exceção*. Por exemplo, talvez você queira chamar a função do Win32 `CreateFile` em seu C++ programa. `CreateFile` não lança exceções; em vez disso, ele define códigos de erro que podem ser recuperados pela função `GetLastError`. Se o C++ seu programa não for trivial, você provavelmente prefere ter uma política de tratamento de erros baseada em exceção consistente. E você provavelmente não desejará abandonar exceções apenas porque você se baseia em uma interface com código não-excepcional, e nenhuma delas deseja misturar políticas de erro baseadas em exceção e não baseadas em C++ exceção em seu módulo.

## <a name="calling-non-exceptional-functions-from-c"></a>Chamando funções não excepcionais deC++

Quando você chama uma função não excepcional de C++, a ideia é encapsular essa função em uma C++ função que detecta erros e, em seguida, gera uma exceção. Quando você projeta essa função de invólucro, primeiro decida qual tipo de garantia de exceção fornecer: no-throw, strong ou Basic. Em segundo lugar, projete a função para que todos os recursos, por exemplo, identificadores de arquivo, sejam liberados corretamente se uma exceção for lançada. Normalmente, isso significa que você usa apontadores inteligentes ou gerenciadores de recursos semelhantes para ter os recursos. Para obter mais informações sobre considerações de design, consulte [como: design para segurança de exceção](how-to-design-for-exception-safety.md).

### <a name="example"></a>Exemplo

O exemplo a seguir C++ mostra as funções que usam o `CreateFile` do Win32 e `ReadFile` funções internamente para abrir e ler dois arquivos.  A classe `File` é um wrapper de RAII (aquisição de recursos é inicialização) para os identificadores de arquivo. Seu Construtor detecta uma condição "arquivo não encontrado" e gera uma exceção para propagar o erro na pilha de chamadas do C++ módulo (neste exemplo, a função `main()`). Se uma exceção for lançada depois que um objeto de `File` for totalmente construído, o destruidor chamará automaticamente `CloseHandle` para liberar o identificador de arquivo. (Se preferir, você pode usar a classe de `CHandle` Active Template Library (ATL) para essa mesma finalidade ou uma `unique_ptr` junto com um excluidor personalizado.) As funções que chamam APIs Win32 e CRT detectam erros e, C++ em seguida, geram exceções usando a função `ThrowLastErrorIf` definida localmente, que, por sua vez, usa a classe `Win32Exception`, derivada da classe `runtime_error`. Todas as funções neste exemplo fornecem uma forte garantia de exceção; se uma exceção for lançada em qualquer ponto dessas funções, nenhum recurso será vazado e nenhum estado do programa é modificado.

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

## <a name="calling-exceptional-code-from-non-exceptional-code"></a>Chamando código excepcional de código não-excepcional

C++as funções declaradas como "extern C" podem ser chamadas por programas C. C++Os servidores COM podem ser consumidos pelo código escrito em qualquer um de vários idiomas diferentes. Quando você implementa funções públicas com reconhecimento de exceção C++ no para serem chamadas por código não-excepcional, C++ a função não deve permitir que nenhuma exceção seja propagada de volta para o chamador. Portanto, a C++ função deve capturar especificamente todas as exceções que ele saiba como manipular e, se apropriado, converter a exceção em um código de erro que o chamador entenda. Se nem todas as possíveis exceções forem conhecidas, C++ a função deverá ter um bloco de `catch(...)` como o último manipulador. Nesse caso, é melhor relatar um erro fatal para o chamador, pois seu programa pode estar em um estado desconhecido.

O exemplo a seguir mostra uma função que supõe que qualquer exceção que possa ser gerada é uma Win32exception ou um tipo de exceção derivado de `std::exception`. A função captura qualquer exceção desses tipos e propaga as informações de erro como um código de erro do Win32 para o chamador.

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

Quando você converte de exceções para códigos de erro, um possível problema é que os códigos de erro geralmente não contêm a riqueza de informações que uma exceção pode armazenar. Para resolver isso, você pode fornecer um bloco **Catch** para cada tipo de exceção específico que pode ser lançado e executar o registro em log para registrar os detalhes da exceção antes que ela seja convertida em um código de erro. Essa abordagem pode criar muita repetição de código se várias funções usarem o mesmo conjunto de blocos **Catch** . Uma boa maneira de evitar a repetição de código é refatorar esses blocos em uma função de utilitário particular que implementa os blocos **try** e **Catch** e aceita um objeto de função que é invocado no bloco **try** . Em cada função pública, passe o código para a função do utilitário como uma expressão lambda.

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

O exemplo a seguir mostra como gravar a expressão lambda que define o functor. Quando um functor é definido "inline" usando uma expressão lambda, geralmente é mais fácil de ler do que seria se ele fosse gravado como um objeto de função nomeado.

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

Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](lambda-expressions-in-cpp.md).

## <a name="see-also"></a>Consulte também

[Práticas C++ recomendadas modernas para exceções e tratamento de erros](errors-and-exception-handling-modern-cpp.md)<br/>
[Como projetar tendo em vista a segurança de exceção](how-to-design-for-exception-safety.md)<br/>
