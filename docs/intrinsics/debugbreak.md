---
title: debugbreak | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __debugbreak_cpp
- __debugbreak
dev_langs:
- C++
helpviewer_keywords:
- breakpoints, __debugbreak intrinsic
- __debugbreak intrinsic
ms.assetid: 1d1e1c0c-891a-4613-ae4b-d790094ba830
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 71b7dfca165e76880370368282bdbd7728315cfa
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42539736"
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
|`__debugbreak`|x86, ARM, x64|\<intrin.h>|  
  
## <a name="remarks"></a>Comentários  
 O `__debugbreak` compilador intrínseco, semelhante ao [DebugBreak](http://msdn.microsoft.com/library/windows/desktop/ms679297.aspx), é uma maneira portátil do Win32 para fazer com que um ponto de interrupção.  
  
> [!NOTE]
>  Ao compilar com **/clr**, uma função contendo `__debugbreak` serão compilados para MSIL. `asm int 3` faz com que a função seja compilada como nativa. Para obter mais informações, consulte [ASM](../assembler/inline/asm.md).  
  
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