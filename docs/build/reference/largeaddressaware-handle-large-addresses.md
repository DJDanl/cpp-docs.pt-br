---
title: -LARGEADDRESSAWARE (manipular endereços grandes) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.LargeAddressAware
- /largeaddressaware
dev_langs:
- C++
helpviewer_keywords:
- LARGEADDRESSAWARE linker option
- -LARGEADDRESSAWARE linker option
- /LARGEADDRESSAWARE linker option
ms.assetid: a29756c8-e893-47a9-9750-1f0d25359385
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0a68b18f912d7e6ca0f0f642c85e8439be0e5b67
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45726317"
---
# <a name="largeaddressaware-handle-large-addresses"></a>/LARGEADDRESSAWARE (identificar endereços grandes)

```
/LARGEADDRESSAWARE[:NO]
```

## <a name="remarks"></a>Comentários

A opção /LARGEADDRESSAWARE informa o vinculador que o aplicativo pode manipular endereços maiores que 2 gigabytes. Nos compiladores de 64 bits, essa opção é habilitada por padrão. Nos compiladores de 32 bits, /LARGEADDRESSAWARE: no está habilitado se /LARGEADDRESSAWARE não está especificado na linha do vinculador.

Se um aplicativo foi vinculado com /LARGEADDRESSAWARE, DUMPBIN [/HEADERS](../../build/reference/headers.md) exibirá informações sobre isso.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **sistema** página de propriedades.

1. Modificar a **habilitar endereços grandes** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.LargeAddressAware%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)