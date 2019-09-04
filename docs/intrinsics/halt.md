---
title: __halt
ms.date: 09/02/2019
f1_keywords:
- __halt
- __halt_cpp
helpviewer_keywords:
- __halt intrinsic
- HLT instruction
ms.assetid: a074f44a-101c-45a5-8a5e-cfd223c34002
ms.openlocfilehash: 66f5e05e7673523966ef35ac743fc585930b511c
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222155"
---
# <a name="__halt"></a>__halt

**Seção específica da Microsoft**

Interrompe o microprocessador até uma interrupção habilitada, uma NMI (interrupção não mascarável) ou uma redefinição ocorre.

## <a name="syntax"></a>Sintaxe

```C
void __halt( void );
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__halt`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

A `__halt` função é equivalente à instrução `HLT` da máquina e está disponível somente no modo kernel. Para obter mais informações, pesquise o documento "manual do desenvolvedor de software de arquitetura Intel, volume 2: Referência de conjunto de instruções ", no site da [Intel Corporation](https://software.intel.com/articles/intel-sdm) .

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
