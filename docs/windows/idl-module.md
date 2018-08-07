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
ms.openlocfilehash: bfda47ced14d7c112d27d0036b4d636e32c91907
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39607554"
---
# <a name="idlmodule"></a>idl_module
Especifica um ponto de entrada em um arquivo. dll.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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
 Um parâmetro que impede que a biblioteca que está sendo exibido. Consulte a [ocultos](http://msdn.microsoft.com/library/windows/desktop/aa366861) atributo MIDL para obter mais informações.  
  
 *restrito* (opcional)  
 Membros da biblioteca não podem ser chamados arbitrariamente. Consulte a [restrito](http://msdn.microsoft.com/library/windows/desktop/aa367157) atributo MIDL para obter mais informações.  
  
 *declaração de função*  
 A função que serão definidos.  
  
## <a name="remarks"></a>Comentários  
 O **idl_module** atributo C++ permite que você especifique o ponto de entrada em um arquivo. dll, que lhe permite importar de um arquivo. dll.  
  
 O **idl_module** atributo tem uma funcionalidade semelhante para o [módulo](http://msdn.microsoft.com/library/windows/desktop/aa367099) atributo MIDL.  
  
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
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos autônomos](../windows/stand-alone-attributes.md)   
 [entry](../windows/entry.md)   