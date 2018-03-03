---
title: Tipos de projeto do Visual C++ | Microsoft Docs
ms.custom: 
ms.date: 10/30/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- programs [C++], projects
- project templates [Visual Studio], C++
- TODO comments [C++]
- projects [C++], types
- templates [C++], projects
- applications [C++], projects
- Visual C++ projects, types
ms.assetid: 7337987e-1e7b-4120-9a4b-94f0401f15e7
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a837aa04b0e0c2b8d3d9f5cfd48181a9ea23b346
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="visual-c-project-types"></a>Tipos de projeto do Visual C++

Você pode usar um modelo de projeto para criar a estrutura básica do programa, menus, barras de ferramentas, ícones, referências e instruções `#include` que sejam apropriadas para o tipo de projeto que você deseja criar. O Visual Studio inclui vários tipos de modelos de projeto do Visual C++ e fornece assistentes para muitos deles, de modo que você pode personalizar seus projetos conforme os cria. Imediatamente depois de criar um projeto, você pode compilar e executar o aplicativo. é recomendável criar intermitentemente à medida que desenvolve seu aplicativo.

Você não precisa usar um modelo para criar um projeto, mas na maioria dos casos é mais eficiente fazê-lo, porque é mais fácil modificar os arquivos de projeto fornecidos e estruturá-los do que criá-los a partir do zero.  
  
> [!NOTE]
> Você pode criar um projeto de linguagem C, utilizando modelos de projeto C++. No projeto gerado, localize os arquivos que têm uma extensão de nome de arquivo .cpp e mude para .c. Em seguida, no **propriedades do projeto** página para o projeto (não para a solução), expanda **propriedades de configuração**, **C/C++** e selecione **avançado**. Alterar o **compilar como** definindo como **compilar como código C (/ TC)**.

## <a name="project-templates"></a>Modelos de projeto

Os modelos de projeto incluídos no Visual Studio dependem da versão do produto e as cargas de trabalho que você instalou. Se você tiver instalado o desenvolvimento de área de trabalho com carga de trabalho do C++, Visual Studio tem esses modelos de projeto do Visual C++.

### <a name="windows-desktop"></a>Área de Trabalho do Windows

|Modelo de projeto|Descrição|  
|----------------------|-----------------------------| 
|[Aplicativo de Console do Windows](../windows/creating-a-console-application.md)|Um projeto para criar um aplicativo de console do Windows.|
|[Aplicativo de área de trabalho do Windows](../windows/walkthrough-creating-windows-desktop-applications-cpp.md)|Um projeto para criar um aplicativo de área de trabalho (Win32) do Windows.|
|[Biblioteca de vínculo dinâmico](../build/walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)|Um projeto para criar uma biblioteca de vínculo dinâmico (DLL).|
|[Biblioteca estática](../windows/walkthrough-creating-and-using-a-static-library-cpp.md)|Um projeto para criar uma biblioteca estática (LIB).|
|Assistente de área de trabalho do Windows|Um Assistente para criar aplicativos de área de trabalho do Windows e bibliotecas com opções adicionais.|

### <a name="general"></a>Geral

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|Projeto Vazio|Um projeto vazio para criar um aplicativo, uma biblioteca ou uma DLL. Você deve adicionar qualquer código ou os recursos necessários.|
|[Projeto makefile](../ide/creating-a-makefile-project.md)|Sistema de compilação de um projeto para uso externo.|
|Itens de projeto compartilhado|Um projeto usado para compartilhar arquivos entre vários projetos.|

### <a name="atl"></a>ATL

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|[Projeto ATL](../atl/reference/creating-an-atl-project.md)|Um projeto que usa o Active Template Library.|

### <a name="test"></a>Teste

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|[Projeto de teste de unidade nativa](/visualstudio/test/writing-unit-tests-for-c-cpp-with-the-microsoft-unit-testing-framework-for-cpp)|Um projeto que contém testes de unidade C++ nativo.|

### <a name="mfc"></a>MFC

Se você adicionar que o MFC e ATL oferecem suporte ao componente de instalação do Visual Studio, esses modelos de projeto são adicionados ao Visual Studio.

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|[Aplicativo MFC](../mfc/reference/creating-an-mfc-application.md)|Um projeto para criar um aplicativo que usa a biblioteca Microsoft Foundation Class (MFC).|
|[Controle ActiveX MFC](../mfc/reference/creating-an-mfc-activex-control.md)|Um projeto para criar um controle ActiveX que usa a biblioteca do MFC.|
|[DLL DO MFC](../mfc/reference/creating-an-mfc-dll-project.md)|Um projeto para criar uma biblioteca de vínculo dinâmico que usa a biblioteca do MFC.|

### <a name="windows-universal-apps"></a>Aplicativos universais do Windows

Se você adicionar o componente de ferramentas da plataforma Universal do Windows de C++ para a instalação do Visual Studio, esses modelos de projeto são adicionados ao Visual Studio.

Para obter uma visão geral de aplicativos Universal do Windows em C++, consulte [aplicativos de Windows Universal (C++)](../windows/universal-windows-apps-cpp.md).

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|Aplicativo em Branco|Um projeto para um aplicativo do Windows UWP (plataforma Universal) de uma página que não tem controles predefinidos ou layout.|
|Aplicativo DirectX 11|Um projeto para um aplicativo de plataforma Universal do Windows que usa DirectX 11.|
|Aplicativo DirectX 12|Um projeto para um aplicativo de plataforma Universal do Windows que usa o DirectX 12.|
|Aplicativo DirectX 11 e XAML|Um projeto para um aplicativo de plataforma Universal do Windows que usa DirectX 11 e XAML.|
|Aplicativo de teste de unidade|Um projeto para criar um aplicativo de teste de unidade para aplicativos do Windows UWP (plataforma Universal).|
|DLL|Um projeto para uma biblioteca de vínculo dinâmico (DLL) nativa que pode ser usado por um componente de aplicativo ou tempo de execução de plataforma Universal do Windows.|
|Biblioteca estática|Um projeto para uma biblioteca de vínculo estático nativo (LIB) que pode ser usado por um componente de aplicativo ou tempo de execução de plataforma Universal do Windows.|
|Componente do Tempo de Execução do Windows|Um projeto para um componente de tempo de execução do Windows que pode ser usado por um aplicativo de plataforma Universal do Windows, independentemente da linguagem de programação na qual o aplicativo é escrito.|
|Projeto de empacotamento de aplicativo do Windows|Um projeto que cria um pacote UWP que permite que um aplicativo da área de trabalho ser carregado lado ou distribuídos por meio da Microsoft Store.|

## <a name="todo-comments"></a>Comentários TODO

Muitos dos arquivos gerados por um modelo de projeto contêm comentários TODO para ajudar a identificar onde você pode fornecer seu próprio código-fonte. Para obter mais informações sobre como adicionar código, consulte [adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md) e [trabalhando com arquivos de recurso](../windows/working-with-resource-files.md).

## <a name="see-also"></a>Consulte também

[Criando projetos para área de trabalho com Assistentes de Aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md)   
