---
title: 'Como: criar aplicativos do Console CLR (C + + / CLI) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- console applications, templates
- CLR console applications, project template
ms.assetid: e89bce3c-706f-4ae0-8a90-cb1a0f674e70
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 446ed0c6fb84990db572e1e1ead5c2ab5094ec70
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50076055"
---
# <a name="how-to-create-clr-console-applications-ccli"></a>Como criar aplicativos do console CLR (C++/CLI)

Você pode usar o modelo de aplicativo de Console para criar um projeto de aplicativo de console que já tenha arquivos e as referências de projeto essenciais.

Normalmente, um aplicativo de console é compilado em um arquivo executável autônomo, mas não tem uma interface gráfica do usuário. Um usuário executa o aplicativo de console em um prompt de comando e usar o prompt de comando para obter instruções de problema para o aplicativo em execução. Também no prompt de comando, o aplicativo fornece informações de saída. A urgência de um aplicativo de console torna uma ótima maneira de aprender técnicas de programação sem preocupação com a implementação de uma interface de usuário.

Quando você usa o modelo de aplicativo de Console para criar um projeto, ele automaticamente adiciona essas referências e arquivos:

- Referências a esses namespaces do .NET Framework:

   - [Sistema](https://msdn.microsoft.com/library/system.appdomainmanager.appdomainmanager.aspx)— contém as classes fundamentais e classes base que definem comumente usados valores e tipos de dados de referência, eventos e manipuladores de eventos, interfaces, atributos e exceções de processamento.

   - mscorlib — a DLL que oferece suporte ao desenvolvimento do .NET Framework do assembly.

- Arquivos de origem:

   - Console (arquivo. cpp), ponto de entrada e de arquivo de origem principal no aplicativo que você acabou de criar. Identifica o arquivo. dll do projeto e o namespace do projeto. Forneça seu próprio código nesse arquivo.

   - Atributos de AssemblyInfo.cpp—Contains, arquivos, recursos, tipos, informações de controle de versão, informações de assinatura e assim por diante que você pode usar para modificar metadados do assembly do projeto. Para obter mais informações, consulte [conteúdo do Assembly](/dotnet/framework/app-domains/assembly-contents).

   - Stdafx.cpp—Used para criar um arquivo de cabeçalho pré-compilado que é denominado Win32.pch e um arquivo de tipos precompilados chamado Stdafx. obj.

- Arquivos de cabeçalho:

   - Stdafx.h—Used para criar um arquivo de cabeçalho pré-compilado que é denominado Win32.pch e um arquivo de tipos precompilados chamado Stdafx. obj.

   - Resource.h—A gerado incluir arquivo para app.rc.

- Arquivos de recurso:

   - arquivo de script de recurso App.rc—the de um programa.

   - arquivo de ícone App.ico—the de um programa.

- ReadMe.txt—Describes os arquivos no projeto.

## <a name="to-create-a-common-language-runtime-clr-console-app-project"></a>Para criar um projeto de aplicativo de console do common language runtime (CLR)

1. Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto**.

1. No **novo projeto** caixa de diálogo **modelos instalados**, selecione o **Visual C++** nó, selecione o **CLR** nó e, em seguida, selecione o modelo de aplicativo de Console.

1. No **nome** , digite um nome exclusivo para seu aplicativo.

   Você pode especificar outras configurações de projeto e solução, mas eles não são necessários.

1. Escolha o botão **OK**.

## <a name="see-also"></a>Consulte também

[Projetos CLR](../ide/files-created-for-clr-projects.md)

