---
title: __svm_clgi
ms.date: 09/02/2019
f1_keywords:
- __svm_clgi
helpviewer_keywords:
- CLGI instruction
- __svm_clgi intrinsic
ms.assetid: 6640f5ab-9472-46f9-a042-e15c4f1ff858
ms.openlocfilehash: 740c76e5dcc8f94b9257272624a6ad3c1f9726c1
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219963"
---
# <a name="__svm_clgi"></a>__svm_clgi

**Seção específica da Microsoft**

Limpa o sinalizador de interrupção global.

## <a name="syntax"></a>Sintaxe

```C
void __svm_clgi( void );
```

## <a name="remarks"></a>Comentários

A `__svm_clgi` função é equivalente à instrução `CLGI` da máquina. O sinalizador de interrupção global determina se o microprocessador ignora, adia ou manipula interrupções, devido a eventos como uma conclusão de e/s, um alerta de temperatura de hardware ou uma exceção de depuração.

Essa função dá suporte à interação do monitor de máquina virtual de um host com um sistema operacional convidado e seus aplicativos. Para obter mais informações, pesquise "volume manual do programador de arquitetura AMD64 2: Programação do sistema ", no site da [AMD Corporation](https://developer.amd.com/resources/developer-guides-manuals/) .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__svm_clgi`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__svm_stgi](../intrinsics/svm-stgi.md)
