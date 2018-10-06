---
title: __vmx_vmread | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __vmx_vmread
dev_langs:
- C++
helpviewer_keywords:
- VMREAD instruction
- __vmx_vmread intrinsic
ms.assetid: 08bdd7a0-6435-4ea6-b9a0-f592d870e5aa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0d9483dafd763112f31f5299a5e0e7e54c224459
ms.sourcegitcommit: a738519aa491a493a8f213971354356c0e6a5f3a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/05/2018
ms.locfileid: "48821017"
---
# <a name="vmxvmread"></a>__vmx_vmread

**Seção específica da Microsoft**

Lê um campo especificado da estrutura de controle de máquina virtual atual (VMCS) e o coloca no local especificado.

## <a name="syntax"></a>Sintaxe

```
unsigned char __vmx_vmread(
   size_t Field,
   size_t *FieldValue
);
```

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Campo*|[in] O campo VMCS para ler.|
|*FieldValue*|[in] Ler de um ponteiro para o local para armazenar o valor do campo VMCS especificado pela `Field` parâmetro.|

## <a name="return-value"></a>Valor de retorno

|Valor|Significado|
|-----------|-------------|
|0|A operação foi bem-sucedida.|
|1|A operação falhou com status estendido disponível no `VM-instruction error field` de VMCS o atual.|
|2|Falha na operação sem status disponível.|

## <a name="remarks"></a>Comentários

O `__vmx_vmread` função é equivalente ao `VMREAD` instruções de máquina. O valor da `Field` parâmetro é um índice de campo codificado que é descrito na documentação da Intel. Para obter mais informações, pesquise o documento, "Intel Virtualization Technical especificação para a arquitetura IA-32 Intel," documento número C97063-002, o [Intel Corporation](https://software.intel.com/articles/intel-sdm) do site e, em seguida, consulte o Apêndice C do documento .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__vmx_vmread`|X64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__vmx_vmwrite](../intrinsics/vmx-vmwrite.md)