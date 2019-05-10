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
ms.sourcegitcommit: 00e26915924869cd7eb3c971a7d0604388abd316
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2019
ms.locfileid: "65524791"
---
# <a name="mfc-library-versions"></a>Versões de biblioteca MFC

A biblioteca do MFC está disponível nas versões que dão suporte ao ANSI byte único e o conjunto de caracteres multibyte (MBCS) código, bem como versões que dão suporte a Unicode (codificado como UTF-16LE, o conjunto de caracteres nativos do Windows). Cada versão do MFC está disponível como uma biblioteca estática ou como uma DLL compartilhada. Também é uma versão de biblioteca estática MFC menor que deixa de fora de controles do MFC para caixas de diálogo, para aplicativos que são sensíveis ao tamanho e não precisam desses controles. As bibliotecas MFC estão disponíveis em ambos os depuração e versões para arquiteturas com suporte que incluem processadores ARM, x64 e x86. Você pode criar os dois aplicativos (.exe arquivos) e DLLs com qualquer versão das bibliotecas do MFC. Há também um conjunto de bibliotecas MFC, compilado para fazer interface com código gerenciado. O MFC compartilhado DLLs incluem um número de versão para indicar a compatibilidade binária de biblioteca.

## <a name="automatic-linking-of-mfc-library-versions"></a>Vinculação automática de versões de biblioteca MFC

Os arquivos de cabeçalho MFC determinam automaticamente a versão correta da biblioteca MFC à qual vincular, com base nos valores definidos em seu ambiente de compilação. Os arquivos de cabeçalho MFC adicionar diretivas de compilador instruindo o vinculador para vincular-se em uma versão específica da biblioteca MFC.

Por exemplo, o AFX. Arquivo de cabeçalho de H instrui o vinculador para vincular na estática completo, limitada estática ou compartilhada versão DLL do MFC; Versão ANSI/MBCS ou Unicode; e a versão de depuração ou de varejo, dependendo da sua configuração de compilação:

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

Arquivos de cabeçalho MFC também incluem diretivas vincular nas bibliotecas de todos os itens necessárias, incluindo bibliotecas MFC, bibliotecas Win32, bibliotecas OLE, bibliotecas OLE criadas a partir de exemplos, bibliotecas ODBC e assim por diante.

## <a name="ansi-mbcs-and-unicode"></a>ANSI, MBCS e Unicode

As versões de biblioteca do ANSI/MBCS do MFC dão suporte a ambos os conjuntos de caracteres de byte único, como ASCII e conjuntos de caracteres multibyte como Shift-JIS. As versões da biblioteca MFC Unicode oferecem suporte a Unicode em sua forma codificada de caractere largo UTF-16LE. Use as versões da biblioteca ANSI/MBCS do MFC para suporte a Unicode codificados em UTF-8.

Para definir as configurações do projeto para usar o byte único, vários bytes ou caracteres largos sequência de caracteres e o caractere de suporte a Unicode no IDE, use o **propriedades do projeto** caixa de diálogo. No **propriedades de configuração** > **geral** , defina a **do conjunto de caracteres** propriedade para **não definido** para usar um conjunto de caracteres de byte único. Defina a propriedade como **usar o conjunto de caracteres multibyte** para usar um conjunto de caracteres multibyte, ou como **usar conjunto de caracteres Unicode** usar Unicode codificado como UTF-16.

Projetos MFC usam o símbolo do pré-processador \_UNICODE para indicar o suporte a caracteres largos Unicode UTF-16, e \_suporte MBCS para indicar o MBCS. Essas opções são mutuamente exclusivas em um projeto.

## <a name="mfc-static-library-naming-conventions"></a>Convenções de nomenclatura de biblioteca estática do MFC

Bibliotecas estáticas para MFC usam as seguintes convenções de nomenclatura. Os nomes de biblioteca que o formulário

> <em>u</em>AFX<em>cd</em>.LIB

em que as letras mostradas em itálico letras minúsculas são espaços reservados para especificadores cujos significados são mostrados na tabela a seguir:

|Especificador|Significados e valores|
|---------------|-------------------------|
|*u*|ANSI/MBCS (N) ou Unicode (U); Omitir para a versão sem controles em caixas de diálogo do MFC|
|*c*|Versão com controles do MFC em caixas de diálogo (PV) ou sem (NMCD)|
|*d*|Debug ou Release: 1!d = depuração; omitir o especificador de versão|

Todas as bibliotecas listadas na tabela a seguir estão incluídas predefinidas no diretório \atlmfc\lib para arquiteturas de compilação com suporte.

|Biblioteca|Descrição|
|-------------|-----------------|
|NAFXCW.LIB|Biblioteca de vínculo estático do MFC, versão de lançamento|
|NAFXCWD.LIB|Biblioteca de vínculo estático do MFC, versão de depuração|
|UAFXCW.LIB|Biblioteca de vínculo estático do MFC com suporte a Unicode, versão de lançamento|
|UAFXCWD.LIB|Biblioteca de vínculo estático do MFC com suporte a Unicode, versão de depuração|
|AFXNMCD.LIB|Biblioteca de vínculo estático de MFC sem controles de caixa de diálogo do MFC, versão de lançamento|
|AFXNMCDD.LIB|Biblioteca de vínculo estático de MFC sem controles de caixa de diálogo do MFC, versão de depuração|

Arquivos de depurador que têm o mesmo nome base e uma extensão. PDB também estão disponíveis para cada uma das bibliotecas estáticas.

## <a name="mfc-shared-dll-naming-conventions"></a>Convenções de nomenclatura de DLL compartilhadas do MFC

O MFC DLLs compartilhadas também seguem uma convenção de nomenclatura estruturada. Isso torna mais fácil saber qual DLL ou biblioteca, você deverá usar para qual finalidade.

As DLLs do MFC têm *versão* números que indicam a compatibilidade binária. Use DLLs MFC que têm a mesma versão de outras bibliotecas e ferramentas de compilador para garantir a compatibilidade em um projeto.

|DLL|Descrição|
|---------|-----------------|
|MFC*version*.DLL|Versão de DLL do MFC, ANSI ou MBCS de versão|
|MFC*version*U.DLL|DLL do MFC, versão de lançamento do Unicode|
|MFC*version*D.DLL|Versão de DLL do MFC, ANSI ou MBCS de depuração|
|MFC*version*UD.DLL|DLL do MFC, versão de depuração de Unicode|
|MFCM*version*.DLL|DLL do MFC com controles de formulários do Windows, versão ANSI ou a versão MBCS|
|MFCM*version*U.DLL|DLL do MFC com controles de formulários do Windows, versão de lançamento do Unicode|
|MFCM*version*D.DLL|DLL do MFC com controles de formulários do Windows, versão ANSI ou MBCS de depuração|
|MFCM*version*UD.DLL|DLL do MFC com controles de formulários do Windows, versão de depuração de Unicode|

As bibliotecas de importação necessárias para criar aplicativos ou a extensão de MFC que usam essas DLLs compartilhadas têm o mesmo nome base que a DLL, mas têm uma extensão de nome de arquivo. lib. Quando você usa as DLLs compartilhadas, uma pequena biblioteca estática ainda deve ser vinculada ao seu código; Essa biblioteca é denominada MFCS*versão*. lib de {U} {D}.

Se você estiver vinculando dinamicamente para a versão DLL compartilhada do MFC, se ele é de um aplicativo ou de uma DLL de extensão do MFC, você deve incluir o MFC correspondente*versão*. DLL ou MFC*versão*U.DLL quando você implanta seu produto.

Para obter uma lista de Visual C++ DLLs que podem ser distribuídos com seus aplicativos, consulte [Código distribuível para o Microsoft Visual Studio 2017 e Microsoft Visual Studio 2017 SDK (inclui utilitários e arquivos do BuildServer)](/visualstudio/productinfo/2017-redistribution-vs) ou [ Código distribuível para o Visual Studio de 2019](/visualstudio/releases/2019/redistribution).

Para obter mais informações sobre o suporte MBCS e Unicode em MFC, consulte [suporte a Unicode e conjunto de caracteres Multibyte (MBCS)](../atl-mfc-shared/unicode-and-multibyte-character-set-mbcs-support.md).

## <a name="dynamic-link-library-support"></a>Suporte de biblioteca de vínculo dinâmico

Você pode usar ambos as estáticas ou compartilhadas dinâmicas bibliotecas MFC para criar DLLs que podem ser usadas por executáveis MFC e não MFC. Eles são chamados "DLLs regulares" ou "DLLs MFC regulares", para diferenciá-los de extensão de MFC que só pode ser usado por aplicativos do MFC e o MFC DLLs. Uma DLL compilada usando as bibliotecas estáticas do MFC, às vezes, é chamada um USRDLL nas referências mais antigas, porque os projetos de DLL do MFC definem o símbolo do pré-processador  **\_USRDLL**. Uma DLL que usa o MFC DLLs compartilhadas às vezes é chamada um AFXDLL nas referências mais antigas, pois ele define o símbolo do pré-processador  **\_AFXDLL**.

Quando você cria seu projeto de DLL por meio da vinculação a bibliotecas estáticas do MFC, a DLL pode ser implantada sem DLLs compartilhadas do MFC. Quando seu projeto de DLL se vincula às bibliotecas de importação MFC*versão*. MFC ou LIB*versão*U.LIB, você deve implantar a correspondência compartilhadas de MFC DLL MFC*versão*. DLL ou MFC*versão*U.DLL junto com sua DLL. Para obter mais informações, consulte [DLLs](../build/dlls-in-visual-cpp.md).

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)
