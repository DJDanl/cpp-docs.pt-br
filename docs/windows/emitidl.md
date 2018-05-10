---
title: emitidl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.emitidl
dev_langs:
- C++
helpviewer_keywords:
- emitidl attribute
ms.assetid: 85b80c56-578e-4392-ac03-8443c74ebb7d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e4c66ba8c49a405f9fdd93b1652626ab47488a53
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="emitidl"></a>emitidl
Especifica se todos os atributos IDL subsequentes são processados e colocados no arquivo. idl gerado.  
  
## <a name="syntax"></a>Sintaxe  
  
```
[ emitidl(state, defaultimports=boolean) ];
```  
  
### <a name="parameters"></a>Parâmetros  
*state*  
Um desses valores possíveis: **true**, **false**, **forçado**, **restrito**, **push**, ou **pop**.  
  
-   Se **true**, os atributos de categoria IDL encontrados em um arquivo de código de origem são colocados no arquivo. idl gerado. Essa é a configuração padrão para **emitidl**.  
  
-   Se **false**, os atributos de categoria IDL encontrados em um arquivo de código fonte não são colocados no arquivo. idl gerado.  
  
-   Se **restrito**, permite que os atributos IDL estar em um arquivo sem uma [módulo](../windows/module-cpp.md) atributo. O compilador não gera um arquivo. idl.  
  
-   Se **forçado**, substitui um subsequentes **restrito** atributo, que requer um arquivo com um **módulo** atributo se houver IDL atributos no arquivo.  
  
-   **push** permite que você salve atual **emitidl** configurações interno **emitidl** pilha, e **pop** permite que você defina **emitidl**para qualquer valor que está no topo da interno **emitidl** pilha.  
  
`defaultimports=`*Boolean* \(opcional)  
-   Se *booliano* é **true**, docobj.idl é importado para o arquivo. idl gerado. Além disso, se um arquivo. idl com o mesmo nome que um. h do arquivo que você `#include` em sua fonte de código está localizado no mesmo diretório que o arquivo. h, então, o arquivo. idl gerado contém uma instrução de importação do arquivo. idl.  
  
-   Se *booliano* é **false**, docobj.idl não será importado para o arquivo. idl gerado. Explicitamente, você deve importar arquivos. idl com [importar](../windows/import.md).  
  
## <a name="remarks"></a>Comentários  
Após o **emitidl** atributo C++ é encontrado em um arquivo de código fonte, atributos de categoria IDL são colocados no arquivo. idl gerado. Se não houver nenhum **emitidl** atributo, atributos IDL no arquivo de código de origem são passados para o arquivo. idl gerado.  
  
É possível ter vários **emitidl** atributos em um arquivo de código fonte. Se `[emitidl(false)];` é encontrado em um arquivo sem um subsequentes `[emitidl(true)];`, em seguida, nenhum atributo é processado no arquivo. idl gerado.  
  
Cada vez que o compilador encontra um novo arquivo, **emitidl** é definido implicitamente como **true**.  
  
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
[Atributos de compilador](../windows/compiler-attributes.md)   
[Atributos autônomos](../windows/stand-alone-attributes.md)   
[Exemplos de atributos](http://msdn.microsoft.com/en-us/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)