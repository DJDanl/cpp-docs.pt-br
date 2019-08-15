---
title: importar (C++ atributo com)
ms.date: 10/03/2018
f1_keywords:
- vc-attr.import
helpviewer_keywords:
- import attribute
ms.assetid: ebf07cae-39fb-4047-8b57-54af0a9a83de
ms.openlocfilehash: f9ed80bdcc04302c0dee85935f377c8e3dbfd37f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514627"
---
# <a name="import"></a>import

Especifica outro arquivo. idl,. odl ou de cabeçalho que contém as definições que você deseja referenciar de seu IDL principal.

## <a name="syntax"></a>Sintaxe

```cpp
[ import(
   idl_file
) ];
```

### <a name="parameters"></a>Parâmetros

*idl_file*<br/>
O nome de um arquivo. idl que você deseja importar para a biblioteca de tipos do projeto atual.

## <a name="remarks"></a>Comentários

O atributo de **importação** C++ faz `#import` com que uma instrução seja colocada `import "docobj.idl"` abaixo da instrução no arquivo. idl gerado. O atributo de **importação** tem a mesma funcionalidade que o atributo MIDL de [importação](/windows/win32/Midl/import) .

O atributo de **importação** só coloca o arquivo especificado no arquivo. idl que será gerado pelo seu projeto; o atributo de **importação** não permite que você chame construções no arquivo especificado do código-fonte em seu projeto.  Para chamar construções no arquivo especificado do código-fonte em seu projeto, use [#import](../../preprocessor/hash-import-directive-cpp.md) e o `embedded_idl` atributo ou você pode incluir o arquivo. h para o *idl_file*, se existir um arquivo. h.

## <a name="example"></a>Exemplo

O código a seguir:

```cpp
// cpp_attr_ref_import.cpp
// compile with: /LD
[module(name="MyLib")];
[import(import.idl)];
```

produz o seguinte código no arquivo. idl gerado:

```
import "docobj.idl";
import "import.idl";

[ uuid(EED3644C-8488-3ECD-BA97-147DB3CDB499), version(1.0) ]
library MyLib {
   importlib("stdole2.tlb");
   importlib("olepro32.dll");
...
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Lugares|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)<br/>
[importidl](importidl.md)<br/>
[importlib](importlib.md)<br/>
[include](include-cpp.md)<br/>
[includelib](includelib-cpp.md)