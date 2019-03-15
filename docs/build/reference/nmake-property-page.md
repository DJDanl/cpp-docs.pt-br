---
title: Página de propriedades de NMake (Windows C++) | Microsoft Docs
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCNMakeTool.ReBuildCommandLine
- VC.Project.VCNMakeTool.CleanCommandLine
- VC.Project.VCNMakeTool.Output
- VC.Project.VCNMakeTool.BuildCommandLine
helpviewer_keywords:
- NMake property page
ms.assetid: bd20cb52-9f1d-4240-b4fc-4f43205ac94b
ms.openlocfilehash: c0dbe537635fe6698f814f3d8456f0caa9c8c796
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824294"
---
# <a name="nmake-property-page"></a>Página de propriedades NMake

A página de propriedades de **NMake** permite que você especifique configurações de build para projetos NMake. (NMAKE é a implementação da Microsoft [tornar](https://wikipedia.org/wiki/Make_(software)).)

Para obter mais informações sobre projetos NMake, confira [Criando um projeto Makefile](creating-a-makefile-project.md). Para projetos de MakeFile não - Windows, consulte [propriedades do projeto MakeFile (Linux C++)](../../linux/prop-pages/makefile-linux.md), [propriedades gerais do projeto (Makefile Android C++)](/visualstudio/cross-platform/general-makefile-android-prop-page) ou [propriedades de NMake (Android C++)](/visualstudio/cross-platform/nmake-android-prop-page).

A página de propriedades de **NMake** contém as propriedades a seguir.

## <a name="uielement-list"></a>Lista UIElement

- **Linha de Comando de Build**

   Especifica o comando a ser executado quando o usuário clica em **Compilar** no menu **Build**.

- **Linha de Comando de Recompilar Tudo**

   Especifica o comando a ser executado quando o usuário clica em **Recompilar Tudo** no menu **Build**.

- **Linha de Comando de Limpar**

   Especifica o comando a ser executado quando o usuário clica em **Limpar** no menu **Build**.

- **Saída**

   Especifica o nome do arquivo de saída que conterá a saída da linha de comando. Por padrão, esse nome de arquivo baseia-se no nome do projeto.

- **Definições de Pré-processador**

   Especifica as definições de pré-processador usadas pelos arquivos de origem. O valor padrão é determinado pela plataforma e configuração atuais.

- **Caminho de Pesquisa de Inclusão**

   Especifica os diretórios nos quais o compilador pesquisa arquivos de inclusão.

- **Inclusões Forçadas**

   Especifica os arquivos que o pré-processador processa automaticamente mesmo se eles não são incluídos nos arquivos de projeto.

- **Caminho de Pesquisa de Assembly**

   Especifica os diretórios pesquisados pelo .NET Framework quando ele tenta resolver assemblies .NET.

- **Assemblies de Uso Forçado**

   Especifica os assemblies processados automaticamente pelo .NET Framework.

- **Opções adicionais**

   Especifica as opções adicionais do compilador para uso do IntelliSense ao analisar arquivos C++.

Para obter informações sobre como acessar o **NMake** página de propriedades, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

Para obter informações sobre como acessar os membros desse objeto de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCNMakeTool>.

## <a name="see-also"></a>Consulte também

[Referência de página de propriedades do projeto C++](property-pages-visual-cpp.md)<br>
