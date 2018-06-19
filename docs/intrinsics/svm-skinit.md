---
title: __svm_skinit | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __svm_skinit
dev_langs:
- C++
helpviewer_keywords:
- SKINIT instruction
- __svm_skinit intrinsic
ms.assetid: 787ec781-4cf2-40a2-aa20-5192334b131a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 95e47608b7ec58e433d9be5e2f2178a825b6be2e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33338098"
---
# <a name="svmskinit"></a>__svm_skinit
**Seção específica da Microsoft**  
  
 Inicia o carregamento do software verificável seguro, como um monitor de máquina virtual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __svm_skinit(  
   int SLB  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`SLB`|O endereço físico de 32 bits de um byte de 64K seguro carregador bloco SLB ().|  
  
## <a name="remarks"></a>Comentários  
 O `__svm_skinit` função é equivalente a `SKINIT` instrução da máquina. Essa função é parte de um sistema de segurança que usa o processador e um módulo de plataforma confiável (TPM) para verificar e carregar um software confiável chamado um núcleo de segurança (SK). Um monitor de máquina virtual é um exemplo de um núcleo de segurança. O sistema de segurança verifica a componentes de programa carregado durante o processo de inicialização e protege os componentes de violação por interrupções, acesso ao dispositivo ou outro programa, se o computador é um multiprocessador.  
  
 O `SLB` parâmetro especifica o endereço físico de um bloco de 64K de memória chamada a *proteger carregador bloco* (SLB). O SLB contém um programa chamado o carregador seguro que estabelece o ambiente operacional do computador e subsequentemente carrega o kernel de segurança.  
  
 Essa função oferece suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento, "Manual Volume do programador de arquitetura AMD64 2: programação do sistema," número 24593, 3.11, de revisão de documento no [corporation AMD](http://go.microsoft.com/fwlink/p/?linkid=23746) site.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__svm_skinit`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)