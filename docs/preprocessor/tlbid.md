---
title: tlbid
ms.date: 10/18/2018
f1_keywords:
- tlbid
helpviewer_keywords:
- tlbid attribute
ms.assetid: 54b06785-191b-4e77-a9a5-485f2b4acb09
ms.openlocfilehash: ae79ce9245bb1c0425c3e9b92dd27b52fa443dba
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62179601"
---
# <a name="tlbid"></a>tlbid

**Específico do C++**

Permite carregar bibliotecas diferentes de biblioteca de tipos primárias.

## <a name="syntax"></a>Sintaxe

```
tlbid(number)
```

### <a name="parameters"></a>Parâmetros

*number*<br/>
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