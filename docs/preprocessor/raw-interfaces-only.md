---
title: raw_interfaces_only
ms.date: 11/04/2016
f1_keywords:
- raw_interfaces_only
helpviewer_keywords:
- raw_interfaces_only attribute
ms.assetid: 87056c6d-3f34-4248-af58-f5775a35bfb7
ms.openlocfilehash: 48133b85ccb5ddb8de8e6cb614d41cde22dac66b
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59028254"
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

**FIM de Específico do C++**

## <a name="see-also"></a>Consulte também

[Atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[Diretiva #import](../preprocessor/hash-import-directive-cpp.md)