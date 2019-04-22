---
title: raw_method_prefix
ms.date: 03/27/2019
f1_keywords:
- raw_method_prefix
helpviewer_keywords:
- raw_method_prefix attribute
ms.assetid: 71490313-af78-4bb2-b28a-eee67950d30b
ms.openlocfilehash: 963e04752dcb797343550d9b89f778bfe0e8a593
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59021405"
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