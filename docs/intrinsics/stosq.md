---
title: __stosq | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __stosq
dev_langs:
- C++
helpviewer_keywords:
- rep stosq instruction
- stosq instruction
- __stosq intrinsic
ms.assetid: 3ea28297-4369-4c2d-bf0c-91fa539ce209
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f6afd5349595f849e8b7418fa1efb628c200b4b6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33332020"
---
# <a name="stosq"></a>__stosq
**Seção específica da Microsoft**  
  
 Gera uma instrução de cadeia de caracteres de repositório (`rep stosq`).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __stosb(   
   unsigned __int64* Dest,   
   unsigned __int64 Data,   
   size_t Count   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `Dest`  
 O destino da operação.  
  
 [in] `Data`  
 Os dados a serem armazenados.  
  
 [in] `Count`  
 O comprimento do bloco de quadwords para gravação.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__stosq`|AMD64|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 O resultado é que o quadword `Data` é gravado em um bloco de `Count` quadwords no `Dest` cadeia de caracteres.  
  
 Essa rotina só está disponível como função intrínseca.  
  
## <a name="example"></a>Exemplo  
  
```  
// stosq.c  
// processor: x64  
#include <stdio.h>  
#include <intrin.h>  
  
#pragma intrinsic(__stosq)  
  
int main()  
{  
   unsigned __int64 val = 0xFFFFFFFFFFFFI64;  
   unsigned __int64 a[10];  
   memset(a, 0, sizeof(a));  
   __stosq(a+1, val, 2);  
   printf("%I64x %I64x %I64x %I64x", a[0], a[1], a[2], a[3]);   
}  
```  
  
## <a name="output"></a>Saída  
  
```  
0 ffffffffffff ffffffffffff 0  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)