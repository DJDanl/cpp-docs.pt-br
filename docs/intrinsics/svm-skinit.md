---
title: __svm_skinit
ms.date: 09/02/2019
f1_keywords:
- __svm_skinit
helpviewer_keywords:
- SKINIT instruction
- __svm_skinit intrinsic
ms.assetid: 787ec781-4cf2-40a2-aa20-5192334b131a
ms.openlocfilehash: 6657921d647a23bf027a5800702527951f7f6831
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219862"
---
# <a name="__svm_skinit"></a>__svm_skinit

**Seção específica da Microsoft**

Inicia o carregamento de softwares seguros verificáveis, como um monitor de máquina virtual.

## <a name="syntax"></a>Sintaxe

```C
void __svm_skinit(
   int block_address
);
```

### <a name="parameters"></a>Parâmetros

*block_address*\
O endereço físico de 32 bits de um SLB (bloco de carregador seguro) de 64K bytes.

## <a name="remarks"></a>Comentários

A `__svm_skinit` função é equivalente à instrução `SKINIT` da máquina. Essa função faz parte de um sistema de segurança que usa o processador e um Trusted Platform Module (TPM), para verificar e carregar um software confiável, chamado de *kernel de segurança* (SK). Um monitor de máquina virtual é um exemplo de um kernel de segurança. O sistema de segurança verifica os componentes do programa carregados durante o processo de inicialização. Ele protege os componentes contra violação por interrupções, acesso ao dispositivo ou outro programa se o computador for um multiprocessador.

O parâmetro *block_address* especifica o endereço físico de um bloco de 64K de memória chamado de SLB ( *bloco de carregador seguro* ). O SLB contém um programa chamado *carregador seguro*. Ele estabelece o ambiente operacional para o computador e, em seguida, carrega o kernel de segurança.

Essa função dá suporte à interação do monitor de máquina virtual de um host com um sistema operacional convidado e seus aplicativos. Para obter mais informações, pesquise "volume manual do programador de arquitetura AMD64 2: Programação do sistema ", no site da [AMD Corporation](https://developer.amd.com/resources/developer-guides-manuals/) .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__svm_skinit`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
