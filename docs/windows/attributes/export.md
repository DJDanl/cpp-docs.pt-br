---
title: exportar (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.export
helpviewer_keywords:
- export attribute
ms.assetid: 70b3e848-fad6-4e09-8c72-be60ca72a4df
ms.openlocfilehash: 771bfdfe4eab2acf31e97a606795066e8938a8a1
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69501610"
---
# <a name="export"></a>export

Faz com que uma estrutura de dados seja colocada no arquivo. idl.

## <a name="syntax"></a>Sintaxe

```cpp
[export]
```

## <a name="remarks"></a>Comentários

O atributo de **exportação** C++ faz com que uma estrutura de dados seja colocada no arquivo. idl e, em seguida, esteja disponível na biblioteca de tipos em um formato compatível com binário que a disponibilize para uso com qualquer linguagem.

Você não pode aplicar o atributo de **exportação** a uma classe, mesmo que a classe tenha apenas membros públicos (o equivalente de uma **struct**).

Se você exportar um **enum** ou **struct**sem nome, ele receberá um nome que começa com **__unnamed**<em>x</em>, em que *x* é um número sequencial.

Os TYPEDEFs válidos para exportação são tipos base, structs, uniões, enums ou identificadores de tipo.  Consulte [typedef](/windows/win32/Midl/typedef) para obter mais informações.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar o atributo de **exportação** :

```cpp
// cpp_attr_ref_export.cpp
// compile with: /LD
[module(name="MyLibrary")];

[export]
struct MyStruct {
   int i;
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**Union**, **typedef**, **enum**, **struct**ou **interface**|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)