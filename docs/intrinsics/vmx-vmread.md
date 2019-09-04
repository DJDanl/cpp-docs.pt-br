---
title: __vmx_vmread
ms.date: 09/02/2019
f1_keywords:
- __vmx_vmread
helpviewer_keywords:
- VMREAD instruction
- __vmx_vmread intrinsic
ms.assetid: 08bdd7a0-6435-4ea6-b9a0-f592d870e5aa
ms.openlocfilehash: 409835ac29d6f2e839de62291cc5b142166a465c
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219437"
---
# <a name="__vmx_vmread"></a>__vmx_vmread

**Seção específica da Microsoft**

Lê um campo especificado da VMCS (estrutura de controle de máquina virtual) atual e o coloca no local especificado.

## <a name="syntax"></a>Sintaxe

```C
unsigned char __vmx_vmread(
   size_t Field,
   size_t *FieldValue
);
```

### <a name="parameters"></a>Parâmetros

*Campo*\
no O campo VMCS a ser lido.

*FieldValue*\
no Um ponteiro para o local para armazenar o valor lido do campo VMCs especificado pelo `Field` parâmetro.

## <a name="return-value"></a>Valor retornado

|Valor|Significado|
|-----------|-------------|
|0|A operação foi bem-sucedida.|
|1|A operação falhou com o status estendido disponível `VM-instruction error field` no do VMCs atual.|
|2|A operação falhou sem status disponível.|

## <a name="remarks"></a>Comentários

A `__vmx_vmread` função é equivalente à instrução `VMREAD` da máquina. O valor do `Field` parâmetro é um índice de campo codificado que é descrito na documentação da Intel. Para obter mais informações, pesquise o Apêndice C de "Especificação técnica de virtualização da Intel para a arquitetura Intel IA-32", no site da [Intel Corporation](https://software.intel.com/articles/intel-sdm) .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_vmread`|X64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__vmx_vmwrite](../intrinsics/vmx-vmwrite.md)
