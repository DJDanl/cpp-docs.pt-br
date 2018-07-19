---
title: _com_ptr_t::QueryInterface | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::QueryInterface
- _com_ptr_t.QueryInterface
dev_langs:
- C++
helpviewer_keywords:
- QueryInterface method [C++]
ms.assetid: d03292f1-6b02-40db-9756-8b0837a97319
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c455ce81a869d64b3a9019088028e384c6a06217
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942117"
---
# <a name="comptrtqueryinterface"></a>_com_ptr_t::QueryInterface
**Seção específica da Microsoft**  
  
 Chamadas a `QueryInterface` função de membro de `IUnknown` no ponteiro de interface encapsulado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
template<typename _InterfaceType> HRESULT QueryInterface (  
   const IID& iid,  
   _InterfaceType*& p   
) throw ( );  
template<typename _InterfaceType> HRESULT QueryInterface (  
   const IID& iid,  
   _InterfaceType** p  
) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *IID*  
 `IID` de um ponteiro de interface.  
  
 *p*  
 Ponteiro da interface bruto.  
  
## <a name="remarks"></a>Comentários  
 Chamadas `IUnknown::QueryInterface` no ponteiro de interface encapsulado com especificado `IID` e retorna o ponteiro de interface bruto resultante na *p*. Essa rotina retorna o HRESULT para indicar êxito ou falha.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)