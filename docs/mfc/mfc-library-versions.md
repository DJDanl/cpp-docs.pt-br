---
title: Versões de biblioteca MFC
ms.date: 05/08/2019
helpviewer_keywords:
- class libraries [MFC], building versions
- version information [MFC], MFC library
- MFC class library
- MFC class library, building
- MFC libraries
- MFC, library versions
- libraries [MFC], versions
ms.openlocfilehash: b8e32366d9ff43bd6e5770f64f0ba9d8bf6e56ab
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78856794"
---
# <a name="mfc-library-versions"></a>Versões de biblioteca MFC

A biblioteca do MFC está disponível em versões que dão suporte ao código de configuração de byte único e de conjunto de caracteres multibyte (MBCS), bem como a versões que dão suporte ao Unicode (codificado como UTF-16LE, o conjunto de caracteres nativo do Windows). Cada versão do MFC está disponível como uma biblioteca estática ou como uma DLL compartilhada. Há também uma versão menor da biblioteca estática do MFC que deixa os controles MFC para caixas de diálogo, para aplicativos que são muito sensíveis ao tamanho e não precisam desses controles. As bibliotecas do MFC estão disponíveis em versões de depuração e de lançamento para arquiteturas com suporte que incluem processadores x86, x64 e ARM. Você pode criar aplicativos (arquivos. exe) e DLLs com qualquer versão das bibliotecas do MFC. Também há um conjunto de bibliotecas MFC compiladas para interface com código gerenciado. As DLLs compartilhadas do MFC incluem um número de versão para indicar a compatibilidade binária de biblioteca.

## <a name="automatic-linking-of-mfc-library-versions"></a>Vinculação automática de versões da biblioteca do MFC

Os arquivos de cabeçalho do MFC determinam automaticamente a versão correta da biblioteca do MFC a ser vinculada, com base nos valores definidos em seu ambiente de compilação. Os arquivos de cabeçalho do MFC adicionam diretivas de compilador instruindo o vinculador a vincular em uma versão específica da biblioteca do MFC.

Por exemplo, o AFX. O arquivo de cabeçalho H instrui o vinculador a vincular a versão estática completa, estática limitada ou compartilhada DLL do MFC; Versão ANSI/MBCS ou Unicode; e a versão de depuração ou de varejo, dependendo da sua configuração de compilação:

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

Os arquivos de cabeçalho do MFC também incluem diretivas para vincular em todas as bibliotecas necessárias, incluindo bibliotecas MFC, bibliotecas do Win32, bibliotecas OLE, bibliotecas OLE criadas com base em amostras, bibliotecas ODBC e assim por diante.

## <a name="ansi-mbcs-and-unicode"></a>ANSI, MBCS e Unicode

As versões da biblioteca ANSI/MBCS do MFC dão suporte a conjuntos de caracteres de byte único, como ASCII, e conjuntos de caracteres multibyte, como Shift-JIS. As versões de biblioteca do MFC Unicode dão suporte a Unicode em seu formato codificado de caracteres largos UTF-16LE. Use as versões da biblioteca ANSI/MBCS do MFC para suporte a Unicode codificado em UTF-8.

Para definir a configuração do projeto para usar a cadeia de caracteres Unicode de caractere único, multibyte ou de caracteres largos e o suporte a caracteres no IDE, use a caixa de diálogo **Propriedades do projeto** . Na página **Propriedades de configuração** > **geral** , defina a propriedade **conjunto de caracteres** como **não definido** para usar um conjunto de caracteres de byte único. Defina a propriedade para **usar o conjunto de caracteres de vários bytes** para usar um conjunto de caracteres multibyte ou para **usar o conjunto de caracteres Unicode** para usar o Unicode codificado como UTF-16.

Os projetos MFC usam o símbolo de pré-processador \_UNICODE para indicar o suporte a Unicode de caracteres largos de UTF-16 e \_MBCS para indicar o suporte a MBCS. Essas opções são mutuamente exclusivas em um projeto.

## <a name="mfc-static-library-naming-conventions"></a>Convenções de nomenclatura de biblioteca estática MFC

Bibliotecas estáticas para MFC usam as seguintes convenções de nomenclatura. Os nomes de biblioteca têm o formato

> <em>u</em> AFX<em>CD</em>. LIB

onde as letras mostradas em minúsculas em itálico são espaços reservados para especificadores cujos significados são mostrados na tabela a seguir:

|Especificador|Valores e significados|
|---------------|-------------------------|
|*u*|ANSI/MBCS (N) ou Unicode (U); omitir para versão sem controles MFC em caixas de diálogo|
|*c*|Versão com controles MFC em caixas de diálogo (CW) ou sem (NMCD)|
|*d*|Depuração ou versão: D = Depurar; omitir especificador para liberação|

Todas as bibliotecas listadas na tabela a seguir são incluídas predefinidas no diretório \atlmfc\lib para arquiteturas de compilação com suporte.

|Biblioteca|Descrição|
|-------------|-----------------|
|NAFXCW.LIB|Biblioteca de vínculos estáticos do MFC, versão de lançamento|
|NAFXCWD.LIB|Biblioteca de vínculos estáticos do MFC, versão de depuração|
|UAFXCW.LIB|Biblioteca de vínculos estáticos do MFC com suporte a Unicode, versão de lançamento|
|UAFXCWD.LIB|Biblioteca de vínculos estáticos do MFC com suporte a Unicode, versão de depuração|
|AFXNMCD.LIB|MFC static-link library sem controles da caixa de diálogo do MFC, versão de lançamento|
|AFXNMCDD.LIB|MFC static-link library sem controles da caixa de diálogo do MFC, versão de depuração|

Os arquivos do depurador que têm o mesmo nome base e uma extensão. pdb também estão disponíveis para cada uma das bibliotecas estáticas.

## <a name="mfc-shared-dll-naming-conventions"></a>Convenções de nomenclatura da DLL compartilhada do MFC

As DLLs compartilhadas do MFC também seguem uma Convenção de nomenclatura estruturada. Isso facilita saber qual DLL ou biblioteca você deve usar para qual finalidade.

As DLLs do MFC têm números de *versão* que indicam a compatibilidade binária. Use as DLLs do MFC que têm a mesma versão que as outras bibliotecas e o conjunto de ferramentas do compilador para garantir a compatibilidade em um projeto.

|DLL|Descrição|
|---------|-----------------|
|*Versão*do MFC. DLL|DLL de versão do MFC, ANSI ou MBCS|
|DLL de*versão*do MFC|DLL do MFC, versão de lançamento Unicode|
|*Versão*D. dll do MFC|Versão de depuração de DLL do MFC, ANSI ou MBCS|
|MFC*versão*UD. DLL|DLL do MFC, versão de depuração Unicode|
|*Versão*do MFCM. DLL|DLL do MFC com controles Windows Forms, versão de lançamento ANSI ou MBCS|
|MFCM*versão*U. dll|DLL do MFC com controles Windows Forms, versão de lançamento Unicode|
|MFCM*versão*D. dll|DLL do MFC com controles Windows Forms, versão de depuração ANSI ou MBCS|
|MFCM*versão*UD. DLL|DLL do MFC com controles de Windows Forms, versão de depuração Unicode|

As bibliotecas de importação necessárias para criar aplicativos ou DLLs de extensão MFC que usam essas DLLs compartilhadas têm o mesmo nome base que a DLL, mas têm uma extensão de nome de arquivo. lib. Quando você usa as DLLs compartilhadas, uma pequena biblioteca estática ainda deve ser vinculada ao seu código; Esta biblioteca é denominada MFCS*versão*{U} {D}. lib.

Se você estiver vinculando dinamicamente à versão de DLL compartilhada do MFC, seja de um aplicativo ou de uma DLL de extensão do MFC, você deve incluir a*versão*correspondente do MFC. DLL ou o MFC*versão*U. dll ao implantar seu produto.

Para obter uma lista de C++ DLLs visuais que podem ser distribuídas com seus aplicativos, consulte [código distribuível para Microsoft Visual Studio 2017 e Microsoft Visual Studio SDK 2017 (inclui utilitários e arquivos BuildServer)](/visualstudio/productinfo/2017-redistribution-vs) ou [código distribuível para o Visual Studio 2019](/visualstudio/releases/2019/redistribution).

Para obter mais informações sobre o suporte a MBCS e Unicode no MFC, consulte [suporte para Unicode e conjunto de caracteres multibyte (MBCS)](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md).

## <a name="dynamic-link-library-support"></a>Suporte à biblioteca de vínculo dinâmico

Você pode usar as bibliotecas do MFC dinâmicos ou estáticas para criar DLLs que podem ser usadas por executáveis MFC e não MFC. Elas são chamadas de "DLLs regulares" ou "DLLs regulares do MFC", para distingui-las das DLLs de extensão do MFC que só podem ser usadas por aplicativos MFC e DLLs do MFC. Uma DLL criada usando as bibliotecas estáticas MFC é, às vezes, chamada de USRDLL em referências mais antigas, porque os projetos MFC DLL definem o símbolo de pré-processador **\_USRDLL**. Uma DLL que usa as DLLs compartilhadas do MFC é, às vezes, chamada de AFXDLL em referências mais antigas, porque ela define o símbolo de pré-processador **\_AFXDLL**.

Quando você cria seu projeto de DLL vinculando-se às bibliotecas estáticas do MFC, sua DLL pode ser implantada sem as DLLs compartilhadas do MFC. Quando o projeto de DLL é vinculado à*versão*do MFC de bibliotecas de importação. LIB ou MFC*versão*U. lib, você deve implantar a*versão*do MFC Shared DLL compartilhada correspondente. DLL ou o MFC*versão*U. dll junto com sua dll. Para obter mais informações, consulte [DLLs](../build/dlls-in-visual-cpp.md).

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)
