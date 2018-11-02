---
title: __svm_skinit
ms.date: 11/04/2016
f1_keywords:
- __svm_skinit
helpviewer_keywords:
- SKINIT instruction
- __svm_skinit intrinsic
ms.assetid: 787ec781-4cf2-40a2-aa20-5192334b131a
ms.openlocfilehash: 630d4b9d93802038bd00b65495bb18455b0c61a4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50591211"
---
# <a name="svmskinit"></a>__svm_skinit

**Seção específica da Microsoft**

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

Essa função dá suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento "Volume de Manual do programador da arquitetura AMD64 2: programação do sistema," número 24593, 3.11, de revisão de documentos na [corporation AMD](https://developer.amd.com/resources/developer-guides-manuals/) site.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__svm_skinit`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)