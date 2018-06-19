---
title: SafeInt::SafeInt | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeInt::SafeInt
- SafeInt
- SafeInt.SafeInt
dev_langs:
- C++
helpviewer_keywords:
- SafeInt class, constructor
ms.assetid: 39e6f632-a396-40e6-9ece-cc3d4c5a78ef
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c7154349105c1953ad314b7928e7be8385179c42
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33888741"
---
# <a name="safeintsafeint"></a>SafeInt::SafeInt
Constrói um objeto `SafeInt`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
SafeInt() throw  
  
SafeInt (  
   const T& i  
) throw ()  
  
SafeInt (  
   bool b  
) throw ()  
  
template <typename U>  
SafeInt (  
   const SafeInt <U, E>& u  
)  
  
I template <typename U>  
SafeInt (  
   const U& i  
)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `i`  
 O valor para o novo `SafeInt` objeto. Isso deve ser um parâmetro de tipo T ou U, dependendo do construtor.  
  
 [in] `b`  
 O valor booliano para o novo `SafeInt` objeto.  
  
 [in] `u`  
 Um `SafeInt` de u tipo. O novo `SafeInt` objeto terá o mesmo valor como `u`, mas será do tipo T.  
  
 U  
 O tipo de dados armazenados na `SafeInt`. Isso pode ser um booliano, caractere ou inteiro de tipo. Se for um tipo inteiro, podem ser assinado ou não assinado e estar entre 8 e 64 bits.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre os tipos de modelo `T` e `E`, consulte [classe SafeInt](../windows/safeint-class.md).  
  
 O parâmetro de entrada para o construtor, `i` ou `u`, deve ser um tipo booliano, caractere ou inteiro. Se for outro tipo de parâmetro, o `SafeInt` classe chamadas [static_assert](../cpp/static-assert.md) para indicar um parâmetro de entrada inválido.  
  
 Os construtores que usam o tipo de modelo `U` converter automaticamente o parâmetro de entrada para o tipo especificado pelo `T`. O `SafeInt` classe converte os dados sem nenhuma perda de dados. Relatar para o manipulador de erro `E` se ele não é possível converter os dados para o tipo `T` sem perda de dados.  
  
 Se você criar um `SafeInt` de um parâmetro booliano, é necessário inicializar o valor imediatamente. Não é possível construir um `SafeInt` usando o código `SafeInt<bool> sb;`. Isso irá gerar um erro de compilação.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** safeint.h  
  
 **Namespace:** msl::utilities  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de SafeInt](../windows/safeint-library.md)   
 [Classe SafeInt](../windows/safeint-class.md)   
 [Classe SafeIntException](../windows/safeintexception-class.md)