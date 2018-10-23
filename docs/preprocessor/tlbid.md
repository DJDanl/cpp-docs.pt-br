---
title: tlbid | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- tlbid
dev_langs:
- C++
helpviewer_keywords:
- tlbid attribute
ms.assetid: 54b06785-191b-4e77-a9a5-485f2b4acb09
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6324ec9a64a0d1c47dab8d1beee021f6c8752a96
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49807972"
---
# <a name="tlbid"></a>tlbid

**Específico do C++**

Permite carregar bibliotecas diferentes de biblioteca de tipos primárias.

## <a name="syntax"></a>Sintaxe

```
tlbid(number)
```

### <a name="parameters"></a>Parâmetros

*número*<br/>
O número da biblioteca de tipos em `filename`.

## <a name="remarks"></a>Comentários

Se várias bibliotecas de tipos são criadas em uma única DLL, é possível carregar bibliotecas que não sejam a biblioteca de tipos principal usando **tlbid**.

Por exemplo:

```cpp
#import <MyResource.dll> tlbid(2)
```

equivale a:

```cpp
LoadTypeLib("MyResource.dll\\2");
```

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)