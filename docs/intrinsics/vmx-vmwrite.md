---
title: __vmx_vmwrite
ms.date: 11/04/2016
f1_keywords:
- __vmx_vmwrite
helpviewer_keywords:
- __vmx_vmwrite intrinsic
- VMWRITE instruction
ms.assetid: 88139792-fd3f-4210-97ca-9d84f43a0252
ms.openlocfilehash: e52b1f181f00ce013a111d1a5a62abeff544e20a
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59037504"
---
# <a name="vmxvmwrite"></a>__vmx_vmwrite

**Seção específica da Microsoft**

Grava o valor especificado para o campo especificado na estrutura de controle de máquina virtual atual (VMCS).

## <a name="syntax"></a>Sintaxe

```
unsigned char __vmx_vmwrite(
   size_t Field,
   size_t FieldValue
);
```

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Campo*|[in] O campo VMCS para gravar.|
|*FieldValue*|[in] O valor a ser gravado para o campo VMCS.|

## <a name="return-value"></a>Valor de retorno

0 a operação foi bem-sucedida.

1 a operação falhou com status estendido disponível no `VM-instruction error field` de VMCS o atual.

2 a operação falhou sem status disponível.

## <a name="remarks"></a>Comentários

O `__vmx_vmwrite` função é equivalente ao `VMWRITE` instruções de máquina. O valor da `Field` parâmetro é um índice de campo codificado que é descrito na documentação da Intel. Para obter mais informações, pesquise o documento, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, o [Intel Corporation](https://software.intel.com/articles/intel-sdm) do site e, em seguida, consulte o Apêndice C do que documento.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_vmwrite`|X64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__vmx_vmread](../intrinsics/vmx-vmread.md)