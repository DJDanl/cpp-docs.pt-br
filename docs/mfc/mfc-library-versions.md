---
title: "Versões de biblioteca MFC | Microsoft Docs"
ms.custom: 
ms.date: 1/09/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- class libraries [MFC], building versions
- version information [MFC], MFC library
- MFC class library
- MFC class library, building
- MFC libraries
- MFC, library versions
- libraries [MFC], versions
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7641a970c747576fa3cfd8cd1c00602edb3541e2
ms.sourcegitcommit: 9239c52c05e5cd19b6a72005372179587a47a8e4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2018
---
# <a name="mfc-library-versions"></a>Versões de biblioteca MFC

A biblioteca do MFC está disponível nas versões que dão suporte ao ANSI byte único e conjunto de caracteres multibyte (MBCS) código, bem como versões que dão suporte a Unicode (codificado como UTF-16LE, o conjunto de caracteres nativos do Windows). Cada versão do MFC está disponível como uma biblioteca estática ou como uma DLL compartilhada. Também há uma versão de biblioteca estática MFC menor que omite controles MFC para caixas de diálogo, para aplicativos que são muito sensíveis a tamanho e não precisam desses controles. As bibliotecas MFC estão disponíveis em ambos os depuração e liberação de versões para arquiteturas com suporte que incluem processadores ARM, x64 e x86. Você pode criar ambos os aplicativos (arquivos .exe) e DLLs com qualquer versão das bibliotecas do MFC. Há também um conjunto de bibliotecas MFC compilado para fazer interface com código gerenciado. O MFC compartilhado DLLs incluem um número de versão para indicar a compatibilidade binária da biblioteca.

## <a name="automatic-linking-of-mfc-library-versions"></a>Vinculação automática de versões de biblioteca MFC

Os arquivos de cabeçalho MFC determinam automaticamente a versão correta da biblioteca MFC para vincular, com base nos valores definidos em seu ambiente de compilação. Os arquivos de cabeçalho MFC adicionar diretivas de compilador instrui o vinculador para vincular em uma versão específica da biblioteca do MFC.

Por exemplo, o AFX. Arquivo de cabeçalho H instrui o vinculador a vincular o completo estático, limitada estático ou compartilhado versão DLL do MFC; ANSI/MBCS ou Unicode versão; e a versão de depuração ou de varejo, dependendo da configuração de compilação:

```cpp
#ifndef _AFXDLL
    #ifdef _AFX_NO_MFC_CONTROLS_IN_DIALOGS
        #ifdef _DEBUG
            #pragma comment(lib, "afxnmcdd.lib")
        #else
            #pragma comment(lib, "afxnmcd.lib")
        #endif
        #pragma comment(linker, "/include:__afxNoMFCControlSupportInDialogs")
        #pragma comment(linker, "/include:__afxNoMFCControlContainerInDialogs")
    #endif
    #ifndef _UNICODE
        #ifdef _DEBUG
            #pragma comment(lib, "nafxcwd.lib")
        #else
            #pragma comment(lib, "nafxcw.lib")
        #endif
    #else
        #ifdef _DEBUG
            #pragma comment(lib, "uafxcwd.lib")
        #else
            #pragma comment(lib, "uafxcw.lib")
        #endif
    #endif
#else
    #ifndef _UNICODE
        #ifdef _DEBUG
            #pragma comment(lib, "mfc" _MFC_FILENAME_VER "d.lib")
            #pragma comment(lib, "mfcs" _MFC_FILENAME_VER "d.lib")
        #else
            #pragma comment(lib, "mfc" _MFC_FILENAME_VER ".lib")
            #pragma comment(lib, "mfcs" _MFC_FILENAME_VER ".lib")
        #endif
    #else
        #ifdef _DEBUG
            #pragma comment(lib, "mfc" _MFC_FILENAME_VER "ud.lib")
            #pragma comment(lib, "mfcs" _MFC_FILENAME_VER "ud.lib")
        #else
            #pragma comment(lib, "mfc" _MFC_FILENAME_VER "u.lib")
            #pragma comment(lib, "mfcs" _MFC_FILENAME_VER "u.lib")
        #endif
    #endif
#endif
```

Arquivos de cabeçalho MFC também incluem as diretivas para vincular em bibliotecas de todos os itens necessárias, incluindo bibliotecas MFC, bibliotecas de Win32, bibliotecas OLE, criadas a partir de exemplos das bibliotecas OLE, bibliotecas ODBC e assim por diante. 

## <a name="ansi-mbcs-and-unicode"></a>Unicode, ANSI e MBCS

As versões de biblioteca do MFC ANSI/MBCS oferecem suporte a ambos os conjuntos de caracteres de byte único, como ASCII e conjuntos de caracteres multibyte, como Shift JIS. As versões de biblioteca MFC Unicode oferecem suporte a Unicode em sua forma codificada do caractere largo de UTF-16LE. Use as versões de biblioteca do ANSI/MBCS do MFC para suporte a Unicode codificados em UTF-8.

Para definir a configuração do projeto para usar byte único, multibyte ou caracteres de toda a cadeia de caracteres e caracteres suporte a Unicode no IDE, use o **propriedades do projeto** caixa de diálogo. No **propriedades de configuração** > **geral** , defina o **do conjunto de caracteres** propriedade **não definido** para usar um conjunto de caracteres de byte único. Defina a propriedade como **usar o conjunto de caracteres de vários bytes** para usar um conjunto de caracteres multibyte ou **usar conjunto de caracteres Unicode** usar Unicode codificado como UTF-16.

Projetos MFC usam o símbolo do pré-processador  **\_UNICODE** para indicar o suporte a caracteres largos Unicode UTF-16, e  **\_MBCS** para indicar o suporte de MBCS. Essas opções são mutuamente exclusivas em um projeto.

## <a name="mfc-static-library-naming-conventions"></a>Convenções de nomenclatura de biblioteca estática do MFC

Bibliotecas estáticas para MFC usam as seguintes convenções de nomenclatura. Os nomes de biblioteca que o formulário

> *u*AFX*c**d*.LIB

onde as letras mostradas em itálico minúsculas são espaços reservados para especificadores cujos significados são mostrados na tabela a seguir:

|Especificador|Valores e significados|
|---------------|-------------------------|
|*u*|ANSI/MBCS (N) ou Unicode (U); Omitir para versão sem controles MFC em caixas de diálogo|
|*c*|Versão com controles MFC em caixas de diálogo (CW) ou sem (NMCD)|
|*d*|Depurar ou versão: D = Debug; omitir um especificador de versão|

Todas as bibliotecas listadas na tabela a seguir estão incluídas pré-compiladas no diretório \atlmfc\lib para arquiteturas de compilação com suporte.

|Biblioteca|Descrição|
|-------------|-----------------|
|NAFXCW.LIB|Biblioteca de vínculo estático do MFC, versão de lançamento|
|NAFXCWD.LIB|Biblioteca de vínculo estático do MFC, versão de depuração|
|UAFXCW.LIB|Biblioteca de vínculo estático do MFC com suporte a Unicode, versão de lançamento|
|UAFXCWD.LIB|Biblioteca de vínculo estático do MFC com suporte a Unicode, versão de depuração|
|AFXNMCD.LIB|Biblioteca de Link estático MFC sem controles de caixa de diálogo do MFC, versão de lançamento|
|AFXNMCDD.LIB|Biblioteca de Link estático MFC sem controles de caixa de diálogo do MFC, versão de depuração|

Arquivos do depurador que têm o mesmo nome de base e uma extensão. PDB também estão disponíveis para cada uma das bibliotecas estáticas.

## <a name="mfc-shared-dll-naming-conventions"></a>Convenções de nomenclatura de DLL compartilhada do MFC

O MFC compartilhados DLLs também seguem uma convenção de nomenclatura estruturada. Isso torna mais fácil saber qual DLL ou biblioteca você deve usar para qual finalidade.

As DLLs MFC ter *versão* números que indicam a compatibilidade binária. Use MFC DLLs que tenham a mesma versão que as bibliotecas e conjunto de ferramentas de compilador para garantir a compatibilidade em um projeto.

|DLL|Descrição|
|---------|-----------------|
|MFC*version*.DLL|Versão de DLL MFC, ANSI ou MBCS de versão|
|MFC*version*U.DLL|DLL do MFC, versão de Unicode|
|MFC*version*D.DLL|Versão de DLL MFC, ANSI ou MBCS de depuração|
|MFC*version*UD.DLL|DLL do MFC, versão de depuração de Unicode|
|MFCM*version*.DLL|DLL do MFC com controles de formulários do Windows, versão ANSI ou MBCS versão|
|MFCM*version*U.DLL|DLL do MFC com controles de formulários do Windows, versão de Unicode|
|MFCM*version*D.DLL|DLL do MFC com controles de formulários do Windows, versão ANSI ou MBCS de depuração|
|MFCM*version*UD.DLL|DLL do MFC com controles de formulários do Windows, versão de depuração de Unicode|

As bibliotecas de importação necessárias para criar aplicativos ou extensão de MFC que usam essas DLLs compartilhadas têm o mesmo nome de base como a DLL, mas têm uma extensão de nome de arquivo. lib. Quando você usa os arquivos DLL compartilhados, uma pequena biblioteca estática ainda deve ser vinculada ao seu código; Essa biblioteca é chamada MFCS*versão*. lib de {U} {D}.

Se você está vinculando dinamicamente para a versão DLL compartilhada do MFC, se ele é de um aplicativo ou de uma DLL de extensão do MFC, você deve incluir o MFC correspondente*versão*. DLL ou MFC*versão*U.DLL quando você implanta seu produto.

Para obter uma lista das DLLs do Visual C++ que podem ser distribuídos com seus aplicativos, consulte [Código distribuível para o Microsoft Visual Studio 2017 e Microsoft Visual Studio 2017 SDK (inclui utilitários e arquivos do BuildServer)](http://go.microsoft.com/fwlink/p/?LinkId=823098).

Para obter mais informações sobre suporte a Unicode e MBCS no MFC, consulte [suporte a Unicode e conjunto de caracteres Multibyte (MBCS)](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md).

## <a name="dynamic-link-library-support"></a>Suporte à biblioteca de vínculo dinâmico

Você pode usar ambos as estáticas ou compartilhadas dinâmicas bibliotecas MFC criar DLLs que podem ser usados por arquivos executáveis do MFC e não MFC. Esses são chamados de "DLLs regulares" ou "DLLs normais do MFC", para diferenciá-los de extensão de MFC que só podem ser usados por aplicativos MFC e MFC DLLs. Uma DLL compilada usando as bibliotecas estáticas MFC às vezes é chamada um USRDLL nas referências mais antigas, como projetos de DLL MFC definem o símbolo do pré-processador  **\_USRDLL**. Uma DLL que usa o MFC DLLs compartilhadas às vezes é chamada um AFXDLL nas referências mais antigas, pois ele define o símbolo do pré-processador  **\_AFXDLL**.

Quando você criar o projeto DLL por meio da vinculação a bibliotecas estáticas MFC, sua DLL pode ser implantado sem a MFC compartilhado DLLs. Quando seu projeto DLL contém links para as bibliotecas de importação MFC*versão*. MFC ou LIB*versão*U.LIB, você deve implantar a correspondência de DLL MFC compartilhada do MFC*versão*. DLL ou MFC*versão*U.DLL junto com sua DLL. Para obter mais informações, consulte [DLLs](../build/dlls-in-visual-cpp.md).

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)  
