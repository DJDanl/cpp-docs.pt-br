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
ms.openlocfilehash: f56b35ffb53da8947982359174784a0dbb3cef85
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40012580"
---
# <a name="weakref-class"></a>Classe WeakRef
Representa uma *referência fraca* que pode ser usado pelo apenas Windows Runtime, com clássico não. Uma referência fraca representa um objeto que pode ou não ser acessível.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
class WeakRef : public ComPtr<IWeakReference>  
```  
  
## <a name="remarks"></a>Comentários  
 Um **WeakRef** objeto mantém uma *referência forte*, que é associado um objeto e pode ser válido ou inválido. Chame o `As()` ou `AsIID()` método para obter uma referência forte. Quando a referência forte é válida, ele pode acessar o objeto associado. Quando a referência forte é inválida (**nullptr**), o objeto associado está inacessível.  
  
 Um **WeakRef** objeto normalmente é usado para representar um objeto cuja existência é controlada por um aplicativo ou thread externo. Por exemplo, construir uma **WeakRef** objeto a partir de uma referência a um objeto de arquivo. Enquanto o arquivo estiver aberto, a referência forte é válida. Mas, se o arquivo é fechado, a referência forte se torna inválida.  
  
 Observe que há uma alteração de comportamento na [como](../windows/weakref-as-method.md), [AsIID](../windows/weakref-asiid-method.md) e [CopyTo](../windows/weakref-copyto-method.md) métodos no SDK do Windows 10. Anteriormente, depois de chamar qualquer um desses métodos, você pode verificar o WeakRef para **nullptr** para determinar se uma referência forte foi obtida de com êxito, como no código a seguir:  
  
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
  
 O código acima não funciona ao usar o SDK do Windows 10 (ou posterior). Em vez disso, verifique o ponteiro que foi passado para **nullptr**.  
  
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
|[Construtor WeakRef::WeakRef](../windows/weakref-weakref-constructor.md)|Inicializa uma nova instância dos **WeakRef** classe.|  
|[Destruidor WeakRef::~WeakRef](../windows/weakref-tilde-weakref-destructor.md)|Realiza o desligamento da instância atual do **WeakRef** classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método WeakRef::As](../windows/weakref-as-method.md)|Define especificado `ComPtr` parâmetro de ponteiro para representar a interface especificada.|  
|[Método WeakRef::AsIID](../windows/weakref-asiid-method.md)|Define especificado `ComPtr` parâmetro de ponteiro para representar a ID de interface especificado.|  
|[Método WeakRef::CopyTo](../windows/weakref-copyto-method.md)|Atribui um ponteiro para uma interface, se disponível, para a variável de ponteiro especificado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador WeakRef::operator&](../windows/weakref-operator-ampersand-operator.md)|Retorna um `ComPtrRef` objeto que representa o atual **WeakRef** objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ComPtr`  
  
 `WeakRef`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)