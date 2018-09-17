---
title: BIBLIOTECA | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- LIBRARY
dev_langs:
- C++
helpviewer_keywords:
- LIBRARY .def file statement
ms.assetid: 1d7ccc92-e088-4ef7-9ef0-25c3862cc051
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 43b14e8e8ff4871ba4319c7f4fac5545e72e710b
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45723548"
---
# <a name="library"></a>LIBRARY

Informa o LINK para criar uma DLL. Ao mesmo tempo, o LINK cria uma biblioteca de importação, a menos que um arquivo. EXP seja usado na compilação.

```
LIBRARY [library][BASE=address]
```

## <a name="remarks"></a>Comentários

O *biblioteca* argumento especifica o nome da DLL. Você também pode usar o [/out](../../build/reference/out-output-file-name.md) opção de vinculador para especificar o nome de saída da DLL.

A BASE =*endereço* argumento define o endereço base que o sistema operacional usa para carregar a DLL. Esse argumento substitui o local de DLL padrão do 0x10000000. Consulte a descrição do [/base](../../build/reference/base-base-address.md) opção para obter detalhes sobre os endereços base.

Lembre-se de usar o [/DLL](../../build/reference/dll-build-a-dll.md) opção de vinculador quando você compila uma DLL.

## <a name="see-also"></a>Consulte também

[Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)