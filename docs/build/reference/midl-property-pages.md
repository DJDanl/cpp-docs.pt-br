---
title: Páginas de propriedade do compilador MIDL
ms.date: 07/24/2019
ms.topic: article
ms.assetid: 57498a01-fccc-4a0e-a036-6ff702f83126
f1_keywords:
- VC.Project.VCMidlTool.PreprocessorDefinitions
- VC.Project.VCMidlTool.AdditionalIncludeDirectories
- VC.Project.VCMidlTool.AdditionalMetadataDirectories
- VC.Project.VCMidlTool.IgnoreStandardIncludePath
- VC.Project.VCMidlTool.IgnoreStandardIncludePath
- VC.Project.VCMidlTool.MkTypLibCompatible
- VC.Project.VCMidlTool.WarningLevel
- VC.Project.VCMidlTool.WarnAsError
- VC.Project.VCMidlTool.SuppressStartupBanner
- VC.Project.VCMidlTool.DefaultCharType
- VC.Project.VCMidlTool.TargetEnvironment
- VC.Project.VCMidlTool.GenerateStublessProxies
- VC.Project.VCMidlTool.SuppressCompilerWarnings
- VC.Project.VCMidlTool.ApplicationConfigurationMode
- VC.Project.VCMidlTool.LocaleID
- VC.Project.VCMidlTool.MultiProcMIDL
- VC.Project.VCMidlTool.OutputDirectory
- VC.Project.VCMidlTool.WinmdFileName
- VC.Project.VCMidlTool.HeaderFileName
- VC.Project.VCMidlTool.DLLDataFileName
- VC.Project.VCMidlTool.InterfaceIdentifierFileName
- VC.Project.VCMidlTool.ProxyFileName
- VC.Project.VCMidlTool.GenerateTypeLibrary
- VC.Project.VCMidlTool.TypeLibraryName
- VC.Project.VCMidlTool.GenerateClientFiles
- VC.Project.VCMidlTool.GenerateServerFiles
- VC.Project.VCMidlTool.ClientStubFile
- VC.Project.VCMidlTool.ServerStubFile
- VC.Project.VCMidlTool.TypeLibFormat
- VC.Project.VCMidlTool.CPreprocessOptions
- VC.Project.VCMidlTool.UndefinePreprocessorDefinitions
- VC.Project.VCMidlTool.EnableErrorChecks
- VC.Project.VCMidlTool.ErrorCheckAllocations
- VC.Project.VCMidlTool.ErrorCheckBounds
- VC.Project.VCMidlTool.ErrorCheckEnumRange
- VC.Project.VCMidlTool.ErrorCheckRefPointers
- VC.Project.VCMidlTool.ErrorCheckStubData
- VC.Project.VCMidlTool.PreendWithABINamepsace
- VC.Project.VCMidlTool.ValidateParameters
- VC.Project.VCMidlTool.StructMemberAlignment
- VC.Project.VCMidlTool.RedirectOutputAndErrors
- VC.Project.VCMidlTool.MinimumTargetSystem
- vc.project.AdditionalOptionsPage
ms.openlocfilehash: d6833230baca892836c187799df7f0658aa16772
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336246"
---
# <a name="midl-property-pages"></a>Páginas de propriedade MIDL

As páginas de propriedade MIDL estão disponíveis como uma propriedade de item em um . Arquivo IDL em um projeto C++ que usa COM. Use-os para configurar o [compilador MIDL](/windows/win32/midl/using-the-midl-compiler-2). Para obter informações sobre como acessar as opções de MIDL para projetos do C++ de forma programática, confira o objeto <xref:Microsoft.VisualStudio.VCProjectEngine.VCMidlTool>. Consulte também [a sintaxe geral midl de linha de comando](/windows/win32/midl/general-midl-command-line-syntax).

## <a name="general-property-page"></a>Página de propriedades gerais

### <a name="preprocessor-definitions"></a>Definições do Pré-processador

Especifica uma ou mais definições, incluindo macros\[MIDL\][(/D).](/windows/win32/midl/-d)

### <a name="additional-include-directories"></a>Diretórios de Inclusão Adicionais

Especifica um ou mais diretórios para adicionar ao\]caminho incluir[(/I](/windows/win32/midl/-i)\[caminho ).

### <a name="additional-metadata-directories"></a>Diretórios adicionais de metadados

Especifique o diretório que contém o arquivo Windows.Foundation.WinMD[(/metadata_dir](/windows/win32/midl/-metadata-dir) \[path\]).

### <a name="enable-windows-runtime"></a>Habilitar o tempo de execução do Windows

Habilite a semântica de tempo de execução do Windows para criar o arquivo de metadados do Windows[(/winrt).](/windows/win32/midl/-winrt)

### <a name="ignore-standard-include-path"></a>Ignorar o caminho de incluir padrão

Ignore a corrente e os diretórios INCLUDE[(/no_def_idir).](/windows/win32/midl/-no-def-idir)

### <a name="mktyplib-compatible"></a>Compatível com MkTypLib

Força a compatibilidade com mktyplib.exe versão 2.03 ([/mktyplib203](/windows/win32/midl/-mktyplib203)).

### <a name="warning-level"></a>Nível de aviso

Seleciona a rigidez dos erros de código MIDL[(/W](/windows/win32/midl/-w)).

**Opções**

- **1**
- **1**
- **2**
- **3**
- **4**

### <a name="treat-warnings-as-errors"></a>Tratar Avisos como Erros

Habilita o MIDL para tratar todos os avisos como erros[(/WX](/windows/win32/midl/-wx)).

### <a name="suppress-startup-banner"></a>Suprimir Faixa de Inicialização

Suprimir a exibição do banner de inicialização e a mensagem de informação[(/nologo).](/windows/win32/midl/-nologo)

### <a name="c-compiler-char-type"></a>C Tipo de char do compilador

Especifica o tipo de caractere padrão do compilador C que será usado para compilar o código gerado. ([/char](/windows/win32/midl/-char) assinado|sem assinatura|ascii7).

**Opções**

- **Assinado** - Assinado
- **Não assinado** - Não assinado
- **Ascii** - Ascii

### <a name="target-environment"></a>Ambiente de destino

Especifica qual ambiente ser direcionado ([/env](/windows/win32/midl/-env) arm32|win32|ia64|x64).

**Opções**

- **Not Set** - Win32
- **Microsoft Windows 32-bit** - Win32
- **Microsoft Windows 64-bit em Itanium** - IA64
- **Microsoft Windows ARM** - ARM
- **Microsoft Windows ARM64** - ARM64
- **Microsoft Windows 64-bit em x64** - X64

### <a name="generate-stubless-proxies"></a>Gerar Proxies Stubless

Gerar stubs totalmente interpretados com extensões e proxies stubless para interfaces de objeto ([/Oicf](/windows/win32/midl/-oi), [/Oif](/windows/win32/midl/-oi) ).

### <a name="suppress-compiler-warnings"></a>Suprimir avisos do compilador

Suprimir mensagens de aviso do compilador[(/no_warn](/windows/win32/midl/-no-warn)).

### <a name="application-configuration-mode"></a>Modo de configuração do aplicativo

Permitir atributos ACF selecionados no arquivo IDL[(/app_config).](/windows/win32/midl/-app-config)

### <a name="locale-id"></a>ID da Localidade

Especifica o LCID para arquivos de entrada, nomes de arquivos e caminhos de diretório[(/lcid](/windows/win32/midl/-lcid) DECIMAL).

### <a name="multi-processor-compilation"></a>Compilação de vários processadores

Execute várias instâncias ao mesmo tempo.

## <a name="output-property-page"></a>Página de propriedade de saída

### <a name="output-directory"></a>Diretório de saída

Especifica o diretório de saída ([/out](/windows/win32/midl/-out) [diretório]).

### <a name="metadata-file"></a>Arquivo de metadados

Especifica o nome do arquivo de metadados gerado[(/nome de arquivo winmd).](/windows/win32/midl/-winmd)

### <a name="header-file"></a>Arquivos de cabeçalho

Especifica o nome do arquivo de cabeçalho gerado[(/h](/windows/win32/midl/-h) nome do arquivo).

### <a name="dlldata-file"></a>Arquivo DllData

Especifica o nome do arquivo DLLDATA[(/dlldata](/windows/win32/midl/-dlldata) filename).

### <a name="iid-file"></a>Arquivo IID

Especifica o nome para o arquivo identificador de interface[(/nome do arquivo iid).](/windows/win32/midl/-iid)

### <a name="proxy-file"></a>Arquivo proxy

Especifica o nome do arquivo proxy[(/proxy](/windows/win32/midl/-proxy) filename).

### <a name="generate-type-library"></a>Gerar biblioteca de tipos

Especificar não gerar uma biblioteca de tipo ([/notlb] para não).

### <a name="type-library"></a>Biblioteca de tipos

Especifica o nome do arquivo da biblioteca de tipo (/nome de arquivo[tlb).](/windows/win32/midl/-tlb)

### <a name="generate-client-stub-files"></a>Gerar arquivos stub do cliente

Gerar somente arquivo stub do cliente[(/cliente](/windows/win32/midl/-client) [stub|none]).

**Opções**

- **Stub** - Stub
- **Nenhum** - Nenhum

### <a name="generate-server-stub-files"></a>Gerar arquivos stub do servidor

Gerar somente arquivo stub do servidor[(/server](/windows/win32/midl/-server) [stub|none]).

**Opções**

- **Stub** - Stub
- **Nenhum** - Nenhum

### <a name="client-stub-file"></a>Arquivo stub do cliente

Especifique o arquivo de stub do cliente[(/cstub](/windows/win32/midl/-cstub) [arquivo]).

### <a name="server-stub-file"></a>Arquivo stub do servidor

Especifique o arquivo de stub do servidor[(/sstub](/windows/win32/midl/-sstub) [arquivo]).

### <a name="type-library-format"></a>Formato de biblioteca de tipo

Especifica o formato de arquivo de biblioteca de tipo ([/oldtlb|/newtlb]).

**Opções**

- **NewFormat** - Novo Formato
- **OldFormat** - Formato Antigo

## <a name="advanced-property-page"></a>Página de propriedade avançada

### <a name="c-preprocess-options"></a>C Opções de pré-processo

Especifica os switches para passar para o pré-processador compilador C[(/cpp_opt](/windows/win32/midl/-cpp-opt) switches).

### <a name="undefine-preprocessor-definitions"></a>Excluir definições do pré-processador

Especifica uma ou mais indefinições, incluindo macros MIDL[(/U](/windows/win32/midl/-U) [macros]).

### <a name="enable-error-checking"></a>Ativar verificação de erros

Selecione a opção de verificação de erros ([/erro all|none]).

**Opções**

- **Habilitarpersonalizado** - Tudo
- **Todos -** Todos
- **Nenhum** - Nenhum

### <a name="check-allocations"></a>Verificar alocações

Verifique se há erros de memória[(/alocação de erros).](/windows/win32/midl/-error)

### <a name="check-bounds"></a>Verificar limites

Verifique o tamanho vs especificação do comprimento da transmissão[(/bounds_check de erro).](/windows/win32/midl/-error)

### <a name="check-enum-range"></a>Verifique a faixa de enum

Verifique os valores de enum a serem permitidos[(/enum de erro).](/windows/win32/midl/-error)

### <a name="check-reference-pointers"></a>Verifique ponteiros de referência

Verifique os ponteiros do árbitro como não nulos[(/árbitro de erro).](/windows/win32/midl/-error)

### <a name="check-stub-data"></a>Verificar dados do Stub

Emita verificação adicional para a validade dos dados do stub lateral do servidor[(/stub_data de erro).](/windows/win32/midl/-error)

### <a name="prepend-with-abi-namespace"></a>Prepend com espaço de nome 'ABI'

Prepare o espaço de nome 'ABI' para todos os tipos.  [( /ns_prefix](/windows/win32/midl/-ns-prefix)).

### <a name="validate-parameters"></a>Validar parâmetros

Gerar informações adicionais para validar parâmetros[(robusto/no_robust](/windows/win32/midl/-robust) | [/no_robust](/windows/win32/midl/-no-robust)).

### <a name="struct-member-alignment"></a>Alinhamento do membro de estrutura

Especifica o nível de embalagem das estruturas no sistema de destino (/ZpN).

**Opções**

- **Não definido** - Não definido
- **1 Byte** - Zp1
- **2 Byte** - Zp2
- **4 Byte** - Zp4
- **8 Byte** - Zp8

### <a name="redirect-output"></a>Redirecionar saída

Redireciona a saída da tela para um arquivo[(/o).](/windows/win32/midl/-o)

### <a name="minimum-target-system"></a>Sistema de Destino Mínimo

Defina o sistema de destino mínimo[(/target](/windows/win32/midl/-target) STRING).
