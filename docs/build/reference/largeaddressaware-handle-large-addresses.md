---
title: /LARGEADDRESSAWARE (identificar endereços grandes)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.LargeAddressAware
- /largeaddressaware
helpviewer_keywords:
- LARGEADDRESSAWARE linker option
- -LARGEADDRESSAWARE linker option
- /LARGEADDRESSAWARE linker option
ms.assetid: a29756c8-e893-47a9-9750-1f0d25359385
ms.openlocfilehash: 81a560ebf083e2f93d9bb514fc401186291d7f41
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57808112"
---
# <a name="largeaddressaware-handle-large-addresses"></a>/LARGEADDRESSAWARE (identificar endereços grandes)

```
/LARGEADDRESSAWARE[:NO]
```

## <a name="remarks"></a>Comentários

A opção /LARGEADDRESSAWARE informa o vinculador que o aplicativo pode manipular endereços maiores que 2 gigabytes. Nos compiladores de 64 bits, essa opção é habilitada por padrão. Nos compiladores de 32 bits, /LARGEADDRESSAWARE: no está habilitado se /LARGEADDRESSAWARE não está especificado na linha do vinculador.

Se um aplicativo foi vinculado com /LARGEADDRESSAWARE, DUMPBIN [/HEADERS](headers.md) exibirá informações sobre isso.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **sistema** página de propriedades.

1. Modificar a **habilitar endereços grandes** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.LargeAddressAware%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
