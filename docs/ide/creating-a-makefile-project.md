---
title: Criando um projeto Makefile | Microsoft Docs
ms.custom: ''
ms.date: 02/28/2018
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
ms.openlocfilehash: dc854f96f1c41baf28a5af4ca1f253e47d9a8914
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33336772"
---
# <a name="creating-a-makefile-project"></a>Criando um projeto de makefile

Se você tem um projeto de código-fonte compilado na linha de comando usando um makefile, o ambiente de desenvolvimento do Visual Studio apresenta várias maneiras de transformá-lo em um projeto que pode aproveitar ao máximo as funcionalidades do IDE do Visual Studio. Este artigo descreve como criar um Projeto Makefile no Visual Studio que usa o makefile existente para compilar o código no IDE. Como alternativa, você pode usar o assistente para **Criar Novo Projeto com base em Arquivos de Código Existentes** para criar um projeto nativo do MSBuild com base no código-fonte. Para obter mais informações, consulte [Como criar um projeto do C++ com base no código existente](how-to-create-a-cpp-project-from-existing-code.md). Começando pelo Visual Studio 2017, use também o recurso **Abrir Pasta**, que pode usar vários sistemas de build existentes como se fossem projetos nativos do Visual Studio. Para saber mais, veja [Projetos Abrir Pasta no Visual C++](non-msbuild-projects.md).

Para usar o Visual Studio para abrir e compilar o código-fonte usando o makefile existente, primeiro crie um projeto selecionando o modelo de projeto MakeFile. Um assistente ajudará você a especificar os comandos e o ambiente usados pelo makefile. Em seguida, use esse projeto para compilar seu código no ambiente de desenvolvimento do Visual Studio.

Por padrão, o projeto de makefile não exibe nenhum arquivo no Gerenciador de Soluções. O projeto de makefile especifica as configurações de build, que são refletidas na página de propriedades do projeto.

O arquivo de saída que você especifica no projeto não tem efeito no nome que o script de compilação gera; ele declara apenas uma intenção. O makefile ainda controla o processo de build e especifica os destinos de build.

## <a name="to-create-a-makefile-project"></a>Para criar um projeto Makefile

1. Siga as instruções do tópico da Ajuda [Criando um projeto com um assistente de aplicativo do Visual C++](../ide/creating-desktop-projects-by-using-application-wizards.md).

1. Na caixa de diálogo **Novo Projeto**, expanda **Visual C++** > **Geral** e, em seguida, selecione **Projeto Makefile** no painel Modelos para abrir o assistente de projeto.

1. Na página [Configurações de Aplicativo](../ide/application-settings-makefile-project-wizard.md), forneça as informações de comando, saída, limpeza e recompilação para builds de depuração e varejo.

1. Clique em **Concluir** para fechar o assistente e abrir o projeto recém-criado no **Gerenciador de Soluções**.

Você pode ver e editar as propriedades do projeto em sua página de propriedades. Confira [Definindo propriedades do projeto do Visual C++](../ide/working-with-project-properties.md) para obter informações sobre como exibir a página de propriedades.

## <a name="see-also"></a>Consulte também

[Assistente de Projeto Makefile](../ide/makefile-project-wizard.md)<br/>
[Caracteres especiais em um makefile](../build/special-characters-in-a-makefile.md)<br/>
[Conteúdo de um makefile](../build/contents-of-a-makefile.md)<br/>
