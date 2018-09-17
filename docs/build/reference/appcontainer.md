---
title: -APPCONTAINER | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /APPCONTAINER
dev_langs:
- C++
helpviewer_keywords:
- APPCONTAINER editbin option
- -APPCONTAINER editbin option
- /APPCONTAINER editbin option
ms.assetid: 0ca4f1ec-c8de-4a37-b3e2-deda7af0bb88
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3d8e19724183963329b959286a996b4f21d18b4c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45709171"
---
# <a name="appcontainer"></a>/APPCONTAINER

Marca um executável que deve ser executado em um aplicativo contêiner — por exemplo, um aplicativo Microsoft Store ou Windows Universal.

```

/APPCONTAINER[:NO]
```

## <a name="remarks"></a>Comentários

Um executável que tem o **/APPCONTAINER** conjunto de opções pode ser executado somente em um aplicativo de contêiner, que é o ambiente de isolamento de processo introduzido no Windows 8. Para aplicativos da Microsoft Store e Universal do Windows, essa opção deve ser definida.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](../../build/reference/editbin-options.md)<br/>
[O que é um aplicativo Universal do Windows?](/windows/uwp/get-started/universal-application-platform-guide)