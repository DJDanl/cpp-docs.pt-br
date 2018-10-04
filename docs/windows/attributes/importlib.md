---
title: importlib (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.importlib
dev_langs:
- C++
helpviewer_keywords:
- importlib attribute
ms.assetid: f129e459-b8d3-4aca-a0bc-ee53e18b62ed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: dd43dd8a0fb4660cbe0c631bcb3477ef3d26f0f6
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790267"
---
# <a name="importlib"></a>importlib

Torna os tipos que já foram compilados em outra biblioteca de tipos disponível para a biblioteca de tipos que está sendo criada.

## <a name="syntax"></a>Sintaxe

```cpp
[ importlib("tlb_file") ];
```

### <a name="parameters"></a>Parâmetros

*tlb_file*<br/>
O nome de um arquivo. tlb, entre aspas, o que você deseja importado para a biblioteca de tipos do projeto atual.

## <a name="remarks"></a>Comentários

O **importlib** C++ atributo faz com que um `importlib` instrução a ser colocado no bloco de biblioteca do arquivo. idl gerado. O **importlib** atributo tem a mesma funcionalidade que o [importlib](/windows/desktop/Midl/importlib) atributo MIDL.

## <a name="example"></a>Exemplo

O código a seguir mostra um exemplo de como usar **importlib**:

```cpp
// cpp_attr_ref_importlib.cpp
// compile with: /LD
[module(name="MyLib")];
[importlib("importlib.tlb")];
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Em qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)<br/>
[import](import.md)<br/>
[importidl](importidl.md)<br/>
[include](include-cpp.md)<br/>
[includelib](includelib-cpp.md)