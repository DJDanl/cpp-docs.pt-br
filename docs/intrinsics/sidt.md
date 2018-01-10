---
title: __sidt | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: __sidt
dev_langs: C++
helpviewer_keywords:
- sidt instruction
- __sidt intrinsic
ms.assetid: 01e83d14-6e63-4dea-8f64-5a0339d69641
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d67e671f2f374790c50e45777d62317d3899c383
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="sidt"></a>__sidt
**Seção específica da Microsoft**  
  
 Armazena o valor do registro de tabela de descritor de interrupção (IDTR) no local de memória especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __sidt(  
     void *Destination);  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `Destination`|Um ponteiro para o local da memória onde IDTR está armazenado.|  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__sidt`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 O `__sidt` função é equivalente a `SIDT` instrução da máquina. Para obter mais informações, pesquise o documento, "Manual do desenvolvedor de Software de arquitetura Intel, Volume 2: referência de conjunto de instruções," no [Intel Corporation](http://go.microsoft.com/fwlink/p/?linkid=127) site.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [__lidt](../intrinsics/lidt.md)