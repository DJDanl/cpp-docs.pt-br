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
ms.openlocfilehash: 4e04514933a521bbf9d927fa6b47bacb87896353
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62317634"
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

O compilador MIDL é chamado pelo vinculador MSVC ao vincular projetos que têm o [módulo](../../windows/module-cpp.md) atributo.

Se /TLBOUT não for especificado, o arquivo. tlb receberá seu nome de [/IDLOUT](idlout-name-midl-output-files.md) *filename*. Se /IDLOUT não for especificado, o arquivo. tlb será chamado vc70.tlb.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **IDL incorporado** página de propriedades.

1. Modificar a **biblioteca de tipos** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TypeLibraryFile%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)<br/>
[/IGNOREIDL (não processar atributos em MIDL)](ignoreidl-don-t-process-attributes-into-midl.md)<br/>
[/MIDL (especificar opções de linha de comando de MIDL)](midl-specify-midl-command-line-options.md)<br/>
[Compilando um programa atribuído](../../windows/building-an-attributed-program.md)
