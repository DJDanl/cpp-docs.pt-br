---
title: Operações CString relacionadas a cadeias de caracteres de estilo C
ms.date: 11/04/2016
helpviewer_keywords:
- CString objects, basic operations
- MFC [C++], string handling class
- string conversion [C++], C-style strings
- strings [C++], string operations
- standard run-time library string functions
- null values, Null-terminated string conversion
- string functions
- strings [C++], in C
- string arguments
- C-style strings
- strings [C++], class CString
- casting CString objects
ms.assetid: 5048de8a-5298-4891-b8a0-c554b5a3ac1b
ms.openlocfilehash: bbf483703b04c26c9462e4fe6adb08b614e440f7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222037"
---
# <a name="cstring-operations-relating-to-c-style-strings"></a>Operações CString relacionadas a cadeias de caracteres de estilo C

Um objeto [CString](../atl-mfc-shared/using-cstring.md) contém dados de cadeia de caracteres. `CString`herda o conjunto de [métodos e operadores](../atl-mfc-shared/reference/cstringt-class.md) que são definidos no modelo de classe [CStringT](../atl-mfc-shared/reference/cstringt-class.md) para trabalhar com dados de cadeia de caracteres. ( `CString` é um **`typedef`** que é especializado `CStringT` para trabalhar com o tipo de dados de caractere que o `CString` dá suporte.)

O `CString` não armazena dados de caracteres internamente como uma cadeia de caracteres de terminação nula de estilo C. Em vez disso, o `CString` controla o comprimento dos dados de caracteres, para que ele possa observar de maneira mais segura os dados e o espaço que necessita.

O `CString` não aceita cadeias de caracteres de estilo C e fornece maneiras de acessar dados de caracteres como uma cadeia de caracteres de estilo C. Este tópico contém as seguintes seções que explicam como usar um objeto `CString` como se fosse uma cadeia de caracteres de terminação nula e estilo C.

- [Convertendo para cadeias de caracteres de terminação nula de estilo C](#_core_using_cstring_as_a_c.2d.style_null.2d.terminated_string)

- [Trabalhando com funções padrão de cadeia de caracteres de biblioteca em de tempo de execução](#_core_working_with_standard_run.2d.time_library_string_functions)

- [Modificando o conteúdo de CString diretamente](#_core_modifying_cstring_contents_directly)

- [Usando objetos CString com funções de argumento variáveis](#_core_using_cstring_objects_with_variable_argument_functions)

- [Especificando parâmetros formais de CString](#_core_specifying_cstring_formal_parameters)

## <a name="using-cstring-as-a-c-style-null-terminated-string"></a><a name="_core_using_cstring_as_a_c.2d.style_null.2d.terminated_string"></a>Usando CString como uma cadeia de caracteres terminada em nulo em estilo C

Para usar um `CString` objeto como uma cadeia de caracteres de estilo C, converta o objeto em LPCTSTR. No exemplo a seguir, o `CString` retorna um ponteiro para uma cadeia de caracteres de terminação nula de estilo C somente leitura. A função `strcpy` coloca uma cópia da cadeia de caracteres de estilo C na variável `myString`.

```cpp
CString aCString = "A string";
char myString[256];
strcpy(myString, (LPCTSTR)aCString);
```

Você pode usar métodos `CString`, por exemplo, `SetAt`, para modificar caracteres individuais no objeto de cadeia de caracteres. No entanto, o ponteiro LPCTSTR é temporário e se torna inválido quando qualquer alteração é feita no `CString` . O `CString` também pode sair do escopo e ser automaticamente excluído. Recomendamos que você obtenha um ponteiro LPCTSTR novo de um `CString` objeto toda vez que usar um.

Às vezes, você pode precisar que uma cópia de dados do `CString` seja modificada diretamente. Use a função mais segura `strcpy_s` (ou o Unicode/MBCS-portable `_tcscpy_s`) para copiar o objeto `CString` em um buffer separado. Este é o local onde os caracteres podem ser modificados com segurança, como mostrado no exemplo seguinte.

[!code-cpp[NVC_ATLMFC_Utilities#189](../atl-mfc-shared/codesnippet/cpp/cstring-operations-relating-to-c-style-strings_1.cpp)]

> [!NOTE]
> O terceiro argumento para `strcpy_s` (ou o Unicode/MBCS-portátil `_tcscpy_s` ) é um `const wchar_t*` (Unicode) ou um `const char*` (ANSI). O exemplo acima passa um `CString` para este argumento. O compilador C++ aplica automaticamente a função de conversão definida para o `CString` que converte uma classe `CString` para um `LPCTSTR`. A capacidade de definir as operações de conversão de um tipo para outro é um dos recursos mais úteis do C++.

## <a name="working-with-standard-run-time-library-string-functions"></a><a name="_core_working_with_standard_run.2d.time_library_string_functions"></a>Trabalhando com funções de cadeia de caracteres de biblioteca de tempo de execução padrão

Você conseguirá encontrar um método `CString` para realizar qualquer operação de cadeia de caracteres para a qual você considere o uso das funções padrão de cadeia de biblioteca em tempo de execução C, como `strcmp` (ou o Unicode/MBCS-portable `_tcscmp`).

Se você precisar usar as funções de cadeia de caracteres de tempo de execução C, poderá usar as técnicas descritas em _core_using_cstring_as_a_c. 2D. style_null. 2D. terminated_string. Você pode copiar o objeto `CString` para um buffer de cadeia estilo C equivalente, executar suas operações no buffer e depois atribuir a cadeia de caracteres de estilo C resultante de novo ao objeto `CString`.

## <a name="modifying-cstring-contents-directly"></a><a name="_core_modifying_cstring_contents_directly"></a>Modificando o conteúdo de CString diretamente

Na maioria das situações, você deve usar funções de membro `CString` para modificar o conteúdo de um objeto `CString` ou para converter o `CString` para uma cadeia de caracteres de estilo C.

Existem algumas situações em que faz sentido modificar diretamente o conteúdo `CString`, por exemplo, quando você trabalha com funções do sistema operacional que exigem um buffer de caracteres.

Os métodos `GetBuffer` e `ReleaseBuffer` oferecem acesso ao buffer de caracteres interno de um objeto `CString` e deixam você modificá-lo diretamente. As etapas a seguir mostram como usar essas funções para essa finalidade.

### <a name="to-use-getbuffer-and-releasebuffer-to-access-the-internal-character-buffer-of-a-cstring-object"></a>Para usar os métodos GetBuffer e ReleaseBuffer para acessar o buffer de caracteres interno de um objeto CString

1. Chame `GetBuffer` para um objeto `CString` e especifique o tamanho do buffer que você necessita.

1. Use o ponteiro retornado por `GetBuffer` para escrever caracteres diretamente no objeto `CString`.

1. Chame `ReleaseBuffer` para o objeto `CString` para atualizar todas as informações de estado internas do `CString`, por exemplo, o comprimento da cadeia de caracteres. Depois de modificar o conteúdo de um objeto `CString` diretamente, chame `ReleaseBuffer` antes de chamar qualquer outra função de membro `CString`.

## <a name="using-cstring-objects-with-variable-argument-functions"></a><a name="_core_using_cstring_objects_with_variable_argument_functions"></a>Usando objetos CString com funções de argumento variáveis

Algumas funções C usam um número variável de argumentos. Um exemplo notável é `printf_s`. Devido à forma como esse tipo de função é declarado, o compilador não pode ter certeza do tipo dos argumentos e não pode determinar qual operação de conversão realizar em cada argumento. Portanto, é essencial que você use um tipo de conversão explícita ao passar um objeto `CString` para uma função que recebe um número variável de argumentos.

Para usar um `CString` objeto em uma função de argumento variável, converta explicitamente o `CString` em uma cadeia de caracteres LPCTSTR, conforme mostrado no exemplo a seguir.

[!code-cpp[NVC_ATLMFC_Utilities#190](../atl-mfc-shared/codesnippet/cpp/cstring-operations-relating-to-c-style-strings_2.cpp)]

## <a name="specifying-cstring-formal-parameters"></a><a name="_core_specifying_cstring_formal_parameters"></a>Especificando parâmetros formais de CString

Para a maioria das funções que precisam de um argumento de cadeia de caracteres, é melhor especificar o parâmetro formal no protótipo de função como um **`const`** ponteiro para um caractere ( `LPCTSTR` ) em vez de um `CString` . Quando um parâmetro formal é especificado como um **`const`** ponteiro para um caractere, você pode passar um ponteiro para uma matriz TCHAR, uma cadeia de caracteres literal [ `"hi there"` ] ou um `CString` objeto. O `CString` objeto será convertido automaticamente em um LPCTSTR. Em qualquer lugar, você pode usar um LPCTSTR, você também pode usar um `CString` objeto.

Você também pode especificar um parâmetro formal como uma referência de cadeia de caracteres constante (ou seja, `const CString&` ) se o argumento não for modificado. Descarte o **`const`** modificador se a cadeia de caracteres for modificada pela função. Se você desejar um valor nulo padrão, inicialize-o para a cadeia de caracteres nula [`""`], como mostrado abaixo:

[!code-cpp[NVC_ATLMFC_Utilities#191](../atl-mfc-shared/codesnippet/cpp/cstring-operations-relating-to-c-style-strings_3.cpp)]

Para a maioria dos resultados de função, você pode simplesmente retornar um objeto `CString` por valor.

## <a name="see-also"></a>Confira também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
[Passagem de argumento CString](../atl-mfc-shared/cstring-argument-passing.md)
