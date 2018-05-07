---
title: Ativar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _enable
- _enable_cpp
dev_langs:
- C++
helpviewer_keywords:
- enable intrinsic
- _enable intrinsic
- ssm instruction
ms.assetid: 8bee669b-6bd8-4e25-9383-bb7d57295b4d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 86e6c8ba9fc1b4dff9b1ad947a770ae901937611
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="enable"></a>_enable
**Seção específica da Microsoft**  
  
 Permite interrupções.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _enable(void);  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`_enable`|x86, ARM, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 `_enable` instrui o processador para definir o sinalizador de interrupção. Em sistemas x86, essa função gera a instrução Definir Sinalizador de Interrupção (`sti`).  
  
 Essa função só está disponível no modo de kernel. Se usada no modo de usuário, uma exceção de instrução privilegiada será gerada.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)