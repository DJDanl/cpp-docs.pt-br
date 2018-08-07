---
title: 'Operador new de dontusenewusemake:: Operator | Microsoft Docs'
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
ms.openlocfilehash: 59354062dded7792dca1cd84683bba64f6a64aa0
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39571419"
---
# <a name="dontusenewusemakeoperator-new-operator"></a>DontUseNewUseMake::operator Operador new
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void* operator new(  
   size_t,  
   _In_ void* placement  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *__unnamed0*  
 Um parâmetro não nomeado que especifica o número de bytes de memória para alocar.  
  
 *placement*  
 O tipo a ser alocado.  
  
## <a name="return-value"></a>Valor de retorno  
 Fornece uma maneira de passar argumentos adicionais se você sobrecarregar o operador **novo**.  
  
## <a name="remarks"></a>Comentários  
 Sobrecarrega o operador **novos** e impede que ele seja usado no `RuntimeClass`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe DontUseNewUseMake](../windows/dontusenewusemake-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)