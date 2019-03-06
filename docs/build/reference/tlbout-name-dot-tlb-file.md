---
title: /TLBOUT (nomear arquivo .TLB)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.TypeLibraryFile
- /tlbout
helpviewer_keywords:
- tlb files, renaming
- TLBOUT linker option
- /TLBOUT linker option
- .tlb files, renaming
- -TLBOUT linker option
ms.assetid: 0df6d078-2e48-46c9-a1a5-02674d85dce8
ms.openlocfilehash: 3eaf4305c58ca70619e032f80e661b9c768f7813
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57425517"
---
# <a name="tlbout-name-tlb-file"></a>/TLBOUT (nomear arquivo .TLB)

```
/TLBOUT:[path\]filename
```

## <a name="arguments"></a>Arguments

*path*<br/>
Uma especificação de caminho absoluto ou relativo para o qual o arquivo. tlb deve ser criado.

*filename*<br/>
Especifica o nome do arquivo. tlb criado pelo compilador MIDL. Nenhuma extensão de arquivo é considerado; especificar *filename*. tlb se você quiser que uma extensão. tlb.

## <a name="remarks"></a>Comentários

A opção /TLBOUT Especifica o nome e a extensão do arquivo. tlb.

O compilador MIDL é chamado pelo vinculador do Visual C++, ao vincular projetos que têm o [módulo](../../windows/module-cpp.md) atributo.

Se /TLBOUT não for especificado, o arquivo. tlb receberá seu nome de [/IDLOUT](../../build/reference/idlout-name-midl-output-files.md) *filename*. Se /IDLOUT não for especificado, o arquivo. tlb será chamado vc70.tlb.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **IDL incorporado** página de propriedades.

1. Modificar a **biblioteca de tipos** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TypeLibraryFile%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)<br/>
[/IGNOREIDL (não processar atributos em MIDL)](../../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)<br/>
[/MIDL (especificar opções de linha de comando de MIDL)](../../build/reference/midl-specify-midl-command-line-options.md)<br/>
[Compilando um programa atribuído](../../windows/building-an-attributed-program.md)
