---
title: -MIDL (especificar opções de linha de comando MIDL) | Microsoft Docs
ms.custom: ''
ms.date: 09/05/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /midl
- VC.Project.VCLinkerTool.MidlCommandFile
dev_langs:
- C++
helpviewer_keywords:
- -MIDL linker option
- MIDL
- /MIDL linker option
- MIDL linker option
- MIDL, command line options
ms.assetid: 22dc259e-b34c-4ed3-a380-4beb734482c1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ce4c5159a66963268ae83e0c0adfdc082dfcc81c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45706934"
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

2. Selecione o **propriedades de configuração** > **vinculador** > **IDL incorporado** página de propriedades.

3. Modificar a **comandos de MIDL** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MidlCommandFile%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)<br/>
[/IDLOUT (nomear arquivos de saída MIDL)](../../build/reference/idlout-name-midl-output-files.md)
[/IGNOREIDL (não processar atributos em MIDL)](../../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)
[/TLBOUT (nome. O arquivo TLB)](../../build/reference/tlbout-name-dot-tlb-file.md)
[Compilando um programa atribuído](../../windows/building-an-attributed-program.md)