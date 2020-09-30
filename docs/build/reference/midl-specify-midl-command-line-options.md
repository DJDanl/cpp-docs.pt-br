---
title: /MIDL (especificar opções de linha de comando MIDL)
ms.date: 09/05/2018
f1_keywords:
- /midl
- VC.Project.VCLinkerTool.MidlCommandFile
helpviewer_keywords:
- -MIDL linker option
- MIDL
- /MIDL linker option
- MIDL linker option
- MIDL, command line options
ms.assetid: 22dc259e-b34c-4ed3-a380-4beb734482c1
ms.openlocfilehash: 3f1b6526f51e5aaa48008792361d3e63249d9f16
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502853"
---
# <a name="midl-specify-midl-command-line-options"></a>/MIDL (especificar opções de linha de comando MIDL)

Especifica um arquivo de resposta para opções de linha de comando MIDL

## <a name="syntax"></a>Sintaxe

> **/MIDL: \@ ** do <em>arquivo</em>

## <a name="arguments"></a>Argumentos

*file*<br/>
O nome do arquivo que contém [Opções de linha de comando de MIDL](/windows/win32/Midl/general-midl-command-line-syntax).

## <a name="remarks"></a>Comentários

Todas as opções para a conversão de um arquivo IDL em um arquivo TLB devem ser fornecidas no *arquivo*; As opções de linha de comando MIDL não podem ser especificadas na linha de comando do vinculador. Se/MIDL não for especificado, o compilador MIDL será invocado apenas com o nome do arquivo IDL e nenhuma outra opção.

O arquivo deve conter uma opção de linha de comando MIDL por linha.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**página de propriedades  >  **Linker**  >  **IDL incorporada** do vinculador Properties.

1. Modifique a propriedade de **comandos MIDL** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MidlCommandFile%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)<br/>
[/IDLOUT (arquivos de saída de MIDL de nome)](idlout-name-midl-output-files.md)<br/>
[/IGNOREIDL (não processar atributos no MIDL)](ignoreidl-don-t-process-attributes-into-midl.md)<br/>
[/TLBOUT (nome. Arquivo TLB)](tlbout-name-dot-tlb-file.md)<br/>
[Compilando um programa atribuído](../../windows/attributes/cpp-attributes-com-net.md)
