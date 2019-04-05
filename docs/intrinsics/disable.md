---
title: _disable
ms.date: 11/04/2016
f1_keywords:
- _disable_cpp
- _disable
helpviewer_keywords:
- _disable intrinsic
- rsm instruction
- disable intrinsic
ms.assetid: 52da3df9-815c-4524-9839-6d1742cff5c6
ms.openlocfilehash: 93db063c6b53f0bec739ba134728b83379a21f53
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59024667"
---
# <a name="disable"></a>_disable

**Específico da Microsoft**

Desabilita interrupções.

## <a name="syntax"></a>Sintaxe

```
void _disable(void);
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_disable`|x86, ARM, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

`_disable` instrui o processador para limpar o sinalizador de interrupção. Em sistemas x86, essa função gera a instrução Limpar Sinalizador de Interrupção (`cli`).

Essa função só está disponível no modo de kernel. Se usado no modo de usuário, uma exceção de instrução privilegiada será gerada em tempo de execução.

Em plataformas ARM, essa rotina só está disponível como um intrínseco.

**FIM de Específico da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)