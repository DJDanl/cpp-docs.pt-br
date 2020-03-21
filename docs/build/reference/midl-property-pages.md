---
title: Páginas de propriedades do compilador MIDL
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
ms.openlocfilehash: 260936d01a611f061b0b4fa9a5c087ff38cc66a3
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80076125"
---
# <a name="midl-property-pages"></a>Páginas de propriedade MIDL

As páginas de propriedades de MIDL estão disponíveis como uma propriedade de item em um. Arquivo IDL em um C++ projeto que usa com. Use-os para configurar o [compilador MIDL](/windows/win32/midl/using-the-midl-compiler-2). Para obter informações sobre como acessar as opções de MIDL para projetos do C++ de forma programática, confira o objeto <xref:Microsoft.VisualStudio.VCProjectEngine.VCMidlTool>. Consulte também [sintaxe de linha de comando MIDL geral](/windows/win32/midl/general-midl-command-line-syntax).

## <a name="general-property-page"></a>Página de propriedades geral

### <a name="preprocessor-definitions"></a>Definições do Pré-processador

Especifica uma ou mais definições, incluindo macros de MIDL ([/d](/windows/win32/midl/-d))\[macros\]).

### <a name="additional-include-directories"></a>Diretórios de Inclusão Adicionais

Especifica um ou mais diretórios a serem adicionados ao caminho de inclusão ([/i](/windows/win32/midl/-i)\[caminho\]).

### <a name="additional-metadata-directories"></a>Diretórios de metadados adicionais

Especifique o diretório que contém o arquivo Windows. Foundation. WinMD ([/metadata_dir](/windows/win32/midl/-metadata-dir) \[caminho\]).

### <a name="enable-windows-runtime"></a>Habilitar Windows Runtime

Habilite a semântica de Windows Runtime para criar o arquivo de metadados do Windows ([/winrt](/windows/win32/midl/-winrt)).

### <a name="ignore-standard-include-path"></a>Ignorar caminho de inclusão padrão

Ignore os diretórios atual e de inclusão ([/no_def_idir](/windows/win32/midl/-no-def-idir)).

### <a name="mktyplib-compatible"></a>Compatível com MkTypLib

Força a compatibilidade com o MkTypLib. exe versão 2, 3 ([/mktyplib203](/windows/win32/midl/-mktyplib203)).

### <a name="warning-level"></a>Nível de aviso

Seleciona a restrição dos erros de código de MIDL ([/w](/windows/win32/midl/-w)).

**Opções**

- **1**
- **1**
- **2**
- **3**
- **4**

### <a name="treat-warnings-as-errors"></a>Tratar Avisos como Erros

Permite que MIDL trate todos os avisos como erros ([/WX](/windows/win32/midl/-wx)).

### <a name="suppress-startup-banner"></a>Suprimir Faixa de Inicialização

Suprimir a exibição da faixa de inicialização e mensagem de informação ([/nologo](/windows/win32/midl/-nologo)).

### <a name="c-compiler-char-type"></a>Tipo de caractere do compilador C

Especifica o tipo de caractere padrão do compilador C que será usado para compilar o código gerado. ([/Char](/windows/win32/midl/-char) assinado | não assinado | ascii7).

**Opções**

- Assinado com **assinatura**
- **Não** assinado – não assinado
- **ASCII** -ASCII

### <a name="target-environment"></a>Ambiente de destino

Especifica qual ambiente deve ser direcionado ([/env](/windows/win32/midl/-env) arm32 | Win32 | IA64 | x64).

**Opções**

- **Não definido** -Win32
- **Microsoft Windows 32-bit** -Win32
- **Microsoft Windows 64-bit no Itanium** -IA64
- ARM **do Microsoft Windows**
- **Microsoft Windows ARM64** -ARM64
- **Microsoft Windows 64-bit em x64** -x64

### <a name="generate-stubless-proxies"></a>Gerar proxies sem stub

Gere stubs totalmente interpretados com extensões e proxies sem stub para interfaces de objeto ([/Oicf](/windows/win32/midl/-oi), [/OIF](/windows/win32/midl/-oi) ).

### <a name="suppress-compiler-warnings"></a>Suprimir avisos do compilador

Suprimir mensagens de aviso do compilador ([/no_warn](/windows/win32/midl/-no-warn)).

### <a name="application-configuration-mode"></a>Modo de configuração de aplicativo

Permitir atributos ACF selecionados no arquivo IDL ([/app_config](/windows/win32/midl/-app-config)).

### <a name="locale-id"></a>ID da localidade

Especifica o LCID para arquivos de entrada, nomes de arquivo e caminhos de diretório ([/LCID](/windows/win32/midl/-lcid) decimal).

### <a name="multi-processor-compilation"></a>Compilação de vários processadores

Execute várias instâncias ao mesmo tempo.

## <a name="output-property-page"></a>Página de propriedades de saída

### <a name="output-directory"></a>Diretório de saída

Especifica o diretório de saída ([/out](/windows/win32/midl/-out) [Directory]).

### <a name="metadata-file"></a>Arquivo de metadados

Especifica o nome do arquivo de metadados gerado ([/winmd](/windows/win32/midl/-winmd) filename).

### <a name="header-file"></a>Arquivos de cabeçalho

Especifica o nome do arquivo de cabeçalho gerado ([/h](/windows/win32/midl/-h) filename).

### <a name="dlldata-file"></a>Arquivo DllData

Especifica o nome do arquivo DLLDATA ([/dlldata nomedearquivo](/windows/win32/midl/-dlldata) filename).

### <a name="iid-file"></a>Arquivo IID

Especifica o nome do arquivo de identificador de interface ([/IID nomedearquivo](/windows/win32/midl/-iid) filename).

### <a name="proxy-file"></a>Arquivo de proxy

Especifica o nome do arquivo de proxy ([/proxy nomedearquivo](/windows/win32/midl/-proxy) filename).

### <a name="generate-type-library"></a>Gerar biblioteca de tipos

Especifique não para gerar uma biblioteca de tipos ([/notlb] para não).

### <a name="type-library"></a>Biblioteca de tipos

Especifica o nome do arquivo de biblioteca de tipos ([/tlb](/windows/win32/midl/-tlb) filename).

### <a name="generate-client-stub-files"></a>Gerar arquivos stub de cliente

Gerar somente arquivo stub do cliente ([/Client](/windows/win32/midl/-client) [stub | None]).

**Opções**

- **Stub** -stub
- **Nenhum** -nenhum

### <a name="generate-server-stub-files"></a>Gerar arquivos stub de servidor

Gerar somente arquivo stub de servidor ([/Server](/windows/win32/midl/-server) [stub | None]).

**Opções**

- **Stub** -stub
- **Nenhum** -nenhum

### <a name="client-stub-file"></a>Arquivo stub do cliente

Especifique o arquivo stub do cliente ([/cstub](/windows/win32/midl/-cstub) [File]).

### <a name="server-stub-file"></a>Arquivo stub do servidor

Especifique o arquivo stub do servidor ([/sstub](/windows/win32/midl/-sstub) [File]).

### <a name="type-library-format"></a>Formato de biblioteca de tipos

Especifica o formato de arquivo de biblioteca de tipos ([/oldtlb |/newtlb]).

**Opções**

- **NewFormat** -novo formato
- **OldFormat** -formato antigo

## <a name="advanced-property-page"></a>Página de propriedades avançada

### <a name="c-preprocess-options"></a>Opções de pré-processamento C

Especifica as opções para passar para o pré-processador do compilador C ([/cpp_opt](/windows/win32/midl/-cpp-opt) comutadores).

### <a name="undefine-preprocessor-definitions"></a>Excluir as definições do pré-processador

Especifica um ou mais desdefinidos, incluindo macros de MIDL ([/u](/windows/win32/midl/-U) [macros]).

### <a name="enable-error-checking"></a>Habilitar verificação de erro

Selecione a opção de verificação de erro ([/Error All | None]).

**Opções**

- **EnableCustom** -todos
- **Todos** -todos
- **Nenhum** -nenhum

### <a name="check-allocations"></a>Verificar alocações

Verifique se há erros de memória insuficiente (alocação de[/Error](/windows/win32/midl/-error) ).

### <a name="check-bounds"></a>Verificar limites

Verifique o tamanho vs. especificação do comprimento da transmissão ([/error](/windows/win32/midl/-error) bounds_check).

### <a name="check-enum-range"></a>Verificar intervalo de enumeração

Verifique se os valores de enumeração estão no intervalo permitido ([/Error](/windows/win32/midl/-error) enum).

### <a name="check-reference-pointers"></a>Verificar ponteiros de referência

Verifique se os ponteiros de referência não são nulos ([/Error](/windows/win32/midl/-error) ref).

### <a name="check-stub-data"></a>Verificar dados de stub

Emitir verificação adicional para a validade de dados de stub do lado do servidor ([/error](/windows/win32/midl/-error) stub_data).

### <a name="prepend-with-abi-namespace"></a>Preceder com o namespace ' ABI '

Preceda o namespace ' ABI ' para todos os tipos.  ([/ns_prefix](/windows/win32/midl/-ns-prefix)).

### <a name="validate-parameters"></a>Validar parâmetros

Gere informações adicionais para validar os parâmetros ([/robust](/windows/win32/midl/-robust) | [/no_robust](/windows/win32/midl/-no-robust)).

### <a name="struct-member-alignment"></a>Alinhamento de membro de struct

Especifica o nível de empacotamento das estruturas no sistema de destino (/ZpN).

**Opções**

- **Não definido** -não definido
- **1 byte** -Zp1
- **2 bytes** -Zp2
- **4 bytes** -Zp4
- **8 bytes** -Zp8

### <a name="redirect-output"></a>Redirecionar saída

Redireciona a saída da tela para um arquivo ([/o](/windows/win32/midl/-o) File).

### <a name="minimum-target-system"></a>Sistema de destino mínimo

Defina o sistema de destino mínimo ([/target](/windows/win32/midl/-target) String).
