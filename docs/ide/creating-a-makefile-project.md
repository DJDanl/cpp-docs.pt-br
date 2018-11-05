---
title: Criando um projeto Makefile C++ | Microsoft Docs
ms.custom: ''
ms.date: 10/19/2018
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.appwiz.makefile.project
dev_langs:
- C++
helpviewer_keywords:
- Makefile projects, creating
- project files [C++], Makefile projects
ms.assetid: dd077af3-97a8-48fb-baaa-cf7e07ddef61
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5f937c11b2453bd296468c5f153b7c9495eba290
ms.sourcegitcommit: c045c3a7e9f2c7e3e0de5b7f9513e41d8b6d19b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2018
ms.locfileid: "49990237"
---
# <a name="creating-a-c-makefile-project"></a>Criando um Projeto Makefile C++

Um *makefile* é um arquivo de texto que contém instruções sobre como criar e vincular (ou *compilar*) um conjunto de arquivos de código-fonte do C++. Um programa *make* lê o makefile e invoca um compilador, vinculador e possivelmente outros programas para criar um arquivo executável. A implementação do programa *make* pela Microsoft é chamada **NMAKE**. (Por padrão, o Visual Studio usa o sistema MSBuild com base em arquivos .vcxproj; este é o que foi criado por **Arquivo | Novo | Projeto**.)

Se tiver um projeto makefile existente, você terá estas opções se desejar codificar e/ou depurá-lo no Visual Studio IDE:

- Crie um Projeto Makefile no Visual Studio que usa o makefile existente para compilar o código no IDE. (Você não terá todos os recursos do IDE que tem com um projeto MSBuild nativo). Consulte [Para criar um projeto makefile](#create_a_makefile_project) abaixo.
- Use o assistente para **Criar Novo Projeto com base em Arquivos de Código Existentes** para criar um projeto nativo do MSBuild com base no código-fonte. Para obter mais informações, consulte [Como criar um projeto do C++ com base no código existente](how-to-create-a-cpp-project-from-existing-code.md).
- **Visual Studio 2017 e posterior**: use o recurso **Abrir Pasta** para abrir um projeto makefile sem convertê-lo para MSBuild. Para saber mais, veja [Projetos Abrir Pasta no Visual C++](non-msbuild-projects.md).

## <a name="a-namecreateamakefileproject-to-create-a-makefile-project-with-the-makefile-project-template"></a><a name="create_a_makefile_project"> Para criar um projeto Makefile com o modelo de projeto makefile

No Visual Studio 2017 e posterior, o modelo de projeto Makefile estará disponível quando a carga de trabalho de Desenvolvimento do C++ da área de trabalho for instalada.

Siga o assistente para especificar os comandos e o ambiente usado pelo seu makefile. Em seguida, use esse projeto para compilar seu código no ambiente de desenvolvimento do Visual Studio.

Por padrão, o projeto de makefile não exibe nenhum arquivo no Gerenciador de Soluções. O projeto de makefile especifica as configurações de build, que são refletidas na página de propriedades do projeto.

O arquivo de saída que você especifica no projeto não tem efeito no nome que o script de compilação gera; ele declara apenas uma intenção. O makefile ainda controla o processo de build e especifica os destinos de build.

1. Na página inicial do Visual Studio, digite "makefile" na caixa de pesquisa **Novo projeto**. Ou, na caixa de diálogo **Novo Projeto**, expanda **Visual C++** > **Geral** (Visual Studio 2015) ou **Outro** (Visual Studio 2017) e, em seguida, selecione **Projeto Makefile** no painel Modelos para abrir o assistente de projeto.

1. Na página [Configurações de Aplicativo](../ide/application-settings-makefile-project-wizard.md), forneça as informações de comando, saída, limpeza e recompilação para builds de depuração e varejo.

1. Clique em **Concluir** para fechar o assistente e abrir o projeto recém-criado no **Gerenciador de Soluções**.

Você pode ver e editar as propriedades do projeto em sua página de propriedades. Confira [Definindo propriedades do projeto do Visual C++](../ide/working-with-project-properties.md) para obter informações sobre como exibir a página de propriedades.

## <a name="see-also"></a>Consulte também

[Assistente de Projeto Makefile](../ide/makefile-project-wizard.md)<br/>
[Caracteres especiais em um makefile](../build/special-characters-in-a-makefile.md)<br/>
[Conteúdo de um makefile](../build/contents-of-a-makefile.md)<br/>
