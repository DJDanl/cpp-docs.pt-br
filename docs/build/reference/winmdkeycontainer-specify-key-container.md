---
title: /WINMDKEYCONTAINER (Especifica o contêiner de chave)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.WINMDKEYCONTAINER
ms.assetid: c2fc44dc-7cb5-42b9-897f-1b124928f2f7
ms.openlocfilehash: 8d26c49a8cf4a1f71841fabdd4ec30fb437ad349
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50532230"
---
# <a name="winmdkeycontainer-specify-key-container"></a>/WINMDKEYCONTAINER (Especifica o contêiner de chave)

Especifica um contêiner de chave para assinar um arquivo de metadados do Windows (. winmd).

```
/WINMDKEYCONTAINER:name
```

## <a name="remarks"></a>Comentários

É semelhante a [/KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md) opção de vinculador que é aplicada a um arquivo (. winmd).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **vinculador** pasta.

1. Selecione o **metadados do Windows** página de propriedades.

1. No **contêiner de chave de metadados do Windows** , digite o local.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)