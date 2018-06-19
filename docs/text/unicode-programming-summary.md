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
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2a378d46c517dfc0fbb5857ad54bc31f4c34287b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33859671"
---
# <a name="unicode-programming-summary"></a>Resumo de programação Unicode
Para aproveitar o suporte de tempo de execução MFC e C para Unicode, você precisa:  
  
-   Definir **Unicode**.  
  
     Definir o símbolo **Unicode** antes de criar seu programa.  
  
-   Especifique o ponto de entrada.  
  
     Sobre o **saída** página da pasta vinculador do projeto [páginas de propriedade](../ide/property-pages-visual-cpp.md) caixa de diálogo caixa, defina o símbolo de ponto de entrada **wWinMainCRTStartup**.  
  
-   Use tipos e funções de tempo de execução portátil.  
  
     Use as funções apropriadas do tempo de execução C para manipulação de cadeia de caracteres Unicode. Você pode usar o **wcs** família de funções, mas você talvez prefira totalmente portátil (internacionalmente ativado) **TCHAR** macros. Essas macros são prefixadas com **_tcs**; eles substituem, um para um, para o **str** família de funções. Essas funções são descritas detalhadamente no [internacionalização](../c-runtime-library/internationalization.md) seção o *referência da biblioteca de tempo de execução*. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).  
  
     Use **TCHAR** e os tipos de dados portátil relacionados descritos na [suporte para Unicode](../text/support-for-unicode.md).  
  
-   Lidar corretamente com cadeias de caracteres literais.  
  
     O compilador do Visual C++ interpreta a cadeia de caracteres literal codificada como:  
  
    ```  
    L"this is a literal string"  
    ```  
  
     como uma cadeia de caracteres Unicode. Você pode usar o mesmo prefixo de caracteres literal. Use o **t** macro codificar cadeias de caracteres literais genericamente, para que eles são compilados como cadeias de caracteres Unicode em Unicode ou como cadeias de caracteres ANSI (incluindo MBCS) sem Unicode. Por exemplo, em vez de:  
  
    ```  
    pWnd->SetWindowText( "Hello" );  
    ```  
  
     Uso:  
  
    ```  
    pWnd->SetWindowText( _T("Hello") );  
    ```  
  
     Com **Unicode** definido, **t** converte a cadeia de caracteres literal para o formulário de prefixo L; caso contrário, **t** converte a cadeia de caracteres sem o prefixo L.  
  
    > [!TIP]
    >  O **t** macro é idêntica de `_TEXT` macro.  
  
-   Tenha cuidado passando os comprimentos de cadeia de caracteres para funções.  
  
     Algumas funções deseja que o número de caracteres em uma cadeia de caracteres; outros deseja que o número de bytes. Por exemplo, se **Unicode** for definida, a seguinte chamada para um `CArchive` objeto não funcionará (`str` é um `CString`):  
  
    ```  
    archive.Write( str, str.GetLength( ) );    // invalid  
    ```  
  
     Em um aplicativo de Unicode, o comprimento fornece o número de caracteres, mas não o número correto de bytes, porque cada caractere é de 2 bytes de largura. Em vez disso, você deve usar:  
  
    ```  
    archive.Write( str, str.GetLength( ) * sizeof( _TCHAR ) );    // valid  
    ```  
  
     que especifica o número correto de bytes a serem gravados.  
  
     No entanto, as funções de membro MFC que são orientadas a caracteres, em vez de orientado a bytes, funcionarão sem ela extra de codificação:  
  
    ```  
    pDC->TextOut( str, str.GetLength( ) );  
    ```  
  
     `CDC::TextOut` Obtém um número de caracteres, não é um número de bytes.  
  
-   Use [fopen_s, wfopen_s](../c-runtime-library/reference/fopen-s-wfopen-s.md) para abrir arquivos Unicode.  
  
 Para resumir, MFC e a biblioteca de tempo de execução fornecem o seguinte suporte para programação Unicode:  
  
-   Exceto para funções de membro de classe de banco de dados, todas as funções MFC são habilitados para Unicode, incluindo `CString`. `CString` também fornece funções de conversão Unicode/ANSI.  
  
-   A biblioteca de tempo de execução fornece versões Unicode de todas as funções de manipulação de cadeia de caracteres. (A biblioteca de tempo de execução também fornece versões portátil adequadas para Unicode ou MBCS. Estes são os **_tcs** macros.)  
  
-   TCHAR. h fornece tipos de dados portátil e **t** macro para a conversão de caracteres e cadeias de caracteres literais. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).  
  
-   A biblioteca de tempo de execução fornece uma versão de caractere largo de **principal**. Use **wmain** para tornar seu aplicativo com reconhecimento de Unicode.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte para Unicode](../text/support-for-unicode.md)