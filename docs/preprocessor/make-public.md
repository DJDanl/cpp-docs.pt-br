---
title: make_public | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- vc-pragma.make_public
- make_public_CPP
dev_langs:
- C++
helpviewer_keywords:
- pragmas, make_public
- make_public pragma
ms.assetid: c3665f4d-268a-4932-9661-c37c8ae6a341
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 27db5ac934973178e2485327090ed70f994becec
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33849581"
---
# <a name="makepublic"></a>make_public
Indica que um tipo nativo deve ter a acessibilidade pública de assembly.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma make_public(type)  
```  
  
### <a name="parameters"></a>Parâmetros  
 `type` é o nome do tipo ao qual você deseja ter a acessibilidade pública de assembly.  
  
## <a name="remarks"></a>Comentários  
`make_public` é útil quando o tipo nativo que você deseja referenciar é de um arquivo .h que você não pode alterar. Se você desejar usar o tipo nativo na assinatura de uma função pública em um tipo com visibilidade pública de assembly, o tipo nativo também deve ter a acessibilidade pública do assembly. Caso contrário, o compilador emitirá um aviso.  
  
`make_public` deve ser especificado no escopo global e é aplicado apenas ao ponto em que é declarado até ao final do arquivo de código-fonte.  
  
O tipo nativo pode ser privado implicitamente ou explicitamente; consulte [visibilidade do tipo](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir é o conteúdo de um arquivo .h que contém as definições para duas estruturas nativas.  
  
```cpp  
// make_public_pragma.h  
struct Native_Struct_1 { int i; };  
struct Native_Struct_2 { int i; };  
```  
  
## <a name="example"></a>Exemplo  
O exemplo de código a seguir consome o arquivo de cabeçalho e mostra que, a menos que você marque explicitamente as estruturas nativas como públicas usando `make_public`, o compilador gerará um aviso quando você tentar usar as estruturas nativas na assinatura da função pública em um tipo gerenciado público.  
  
```cpp  
// make_public_pragma.cpp  
// compile with: /c /clr /W1  
#pragma warning (default : 4692)  
#include "make_public_pragma.h"  
#pragma make_public(Native_Struct_1)  
  
public ref struct A {  
   void Test(Native_Struct_1 u) {u.i = 0;}   // OK  
   void Test(Native_Struct_2 u) {u.i = 0;}   // C4692  
};  
```  
  
## <a name="see-also"></a>Consulte também  
[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)