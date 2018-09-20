---
title: __svm_stgi | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __svm_stgi
dev_langs:
- C++
helpviewer_keywords:
- __svm_stgi intrinsic
- STGI instruction
ms.assetid: 96488da4-5587-4e99-8674-627a9e51be84
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fd4d2593621c7c2cc36f84580a757e98f5e48c92
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46431242"
---
# <a name="svmstgi"></a>__svm_stgi

**Seção específica da Microsoft**

Define o sinalizador de interrupção global.

## <a name="syntax"></a>Sintaxe

```
void __svm_stgi(void);
```

## <a name="remarks"></a>Comentários

O `__svm_stgi` função é equivalente ao `STGI` instruções de máquina. O sinalizador de interrupção global determina se o microprocessador ignora, adia ou lida com interrupções devido a eventos como uma conclusão de e/s, um alerta de temperatura de hardware ou uma exceção de depuração.

Essa função dá suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento "Volume de Manual do programador da arquitetura AMD64 2: programação do sistema," número 24593, 3.11, de revisão de documentos na [corporation AMD](https://developer.amd.com/resources/developer-guides-manuals/) site.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__svm_stgi`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__svm_clgi](../intrinsics/svm-clgi.md)