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
ms.openlocfilehash: 62913eaadd0f0a88f05ce347a6778062a1e66f17
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509334"
---
# <a name="tlbout-name-tlb-file"></a>/TLBOUT (nomear arquivo .TLB)

```
/TLBOUT:[path\]filename
```

## <a name="arguments"></a>Argumentos

*path*<br/>
Uma especificação de caminho absoluto ou relativo para onde o arquivo. tlb deve ser criado.

*nome do arquivo*<br/>
Especifica o nome do arquivo. tlb criado pelo compilador MIDL. Nenhuma extensão de arquivo é assumida; Especifique *filename*. tlb se você quiser uma extensão. tlb.

## <a name="remarks"></a>Comentários

A opção/TLBOUT especifica o nome e a extensão do arquivo. tlb.

O compilador MIDL é chamado pelo vinculador MSVC ao vincular projetos que têm o atributo [Module](../../windows/attributes/module-cpp.md) .

Se/TLBOUT não for especificado, o arquivo. tlb receberá seu nome de [/IDLOUT](idlout-name-midl-output-files.md) *filename*. Se/IDLOUT não for especificado, o arquivo. tlb será chamado de vc70. tlb.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **Vinculador**.

1. Clique na página de propriedades **IDL inserida** .

1. Modifique a propriedade da **biblioteca de tipos** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TypeLibraryFile%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)<br/>
[/IGNOREIDL (não processar atributos no MIDL)](ignoreidl-don-t-process-attributes-into-midl.md)<br/>
[/MIDL (especifique as opções de linha de comando MIDL)](midl-specify-midl-command-line-options.md)<br/>
[Compilando um programa atribuído](../../windows/attributes/cpp-attributes-com-net.md)
