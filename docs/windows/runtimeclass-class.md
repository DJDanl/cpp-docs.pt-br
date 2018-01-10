---
title: Classe RuntimeClass | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::RuntimeClass
dev_langs: C++
helpviewer_keywords: RuntimeClass class
ms.assetid: d52f9d1a-98e5-41f2-a143-8fb629dd0727
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d5c75492b55cd1c238798d3500e2157738c3c58f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="runtimeclass-class"></a>Classe RuntimeClass
Representa uma classe WinRT ou COM que herda as interfaces especificadas e fornece o tempo de execução do Windows especificado, COM clássico e suporte de referência fraca.  
  
Essa classe fornece a implementação de boilerplate de classes do WinRT e COM, fornecendo a implementação de `QueryInterface`, `AddRef`, `Release` etc., gerencia a contagem de referência do módulo e tem suporte para fornecer a fábrica de classes para objetos ativáveis.
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename ...TInterfaces> class RuntimeClass
template <unsigned int classFlags, typename ...TInterfaces> class RuntimeClass;
```
  
#### <a name="parameters"></a>Parâmetros  
 `classFlags`  
Parâmetro opcional. Uma combinação de um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valores de enumeração. O `__WRL_CONFIGURATION_LEGACY__` macro pode ser definida para alterar o valor padrão de classFlags para todas as classes de tempo de execução do projeto. Se definido, RuntimeClass instâncias são não agile por padrão. Quando não estiver definido, RuntimeClass instâncias são agile por padrão. Para evitar ambiguidade sempre especificar Microsoft::WRL::FtmBase em `TInterfaces` ou RuntimeClassType::InhibitFtmBase. Observe que, se InhibitFtmBase e FtmBase são que ambos usados o objeto será agile.
 
 `TInterfaces`  
A lista de interfaces de objeto implementa além IUnknown, IInspectable ou outras interfaces controlados por [RuntimeClassType](../windows/runtimeclasstype-enumeration.md). Ele também pode listar outras classes de derivar de Microsoft::WRL::FtmBase especialmente para tornar o objeto agile e fazer com que ele implementa IMarshal.
  
## <a name="members"></a>Membros  
`RuntimeClassInitialize`Uma função que inicializa o objeto se a função de modelo MakeAndInitialize é usada para construir o objeto. Retorna S_OK se o objeto foi inicializado com êxito, ou um código de erro COM se a falha na inicialização. O código de erro COM é propagado como o valor de retorno de MakeAndInitialize. Observe que o método RuntimeClassInitialize não é chamado se a função de modelo de marca é usada para construir o objeto.

### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor RuntimeClass::RuntimeClass](../windows/runtimeclass-runtimeclass-constructor.md)|Inicializa a instância atual da classe RuntimeClass.|  
|[Destruidor RuntimeClass::~RuntimeClass](../windows/runtimeclass-tilde-runtimeclass-destructor.md)|Deinitializes a instância atual da classe RuntimeClass.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
Este é um detalhe de implementação.
  
## <a name="requirements"></a>Requisitos  
**Cabeçalho:** implements.h  
  
**Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)
