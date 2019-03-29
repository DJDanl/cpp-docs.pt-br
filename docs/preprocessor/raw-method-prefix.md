---
title: raw_method_prefix
ms.date: 03/27/2019
f1_keywords:
- raw_method_prefix
helpviewer_keywords:
- raw_method_prefix attribute
ms.assetid: 71490313-af78-4bb2-b28a-eee67950d30b
ms.openlocfilehash: c3015cf8b51646d25fd8f36a7336c63dc8fe492b
ms.sourcegitcommit: 309dc532f13242854b47759cef846de59bb807f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/28/2019
ms.locfileid: "58565591"
---
# <a name="rawmethodprefix"></a>raw_method_prefix

**Específico do C++**

Especifica um prefixo diferente para evitar colisões de nome.

## <a name="syntax"></a>Sintaxe

```
raw_method_prefix("Prefix")
```

### <a name="parameters"></a>Parâmetros

*Prefixo*<br/>
O prefixo a ser usado.

## <a name="remarks"></a>Comentários

Métodos e propriedades de baixo nível são expostos por funções de membro nomeadas com o prefixo padrão **RAW _** para evitar colisões de nome com as funções de membro de tratamento de erros alto nível.

> [!NOTE]
> Os efeitos do **raw_method_prefix** atributo não será alterado pela presença da [raw_interfaces_only](raw-interfaces-only.md) atributo. O **raw_method_prefix** sempre tem precedência sobre `raw_interfaces_only` na especificação de um prefixo. Se ambos os atributos são usados na mesma `#import` instrução, em seguida, o prefixo especificado o **raw_method_prefix** atributo é usado.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)