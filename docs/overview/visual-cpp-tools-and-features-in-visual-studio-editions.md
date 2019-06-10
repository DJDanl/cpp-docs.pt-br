---
title: Ferramentas e recursos do C++ em edições do Visual Studio
ms.date: 05/21/2019
helpviewer_keywords:
- tools and platforms [C++]
ms.assetid: 3d88607b-9cc4-490a-8d4c-31ee7610a26f
ms.openlocfilehash: c5c0459888f8787fd8abba495395130d64a193e0
ms.sourcegitcommit: bde3279f70432f819018df74923a8bb895636f81
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/23/2019
ms.locfileid: "66182906"
---
# <a name="c-tools-and-features-in-visual-studio-editions"></a>Ferramentas e recursos do C++ em edições do Visual Studio


::: moniker range=">=vs-2019"


Os recursos do C++ a seguir estão disponíveis no Visual Studio 2019. A menos que indicado de outra forma, todos os recursos estão disponíveis em todas as edições: Visual Studio Community, Visual Studio Professional e Visual Studio Enterprise. Alguns recursos exigem cargas de trabalho específicas ou componentes opcionais, que você pode instalar com o Instalador do Visual Studio.

## <a name="platforms"></a>Plataformas

- Área de Trabalho do Windows
- Plataforma Universal do Windows ((tablet, computador, Xbox, IoT e HoloLens))
- Linux
- Android
- iOS

## <a name="compilers"></a>Compiladores

- Compilador MSVC de 32 bits para x86, x64, ARM e ARM64
- Compilador MSVC de 64 bits para x86, x64, ARM e ARM64
- Compilador cruzado GCC para ARM
- Clang/LLVM
  - No Windows, Clang/LLVM 7.0, direcionando x86 ou x64 (somente suporte a CMake). Outras versões do Clang poderiam funcionar, mas não há suporte oficial para elas.
  - No Linux, há suporte a qualquer instalação do Clang/LLVM pela distribuição.
 
## <a name="c-workloads"></a>Cargas de trabalho do C++

O Visual Studio inclui as seguintes cargas de trabalho para desenvolvimento do C++. É possível instalar qualquer uma ou todas elas juntamente com outras cargas de trabalho como Desenvolvimento para Desktop do .NET, Desenvolvimento do Python, Desenvolvimento do Azure, Desenvolvimento de Extensão do Visual Studio e outros.

### <a name="desktop-development-with-c"></a>Desenvolvimento de área de trabalho com o C++

Incluído:
- Principais recursos de área de trabalho do C++

Componentes opcionais:
- MSVC v142 – ferramentas de build do C++ para VS 2019 x64/x86 (v14.21)
- SDK do Windows 10 (10.0.17763.0)
- Depurador Just-In-Time
- Ferramentas de criação de perfil do C++
- Ferramentas CMake do C++ para Windows
- ATL do C++ para ferramentas de build v142 (x86 e x64)
- Adaptador de Teste para Boost.Test
- Adaptador de Teste para Google Test
- Live Share
- IntelliCode
- IntelliTrace (somente Enterprise)
- MFC do C++ para ferramentas de build v142 (x86 e x64)
- Suporte do C++/CLI para ferramentas de build v142 (14.21)
- Módulos do C++ para ferramentas de build v142 (x64/x86 – experimental)
- Compilador do Clang para Windows
- IncrediBuild - Aceleração de Build
- SDK do Windows 10 (10.0.17134.0)
- SDK do Windows 10 (10.0.16299.0)
- MSVC v141 – ferramentas de build do C++ para VS 2017 x64/x86 (v14.16)
- MSVC v140 – ferramentas de build do C++ para VS 2015 (v14.00)

### <a name="linux-development-with-c"></a>Desenvolvimento de Linux com C++

Incluído:
- Funcionalidades principais do C++
- Tempo de execução C Universal do Windows
- Desenvolvimento do C++ para Linux

Componentes opcionais:
- Ferramentas CMake do C++ para Linux
- Ferramentas de desenvolvimento inseridas e de IoT

### <a name="universal-windows-platform-development"></a>Desenvolvimento na Plataforma Universal do Windows

Incluído:
- Blend for Visual Studio
- .NET Native e .NET Standard
- Gerenciador de pacotes NuGet
- Ferramentas da Plataforma Universal do Windows
- SDK do Windows 10 (10.0.17763.0)

Componentes opcionais:
- IntelliCode
- IntelliTrace (somente Enterprise)
- Conectividade de dispositivos USB
- Ferramentas da Plataforma Universal do Windows do C++ (v142)
- Ferramentas da Plataforma Universal do Windows do C++ (v141)
- Depurador de gráficos e criador de perfil de GPU do DirectX
- SDK do Windows 10 (10.0.18362.0)
- SDK do Windows 10 (10.0.17134.0)
- SDK do Windows 10 (10.0.16299.0)
- Ferramentas de arquitetura e análise

### <a name="c-game-development"></a>Desenvolvimento de jogos do C++

Incluído:
- Funcionalidades principais do C++
- Tempo de execução C Universal do Windows
- Atualização dos Pacotes Redistribuíveis do C++ 2019
- MSVC v142 – ferramentas de build do C++ para VS 2019 x64/x86 (v14.21)

Componentes opcionais:
- Ferramentas de criação de perfil do C++
- SDK do Windows 10 (10.0.17763.0)
- IntelliCode
- IntelliTrace (somente Enterprise)
- SDK do Windows 10 (10.0.17134.0)
- SDK do Windows 10 (10.0.16299.0)
- IncrediBuild - Aceleração de Build
- Cocos
- Instalador do Unreal Engine
- Suporte do IDE do Android para Unreal Engine

### <a name="mobile-development-with-c"></a>Desenvolvimento móvel com C++

Incluído:
- Funcionalidades principais do C++
- Instalação do SDK do Android (nível da API 25) (instalação local para Desenvolvimento Móvel com C++)

Componentes opcionais:
- NDK do Android (R16B)
- Apache Ant (1.9.3)
- Ferramentas de desenvolvimento do Android para C++
- IntelliCode
- Google Android Emulator (Nível da API 25) (instalação local)
- Intel HAXM (Hardware Accelerated Execution Manager) (instalação local)
- NDK do Android (R16B) (32 bits)
- Ferramentas de desenvolvimento do iOS para C++
- IncrediBuild - Aceleração de Build


## <a name="individual-components"></a>Componentes individuais

É possível instalar esses componentes independentemente de qualquer carga de trabalho.

- Diagnóstico do JavaScript
- Live Share
- Tempo de execução da Plataforma Universal do Windows do C++ para ferramentas de build v142
- Publicação ClickOnce
- Projetos do Instalador do Microsoft Visual Studio

## <a name="libraries-and-headers"></a>Bibliotecas e cabeçalhos

- Cabeçalhos e bibliotecas do Windows
- CRT (Tempo de execução C) Universal do Windows
- Biblioteca Padrão C++
- ATL
- MFC
- Biblioteca de classes .NET Framework
- Biblioteca de suporte do C++ para .NET
- OpenMP 2.0
- Mais de 900 bibliotecas open-source por meio do catálogo de vcpkg

## <a name="build-and-project-systems"></a>Sistemas de build e de projeto

- CMake
- Qualquer sistema de build por meio de Abrir Pasta
- Builds de linha de comando (msbuild.exe)
- Multiplataforma nativa
- Multiplataforma gerenciada
- Builds paralelos
- Personalizações de build
- Extensibilidade de páginas de propriedades

## <a name="project-templates"></a>Modelos de projeto

Os seguintes modelos de projeto estão disponíveis dependendo de quais cargas de trabalho você instalou.

Área de Trabalho do Windows:
- Projeto Vazio
- Aplicativo de console
- Assistente da Área de Trabalho do Windows
- Aplicativo da Área de Trabalho do Windows
- Projeto Itens Compartilhados
- Aplicativo do MFC
- Biblioteca de vínculo dinâmico
- Projeto CLR Vazio
- Aplicativo de console do CLR
- Biblioteca Estática
- Projeto do CMake
- Projeto ATL
- Biblioteca de vínculo dinâmico do MFC
- Biblioteca de classes do CLR
- Projeto Makefile (Windows)
- ActiveXControl do MFC
- Projeto de teste de unidade nativo
- Google Test

Plataforma Universal do Windows (C++/CX):
- Aplicativo em Branco
- Aplicativo DirectX 11 e XAML
- Aplicativo DirectX 11
- Aplicativo DirectX 12 
- Aplicativo de Teste de Unidade 
- DLL 
- Componente do Tempo de Execução do Windows 
- Biblioteca Estática 
- Projeto de Empacotamento de Aplicativos do Windows

Linux:
- Aplicativo de console (Linux)
- Projeto vazio (Linux)
- Raspberry Pi Blink
- Projeto Makefile (Linux)

## <a name="tools"></a>Ferramentas

- Vinculador Incremental (Link.exe)
- Utilitário do Microsoft Makefile (Nmake.exe)
- Gerador de Lib (Lib.exe)
- Compilador de Recurso do Windows (Rc.exe)
- Recurso do Windows para Conversor de Objeto (CvtRes.exe)
- Utilitário de Manutenção de Informações de Procura (BscMake.exe)
- Removedor de Decoração de Nomes do C++ (Undname.exe)
- Despejo de COFF/PE (Dumpbin.exe)
- Editor de COFF/PE (Editbin.exe)
- MASM (Ml.exe)
- Spy++
- ErrLook
- AtlTrace
- Regras de inferência
- Otimizações guiadas por perfil

## <a name="debugging-features"></a>Funcionalidades de depuração

- Depuração nativa
- natvis (visualização nativa de tipo)
- Depuração de gráficos
- Depuração gerenciada
- Uso de GPU
- Uso de memória
- Depuração remota
- Depuração SQL
- Análise de código estático

## <a name="designers-and-editors"></a>Designers e Editores

- XAML Designer
- Designer/Editor de Estilo CSS
- Designer/Editor de HTML
- Editor de XML
- Editor de Código-fonte
- Recursos de produtividade: Refatoração, mecanismo IntelliSense EDG, Formatação de código do C++
- Designer de Formulários do Windows
- Designer de dados
- Editor de Recurso Nativo (arquivos .rc)
- Editores de recursos
- Editor de modelos
- Designer de sombreador
- Validação de dependência dinâmica (somente Enterprise)
- Diagramas de camada de arquitetura (somente Enterprise)
- Validação de arquitetura (somente Enterprise)
- Clone de código (somente Enterprise)

## <a name="data-features"></a>Funcionalidades de dados

- Designer de dados
- Objetos de dados
- Serviços Web
- conexões de servidor

## <a name="automation-and-extensibility"></a>Automação e extensibilidade

- Modelos de objeto de extensibilidade
- Modelo de código
- Modelo de Projeto
- Modelo de editor de recursos
- Modelo de assistente
- Modelo de objeto do depurador

## <a name="application-lifecycle-management-tools"></a>Ferramentas de gerenciamento de ciclo de vida do aplicativo

- Teste de Unidade (Microsoft Native C++, Boost.Test, Google Test, CTest)
- Mapa de códigos e grafos de dependência (Professional e Enterprise)
- Cobertura de código (somente Enterprise)
- Teste manual (somente Enterprise)
- Teste exploratório (somente Enterprise)
- Gerenciamento de caso de teste (somente Enterprise)
- Integração de depurador do mapa de códigos (somente Enterprise)
- Live Unit Testing (somente Enterprise)
- IntelliTrace (somente Enterprise)
- IntelliTest (somente Enterprise)
- Microsoft Fakes (Isolamento de teste de unidade) (somente Enterprise)
- Cobertura de código (somente Enterprise)

## <a name="see-also"></a>Consulte também

[Instalar o Visual Studio](/visualstudio/install/install-visual-studio)<br/>
[Novidades no Visual Studio](/visualstudio/ide/whats-new-in-visual-studio)<br/>
[Tipos de projeto do C++ no Visual Studio](../build/reference/visual-cpp-project-types.md)<br/>

::: moniker-end

::: moniker range="<=vs-2017"

As tabelas a seguir mostram os recursos do Visual C++ disponíveis no Visual Studio 2017. Um X em uma célula indica que o recurso está disponível; uma célula vazia indica que o recurso não está disponível. As observações entre parênteses indicam que um recurso está disponível, mas é restrito.

## <a name="platforms"></a>Plataformas

||||||
|-|-|-|-|-|
|Plataforma|Visual Studio Express para Windows 10|Visual Studio Express para Windows Desktop|Visual Studio Community/Professional|Visual Studio Enterprise|
|Área de Trabalho do Windows||X|X|X|
|Plataforma Universal do Windows (telefone, tablet, computador, Xbox, IoT e HoloLens)|X||X|X|
|Linux|X|X|
|Microsoft Store 8.1|||X|X|
|Windows Phone 8.0|||X|X|
|Android|||X|X|
|iOS|||X|X|

## <a name="compilers"></a>Compiladores

|Compilador|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional/Community|Visual Studio Enterprise|
|--------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Compilador MSVC X86 de 32 bits|X|X|X|X|
|Compilador cruzado X86_arm|X||X|X|
|Compilador MSVC x64 de 64 bits|||X|X|
|Compilador cruzado X86_ x64|X|X|X|X|

## <a name="libraries-and-headers"></a>Bibliotecas e cabeçalhos

|Biblioteca ou cabeçalho|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional/Community|Visual Studio Enterprise|
|-----------------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Cabeçalhos e bibliotecas do Windows e biblioteca CRT|(X)|X|X|X|
|Biblioteca Padrão C++|X|X|X|X|
|ATL|||X|X|
|MFC|||X|X|
|Biblioteca de classes .NET Framework||X|X|X|
|Biblioteca de suporte do C++ para .NET||X|X|X|
|OpenMP 2.0|X|X|X|X|

## <a name="project-templates"></a>Modelos de projeto

|Modelo|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional/Community|Visual Studio Enterprise|
|--------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Modelos XAML para UWP, Windows 8.1, Windows Phone 8.0|X||X|X|
|Aplicativo Direct3D|X||X|X|
|DLL (Universal do Windows)|X||X|X|
|Biblioteca Estática (Universal do Windows)|X||X|X|
|Componente do Tempo de Execução do Windows|X||X|X|
|Aplicativo de Teste de Unidade (Universal do Windows)|X||X|X|
|Projeto ATL|||X|X|
|Biblioteca de Classes (CLR)||X|X|X|
|Aplicativo de Console CLR||X|X|X|
|Projeto CLR Vazio||X|X|X|
|Assistente personalizado|||X|X|
|Projeto Vazio||X|X|X|
|Projeto Makefile||X|X|X|
|Controle ActiveX do MFC|||X|X|
|Aplicativo MFC|||X|X|
|DLL do MFC|||X|X|
|Projeto de Teste|X|X|X|X|
|Aplicativo de Console Win32||X|X|X|
|Projeto Win32||X|X|X|

## <a name="tools"></a>Ferramentas

|Ferramenta|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional/Community|Visual Studio Enterprise|
|----------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Vinculador Incremental (Link.exe)|X|X|X|X|
|Utilitário de Manutenção de Programas (Nmake.exe)||X|X|X|
|Gerador de Lib (Lib.exe)|X|X|X|X|
|Compilador de Recurso do Windows (Rc.exe)|X|X|X|X|
|Recurso do Windows para Conversor de Objeto (CvtRes.exe)||X|X|X|
|Utilitário de Manutenção de Informações de Procura (BscMake.exe)|X|X|X|X|
|Removedor de Decoração de Nomes do C++ (Undname.exe)|X|X|X|X|
|Despejo de COFF/PE (Dumpbin.exe)|X|X|X|X|
|Editor de COFF/PE (Editbin.exe)|X|X|X|X|
|MASM (Ml.exe)|||X|X|
|Spy++|||X|X|
|ErrLook|||X|X|
|AtlTrace|||X|X|
|Devenv.com|||X|X|
|Regras de inferência|||X|X|
|Atualizar projetos .vcproj do VCBuild para o MSBuild (VCUpgrade.exe)|X|X|X|X|
|Otimizações guiadas por perfil|||X|X|

## <a name="debugging-features"></a>Funcionalidades de depuração

|Recurso de depuração|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional/Community|Visual Studio Enterprise|
|-----------------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Depuração nativa|X|X|X|X|
|natvis (visualização nativa de tipo)|X|X|X|X|
|Depuração de gráficos|X||X|X|
|Depuração gerenciada||X|X|X|
|Uso de GPU|X||X|X|
|Uso de memória|X||X|X|
|Depuração remota|X|X|X|X|
|Depuração SQL|||X|X|
|Análise de código estático|Limitado|Limitado|X|X|

## <a name="designers-and-editors"></a>Designers e Editores

|Designer ou Editor|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional/Community|Visual Studio Enterprise|
|------------------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|XAML Designer|X||X|X|
|Designer/Editor de Estilo CSS|X|X|X|X|
|Designer/Editor de HTML|X|X|X|X|
|Editor de XML|X|X|X|X|
|Editor de Código-fonte|X|X|X|X|
|Recursos de produtividade: Refatoração, IntelliSense, formatação de Código C++|X|X|X|X|
|Designer de Formulários do Windows||X|X|X|
|Designer de dados|||X|X|
|Editor de Recurso Nativo (arquivos .rc)|||X|X|
|Editores de recursos|X|X|X|X|
|Editor de modelos|X||X|X|
|Designer de sombreador|X||X|X|

## <a name="data-features"></a>Funcionalidades de dados

|Recurso de dados|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional/Community|Visual Studio Enterprise|
|------------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Designer de dados|||X|X|
|Objetos de dados|||X|X|
|Serviços Web|||X|X|
|conexões de servidor|||X|X|

## <a name="build-and-project-systems"></a>Sistemas de build e de projeto

|Recurso de build ou de projeto|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional/Community|Visual Studio Enterprise|
|------------------------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Builds de linha de comando (msbuild.exe)|X|X|X|X|
|Multiplataforma nativa||X|X|X|
|Multiplataforma gerenciada||X|X|X|
|Builds paralelos|X|X|X|X|
|Personalizações de build|X|X|X|X|
|Extensibilidade de páginas de propriedades|X|X|X|X|

## <a name="automation-and-extensibility"></a>Automação e extensibilidade

|Automação e extensibilidade|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional/Community|Visual Studio Enterprise|
|----------------------------------|---------------------------------------|-----------------------------------------------|---------------------------------------------|------------------------------|
|Modelos de objeto de extensibilidade|||X|X|
|Modelo de código|||X|X|
|Modelo de Projeto|||X|X|
|Modelo de editor de recursos|||X|X|
|Modelo de assistente|||X|X|
|Modelo de objeto do depurador|||X|X|

## <a name="application-lifecycle-management-tools"></a>Ferramentas de gerenciamento de ciclo de vida do aplicativo

||||||
|-|-|-|-|-|
|Ferramenta|Visual Studio Express para Windows|Visual Studio Express para Windows Desktop|Visual Studio Professional/Community|Visual Studio Enterprise|
|Teste de unidade (estrutura nativa)|X|X|X|X|
|Teste de unidade (estrutura gerenciada)||X|X|X|
|Cobertura de código||||X|
|Teste manual||||X|
|Teste exploratório||||X|
|Gerenciamento de casos de teste||||X|
|Mapa de códigos e grafos de dependência|||somente leitura|X|
|Depuração do mapa de códigos||||X|

## <a name="see-also"></a>Consulte também

[Instalar o Visual Studio](/visualstudio/install/install-visual-studio)<br/>
[Novidades no Visual Studio](/visualstudio/ide/whats-new-in-visual-studio)<br/>
[Tipos de projeto do C++ no Visual Studio](../build/reference/visual-cpp-project-types.md)<br/>

::: moniker-end
