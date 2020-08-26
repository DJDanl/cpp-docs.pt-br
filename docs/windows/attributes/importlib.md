---
title: importlib (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.importlib
helpviewer_keywords:
- importlib attribute
ms.assetid: f129e459-b8d3-4aca-a0bc-ee53e18b62ed
ms.openlocfilehash: 004533282ca089a076df6b110d52701abc16f71d
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842215"
---
# <a name="importlib"></a>importlib

Torna os tipos que já foram compilados em outra biblioteca de tipos disponíveis para a biblioteca de tipos que está sendo criada.

## <a name="syntax"></a>Sintaxe

```cpp
[ importlib("tlb_file") ];
```

### <a name="parameters"></a>parâmetros

*tlb_file*<br/>
O nome de um arquivo. tlb, entre aspas, que você deseja importar para a biblioteca de tipos do projeto atual.

## <a name="remarks"></a>Comentários

O atributo **importlib** C++ faz com que uma `importlib` instrução seja colocada no bloco de biblioteca do arquivo. idl gerado. O atributo **importlib** tem a mesma funcionalidade que o atributo MIDL [importlib](/windows/win32/Midl/importlib) .

## <a name="example"></a>Exemplo

O código a seguir mostra um exemplo de como usar **importlib**:

```cpp
// cpp_attr_ref_importlib.cpp
// compile with: /LD
[module(name="MyLib")];
[importlib("importlib.tlb")];
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos do compilador](compiler-attributes.md)<br/>
[Atributos autônomos](stand-alone-attributes.md)<br/>
[import](import.md)<br/>
[importidl](importidl.md)<br/>
[incluir](include-cpp.md)<br/>
[includelib](includelib-cpp.md)
