---
title: _disable
ms.date: 09/02/2019
f1_keywords:
- _disable_cpp
- _disable
helpviewer_keywords:
- _disable intrinsic
- rsm instruction
- disable intrinsic
ms.assetid: 52da3df9-815c-4524-9839-6d1742cff5c6
ms.openlocfilehash: 94be850e1d494ff62df84922b46f28481be68314
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216823"
---
# <a name="_disable"></a>_disable

**Seção específica da Microsoft**

Desabilita interrupções.

## <a name="syntax"></a>Sintaxe

```C
void _disable(void);
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_disable`|x86, ARM, x64, ARM64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

`_disable` instrui o processador para limpar o sinalizador de interrupção. Em sistemas x86, essa função gera a instrução Limpar Sinalizador de Interrupção (`cli`).

Essa função só está disponível no modo de kernel. Se usado no modo de usuário, uma exceção de instrução privilegiada será gerada em tempo de execução.

Em plataformas ARM e ARM64, essa rotina só está disponível como intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
