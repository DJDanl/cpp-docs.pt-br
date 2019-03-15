---
title: Assistente de aplicativo Win32
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.win32.overview
helpviewer_keywords:
- Win32 Application Wizard
- Win32 Project Wizard
ms.assetid: 5d7b3a5e-8461-479a-969a-67b7883725b9
ms.openlocfilehash: 639834c8d723b65b894e6d216cbeb3b7f4dc37ec
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57822685"
---
# <a name="win32-application-wizard"></a>Assistente de aplicativo Win32

O Assistente de aplicativo do Visual C++ Win32 permite que você crie qualquer um dos quatro tipos de projetos (listados no título na tabela a seguir). Em cada caso, você pode especificar opções adicionais que são apropriadas para o tipo de projeto que você abrir. A tabela a seguir indica quais opções estão disponíveis para cada tipo de aplicativo.

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

Para alterar esses padrões, clique na guia [Configurações de Aplicativo](../windows/application-settings-win-32-project-wizard.md) na coluna à esquerda do assistente e faça as alterações desejadas.

Depois de criar um aplicativo de desktop do Windows, você pode adicionar classes C++ genéricas usando o [genérico](../ide/generic-cpp-class-wizard.md) Assistente de código. Você pode adicionar outros itens, como arquivos HTML, arquivos de cabeçalho, recursos ou arquivos de texto.

> [!NOTE]
> Não é possível adicionar classes da ATL, e você pode adicionar classes MFC somente para os tipos de aplicativo da área de trabalho do Windows que dão suporte a MFC (consulte a tabela anterior).

Você pode exibir os arquivos que o assistente cria para seu projeto no **Gerenciador de soluções**. Para obter mais informações sobre os arquivos que o assistente cria para seu projeto, consulte o arquivo de projeto gerado, `ReadMe.txt`. Para obter mais informações sobre os tipos de arquivo [tipos de arquivo criados para projetos do Visual C++](../build/reference/file-types-created-for-visual-cpp-projects.md).

## <a name="see-also"></a>Consulte também

[Criando um aplicativo da área de trabalho do Windows vazio](../windows/creating-an-empty-windows-desktop-application.md)<br/>
[Tipos de projeto do Visual C++](../build/reference/visual-cpp-project-types.md)