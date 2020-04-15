---
title: Como criar aplicativos do console CLR (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- console applications, templates
- CLR console applications, project template
ms.assetid: e89bce3c-706f-4ae0-8a90-cb1a0f674e70
ms.openlocfilehash: 86e5abe330b0edc514fed74a12188ab73e8bfdd8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368532"
---
# <a name="how-to-create-clr-console-applications-ccli"></a>Como criar aplicativos do console CLR (C++/CLI)

Você pode usar o modelo de Aplicativo de Console para criar um projeto de aplicativo de console que já tenha referências e arquivos essenciais do projeto.

Normalmente, um aplicativo de console é compilado em um arquivo executável autônomo, mas não tem uma interface gráfica do usuário. Um usuário executa o aplicativo do console em um prompt de comando e usa o prompt de comando para emitir instruções para o aplicativo em execução. Também no prompt de comando, o aplicativo fornece informações de saída. O imediatismo de um aplicativo de console torna-o uma ótima maneira de aprender técnicas de programação sem preocupação em implementar uma interface de usuário.

Quando você usa o modelo de aplicativo de console para criar um projeto, ele adiciona automaticamente essas referências e arquivos:

- Referências a esses namespaces do .NET Framework:

  - <xref:System.AppDomainManager>— Contém classes e classes básicas fundamentais que definem valores e tipos de dados de referência comumente usados, manipuladores de eventos e eventos, interfaces, atributos e exceções de processamento.

  - mscorlib — O Conjunto DLL que suporta o desenvolvimento do .NET Framework.

- Arquivos de origem:

  - Console (arquivo.cpp)— O arquivo principal de origem e o ponto de entrada no aplicativo que você acabou de criar. Ele identifica o arquivo project .dll e o namespace do projeto. Forneça seu próprio código nesse arquivo.

  - AssemblyInfo.cpp — Contém atributos, arquivos, recursos, tipos, informações de versão, informações de assinatura e assim por diante que você pode usar para modificar os metadados de montagem do projeto. Para obter mais informações, consulte [Conteúdo de montagem](/dotnet/framework/app-domains/assembly-contents).

  - Stdafx.cpp — Usado para construir um arquivo de cabeçalho pré-compilado chamado Win32.pch e um arquivo de tipos pré-compilado saudoso chamado StdAfx.obj.

- Arquivos de cabeçalho:

  - Stdafx.h — Usado para construir um arquivo de cabeçalho pré-compilado chamado Win32.pch e um arquivo de tipos pré-compilado saudoso chamado StdAfx.obj.

  - resource.h — Um arquivo gerado inclua para app.rc.

- Arquivos de recurso:

  - app.rc — O arquivo de script de recurso de um programa.

  - app.ico — O arquivo ícone de um programa.

- ReadMe.txt — Descreve os arquivos do projeto.

## <a name="to-create-a-common-language-runtime-clr-console-app-project"></a>Para criar um projeto de aplicativo de console de tempo de execução de idioma comum (CLR)

1. Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto**.

1. Na caixa de diálogo **Novo Projeto,** em **Modelos instalados,** selecione o nó **Visual C++,** selecione o nó **CLR** e selecione o modelo de aplicativo do console.

1. Na caixa **Nome,** digite um nome exclusivo para sua aplicação.

   Você pode especificar outras configurações de projeto e solução, mas elas não são necessárias.

1. Clique no botão **OK**.

## <a name="see-also"></a>Confira também

[Projetos CLR](../build/reference/files-created-for-clr-projects.md)
