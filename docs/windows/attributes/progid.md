---
title: ProgID (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.progid
helpviewer_keywords:
- progid attribute
ms.assetid: afcf559c-e432-481f-aa9a-bd3bb72c02a8
ms.openlocfilehash: d529d7362dc62207cfd72576159f560a3e04c221
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514241"
---
# <a name="progid"></a>progid

Especifica o ProgID de um objeto COM.

## <a name="syntax"></a>Sintaxe

```cpp
[ progid(name) ];
```

### <a name="parameters"></a>Parâmetros

*name*<br/>
O ProgID que representa o objeto.

Os ProgIDs apresentam uma versão legível do identificador de classe (CLSID) usada para identificar objetos COM/ActiveX.

## <a name="remarks"></a>Comentários

O atributo **ProgID** C++ permite especificar o ProgID para um objeto com. Um ProgID tem a forma *nome1. nome2. Version*. Se você não especificar uma *versão* para um ProgID, a versão padrão será 1. Se você não especificar *nome1. nome2*, o nome padrão será *ClassName. ClassName*. Se você não especificar **ProgID** e especificar `vi_progid`, *nome1. nome2* serão tirados de `vi_progid` e a versão (próximo número sequencial) será anexada.

Se um bloco de atributo que usa **ProgID** também não usar **UUID**, o compilador verificará o registro para ver se existe um **UUID** para o **ProgID**especificado. Se **ProgID** não for especificado, a versão (e o nome da coclasse, se criar uma coclass) serão usadas para gerar um **ProgID**.

**ProgID** implica o `coclass` atributo, ou seja, se você especificar **ProgID**, será a mesma coisa que especificar os `coclass` atributos e **ProgID** .

O atributo **ProgID** faz com que uma classe seja automaticamente registrada sob o nome especificado. O arquivo. idl gerado não exibirá o valor de **ProgID** .

Quando esse atributo é usado em um projeto que usa ATL, o comportamento do atributo é alterado. Além do comportamento acima, as informações especificadas com esse atributo são usadas na `GetProgID` função, injetada `coclass` pelo atributo. Para obter mais informações, consulte o atributo [coclass](coclass.md) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [coclass](coclass.md) para obter um exemplo de uso de **ProgID**.

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
[Atributos de classe](class-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Chave de ProgID](/windows/win32/com/-progid--key)
