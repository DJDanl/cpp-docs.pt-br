---
title: -NOLOGO (Suprimir faixa de inicialização) (Vinculador) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.SuppressStartupBanner
- /nologo
dev_langs:
- C++
helpviewer_keywords:
- suppress startup banner linker option
- -NOLOGO linker option
- /NOLOGO linker option
- copyright message
- version numbers, preventing linker display
- banners, suppressing startup
- NOLOGO linker option
ms.assetid: 3b20dddd-eca6-4545-a331-9f70bf720197
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 405cfd08b681d8b48343bae5055f5be9cf23dadb
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707571"
---
# <a name="nologo-suppress-startup-banner-linker"></a>/NOLOGO (suprimir faixa de inicialização) (vinculador)

```
/NOLOGO
```

## <a name="remarks"></a>Comentários

A opção /NOLOGO previne a exibição do número de versão e de mensagem de direitos autorais.

Essa opção também suprime a repetição de arquivos de comando. Para obter detalhes, consulte [arquivos de comando LINK](../../build/reference/link-command-files.md).

Por padrão, essas informações são enviadas pelo vinculador à janela de saída. Na linha de comando, ele é enviado para a saída padrão e pode ser redirecionado para um arquivo.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Essa opção só deve ser usada na linha de comando.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Essa opção de vinculador não pode ser alterada programaticamente.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)