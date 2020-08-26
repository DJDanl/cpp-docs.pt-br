---
title: ProgID (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.progid
helpviewer_keywords:
- progid attribute
ms.assetid: afcf559c-e432-481f-aa9a-bd3bb72c02a8
ms.openlocfilehash: 136c651ec92c78339c2f701804a6a409523dd30f
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839992"
---
# <a name="progid"></a>progid

Especifica o ProgID de um objeto COM.

## <a name="syntax"></a>Sintaxe

```cpp
[ progid(name) ];
```

### <a name="parameters"></a>parâmetros

*name*<br/>
O ProgID que representa o objeto.

Os ProgIDs apresentam uma versão legível do identificador de classe (CLSID) usada para identificar objetos COM/ActiveX.

## <a name="remarks"></a>Comentários

O `progid` atributo C++ permite especificar o ProgID para um objeto com. Um ProgID tem a forma *nome1. nome2. Version*. Se você não especificar uma *versão* para um ProgID, a versão padrão será 1. Se você não especificar *nome1. nome2*, o nome padrão será *ClassName. ClassName*. Se você não especificar `progid` e especificar `vi_progid` , *nome1. nome2* serão obtidos `vi_progid` e a versão (próximo número sequencial) for anexada.

Se um bloco de atributos que `progid` o usa também não usar `uuid` , o compilador verificará o registro para ver se `uuid` existe um para o especificado `progid` . Se `progid` não for especificado, a versão (e o nome da coclasse, se criar uma coclass) serão usadas para gerar um `progid` .

`progid` implica o `coclass` atributo, ou seja, se você especificar `progid` , será a mesma coisa que especificar os `coclass` atributos e `progid` .

O `progid` atributo faz com que uma classe seja automaticamente registrada sob o nome especificado. O arquivo. idl gerado não exibirá o `progid` valor.

Quando esse atributo é usado em um projeto que usa ATL, o comportamento do atributo é alterado. Além do comportamento acima, as informações especificadas com esse atributo são usadas na `GetProgID` função, injetada pelo `coclass` atributo. Para obter mais informações, consulte o atributo [coclass](coclass.md) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [coclass](coclass.md) para obter um exemplo de uso de `progid` .

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|`class`, `struct`|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Chave de ProgID](/windows/win32/com/-progid--key)
