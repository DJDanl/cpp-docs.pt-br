---
title: __svm_clgi
ms.date: 11/04/2016
f1_keywords:
- __svm_clgi
helpviewer_keywords:
- CLGI instruction
- __svm_clgi intrinsic
ms.assetid: 6640f5ab-9472-46f9-a042-e15c4f1ff858
ms.openlocfilehash: fe25141499a19a265e2ac3ec746664ecd6cc9a2e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62390302"
---
# <a name="svmclgi"></a>__svm_clgi

**Seção específica da Microsoft**

Limpa o sinalizador de interrupção global.

## <a name="syntax"></a>Sintaxe

```
void __svm_clgi( void );
```

## <a name="remarks"></a>Comentários

O `__svm_clgi` função é equivalente ao `CLGI` instruções de máquina. O sinalizador de interrupção global determina se o microprocessador ignora, adia ou lida com interrupções devido a eventos como uma conclusão de e/s, um alerta de temperatura de hardware ou uma exceção de depuração.

Essa função dá suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento "Volume de Manual do programador da arquitetura AMD64 2: Sistema de programação,"documento número 24593, revisão 3.11, o [corporation AMD](https://developer.amd.com/resources/developer-guides-manuals/) site.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__svm_clgi`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__svm_stgi](../intrinsics/svm-stgi.md)