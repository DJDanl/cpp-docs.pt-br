---
title: /IGNOREIDL (Don&#39;t processar atributos em MIDL)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.IgnoreEmbeddedIDL
- /ignoreidl
helpviewer_keywords:
- IGNOREIDL linker option
- -IGNOREIDL linker option
- /IGNOREIDL linker option
ms.assetid: 29514098-6a1c-4317-af2f-1dc268972780
ms.openlocfilehash: 210778adecd87ffdd5f2702c10106f12bd5a1b79
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62291672"
---
# <a name="ignoreidl-don39t-process-attributes-into-midl"></a>/IGNOREIDL (Don&#39;t processar atributos em MIDL)

```
/IGNOREIDL
```

## <a name="remarks"></a>Comentários

A opção /IGNOREIDL Especifica que qualquer [atributos de IDL](../../windows/idl-attributes.md) na fonte de código não deve ser processado em um arquivo. idl.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **IDL incorporado** página de propriedades.

1. Modificar a **Ignorar IDL incorporado** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.IgnoreEmbeddedIDL%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)<br/>
[/IDLOUT (nomear arquivos de saída MIDL)](idlout-name-midl-output-files.md)<br/>
[/TLBOUT (nomear arquivo .TLB)](tlbout-name-dot-tlb-file.md)<br/>
[/MIDL (especificar opções de linha de comando de MIDL)](midl-specify-midl-command-line-options.md)<br/>
[Compilando um programa atribuído](../../windows/building-an-attributed-program.md)
