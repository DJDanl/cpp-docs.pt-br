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
ms.openlocfilehash: e1ece6d6f4040b81b55d8400407d46f165b56b53
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59024511"
---
# <a name="enable"></a>_enable

**Específico da Microsoft**

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

**FIM de Específico da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)