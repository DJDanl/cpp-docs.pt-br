---
title: debugbreak | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- __debugbreak_cpp
- __debugbreak
dev_langs: C++
helpviewer_keywords:
- breakpoints, __debugbreak intrinsic
- __debugbreak intrinsic
ms.assetid: 1d1e1c0c-891a-4613-ae4b-d790094ba830
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 07cac11754a8b5f242c38d5fd45d4c7f0707d69a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="debugbreak"></a>__debugbreak
**Seção específica da Microsoft**  
  
 Cria um ponto de interrupção no código, onde o sistema solicitará que o usuário execute o depurador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __debugbreak();  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|Cabeçalho|  
|---------------|------------------|------------|  
|`__debugbreak`|x86, ARM, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|\<intrin.h >|  
  
## <a name="remarks"></a>Comentários  
 O `__debugbreak` compilador intrínseco, semelhante ao [DebugBreak](http://msdn.microsoft.com/library/windows/desktop/ms679297.aspx), é uma maneira de Win32 portátil para fazer com que um ponto de interrupção.  
  
> [!NOTE]
>  Ao compilar com **/clr**, uma função que contém `__debugbreak` serão compilados para MSIL. `asm int 3` faz com que a função seja compilada como nativa. Para obter mais informações, consulte [ASM](../assembler/inline/asm.md).  
  
 Por exemplo:  
  
```  
main() {  
   __debugbreak();  
}  
```  
  
 é similar a:  
  
```  
main() {  
   __asm {  
      int 3  
   }  
}  
```  
  
 em computadores x86.  
  
 Essa rotina só está disponível como função intrínseca.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)