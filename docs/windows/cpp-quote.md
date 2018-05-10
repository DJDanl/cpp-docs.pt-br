---
title: cpp_quote | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.cpp_quote
dev_langs:
- C++
helpviewer_keywords:
- cpp_quote attribute
ms.assetid: f75327ff-42bd-498b-9177-7ffa25427e1f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 38ecabcde55f49687abf7caff66fb2c316fab0fe
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="cppquote"></a>cpp_quote
Emite a cadeia de caracteres especificada, sem o caractere de aspas, no arquivo. idl gerado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ cpp_quote(  
   "statement"  
) ];  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *statement*  
 Uma instrução de C.  
  
## <a name="remarks"></a>Comentários  
 O **cpp_quote** atributo C++ é útil se você quiser colocar uma diretiva de pré-processador em um arquivo. idl.  
  
 Você também pode usar **cpp_quote** e gerar um arquivo. h como parte da compilação de MIDL. Por exemplo, se você tiver um arquivo de cabeçalho do C++ que usa atributos IDL C++, mas não é possível usar esse arquivo para uma tarefa, em seguida, poderá compilá-lo para criar um arquivo gerado pelo MIDL h, que deve ser capaz de usar.  
  
 O **cpp_quote** atributo tem a mesma funcionalidade que o [cpp_quote](http://msdn.microsoft.com/library/windows/desktop/aa366765) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [dual](../windows/dual.md) para obter um exemplo usar como usar **cpp_quote**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Em qualquer lugar|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos independentes](../windows/stand-alone-attributes.md)   
