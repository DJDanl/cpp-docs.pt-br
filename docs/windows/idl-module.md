---
title: idl_module | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.idl_module
dev_langs: C++
helpviewer_keywords: idl_module attribute
ms.assetid: 3578b337-e38a-4334-b747-15404c02dbc0
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f052692686149b247a50c0d89e77797f4f48fab3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
  
#### <a name="parameters"></a>Parâmetros  
 **name**  
 Um nome definido pelo usuário para o bloco de código que será exibido no arquivo. idl.  
  
 **nomedadll** (opcional)  
 O arquivo. dll que contém a exportação.  
  
 `uuid` (opcional)  
 Uma ID exclusiva.  
  
 **HelpString** (opcional)  
 Uma cadeia de caracteres usada para descrever a biblioteca de tipos.  
  
 **helpstringcontext** (opcional)  
 A ID de um tópico da Ajuda em um arquivo. hlp ou. chm.  
  
 **HelpContext** (opcional)  
 A identificação de ajuda para esta biblioteca de tipos.  
  
 **oculta** (opcional)  
 Um parâmetro que impede que a biblioteca que está sendo exibido. Consulte o [oculta](http://msdn.microsoft.com/library/windows/desktop/aa366861) atributo MIDL para obter mais informações.  
  
 ***restrito*** (opcional)  
 Membros da biblioteca não podem ser chamados arbitrariamente. Consulte o [restrito](http://msdn.microsoft.com/library/windows/desktop/aa367157) atributo MIDL para obter mais informações.  
  
 *declaração de função*  
 A função que você define.  
  
## <a name="remarks"></a>Comentários  
 O `idl_module` atributo C++ permite que você especifique o ponto de entrada em um arquivo. dll, que permite que você importar de um arquivo. dll.  
  
 O **idl_module** atributo tem funcionalidade semelhante para o [módulo](http://msdn.microsoft.com/library/windows/desktop/aa367099) atributo MIDL.  
  
 Você pode exportar tudo de um objeto COM que você pode exportar de um arquivo. dll, colocando um ponto de entrada da DLL no bloco de biblioteca de um arquivo. idl.  
  
 O deve usar `idl_module` em duas etapas. Primeiro, você deve definir um par nome/DLL. Em seguida, quando você usa `idl_module` para especificar um ponto de entrada, especifique o nome e os atributos adicionais.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como usar o `idl_module` atributo:  
  
```  
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
|**Aplica-se a**|Em qualquer lugar|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos autônomos](../windows/stand-alone-attributes.md)   
 [entry](../windows/entry.md)   
