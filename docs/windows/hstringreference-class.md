---
title: Classe HStringReference | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HStringReference
dev_langs:
- C++
ms.assetid: 9bf823b1-17eb-4ac4-8c5d-27d27c7a4150
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: de3c7fe60432acfc3096ea19fc00cf371a7c4e92
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42610500"
---
# <a name="hstringreference-class"></a>Classe HStringReference

Representa um HSTRING que é criado a partir de uma cadeia de caracteres existente.

## <a name="syntax"></a>Sintaxe

```cpp
class HStringReference;
```

## <a name="remarks"></a>Comentários

O tempo de vida do buffer de backup no novo HSTRING não é gerenciado pelo tempo de execução do Windows. O chamador aloca uma cadeia de caracteres de origem no quadro da pilha para evitar uma alocação de heap e eliminar o risco de perda de memória. Além disso, o chamador deve garantir que a cadeia de caracteres de origem permaneça inalterada durante a vida útil do HSTRING anexado. Para obter mais informações, consulte [WindowsCreateStringReference função](http://msdn.microsoft.com/0361bb7e-da49-4289-a93e-de7aab8712ac).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor HStringReference::HStringReference](../windows/hstringreference-hstringreference-constructor.md)|Inicializa uma nova instância dos **HStringReference** classe.|

### <a name="members"></a>Membros

|Membro|Descrição|
|------------|-----------------|
|[Método HStringReference::CopyTo](../windows/hstringreference-copyto-method.md)|Copia o atual **HStringReference** objeto para um objeto HSTRING.|
|[Método HStringReference::Get](../windows/hstringreference-get-method.md)|Recupera o valor do identificador subjacente de HSTRING.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador HStringReference::Operator=](../windows/hstringreference-operator-assign-operator.md)|Move o valor de outro **HStringReference** objeto atual **HStringReference** objeto.|
|[Operador HStringReference::Operator==](../windows/hstringreference-operator-equality-operator.md)|Indica se os dois parâmetros são iguais.|
|[Operador HStringReference::Operator!=](../windows/hstringreference-operator-inequality-operator.md)|Indica se os dois parâmetros não são iguais.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HStringReference`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)