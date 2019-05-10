---
title: Tipos de projeto do Visual C++
ms.date: 11/29/2018
helpviewer_keywords:
- programs [C++], projects
- project templates [Visual Studio], C++
- TODO comments [C++]
- projects [C++], types
- templates [C++], projects
- applications [C++], projects
- C++ projects, types
ms.assetid: 7337987e-1e7b-4120-9a4b-94f0401f15e7
ms.openlocfilehash: dce96a221804e5538929d63fa3c125a27e7fc36d
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65217779"
---
# <a name="c-project-templates"></a>Modelos de projeto C++

Modelos de projeto do Visual Studio geram arquivos de código-fonte, opções do compilador, menus, barras de ferramentas, ícones, referências, e `#include` instruções que são apropriadas para o tipo de projeto que você deseja criar. O Visual Studio inclui vários tipos de C++ modelos de projeto e fornece assistentes para muitos deles, para que você possa personalizar seus projetos conforme você criá-los. Imediatamente depois de criar um projeto, você pode compilá-lo e executar o aplicativo; é uma boa prática compilar o projeto de forma intermitente durante o desenvolvimento do aplicativo.

> [!NOTE]
> Você pode criar um projeto de linguagem C, utilizando modelos de projeto C++. No projeto gerado, localize os arquivos que têm uma extensão de nome de arquivo .cpp e mude para .c. Em seguida, na página **Propriedades do Projeto** do projeto (não da solução), expanda **Propriedades de Configuração**, **C/C++** e selecione **Avançado**. Altere as configurações de **Compilar como** para **Compilar como Código C (/TC)**.

## <a name="project-templates"></a>Modelos de projeto

Os modelos de projeto incluídos no Visual Studio dependem da versão do produto e das cargas de trabalho instaladas. Se você tiver instalado o desenvolvimento para Desktop com C++ carga de trabalho, o Visual Studio possui os seguintes C++ modelos de projeto.

### <a name="windows-desktop"></a>Área de Trabalho do Windows

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|[Aplicativo de Console do Windows](../../windows/creating-a-console-application.md)|Um projeto para a criação de um aplicativo de console do Windows.|
|[Aplicativo da Área de Trabalho do Windows](../../windows/walkthrough-creating-windows-desktop-applications-cpp.md)|Um projeto para a criação de um aplicativo da área de trabalho do Windows (Win32).|
|[Biblioteca de Vínculo Dinâmico](../walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)|Um projeto para a criação de uma DLL (biblioteca de vínculo dinâmico).|
|[Biblioteca Estática](../../windows/walkthrough-creating-and-using-a-static-library-cpp.md)|Um projeto para a criação de uma LIB (biblioteca estática).|
|Assistente da Área de Trabalho do Windows|Um assistente para a criação de aplicativos da área de trabalho do Windows e bibliotecas com opções adicionais.|

### <a name="general"></a>Geral

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|Projeto Vazio|Um projeto vazio para a criação de um aplicativo, uma biblioteca ou uma DLL. É necessário adicionar o código ou os recursos necessários.|
|[Projeto Makefile](creating-a-makefile-project.md)|Um projeto que encapsula um makefile do Windows em um projeto do Visual Studio. (Para abrir um makefile como-está no Visual Studio, use [Abrir pasta](../open-folder-projects-cpp.md).|
|Projeto Itens Compartilhados|Um projeto usado para o compartilhamento de arquivos de código ou arquivos de recursos entre vários projetos. Esse tipo de projeto não produz um arquivo executável.|

### <a name="atl"></a>ATL

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|[Projeto ATL](../../atl/reference/creating-an-atl-project.md)|Um projeto que usa a Active Template Library.|

### <a name="test"></a>Teste

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|[Projeto de Teste de Unidade Nativo](/visualstudio/test/writing-unit-tests-for-c-cpp-with-the-microsoft-unit-testing-framework-for-cpp)|Um projeto que contém testes de unidade do C++ nativo.|

### <a name="mfc"></a>MFC

Se você adicionar o componente de suporte para MFC e ATL à instalação do Visual Studio, esses modelos de projeto serão adicionados ao Visual Studio.

|Modelo de projeto|Descrição|
|----------------------|-----------------------------|
|[Aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md)|Um projeto para a criação de um aplicativo que usa a Biblioteca MFC (Microsoft Foundation Class).|
|[Controle ActiveX do MFC](../../mfc/reference/creating-an-mfc-activex-control.md)|Um projeto para a criação de um controle ActiveX que usa a biblioteca MFC.|
|[DLL do MFC](../../mfc/reference/creating-an-mfc-dll-project.md)|Um projeto para a criação de uma biblioteca de vínculo dinâmico que usa a biblioteca MFC.|

### <a name="windows-universal-apps"></a>Aplicativos Universais para Windows

Se você adicionar o componente de ferramentas da Plataforma Universal do Windows do C++ à instalação do Visual Studio, esses modelos de projeto serão adicionados ao Visual Studio.

Para obter uma visão geral dos aplicativos Universais do Windows no C++, confira [Aplicativos Universais do Windows (C++)](../../windows/universal-windows-apps-cpp.md).

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

Muitos dos arquivos gerados por um modelo de projeto contêm comentários TODO para ajudar a identificar onde você pode fornecer seu próprio código-fonte. Para obter mais informações sobre como adicionar um código, confira [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md) e [Trabalhando com arquivos de recurso](../../windows/working-with-resource-files.md).


