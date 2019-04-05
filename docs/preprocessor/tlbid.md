---
title: tlbid
ms.date: 10/18/2018
f1_keywords:
- tlbid
helpviewer_keywords:
- tlbid attribute
ms.assetid: 54b06785-191b-4e77-a9a5-485f2b4acb09
ms.openlocfilehash: ae79ce9245bb1c0425c3e9b92dd27b52fa443dba
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59037921"
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

**FIM de Específico do C++**

## <a name="see-also"></a>Consulte também

[Atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[Diretiva #import](../preprocessor/hash-import-directive-cpp.md)