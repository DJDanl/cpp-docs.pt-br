---
title: Classe ComPtrRef | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::ComPtrRef
dev_langs:
- C++
helpviewer_keywords:
- ComPtrRef class
ms.assetid: d6bdfd20-e977-45b4-9ac1-1b8efbdb77de
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7f7f392df62892ea0e053e9d243f85772fa0605d
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39463071"
---
# <a name="comptrref-class"></a>Classe ComPtrRef
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename T  
>  
class ComPtrRef : public ComPtrRefBase<T>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 Um [ComPtr\<T >](../windows/comptr-class.md) tipo ou um tipo derivado dele, não simplesmente a interface representada pelo `ComPtr`.  
  
## <a name="remarks"></a>Comentários  
 Representa uma referência a um objeto do tipo `ComPtr<T>`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor ComPtrRef::ComPtrRef](../windows/comptrref-comptrref-constructor.md)|Inicializa uma nova instância dos **ComPtrRef** classe a partir o ponteiro especificado para outro **ComPtrRef** objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método ComPtrRef::GetAddressOf](../windows/comptrref-getaddressof-method.md)|Recupera o endereço de um ponteiro para a interface representada pelo objeto ComPtrRef atual.|  
|[Método ComPtrRef::ReleaseAndGetAddressOf](../windows/comptrref-releaseandgetaddressof-method.md)|Exclui o atual **ComPtrRef** do objeto e retorna um ponteiro-para-um-ponteiro para a interface que foi representada pela **ComPtrRef** objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador ComPtrRef::operator InterfaceType**](../windows/comptrref-operator-interfacetype-star-star-operator.md)|Exclui o atual **ComPtrRef** do objeto e retorna um ponteiro-para-um-ponteiro para a interface que foi representada pela **ComPtrRef** objeto.|  
|[Operador ComPtrRef::operator T*](../windows/comptrref-operator-t-star-operator.md)|Retorna o valor da [PTR _](../windows/comptrrefbase-ptr-data-member.md) membro de dados do objeto ComPtrRef atual.|  
|[Operador ComPtrRef::operator void**](../windows/comptrref-operator-void-star-star-operator.md)|Exclui o atual **ComPtrRef** do objeto, converte o ponteiro para a interface que foi representado pela **ComPtrRef** objeto como um ponteiro-para-ponteiro-para **void**e, em seguida, Retorna o ponteiro de conversão.|  
|[Operador ComPtrRef::operator*](../windows/comptrref-operator-star-operator.md)|Recupera o ponteiro para a interface representado pelo atual **ComPtrRef** objeto.|  
|[Operador ComPtrRef::operator==](../windows/comptrref-operator-equality-operator.md)|Indica se dois **ComPtrRef** objetos são iguais.|  
|[Operador ComPtrRef::operator!=](../windows/comptrref-operator-inequality-operator.md)|Indica se dois **ComPtrRef** objetos não forem iguais.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ComPtrRefBase`  
  
 `ComPtrRef`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)