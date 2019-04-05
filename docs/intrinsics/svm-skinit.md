---
title: __svm_skinit
ms.date: 11/04/2016
f1_keywords:
- __svm_skinit
helpviewer_keywords:
- SKINIT instruction
- __svm_skinit intrinsic
ms.assetid: 787ec781-4cf2-40a2-aa20-5192334b131a
ms.openlocfilehash: 199cba2623f9d8e47c08be642ec485599b87976e
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59026130"
---
# <a name="svmskinit"></a>__svm_skinit

**Específico da Microsoft**

Inicia o carregamento de software seguro verificável, como um monitor de máquina virtual.

## <a name="syntax"></a>Sintaxe

```
void __svm_skinit(
   int SLB
);
```

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`SLB`|O endereço físico de 32 bits de um byte de 64K bloco de carregador seguro (SLB).|

## <a name="remarks"></a>Comentários

O `__svm_skinit` função é equivalente ao `SKINIT` instruções de máquina. Essa função é parte de um sistema de segurança que usa o processador e um módulo de plataforma confiável (TPM) para verificar e carregar um software confiável chamado um kernel de segurança (SK). Um monitor de máquina virtual é um exemplo de um kernel de segurança. O sistema de segurança verifica os componentes de programa carregado durante o processo de inicialização e protege os componentes de violação por interrupções, acesso ao dispositivo ou outro programa, se o computador for um multiprocessador.

O `SLB` parâmetro especifica o endereço físico de um bloco de 64K de memória chamada a *bloco de carregador seguro* (SLB). O SLB contém um programa chamado o carregador seguro que estabelece o ambiente operacional do computador e, subsequentemente, carrega o kernel de segurança.

Essa função dá suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento "Volume de Manual do programador da arquitetura AMD64 2: Sistema de programação,"documento número 24593, revisão 3.11, o [corporation AMD](https://developer.amd.com/resources/developer-guides-manuals/) site.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__svm_skinit`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**FIM de Específico da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)