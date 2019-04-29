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
ms.openlocfilehash: 584958ac51bdc491ad1bdd16117ecaad6e000ec7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62321066"
---
# <a name="midl-specify-midl-command-line-options"></a>/MIDL (especificar opções de linha de comando MIDL)

Especifica um arquivo de resposta para opções de linha de comando MIDL

## <a name="syntax"></a>Sintaxe

> **/MIDL:\@**<em>file</em>

## <a name="arguments"></a>Arguments

*file*<br/>
O nome do arquivo que contém [opções de linha de comando MIDL](/windows/desktop/Midl/general-midl-command-line-syntax).

## <a name="remarks"></a>Comentários

Todas as opções para a conversão de um arquivo IDL para um arquivo TLB devem ser fornecidas em *arquivo*; Opções de linha de comando MIDL não podem ser especificadas na linha de comando do vinculador. Se /MIDL não for especificado, o compilador MIDL será invocado com apenas o nome do arquivo IDL e nenhuma outra opção.

O arquivo deve conter uma opção de linha de comando de MIDL por linha.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **IDL incorporado** página de propriedades.

1. Modificar a **comandos de MIDL** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MidlCommandFile%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)<br/>
[/IDLOUT (nomear arquivos de saída MIDL)](idlout-name-midl-output-files.md)<br/>
[/IGNOREIDL (não processar atributos em MIDL)](ignoreidl-don-t-process-attributes-into-midl.md)<br/>
[/TLBOUT (nomear arquivo .TLB)](tlbout-name-dot-tlb-file.md)<br/>
[Compilando um programa atribuído](../../windows/building-an-attributed-program.md)
