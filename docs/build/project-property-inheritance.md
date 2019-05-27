---
title: Herança de propriedade em projetos do Visual Studio – C++
ms.date: 05/16/2019
helpviewer_keywords:
- C++ projects, property inheritance
ms.openlocfilehash: 472700226ffc1f265f6fab84dbd44fca651b3c87
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837397"
---
# <a name="property-inheritance-in-visual-studio-projects"></a>Herança de propriedade em projetos do Visual Studio

O sistema de projeto do Visual Studio é baseado no MSBuild, que define os formatos de arquivo e as regras para a compilação de projetos de qualquer tipo. O MSBuild gerencia grande parte da complexidade da compilação para várias configurações e plataformas, mas você precisa entender um pouco sobre como ele funciona. Isso é especialmente importante se você deseja definir configurações personalizadas ou criar conjuntos reutilizáveis de propriedades que você pode compartilhar e importar para vários projetos.

## <a name="the-vcxproj-file-props-files-and-targets-files"></a>O arquivo .vcxproj, arquivos .props e arquivos .targets

As propriedades do projeto são armazenadas diretamente no arquivo de projeto (*.vcxproj) ou em outros arquivos .targets ou .props que são importados pelo arquivo de projeto e que fornecem valores padrão. No Visual Studio 2015, esses arquivos estão localizados em **\Arquivos de Programas (x86)\MSBuild\Microsoft.Cpp\v4.0\V140**. Para o Visual Studio 2017 ou o Visual Studio 2019, esses arquivos estão localizados em **\\Arquivos de Programas (x86)\\Microsoft Visual Studio\\&lt;2017 ou 2019>\\_edição_\\Common7\\IDE\\VC\\VCTargets**, em que _edição_ é a edição instalada do Visual Studio. As propriedades também são armazenadas em arquivos .props personalizados que você pode adicionar ao seu próprio projeto. É altamente recomendável que você NÃO edite esses arquivos manualmente e, em vez disso, use as páginas de propriedades no IDE para modificar todas as propriedades, especialmente aquelas que participam da herança, a menos que você tenha noções avançadas do MSBuild.

Conforme mostrado anteriormente, a mesma propriedade para a mesma configuração pode receber um valor diferente nesses arquivos diferentes. Quando você compila um projeto, o mecanismo MSBuild avalia o arquivo de projeto e todos os arquivos importados em uma ordem bem definida (descrita abaixo). Conforme cada arquivo for avaliado, os valores de propriedade definidos nesse arquivo substituirão os valores existentes. Os valores não especificados são herdados dos arquivos que foram avaliados anteriormente. Portanto, quando você define uma propriedade com páginas de propriedades, também é importante ficar atento ao local em que você a define. Se você definir uma propriedade como "X" em um arquivo .props, mas a propriedade for definida como "Y" no arquivo de projeto, o projeto será compilado com a propriedade definida como "Y". Se a mesma propriedade for definida como "Z" em um item de projeto, como um arquivo .cpp, o mecanismo MSBuild usará o valor "Z". 

Veja a árvore básica de herança:

1. Configurações padrão do Conjunto de Ferramentas MSBuild CPP (..\Arquivos de Programas\MSBuild\Microsoft.Cpp\v4.0\Microsoft.Cpp.Default.props, que é importado pelo arquivo .vcxproj)

2. Folhas de propriedade

3. Arquivo .vcxproj. (Pode substituir as configurações padrão e as da folha de propriedades.)

4. Metadados de itens

> [!TIP]
> Em uma página de propriedades, uma propriedade em `bold` é definida no contexto atual. Uma propriedade na fonte normal é herdada.

## <a name="view-an-expanded-project-file-with-all-imported-values"></a>Exibir um arquivo de projeto expandido com todos os valores importados

Às vezes é útil ver o arquivo expandido para determinar como um valor de propriedade fornecido é herdado. Para ver a versão expandida, digite o comando a seguir em um prompt de comando do Visual Studio. (Altere os nomes dos arquivos de espaço reservado com o nome que você deseja usar.)

**msbuild /pp:** *temp* **.txt** *myapp* **.vcxproj**

Os arquivos de projeto expandidos podem ser grandes e difíceis de entender, a menos que você esteja familiarizado com o MSBuild. Veja a estrutura básica de um arquivo de projeto:

1. Propriedades fundamentais do projeto, que não são expostas no IDE.

2. Importação de Microsoft.cpp.default.props, que define algumas propriedades básicas e independentes do conjunto de ferramentas.

3. Propriedades de Configuração Global (expostas como propriedades padrão de **PlatformToolset** e **Project** na página **Configuração Geral**). Essas propriedades determinam quais folhas de propriedade intrínseca e conjuntos de ferramentas são importados no Microsoft.cpp.props na próxima etapa.

4. Importação de Microsoft.cpp.props, que define a maioria dos padrões do projeto.

5. Importação de todas as folhas de propriedade, incluindo arquivos .user. Essas folhas de propriedade podem substituir tudo, exceto as propriedades padrão **PlatformToolset** e **Project**.

6. O restante das propriedades de configuração do projeto. Esses valores podem substituir o que foi definido nas folhas de propriedade.

7. Itens (arquivos) com seus metadados. Essas são sempre as últimas palavras em regras de avaliação do MSBuild, mesmo que ocorram antes de outras propriedades e importações.

Para mais informações, consulte [Propriedades do MSBuild](/visualstudio/msbuild/msbuild-properties).

## <a name="build-configurations"></a>Configurações de build

Uma configuração é apenas um grupo arbitrário de propriedades que recebem um nome. O Visual Studio fornece configurações de Depuração e Versão e cada uma define várias propriedades de maneira apropriada para um build de depuração ou de versão. Use o **Configuration Manager** para definir configurações personalizadas como uma maneira conveniente de agrupar propriedades para um tipo específico de build. 

Para obter uma ideia melhor das configurações de build, abra o **Gerenciador de Propriedades** escolhendo **Exibir &#124; Gerenciador de Propriedades** ou **Exibir &#124; Outras Janelas &#124; Gerenciador de Propriedades** dependendo das configurações. O **Gerenciador de Propriedades** contém nós para cada par de configuração/plataforma no projeto. Em cada um desses nós estão os nós das folhas de propriedades (arquivos .props) que definem algumas propriedades específicas para essa configuração.

![Gerenciador de Propriedades](media/property-manager.png "Property Manager")

Se você acessar o painel Geral nas páginas de propriedades e definir a propriedade Conjunto de Caracteres como "Não Definido", em vez de "Usar Unicode" e clicar em **OK**, o Gerenciador de Propriedades não mostrará nenhuma folha de propriedades **Suporte a Unicode** para a configuração atual, mas ela ainda estará presente para outras configurações.

Para obter mais informações sobre o Gerenciador de Propriedades e as folhas de propriedades, confira [Compartilhar ou reutilizar as configurações de projeto do Visual Studio C++](create-reusable-property-configurations.md).

> [!TIP]
> O arquivo .user é um recurso herdado, e recomendamos que você o exclua para manter as propriedades agrupadas corretamente de acordo com a configuração/plataforma.



