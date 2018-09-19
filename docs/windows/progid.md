---
title: ProgID | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.progid
dev_langs:
- C++
helpviewer_keywords:
- progid attribute
ms.assetid: afcf559c-e432-481f-aa9a-bd3bb72c02a8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 337972b9659ae32e2ea40e12d6301cc1f0c9aba7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46407992"
---
# <a name="progid"></a>progid

Especifica o ProgID de um objeto COM.

## <a name="syntax"></a>Sintaxe

```cpp
[ progid(
   name
) ];
```

### <a name="parameters"></a>Parâmetros

*name*<br/>
O ProgID que representa o objeto.

ProgIDs apresentar uma versão legível do identificador de classe (CLSID) usado para identificar objetos ActiveX/COM.

## <a name="remarks"></a>Comentários

O **progid** atributo C++ permite que você especifique o ProgID de um objeto COM. Um ProgID tem o formato *name1.name2.version*. Se você não especificar uma *versão* para um ProgID, a versão padrão é 1. Se você não especificar *name1.name2*, o nome padrão é *classname.classname*. Se você não especificar **progid** e você especificar `vi_progid`, *name1.name2* são obtidos do `vi_progid` e o (próximo número sequencial) versão é acrescentado.

Se um bloco de atributo que usa **progid** também não usa **uuid**, o compilador verificará o registro para ver se um **uuid** existe para especificado **progid** . Se **progid** não for especificado, a versão (e o nome de coclass, se a criação de uma coclass) serão usados para gerar um **progid**.

**ProgID** implica a `coclass` do atributo, ou seja, se você especificar **progid**, é a mesma coisa que especificando a `coclass` e **progid** atributos.

O **progid** atributo faz com que uma classe a ser registrado automaticamente no nome especificado. O arquivo. idl gerado não exibirão o **progid** valor.

Quando esse atributo é usado dentro de um projeto que usa ATL, altera o comportamento do atributo. Além do comportamento acima, as informações especificadas com esse atributo são usadas na `GetProgID` função, injetada pelo `coclass` atributo. Para obter mais informações, consulte o [coclass](../windows/coclass.md) atributo.

## <a name="example"></a>Exemplo

Veja o exemplo de [coclass](../windows/coclass.md) para uso do exemplo **progid**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos de classe](../windows/class-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)<br/>
[Chave progID](/windows/desktop/com/-progid--key)  
