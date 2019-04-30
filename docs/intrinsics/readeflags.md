---
title: __readeflags
ms.date: 11/04/2016
f1_keywords:
- __readeflags
helpviewer_keywords:
- __readeflags intrinsic
ms.assetid: f9d2f4d8-c428-491f-b8de-04d0566b2b6b
ms.openlocfilehash: 9913fb4287e673faf79b2c352bb42eda7f590fdd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62396477"
---
# <a name="readeflags"></a>__readeflags

Lê que o status do programa e o controle (EFLAGS) registram.

## <a name="syntax"></a>Sintaxe

```
unsigned     int __readeflags(void);
unsigned __int64 __readeflags(void);
```

## <a name="return-value"></a>Valor de retorno

O valor do registrador EFLAGS. O valor de retorno é de 32 bits longa em uma plataforma de 32 bits e 64 bits longa em uma plataforma de 64 bits.

## <a name="remarks"></a>Comentários

Essas rotinas estão disponíveis apenas como intrínsecos.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__readeflags`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__writeeflags](../intrinsics/writeeflags.md)