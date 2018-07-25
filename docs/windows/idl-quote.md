---
title: idl_quote | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.idl_quote
dev_langs:
- C++
helpviewer_keywords:
- idl_quote attribute
ms.assetid: a370e1b7-948b-4e67-9a25-58facf24e4c9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a8844a4770d0a4746c9d9de32a593d0770dcc9a9
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33878506"
---
# <a name="idlquote"></a>idl_quote
Permite que você use as construções de IDL não tem suporte na versão atual do Visual C++ e que eles passam para o arquivo. idl gerado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ idl_quote(  
   text  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *text*  
 O nome do atributo que você pretende que o compilador do Visual C++ para passar para o arquivo. idl gerado sem retornar um erro do compilador.  
  
## <a name="remarks"></a>Comentários  
 Se o **idl_quote** atributo C++ é usado como um atributo autônomo (com um ponto e vírgula após o colchete de fechamento), em seguida, *texto* é colocado no arquivo. idl mesclado como está. Se **idl_quote** é usada em um símbolo, *texto* é colocado dentro do bloco de atributo para esse símbolo.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como você pode especificar um atributo sem suporte (usando **em**, que tem suporte) e como definir e usar uma construção de IDL não definido:  
  
```  
// cpp_attr_ref_idl_quote.cpp  
// compile with: /LD  
#include <unknwn.h>  
[module(name="MyLibrary")];  
  
[export]  
struct MYFLOT {  
   int i;  
};  
  
[export]  
struct MYDUB {  
   int i;  
};  
  
[idl_quote("typedef union _S1_TYPE switch (long l1) U1_TYPE { case 1024: \  
struct MYFLOT f1; case 2048: struct MYDUB d2; } S1_TYPE;") ];  
  
typedef struct _S1_TYPE {   
   long l1;   
  
union {   
   MYFLOT f1; MYDUB d2; } U1_TYPE;   
} S1_TYPE;  
  
[uuid("2F5F63F1-16DA-11d2-9E7B-00C04FB926DA"), object]  
__interface IStatic{  
   HRESULT Func1([idl_quote("in")] int i);  
   HRESULT func( S1_TYPE* myStruct );  
};  
```  
  
 Este código faz com que MYFLOT e MYDUB e *texto* entrada será colocado no arquivo. idl gerado. O *nome* parâmetro força *texto* para ser colocado antes de qualquer coisa que faz referência a *nome* no arquivo. idl gerado. O *dependências* parâmetro força as definições de lista de dependência para ser colocado antes de *texto* no arquivo. idl gerado.  
  
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
 [Atributos independentes](../windows/stand-alone-attributes.md)   
