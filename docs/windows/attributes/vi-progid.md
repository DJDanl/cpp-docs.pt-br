---
title: vi_progid (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.vi_progid
helpviewer_keywords:
- vi_progid attribute
ms.assetid: a52449be-b93e-4111-b883-44bb8da53261
ms.openlocfilehash: fbf5ab2bc4263356a1cfcf789865a3f7e286ccd7
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514860"
---
# <a name="vi_progid"></a>vi_progid

Especifica uma forma independente de versão do ProgID.

## <a name="syntax"></a>Sintaxe

```cpp
[ vi_progid(name) ];
```

### <a name="parameters"></a>Parâmetros

*name*<br/>
O ProgID independente de versão que representa o objeto.

Os ProgIDs apresentam uma versão legível do identificador de classe (CLSID) usada para identificar objetos COM/ActiveX.

## <a name="remarks"></a>Comentários

O atributo **vi_progid** C++ permite especificar um ProgID independente de versão para um objeto com. Um ProgID tem a forma *nome1. nome2. Version*. Um ProgID independente de versão não tem uma *versão*. É possível especificar `progid` os atributos e **vi_progid** em um `coclass`. Se você não especificar **vi_progid**, o ProgID independente de versão será o valor especificado pelo atributo [ProgID](progid.md) .

**vi_progid** implica o `coclass` atributo, ou seja, se você especificar **vi_progid**, será a mesma coisa que especificar os `coclass` atributos e **vi_progid** .

O atributo **vi_progid** faz com que uma classe seja automaticamente registrada sob o nome especificado. O arquivo. idl gerado não exibirá o valor de ProgID.

Em projetos ATL, se o atributo [coclass](coclass.md) também estiver presente, o ProgID especificado será usado pela `GetVersionIndependentProgID` função `coclass` (inserida pelo atributo).

## <a name="example"></a>Exemplo

Consulte o exemplo [coclass](coclass.md) para obter um exemplo de uso de **vi_progid**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Chave de ProgID](/windows/win32/com/-progid--key)
