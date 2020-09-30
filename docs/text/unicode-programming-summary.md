---
title: Resumo de programação Unicode
ms.date: 11/04/2016
helpviewer_keywords:
- Unicode [C++], programming with
- Unicode [C++], MFC and C run-time functions
ms.assetid: a4c9770f-6c9c-447c-996b-980920288bed
ms.openlocfilehash: 5095e1c58db3e5c35eb9215367f2fbb064bc228a
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91504715"
---
# <a name="unicode-programming-summary"></a>Resumo de programação Unicode

Para aproveitar o suporte a MFC e o tempo de execução do C para Unicode, você precisa:

- Definir `_UNICODE` .

   Defina o símbolo `_UNICODE` antes de compilar o programa.

- Especifique o ponto de entrada.

   Na página **avançado** da pasta do **vinculador** na caixa de diálogo [páginas de propriedades](../build/reference/property-pages-visual-cpp.md) do projeto, defina o símbolo de **ponto de entrada** como `wWinMainCRTStartup` .

- Use funções e tipos de tempo de execução portáteis.

   Use as funções adequadas de tempo de execução C para manipulação de cadeia de caracteres Unicode. Você pode usar a `wcs` família de funções, mas pode preferir as macros totalmente portáteis (habilitadas para internacionalmente) `_TCHAR` . Todas essas macros prefixadas `_tcs` ; elas substituem, uma para uma, para a `str` família de funções. Essas funções são descritas em detalhes na seção [internacionalização](../c-runtime-library/internationalization.md) da *referência da biblioteca de tempo de execução*. Para obter mais informações, consulte [mapeamentos de texto genérico em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).

   Use `_TCHAR` o e os tipos de dados portáteis relacionados descritos em [suporte para Unicode](../text/support-for-unicode.md).

- Manipule cadeias de caracteres literais corretamente.

   O compilador de Visual C++ interpreta uma cadeia de caracteres literal codificada como:

    ```cpp
    L"this is a literal string"
    ```

   para significar uma cadeia de caracteres Unicode. Você pode usar o mesmo prefixo para caracteres literais. Use a `_T` macro para codificar Cadeias de caracteres literais genericamente, portanto, elas são compiladas como cadeias de caracteres Unicode em Unicode ou como cadeias de caracteres ANSI (incluindo MBCS) sem Unicode. Por exemplo, em vez de:

    ```cpp
    pWnd->SetWindowText( "Hello" );
    ```

   utilizá

    ```cpp
    pWnd->SetWindowText( _T("Hello") );
    ```

   Com o `_UNICODE` definido, `_T` traduz a cadeia de caracteres literal para o formato l-prefixado; caso contrário, `_T` traduz a cadeia de caracteres sem o prefixo l.

    > [!TIP]
    >  A `_T` macro é idêntica à `_TEXT` macro.

- Tenha cuidado ao passar comprimentos de cadeia de caracteres para funções.

   Algumas funções querem o número de caracteres em uma cadeia de caracteres; outros querem o número de bytes. Por exemplo, se `_UNICODE` for definido, a chamada a seguir para um `CArchive` objeto não funcionará ( `str` é um `CString` ):

    ```cpp
    archive.Write( str, str.GetLength( ) );    // invalid
    ```

   Em um aplicativo Unicode, o comprimento fornece o número de caracteres, mas não o número correto de bytes, porque cada caractere tem 2 bytes de largura. Em vez disso, você deve usar:

    ```cpp
    archive.Write( str, str.GetLength( ) * sizeof( _TCHAR ) );    // valid
    ```

   que especifica o número correto de bytes a serem gravados.

   No entanto, as funções de membro do MFC que são orientadas por caractere, em vez de orientadas a byte, funcionam sem essa codificação extra:

    ```cpp
    pDC->TextOut( str, str.GetLength( ) );
    ```

   `CDC::TextOut` usa um número de caracteres, não um número de bytes.

- Use [fopen_s, _wfopen_s](../c-runtime-library/reference/fopen-s-wfopen-s.md) para abrir arquivos Unicode.

Para resumir, o MFC e a biblioteca de tempo de execução fornecem o seguinte suporte para programação Unicode:

- Exceto para funções de membro de classe de banco de dados, todas as funções MFC são habilitadas para Unicode, incluindo `CString` . `CString` também fornece funções de conversão Unicode/ANSI.

- A biblioteca de tempo de execução fornece versões Unicode de todas as funções de manipulação de cadeia de caracteres. (A biblioteca de tempo de execução também fornece versões portáteis adequadas para Unicode ou MBCS. Essas são as `_tcs` macros.)

- TCHAR. h fornece tipos de dados portáteis e a `_T` macro para converter cadeias de caracteres literais e personagens. Para obter mais informações, consulte [mapeamentos de texto genérico em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).

- A biblioteca de tempo de execução fornece uma versão de caractere largo do `main` . Use `wmain` para tornar seu aplicativo ciente de Unicode.

## <a name="see-also"></a>Consulte também

[Suporte para Unicode](../text/support-for-unicode.md)
