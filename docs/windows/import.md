---
title: Importar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.import
dev_langs:
- C++
helpviewer_keywords:
- import attribute
ms.assetid: ebf07cae-39fb-4047-8b57-54af0a9a83de
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f0b7498ce36243d2f7a7014b8fa9041a1a7378d2
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39604701"
---
# <a name="import"></a>import
Especifica outro arquivo. idl, odl ou cabeçalho que contém definições que você deseja referenciar de IDL seu principal.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[ import(  
   idl_file  
) ];  
```  
  
### <a name="parameters"></a>Parâmetros  
 *idl_file*  
 O nome de um arquivo. IDL que você deseja importado para a biblioteca de tipos do projeto atual.  
  
## <a name="remarks"></a>Comentários  
 O **importe** C++ atributo faz com que um `#import` instrução a ser colocado abaixo o `import "docobj.idl"` instrução no arquivo. idl gerado. O **importação** atributo tem a mesma funcionalidade que o [importar](http://msdn.microsoft.com/library/windows/desktop/aa367047) atributo MIDL.  
  
 O **importação** atributo apenas coloca o arquivo especificado no arquivo. IDL que será gerado pelo seu projeto; o **importar** atributo não permite que você chame construções no arquivo especificado no código-fonte em seu projeto.  Para chamar construtores no arquivo especificado do código-fonte em seu projeto, use [#import](../preprocessor/hash-import-directive-cpp.md) e o `embedded_idl` atributo, ou você pode incluir o arquivo. h para o *idl_file*, se existir um arquivo. h.  
  
## <a name="example"></a>Exemplo  
 O código a seguir:  
  
```cpp  
// cpp_attr_ref_import.cpp  
// compile with: /LD  
[module(name="MyLib")];  
[import(import.idl)];  
```  
  
 produz o seguinte código no arquivo. idl gerado:  
  
```  
import "docobj.idl";  
import "import.idl";  
  
[ uuid(EED3644C-8488-3ECD-BA97-147DB3CDB499), version(1.0) ]  
library MyLib {  
   importlib("stdole2.tlb");  
   importlib("olepro32.dll");  
...  
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
 [importidl](../windows/importidl.md)   
 [importlib](../windows/importlib.md)   
 [Incluir](../windows/include-cpp.md)   
 [includelib](../windows/includelib-cpp.md)   