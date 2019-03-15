---
title: /WINMDKEYFILE (Especifica o arquivo de chave winmd)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.WINMDKeyFile
ms.assetid: 65d88fdc-fff9-49ea-8cfc-b2f408741734
ms.openlocfilehash: 4b0c847bc5be6c73b78af4aa15b0074c712cc840
ms.sourcegitcommit: faa42c8a051e746d99dcebe70fd4bbaf3b023ace
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/15/2019
ms.locfileid: "57820397"
---
# <a name="winmdkeyfile-specify-winmd-key-file"></a>/WINMDKEYFILE (Especifica o arquivo de chave winmd)

Especifica uma chave ou um par de chaves para assinar um arquivo de metadados de tempo de execução do Windows (. winmd).

```
/WINMDKEYFILE:filename
```

## <a name="remarks"></a>Comentários

É semelhante a [/KEYFILE](keyfile-specify-key-or-key-pair-to-sign-an-assembly.md) opção de vinculador que é aplicada a um arquivo. winmd.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **vinculador** pasta.

1. Selecione o **metadados do Windows** página de propriedades.

1. No **arquivo de chave de metadados do Windows** , digite o local do arquivo.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
