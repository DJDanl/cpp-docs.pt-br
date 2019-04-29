---
title: Herança de propriedade em projetos do Visual Studio – C++
ms.date: 12/10/2018
helpviewer_keywords:
- Visual C++ projects, property inheritance
ms.openlocfilehash: edd6d3bf82f7a13cf6687abeba3758dcceca5e84
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62295430"
---
# <a name="property-inheritance-in-visual-studio-projects"></a>Herança de propriedade em projetos do Visual Studio

O sistema de projeto do Visual Studio é baseado no MSBuild, que define os formatos de arquivo e as regras para a criação de projetos de qualquer tipo. O MSBuild gerencia grande parte da complexidade da compilação para várias configurações e plataformas, mas você precisa entender um pouco sobre como ele funciona. Isso é especialmente importante se você deseja definir configurações personalizadas ou criar conjuntos reutilizáveis de propriedades que você pode compartilhar e importar para vários projetos.

## <a name="the-vcxproj-file-props-files-and-targets-files"></a>O arquivo. vcxproj, arquivos. Props e arquivos. targets

Propriedades do projeto são armazenadas diretamente no arquivo de projeto (*. vcxproj) ou em outros arquivos. targets ou. Props, que as importações do arquivo de projeto e a quais fornecem valores padrão. No Visual Studio 2015, esses arquivos estão localizados em **\Arquivos de Programas (x86)\MSBuild\Microsoft.Cpp\v4.0\V140**. No Visual Studio 2017, esses arquivos estão localizados em **\\Arquivos de Programas (x86)\\Microsoft Visual Studio\\2017\\_edition_\\Common7\\IDE\\VC\\VCTargets**, em que _edition_ é a edição instalada do Visual Studio. As propriedades também são armazenadas em arquivos .props personalizados que você pode adicionar ao seu próprio projeto. É altamente recomendável que você NÃO edite esses arquivos manualmente e, em vez disso, use as páginas de propriedades no IDE para modificar todas as propriedades, especialmente aquelas que participam da herança, a menos que você tenha noções avançadas do MSBuild.

Como mostrado anteriormente, a mesma propriedade para a mesma configuração pode ser atribuída um valor diferente nesses arquivos diferentes. Quando você compila um projeto, o mecanismo MSBuild avalia o arquivo de projeto e todos os arquivos importados em uma ordem bem definida (descrita abaixo). Conforme cada arquivo for avaliado, os valores de propriedade definidos nesse arquivo substituirão os valores existentes. Os valores não especificados são herdados dos arquivos que foram avaliados anteriormente. Portanto, quando você define uma propriedade com páginas de propriedades, também é importante ficar atento ao local em que você a define. Se você definir uma propriedade como "X" em um arquivo .props, mas a propriedade for definida como "Y" no arquivo de projeto, o projeto será compilado com a propriedade definida como "Y". Se a mesma propriedade for definida como "Z" em um item de projeto, como um arquivo .cpp, o mecanismo MSBuild usará o valor "Z". 

Veja a árvore básica de herança:

1. Configurações padrão do Conjunto de Ferramentas MSBuild CPP (..\Arquivos de Programas\MSBuild\Microsoft.Cpp\v4.0\Microsoft.Cpp.Default.props, que é importado pelo arquivo .vcxproj)

2. Folhas de propriedade

3. Arquivo .vcxproj. (Pode substituir as configurações padrão e as da folha de propriedades.)

4. Metadados de itens

> [!TIP]
> Em uma página de propriedades, uma propriedade em `bold` é definida no contexto atual. Uma propriedade na fonte normal é herdada.

## <a name="view-an-expanded-project-file-with-all-imported-values"></a>Exibir um arquivo de projeto expandidos com todos os valores importados

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

Para obter uma ideia melhor de configurações de compilação, abra **Gerenciador de propriedades** escolhendo **exibir &#124; Gerenciador de propriedades** ou **exibição &#124; Other Windows &#124; Gerenciador de propriedades**  dependendo de suas configurações. **Gerenciador de propriedades** tem nós para cada par de configuração/plataforma no projeto. Em cada um desses nós estão os nós das folhas de propriedades (arquivos .props) que definem algumas propriedades específicas para essa configuração.

![Gerenciador de Propriedades](media/property-manager.png "Property Manager")

Se você vai para o painel Geral nas páginas de propriedades e defina a propriedade do conjunto de caracteres para "Não configurado", em vez de "Uso de Unicode" e clique em **Okey**, o Gerenciador de propriedade mostrará nenhum **suporte a Unicode** folha de propriedades a configuração atual, mas ele ainda estará lá para outras configurações.

Para obter mais informações sobre o Gerenciador de propriedades e folhas de propriedades, consulte [resuse ou compartilhamento de configurações de projeto do Visual Studio C++](create-reusable-property-configurations.md).

> [!TIP]
> O arquivo .user é um recurso herdado, e recomendamos que você o exclua para manter as propriedades agrupadas corretamente de acordo com a configuração/plataforma.



