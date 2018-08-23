---
title: Resumo de programação Unicode | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Unicode [C++], programming with
- Unicode [C++], MFC and C run-time functions
ms.assetid: a4c9770f-6c9c-447c-996b-980920288bed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 78e40e258334ed1e9622e31e8452810f231cb61f
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42581997"
---
# <a name="unicode-programming-summary"></a>Resumo de programação Unicode
Para aproveitar o suporte de tempo de execução MFC e C para Unicode, você precisa:  
  
-   Definir `_UNICODE`.  
  
     Defina o símbolo `_UNICODE` antes de compilar seu programa.  
  
-   Especifique o ponto de entrada.  
  
     No **saída** página do **vinculador** pasta do projeto [páginas de propriedades](../ide/property-pages-visual-cpp.md) caixa de diálogo, defina o **ponto de entrada** símbolo a ser `wWinMainCRTStartup`.  
  
-   Use tipos e funções de tempo de execução portátil.  
  
     Use as funções de tempo de execução C apropriadas para manipulação de cadeia de caracteres Unicode. Você pode usar o `wcs` família de funções, mas você talvez prefira totalmente portátil (internacionalmente habilitado) `_TCHAR` macros. Essas macros são prefixadas com `_tcs`; eles substituem, um para um, para o `str` família de funções. Essas funções são descritas detalhadamente na [internacionalização](../c-runtime-library/internationalization.md) seção o *referência de biblioteca de tempo de execução*. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).  
  
     Use `_TCHAR` e os tipos de dados portáteis relacionados descritos [suporte para Unicode](../text/support-for-unicode.md).  
  
-   Tratar corretamente cadeias de caracteres literais.  
  
     O compilador do Visual C++ interpreta uma cadeia de caracteres literal, codificada como:  
  
    ```  
    L"this is a literal string"  
    ```  
  
     para indicar uma cadeia de caracteres Unicode. Você pode usar o mesmo prefixo para caracteres literais. Use o `_T` macro codificar cadeias de caracteres literais genericamente, portanto, eles são compilados como cadeias de caracteres Unicode em Unicode ou ANSI cadeias de caracteres (incluindo MBCS) sem Unicode. Por exemplo, em vez de:  
  
    ```  
    pWnd->SetWindowText( "Hello" );  
    ```  
  
     Uso:  
  
    ```  
    pWnd->SetWindowText( _T("Hello") );  
    ```  
  
     Com o `_UNICODE` definidos, `_T` converte a cadeia de caracteres literal para o formulário com o prefixo L; caso contrário, `_T` converte a cadeia de caracteres sem o prefixo L.  
  
    > [!TIP]
    >  O `_T` macro é idêntica de `_TEXT` macro.  
  
-   Tenha cuidado passar comprimentos de cadeia de caracteres para funções.  
  
     Algumas funções deseja que o número de caracteres em uma cadeia de caracteres; outros preferem o número de bytes. Por exemplo, se `_UNICODE` for definida, a seguinte chamada para um `CArchive` objeto não funcionará (`str` é um `CString`):  
  
    ```  
    archive.Write( str, str.GetLength( ) );    // invalid  
    ```  
  
     Em um aplicativo Unicode, o comprimento fornece o número de caracteres, mas não o número correto de bytes, porque cada caractere é 2 bytes de largura. Em vez disso, você deve usar:  
  
    ```  
    archive.Write( str, str.GetLength( ) * sizeof( _TCHAR ) );    // valid  
    ```  
  
     que especifica o número correto de bytes a serem gravados.  
  
     No entanto, as funções de membro MFC que são orientadas a caracteres, em vez de orientado a bytes, funcionam sem essa codificação extra:  
  
    ```  
    pDC->TextOut( str, str.GetLength( ) );  
    ```  
  
     `CDC::TextOut` usa um número de caracteres, não é um número de bytes.  
  
-   Use [fopen_s, wfopen_s](../c-runtime-library/reference/fopen-s-wfopen-s.md) para abrir arquivos Unicode.  
  
 Para resumir, MFC e a biblioteca de tempo de execução fornecem o seguinte suporte de programação de Unicode:  
  
-   Exceto para funções de membro de classe de banco de dados, todas as funções MFC são habilitados para Unicode, incluindo `CString`. `CString` também fornece funções de conversão de Unicode/ANSI.  
  
-   A biblioteca de tempo de execução fornece versões Unicode de todas as funções de manipulação de cadeia de caracteres. (A biblioteca de tempo de execução também fornece versões portáveis adequadas para Unicode ou MBCS. Esses são os `_tcs` macros.)  
  
-   TCHAR. h fornece tipos de dados portáteis e o `_T` macro para converter cadeias de caracteres literais e caracteres. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).  
  
-   A biblioteca de tempo de execução fornece uma versão de caractere largo de `main`. Use `wmain` para tornar seu aplicativo com reconhecimento de Unicode.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte para Unicode](../text/support-for-unicode.md)