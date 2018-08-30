---
title: idl_module | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.idl_module
dev_langs:
- C++
helpviewer_keywords:
- idl_module attribute
ms.assetid: 3578b337-e38a-4334-b747-15404c02dbc0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9fc3be9fb25b6593f4b69f846394544b7b7d756a
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43220459"
---
# <a name="idlmodule"></a>idl_module

Especifica um ponto de entrada em um arquivo. dll.

## <a name="syntax"></a>Sintaxe

```cpp
[ idl_module (
   name=module_name,
   dllname=dll,
   uuid="uuid",
   helpstring="help text",
   helpstringcontext=helpcontextID,
   helpcontext=helpcontext,
   hidden,
   restricted
) ]
function declaration
```

### <a name="parameters"></a>Parâmetros

*name*  
Um nome definido pelo usuário para o bloco de código que será exibida no arquivo. idl.

*dllname* (opcional)  
O arquivo. dll que contém a exportação.

*UUID* (opcional)  
Uma ID exclusiva.

*HelpString* (opcional)  
Uma cadeia de caracteres usada para descrever a biblioteca de tipos.

*helpstringcontext* (opcional)  
A ID do tópico da Ajuda em um arquivo. hlp ou. chm.

*HelpContext* (opcional)  
A identificação de ajuda para esta biblioteca de tipos.

*oculto* (opcional)  
Um parâmetro que impede que a biblioteca que está sendo exibido. Consulte a [ocultos](/windows/desktop/Midl/hidden) atributo MIDL para obter mais informações.

*restrito* (opcional)  
Membros da biblioteca não podem ser chamados arbitrariamente. Consulte a [restrito](/windows/desktop/Midl/restricted) atributo MIDL para obter mais informações.

*declaração de função*  
A função que serão definidos.

## <a name="remarks"></a>Comentários

O **idl_module** atributo C++ permite que você especifique o ponto de entrada em um arquivo. dll, que lhe permite importar de um arquivo. dll.

O **idl_module** atributo tem uma funcionalidade semelhante para o [módulo](/windows/desktop/Midl/module) atributo MIDL.

Você pode exportar qualquer coisa de um objeto COM que você pode exportar de um arquivo. dll, colocando um ponto de entrada da DLL no bloco de biblioteca de um arquivo. idl.

O deve usar **idl_module** em duas etapas. Primeiro, você deve definir um par nome/DLL. Em seguida, quando você usa **idl_module** para especificar um ponto de entrada, especifique o nome e os atributos adicionais.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar o **idl_module** atributo:

```cpp
// cpp_attr_ref_idl_module.cpp
// compile with: /LD
[idl_quote("midl_pragma warning(disable:2461)")];
[module(name="MyLibrary"), idl_module(name="MyLib", dllname="xxx.dll")];
[idl_module(name="MyLib"), entry(4), usesgetlasterror]
void FuncName(int i);
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Em qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos independentes](../windows/stand-alone-attributes.md)  
[entry](../windows/entry.md)  