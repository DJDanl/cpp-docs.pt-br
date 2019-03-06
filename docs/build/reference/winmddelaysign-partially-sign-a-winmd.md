---
title: /WINMDDELAYSIGN (Assina parcialmente um winmd)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.WINMDDelaySign
ms.assetid: 445cd602-62cb-400a-8e3a-4beb6572724d
ms.openlocfilehash: 85698362a753e147a28922db19b456d4d649e55d
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57421449"
---
# <a name="winmddelaysign-partially-sign-a-winmd"></a>/WINMDDELAYSIGN (Assina parcialmente um winmd)

Habilita a assinatura parcial de um arquivo de metadados de tempo de execução do Windows (. winmd) colocando a chave pública no arquivo.

```
/WINMDDELAYSIGN[:NO]
```

## <a name="remarks"></a>Comentários

É semelhante a [/DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md) opção de vinculador que é aplicada ao arquivo. winmd. Use **/WINMDDELAYSIGN** se você quiser colocar somente a chave pública no arquivo. winmd. Por padrão, o vinculador age como se **/winmddelaysign: no** foram especificados; ou seja, ele não assina o arquivo winmd.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **vinculador** pasta.

1. Selecione o **metadados do Windows** página de propriedades.

1. No **sinal de atraso de metadados do Windows** lista suspensa, selecione a opção desejada.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
