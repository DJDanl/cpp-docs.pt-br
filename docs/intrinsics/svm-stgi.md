---
title: __svm_stgi | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: __svm_stgi
dev_langs: C++
helpviewer_keywords:
- __svm_stgi intrinsic
- STGI instruction
ms.assetid: 96488da4-5587-4e99-8674-627a9e51be84
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 94e386827ae747fb3289354ba380d390756359ff
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="svmstgi"></a>__svm_stgi
**Seção específica da Microsoft**  
  
 Define o sinalizador global de interrupção.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __svm_stgi(void);  
```  
  
## <a name="remarks"></a>Comentários  
 O `__svm_stgi` função é equivalente a `STGI` instrução da máquina. O sinalizador global interrupção determina se o microprocessador ignora, adia ou manipula interrupções devido a eventos como uma conclusão de e/s, um alerta de temperatura de hardware ou uma exceção de depuração.  
  
 Essa função oferece suporte a interação do monitor de máquina virtual do host com um sistema operacional e seus aplicativos de convidado. Para obter mais informações, pesquise o documento, "Manual Volume do programador de arquitetura AMD64 2: programação do sistema," número 24593, 3.11, de revisão de documento no [corporation AMD](http://go.microsoft.com/fwlink/p/?linkid=23746) site.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__svm_stgi`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [__svm_clgi](../intrinsics/svm-clgi.md)