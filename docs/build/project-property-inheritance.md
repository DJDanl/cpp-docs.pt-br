---
title: Herança de propriedade em projetos do Visual Studio – C++
description: Como funciona a herança de propriedades em projetos nativos (MSBuild) Visual Studio C++.
ms.date: 02/21/2020
helpviewer_keywords:
- C++ projects, property inheritance
ms.openlocfilehash: 4740c479c6cc7c877fd72b7828a8e4811826de6c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328469"
---
# <a name="property-inheritance-in-visual-studio-projects"></a>Herança de propriedade em projetos do Visual Studio

O sistema de projeto nativo do Visual Studio é baseado no MSBuild. O MSBuild define formatos de arquivos e regras para a construção de projetos de qualquer tipo. Ele gerencia a maior parte da complexidade de construção para múltiplas configurações e plataformas. Você vai achar útil entender como funciona. Isso é especialmente importante se você quiser definir configurações personalizadas. Ou, para criar conjuntos reutilizáveis de propriedades que você pode compartilhar e importar em vários projetos.

## <a name="the-vcxproj-file-props-files-and-targets-files"></a>O arquivo .vcxproj, arquivos .props e arquivos .targets

As propriedades do projeto são armazenadas diretamente no arquivo do projeto (*`.vcxproj`*) ou em outros *`.targets`* arquivos *`.props`* que o arquivo do projeto importa e que fornecem valores padrão. Para o Visual Studio 2015, *`\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V140`* esses arquivos estão localizados em . Para o Visual Studio 2017, *`\Program Files (x86)\Microsoft Visual Studio\2017\<edition>\Common7\IDE\VC\VCTargets`* esses *`<edition>`* arquivos estão localizados em , onde está instalado o Visual Studio edição. No Visual Studio 2019, esses *`\Program Files (x86)\Microsoft Visual Studio\2019\<edition>\MSBuild\Microsoft\VC\v160`* arquivos estão localizados em . As propriedades também são *`.props`* armazenadas em quaisquer arquivos personalizados que você possa adicionar ao seu próprio projeto. Recomendamos que você NÃO edite esses arquivos manualmente. Em vez disso, use as páginas de propriedade no IDE para modificar todas as propriedades, especialmente as que participam da herança, a menos que você tenha uma compreensão profunda do MSBuild.

Conforme mostrado anteriormente, a mesma propriedade para a mesma configuração pode receber um valor diferente nesses arquivos diferentes. Quando você compila um projeto, o mecanismo MSBuild avalia o arquivo de projeto e todos os arquivos importados em uma ordem bem definida (descrita abaixo). Conforme cada arquivo for avaliado, os valores de propriedade definidos nesse arquivo substituirão os valores existentes. Todos os valores que não são especificados são herdados de arquivos que foram avaliados anteriormente. Quando você define uma propriedade com páginas de propriedade, também é importante prestar atenção onde você defini-lo. Se você definir uma propriedade para *`.props`* "X" em um arquivo, mas a propriedade estiver definida como "Y" no arquivo do projeto, então o projeto será construído com a propriedade definida como "Y". Se a mesma propriedade estiver definida como "Z" em *`.cpp`* um item de projeto, como um arquivo, o mecanismo MSBuild usará o valor "Z".

Veja a árvore básica de herança:

1. Configurações padrão do conjunto de ferramentas MSBuild CPP (.. \Arquivos do programa\MSBuild\Microsoft.Cpp\v4.0\Microsoft.Cpp.Default.props, que *`.vcxproj`* é importado pelo arquivo.)

1. Folhas de propriedade

1. *`.vcxproj`* Arquivo. (Pode substituir as configurações padrão e as da folha de propriedades.)

1. Metadados de itens

> [!TIP]
> Em uma página de propriedade, uma propriedade em **negrito** é definida no contexto atual. Uma propriedade na fonte normal é herdada.

## <a name="view-an-expanded-project-file-with-all-imported-values"></a>Exibir um arquivo de projeto expandido com todos os valores importados

Às vezes é útil ver o arquivo expandido para determinar como um valor de propriedade fornecido é herdado. Para ver a versão expandida, digite o comando a seguir em um prompt de comando do Visual Studio. (Altere os nomes dos arquivos de espaço reservado com o nome que você deseja usar.)

> **msbuild /pp:**_temp_**.txt** _myapp_**.vcxproj**

Arquivos de projeto expandidos podem ser grandes e difíceis de entender, a menos que você esteja familiarizado com o MSBuild. Veja a estrutura básica de um arquivo de projeto:

1. Propriedades fundamentais do projeto, que não estão expostas no IDE.

1. Importação *`Microsoft.cpp.default.props`* de , que define algumas propriedades básicas, independentes de conjunto de ferramentas.

1. Propriedades de Configuração Global (expostas como propriedades padrão de **PlatformToolset** e **Project** na página **Configuração Geral**). Essas propriedades determinam em *`Microsoft.cpp.props`* qual conjunto de ferramentas e folhas de propriedade intrínsecas são importadas na próxima etapa.

1. Importação *`Microsoft.cpp.props`* de , que define a maioria dos padrões do projeto.

1. Importação de todas as *`.user`* folhas de propriedade, incluindo arquivos. Essas folhas de propriedade podem substituir tudo, exceto as propriedades padrão **PlatformToolset** e **Project**.

1. O resto das propriedades de configuração do projeto. Esses valores podem substituir o que foi definido nas folhas de propriedade.

1. Itens (arquivos) com seus metadados. Esses itens são sempre a última palavra nas regras de avaliação do MSBuild, mesmo que ocorram antes de outras propriedades e importações.

Para obter mais informações, consulte [MSBuild Properties](/visualstudio/msbuild/msbuild-properties).

## <a name="build-configurations"></a>Configurações de build

Uma configuração é apenas um grupo arbitrário de propriedades que recebem um nome. O Visual Studio fornece configurações de Debug e Release. Cada um define várias propriedades apropriadamente para uma compilação de depuração ou compilação de liberação. Você pode usar o **Gerenciador de Configuração** para definir configurações personalizadas. Eles são uma maneira conveniente de agrupar propriedades para um sabor específico de construção.

Para ter uma ideia melhor das configurações de construção, abra **o Property Manager**. Você pode abri-lo escolhendo **Exibir > Gerenciador de Propriedades** ou exibir > Outros > Gerenciador de Propriedades do **Windows,** dependendo das configurações. **O Property Manager** tem nós para cada configuração e par de plataformas no projeto. Em cada um desses nós estão nós para*`.props`* folhas de propriedade (arquivos) que definem algumas propriedades específicas para essa configuração.

![Gerenciador de Propriedades](media/property-manager.png "Gerenciador de Propriedades")

Por exemplo, você pode ir para o painel Geral nas Páginas de Propriedade. Altere a propriedade ''Não definir', em vez de "Usar Unicode", e clique em **OK**. O Gerenciador de Propriedades agora não mostra nenhuma folha de propriedade **de suporte unicode.** É removido para a configuração atual, mas ainda está lá para outras configurações.

Para obter mais informações sobre o Gerenciador de Propriedades e as folhas de propriedades, confira [Compartilhar ou reutilizar as configurações de projeto do Visual Studio C++](create-reusable-property-configurations.md).

> [!TIP]
> O *`.user`* arquivo é um recurso legado. Recomendamos que você o exclua, para manter as propriedades corretamente agrupadas de acordo com a configuração e a plataforma.
