---
title: __readmsr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __readmsr
dev_langs:
- C++
helpviewer_keywords:
- Read Model Specific Register
- rdmsr instruction
- __readmsr intrinsic
ms.assetid: 7ab1f8e8-72cb-4ce4-817d-3e728a3c9716
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4e8196b25b1507c92542faa6dd8ca59b4632d8f0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33335907"
---
# <a name="readmsr"></a>__readmsr
**Seção específica da Microsoft**  
  
 Gera o `rdmsr` instrução, que lê o registro de modelo específico especificado pelo `register` e retorna seu valor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__int64 __readmsr(   
   int register   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `register`  
 O registro específico de modelo para ler.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor no registro especificado.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`__readmsr`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 Essa função só está disponível no modo kernel, e a rotina só está disponível como um intrínseco.  
  
 Para obter mais informações, consulte a documentação do AMD.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)