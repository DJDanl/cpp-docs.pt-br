---
title: /APPCONTAINER (aplicativo de UWP/Microsoft Store) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
ms.assetid: 9a432db5-7640-460b-ab18-6f61fa7daf6f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6d52148f14c21773a6fe93c3909c91f80c3c3650
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45726564"
---
# <a name="appcontainer-microsoft-store-app"></a>/APPCONTAINER (aplicativo da Microsoft Store)

Especifica se o vinculador cria uma imagem executável que deve ser executada em um contêiner de aplicativo.

## <a name="syntax"></a>Sintaxe

```
/APPCONTAINER[:NO]
```

## <a name="remarks"></a>Comentários

Por padrão, /APPCONTAINER está desativado.

Essa opção modifica um executável para indicar se o aplicativo deve ser executado no ambiente de isolamento do processo de appcontainer. Especifica /APPCONTAINER para um aplicativo que deve ser executados no appcontainer ambiente — por exemplo, um aplicativo de 8.x plataforma Universal do Windows (UWP) ou Windows Phone. (A opção é definida automaticamente no Visual Studio quando você cria um aplicativo Windows Universal de um modelo.) Para um aplicativo da área de trabalho, especifique /appcontainer: no ou apenas omita a opção.

A opção de /APPCONTAINER foi introduzida no Windows 8.

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o **vinculador** nó.

1. Selecione o **linha de comando** página de propriedades.

1. Na **opções adicionais**, insira `/APPCONTAINER` ou `/APPCONTAINER:NO`.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)