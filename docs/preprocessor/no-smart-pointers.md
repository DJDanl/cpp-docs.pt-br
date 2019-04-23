---
title: no_smart_pointers
ms.date: 11/04/2016
f1_keywords:
- no_search_pointers
helpviewer_keywords:
- no_smart_pointers attribute
ms.assetid: d69dd71e-08a8-4446-a3d0-a062dc29cb17
ms.openlocfilehash: ed4950b9e90ef968fcf0c42e4f0a9775c58ea7ec
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59030161"
---
# <a name="nosmartpointers"></a>no_smart_pointers
**Específico do C++**

Suprime a criação de ponteiros inteligentes para todas as interfaces na biblioteca de tipos.

## <a name="syntax"></a>Sintaxe

```
no_smart_pointers
```

## <a name="remarks"></a>Comentários

Por padrão, quando você usa `#import`, consegue uma declaração de ponteiro inteligente em todas as interfaces na biblioteca de tipos. Esses ponteiros inteligentes são do tipo [classe com_ptr_t](../cpp/com-ptr-t-class.md).

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)