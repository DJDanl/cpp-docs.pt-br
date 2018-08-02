---
title: Classe ComPtr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr
dev_langs:
- C++
helpviewer_keywords:
- ComPtr class
ms.assetid: a6551902-6819-478a-8df7-b6f312ab1fb0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 21503e38bb612f935e26f6eaaa93df2097e10445
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39465331"
---
# <a name="comptr-class"></a>Classe ComPtr
Cria uma *ponteiro inteligente* tipo que representa a interface especificada pelo parâmetro de modelo. **ComPtr** automaticamente mantém uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <typename T>  
class ComPtr;  
  
template<class T>  
friend class ComPtr;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 A interface que o **ComPtr** representa.  
  
 *U*  
 Uma classe à qual o atual **ComPtr** é um amigo. (O modelo que usa esse parâmetro é protegido).  
  
## <a name="remarks"></a>Comentários  
 `ComPtr<>` declara um tipo que representa o ponteiro de interface subjacente. Use `ComPtr<>` para declarar uma variável e, em seguida, use o operador de acesso de membro de seta (`->`) para acessar uma função de membro de interface.  
  
 Para obter mais informações sobre ponteiros inteligentes, consulte a subseção "Ponteiros inteligentes COM" a [práticas recomendadas de codificação COM](http://msdn.microsoft.com/76aca556-b4d6-4e67-a2a3-4439900f0c39)tópico na biblioteca MSDN.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`InterfaceType`|Um sinônimo para o tipo especificado o *T* parâmetro de modelo.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor ComPtr::ComPtr](../windows/comptr-comptr-constructor.md)|Inicializa uma nova instância dos **ComPtr** classe. Sobrecargas fornecem construtores padrão, copiar, mover e conversão.|  
|[Destruidor ComPtr::~ComPtr](../windows/comptr-tilde-comptr-destructor.md)|Realiza o desligamento de uma instância do **ComPtr**.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método ComPtr::As](../windows/comptr-as-method.md)|Retorna um **ComPtr** objeto que representa a interface identificada pelo parâmetro de modelo especificado.|  
|[Método ComPtr::AsIID](../windows/comptr-asiid-method.md)|Retorna um **ComPtr** objeto que representa a interface identificada pela ID da interface especificada.|  
|[Método ComPtr::AsWeak](../windows/comptr-asweak-method.md)|Recupera uma referência fraca ao objeto atual.|  
|[Método ComPtr::Attach](../windows/comptr-attach-method.md)|Associa isso **ComPtr** com o tipo de interface especificado pelo parâmetro de tipo de modelo atual.|  
|[Método ComPtr::CopyTo](../windows/comptr-copyto-method.md)|Copia a interface atual ou especificada associada a este **ComPtr** para o ponteiro de saída especificado.|  
|[Método ComPtr::Detach](../windows/comptr-detach-method.md)|Desassocia isso **ComPtr** da interface que ele representa.|  
|[Método ComPtr::Get](../windows/comptr-get-method.md)|Recupera um ponteiro para a interface que está associado a este **ComPtr**.|  
|[Método ComPtr::GetAddressOf](../windows/comptr-getaddressof-method.md)|Recupera o endereço do [PTR _](../windows/comptr-ptr-data-member.md) membro de dados, que contém um ponteiro para a interface representado por esse **ComPtr**.|  
|[Método ComPtr::ReleaseAndGetAddressOf](../windows/comptr-releaseandgetaddressof-method.md)|Libera a interface associada a este **ComPtr** e, em seguida, recupera o endereço da [PTR _](../windows/comptr-ptr-data-member.md) membro de dados, que contém um ponteiro para a interface que foi lançado.|  
|[ComPtr::Reset](../windows/comptr-reset.md)|Libera todas as referências para o ponteiro para a interface que está associado a este **ComPtr**.|  
|[Método ComPtr::Swap](../windows/comptr-swap-method.md)|Troca a interface gerenciada pelo atual **ComPtr** com a interface gerenciada pelo especificado **ComPtr**.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método ComPtr::InternalAddRef](../windows/comptr-internaladdref-method.md)|Incrementa a contagem de referência da interface associada a este **ComPtr**.|  
|[Método ComPtr::InternalRelease](../windows/comptr-internalrelease-method.md)|Executa uma operação de lançamento COM na interface associado a este **ComPtr**.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador ComPtr::operator Microsoft::WRL::Details::BoolType](../windows/comptr-operator-microsoft-wrl-details-booltype-operator.md)|Indica se um **ComPtr** está gerenciando o tempo de vida do objeto de uma interface.|  
|[Operador ComPtr::operator&](../windows/comptr-operator-ampersand-operator.md)|Recupera o endereço do atual **ComPtr**.|  
|[Operador ComPtr::operator=](../windows/comptr-operator-assign-operator.md)|Atribui um valor para a atual **ComPtr**.|  
|[Operador ComPtr::operator->](../windows/comptr-operator-arrow-operator.md)|Recupera um ponteiro para o tipo especificado pelo parâmetro de modelo atual.|  
|[Operador ComPtr::operator==](../windows/comptr-operator-equality-operator.md)|Indica se dois **ComPtr** objetos são iguais.|  
|[Operador ComPtr::operator!=](../windows/comptr-operator-inequality-operator.md)|Indica se dois **ComPtr** objetos não forem iguais.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados ComPtr::ptr_](../windows/comptr-ptr-data-member.md)|Contém um ponteiro para a interface que está associado e gerenciada por esse **ComPtr**.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ComPtr`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)