---
title: no_smart_pointers | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- no_search_pointers
dev_langs:
- C++
helpviewer_keywords:
- no_smart_pointers attribute
ms.assetid: d69dd71e-08a8-4446-a3d0-a062dc29cb17
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 233e302d4035801e7d8871754d8ecfcfee54cf1a
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50060905"
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