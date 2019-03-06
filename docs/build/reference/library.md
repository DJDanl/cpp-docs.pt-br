---
title: LIBRARY
ms.date: 11/04/2016
f1_keywords:
- LIBRARY
helpviewer_keywords:
- LIBRARY .def file statement
ms.assetid: 1d7ccc92-e088-4ef7-9ef0-25c3862cc051
ms.openlocfilehash: 73609be698719da05fff357ba80200c49f598add
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57422657"
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
