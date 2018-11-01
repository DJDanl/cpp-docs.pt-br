---
title: /APPCONTAINER
ms.date: 11/04/2016
f1_keywords:
- /APPCONTAINER
helpviewer_keywords:
- APPCONTAINER editbin option
- -APPCONTAINER editbin option
- /APPCONTAINER editbin option
ms.assetid: 0ca4f1ec-c8de-4a37-b3e2-deda7af0bb88
ms.openlocfilehash: 0805393990070a10caed8208138e31ab9084bdf0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50482544"
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