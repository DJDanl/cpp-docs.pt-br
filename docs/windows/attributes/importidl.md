---
title: importidl (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.importidl
helpviewer_keywords:
- importidl attribute
ms.assetid: 4b0a4b55-6c57-4e6e-bc7b-a12cc8063941
ms.openlocfilehash: 9db62d4f2a36b8cc0592c924b113077a758915c0
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59029908"
---
# <a name="importidl"></a>importidl

Insere o arquivo. idl especificado no arquivo. idl gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[ importidl(idl_file) ];
```

### <a name="parameters"></a>Parâmetros

*idl_file*<br/>
Identifica o nome do arquivo. IDL que você deseja mesclar com o arquivo. IDL que será gerado para o seu aplicativo.

## <a name="remarks"></a>Comentários

O **importidl** C++ atributo coloca a seção fora do bloco de biblioteca (no *idl_file*) no arquivo de IDL gerado do seu programa e a seção da biblioteca (no *idl_file*) na seção de biblioteca do arquivo de IDL gerado do seu programa.

Você talvez queira usar **importidl**, por exemplo, se você quiser usar um arquivo. idl de mão-codificados com seu arquivo. idl gerado.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_importidl.cpp
// compile with: /LD
[module(name="MyLib")];
[importidl("import.idl")];
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
[importlib](importlib.md)<br/>
[include](include-cpp.md)<br/>
[includelib](includelib-cpp.md)