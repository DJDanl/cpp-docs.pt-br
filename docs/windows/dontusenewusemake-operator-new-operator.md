---
title: 'Operador new dontusenewusemake:: Operator | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::DontUseNewUseMake::operator new
dev_langs:
- C++
helpviewer_keywords:
- operator new operator
ms.assetid: 6af07a0d-2271-430c-9d9b-5a4223fed049
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9785ea27c79ff0a118ff3697a22804c520b265ee
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33873674"
---
# <a name="dontusenewusemakeoperator-new-operator"></a>DontUseNewUseMake::operator Operador new
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void* operator new(  
   size_t,  
   _In_ void* placement  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `__unnamed0`  
 Um parâmetro não nomeado que especifica o número de bytes de memória a ser alocada.  
  
 `placement`  
 O tipo a ser alocada.  
  
## <a name="return-value"></a>Valor de retorno  
 Fornece uma maneira de passar argumentos adicionais se você sobrecarregar o operador `new`.  
  
## <a name="remarks"></a>Comentários  
 Sobrecargas de operador `new` e impede que ele seja usado em RuntimeClass.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe DontUseNewUseMake](../windows/dontusenewusemake-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)