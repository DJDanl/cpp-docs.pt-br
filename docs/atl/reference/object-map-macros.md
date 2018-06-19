---
title: Macros de mapa do objeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlcom/ATL::DECLARE_OBJECT_DESCRIPTION
- atlcom/ATL::OBJECT_ENTRY_AUTO
- atlcom/ATL::OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO
dev_langs:
- C++
ms.assetid: 680087f4-9894-41dd-a79c-6f337e1f13c1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 671fd80bc2c4ad320efb282fd659899756c2ecbc
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32362937"
---
# <a name="object-map-macros"></a>Macros de mapa de objeto
Essas macros definem mapas de objeto e entradas.  
  
|||  
|-|-|  
|[DECLARE_OBJECT_DESCRIPTION](#declare_object_description)|Permite que você especifique a descrição de texto do objeto de classe, que será inserida no mapa de objeto.|  
|[OBJECT_ENTRY_AUTO](#object_entry_auto)|Insere um objeto ATL para o mapa de objeto, atualiza o registro e cria uma instância do objeto.|  
|[OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](#object_entry_non_createable_ex_auto)|Permite que você especifique que o objeto deve ser registrado e inicializado, mas não deve ser instanciável externamente via `CoCreateInstance`.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
   
##  <a name="declare_object_description"></a>  DECLARE_OBJECT_DESCRIPTION  
 Permite que você especifique uma descrição para o objeto de classe.  
  
```
DECLARE_OBJECT_DESCRIPTION( x )
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] Descrição do objeto de classe.  
  
### <a name="remarks"></a>Comentários  
 ATL insere essa descrição para o mapa de objeto por meio de [OBJECT_ENTRY](http://msdn.microsoft.com/en-us/abd10ee2-54f0-4f94-9ec2-ddf8f4c8c8cd) macro.  
  
 `DECLARE_OBJECT_DESCRIPTION` implementa um `GetObjectDescription` função, que você pode usar para substituir o [CComCoClass::GetObjectDescription](ccomcoclass-class.md#getobjectdescription) método.  

  
 O `GetObjectDescription` função é chamada pelo **IComponentRegistrar::GetComponents**. **IComponentRegistrar** é uma interface de automação que permite registrar e cancelar o registro de componentes individuais em uma DLL. Quando você cria um objeto do registrador de componente com o Assistente de projeto de ATL, o assistente automaticamente implementará o **IComponentRegistrar** interface. **IComponentRegistrar** normalmente é usado pelo Microsoft Transaction Server.  
  
 Para obter mais informações sobre o Assistente de projeto de ATL, consulte o artigo [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#123](../../atl/codesnippet/cpp/object-map-macros_1.h)]  
  
##  <a name="object_entry_auto"></a>  OBJECT_ENTRY_AUTO  
 Insere um objeto ATL para o mapa de objeto, atualiza o registro e cria uma instância do objeto.  
  
```
OBJECT_ENTRY_AUTO( clsid, class )
```  
  
### <a name="parameters"></a>Parâmetros  
 `clsid`  
 [in] O CLSID de uma classe COM implementado pela classe C++ chamado `class`.  
  
 `class`  
 [in] O nome da classe C++ Implementando a classe COM representado por `clsid`.  
  
### <a name="remarks"></a>Comentários  
 Macros de entrada do objeto são colocadas no escopo global no projeto para fornecer suporte para o registro, a inicialização e a criação de uma classe.  
  
 `OBJECT_ENTRY_AUTO` Insere os ponteiros de função da classe do criador e classe do criador de fábrica de classes `CreateInstance` funções para este objeto para o mapa de objeto ATL gerado automaticamente. Quando [CAtlComModule::RegisterServer](catlcommodule-class.md#registerserver) é chamado, ele atualiza o registro do sistema para cada objeto no mapa do objeto.  

  
 A tabela a seguir descreve como as informações adicionadas ao mapa do objeto são obtidas da classe fornecida como segundo parâmetro para esta macro.  
  
|Informações de|Obtido|  
|---------------------|-------------------|  
|Registro COM|[Macros de Registro](../../atl/reference/registry-macros.md)|  
|Criação da fábrica de classes|[Macros de fábrica de classe](../../atl/reference/aggregation-and-class-factory-macros.md)|  
|Criação de instância|[Macros de agregação](../../atl/reference/aggregation-and-class-factory-macros.md)|  
|Registro de categoria de componente|[Macros de categoria](../../atl/reference/category-macros.md)|  
|Limpeza e a inicialização de nível de classe|[ObjectMain](ccomobjectrootex-class.md#objectmain)|  

  
##  <a name="object_entry_non_createable_ex_auto"></a>  OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO  
 Permite que você especifique que o objeto deve ser registrado e inicializado, mas não deve ser instanciável externamente via `CoCreateInstance`.  
  
```
OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO( clsid, class )
```  
  
### <a name="parameters"></a>Parâmetros  
 `clsid`  
 [in] O CLSID de uma classe COM implementado pela classe C++ chamado `class`.  
  
 `class`  
 [in] O nome da classe C++ Implementando a classe COM representado por `clsid`.  
  
### <a name="remarks"></a>Comentários  
 Macros de entrada do objeto são colocadas no escopo global no projeto para fornecer suporte para o registro, a inicialização e a criação de uma classe.  
  
 `OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO` permite que você especifique que um objeto deve ser registrado e inicializado (consulte [OBJECT_ENTRY_AUTO](#object_entry_auto) para obter mais informações), mas não deve ser instanciável via `CoCreateInstance`.  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)
