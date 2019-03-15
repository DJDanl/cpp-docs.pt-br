---
title: /WINMDKEYCONTAINER (Especifica o contêiner de chave)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.WINMDKEYCONTAINER
ms.assetid: c2fc44dc-7cb5-42b9-897f-1b124928f2f7
ms.openlocfilehash: 0b6cb42fc391d94634ae90e5a4cc17e69a14ff09
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57813065"
---
# <a name="winmdkeycontainer-specify-key-container"></a>/WINMDKEYCONTAINER (Especifica o contêiner de chave)

Especifica um contêiner de chave para assinar um arquivo de metadados do Windows (. winmd).

```
/WINMDKEYCONTAINER:name
```

## <a name="remarks"></a>Comentários

É semelhante a [/KEYCONTAINER](keycontainer-specify-a-key-container-to-sign-an-assembly.md) opção de vinculador que é aplicada a um arquivo (. winmd).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **vinculador** pasta.

1. Selecione o **metadados do Windows** página de propriedades.

1. No **contêiner de chave de metadados do Windows** , digite o local.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
