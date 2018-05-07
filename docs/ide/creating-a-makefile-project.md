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
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="creating-a-makefile-project"></a>Criando um projeto de makefile

Se você tiver um projeto de código de origem existente que você compila na linha de comando usando um makefile, o ambiente de desenvolvimento do Visual Studio tem várias maneiras de ativá-lo em um projeto que pode se beneficiar dos recursos do Visual Studio IDE. Este artigo descreve como criar um projeto Makefile do Visual Studio que usa o makefile existente para compilar seu código no IDE. Como alternativa, você pode usar o **criar novo projeto de arquivos de código existentes** Assistente para criar um projeto do MSBuild nativo de seu código-fonte. Para obter mais informações, consulte [Como criar um projeto do C++ com base no código existente](how-to-create-a-cpp-project-from-existing-code.md). A partir de 2017 do Visual Studio, você também pode usar o **Abrir pasta** recurso, que pode usar vários sistemas de compilação existentes, como se fossem nativos projetos do Visual Studio. Para saber mais, veja [Projetos Abrir Pasta no Visual C++](non-msbuild-projects.md).

Para usar o Visual Studio para abrir e criar seu código-fonte usando o makefile existente, você deve primeiro cria um novo projeto selecionando o modelo de projeto MakeFile. Um assistente o ajudará a especificar os comandos e o ambiente usado pelo seu makefile. Você pode usar este projeto para criar seu código no ambiente de desenvolvimento do Visual Studio.

Por padrão, o projeto de makefile não exibe nenhum arquivo no Gerenciador de soluções. O projeto makefile Especifica as configurações de compilação, que são refletidas na página de propriedades do projeto.

O arquivo de saída que você especifica no projeto não tem efeito no nome que o script de compilação gera; ele declara apenas uma intenção. O makefile ainda controla o processo de compilação e especifica os destinos de compilação.

## <a name="to-create-a-makefile-project"></a>Para criar um projeto Makefile

1. Siga as instruções no tópico da Ajuda [criando um projeto com um Assistente de aplicativo do Visual C++](../ide/creating-desktop-projects-by-using-application-wizards.md).

1. No **novo projeto** caixa de diálogo caixa, expanda **Visual C++** > **geral** e, em seguida, selecione **projeto Makefile** do Painel de modelos para abrir o Assistente de projeto.

1. No [configurações do aplicativo](../ide/application-settings-makefile-project-wizard.md) , forneça a saída do comando, limpar e cria informações de reconstrução para depuração e varejo.

1. Clique em **concluir** para fechar o assistente e abra o projeto recém-criado no **Gerenciador de soluções**.

Você pode ver e editar as propriedades do projeto em sua página de propriedades. Consulte [configuração Visual C++ Project Properties](../ide/working-with-project-properties.md) para obter informações sobre como exibir a página de propriedades.

## <a name="see-also"></a>Consulte também

[Assistente de Projeto Makefile](../ide/makefile-project-wizard.md)<br/>
[Caracteres especiais em um makefile](../build/special-characters-in-a-makefile.md)<br/>
[Conteúdo de um makefile](../build/contents-of-a-makefile.md)<br/>
