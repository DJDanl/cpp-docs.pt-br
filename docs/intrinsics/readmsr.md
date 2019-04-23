---
title: __readmsr
ms.date: 11/04/2016
f1_keywords:
- __readmsr
helpviewer_keywords:
- Read Model Specific Register
- rdmsr instruction
- __readmsr intrinsic
ms.assetid: 7ab1f8e8-72cb-4ce4-817d-3e728a3c9716
ms.openlocfilehash: 2c866213c452f3b8791bf0fe031a43bb024e91fb
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59027617"
---
# <a name="readmsr"></a>__readmsr

**Seção específica da Microsoft**

Gera o `rdmsr` instrução, que lê o registro de modelo específico especificado pelo `register` e retorna seu valor.

## <a name="syntax"></a>Sintaxe

```
__int64 __readmsr(
   int register
);
```

#### <a name="parameters"></a>Parâmetros

*register*<br/>
[in] O registro específico de modelo para ler.

## <a name="return-value"></a>Valor de retorno

O valor no registro especificado.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__readmsr`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Essa função só está disponível no modo kernel e a rotina só está disponível como um intrínseco.

Para obter mais informações, consulte a documentação do AMD.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)