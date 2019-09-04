---
title: atributo de importação de no_dual_interfaces
ms.date: 08/29/2019
f1_keywords:
- no_dual_interfaces
helpviewer_keywords:
- no_dual_interfaces attribute
ms.assetid: 9acd5d9d-4a49-4cdc-9470-73a2c23cf512
ms.openlocfilehash: 6270888f0d31e4fbe18fb3364995be8c73426b83
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220754"
---
# <a name="no_dual_interfaces-import-attribute"></a>atributo de importação de no_dual_interfaces

**C++Determinados**

Altera o modo como o compilador gerenciar funções wrapper para métodos da interface dupla.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **no_dual_interfaces**

## <a name="remarks"></a>Comentários

Normalmente, o wrapper chama o método por meio da tabela de funções virtuais para a interface. Com **no_dual_interfaces**, o wrapper, em `IDispatch::Invoke` vez disso, chama para invocar o método.

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
