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
ms.openlocfilehash: 273e4ea5776c0de5af16eba235c5775d6f4c4b54
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50525561"
---
# <a name="midl-specify-midl-command-line-options"></a>/MIDL (especificar opções de linha de comando MIDL)

Especifica um arquivo de resposta para opções de linha de comando MIDL

## <a name="syntax"></a>Sintaxe

> **/ MIDL:\@**<em>arquivo</em>

## <a name="arguments"></a>Arguments

*file*<br/>
O nome do arquivo que contém [opções de linha de comando MIDL](/windows/desktop/Midl/general-midl-command-line-syntax).

## <a name="remarks"></a>Comentários

Todas as opções para a conversão de um arquivo IDL para um arquivo TLB devem ser fornecidas em *arquivo*; Opções de linha de comando MIDL não podem ser especificadas na linha de comando do vinculador. Se /MIDL não for especificado, o compilador MIDL será invocado com apenas o nome do arquivo IDL e nenhuma outra opção.

O arquivo deve conter uma opção de linha de comando de MIDL por linha.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **IDL incorporado** página de propriedades.

1. Modificar a **comandos de MIDL** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MidlCommandFile%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)<br/>
[/IDLOUT (nomear arquivos de saída MIDL)](../../build/reference/idlout-name-midl-output-files.md)<br/>
[/IGNOREIDL (não processar atributos em MIDL)](../../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)<br/>
[/TLBOUT (nomear arquivo .TLB)](../../build/reference/tlbout-name-dot-tlb-file.md)<br/>
[Compilando um programa atribuído](../../windows/building-an-attributed-program.md)
