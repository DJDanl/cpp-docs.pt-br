---
title: Como integrar ferramentas personalizar a propriedades de projeto
description: Como integrar ferramentas personalizadas às propriedades do projeto em projetos do Visual Studio C++.
ms.date: 10/08/2020
helpviewer_keywords:
- 'MSBuild (C++), howto: integrate custom tools'
ms.openlocfilehash: 4b88bf94a92efaf5046fd83e5c6358f3fdf80895
ms.sourcegitcommit: 6e5429e076e552b32e8bdc49480c51498d7924c1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2020
ms.locfileid: "92099661"
---
# <a name="how-to-integrate-custom-tools-into-the-project-properties"></a>Como integrar ferramentas personalizar a propriedades de projeto

Você pode adicionar opções de ferramentas personalizadas à janela de **páginas de propriedades** do Visual Studio criando um arquivo XML.

A seção de **Propriedades de configuração** da janela **páginas de propriedades** exibe grupos de configuração conhecidos como *regras*. Cada regra contém as configurações para uma ferramenta ou um grupo de funcionalidades. Por exemplo, a regra **Vinculador** contém as configurações para a ferramenta do vinculador. As configurações em uma regra podem ser subdivididas em *categorias*.

Você pode criar um arquivo de regra que contém propriedades para sua ferramenta personalizada para que as propriedades sejam carregadas quando o Visual Studio for iniciado. Para obter informações sobre como modificar o arquivo, consulte [extensibilidade de plataforma parte 2](/archive/blogs/vsproject/platform-extensibility-part-2) no blog da equipe do projeto do Visual Studio.

::: moniker range="vs-2015"

A pasta na qual o arquivo de regra deve ser colocado depende da localidade e da versão do Visual Studio em uso. Em um prompt de comando do desenvolvedor do Visual Studio 2015 ou anterior, a pasta regras é *`%ProgramFiles(x86)%\MSBuild\Microsoft.Cpp\v4.0\<version>\<locale>`* . O `<version>` valor está *`v140`* no Visual Studio 2015. O `<locale>` é um LCID, por exemplo, `1033` para inglês. Você usará um caminho diferente para cada edição do Visual Studio que está instalado e para cada idioma. Por exemplo, o caminho da pasta regras padrão para o Visual Studio 2015 Community Edition em inglês pode ser *`C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\v140\1033\`* .

::: moniker-end

::: moniker range="vs-2017"

A pasta na qual o arquivo de regra deve ser colocado depende da localidade e da versão do Visual Studio em uso. Em um prompt de comando do desenvolvedor do Visual Studio 2017, a pasta regras é *`%VSINSTALLDIR%Common7\IDE\VC\VCTargets\<locale>\`* . O `<locale>` é um LCID, por exemplo, `1033` para inglês. Em um prompt de comando do desenvolvedor do Visual Studio 2015 ou anterior, a pasta regras é *`%ProgramFiles(x86)%\MSBuild\Microsoft.Cpp\v4.0\<version>\<locale>\`* , em que o `<version>` valor está *`v140`* no Visual Studio 2015. Você usará um caminho diferente para cada edição do Visual Studio que está instalado e para cada idioma. Por exemplo, o caminho da pasta regras padrão para o Visual Studio 2017 Community Edition em inglês pode ser *`C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\VC\VCTargets\1033\`* .

::: moniker-end

::: moniker range=">=vs-2019"

A pasta na qual o arquivo de regra deve ser colocado depende da localidade e da versão do Visual Studio em uso. Em um prompt de comando do desenvolvedor do Visual Studio 2019 ou posterior, a pasta regras é *`%VSINSTALLDIR%MSBuild\Microsoft\VC\<version>\<locale>\`* , em que o `<version>` valor está *`v160`* no Visual Studio 2019. O `<locale>` é um LCID, por exemplo, `1033` para inglês. No Visual Studio 2017, a pasta regras é *`%VSINSTALLDIR%Common7\IDE\VC\VCTargets\<locale>\`* . Em um prompt de comando do desenvolvedor do Visual Studio 2015 ou anterior, a pasta regras é *`%ProgramFiles(x86)%\MSBuild\Microsoft.Cpp\v4.0\<version>\<locale>\`* . Você usará um caminho diferente para cada edição do Visual Studio que está instalado e para cada idioma. Por exemplo, o caminho da pasta regras padrão para o Visual Studio 2019 Community Edition em inglês pode ser *`C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Microsoft\VC\v160\1033\`* .

::: moniker-end

### <a name="to-add-or-change-project-properties"></a>Para adicionar ou alterar as propriedades de projeto

1. No editor de XML, crie um arquivo XML.

1. Salve o arquivo na pasta regras padrão. Ajuste o caminho de acordo com a linguagem e a edição do Visual Studio. Cada regra na janela **Páginas de Propriedades** é representada por um arquivo XML nessa pasta. Verifique se o arquivo está exclusivamente nomeado na pasta.

1. Copie o conteúdo de um arquivo de regras existente, como *`rc.xml`* , feche-o sem salvar as alterações e, em seguida, Cole o conteúdo no novo arquivo XML. Você pode copiar qualquer arquivo de esquema XML para usar como um modelo. Escolha um que seja semelhante à sua ferramenta.

1. No novo arquivo XML, modifique o conteúdo de acordo com suas necessidades. Lembre-se de alterar o **Nome da Regra** e **Rule.DisplayName** na parte superior do arquivo.

1. Salve suas alterações e feche o arquivo.

1. Os arquivos XML na pasta regras são carregados quando o Visual Studio é iniciado. Para testar o novo arquivo, reinicie o Visual Studio.

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse em um projeto e escolha **Propriedades**. Na janela **páginas de propriedades** , verifique se há um novo nó com o nome da sua regra.

## <a name="see-also"></a>Veja também

[MSBuild na linha de comando-C++](msbuild-visual-cpp.md)
