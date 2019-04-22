---
title: Assistente da Área de Trabalho do Windows
ms.date: 03/29/2019
f1_keywords:
- vc.appwiz.win32.overview
- vc.appwiz.win32.appset
helpviewer_keywords:
- Windows Desktop Wizard
- Win32 Project Wizard
ms.assetid: 5d7b3a5e-8461-479a-969a-67b7883725b9
ms.openlocfilehash: 43a47366475b227ccfc5918b07760cc582326e82
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59041465"
---
# <a name="windows-desktop-wizard"></a>Assistente da Área de Trabalho do Windows

O Assistente de área de trabalho do Windows substitui o Assistente de aplicativo Win32 no Visual Studio 2017 e versões posteriores. O assistente permite que você crie qualquer um dos quatro tipos de projetos do C++ (listados no título na tabela a seguir). Em cada caso, você pode especificar opções adicionais que são apropriadas para o tipo de projeto que você abrir. 

   ![Assistente da Área de Trabalho do Windows](media/windows-desktop-wizard.png)

A tabela a seguir indica quais opções estão disponíveis para cada tipo de aplicativo.

|Tipo de suporte|Aplicativo de console|Aplicativo executável (Windows)|Biblioteca de vínculo dinâmico|Biblioteca estática|
|---------------------|-------------------------|----------------------------------------|---------------------------|--------------------|
|**Projeto vazio**|Sim|Sim|Sim|Não|
|**Exportar símbolos**|Não|Não|Sim|Não|
|**Cabeçalho pré-compilado**|Não|Não|Não|Sim|
|**Suporte ATL**|Sim|Não|Não|Não|
|**Suporte do MFC**|Sim|Não|Não|Sim|

## <a name="overview"></a>Visão geral

Esta página do assistente descreve as configurações do projeto atual para o aplicativo do Win32 que você está criando. Por padrão, as seguintes opções estão definidas:

- O projeto é um aplicativo do Windows.

- O projeto não está vazio.

- O projeto não contém nenhum símbolo de exportação.

- O projeto não usa um arquivo de cabeçalho pré-compilado (essa opção está disponível para projetos de biblioteca estática somente).

- O projeto inclui suporte para MFC nem o ATL.

## <a name="application-type"></a>Tipo de aplicativo

Cria o tipo de aplicativo especificado.

|Opção|Descrição|
|------------|-----------------|
|**Aplicativo de console**|Crie um aplicativo de console. Programas de console são desenvolvidos com [funções do Console](https://msdn.microsoft.com/library/ms813137.aspx), que fornecem suporte de modo de caractere nas janelas do console. O Visual C++ [bibliotecas de tempo de execução](../c-runtime-library/c-run-time-library-reference.md) também fornecem a saída e entrada do windows do console com funções de e/s padrão, como `printf_s()` e `scanf_s()`. Um aplicativo de console não tem nenhuma interface gráfica do usuário. Ele compila em um arquivo .exe e pode ser executado como um aplicativo autônomo da linha de comando.<br /><br /> Você pode adicionar suportam a MFC e ATL para um aplicativo de console.|
|**Aplicativo do Windows**|Cria um programa Win32. Um programa Win32 é um aplicativo executável (EXE) escrito em C ou C++, usando chamadas à API do Win32 para criar uma interface gráfica do usuário.<br /><br /> Não é possível adicionar o MFC ou ATL oferecem suporte a um aplicativo do Windows.|
|**Biblioteca de vínculo dinâmico**|Cria uma biblioteca de vínculo dinâmico (DLL) do Win32. Uma DLL Win32 é um arquivo binário, escrito em C ou C++, que usa chamadas à API do Win32 em vez de classes do MFC e que atua como uma biblioteca compartilhada de funções que podem ser usados simultaneamente por vários aplicativos.<br /><br /> Você não pode adicionar suporte MFC ou ATL para um aplicativo de DLL criado usando este assistente, mas você pode criar uma DLL MFC por escolher **Novo > projeto > DLL do MFC**.|
|**Biblioteca estática**|Cria uma biblioteca estática. Uma biblioteca estática é um arquivo que contém objetos e suas funções e os dados que vincula-se ao seu programa quando o arquivo executável é compilado. Este tópico explica como criar os arquivos iniciais e [propriedades do projeto](../build/reference/property-pages-visual-cpp.md) para uma biblioteca estática. Um arquivo de biblioteca estática fornece os seguintes benefícios:<br /><br />-Uma biblioteca estática do Win32 será útil se o aplicativo que você está trabalhando em faz chamadas para a API do Win32 em vez de classes do MFC.<br />– O processo de vinculação é o mesmo se o restante do seu aplicativo do Windows é escrito em C ou C++.<br />-Você pode vincular uma biblioteca estática em um programa MFC ou a um programa não MFC.|

## <a name="additional-options"></a>Opções adicionais

Define as opções para o aplicativo, dependendo do seu tipo e o suporte.

|Opção|Descrição|
|------------|-----------------|
|**Projeto vazio**|Especifica que os arquivos de projeto em branco. Se você tiver um conjunto de arquivos de código fonte (como arquivos. cpp, arquivos de cabeçalho, ícones, barras de ferramentas, caixas de diálogo e assim por diante) e deseja criar um projeto no ambiente de desenvolvimento do Visual C++, primeiro você deve criar um projeto em branco e adicione os arquivos ao projeto.<br /><br /> Essa seleção não está disponível para projetos de biblioteca estática.|
|**Exportar símbolos**|Especifica que o projeto de DLL exporta símbolos.|
|**Cabeçalho pré-compilado**|Especifica que o projeto de biblioteca estática usa um cabeçalho pré-compilado.|
|**Verificações do Security Development Lifecycle (SDL)**|Para obter mais informações sobre o SDL, consulte [diretrizes de processo do Microsoft Security Development Lifecycle (SDL)](../build/reference/sdl-enable-additional-security-checks.md)|

## <a name="add-common-headers-for"></a>Adicione cabeçalho comuns para:

Adicione suporte para uma das bibliotecas fornecidas no Visual C++.

|Opção|Descrição|
|------------|-----------------|
|**ATL**|Compila para o suporte de projeto para classes na biblioteca ATL (Active Template). Para aplicativos de console Win32 somente.<br /><br /> **Observação** essa opção não indica suporte para adicionar objetos ATL usando a ATL assistentes de código. Você pode adicionar objetos ATL somente a projetos ATL ou dar suporte a projetos MFC com ATL.|
|**MFC**|Compila para o suporte de projeto para a biblioteca Microsoft Foundation Class (MFC). Para aplicativos de console Win32 e apenas as bibliotecas estáticas.|

## <a name="remarks"></a>Comentários

Depois de criar um aplicativo de desktop do Windows, você pode adicionar classes C++ genéricas usando o [genérico](../ide/generic-cpp-class-wizard.md) Assistente de código. Você pode adicionar outros itens, como arquivos HTML, arquivos de cabeçalho, recursos ou arquivos de texto.

> [!NOTE]
> Não é possível adicionar classes da ATL, e você pode adicionar classes MFC somente para os tipos de aplicativo da área de trabalho do Windows que dão suporte a MFC (consulte a tabela anterior).

Você pode exibir os arquivos que o assistente cria para seu projeto no **Gerenciador de soluções**. Para obter mais informações sobre os arquivos que o assistente cria para seu projeto, consulte o arquivo de projeto gerado, `ReadMe.txt`. Para obter mais informações sobre os tipos de arquivo [tipos de arquivo criados para projetos do Visual C++](../build/reference/file-types-created-for-visual-cpp-projects.md).

## <a name="see-also"></a>Consulte também

[Tipos de projeto do Visual C++](../build/reference/visual-cpp-project-types.md)