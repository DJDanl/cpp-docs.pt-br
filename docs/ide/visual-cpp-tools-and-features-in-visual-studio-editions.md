---
title: Ferramentas do Visual C++ e recursos em edições do Visual Studio | Microsoft Docs
ms.custom: ''
ms.date: 02/28/2018
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- versions [C++]
- Visual C++, versions
- editions [C++]
ms.assetid: 3d88607b-9cc4-490a-8d4c-31ee7610a26f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a5eace3ef3cfd07847c995151554ba70ca23f820
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="visual-c-tools-and-features-in-visual-studio-editions"></a>Ferramentas do Visual C++ e recursos em edições do Visual Studio

As tabelas a seguir mostram os recursos do Visual C++ que estão disponíveis no Visual Studio. Um X em uma célula indica que o recurso está disponível. uma célula vazia indica que o recurso não está disponível. Notas entre parênteses indicam que um recurso está disponível, mas restrito.

## <a name="platforms"></a>Plataformas

||||||
|-|-|-|-|-|
|Plataforma|Visual Studio Express para Windows 10|O Visual Studio Express para Windows Desktop|Comunidade do Visual Studio/Professional|Visual Studio Enterprise|
|Área de Trabalho do Windows||X|X|X|
|Plataforma universal do Windows ((telefone, tablet, PC, Xbox, IoT e HoloLens))|X||X|X|
|Microsoft Store 8.1|||X|X|
|Windows Phone 8.0|||X|X|
|Android|||X|X|
|iOS|||X|X|

## <a name="compilers"></a>Compiladores

|Compilador|Visual Studio Express para Windows|O Visual Studio Express para Windows Desktop|O Visual Studio Professional / Community|Visual Studio Enterprise|
|--------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|X86 de 32 bits compilador|X|X|X|X|
|Compilador cruzado X86_arm|X||X|X|
|64 bits [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)] compilador|||X|X|
|X86_ [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)] compilador cruzado|X|X|X|X|

## <a name="libraries-and-headers"></a>Cabeçalhos e bibliotecas

|Biblioteca ou cabeçalho|Visual Studio Express para Windows|O Visual Studio Express para Windows Desktop|O Visual Studio Professional / Community|Visual Studio Enterprise|
|-----------------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Cabeçalhos de Windows e bibliotecas e biblioteca CRT|(X)|X|X|X|
|Biblioteca Padrão C++|X|X|X|X|
|ATL|||X|X|
|MFC|||X|X|
|Biblioteca de classes .NET Framework||X|X|X|
|Biblioteca de suporte do C++ para .NET||X|X|X|
|OpenMP|X|X|X|X|

## <a name="project-templates"></a>Modelos de projeto

|Modelo|Visual Studio Express para Windows|O Visual Studio Express para Windows Desktop|O Visual Studio Professional / Community|Visual Studio Enterprise|
|--------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Modelos XAML para UWP, Windows 8.1, Windows Phone 8.0|X||X|X|
|Aplicativo Direct3D|X||X|X|
|DLL (Universal do Windows)|X||X|X|
|Biblioteca estática (Universal do Windows)|X||X|X|
|Componente do Tempo de Execução do Windows|X||X|X|
|Aplicativo de teste de unidade (Universal do Windows)|X||X|X|
|Projeto ATL|||X|X|
|Biblioteca de classes (CLR)||X|X|X|
|Aplicativo do Console CLR||X|X|X|
|Projeto vazio do CLR||X|X|X|
|Assistente personalizado|||X|X|
|Projeto Vazio||X|X|X|
|Projeto Makefile||X|X|X|
|Controle ActiveX do MFC|||X|X|
|Aplicativo MFC|||X|X|
|DLL do MFC|||X|X|
|Projeto de Teste|X|X|X|X|
|Aplicativo do Console Win32||X|X|X|
|Projeto Win32||X|X|X|

## <a name="tools"></a>Ferramentas

|Ferramenta|Visual Studio Express para Windows|O Visual Studio Express para Windows Desktop|O Visual Studio Professional / Community|Visual Studio Enterprise|
|----------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Vinculador incremental (Link.exe)|X|X|X|X|
|Utilitário de manutenção do programa (Nmake.exe)||X|X|X|
|Gerador de lib (Lib.exe)|X|X|X|X|
|Compilador de recurso do Windows (Rc.exe)|X|X|X|X|
|Recurso do Windows para o conversor de objeto (CvtRes.exe)||X|X|X|
|Procurar o utilitário de manutenção de informações (BscMake.exe)|X|X|X|X|
|Nome em C++ Undecorator (Undname.exe)|X|X|X|X|
|Despejo COFF/PE (Dumpbin.exe)|X|X|X|X|
|Editor de COFF/PE (Editbin.exe)|X|X|X|X|
|MASM (Ml.exe)|||X|X|
|Spy++|||X|X|
|ErrLook|||X|X|
|AtlTrace|||X|X|
|Devenv.com|||X|X|
|Regras de inferência|||X|X|
|Atualizar o VCBuild. vcproj projetos MSBuild (VCUpgrade.exe)|X|X|X|X|
|Otimizações guiadas por perfil|||X|X|

## <a name="debugging-features"></a>Recursos de depuração

|Recurso de depuração|Visual Studio Express para Windows|O Visual Studio Express para Windows Desktop|O Visual Studio Professional / Community|Visual Studio Enterprise|
|-----------------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Depuração nativa|X|X|X|X|
|natvis (visualização do tipo nativo)|X|X|X|X|
|Depuração de gráficos|X||X|X|
|Depuração gerenciada||X|X|X|
|Uso de GPU|X||X|X|
|Uso de memória|X||X|X|
|Depuração remota|X|X|X|X|
|Depuração de SQL|||X|X|
|Análise de código estático|Limitado|Limitado|X|X|

## <a name="designers-and-editors"></a>Designers e editores

|Designer ou Editor|Visual Studio Express para Windows|O Visual Studio Express para Windows Desktop|O Visual Studio Professional / Community|Visual Studio Enterprise|
|------------------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|XAML Designer|X||X|X|
|Designer de estilo CSS e Editor|X|X|X|X|
|Designer de HTML e Editor|X|X|X|X|
|Editor de XML|X|X|X|X|
|Editor de código fonte|X|X|X|X|
|Recursos de produtividade: Refatoração, IntelliSense, formatação de código C++|X|X|X|X|
|Designer de Formulários do Windows||X|X|X|
|Designer de dados|||X|X|
|Editor de recurso nativo (arquivos. rc)|||X|X|
|Editores de recursos|X|X|X|X|
|Editor de modelos|X||X|X|
|Designer de sombreador|X||X|X|

## <a name="data-features"></a>Recursos de dados

|Recurso de dados|Visual Studio Express para Windows|O Visual Studio Express para Windows Desktop|O Visual Studio Professional / Community|Visual Studio Enterprise|
|------------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Designer de dados|||X|X|
|Objetos de dados|||X|X|
|Serviços Web|||X|X|
|conexões de servidor|||X|X|

## <a name="build-and-project-systems"></a>Compilação e sistemas de projeto

|Compilação ou o recurso de projeto|Visual Studio Express para Windows|O Visual Studio Express para Windows Desktop|O Visual Studio Professional / Community|Visual Studio Enterprise|
|------------------------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Compilações de linha de comando (msbuild.exe)|X|X|X|X|
|Multi-targeting nativo||X|X|X|
|Multi-targeting gerenciado||X|X|X|
|Compilações paralelas|X|X|X|X|
|Criar personalizações|X|X|X|X|
|Extensibilidade de páginas de propriedade|X|X|X|X|

## <a name="automation-and-extensibility"></a>Automação e extensibilidade

|Automação e extensibilidade|Visual Studio Express para Windows|O Visual Studio Express para Windows Desktop|O Visual Studio Professional / Community|Visual Studio Enterprise|
|----------------------------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Modelos de objeto de extensibilidade|||X|X|
|Modelo de código|||X|X|
|Modelo de Projeto|||X|X|
|Editor de recursos do modelo|||X|X|
|Assistente de modelo|||X|X|
|Modelo de objeto do depurador|||X|X|

## <a name="application-lifecycle-management-tools"></a>Ferramentas de gerenciamento de ciclo de vida do aplicativo

||||||
|-|-|-|-|-|
|Ferramenta|Visual Studio Express para Windows|O Visual Studio Express para Windows Desktop|O Visual Studio Professional / Community|Visual Studio Enterprise|
|Teste de unidade (nativo framework)|X|X|X|X|
|Teste de unidade (framework gerenciado)||X|X|X|
|Cobertura de código||||X|
|Teste manual||||X|
|Teste exploratório||||X|
|Gerenciamento de casos de teste||||X|
|Gráficos de dependência e mapa de código|||somente leitura|X|
|Depuração de mapa de código||||X|

## <a name="see-also"></a>Consulte também

[Instalar o Visual Studio](/visualstudio/install/install-visual-studio)<br/>
[O que há de novo no Visual Studio](/visualstudio/ide/whats-new-in-visual-studio)<br/>
[Tipos de projeto do Visual C++](../ide/visual-cpp-project-types.md)<br/>
[SQL Server Data Tools](https://msdn.microsoft.com/library/hh272686)<br/>
