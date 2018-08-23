---
title: vi_progid | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.vi_progid
dev_langs:
- C++
helpviewer_keywords:
- vi_progid attribute
ms.assetid: a52449be-b93e-4111-b883-44bb8da53261
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d5848581b26812f322782a73d8964deee1feefb9
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42606968"
---
# <a name="viprogid"></a>vi_progid

Especifica uma forma independente de versão do ProgID.

## <a name="syntax"></a>Sintaxe

```cpp
[ vi_progid(
   name
) ];
```

### <a name="parameters"></a>Parâmetros

*name*  
O ProgID independente de versão que representa o objeto.

ProgIDs apresentar uma versão legível do identificador de classe (CLSID) usado para identificar objetos ActiveX/COM.

## <a name="remarks"></a>Comentários

O **vi_progid** atributo C++ permite que você especifique um ProgID independente de versão para um objeto COM. Um ProgID tem o formato *name1.name2.version*. Um ProgID independente de versão não tem um *versão*. É possível especificar ambos os `progid` e o **vi_progid** atributos em um `coclass`. Se você não especificar **vi_progid**, a versão de ProgID é o valor especificado pela [progid](../windows/progid.md) atributo.

**vi_progid** implica a `coclass` do atributo, ou seja, se você especificar **vi_progid**, é a mesma coisa que especificando a `coclass` e **vi_progid** atributos.

O **vi_progid** atributo faz com que uma classe a ser registrado automaticamente no nome especificado. O arquivo. idl gerado não exibirá o valor de ProgID.

Em projetos ATL, se o [coclass](../windows/coclass.md) atributo também estiver presente, o ProgID especificado é usado pelo `GetVersionIndependentProgID` função (inserido pelo `coclass` atributo).

## <a name="example"></a>Exemplo

Consulte a [coclass](../windows/coclass.md) exemplo para uso do exemplo **vi_progid**.

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

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)  
[Atributos de classe](../windows/class-attributes.md)  
[Chave progID](http://msdn.microsoft.com/library/windows/desktop/dd542719)  
