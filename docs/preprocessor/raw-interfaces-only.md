---
title: raw_interfaces_only
ms.date: 11/04/2016
f1_keywords:
- raw_interfaces_only
helpviewer_keywords:
- raw_interfaces_only attribute
ms.assetid: 87056c6d-3f34-4248-af58-f5775a35bfb7
ms.openlocfilehash: c07401036261b9f93bb2c07dcf3aff1ecf72e2fc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519347"
---
# <a name="rawinterfacesonly"></a>raw_interfaces_only
**Específico do C++**

Suprime a geração de funções de wrapper de tratamento de erros e [propriedade](../cpp/property-cpp.md) declarações que usam essas funções wrapper.

## <a name="syntax"></a>Sintaxe

```
raw_interfaces_only
```

## <a name="remarks"></a>Comentários

O **raw_interfaces_only** atributo também faz com que o prefixo padrão usado na nomeação as funções não são da propriedade a ser removido. Normalmente, é o prefixo **RAW _**. Se esse atributo for especificado, os nomes de função serão diretamente da biblioteca de tipos.

Esse atributo permite que você exiba somente o conteúdo de nível baixo da biblioteca de tipos.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)