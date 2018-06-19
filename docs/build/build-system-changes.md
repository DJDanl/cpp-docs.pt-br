---
title: Alterações no sistema de compilação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
f1_keywords:
- vc.msbuild.changes
dev_langs:
- C++
helpviewer_keywords:
- Build system changes, project file (.vcxprog)
- Build system changes, custom build rules
- Build system changes, MSBuild
- MSBuild, build system changes
- Build system changes, .vsprops
- Build system changes, $(Inherit)
- Build system changes, $(NoInherit)
ms.assetid: e564d95f-a6cc-4d97-b57e-1a71daf66f4a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 01eb3a38ddaf7cdb1d54061e48680396f16b25e0
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32363315"
---
# <a name="build-system-changes"></a>Alterações no sistema de build
O sistema MSBuild é usado para criar projetos do Visual C++. No entanto, no Visual Studio 2008 e versões anteriores, o sistema VCBuild foi usado. Determinados tipos de arquivo e conceitos que dependiam VCBuild não existem ou estão representados de maneira diferente no sistema atual. Este documento aborda as diferenças no sistema de compilação atual.  
  
## <a name="vcproj-is-now-vcxproj"></a>. vcproj agora é. vcxproj  
 Arquivos de projeto não usam a extensão de nome de arquivo. vcproj. O Visual Studio converte automaticamente os arquivos de projeto que foram criados por uma versão anterior do Visual C++ para o formato usado pelo sistema atual. Para obter mais informações sobre como atualizar manualmente um projeto, consulte [/Upgrade (devenv.exe)](/visualstudio/ide/reference/upgrade-devenv-exe).  
  
 Na versão atual, a extensão de nome de arquivo para um arquivo de projeto é. vcxproj.  
  
## <a name="vsprops-is-now-props"></a>. vsprops agora é .props  
 Em versões anteriores, uma *da folha de propriedades do projeto* é um arquivo baseado em XML que tem uma extensão de nome de arquivo. vsprops. Uma folha de propriedades do projeto permite especificar opções para as ferramentas de compilação, como o compilador ou vinculador e criar macros definidas pelo usuário.  
  
 Na versão atual, a extensão de nome de arquivo para uma folha de propriedades do projeto é .props.  
  
## <a name="custom-build-rules-and-rules-files"></a>Arquivos. Rules e regras de compilação personalizada  
 Em versões anteriores, uma *arquivo de regra* é um arquivo baseado em XML que tem uma extensão de nome de arquivo. rules. Um arquivo de regra permite definir regras de compilação personalizada e incorporá-los ao processo de compilação de um projeto do Visual C++. Uma regra de compilação personalizada, que pode ser associada uma ou mais extensões de nome de arquivo, permite que você passe os arquivos de entrada para uma ferramenta que cria um ou mais arquivos de saída.  
  
 Nesta versão, as regras de compilação personalizadas são representadas por três tipos de arquivo. XML, .props e. targets, em vez de um arquivo. rules. Quando um arquivo. rules que foi criado usando uma versão anterior do Visual C++ é migrado para a versão atual, arquivos. targets,. XML e .props equivalentes são criados e armazenados em seu projeto junto com o arquivo. Rules original.  
  
> [!IMPORTANT]
>  Na versão atual, o [!INCLUDE[TLA2#tla_ide](../build/includes/tla2sharptla_ide_md.md)] não oferece suporte à criação de novas regras. Por esse motivo, a maneira mais fácil de usar um arquivo de regra de um projeto que foi criado usando uma versão anterior do Visual C++ é migrar o projeto para a versão atual.  
  
## <a name="inheritance-macros"></a>Macros de herança  
 Em versões anteriores, o **Inherit** macro Especifica a ordem na qual as propriedades herdadas aparecem na linha de comando que é composta pelo sistema de compilação do projeto. O **noInherit** macro faz com que qualquer ocorrência de Inherit sejam ignorados e faz com que as propriedades que seriam contrário herdadas, não seja herdada. Por exemplo, por padrão a macro $ (Inherit) faz com que arquivos especificados usando o [/I (diretórios de inclusão adicionais)](../build/reference/i-additional-include-directories.md) opção de compilador a ser anexada à linha de comando.  
  
 Na versão atual, há suporte a herança, especificando o valor de uma propriedade como a concatenação de um ou mais valores literais e macros de propriedade. O **Inherit** e **noInherit** macros não têm suporte.  
  
 No exemplo a seguir, uma lista separada por ponto-e-vírgula é atribuída a uma propriedade em uma página de propriedades. A lista é composta de concatenação do  *\<valor >* literal e o valor da `MyProperty` propriedade, o que pode é acessada usando a notação de macro, **$(***MyProperty***)** .  
  
```  
Property=<value>;$(MyProperty)  
```  
  
## <a name="vcxprojuser-files"></a>. vcxproj.user arquivos  
 Um arquivo de usuário (. vcxproj.user) armazena as propriedades específicas do usuário, as configurações de exemplo, depuração e implantação. O arquivo vcxproj.user se aplica a todos os projetos para um usuário específico.  
  
## <a name="vcxprojfilters-file"></a>. vcxproj.filters arquivo  
 Quando **Solution Explorer** é usado para adicionar um arquivo a um projeto, o arquivo de filtros (. vcxproj.filters) define onde no **Solution Explorer** com base em sua extensão de nome de arquivo for adicionado, exibição de árvore.  
  
## <a name="vc-directories-settings"></a>Configurações de diretórios do VC + +  
 Configurações de diretórios do Visual C++ são especificadas no [página de propriedade de diretórios VC + +](../ide/vcpp-directories-property-page.md). Em versões anteriores do Visual Studio, as configurações de diretórios se aplicam a cada usuário e a lista de pastas excluídas é especificada no arquivo sysincl.dat.  
  
 Você não pode alterar as configurações de diretórios VC + + se você executar [/resetsettings devenv](/visualstudio/ide/reference/resetsettings-devenv-exe) na linha de comando. Você também não pode alterar as configurações se você abrir o **ferramentas** menu, clique em **importar e exportar configurações**e, em seguida, selecione o **redefinir todas as configurações** opção.  
  
 Migre as configurações de diretórios VC + + de um arquivo vssettings criado por uma versão anterior do Visual C++. Abra o **ferramentas** menu, clique em **importar e exportar configurações**, selecione **configurações de ambiente selecionadas de importação**e, em seguida, siga as instruções no assistente. Ou quando você inicia o Visual Studio pela primeira vez, no **escolher configurações de ambiente padrão** caixa de diálogo, selecione **migrar minhas configurações qualificadas de uma versão anterior e aplicá-las além das configurações padrão selecionado abaixo**.  
  
## <a name="see-also"></a>Consulte também  
 [MSBuild (Visual C++)](../build/msbuild-visual-cpp.md)