---
title: /LINKREPROTARGET (nome do arquivo de reprodução de link)
description: Opção de ferramenta de biblioteca ou vinculador para definir um nome de arquivo de destino para uma reprodução de link.
ms.date: 09/24/2019
f1_keywords:
- /LINKREPROTARGET
helpviewer_keywords:
- LINKREPROTARGET linker option
- /LINKREPROTARGET linker option
- -LINKREPROTARGET linker option
- linker repro reporting
ms.openlocfilehash: d629c4c2665239d03f38569677fa579b6c8d37e0
ms.sourcegitcommit: a361362354f6ce51eda4ffdb016b81c24cd225cb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/01/2019
ms.locfileid: "71712675"
---
# <a name="linkreprotarget-link-repro-file-name"></a>/LINKREPROTARGET (nome do arquivo de reprodução de link)

Informa ao vinculador ou à ferramenta de biblioteca para gerar uma reprodução de link somente quando o destino tiver o nome de arquivo especificado.

## <a name="syntax"></a>Sintaxe

> **/LINKREPROTARGET:** _nome-do-arquivo_

### <a name="arguments"></a>Argumentos

**/LINKREPROTARGET:** _file-name_\
O nome do arquivo de destino para filtrar. Uma reprodução de link só é gerada quando o arquivo nomeado é o destino de saída. Os nomes de arquivo que incluem espaços devem ser colocados entre aspas duplas. O nome do arquivo deve incluir o nome de base e a extensão, mas não o caminho.

## <a name="remarks"></a>Comentários

A opção **/LINKREPROTARGET** é usada para especificar um nome de arquivo de destino para gerar uma *reprodução de link* para. Uma reprodução de link é um conjunto de artefatos de compilação que permite à Microsoft reproduzir um problema que ocorre no momento do link ou durante operações de biblioteca. A ferramenta de biblioteca ou vinculador produz uma reprodução de link quando você especifica a opção [/LINKREPRO](linkrepro.md) ou quando você define a variável de ambiente `link_repro` em seu ambiente de compilação de linha de comando.

A opção **/LINKREPROTARGET** é útil em compilações complexas que invocam o vinculador ou a ferramenta de biblioteca mais de uma vez. Ele permite que você especifique um destino específico para a reprodução do link, como o *problem. dll*. Ele permite que você gere a reprodução do link somente quando a ferramenta produz um arquivo específico.

Para obter mais informações sobre como e quando criar uma reprodução de link, consulte a seção [link repróss](../../overview/how-to-report-a-problem-with-the-visual-cpp-toolset.md#link-repros) de [como relatar um problema com o C++ conjunto de ferramentas da Microsoft](../../overview/how-to-report-a-problem-with-the-visual-cpp-toolset.md).

As opções **/LINKREPRO** e [/out](out-output-file-name.md) devem ser definidas para que a opção **/LINKREPROTARGET** tenha qualquer efeito.

O **/LINKREPROTARGET** está disponível a partir do Visual Studio 2019 versão 16,1.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **página de propriedades de** **linha de comando**  > **vinculador** > .

1. Insira a opção **/LINKREPROTARGET:** _File-Name_ na caixa **Opções adicionais** . Escolha **OK** para aplicar a alteração.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[referência do vinculador MSVC](linking.md)\
[Opções do vinculador MSVC](linker-options.md)\
[/LINKREPRO](linkrepro.md)
