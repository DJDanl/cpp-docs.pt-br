---
title: Alterações no sistema de compilação
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
ms.openlocfilehash: 742b018ae96ff706336a81b49e1d8e5fb954d9b7
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57425439"
---
# <a name="build-system-changes"></a>Alterações no sistema de compilação

O sistema MSBuild é usado para compilar projetos do Visual C++. No entanto, no Visual Studio 2008 e versões anteriores, o sistema de VCBuild foi usado. Determinados tipos de arquivo e conceitos que dependem de VCBuild não existem ou são representados de maneira diferente no sistema atual. Este documento discute as diferenças no sistema de compilação atual.

## <a name="vcproj-is-now-vcxproj"></a>. vcproj agora é. vcxproj

Arquivos de projeto não for mais usam a extensão de nome de arquivo. vcproj. Visual Studio converte automaticamente os arquivos de projeto que foram criados por uma versão anterior do Visual C++ para o formato usado pelo sistema atual. Para obter mais informações sobre como atualizar manualmente um projeto, consulte [/Upgrade (devenv.exe)](/visualstudio/ide/reference/upgrade-devenv-exe).

Na versão atual, a extensão de nome de arquivo para um arquivo de projeto é. vcxproj.

## <a name="vsprops-is-now-props"></a>. vsprops agora é. Props

Em versões anteriores, uma *folha de propriedades do projeto* é um arquivo baseado em XML que tem uma extensão de nome de arquivo. vsprops. Uma folha de propriedades de projeto permite especificar opções para ferramentas de compilação, como o compilador ou vinculador e criar macros definidas pelo usuário.

Na versão atual, a extensão de nome de arquivo para uma folha de propriedades do projeto é. Props.

## <a name="custom-build-rules-and-rules-files"></a>Arquivos. Rules e regras de compilação personalizada

Em versões anteriores, uma *arquivo de regras* é um arquivo baseado em XML que tem uma extensão de nome de arquivo. rules. Um arquivo de regra permite definir regras de compilação personalizada e incorporá-los ao processo de compilação de um projeto do Visual C++. Uma regra de compilação personalizada, que pode ser associada uma ou mais extensões de nome de arquivo, permite que você passe os arquivos de entrada para uma ferramenta que cria um ou mais arquivos de saída.

Nesta versão, as regras de compilação personalizadas são representadas por três tipos de arquivo,. XML,. Props e. targets, em vez de um arquivo. rules. Quando um arquivo. rules que foi criado usando uma versão anterior do Visual C++ é migrado para a versão atual, arquivos. XML,. Props e. targets equivalentes são criados e armazenados em seu projeto junto com o arquivo. Rules original.

> [!IMPORTANT]
>  Na versão atual, o IDE não suporta a criação de novas regras. Por esse motivo, a maneira mais fácil de usar um arquivo de regras de um projeto que foi criado usando uma versão anterior do Visual C++ é migrar o projeto para a versão atual.

## <a name="inheritance-macros"></a>Macros de herança

Em versões anteriores, o **$ (Inherit)** macro Especifica a ordem na qual as propriedades herdadas são exibidos na linha de comando que é composta pelo sistema de compilação do projeto. O **$ (noInherit)** macro faz com que qualquer ocorrência de $ (Inherit) a serem ignorados e faz com que as propriedades que seriam caso contrário, herdadas, não a ser herdada. Por exemplo, por padrão a macro $ (Inherit) faz com que arquivos especificados usando o [/I (diretórios de inclusão adicionais)](../build/reference/i-additional-include-directories.md) opção do compilador a ser acrescentada à linha de comando.

Na versão atual, a herança é compatível com especificando o valor de uma propriedade como a concatenação de um ou mais valores literais e macros de propriedade. O **$ (Inherit)** e **$ (noInherit)** macros não têm suporte.

No exemplo a seguir, uma lista delimitada por ponto e vírgula é atribuída a uma propriedade em uma página de propriedades. A lista consiste de concatenação do  *\<valor >* literal e o valor da `MyProperty` propriedade, que pode é acessada usando a notação de macro, **$(**  <em>MyProperty</em>**)**.

```
Property=<value>;$(MyProperty)
```

## <a name="vcxprojuser-files"></a>.vcxproj.user Files

Um arquivo de usuário (. vcxproj) armazena as propriedades específicas do usuário, as configurações de exemplo, depuração e implantação. O arquivo vcxproj se aplica a todos os projetos para um usuário específico.

## <a name="vcxprojfilters-file"></a>.vcxproj.filters File

Quando **Gerenciador de soluções** é usado para adicionar um arquivo a um projeto, o arquivo de filtros (. vcxproj.filters) define onde na **Gerenciador de soluções** com base em sua extensão de nome de arquivo do arquivo for adicionado, exibição de árvore.

## <a name="vc-directories-settings"></a>Configurações de diretórios do VC + +

Configurações de diretórios do Visual C++ são especificadas na [página de propriedade dos diretórios VC + +](../ide/vcpp-directories-property-page.md). Em versões anteriores do Visual Studio, diretórios configurações aplicam-se por usuário e a lista de pastas excluídas é especificada no arquivo sysincl.dat.

Você não pode alterar as configurações de diretórios do VC + + se você executar [/resetsettings (devenv)](/visualstudio/ide/reference/resetsettings-devenv-exe) na linha de comando. Você também não é possível alterar as configurações se você abrir o **ferramentas** menu, clique em **Import and Export Settings**e, em seguida, selecione o **redefinir todas as configurações** opção.

Migre configurações de diretórios do VC + + de um arquivo. vssettings que é criado por uma versão anterior do Visual C++. Abra o **ferramentas** menu, clique em **Import and Export Settings**, selecione **importar configurações de ambiente selecionadas**e, em seguida, siga as instruções no assistente. Ou quando você inicia o Visual Studio pela primeira vez, sobre o **escolher configurações de ambiente padrão** caixa de diálogo, selecione **migrar minhas configurações qualificadas de uma versão anterior e aplicá-las além das configurações padrão selecionado abaixo**.

## <a name="see-also"></a>Consulte também

[MSBuild (Visual C++)](../build/msbuild-visual-cpp.md)
