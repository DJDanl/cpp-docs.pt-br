---
title: importidl (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.importidl
helpviewer_keywords:
- importidl attribute
ms.assetid: 4b0a4b55-6c57-4e6e-bc7b-a12cc8063941
ms.openlocfilehash: 8f3c2c5c67ac216d096d1082814c561698f3f732
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842241"
---
# <a name="importidl"></a>importidl

Insere o arquivo. idl especificado no arquivo. idl gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[ importidl(idl_file) ];
```

### <a name="parameters"></a>parâmetros

*idl_file*<br/>
Identifica o nome do arquivo. idl que você deseja mesclar com o arquivo. idl que será gerado para seu aplicativo.

## <a name="remarks"></a>Comentários

O atributo **importidl** C++ coloca a seção fora do bloco de biblioteca (em *idl_file*) no arquivo. idl gerado do programa e na seção de biblioteca (em *idl_file*) na seção da biblioteca do arquivo. idl gerado do seu programa.

Talvez você queira usar **importidl**, por exemplo, se quiser usar um arquivo. idl codificado manualmente com o arquivo. idl gerado.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_importidl.cpp
// compile with: /LD
[module(name="MyLib")];
[importidl("import.idl")];
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
[importlib](importlib.md)<br/>
[incluir](include-cpp.md)<br/>
[includelib](includelib-cpp.md)
