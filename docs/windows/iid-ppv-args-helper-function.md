---
title: Função IID_PPV_ARGS_Helper | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/IID_PPV_ARGS_Helper
dev_langs:
- C++
helpviewer_keywords:
- IID_PPV_ARGS_Helper function
ms.assetid: afee9b23-8df1-4575-903f-e9ba748418f0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0cef979ae284a303b120df7d14ae71f311498423
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33882336"
---
# <a name="iidppvargshelper-function"></a>Função IID_PPV_ARGS_Helper
Verifica se o tipo do argumento especificado deriva o `IUnknown` interface.  
  
> [!IMPORTANT]
>  Essa especialização de modelo dá suporte à infraestrutura do WRL e não se destina a ser usado diretamente no seu código. Use [IID_PPV_ARGS](http://msdn.microsoft.com/library/windows/desktop/ee330727.aspx) em vez disso.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T>  
void** IID_PPV_ARGS_Helper(  
   _Inout_ Microsoft::WRL::Details::ComPtrRef<T> pp  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de argumento `pp`.  
  
 `pp`  
 Um ponteiro duplamente indireta.  
  
## <a name="return-value"></a>Valor de retorno  
 Argumento `pp` convertido para um ponteiro-para-um-ponteiro para `void`.  
  
## <a name="remarks"></a>Comentários  
 Um erro de tempo de compilação será gerado se o parâmetro de modelo `T` não deriva de `IUnknown`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
## <a name="see-also"></a>Consulte também  
 [Referência (biblioteca de tempo de execução do Windows)](http://msdn.microsoft.com/en-us/00000000-0000-0000-0000-000000000000)