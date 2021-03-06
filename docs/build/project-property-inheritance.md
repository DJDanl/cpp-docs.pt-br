---
title: Herança de propriedade em projetos do Visual Studio – C++
description: Como a herança de propriedade funciona em projetos nativos (MSBuild) do Visual Studio C++.
ms.date: 02/21/2020
helpviewer_keywords:
- C++ projects, property inheritance
ms.openlocfilehash: 17b23426f70bb2d306491e538d30cffc0f202362
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919209"
---
# <a name="property-inheritance-in-visual-studio-projects"></a>Herança de propriedade em projetos do Visual Studio

O sistema de projeto nativo do Visual Studio é baseado no MSBuild. O MSBuild define formatos de arquivo e regras para compilar projetos de qualquer tipo. Ele gerencia a maior parte da complexidade da compilação para várias configurações e plataformas. Você achará útil entender como ele funciona. Isso é especialmente importante se você quiser definir configurações personalizadas. Ou, para criar conjuntos reutilizáveis de propriedades que você pode compartilhar e importar em vários projetos.

## <a name="the-vcxproj-file-props-files-and-targets-files"></a>O arquivo .vcxproj, arquivos .props e arquivos .targets

::: moniker range="msvc-140"

As propriedades do projeto são armazenadas em vários arquivos. Alguns são armazenados diretamente no *`.vcxproj`* arquivo do projeto. Outros são provenientes de outros *`.targets`* ou *`.props`* arquivos que o arquivo de projeto importa e que fornecem valores padrão. Você encontrará os arquivos de projeto do Visual Studio 2015 em uma pasta específica de localidade no diretório base, *`%ProgramFiles(x86)%\MSBuild\Microsoft.Cpp\v4.0\v140`* .

::: moniker-end

::: moniker range="msvc-150"

As propriedades do projeto são armazenadas em vários arquivos. Alguns são armazenados diretamente no *`.vcxproj`* arquivo do projeto. Outros são provenientes de outros *`.targets`* ou *`.props`* arquivos que o arquivo de projeto importa e que fornecem valores padrão. Você encontrará os arquivos de projeto do Visual Studio 2017 em uma pasta específica de localidade no diretório base, *`%VSINSTALLDIR%Common7\IDE\VC\VCTargets\`* .

::: moniker-end

::: moniker range=">=msvc-160"

As propriedades do projeto são armazenadas em vários arquivos. Alguns são armazenados diretamente no *`.vcxproj`* arquivo do projeto. Outros são provenientes de outros *`.targets`* ou *`.props`* arquivos que o arquivo de projeto importa e que fornecem valores padrão. Você encontrará os arquivos de projeto do Visual Studio em uma pasta específica de localidade no diretório base, *`%VSINSTALLDIR%MSBuild\Microsoft\VC\<version>`* . O `<version>` é específico para a versão do Visual Studio. É *`v160`* para o Visual Studio 2019.

::: moniker-end

As propriedades também são armazenadas em qualquer *`.props`* arquivo personalizado que você possa adicionar ao seu próprio projeto. É altamente recomendável que você *não* edite esses arquivos manualmente. Em vez disso, use as páginas de propriedades no IDE para modificar todas as propriedades, especialmente aquelas que participam da herança, a menos que você tenha uma compreensão profunda do MSBuild e dos *`.vcxproj`* arquivos.

Conforme mostrado anteriormente, a mesma propriedade para a mesma configuração pode receber um valor diferente nesses arquivos diferentes. Quando você cria um projeto, o mecanismo do MSBuild avalia o arquivo de projeto e todos os arquivos importados em uma ordem bem definida que é descrita posteriormente. Conforme cada arquivo for avaliado, os valores de propriedade definidos nesse arquivo substituirão os valores existentes. Quaisquer valores que não são especificados são herdados de arquivos que foram avaliados anteriormente. Quando você define uma propriedade com páginas de propriedades, também é importante prestar atenção ao local em que você a define. Se você definir uma propriedade como "X" em um *`.props`* arquivo, mas a propriedade estiver definida como "y" no arquivo de projeto, o projeto será criado com a propriedade definida como "y". Se a mesma propriedade for definida como "Z" em um item de projeto, como um *`.cpp`* arquivo, o mecanismo do MSBuild usará o valor "Z".

Veja a árvore básica de herança:

1. Configurações padrão do conjunto de ferramentas do MSBuild CPP (o *`Microsoft.Cpp.Default.props`* arquivo no diretório base, que é importado pelo *`.vcxproj`* arquivo).

1. Folhas de propriedade

1. *`.vcxproj`* Grupo. (Esse arquivo pode substituir as configurações padrão e folha de propriedades.)

1. Metadados de itens

> [!TIP]
> Em uma página de propriedades, uma propriedade em **negrito** é definida no contexto atual. Uma propriedade na fonte normal é herdada.

## <a name="view-an-expanded-project-file-with-all-imported-values"></a>Exibir um arquivo de projeto expandido com todos os valores importados

Às vezes é útil ver o arquivo expandido para determinar como um valor de propriedade fornecido é herdado. Para ver a versão expandida, digite o comando a seguir em um prompt de comando do Visual Studio. (Altere os nomes dos arquivos de espaço reservado com o nome que você deseja usar.)

> **msbuild /pp:**_temp_**.txt** _myapp_**.vcxproj**

Arquivos de projeto expandidos podem ser grandes e difíceis de entender, a menos que você esteja familiarizado com o MSBuild. Veja a estrutura básica de um arquivo de projeto:

1. Propriedades fundamentais do projeto, que não são expostas no IDE.

1. Importação do *`Microsoft.cpp.default.props`* , que define algumas propriedades básicas, independentes de conjunto de ferramentas.

1. Propriedades de Configuração Global (expostas como propriedades padrão de **PlatformToolset** e **Project** na página **Configuração Geral** ). Essas propriedades determinam quais conjuntos de ferramentas e folhas de propriedades intrínsecas são importadas na *`Microsoft.cpp.props`* próxima etapa.

1. Importação do *`Microsoft.cpp.props`* , que define a maioria dos padrões do projeto.

1. Importação de todas as folhas de propriedades, incluindo *`.user`* arquivos. Essas folhas de propriedade podem substituir tudo, exceto as propriedades padrão **PlatformToolset** e **Project** .

1. O restante das propriedades de configuração do projeto. Esses valores podem substituir o que foi definido nas folhas de propriedade.

1. Itens (arquivos) com seus metadados. Esses itens são sempre a última palavra nas regras de avaliação do MSBuild, mesmo que eles ocorram antes de outras propriedades e importações.

Para obter mais informações, consulte [Propriedades do MSBuild](/visualstudio/msbuild/msbuild-properties).

## <a name="build-configurations"></a>Configurações de build

Uma configuração é apenas um grupo arbitrário de propriedades que recebem um nome. O Visual Studio fornece configurações de depuração e versão. Cada um define várias propriedades adequadamente para uma compilação de depuração ou Build de versão. Você pode usar o **Configuration Manager** para definir configurações personalizadas. São uma maneira conveniente de agrupar Propriedades para um tipo específico de compilação.

Para ter uma ideia melhor das configurações de compilação, abra **Gerenciador de propriedades** . Você pode abri-lo escolhendo **exibir > Gerenciador de propriedades** ou **exibir > outras Gerenciador de propriedades de > do Windows** , dependendo de suas configurações. **Gerenciador de propriedades** tem nós para cada par de configuração e plataforma no projeto. Em cada um desses nós há nós para folhas de Propriedades ( *`.props`* arquivos) que definem algumas propriedades específicas para essa configuração.

![Gerenciador de Propriedades](media/property-manager.png "Gerenciador de Propriedades")

Por exemplo, você pode ir para o painel geral nas páginas de propriedades. Altere a propriedade conjunto de caracteres para "não definido" em vez de "usar Unicode" e clique em **OK** . A Gerenciador de Propriedades agora não mostra nenhuma folha de propriedades de **suporte Unicode** . Ele foi removido para a configuração atual, mas ainda está lá para outras configurações.

Para obter mais informações sobre o Gerenciador de Propriedades e as folhas de propriedades, confira [Compartilhar ou reutilizar as configurações de projeto do Visual Studio C++](create-reusable-property-configurations.md).

> [!TIP]
> O *`.user`* arquivo é um recurso herdado. Recomendamos que você o exclua para manter as propriedades agrupadas corretamente de acordo com a configuração e a plataforma.
