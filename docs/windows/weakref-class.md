---
title: Classe WeakRef | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef
dev_langs:
- C++
helpviewer_keywords:
- WeakRef class
ms.assetid: 572be703-c641-496c-8af5-ad6164670ba1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ba7efc595be55b807cd3f044269db0debcb72407
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33891692"
---
# <a name="weakref-class"></a>Classe WeakRef
Representa um *referência fraca* que pode ser usado por somente o Windows Runtime, COM. não clássico Uma referência fraca representa um objeto que pode ou não pode ser acessado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class WeakRef : public ComPtr<IWeakReference>  
```  
  
## <a name="remarks"></a>Comentários  
 Um objeto WeakRef mantém um *referência forte*, que é associado um objeto e pode ser válido ou inválido. Chame o método As() ou AsIID() para obter uma referência forte. Quando a referência forte é válida, ele pode acessar o objeto associado. Quando a referência forte é inválida (`nullptr`), o objeto associado está inacessível.  
  
 Um objeto de WeakRef normalmente é usado para representar um objeto cuja existência é controlada por um aplicativo ou thread externo. Por exemplo, criar um objeto de WeakRef de uma referência a um objeto de arquivo. Enquanto o arquivo estiver aberto, a referência forte é válida. Mas, se o arquivo for fechado, a referência forte torna-se inválido.  
  
 Observe que há uma alteração de comportamento no [como](../windows/weakref-as-method.md), [AsIID](../windows/weakref-asiid-method.md) e [CopyTo](../windows/weakref-copyto-method.md) métodos no SDK do Windows 10. Anteriormente, depois de chamar qualquer um desses métodos, você pode verificar o WeakRef para `nullptr` para determinar se uma referência forte foi obtida de com êxito, como no código a seguir:  
  
```cpp  
WeakRef wr;  
strongComptrRef.AsWeak(&wr);  
  
// Now suppose that the object strongComPtrRef points to no longer exists  
// and the following code tries to get a strong ref from the weak ref:  
ComPtr<ISomeInterface> strongRef;  
HRESULT hr = wr.As(&strongRef);  
  
// This check won't work with the Windows 10 SDK version of the library.  
// Check the input pointer instead.  
if(wr == nullptr)  
{  
    wprintf(L"Couldn’t get strong ref!");  
}  
  
```  
  
 O código acima não funciona ao usar o SDK do Windows 10 (ou posterior). Em vez disso, verifique o ponteiro foi passado para `nullptr`.  
  
```cpp  
if (strongRef == nullptr)  
{  
    wprintf(L"Couldn't get strong ref!");  
 }  
  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor WeakRef::WeakRef](../windows/weakref-weakref-constructor.md)|Inicializa uma nova instância da classe WeakRef.|  
|[Destruidor WeakRef::~WeakRef](../windows/weakref-tilde-weakref-destructor.md)|Deinitializes a instância atual da classe WeakRef.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método WeakRef::As](../windows/weakref-as-method.md)|Define o parâmetro de ponteiro ComPtr especificado para representar a interface especificada.|  
|[Método WeakRef::AsIID](../windows/weakref-asiid-method.md)|Define o parâmetro de ponteiro ComPtr especificado para representar a ID de interface especificado.|  
|[Método WeakRef::CopyTo](../windows/weakref-copyto-method.md)|Atribui um ponteiro para uma interface, se disponível, para a variável de ponteiro especificado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador WeakRef::operator&](../windows/weakref-operator-ampersand-operator.md)|Retorna um objeto ComPtrRef que representa o objeto WeakRef atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ComPtr`  
  
 `WeakRef`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)