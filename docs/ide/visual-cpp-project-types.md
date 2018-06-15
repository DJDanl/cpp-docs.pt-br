---
title: Tipos de projeto do Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 10/30/2017
ms.technology:
- cpp-ide
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 80ac3479338dcb7f6be9e7e5f3f150cc8e15a9a9
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33339976"
---
# <a name="visual-c-project-types"></a>Tipos de projeto do Visual C++

Você pode usar um modelo de projeto para criar a estrutura básica do programa, menus, barras de ferramentas, ícones, referências e instruções `#include` que sejam apropriadas para o tipo de projeto que você deseja criar. O Visual Studio inclui vários tipos de modelos de projeto do Visual C++ e fornece assistentes para muitos deles, de modo que você pode personalizar seus projetos conforme os cria. Imediatamente depois de criar um projeto, você pode compilá-lo e executar o aplicativo; é uma boa prática compilar o projeto de forma intermitente durante o desenvolvimento do aplicativo.

Você não precisa usar um modelo para criar um projeto, mas na maioria dos casos é mais eficiente fazê-lo, porque é mais fácil modificar os arquivos de projeto fornecidos e estruturá-los do que criá-los a partir do zero.  
  
> [!NOTE]
> Você pode criar um projeto de linguagem C, utilizando modelos de projeto C++. No projeto gerado, localize os arquivos que têm uma extensão de nome de arquivo .cpp e mude para .c. Em seguida, na página **Propriedades do Projeto** do projeto (não da solução), expanda **Propriedades de Configuração**, **C/C++** e selecione **Avançado**. Altere as configurações de **Compilar como** para **Compilar como Código C (/TC)**.

## <a name="project-templates"></a>Modelos de projeto

Os modelos de projeto incluídos no Visual Studio dependem da versão do produto e das cargas de trabalho instaladas. Se você instalou a carga de trabalho Desenvolvimento para desktop com C++, isso significa que o Visual Studio tem esses modelos de projeto do Visual C++.

### <a name="windows-desktop"></a>Área de Trabalho do Windows

|Modelo de projeto|Descrição|  
|----------------------|-----------------------------| 
|[Aplicativo de Console do Windows](../windows/creating-a-console-application.md)|Um projeto para a criação de um aplicativo de console do Windows.|
|[Aplicativo da Área de Trabalho do Windows](../windows/walkthrough-creating-windows-desktop-applications-cpp.md)|Um projeto para a criação de um aplicativo da área de trabalho do Windows (Win32).|
|[Biblioteca de Vínculo Dinâmico](../build/walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)|Um projeto para a criação de uma DLL (biblioteca de vínculo dinâmico).|
|[Biblioteca Estática](../windows/walkthrough-creating-and-using-a-static-library-cpp.md)|Um projeto para a criação de uma LIB (biblioteca estática).|
|Assistente da Área de Trabalho do Windows|Um assistente para a criação de aplicativos da área de trabalho do Windows e bibliotecas com opções adicionais.|

### <a name="general"></a>Geral

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|Projeto Vazio|Um projeto vazio para a criação de um aplicativo, uma biblioteca ou uma DLL. É necessário adicionar o código ou os recursos necessários.|
|[Projeto Makefile](../ide/creating-a-makefile-project.md)|Um projeto para o uso de um sistema de build externo.|
|Projeto Itens Compartilhados|Um projeto usado para compartilhar arquivos entre vários projetos.|

### <a name="atl"></a>ATL

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|[Projeto ATL](../atl/reference/creating-an-atl-project.md)|Um projeto que usa a Active Template Library.|

### <a name="test"></a>Teste

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|[Projeto de Teste de Unidade Nativo](/visualstudio/test/writing-unit-tests-for-c-cpp-with-the-microsoft-unit-testing-framework-for-cpp)|Um projeto que contém testes de unidade do C++ nativo.|

### <a name="mfc"></a>MFC

Se você adicionar o componente de suporte para MFC e ATL à instalação do Visual Studio, esses modelos de projeto serão adicionados ao Visual Studio.

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|[Aplicativo MFC](../mfc/reference/creating-an-mfc-application.md)|Um projeto para a criação de um aplicativo que usa a Biblioteca MFC (Microsoft Foundation Class).|
|[Controle ActiveX do MFC](../mfc/reference/creating-an-mfc-activex-control.md)|Um projeto para a criação de um controle ActiveX que usa a biblioteca MFC.|
|[DLL do MFC](../mfc/reference/creating-an-mfc-dll-project.md)|Um projeto para a criação de uma biblioteca de vínculo dinâmico que usa a biblioteca MFC.|

### <a name="windows-universal-apps"></a>Aplicativos Universais para Windows

Se você adicionar o componente de ferramentas da Plataforma Universal do Windows do C++ à instalação do Visual Studio, esses modelos de projeto serão adicionados ao Visual Studio.

Para obter uma visão geral dos aplicativos Universais do Windows no C++, confira [Aplicativos Universais do Windows (C++)](../windows/universal-windows-apps-cpp.md).

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|Aplicativo em Branco|Um projeto para um aplicativo UWP (Plataforma Universal do Windows) de página única que não tem layout nem controles predefinidos.|
|Aplicativo DirectX 11|Um projeto para um aplicativo da Plataforma Universal do Windows que usa o DirectX 11.|
|Aplicativo DirectX 12|Um projeto para um aplicativo da Plataforma Universal do Windows que usa o DirectX 12.|
|Aplicativo DirectX 11 e XAML|Um projeto para um aplicativo da Plataforma Universal do Windows que usa o DirectX 11 e o XAML.|
|Aplicativo de Teste de Unidade|Um projeto para a criação de um aplicativo de teste de unidade para aplicativos UWP (Plataforma Universal do Windows).|
|DLL|Um projeto para uma DLL (biblioteca de vínculo dinâmico) nativa que pode ser usada por um aplicativo da Plataforma Universal do Windows ou um componente do tempo de execução.|
|Biblioteca Estática|Um projeto para uma LIB (biblioteca de vínculo estático) nativa que pode ser usada por um aplicativo da Plataforma Universal do Windows ou um componente do tempo de execução.|
|Componente do Tempo de Execução do Windows|Um projeto para um componente do Tempo de Execução do Windows que pode ser usado por um aplicativo da Plataforma Universal do Windows, seja qual for a linguagem de programação na qual o aplicativo é escrito.|
|Projeto de Empacotamento de Aplicativos do Windows|Um projeto que cria um pacote UWP, permitindo que um aplicativo da área de trabalho seja carregado por sideload ou distribuído por meio da Microsoft Store.|

## <a name="todo-comments"></a>Comentários TODO

Muitos dos arquivos gerados por um modelo de projeto contêm comentários TODO para ajudar a identificar onde você pode fornecer seu próprio código-fonte. Para obter mais informações sobre como adicionar um código, confira [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md) e [Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md).

## <a name="see-also"></a>Consulte também

[Criando projetos para área de trabalho com Assistentes de Aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md)   
