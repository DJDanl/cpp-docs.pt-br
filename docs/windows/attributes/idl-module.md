---
title: idl_module (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.idl_module
helpviewer_keywords:
- idl_module attribute
ms.assetid: 3578b337-e38a-4334-b747-15404c02dbc0
ms.openlocfilehash: 6dd0a34d5d957838613bde2c9e05d5ef26a1f678
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168038"
---
# <a name="idl_module"></a>idl_module

Especifica um ponto de entrada em um arquivo. dll.

## <a name="syntax"></a>Sintaxe

```cpp
[ idl_module (name=module_name, dllname=dll, uuid="uuid", helpstring="help text", helpstringcontext=helpcontextID, helpcontext=helpcontext, hidden, restricted) ]
function declaration
```

### <a name="parameters"></a>parâmetros

*name*<br/>
Um nome definido pelo usuário para o bloco de código que será exibido no arquivo. idl.

*nomedadll*<br/>
Adicional O arquivo. dll que contém a exportação.

*uuid*<br/>
Adicional Uma ID exclusiva.

*helpstring*<br/>
Adicional Uma cadeia de caracteres usada para descrever a biblioteca de tipos.

*helpstringcontext*<br/>
Adicional A ID de um tópico da ajuda em um arquivo. hlp ou. chm.

*helpcontext*<br/>
Adicional A ID da ajuda para esta biblioteca de tipos.

*hidden*<br/>
Adicional Um parâmetro que impede a exibição da biblioteca. Consulte o atributo MIDL [oculto](/windows/win32/Midl/hidden) para obter mais informações.

*restricted*<br/>
Adicional Os membros da biblioteca não podem ser chamados arbitrariamente. Consulte o atributo MIDL [restrito](/windows/win32/Midl/restricted) para obter mais informações.

*declaração de função*<br/>
A função que você definirá.

## <a name="remarks"></a>Comentários

O atributo **idl_module** C++ permite que você especifique o ponto de entrada em um arquivo. dll, que permite que você importe de um arquivo. dll.

O atributo **idl_module** tem funcionalidade semelhante ao atributo MIDL do [módulo](/windows/win32/Midl/module) .

Você pode exportar qualquer coisa de um objeto COM que pode ser exportado de um arquivo. dll colocando um ponto de entrada de DLL no bloco de biblioteca de um arquivo. idl.

Você deve usar **idl_module** em duas etapas. Primeiro, você deve definir um par nome/DLL. Em seguida, quando você usar **idl_module** para especificar um ponto de entrada, especifique o nome e quaisquer atributos adicionais.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar o atributo **idl_module** :

```cpp
// cpp_attr_ref_idl_module.cpp
// compile with: /LD
[idl_quote("midl_pragma warning(disable:2461)")];
[module(name="MyLibrary"), idl_module(name="MyLib", dllname="xxx.dll")];
[idl_module(name="MyLib"), entry(4), usesgetlasterror]
void FuncName(int i);
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Lugares|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)<br/>
[entry](entry.md)
