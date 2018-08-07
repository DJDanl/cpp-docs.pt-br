---
title: Classe RuntimeClass | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClass
dev_langs:
- C++
helpviewer_keywords:
- RuntimeClass class
ms.assetid: d52f9d1a-98e5-41f2-a143-8fb629dd0727
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d777dd15e484ae296139bbe2bdc9b0cddcab2d59
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39606326"
---
# <a name="runtimeclass-class"></a>Classe RuntimeClass
Representa uma classe COM ou WinRT que herda as interfaces especificadas e fornece o tempo de execução do Windows especificado, COM clássico e suporte fraco de referência.  
  
Essa classe fornece a implementação de texto clichê de classes do WinRT e COM, fornecendo a implementação de `QueryInterface`, `AddRef`, `Release` etc., gerencia a contagem de referência do módulo e tem suporte para fornecer a fábrica de classes para objetos ativáveis.
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename ...TInterfaces> class RuntimeClass
template <unsigned int classFlags, typename ...TInterfaces> class RuntimeClass;
```
  
### <a name="parameters"></a>Parâmetros  
 *classFlags*  
Parâmetro opcional. Uma combinação de um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valores de enumeração. O `__WRL_CONFIGURATION_LEGACY__` macro pode ser definida para alterar o valor padrão de classFlags para todas as classes de tempo de execução do projeto. Se definido, RuntimeClass instâncias são não agile por padrão. Quando não definido, as instâncias de RuntimeClass são agile por padrão. Para evitar ambiguidade, sempre especifique o `Microsoft::WRL::FtmBase` na `TInterfaces` ou `RuntimeClassType::InhibitFtmBase`. Observe que, se InhibitFtmBase e FtmBase são que ambos utilizou o objeto será agile.
 
 *TInterfaces*  
A lista de interfaces que o objeto implementa além `IUnknown`, `IInspectable` ou outras interfaces controlados pelo [RuntimeClassType](../windows/runtimeclasstype-enumeration.md). Ele também pode listar outras classes a serem derivadas, notavelmente `Microsoft::WRL::FtmBase` para tornar o objeto agile e fazer com que ela implemente `IMarshal`.
  
## <a name="members"></a>Membros  
`RuntimeClassInitialize` Uma função que inicializa o objeto se a `MakeAndInitialize` função de modelo é usada para construir o objeto. Ele retorna S_OK se o objeto foi inicializado com êxito, ou um código de erro COM se a falha na inicialização. O código de erro COM é propagado como o valor de retorno `MakeAndInitialize`. Observe que o `RuntimeClassInitialize` método não será chamado se o `Make` função de modelo é usada para construir o objeto.

### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor RuntimeClass::RuntimeClass](../windows/runtimeclass-runtimeclass-constructor.md)|Inicializa a instância atual da classe RuntimeClass.|  
|[Destruidor RuntimeClass::~RuntimeClass](../windows/runtimeclass-tilde-runtimeclass-destructor.md)|Realiza o desligamento a instância atual da classe RuntimeClass.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
Isso é um detalhe de implementação.
  
## <a name="requirements"></a>Requisitos  
**Cabeçalho:** Implements. h  
  
**Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)