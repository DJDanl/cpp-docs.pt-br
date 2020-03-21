---
title: Como criar aplicativos do console CLR (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- console applications, templates
- CLR console applications, project template
ms.assetid: e89bce3c-706f-4ae0-8a90-cb1a0f674e70
ms.openlocfilehash: 610efc8b0780422fc89e3bf9708ba488fe7d1f47
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80080059"
---
# <a name="how-to-create-clr-console-applications-ccli"></a>Como criar aplicativos do console CLR (C++/CLI)

Você pode usar o modelo de aplicativo de console para criar um projeto de aplicativo de console que já tenha arquivos e referências de projeto essenciais.

Normalmente, um aplicativo de console é compilado em um arquivo executável autônomo, mas não tem uma interface gráfica do usuário. Um usuário executa o aplicativo de console em um prompt de comando e usa o prompt de comando para emitir instruções para o aplicativo em execução. Além disso, no prompt de comando, o aplicativo fornece informações de saída. O imediata de um aplicativo de console torna uma ótima maneira de aprender técnicas de programação sem preocupação com a implementação de uma interface do usuário.

Quando você usa o modelo de aplicativo de console para criar um projeto, ele adiciona automaticamente essas referências e arquivos:

- Referências a esses namespaces de .NET Framework:

   - <xref:System.AppDomainManager>— contém classes fundamentais e classes base que definem valores comumente usados e tipos de dados de referência, eventos e manipuladores de eventos, interfaces, atributos e exceções de processamento.

   - mscorlib — a DLL do assembly que dá suporte ao desenvolvimento de .NET Framework.

- Arquivos de origem:

   - Console (arquivo. cpp) — o principal arquivo de origem e o ponto de entrada no aplicativo que você acabou de criar. Ele identifica o arquivo Project. dll e o namespace do projeto. Forneça seu próprio código nesse arquivo.

   - AssemblyInfo. cpp — contém atributos, arquivos, recursos, tipos, informações de controle de versão, informações de assinatura e assim por diante que você pode usar para modificar os metadados do assembly do projeto. Para obter mais informações, consulte [conteúdo do assembly](/dotnet/framework/app-domains/assembly-contents).

   - Stdafx. cpp — usado para criar um arquivo de cabeçalho pré-compilado chamado Win32. pch e um arquivo de tipos pré-compilado chamado StdAfx. obj.

- Arquivos de cabeçalho:

   - Stdafx. h — usado para criar um arquivo de cabeçalho pré-compilado chamado Win32. pch e um arquivo de tipos pré-compilado chamado StdAfx. obj.

   - Resource. h — um arquivo de inclusão gerado para app. rc.

- Arquivos de recurso:

   - App. rc — o arquivo de script de recurso de um programa.

   - App. ico — o arquivo de ícone de um programa.

- ReadMe. txt — descreve os arquivos no projeto.

## <a name="to-create-a-common-language-runtime-clr-console-app-project"></a>Para criar um projeto de aplicativo de console Common Language Runtime (CLR)

1. Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto**.

1. Na caixa de diálogo **novo projeto** , em **modelos instalados**, selecione o **nó C++ Visual** , selecione o nó **CLR** e, em seguida, selecione o modelo aplicativo de console.

1. Na caixa **nome** , insira um nome exclusivo para seu aplicativo.

   Você pode especificar outras configurações de projeto e solução, mas elas não são necessárias.

1. Escolha o botão **OK** .

## <a name="see-also"></a>Confira também

[Projetos CLR](../build/reference/files-created-for-clr-projects.md)
