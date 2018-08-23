---
title: _disable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _disable_cpp
- _disable
dev_langs:
- C++
helpviewer_keywords:
- _disable intrinsic
- rsm instruction
- disable intrinsic
ms.assetid: 52da3df9-815c-4524-9839-6d1742cff5c6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2748d0412c9ee0f7e7684d35a38f3c2b5d133754
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42541177"
---
# <a name="disable"></a>_disable
**Seção específica da Microsoft**  
  
 Desabilita interrupções.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _disable(void);  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`_disable`|x86, ARM, x64|  
  
 **Arquivo de cabeçalho** \<intrin. h >  
  
## <a name="remarks"></a>Comentários  
 `_disable` instrui o processador para limpar o sinalizador de interrupção. Em sistemas x86, essa função gera a instrução Limpar Sinalizador de Interrupção (`cli`).  
  
 Essa função só está disponível no modo de kernel. Se usado no modo de usuário, uma exceção de instrução privilegiada será gerada em tempo de execução.  
  
 Em plataformas ARM, essa rotina só está disponível como um intrínseco.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)