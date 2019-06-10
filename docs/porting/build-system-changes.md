---
title: Alterações no sistema de build do Visual Studio 2010
ms.date: 11/04/2016
f1_keywords:
- vc.msbuild.changes
helpviewer_keywords:
- Build system changes, project file (.vcxprog)
- Build system changes, custom build rules
- Build system changes, MSBuild
- MSBuild, build system changes
- Build system changes, .vsprops
- Build system changes, $(Inherit)
- Build system changes, $(NoInherit)
ms.assetid: e564d95f-a6cc-4d97-b57e-1a71daf66f4a
ms.openlocfilehash: c3e51aa7e5a4346137e94191b551b0d53452e460
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65449013"
---
# <a name="build-system-changes"></a>Alterações no sistema de compilação

O sistema MSBuild é usado para compilar projetos do Visual Studio C++. No entanto, no Visual Studio 2008 e em versões anteriores, o sistema VCBuild foi usado. Determinados tipos de arquivo e conceitos que dependem do VCBuild não existem ou são representados de maneira diferente no sistema atual. Este documento discute as diferenças no sistema de build atual.

## <a name="vcproj-is-now-vcxproj"></a>.vcproj agora é .vcxproj

Arquivos de projeto não usam mais a extensão de nome de arquivo .vcproj. O Visual Studio converte automaticamente os arquivos de projeto que foram criados por uma versão anterior do Visual C++ para o formato usado pelo sistema atual. Para obter mais informações sobre como atualizar manualmente um projeto, confira [/Upgrade (devenv.exe)](/visualstudio/ide/reference/upgrade-devenv-exe).

Na versão atual, a extensão de nome de arquivo para um arquivo de projeto é .vcxproj.

## <a name="vsprops-is-now-props"></a>.vsprops agora é .props

Em versões anteriores, uma *folha de propriedades do projeto* é um arquivo baseado em XML que tem uma extensão de nome de arquivo .vsprops. Uma folha de propriedades do projeto permite especificar opções para ferramentas de build, como o compilador ou vinculador e criar macros definidas pelo usuário.

Na versão atual, a extensão de nome de arquivo para uma folha de propriedades do projeto é .props.

## <a name="custom-build-rules-and-rules-files"></a>Regras de build personalizadas e arquivos .rules

Em versões anteriores, um *arquivo de regra* é um arquivo baseado em XML que tem uma extensão de nome de arquivo .rules. Um arquivo de regra permite definir regras de build personalizadas e incorporá-las ao processo de build de um projeto do Visual Studio C++. Uma regra de build personalizada, que pode ser associada a uma ou mais extensões de nome de arquivo, permite que você passe os arquivos de entrada para uma ferramenta que cria um ou mais arquivos de saída.

Nesta versão, as regras de build personalizadas são representadas por três tipos de arquivo: .xml, .props e .targets, em vez de um arquivo .rules. Quando um arquivo .rules que foi criado usando uma versão anterior do Visual C++ é migrado para a versão atual, arquivos .xml, .props e .targets equivalentes são criados e armazenados em seu projeto junto com o arquivo .rules original.

> [!IMPORTANT]
>  Na versão atual, o IDE não dá suporte à criação de regras. Por esse motivo, a maneira mais fácil de usar um arquivo de regra de um projeto que foi criado usando uma versão anterior do Visual C++ é migrar o projeto para a versão atual.

## <a name="inheritance-macros"></a>Macros de herança

Em versões anteriores, a macro **$(Inherit)** especifica a ordem na qual as propriedades herdadas são exibidas na linha de comando que é composta pelo sistema de build do projeto. A macro **$(NoInherit)** faz com que qualquer ocorrência de $(Inherit) seja ignorada e faz com que as propriedades que seriam herdadas não sejam mais. Por exemplo, por padrão a macro $(Inherit) faz com que arquivos especificados usando a opção do compilador [/I (diretórios de inclusão adicionais)](../build/reference/i-additional-include-directories.md) sejam acrescentados à linha de comando.

Na versão atual, a herança é compatível especificando o valor de uma propriedade como a concatenação de um ou mais valores literais e macros de propriedade. Não há suporte para as macros **$(Inherit)** e **$(NoInherit)** .

No exemplo a seguir, uma lista delimitada por ponto e vírgula é atribuída a uma propriedade em uma página de propriedades. A lista consiste na concatenação do *\<value>* literal e do valor da propriedade `MyProperty`, que é acessada usando a notação de macro, **$(** <em>MyProperty</em> **)** .

```
Property=<value>;$(MyProperty)
```

## <a name="vcxprojuser-files"></a>Arquivos .vcxproj.user

Um arquivo de usuário (.vcxproj.user) armazena as propriedades específicas do usuário, por exemplo, depuração e configurações de implantação. O arquivo vcxproj.user se aplica a todos os projetos de um usuário específico.

## <a name="vcxprojfilters-file"></a>Arquivo .vcxproj.filters

Quando o **Gerenciador de Soluções** é usado para adicionar um arquivo a um projeto, o arquivo de filtros (.vcxproj.filters) define em que o local no modo de exibição de árvore do **Gerenciador de Soluções** o arquivo é adicionado, com base em sua extensão de nome de arquivo.

## <a name="vc-directories-settings"></a>Configurações de diretórios do VC++

As configurações de diretórios do Visual C++ são especificadas na [Página de propriedades dos diretórios do VC++](../ide/vcpp-directories-property-page.md). Em versões anteriores do Visual Studio, as configurações dos diretórios se aplicam por usuário e a lista de diretórios excluídos é especificada no arquivo sysincl.dat.

Você não poderá alterar as configurações de diretórios do VC++ se executar [devenv /resetsettings](/visualstudio/ide/reference/resetsettings-devenv-exe) na linha de comando. Também não será possível alterar as configurações se você abrir o menu **Ferramentas**, clicar em **Importar e Exportar Configurações** e selecionar a opção **Redefinir todas as configurações**.

Migre as configurações de diretórios do VC++ de um arquivo .vssettings que é criado por uma versão anterior do Visual C++. Abra o menu **Ferramentas**, clique em **Importar e Exportar Configurações**, selecione **Importar configurações de ambiente selecionadas** e siga as instruções no assistente. Ou, ao iniciar o Visual Studio pela primeira vez, na caixa de diálogo **Escolher Configurações de Ambiente Padrão**, selecione **Migrar minhas configurações qualificadas de uma versão anterior e aplicá-las em acréscimo às configurações padrão selecionadas abaixo**.

## <a name="see-also"></a>Consulte também

[MSBuild na linha de comando – C++](../build/msbuild-visual-cpp.md)
