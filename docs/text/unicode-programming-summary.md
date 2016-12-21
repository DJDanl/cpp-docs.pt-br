---
title: "Resumo de programa&#231;&#227;o Unicode | Microsoft Docs"
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
helpviewer_keywords: 
  - "Unicode [C++], funções e tempo de execução MFC e C"
  - "Unicode [C++], programando com"
ms.assetid: a4c9770f-6c9c-447c-996b-980920288bed
caps.latest.revision: 8
caps.handback.revision: 8
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Resumo de programa&#231;&#227;o Unicode
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para aproveitar MFC e suporte de tempo de execução C para Unicode, você precisa:  
  
-   Define **\_UNICODE**.  
  
     Define o símbolo **\_UNICODE** antes de criar o programa.  
  
-   Especifique o ponto de entrada.  
  
     Na página de **Saída** da pasta do vinculador na caixa de diálogo de [Páginas de propriedades](../ide/property-pages-visual-cpp.md) de projeto, defina o símbolo de ponto de entrada para **wWinMainCRTStartup**.  
  
-   Use funções portáteis e tipos de tempo de execução.  
  
     Use as funções apropriadas de tempo de execução C para a manipulação de cadeia de caracteres Unicode.  Você pode usar a família de **wcs** de funções, mas você pode preferir macros \(international habilitados\) totalmente portátil de **\_TCHAR** .  Macros todos esses são prefixados com **\_tcs**; substituição, um para um, da família de **str** de funções.  Essas funções são descritas em detalhes na seção de [Internacionalização](../c-runtime-library/internationalization.md)*de referência da biblioteca de tempo de execução*.  Para obter mais informações, consulte [Mapeamentos de Genérico\- texto em Tchar.h](../Topic/Generic-Text%20Mappings%20in%20Tchar.h.md).  
  
     Use **\_TCHAR** e os tipos de dados portáteis relacionadas descritas em [Suporte para Unicode](../text/support-for-unicode.md).  
  
-   Tratar cadeias de caracteres literais corretamente.  
  
     O compilador do Visual C\+\+ interpreta uma cadeia de caracteres literal codificada como:  
  
    ```  
    L"this is a literal string"  
    ```  
  
     para mostrar uma cadeia de caracteres de caracteres Unicode.  Você pode usar o mesmo prefixo de caracteres literais.  Use a macro de **\_T** para codificar genèrica cadeias de caracteres literais, assim que criam como cadeias de caracteres Unicode em Unicode ou como as cadeias de caracteres ANSI \(inclusive MBCS\) sem Unicode.  Por exemplo, em vez de:  
  
    ```  
    pWnd->SetWindowText( "Hello" );  
    ```  
  
     use:  
  
    ```  
    pWnd->SetWindowText( _T("Hello") );  
    ```  
  
     Com **\_UNICODE** definiu, **\_T** converte a cadeia de caracteres literal para o formulário L\- prefixado; caso contrário, **\_T** converte a cadeia de caracteres sem o prefixo L.  
  
    > [!TIP]
    >  A macro de **\_T** é idêntico a macro de `_TEXT` .  
  
-   Tenha cuidado ao passar os comprimentos de cadeia de caracteres às funções.  
  
     Algumas funções desejam o número de caracteres em uma cadeia de caracteres; outro desejam o número de bytes.  Por exemplo, se **\_UNICODE** é definido, o seguinte chamada a um objeto de `CArchive` não funcionará \(`str` é `CString`\):  
  
    ```  
    archive.Write( str, str.GetLength( ) );    // invalid  
    ```  
  
     Em um aplicativo Unicode, o comprimento é o número de caracteres mas não o número de bytes correto, porque cada caractere é de 2 bytes de comprimento.  Em vez disso, você deve usar:  
  
    ```  
    archive.Write( str, str.GetLength( ) * sizeof( _TCHAR ) );    // valid  
    ```  
  
     que especifica o número de bytes correto para gravação.  
  
     Porém, as funções de membro de MFC que são a caracteres, em vez de orientado, trabalho sem essa codificação adicional:  
  
    ```  
    pDC->TextOut( str, str.GetLength( ) );  
    ```  
  
     `CDC::TextOut` usa um número de caracteres, um número de bytes.  
  
-   Use [fopen\_s, \_wfopen\_s](../c-runtime-library/reference/fopen-s-wfopen-s.md) para abrir arquivos Unicode.  
  
 Para resumir, MFC o e a biblioteca de tempo de execução a seguir fornecem suporte para Unicode que programa no Windows 2000:  
  
-   Com exceção das funções de membro da classe base de dados de, todas as funções de MFC estiverem habilitadas, incluindo `CString`.  `CString` também fornece funções de conversão Unicode\/ANSI.  
  
-   A biblioteca de tempo de execução fornece versões Unicode de todas as funções de cadeia de caracteres\- manipulação. \(Biblioteca de tempo de execução também fornece as versões portáteis adequadas para Unicode ou para MBCS.  Esses são macros de **\_tcs** .\)  
  
-   Tchar.h o fornece os tipos de dados portáteis e a macro de **\_T** para converter cadeias de caracteres literais e caracteres.  Para obter mais informações, consulte [Mapeamentos de Genérico\- texto em Tchar.h](../Topic/Generic-Text%20Mappings%20in%20Tchar.h.md).  
  
-   A biblioteca de tempo de execução fornece uma ampla versão do caractere de **main**.  Use **wmain** para fazer seu aplicativo cientes do.  
  
## Consulte também  
 [Suporte para Unicode](../text/support-for-unicode.md)