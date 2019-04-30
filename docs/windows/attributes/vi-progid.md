---
title: vi_progid (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.vi_progid
helpviewer_keywords:
- vi_progid attribute
ms.assetid: a52449be-b93e-4111-b883-44bb8da53261
ms.openlocfilehash: 7050543c9acf3801a99d3e32e119325900bdb050
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62404761"
---
# <a name="viprogid"></a>vi_progid

Especifica uma forma independente de versão do ProgID.

## <a name="syntax"></a>Sintaxe

```cpp
[ vi_progid(name) ];
```

### <a name="parameters"></a>Parâmetros

*name*<br/>
O ProgID independente de versão que representa o objeto.

ProgIDs apresentar uma versão legível do identificador de classe (CLSID) usado para identificar objetos ActiveX/COM.

## <a name="remarks"></a>Comentários

O **vi_progid** C++ atributo permite que você especifique um ProgID independente de versão para um objeto COM. Um ProgID tem o formato *name1.name2.version*. Um ProgID independente de versão não tem um *versão*. É possível especificar ambos os `progid` e o **vi_progid** atributos em um `coclass`. Se você não especificar **vi_progid**, a versão de ProgID é o valor especificado pela [progid](progid.md) atributo.

**vi_progid** implica a `coclass` do atributo, ou seja, se você especificar **vi_progid**, é a mesma coisa que especificando a `coclass` e **vi_progid** atributos.

O **vi_progid** atributo faz com que uma classe a ser registrado automaticamente no nome especificado. O arquivo. idl gerado não exibirá o valor de ProgID.

Em projetos ATL, se o [coclass](coclass.md) atributo também estiver presente, o ProgID especificado é usado pelo `GetVersionIndependentProgID` função (inserido pelo `coclass` atributo).

## <a name="example"></a>Exemplo

Consulte a [coclass](coclass.md) exemplo para uso do exemplo **vi_progid**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**class**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Chave progID](/windows/desktop/com/-progid--key)
