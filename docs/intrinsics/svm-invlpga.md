---
title: __svm_invlpga | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: __svm_invlpga
dev_langs: C++
helpviewer_keywords:
- __svm_invlpga intrinsic
- INVLPGA instruction
ms.assetid: aa6578ce-8278-464b-8815-a0fc45330915
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f3206fa7f67fcd676b1490c6fad3be9a03c1ea40
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="svminvlpga"></a>__svm_invlpga
**Seção específica da Microsoft**  
  
 Invalida a entrada de mapeamento de endereço no buffer de visão-aside de tradução do computador. Parâmetros especificam o endereço virtual e o identificador de espaço de endereço da página para invalidar.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __svm_invlpga(  
     void *Va,  
     int ASID);  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `Va`|O endereço virtual da página para invalidar.|  
|[in] `ASID`|O identificador do espaço de endereço (ASID) da página para invalidar.|  
  
## <a name="remarks"></a>Comentários  
 O `__svm_invlpga` função é equivalente a `INVLPGA` instrução da máquina. Essa função oferece suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento, "Manual Volume do programador de arquitetura AMD64 2: programação do sistema," número 24593, 3.11, de revisão de documento no [corporation AMD](http://go.microsoft.com/fwlink/p/?linkid=23746) site.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__svm_invlpga`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)