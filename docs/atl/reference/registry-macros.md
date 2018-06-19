---
title: Macros de registro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlcom/ATL::_ATL_STATIC_REGISTRY
- atlcom/ATL::DECLARE_LIBID
- atlcom/ATL::DECLARE_NO_REGISTRY
- atlcom/ATL::DECLARE_REGISTRY
- atlcom/ATL::DECLARE_REGISTRY_APPID_RESOURCEID
- atlcom/ATL::DECLARE_REGISTRY_RESOURCE
- atlcom/ATL::DECLARE_REGISTRY_RESOURCEID
dev_langs:
- C++
helpviewer_keywords:
- registry, ATL macros
ms.assetid: 3ee041da-c63b-42a4-89cf-2a4b2a6f81ae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ed9b172217f1ca7ada7d8752151126b53055df37
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32365210"
---
# <a name="registry-macros"></a>Macros de registro
Essas macros definem recursos de biblioteca e o registro do tipo útil.  
  
|||  
|-|-|  
|[_ATL_STATIC_REGISTRY](#_atl_static_registry)|Indica que você deseja que o código de registro para o objeto no objeto para evitar uma dependência em ATL. DLL.|  
|[DECLARE_LIBID](#declare_libid)|Fornece uma maneira de ATL obter o *libid* da biblioteca de tipos.|  
|[DECLARE_NO_REGISTRY](#declare_no_registry)|Evita o registro ATL do padrão.|  
|[DECLARE_REGISTRY](#declare_registry)|Insere ou remove a entrada do objeto principal no registro do sistema.|  
|[DECLARE_REGISTRY_APPID_RESOURCEID](#declare_registry_appid_resourceid)|Especifica as informações necessárias para se registrar automaticamente o *appid*.|  
|[DECLARE_REGISTRY_RESOURCE](#declare_registry_resource)|Localiza o recurso denominado e executa o script de registro dentro dele.|  
|[DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid)|Localiza o recurso identificado por um número de identificação e executa o script de registro dentro dele.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
    
##  <a name="_atl_static_registry"></a>  _ATL_STATIC_REGISTRY  
 Um símbolo que indica que você deseja que o código de registro para o objeto no objeto para evitar uma dependência em ATL. DLL.  
  
```
#define _ATL_STATIC_REGISTRY
```  
  
### <a name="remarks"></a>Comentários  
 Quando você define **ATL_STATIC_REGISTRY**, você deve usar o código a seguir:  
  
 [!code-cpp[NVC_ATL_EventHandlingSample#5](../../atl/codesnippet/cpp/registry-macros_1.cpp)]  
  
##  <a name="declare_libid"></a>  DECLARE_LIBID  
 Fornece uma maneira de ATL obter o *libid* da biblioteca de tipos.  
  
```
DECLARE_LIBID( libid )
```  
  
### <a name="parameters"></a>Parâmetros  
 *ID da biblioteca*  
 O GUID da biblioteca de tipos.  
  
### <a name="remarks"></a>Comentários  
 Use `DECLARE_LIBID` em um `CAtlModuleT`-classe derivada.  
  
### <a name="example"></a>Exemplo  
 Não atribuído geradas pelo Assistente de projetos ATL terá um exemplo de como usar esta macro.  
  
##  <a name="declare_no_registry"></a>  DECLARE_NO_REGISTRY  
 Use `DECLARE_NO_REGISTRY` se você quiser evitar qualquer registro ATL padrão para a classe na qual esta macro aparece.  
  
```
DECLARE_NO_REGISTRY()
```  
  
##  <a name="declare_registry"></a>  DECLARE_REGISTRY  
 Insere o registro de classe padrão no registro do sistema ou remove-o do registro do sistema.  
  
```
DECLARE_REGISTRY(
    class, 
    pid, 
    vpid, 
    nid, 
    flags )
```  
  
### <a name="parameters"></a>Parâmetros  
 `class`  
 [in] Incluído para compatibilidade com versões anteriores.  
  
 `pid`  
 [in] Um `LPCTSTR` que é um identificador de programa específicos da versão.  
  
 *vpid*  
 [in] Um `LPCTSTR` que é um identificador de programa independente de versão.  
  
 *NID*  
 [in] Um **UINT** que é um índice da cadeia de caracteres de recurso no registro para usar como a descrição do programa.  
  
 `flags`  
 [in] Um `DWORD` que contém o programa de encadeamento do modelo no registro. Deve ser um dos seguintes valores: **THREADFLAGS_APARTMENT**, **THREADFLAGS_BOTH**, ou **AUTPRXFLAG**.  
  
### <a name="remarks"></a>Comentários  
 O registro padrão consiste o CLSID, identificação de programa, ID de programa independente de versão, cadeia de caracteres de descrição e o modelo de thread.  
  
 Quando você cria um objeto ou controla usando o Assistente para Adicionar classe do ATL, o assistente implementa o suporte baseado em script de registro e adiciona automaticamente o [DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid) macro em seus arquivos. Se você não quiser o suporte de registro baseado em script, você precisa substituir essa macro com `DECLARE_REGISTRY`. `DECLARE_REGISTRY` somente insere as cinco chaves básico descritas acima para o registro. Manualmente, você deve escrever código para inserir outras chaves no registro.  
  
##  <a name="declare_registry_appid_resourceid"></a>  DECLARE_REGISTRY_APPID_RESOURCEID  
 Especifica as informações necessárias para se registrar automaticamente o *appid*.  
  
```
DECLARE_REGISTRY_APPID_RESOURCEID(
    resid, 
    appid )
```  
  
### <a name="parameters"></a>Parâmetros  
 *RESID*  
 A id de recurso do arquivo. rgs que contém informações sobre o *appid*.  
  
 *AppID*  
 Uma GUID.  
  
### <a name="remarks"></a>Comentários  
 Use `DECLARE_REGISTRY_APPID_RESOURCEID` em um `CAtlModuleT`-classe derivada.  
  
### <a name="example"></a>Exemplo  
 Classes adicionadas a projetos ATL com o assistente Adicionar classe de código terá um exemplo de como usar esta macro.  
  
##  <a name="declare_registry_resource"></a>  DECLARE_REGISTRY_RESOURCE  
 Obtém o recurso denominado que contém o arquivo de registro e executa o script para inserir objetos no registro do sistema ou removê-los do registro do sistema.  
  
```
DECLARE_REGISTRY_RESOURCE( x )
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] Identificador do recurso de cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Quando você cria um objeto ou controla usando o Assistente de projeto de ATL, o assistente automaticamente implementa o suporte a registro baseado em script e adicione o [DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid) macro, que é semelhante ao `DECLARE_REGISTRY_RESOURCE`, para o arquivos.  
  
 Você pode vincular estaticamente com o componente de registro ATL (Registrar) para acesso ao registro otimizado. Para vincular estaticamente para o código de registrador, adicione a seguinte linha ao arquivo Stdafx. h:  
  
 [!code-cpp[NVC_ATL_COM#56](../../atl/codesnippet/cpp/registry-macros_2.h)]  
  
 Se você quiser ATL para substituir valores de substituição em tempo de execução, não especifique o `DECLARE_REGISTRY_RESOURCE` ou `DECLARE_REGISTRY_RESOURCEID` macro. Em vez disso, crie uma matriz de **_ATL_REGMAP_ENTRIES** estruturas, onde cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado em tempo de execução. Em seguida, chame [CAtlModule::UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule::UpdateRegistryFromResourceS](catlmodule-class.md#updateregistryfromresources), passando uma matriz. Isso adiciona todos os valores de substituição no **_ATL_REGMAP_ENTRIES** estruturas para o mapa de substituição do registrador.  

  
 Para obter mais informações sobre parâmetros substituíveis e scripts, consulte o artigo [o componente de registro ATL (Registrar)](../../atl/atl-registry-component-registrar.md).  
  
##  <a name="declare_registry_resourceid"></a>  DECLARE_REGISTRY_RESOURCEID  
 Mesmo que [DECLARE_REGISTRY_RESOURCE](#declare_registry_resource) exceto que ele usa um gerado pelo assistente **UINT** para identificar o recurso, em vez de um nome de cadeia de caracteres.  
  
```
DECLARE_REGISTRY_RESOURCEID( x )
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] Identificador gerado pelo Assistente do recurso.  
  
### <a name="remarks"></a>Comentários  
 Quando você cria um objeto ou controla usando o Assistente de projeto de ATL, o assistente automaticamente implementa o suporte a registro baseado em script e adicione o `DECLARE_REGISTRY_RESOURCEID` macro em seus arquivos.  
  
 Você pode vincular estaticamente com o componente de registro ATL (Registrar) para acesso ao registro otimizado. Para vincular estaticamente para o código de registrador, adicione a seguinte linha ao arquivo Stdafx. h:  
  
 [!code-cpp[NVC_ATL_COM#56](../../atl/codesnippet/cpp/registry-macros_2.h)]  
  
 Se você quiser ATL para substituir valores de substituição em tempo de execução, não especifique o `DECLARE_REGISTRY_RESOURCE` ou `DECLARE_REGISTRY_RESOURCEID` macro. Em vez disso, crie uma matriz de **_ATL_REGMAP_ENTRIES** estruturas, onde cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado em tempo de execução. Em seguida, chame [CAtlModule::UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule::UpdateRegistryFromResourceS](catlmodule-class.md#updateregistryfromresources), passando uma matriz. Isso adiciona todos os valores de substituição no **_ATL_REGMAP_ENTRIES** estruturas para o mapa de substituição do registrador.  

  
 Para obter mais informações sobre parâmetros substituíveis e scripts, consulte o artigo [o componente de registro ATL (Registrar)](../../atl/atl-registry-component-registrar.md).  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)
