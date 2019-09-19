---
title: __vmx_vmwrite
ms.date: 09/02/2019
f1_keywords:
- __vmx_vmwrite
helpviewer_keywords:
- __vmx_vmwrite intrinsic
- VMWRITE instruction
ms.assetid: 88139792-fd3f-4210-97ca-9d84f43a0252
ms.openlocfilehash: cdc5590858f160db24bf75ef11c8f20b204a3152
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219398"
---
# <a name="__vmx_vmwrite"></a>__vmx_vmwrite

**Seção específica da Microsoft**

Grava o valor especificado para o campo especificado na estrutura de controle de máquina virtual atual (VMCS).

## <a name="syntax"></a>Sintaxe

```C
unsigned char __vmx_vmwrite(
   size_t Field,
   size_t FieldValue
);
```

### <a name="parameters"></a>Parâmetros

*Campo*\
no O campo VMCS a ser gravado.

*FieldValue*\
no O valor a ser gravado no campo VMCS.

## <a name="return-value"></a>Valor retornado

0\
A operação foi bem-sucedida.

1\
A operação falhou com o status estendido disponível `VM-instruction error field` no do VMCs atual.

2\
A operação falhou sem status disponível.

## <a name="remarks"></a>Comentários

A `__vmx_vmwrite` função é equivalente à instrução `VMWRITE` da máquina. O valor do `Field` parâmetro é um índice de campo codificado que é descrito na documentação da Intel. Para obter mais informações, pesquise o Apêndice C de "Especificação técnica de virtualização da Intel para a arquitetura Intel IA-32", no site da [Intel Corporation](https://software.intel.com/articles/intel-sdm) .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_vmwrite`|X64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__vmx_vmread](../intrinsics/vmx-vmread.md)
