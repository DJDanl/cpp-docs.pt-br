---
title: Classe HString | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString
dev_langs:
- C++
ms.assetid: 6709dd2e-8d72-4675-8ec7-1baa7d71854d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: eea40f989e7d41afbff2773fcc5e6e5b2cfbafd2
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42613647"
---
# <a name="hstring-class"></a>Classe HString

Uma classe auxiliar para gerenciar o tempo de vida de um HSTRING usando o padrão RAII.

## <a name="syntax"></a>Sintaxe

```cpp
class HString;
```

## <a name="remarks"></a>Comentários

O tempo de execução do Windows fornece acesso às cadeias de caracteres através das alças HSTRING. O **HString** classe fornece funções de conveniência e operadores para simplificar o uso de identificadores de HSTRING. Essa classe pode manipular o tempo de vida do HSTRING ela detém por meio de um padrão RAII.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor HString::HString](../windows/hstring-hstring-constructor.md)|Inicializa uma nova instância dos **HString** classe.|
|[Destruidor HString::~HString](../windows/hstring-tilde-hstring-destructor.md)|Destrói a instância atual do **HString** classe.|

### <a name="members"></a>Membros

|Nome|Descrição|
|----------|-----------------|
|[Método HString::Set](../windows/hstring-set-method.md)|Define o valor do atual **HString** objeto de cadeia de caracteres largos especificada ou **HString** parâmetro.|
|[Método HString::Attach](../windows/hstring-attach-method.md)|Associa a especificada **HString** objeto com o atual **HString** objeto.|
|[Método HString::CopyTo](../windows/hstring-copyto-method.md)|Copia o atual **HString** objeto para um objeto HSTRING.|
|[Método HString::Detach](../windows/hstring-detach-method.md)|Desassocia especificado **HString** objeto do valor subjacente.|
|[Método HString::GetAddressOf](../windows/hstring-getaddressof-method.md)|Recupera um ponteiro para o identificador subjacente de HSTRING.|
|[Método HString::Get](../windows/hstring-get-method.md)|Recupera o valor do identificador subjacente de HSTRING.|
|[Método HString::Release](../windows/hstring-release-method.md)|Exclui o valor de cadeia de caracteres subjacente e inicializa o atual **HString** objeto para um valor vazio.|
|[Método HString::MakeReference](../windows/hstring-makereference-method.md)|Cria um `HStringReference` objeto a partir de um parâmetro de cadeia de caracteres especificada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador HString::Operator=](../windows/hstring-operator-assign-operator.md)|Move o valor de outro **HString** objeto atual **HString** objeto.|
|[Operador HString::Operator==](../windows/hstring-operator-equality-operator.md)|Indica se os dois parâmetros são iguais.|
|[Operador HString::Operator!=](../windows/hstring-operator-inequality-operator.md)|Indica se os dois parâmetros não são iguais.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`HString`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)