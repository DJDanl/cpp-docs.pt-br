---
title: exportar (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.export
helpviewer_keywords:
- export attribute
ms.assetid: 70b3e848-fad6-4e09-8c72-be60ca72a4df
ms.openlocfilehash: 4854789d9f977b3b747fd9b546cb92642942be88
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845270"
---
# <a name="export"></a>exportar

Faz com que uma estrutura de dados seja colocada no arquivo. idl.

## <a name="syntax"></a>Sintaxe

```cpp
[export]
```

## <a name="remarks"></a>Comentários

O **`[export]`** atributo C++ faz com que uma estrutura de dados seja colocada no arquivo. idl e, em seguida, esteja disponível na biblioteca de tipos em um formato compatível com binário que a disponibilize para uso com qualquer linguagem.

Você não pode aplicar o **`[export]`** atributo a uma classe, mesmo que a classe tenha apenas membros públicos (o equivalente a um **`struct`** ).

Se você exportar um **`enum`** não nomeado ou **`struct`** , ele receberá um nome que começa com **__unnamed**<em>x</em>, em que *x* é um número sequencial.

Os TYPEDEFs válidos para exportação são tipos base, structs, uniões, enums ou identificadores de tipo.  Consulte [`typedef`](/windows/win32/Midl/typedef) para obter mais informações.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar o **`[export]`** atributo:

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

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`union`**, **`typedef`** , **`enum`** , **`struct`** ou **`interface`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos do compilador](compiler-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)
