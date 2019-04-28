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
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62264160"
---
# <a name="disable"></a>_disable

**Seção específica da Microsoft**

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)