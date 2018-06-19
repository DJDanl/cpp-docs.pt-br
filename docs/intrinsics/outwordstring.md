---
title: __outwordstring | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __outwordstring
dev_langs:
- C++
helpviewer_keywords:
- rep outsw instruction
- __outwordstring intrinsic
- outsw instruction
ms.assetid: b470c7a0-1de9-4370-886a-b2c3a1f842f4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fc25fdc4d43b7454761787264583b5e4f8fa47e0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33333688"
---
# <a name="outwordstring"></a>__outwordstring
**Seção específica da Microsoft**  
  
 Gera o `rep outsw` instrução, que envia `Count` palavras que começam em `Buffer` para a porta de e/s especificada pelo `Port`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __outwordstring(   
   unsigned short Port,   
   unsigned short* Buffer,   
   unsigned long Count   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `Port`  
 A porta para enviar os dados.  
  
 [in] `Buffer`  
 Um ponteiro para os dados a serem enviadas a porta especificada.  
  
 [in] `Count`  
 O número de palavras para enviar.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__outwordstring`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 Essa rotina só está disponível como função intrínseca.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)