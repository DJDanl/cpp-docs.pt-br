---
title: Como modificar propriedades e destinos de projeto C++ sem alterar o arquivo de projeto
ms.date: 11/28/2018
helpviewer_keywords:
- project properties [C++], modifying outside project file
ms.openlocfilehash: a1ba5647542f69cfc7748986e512e74401bfc404
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833355"
---
# <a name="how-to-modify-c-project-properties-and-targets-without-changing-the-project-file"></a>Como modificar propriedades e destinos de projeto C++ sem alterar o arquivo de projeto

Substitua as propriedades e os destinos do projeto no prompt de comando do MSBuild sem alterar o arquivo de projeto. Isso é útil quando você deseja aplicar algumas propriedades temporária ou ocasionalmente. Isso pressupõe noções básicas do MSBuild. Para mais informações, consulte [MSBuild](/visualstudio/msbuild/msbuild).

> [!IMPORTANT]
> Use o Editor de XML no Visual Studio ou qualquer editor de texto para criar o arquivo .props ou .targets. Não use o **Gerenciador de Propriedades** neste cenário porque ele adiciona as propriedades ao arquivo de projeto.

*Para substituir as propriedades do projeto:*

1. Crie um arquivo .props que especifica as propriedades que você deseja substituir.

1. No prompt de comando: defina ForceImportBeforeCppTargets="C:\sources\my_props.props"

*Para substituir os destinos do projeto:*

1. Criar um arquivo .targets com sua implementação ou um destino específico

2. No prompt de comando: defina ForceImportAfterCppTargets ="C:\sources\my_target.targets"

Defina também qualquer uma das opções na linha de comando do MSBuild usando a opção /p:

```cmd
> msbuild myproject.sln /p:ForceImportBeforeCppTargets="C:\sources\my_props.props"
> msbuild myproject.sln /p:ForceImportAfterCppTargets="C:\sources\my_target.targets"
```

A substituição de propriedades e destinos dessa maneira é equivalente à adição das seguintes importações a todos os arquivos .vcxproj da solução:

```cmd
<Import Project=="C:\sources\my_props.props" />
<Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
<Import Project==" C:\sources\my_target.targets"" />
```
