---
title: include()
ms.date: 10/18/2018
f1_keywords:
- include()
helpviewer_keywords:
- include() attribute
ms.assetid: 86c9dcb2-d9e0-4fd5-97d7-0bb3e23d6ecc
ms.openlocfilehash: 8f3227ba49cc0928fec5d5917efcd8869982d94a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50599739"
---
# <a name="include"></a>include()

**Específico do C++**

Desabilita a exclusão automática.

## <a name="syntax"></a>Sintaxe

```
include("Name1"[,"Name2", ...])
```

### <a name="parameters"></a>Parâmetros

*Nome1*<br/>
Primeiro item a ser incluído de modo forçado.

*Nome2*<br/>
O segundo item a ser incluído de modo forçado (se necessário).

## <a name="remarks"></a>Comentários

As bibliotecas de tipos podem conter definições dos itens definidos em cabeçalhos do sistema ou em outras bibliotecas de tipos. `#import` tenta impedir vários erros de definição excluindo automaticamente esses itens. Se os itens tiverem sido excluídos, conforme indicado pela [aviso do compilador (nível 3) C4192](../error-messages/compiler-warnings/compiler-warning-level-3-c4192.md), e não deve ter sido, esse atributo pode ser usado para desabilitar a exclusão automática. Esse atributo pode usar qualquer número de argumentos, cada um sendo o nome do item da biblioteca de tipos a ser incluído.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)