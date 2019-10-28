---
title: /LINKREPRO (nome do diretório de reprodução de link)
description: Opção de ferramenta de biblioteca ou vinculador para definir o diretório para reprodução de um link.
ms.date: 09/24/2019
f1_keywords:
- /LINKREPRO
helpviewer_keywords:
- LINKREPRO linker option
- /LINKREPRO linker option
- -LINKREPRO linker option
- linker repro reporting
ms.openlocfilehash: d81fb529cdbb0741c6dff58032dad97df89b4d4f
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71686848"
---
# <a name="linkrepro-link-repro-directory-name"></a>/LINKREPRO (nome do diretório de reprodução de link)

Informa ao vinculador ou à ferramenta de biblioteca para gerar uma reprodução de link em um diretório especificado.

## <a name="syntax"></a>Sintaxe

> **/LINKREPRO:** _diretório-nome_

### <a name="arguments"></a>Argumentos

**/LINKREPRO:** _directory-Name_\
O diretório especificado pelo usuário para armazenar a reprodução do link. Os nomes de diretório que incluem espaços devem ser colocados entre aspas duplas.

## <a name="remarks"></a>Comentários

A opção **/LINKREPRO** é usada para criar uma *reprodução de link*. É um conjunto de artefatos de compilação que permite à Microsoft reproduzir um problema que ocorre no momento do link ou durante operações de biblioteca. Ele é útil para problemas como uma falha de back-end envolvendo geração de código de tempo de vinculação (LTCG), um erro de vinculador LNK1000 ou uma falha do vinculador. A ferramenta produz uma reprodução de link quando você especifica a opção de vinculador **/LINKREPRO** ou quando você define a variável de ambiente `link_repro` em seu ambiente de compilação de linha de comando. Para obter mais informações, consulte a seção [link repróss](../../overview/how-to-report-a-problem-with-the-visual-cpp-toolset.md#link-repros) de [como relatar um problema com o C++ conjunto de ferramentas da Microsoft](../../overview/how-to-report-a-problem-with-the-visual-cpp-toolset.md).

A opção de vinculador **/LINKREPRO** e a variável de ambiente `link_repro` exigem que você especifique um diretório de saída para a reprodução do link. Na linha de comando ou no IDE, especifique o diretório usando uma opção **/LINKREPRO:** _Directory-Name_ . O _nome de diretório_ especificado pode ser um caminho absoluto ou relativo, mas o diretório deve existir. A opção de linha de comando substitui qualquer valor de diretório definido na variável de ambiente `link_repro`.

Para obter informações sobre como limitar a geração de reprodução de link para um nome de arquivo de destino específico, consulte a opção [/LINKREPROTARGET](linkreprotarget.md) . Essa opção pode ser usada para especificar um destino específico para gerar uma reprodução de link para. É útil em compilações complexas que invocam o vinculador ou a ferramenta de biblioteca mais de uma vez.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **página de propriedades de** **linha de comando**  > **vinculador** > .

1. Insira a opção **/LINKREPRO:** _Directory-Name_ na caixa **Opções adicionais** . O valor do _diretório-nome_ especificado deve existir. Escolha **OK** para aplicar a alteração.

Depois de gerar a reprodução do link, abra essa página de propriedades novamente para remover a opção **/LINKREPRO** de suas compilações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[referência do vinculador MSVC](linking.md)\
[Opções do vinculador MSVC](linker-options.md)\
[/LINKREPROTARGET](linkreprotarget.md)
