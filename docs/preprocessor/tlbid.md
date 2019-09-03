---
title: atributo de importação de TLBID
ms.date: 08/29/2019
f1_keywords:
- tlbid
helpviewer_keywords:
- tlbid attribute
ms.assetid: 54b06785-191b-4e77-a9a5-485f2b4acb09
ms.openlocfilehash: 364fb224b0f2769cb0933e71d18ff70768189328
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216537"
---
# <a name="tlbid-import-attribute"></a>atributo de importação de TLBID

**C++Determinados**

Permite carregar bibliotecas diferentes de biblioteca de tipos primárias.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos-dll* **TlbId (** *número* **)**

### <a name="parameters"></a>Parâmetros

*automática*\
O número da biblioteca de tipos no *Type-Library-DLL*.

## <a name="remarks"></a>Comentários

Se várias bibliotecas de tipos forem criadas em uma única DLL, será possível carregar bibliotecas diferentes da biblioteca de tipos primária usando **TLBID**.

Por exemplo:

```cpp
#import <MyResource.dll> tlbid(2)
```

equivale a:

```cpp
LoadTypeLib("MyResource.dll\\2");
```

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
