---
title: _enable
ms.date: 11/04/2016
f1_keywords:
- _enable
- _enable_cpp
helpviewer_keywords:
- enable intrinsic
- _enable intrinsic
- ssm instruction
ms.assetid: 8bee669b-6bd8-4e25-9383-bb7d57295b4d
ms.openlocfilehash: 1d129db17b489972555efb0b5df2de52e01fa649
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50631226"
---
# <a name="enable"></a>_enable

**Seção específica da Microsoft**

Permite interrupções.

## <a name="syntax"></a>Sintaxe

```
void _enable(void);
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_enable`|x86, ARM, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

`_enable` instrui o processador para definir o sinalizador de interrupção. Em sistemas x86, essa função gera a instrução Definir Sinalizador de Interrupção (`sti`).

Essa função só está disponível no modo de kernel. Se usada no modo de usuário, uma exceção de instrução privilegiada será gerada.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)