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
ms.openlocfilehash: 3d8be0cc33e0435bc5a18191303dbbc91277de0b
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80075445"
---
# <a name="windows-desktop-wizard"></a>Assistente da Área de Trabalho do Windows

O assistente de área de trabalho do Windows substitui o assistente de aplicativo Win32 no Visual Studio 2017 e posterior. O assistente permite que você crie qualquer um dos quatro tipos C++ de projetos (listados no título na tabela abaixo). Em cada caso, você pode especificar opções adicionais apropriadas para o tipo de projeto que você abrir.

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

Esta página de assistente descreve as configurações de projeto atuais para o aplicativo Win32 que você está criando. Por padrão, as seguintes opções são definidas:

- O projeto é um aplicativo do Windows.

- O projeto não está vazio.

- O projeto não contém símbolos de exportação.

- O projeto não usa um arquivo de cabeçalho pré-compilado (essa opção está disponível somente para projetos de biblioteca estática).

- O projeto inclui suporte para nem MFC nem ATL.

## <a name="application-type"></a>Tipo de aplicativo

Cria o tipo de aplicativo especificado.

|Opção|DESCRIÇÃO|
|------------|-----------------|
|**Aplicativo de console**|Crie um aplicativo de console. As C++ [bibliotecas de tempo de execução](../c-runtime-library/c-run-time-library-reference.md) do Visual também fornecem saída e entrada de janelas de console com funções de e/s padrão, como `printf_s()` e `scanf_s()`. Um aplicativo de console não tem nenhuma interface gráfica do usuário. Ele é compilado em um arquivo. exe e pode ser executado como um aplicativo autônomo da linha de comando.<br /><br /> Você pode adicionar suporte a MFC e ATL a um aplicativo de console.|
|**Aplicativo do Windows**|Cria um programa Win32. Um programa Win32 é um aplicativo executável (EXE) escrito em C ou C++usando chamadas para a API do Win32 para criar uma interface gráfica do usuário.<br /><br /> Você não pode adicionar suporte a MFC ou ATL a um aplicativo do Windows.|
|**Biblioteca de vínculo dinâmico**|Cria uma DLL (biblioteca de vínculo dinâmico) do Win32. Uma DLL Win32 é um arquivo binário, escrito em C ou C++, que usa chamadas para a API do Win32 em vez de classes MFC, e que atua como uma biblioteca compartilhada de funções que podem ser usadas simultaneamente por vários aplicativos.<br /><br /> Não é possível adicionar suporte a MFC ou ATL a um aplicativo DLL criado com esse assistente, mas você pode criar uma DLL do MFC escolhendo **novo projeto de > > dll do MFC**.|
|**Biblioteca estática**|Cria uma biblioteca estática. Uma biblioteca estática é um arquivo que contém objetos e suas funções e dados que são vinculados ao seu programa quando o arquivo executável é criado. Este tópico explica como criar os arquivos iniciais e [as propriedades do projeto](../build/reference/property-pages-visual-cpp.md) para uma biblioteca estática. Um arquivo de biblioteca estática fornece os seguintes benefícios:<br /><br />-Uma biblioteca estática Win32 é útil se o aplicativo no qual você está trabalhando faz chamadas para a API do Win32 em vez de classes MFC.<br />-O processo de vinculação é o mesmo se o restante do seu aplicativo do Windows for escrito em C C++ou no.<br />-Você pode vincular uma biblioteca estática a um programa baseado em MFC ou a um programa não MFC.|

## <a name="additional-options"></a>Opções adicionais

Define o suporte e as opções para o aplicativo, dependendo de seu tipo.

|Opção|DESCRIÇÃO|
|------------|-----------------|
|**Projeto vazio**|Especifica que os arquivos de projeto estão em branco. Se você tiver um conjunto de arquivos de código-fonte (como arquivos. cpp, arquivos de cabeçalho, ícones, barras de ferramentas, caixas de diálogo e assim por diante) e quiser criar um projeto C++ no ambiente de desenvolvimento Visual, primeiro deverá criar um projeto em branco e, em seguida, adicionar os arquivos ao projeto.<br /><br /> Essa seleção não está disponível para projetos de biblioteca estática.|
|**Exportar símbolos**|Especifica que o projeto DLL exporta símbolos.|
|**Cabeçalho pré-compilado**|Especifica que o projeto de biblioteca estática usa um cabeçalho pré-compilado.|
|**Verificações de ciclo de vida de desenvolvimento de segurança (SDL)**|Para obter mais informações sobre o SDL, consulte [diretrizes de processo de Microsoft Security Development Lifecycle (SDL)](../build/reference/sdl-enable-additional-security-checks.md)|

## <a name="add-common-headers-for"></a>Adicionar cabeçalhos comuns para:

Adicione suporte para uma das bibliotecas fornecidas no Visual C++.

|Opção|DESCRIÇÃO|
|------------|-----------------|
|**ATL**|O se baseia no suporte do projeto para classes no Active Template Library (ATL). Somente para aplicativos de console Win32.<br /><br /> **Observação** Essa opção não indica suporte para a adição de objetos ATL usando os assistentes de código ATL. Você pode adicionar objetos ATL somente a projetos ATL ou a projetos MFC com suporte ATL.|
|**MFC**|O se baseia no suporte do projeto para a biblioteca do Microsoft Foundation Class (MFC). Somente para aplicativos de console do Win32 e bibliotecas estáticas.|

## <a name="remarks"></a>Comentários

Depois de criar um aplicativo de área de trabalho do Windows, você C++ pode adicionar classes genéricas usando o assistente de código [genérico](../ide/generic-cpp-class-wizard.md) . Você pode adicionar outros itens, como arquivos HTML, arquivos de cabeçalho, recursos ou arquivos de texto.

> [!NOTE]
> Você não pode adicionar classes ATL e pode adicionar classes MFC somente a esses tipos de aplicativos da área de trabalho do Windows que dão suporte ao MFC (consulte a tabela anterior).

Você pode exibir os arquivos que o assistente cria para seu projeto no **Gerenciador de soluções**. Para obter mais informações sobre os arquivos que o assistente cria para seu projeto, consulte o arquivo gerado pelo projeto, `ReadMe.txt`. Para obter mais informações sobre os tipos de arquivo, [tipos de arquivo criados C++ para projetos do Visual Studio](../build/reference/file-types-created-for-visual-cpp-projects.md).

## <a name="see-also"></a>Confira também

[Tipos de projeto do C++ no Visual Studio](../build/reference/visual-cpp-project-types.md)