---
title: vi_progid (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.vi_progid
helpviewer_keywords:
- vi_progid attribute
ms.assetid: a52449be-b93e-4111-b883-44bb8da53261
ms.openlocfilehash: b27a9a2f5a05535bd11b8091059e5be277b9692c
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832913"
---
# <a name="vi_progid"></a>vi_progid

Especifica uma forma independente de versão do ProgID.

## <a name="syntax"></a>Sintaxe

```cpp
[ vi_progid(name) ];
```

### <a name="parameters"></a>parâmetros

*name*<br/>
O ProgID independente de versão que representa o objeto.

Os ProgIDs apresentam uma versão legível do identificador de classe (CLSID) usada para identificar objetos COM/ActiveX.

## <a name="remarks"></a>Comentários

O atributo **vi_progid** C++ permite especificar um ProgID independente de versão para um objeto com. Um ProgID tem a forma *nome1. nome2. Version*. Um ProgID independente de versão não tem uma *versão*. É possível especificar o `progid` e os atributos de **vi_progid** em um `coclass` . Se você não especificar **vi_progid**, o ProgID independente de versão será o valor especificado pelo atributo [ProgID](progid.md) .

**vi_progid** implica o `coclass` atributo, ou seja, se você especificar **vi_progid**, será a mesma coisa que especificar os `coclass` atributos e **vi_progid** .

O atributo **vi_progid** faz com que uma classe seja automaticamente registrada sob o nome especificado. O arquivo. idl gerado não exibirá o valor de ProgID.

Em projetos ATL, se o atributo [coclass](coclass.md) também estiver presente, o ProgID especificado será usado pela `GetVersionIndependentProgID` função (inserida pelo `coclass` atributo).

## <a name="example"></a>Exemplo

Consulte o exemplo [coclass](coclass.md) para obter um exemplo de uso de **vi_progid**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`**, **`struct`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Chave de ProgID](/windows/win32/com/-progid--key)
