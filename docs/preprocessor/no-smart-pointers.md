---
title: atributo de importação de no_smart_pointers
ms.date: 08/29/2019
f1_keywords:
- no_smart_pointers
helpviewer_keywords:
- no_smart_pointers attribute
ms.assetid: d69dd71e-08a8-4446-a3d0-a062dc29cb17
ms.openlocfilehash: 1fca3eb486ff3cfc7403c38e91855b799a698782
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220694"
---
# <a name="no_smart_pointers-import-attribute"></a>atributo de importação de no_smart_pointers

**C++Determinados**

Suprime a criação de ponteiros inteligentes para todas as interfaces na biblioteca de tipos.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **no_smart_pointers**

## <a name="remarks"></a>Comentários

Por padrão, quando você usa `#import`, consegue uma declaração de ponteiro inteligente em todas as interfaces na biblioteca de tipos. Esses ponteiros inteligentes são do tipo [_com_ptr_t](../cpp/com-ptr-t-class.md).

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
