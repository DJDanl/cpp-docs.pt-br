---
title: importidl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 9406cc95804e4eb9fd76f53201118f13f0e422a4
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46410501"
---
# <a name="importidl"></a>importidl

Insere o arquivo. idl especificado no arquivo. idl gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[ importidl(
   idl_file
) ];
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

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](../windows/compiler-attributes.md)<br/>
[Atributos independentes](../windows/stand-alone-attributes.md)<br/>
[import](../windows/import.md)<br/>
[importlib](../windows/importlib.md)<br/>
[include](../windows/include-cpp.md)<br/>
[includelib](../windows/includelib-cpp.md)  