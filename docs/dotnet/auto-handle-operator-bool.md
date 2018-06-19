---
title: 'bool auto_handle:: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- auto_handle.operator bool
- msclr.auto_handle.operator bool
- operator bool
- msclr::auto_handle::operator bool
- auto_handle::operator bool
dev_langs:
- C++
helpviewer_keywords:
- auto_handle::operator bool
ms.assetid: 2e535e99-cf87-4008-b588-02c587d77453
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 562aefc72a8ce2738a78527dcdc6a73f606a7627
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33106174"
---
# <a name="autohandleoperator-bool"></a>Bool auto_handle::operator
Operador para o uso de `auto_handle` em uma expressão condicional.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
operator bool();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 `true` Se o objeto encapsulado é válido. `false` caso contrário.  
  
## <a name="remarks"></a>Comentários  
 Esse operador realmente converte em `_detail_class::_safe_bool` que é mais seguro que `bool` porque ele não pode ser convertido em um tipo integral.  
  
## <a name="example"></a>Exemplo  
  
```  
// msl_auto_handle_operator_bool.cpp  
// compile with: /clr  
#include <msclr\auto_handle.h>  
  
using namespace System;  
using namespace msclr;  
  
int main() {  
   auto_handle<String> s1;  
   auto_handle<String> s2 = "hi";  
   if ( s1 ) Console::WriteLine( "s1 is valid" );  
   if ( !s1 ) Console::WriteLine( "s1 is invalid" );  
   if ( s2 ) Console::WriteLine( "s2 is valid" );  
   if ( !s2 ) Console::WriteLine( "s2 is invalid" );  
   s2.reset();  
   if ( s2 ) Console::WriteLine( "s2 is now valid" );  
   if ( !s2 ) Console::WriteLine( "s2 is now invalid" );  
}  
```  
  
```Output  
s1 is invalid  
s2 is valid  
s2 is now invalid  
```  
  
## <a name="requirements"></a>Requisitos  
 **Arquivo de cabeçalho** \<msclr\auto_handle.h >  
  
 **Namespace** msclr  
  
## <a name="see-also"></a>Consulte também  
 [Membros auto_handle](../dotnet/auto-handle-members.md)   
 [auto_handle::operator!](../dotnet/auto-handle-operator-logical-not.md)