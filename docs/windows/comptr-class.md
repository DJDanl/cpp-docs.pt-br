---
title: Classe ComPtr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr
dev_langs:
- C++
helpviewer_keywords:
- ComPtr class
ms.assetid: a6551902-6819-478a-8df7-b6f312ab1fb0
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 04f8181c7308d63cc4fe07aaf4a05d34ccfaf132
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="comptr-class"></a>Classe ComPtr
Cria um *ponteiro inteligente* tipo que representa a interface especificada pelo parâmetro de modelo. ComPtr automaticamente mantém uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename T  
>  
class ComPtr;  
  
template<  
   class U  
>  
friend class ComPtr;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A interface que representa o ComPtr.  
  
 `U`  
 Uma classe à qual a ComPtr atual é um amigo. (O modelo que usa esse parâmetro é protegido).  
  
## <a name="remarks"></a>Comentários  
 ComPtr <> declara um tipo que representa o ponteiro de interface subjacente. Use ComPtr <> para declarar uma variável e, em seguida, use o operador de acesso de membro de seta (`->`) para acessar uma função de membro de interface.  
  
 Para obter mais informações sobre como ponteiros inteligentes, consulte a subseção "COM ponteiros inteligentes" o [práticas de codificação COM](http://msdn.microsoft.com/en-us/76aca556-b4d6-4e67-a2a3-4439900f0c39)tópico na biblioteca MSDN.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`InterfaceType`|Um sinônimo para o tipo especificado pelo `T` parâmetro do modelo.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor ComPtr::ComPtr](../windows/comptr-comptr-constructor.md)|Inicializa uma nova instância da classe ComPtr. Sobrecargas fornecem construtores padrão, copiar, mover e conversão.|  
|[Destruidor ComPtr::~ComPtr](../windows/comptr-tilde-comptr-destructor.md)|Deinitializes uma instância de ComPtr.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método ComPtr::As](../windows/comptr-as-method.md)|Retorna um objeto ComPtr que representa a interface identificada pelo parâmetro de modelo especificado.|  
|[Método ComPtr::AsIID](../windows/comptr-asiid-method.md)|Retorna um objeto ComPtr que representa a interface identificada pela ID da interface especificada.|  
|[Método ComPtr::AsWeak](../windows/comptr-asweak-method.md)|Recupera uma referência fraca ao objeto atual.|  
|[Método ComPtr::Attach](../windows/comptr-attach-method.md)|Associa esse ComPtr com o tipo de interface especificado pelo parâmetro de tipo de modelo atual.|  
|[Método ComPtr::CopyTo](../windows/comptr-copyto-method.md)|Copia a interface atual ou especificada associada a este ComPtr para o ponteiro de saída especificado.|  
|[Método ComPtr::Detach](../windows/comptr-detach-method.md)|Desassocia este ComPtr da interface que representa.|  
|[Método ComPtr::Get](../windows/comptr-get-method.md)|Recupera um ponteiro para a interface que está associado este ComPtr.|  
|[Método ComPtr::GetAddressOf](../windows/comptr-getaddressof-method.md)|Recupera o endereço do [PTR _](../windows/comptr-ptr-data-member.md) membro de dados, que contém um ponteiro para a interface representado por esse ComPtr.|  
|[Método ComPtr::ReleaseAndGetAddressOf](../windows/comptr-releaseandgetaddressof-method.md)|Libera a interface associada a este ComPtr e, em seguida, recupera o endereço do [PTR _](../windows/comptr-ptr-data-member.md) membro de dados, que contém um ponteiro para a interface que foi liberado.|  
|[ComPtr::Reset](../windows/comptr-reset.md)|Libera todas as referências para o ponteiro para a interface que está associado este ComPtr.|  
|[Método ComPtr::Swap](../windows/comptr-swap-method.md)|Troca a interface gerenciada por ComPtr o atual com a interface gerenciada pelo ComPtr especificado.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método ComPtr::InternalAddRef](../windows/comptr-internaladdref-method.md)|Incrementa a contagem de referência da interface associada a este ComPtr.|  
|[Método ComPtr::InternalRelease](../windows/comptr-internalrelease-method.md)|Executa uma operação COM versão na interface associado a este ComPtr.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador ComPtr::operator Microsoft::WRL::Details::BoolType](../windows/comptr-operator-microsoft-wrl-details-booltype-operator.md)|Indica se há ou não uma ComPtr está gerenciando o tempo de vida do objeto de uma interface.|  
|[Operador ComPtr::operator&](../windows/comptr-operator-ampersand-operator.md)|Recupera o endereço de ComPtr o atual.|  
|[Operador ComPtr::operator=](../windows/comptr-operator-assign-operator.md)|Atribui um valor para o ComPtr atual.|  
|[Operador ComPtr::operator->](../windows/comptr-operator-arrow-operator.md)|Recupera um ponteiro para o tipo especificado pelo parâmetro de modelo atual.|  
|[Operador ComPtr::operator==](../windows/comptr-operator-equality-operator.md)|Indica se dois objetos ComPtr são iguais.|  
|[Operador ComPtr::operator!=](../windows/comptr-operator-inequality-operator.md)|Indica se dois objetos ComPtr não são iguais.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados ComPtr::ptr_](../windows/comptr-ptr-data-member.md)|Contém um ponteiro para a interface que está associado e gerenciado por este ComPtr.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ComPtr`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)