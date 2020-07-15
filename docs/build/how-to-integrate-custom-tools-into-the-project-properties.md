---
title: Como integrar ferramentas personalizar a propriedades de projeto
ms.date: 05/16/2019
helpviewer_keywords:
- 'msbuild (c++), howto: integrate custom tools'
ms.assetid: f32d91a4-44e9-4de3-aa9a-1c7f709ad2ee
ms.openlocfilehash: 5a96ffd15bb28022b3000252307c75b3383ac59c
ms.sourcegitcommit: 31a443c9998cf5cfbaff00fcf815b133f55b2426
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/14/2020
ms.locfileid: "86373743"
---
# <a name="how-to-integrate-custom-tools-into-the-project-properties"></a>Como integrar ferramentas personalizar a propriedades de projeto

Adicione opções de ferramentas personalizadas à janela **Páginas de Propriedades** do Visual Studio criando um arquivo de esquema XML subjacente.

A seção **Propriedades de Configuração** da janela **Páginas de Propriedades** exibe os grupos de configurações que são conhecidos como *regras*. Cada regra contém as configurações para uma ferramenta ou um grupo de funcionalidades. Por exemplo, a regra **Vinculador** contém as configurações para a ferramenta do vinculador. As configurações em uma regra podem ser subdivididas em *categorias*.

Este documento explica como criar um arquivo em um diretório definido que contém propriedades para a ferramenta personalizada, de modo que as propriedades sejam carregadas quando o Visual Studio for iniciado. Para obter informações sobre como modificar o arquivo, confira [Extensibilidade de plataforma parte 2](https://docs.microsoft.com/archive/blogs/vsproject/platform-extensibility-part-2) no blog da equipe de projeto do Visual Studio.

### <a name="to-add-or-change-project-properties"></a>Para adicionar ou alterar as propriedades de projeto

1. No editor de XML, crie um arquivo XML.

1. Salve o arquivo na pasta `VCTargets\1033` do Visual Studio. Você terá um caminho diferente para cada linguagem e edição instalada do Visual Studio. Por exemplo, o caminho da pasta padrão para o Visual Studio 2019 Community Edition em inglês é `C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\VC\VCTargets`. Ajuste o caminho de acordo com a linguagem e a edição do Visual Studio. Cada regra na janela **Páginas de Propriedades** é representada por um arquivo XML nessa pasta. Verifique se o arquivo está exclusivamente nomeado na pasta.

1. Copie o conteúdo de `%ProgramFiles%\Microsoft Visual Studio\2019\<VS Edition>\Common7\IDE\VC\VCTargets\<LCID>\cl.xml` (ou qualquer que seja seu caminho), feche-o sem salvar as alterações e, em seguida, cole o conteúdo no novo arquivo XML. Use qualquer arquivo de esquema XML – esse é apenas um que pode ser usado para que você comece com um modelo.

1. No novo arquivo XML, modifique o conteúdo de acordo com suas necessidades. Lembre-se de alterar o **Nome da Regra** e **Rule.DisplayName** na parte superior do arquivo.

1. Salve as alterações e feche o arquivo.

1. Os arquivos XML no `%ProgramFiles%\Microsoft Visual Studio\2019\<VS Edition>\Common7\IDE\VC\VCTargets\<LCID>` (ou no local em que você os salvou) são carregados quando o Visual Studio é iniciado. Portanto, para testar o novo arquivo, reinicie o Visual Studio.

1. No **Gerenciador de Soluções**, clique com o botão direito do mouse em um projeto e, em seguida, clique em **Propriedades**. Na janela **Páginas de Propriedades**, no painel esquerdo, verifique se há um novo nó com o nome da regra.

## <a name="see-also"></a>Confira também

[MSBuild na linha de comando-C++](msbuild-visual-cpp.md)
