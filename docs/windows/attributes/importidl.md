---
title: importidl (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.importidl
dev_langs:
- C++
helpviewer_keywords:
- importidl attribute
ms.assetid: 4b0a4b55-6c57-4e6e-bc7b-a12cc8063941
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d1c022a48ef5510f67355af3af1ff0a0e98ad4c4
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790113"
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

O **importidl** atributo C++ coloca a seção fora do bloco de biblioteca (no *idl_file*) no arquivo de IDL gerado do seu programa e a seção da biblioteca (em *idl_file*) para a biblioteca de seção do seu programa gerado o arquivo. idl.

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