---
title: Macros de registro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- registry, ATL macros
ms.assetid: 3ee041da-c63b-42a4-89cf-2a4b2a6f81ae
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 3a3abf5ad29b50c7f6708f02fd7c5aa193b3591c
ms.lasthandoff: 02/25/2017

---
# <a name="registry-macros"></a>Macros de registro
Essas macros definem recursos de biblioteca e o registro do tipo útil.  
  
|||  
|-|-|  
|[_ATL_STATIC_REGISTRY](#_atl_static_registry)|Indica que você deseja que o código de registro para o objeto no objeto para evitar uma dependência em ATL. DLL.|  
|[DECLARE_LIBID](#declare_libid)|Fornece uma maneira para ATL obter o *libid* da biblioteca de tipos.|  
|[DECLARE_NO_REGISTRY](#declare_no_registry)|Evita o registro ATL do padrão.|  
|[DECLARE_REGISTRY](#declare_registry)|Insere ou remove a entrada do objeto principal no registro do sistema.|  
|[DECLARE_REGISTRY_APPID_RESOURCEID](#declare_registry_appid_resourceid)|Especifica as informações necessárias para registrar automaticamente o *appid*.|  
|[DECLARE_REGISTRY_RESOURCE](#declare_registry_resource)|Localiza o recurso denominado e executa o script de registro dentro dele.|  
|[DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid)|Localiza o recurso identificado por um número de identificação e executa o script de registro dentro dele.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
    
##  <a name="a-nameatlstaticregistrya--atlstaticregistry"></a><a name="_atl_static_registry"></a>_ATL_STATIC_REGISTRY  
 Um símbolo que indica que você deseja que o código de registro para o objeto no objeto para evitar uma dependência em ATL. DLL.  
  
```
#define _ATL_STATIC_REGISTRY
```  
  
### <a name="remarks"></a>Comentários  
 Quando você define **ATL_STATIC_REGISTRY**, você deve usar o seguinte código:  
  
 [!code-cpp[NVC_ATL_EventHandlingSample n º&5;](../../atl/codesnippet/cpp/registry-macros_1.cpp)]  
  
##  <a name="a-namedeclarelibida--declarelibid"></a><a name="declare_libid"></a>DECLARE_LIBID  
 Fornece uma maneira para ATL obter o *libid* da biblioteca de tipos.  
  
```
DECLARE_LIBID( libid )
```  
  
### <a name="parameters"></a>Parâmetros  
 *ID da biblioteca*  
 O GUID da biblioteca de tipos.  
  
### <a name="remarks"></a>Comentários  
 Use `DECLARE_LIBID` em um `CAtlModuleT`-classe derivada.  
  
### <a name="example"></a>Exemplo  
 Atribuído não gerado pelo Assistente de projetos ATL terá um exemplo de como usar essa macro.  
  
##  <a name="a-namedeclarenoregistrya--declarenoregistry"></a><a name="declare_no_registry"></a>DECLARE_NO_REGISTRY  
 Use `DECLARE_NO_REGISTRY` para evitar qualquer registro ATL padrão para a classe em que essa macro é exibida.  
  
```
DECLARE_NO_REGISTRY()
```  
  
##  <a name="a-namedeclareregistrya--declareregistry"></a><a name="declare_registry"></a>DECLARE_REGISTRY  
 Insere o registro de classe padrão no registro do sistema ou remove o registro do sistema.  
  
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
 [in] A **UINT** que é um índice da cadeia de caracteres de recurso no registro para usar como a descrição do programa.  
  
 `flags`  
 [in] Um `DWORD` que contém o programa de encadeamento do modelo no registro. Deve ser um dos seguintes valores: **THREADFLAGS_APARTMENT**, **THREADFLAGS_BOTH**, ou **AUTPRXFLAG**.  
  
### <a name="remarks"></a>Comentários  
 O registro padrão consiste o CLSID, ID do programa, ID de programa independente de versão, cadeia de caracteres de descrição e o modelo de thread.  
  
 Quando você cria um objeto ou controla usando o Assistente para Adicionar classe do ATL, o assistente implementa o suporte ao registro baseado em script e adiciona automaticamente o [DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid) macro em seus arquivos. Se não desejar suporte a registro baseada em script, você precisa substituir essa macro com `DECLARE_REGISTRY`. `DECLARE_REGISTRY`Insere somente as cinco chaves básicas descritas acima para o registro. Manualmente, você deve escrever código para inserir outras chaves do registro.  
  
##  <a name="a-namedeclareregistryappidresourceida--declareregistryappidresourceid"></a><a name="declare_registry_appid_resourceid"></a>DECLARE_REGISTRY_APPID_RESOURCEID  
 Especifica as informações necessárias para registrar automaticamente o *appid*.  
  
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
 Classes adicionadas aos projetos do ATL com o Assistente de código Adicionar classe terá um exemplo de como usar essa macro.  
  
##  <a name="a-namedeclareregistryresourcea--declareregistryresource"></a><a name="declare_registry_resource"></a>DECLARE_REGISTRY_RESOURCE  
 Obtém o recurso nomeado que contém o arquivo de registro e executa o script para inserir objetos no registro do sistema ou removê-los do registro do sistema.  
  
```
DECLARE_REGISTRY_RESOURCE( x )
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] Identificador do recurso de cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Quando você cria um objeto ou controle usando a ATL Project Wizard, o assistente automaticamente implementar o suporte a registro baseadas em script e adicionar o [DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid) macro, que é semelhante ao `DECLARE_REGISTRY_RESOURCE`, em seus arquivos.  
  
 Você pode vincular estaticamente com o componente de registro ATL (Registrar) para acesso ao registro otimizado. Para vincular estaticamente no código de registrador, adicione a seguinte linha ao seu arquivo Stdafx. h:  
  
 [!code-cpp[NVC_ATL_COM&56;](../../atl/codesnippet/cpp/registry-macros_2.h)]  
  
 Se você quiser ATL para substituir valores de substituição em tempo de execução, não especifique o `DECLARE_REGISTRY_RESOURCE` ou `DECLARE_REGISTRY_RESOURCEID` macro. Em vez disso, crie uma matriz de **_ATL_REGMAP_ENTRIES** estruturas, onde cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado em tempo de execução. Em seguida, chame [CAtlModule::UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule::UpdateRegistryFromResourceS](catlmodule-class.md#updateregistryfromresources), passando a matriz. Isso adiciona todos os valores de substituição no **_ATL_REGMAP_ENTRIES** estruturas ao mapa de substituição do registrador.  

  
 Para obter mais informações sobre parâmetros substituíveis e scripts, consulte o artigo [o componente de registro ATL (Registrar)](../../atl/atl-registry-component-registrar.md).  
  
##  <a name="a-namedeclareregistryresourceida--declareregistryresourceid"></a><a name="declare_registry_resourceid"></a>DECLARE_REGISTRY_RESOURCEID  
 Mesmo que [DECLARE_REGISTRY_RESOURCE](#declare_registry_resource) exceto que ele usa um gerado pelo assistente **UINT** para identificar o recurso, em vez de um nome de cadeia de caracteres.  
  
```
DECLARE_REGISTRY_RESOURCEID( x )
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] Identificador gerado pelo Assistente do recurso.  
  
### <a name="remarks"></a>Comentários  
 Quando você cria um objeto ou controle usando a ATL Project Wizard, o assistente automaticamente implementar o suporte a registro baseadas em script e adicionar o `DECLARE_REGISTRY_RESOURCEID` macro em seus arquivos.  
  
 Você pode vincular estaticamente com o componente de registro ATL (Registrar) para acesso ao registro otimizado. Para vincular estaticamente no código de registrador, adicione a seguinte linha ao seu arquivo Stdafx. h:  
  
 [!code-cpp[NVC_ATL_COM&56;](../../atl/codesnippet/cpp/registry-macros_2.h)]  
  
 Se você quiser ATL para substituir valores de substituição em tempo de execução, não especifique o `DECLARE_REGISTRY_RESOURCE` ou `DECLARE_REGISTRY_RESOURCEID` macro. Em vez disso, crie uma matriz de **_ATL_REGMAP_ENTRIES** estruturas, onde cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado em tempo de execução. Em seguida, chame [CAtlModule::UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule::UpdateRegistryFromResourceS](catlmodule-class.md#updateregistryfromresources), passando a matriz. Isso adiciona todos os valores de substituição no **_ATL_REGMAP_ENTRIES** estruturas ao mapa de substituição do registrador.  

  
 Para obter mais informações sobre parâmetros substituíveis e scripts, consulte o artigo [o componente de registro ATL (Registrar)](../../atl/atl-registry-component-registrar.md).  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)

