---
title: VCBuild versus MSBuild
description: O sistema de C++ compilação do Visual Studio mudou de VCBuild para MSBuild no VIsual Studio 2010.
ms.date: 10/25/2019
helpviewer_keywords:
- Build system changes, project file (.vcxprog)
- Build system changes, custom build rules
- Build system changes, MSBuild
- MSBuild, build system changes
- Build system changes, .vsprops
- Build system changes, $(Inherit)
- Build system changes, $(NoInherit)
ms.assetid: e564d95f-a6cc-4d97-b57e-1a71daf66f4a
ms.openlocfilehash: ce3eb9e51a103aa54b74c7b5b4f775eb402269f1
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80076944"
---
# <a name="vcbuild-vs-msbuild-build-system-changes-in-visual-studio-2010"></a>VCBuild versus MSBuild: criar alterações no sistema no Visual Studio 2010

O sistema MSBuild para C++ projetos foi introduzido no Visual Studio 2010. No Visual Studio 2008 e versões anteriores, o sistema VCBuild foi usado. Determinados tipos de arquivo e conceitos que dependem de VCBuild não existem ou são representados de modo diferente no MSBuild. Este documento discute as diferenças no sistema de build atual. Para converter um projeto do Visual Studio 2008 no MSBuild, você deve usar o Visual Studio 2010. Depois que o projeto for convertido, você deverá usar a versão mais recente do Visual Studio para atualizar para o IDE atual e o conjunto de ferramentas do compilador. Para obter mais informações, incluindo como obter o Visual Studio 2010, consulte [as instruções para o visual studio 2008](use-native-multi-targeting.md#instructions-for-visual-studio-2008).

As seções a seguir resumem as alterações de VCBuild para MSBuild. Se seu projeto VCBuild tiver regras de compilação personalizadas ou macros que não são reconhecidas pelo MSBuild, consulte [projetos do Visual Studio- C++ ](../build/creating-and-managing-visual-cpp-projects.md) para saber como converter essas instruções no sistema MSBuild. A conversão inicial de VCBuild para MSBuild é apenas uma etapa intermediária. Não é necessário colocar o arquivo de projeto completamente correto ou fazer com que o programa seja compilado sem erros. Você está usando apenas o Visual Studio 2010 para converter o projeto para o formato MSBuild para que você tenha o projeto funcionando na versão mais recente do Visual Studio.

## <a name="vcproj-is-now-vcxproj"></a>.vcproj agora é .vcxproj

Arquivos de projeto não usam mais a extensão de nome de arquivo .vcproj. O Visual Studio 2010 converte automaticamente os arquivos de projeto que foram criados por uma versão C++ anterior do Visual no formato MSBuild, que usa a extensão. vcxproj para arquivos de projeto.

## <a name="vsprops-is-now-props"></a>.vsprops agora é .props

No Visual Studio 2008 e anterior, uma *folha de propriedades do projeto* é um arquivo baseado em XML que tem uma extensão de nome de arquivo. vsprops. Uma folha de propriedades do projeto permite especificar opções para ferramentas de build, como o compilador ou vinculador e criar macros definidas pelo usuário. No MSBuild, a extensão de nome de arquivo para uma folha de propriedades de projeto é. props.

## <a name="custom-build-rules-and-rules-files"></a>Regras de compilação personalizadas e arquivos. Rules

No Visual Studio 2008 e anterior, um *arquivo de regras* é um arquivo baseado em XML que tem uma extensão. Rules de nome de arquivo. Um arquivo de regra permite definir regras de build personalizadas e incorporá-las ao processo de build de um projeto do Visual Studio C++. Uma regra de build personalizada, que pode ser associada a uma ou mais extensões de nome de arquivo, permite que você passe os arquivos de entrada para uma ferramenta que cria um ou mais arquivos de saída.

No sistema MSBuild, as regras de compilação personalizadas são representadas por três tipos de arquivo,. xml,. props e. targets, em vez de um arquivo. Rules. Quando um arquivo. Rules criado usando uma versão anterior do Visual C++ é migrado para o visual Studio 2010, os arquivos equivalentes. xml,. props e. targets são criados e armazenados em seu projeto junto com o arquivo. Rules original.

> [!IMPORTANT]
> No Visual Studio 2010, o IDE não oferece suporte à criação de novas regras. Por esse motivo, a maneira mais fácil de usar um arquivo de regra de um projeto criado com o uso de uma versão anterior do C++ Visual é migrar o projeto para o Visual Studio 2010.

## <a name="inheritance-macros"></a>Macros de herança

No Visual Studio 2008 e anterior, a macro **$ (Inherit)** especifica a ordem na qual as propriedades herdadas aparecem na linha de comando que é composta pelo sistema de compilação do projeto. A macro **$(NoInherit)** faz com que qualquer ocorrência de $(Inherit) seja ignorada e faz com que as propriedades que seriam herdadas não sejam mais. Por exemplo, por padrão a macro $(Inherit) faz com que arquivos especificados usando a opção do compilador [/I (diretórios de inclusão adicionais)](../build/reference/i-additional-include-directories.md) sejam acrescentados à linha de comando.

No Visual Studio 2010, há suporte para a herança, especificando o valor de uma propriedade como a concatenação de um ou mais valores literais e macros de propriedade. Não há suporte para as macros **$(Inherit)** e **$(NoInherit)** .

No exemplo a seguir, uma lista delimitada por ponto e vírgula é atribuída a uma propriedade em uma página de propriedades. A lista consiste na concatenação do *\<value>* literal e do valor da propriedade `MyProperty`, que é acessada usando a notação de macro, **$(** <em>MyProperty</em> **)** .

```
Property=<value>;$(MyProperty)
```

## <a name="vcxprojuser-files"></a>arquivos. vcxproj. User

Um arquivo de usuário (.vcxproj.user) armazena as propriedades específicas do usuário, por exemplo, depuração e configurações de implantação. O arquivo *vcxproj. User* se aplica a todos os projetos para um usuário específico.

## <a name="vcxprojfilters-file"></a>arquivo. vcxproj. Filters

Quando **Gerenciador de soluções** é usado para adicionar um arquivo a um projeto, o arquivo de filtros ( *. vcxproj. Filters*) define onde, na exibição de árvore de **Gerenciador de soluções** , o arquivo é adicionado, com base em sua extensão de nome de arquivo.

## <a name="vc-directories-settings"></a>Configurações de diretórios do VC + +

As configurações de diretórios do Visual C++ são especificadas na [Página de propriedades dos diretórios do VC++](../ide/vcpp-directories-property-page.md). No Visual Studio 2008 e versões anteriores, as configurações de diretórios se aplicam por usuário e a lista de diretórios excluídos é especificada no arquivo *SYSINCL. dat* .

Você não poderá alterar as configurações de diretórios do VC++ se executar [devenv /resetsettings](/visualstudio/ide/reference/resetsettings-devenv-exe) na linha de comando. Também não será possível alterar as configurações se você abrir o menu **Ferramentas**, clicar em **Importar e Exportar Configurações** e selecionar a opção **Redefinir todas as configurações**.

Para migrar as configurações de diretórios do VC + + de um arquivo *. vssettings* que foi criado por uma versão anterior do Visual Studio:

1. Abra o menu **ferramentas** , clique em **importar e exportar configurações**
2. Selecione **Importar configurações de ambiente selecionadas**
3. Siga as instruções no assistente.

## <a name="see-also"></a>Confira também

[MSBuild na linha de comando – C++](../build/msbuild-visual-cpp.md)
