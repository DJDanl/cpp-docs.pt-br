---
title: "gerenciado, não gerenciado | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc-pragma.unmanaged
- managed_CPP
- unmanaged_CPP
- vc-pragma.managed
dev_langs:
- C++
helpviewer_keywords:
- managed pragma
- pragmas, unmanaged
- pragmas, managed
- unmanaged pragma
ms.assetid: f072ddcc-e1ec-408a-8ce1-326ddb60e4a4
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bc7e86e053cec68a3a25c753b7c3b7fb8ab50363
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="managed-unmanaged"></a>gerenciado, não gerenciado
Habilita o controle do nível da função para criar funções como gerenciadas ou o não gerenciadas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      #pragma managed  
#pragma unmanaged  
#pragma managed([push,] on | off)  
#pragma managed(pop)  
```  
  
## <a name="remarks"></a>Comentários  
 O [/clr](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador fornece controle de nível de módulo para compilação funções como gerenciados ou não gerenciados.  
  
 Uma função não gerenciada será criada para a plataforma nativa e a execução dessa parte do programa será passada para a plataforma nativa pelo Common Language Runtime.  
  
 Funções são compiladas como gerenciado por padrão quando **/clr** é usado.  
  
 Ao aplicar essas pragmas:  
  
-   Adicione o pragma que precede uma função mas não em um corpo da função.  
  
-   Adicionar o pragma após `#include` instruções. Não use esses pragmas antes `#include` instruções.  
  
 O compilador ignora o `managed` e `unmanaged` pragmas se **/clr** não é usado na compilação.  
  
 Quando uma função de modelo é instanciada, o estado de pragma no momento da definição do modelo determina se ela é gerenciada ou não gerenciada.  
  
 Para obter mais informações, consulte [inicialização de Assemblies mistos](../dotnet/initialization-of-mixed-assemblies.md).  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// pragma_directives_managed_unmanaged.cpp  
// compile with: /clr  
#include <stdio.h>  
  
// func1 is managed  
void func1() {  
   System::Console::WriteLine("In managed function.");  
}  
  
// #pragma unmanaged  
// push managed state on to stack and set unmanaged state  
#pragma managed(push, off)  
  
// func2 is unmanaged  
void func2() {  
   printf("In unmanaged function.\n");  
}  
  
// #pragma managed  
#pragma managed(pop)  
  
// main is managed  
int main() {  
   func1();  
   func2();  
}  
```  
  
```Output  
In managed function.  
In unmanaged function.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)