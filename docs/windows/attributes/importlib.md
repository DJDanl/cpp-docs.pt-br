---
title: importlib (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.importlib
helpviewer_keywords:
- importlib attribute
ms.assetid: f129e459-b8d3-4aca-a0bc-ee53e18b62ed
ms.openlocfilehash: d0bedb4bac91aa1a5aa72c8334db07aea0f04a97
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50649872"
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