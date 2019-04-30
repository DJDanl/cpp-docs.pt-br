---
title: __wbinvd
ms.date: 11/04/2016
f1_keywords:
- __wbinvd
helpviewer_keywords:
- __wbinvd intrinsic
- wbinvd instruction
ms.assetid: 628d0981-39e5-49e1-bd43-706d123af121
ms.openlocfilehash: 99c7a452e063dea328e4aa1362aae8783929deb0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62390016"
---
# <a name="wbinvd"></a>__wbinvd

**Seção específica da Microsoft**

Gera o gravar novamente e invalidar o Cache (`wbinvd`) instrução.

## <a name="syntax"></a>Sintaxe

```
void __wbinvd(void);
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__wbinvd`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Essa função só está disponível no modo de kernel com um nível de privilégio (CPL) igual a 0 e a rotina só está disponível como um intrínseco.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)