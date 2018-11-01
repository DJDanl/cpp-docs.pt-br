---
title: Macros de registro
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::_ATL_STATIC_REGISTRY
- atlcom/ATL::DECLARE_LIBID
- atlcom/ATL::DECLARE_NO_REGISTRY
- atlcom/ATL::DECLARE_REGISTRY
- atlcom/ATL::DECLARE_REGISTRY_APPID_RESOURCEID
- atlcom/ATL::DECLARE_REGISTRY_RESOURCE
- atlcom/ATL::DECLARE_REGISTRY_RESOURCEID
helpviewer_keywords:
- registry, ATL macros
ms.assetid: 3ee041da-c63b-42a4-89cf-2a4b2a6f81ae
ms.openlocfilehash: bced900cd7bac666daf415d91a4540828c769025
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50660376"
---
# <a name="registry-macros"></a>Macros de registro

Essas macros definem os recursos de biblioteca e o registro do tipo útil.

|||
|-|-|
|[_ATL_STATIC_REGISTRY](#_atl_static_registry)|Indica que você deseja que o código de registro para seu objeto seja no objeto para evitar uma dependência em ATL. DLL.|
|[DECLARE_LIBID](#declare_libid)|Fornece uma maneira para ATL obter o *libid* da biblioteca de tipos.|
|[DECLARE_NO_REGISTRY](#declare_no_registry)|Evita o registro ATL padrão.|
|[DECLARE_REGISTRY](#declare_registry)|Insere ou remove a entrada do objeto principal no registro do sistema.|
|[DECLARE_REGISTRY_APPID_RESOURCEID](#declare_registry_appid_resourceid)|Especifica as informações necessárias para se registrar automaticamente o *appid*.|
|[DECLARE_REGISTRY_RESOURCE](#declare_registry_resource)|Localiza o recurso denominado e executa o script de registro dentro dele.|
|[DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid)|Localiza o recurso identificado por um número de identificação e executa o script de registro dentro dele.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="_atl_static_registry"></a>  _ATL_STATIC_REGISTRY

Um símbolo que indica que você deseja que o código de registro para seu objeto seja no objeto para evitar uma dependência em ATL. DLL.

```
#define _ATL_STATIC_REGISTRY
```

### <a name="remarks"></a>Comentários

Quando você define ATL_STATIC_REGISTRY, você deve usar o código a seguir:

[!code-cpp[NVC_ATL_EventHandlingSample#5](../../atl/codesnippet/cpp/registry-macros_1.cpp)]

##  <a name="declare_libid"></a>  DECLARE_LIBID

Fornece uma maneira para ATL obter o *libid* da biblioteca de tipos.

```
DECLARE_LIBID( libid )
```

### <a name="parameters"></a>Parâmetros

*ID da biblioteca*<br/>
O GUID da biblioteca de tipos.

### <a name="remarks"></a>Comentários

Use DECLARE_LIBID em um `CAtlModuleT`-classe derivada.

### <a name="example"></a>Exemplo

Atribuída não são gerados pelo Assistente de projetos ATL terá um exemplo de como usar essa macro.

##  <a name="declare_no_registry"></a>  DECLARE_NO_REGISTRY

Use DECLARE_NO_REGISTRY se você quiser evitar qualquer registro ATL padrão para a classe em que essa macro é exibido.

```
DECLARE_NO_REGISTRY()
```

##  <a name="declare_registry"></a>  DECLARE_REGISTRY

Insere o registro de classe padrão no registro do sistema ou remove-registro do sistema.

```
DECLARE_REGISTRY(
    class,
    pid,
    vpid,
    nid,
    flags )
```

### <a name="parameters"></a>Parâmetros

*class*<br/>
[in] Incluído para compatibilidade com versões anteriores.

*pid*<br/>
[in] Um LPCTSTR que é um identificador de programa específicos da versão.

*vpid*<br/>
[in] Um LPCTSTR que é um identificador de programa independente de versão.

*NID*<br/>
[in] UINT que é um índice da cadeia de caracteres de recurso no registro para usar como a descrição do programa.

*flags*<br/>
[in] Um DWORD que contém o modelo de threading do programa no registro. Deve ser um dos seguintes valores: THREADFLAGS_APARTMENT, THREADFLAGS_BOTH ou AUTPRXFLAG.

### <a name="remarks"></a>Comentários

O registro padrão consiste no CLSID, ID do programa, ID de programa independente de versão, cadeia de caracteres de descrição e o modelo de thread.

Quando você cria um objeto ou controle usando o Assistente para Adicionar classe do ATL, o assistente implementa o suporte de registro baseado em script e adiciona automaticamente o [DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid) macro em seus arquivos. Se você não quiser que o suporte de registro baseado em script, você precisará substituir essa macro com DECLARE_REGISTRY. DECLARE_REGISTRY apenas inserções de cinco chaves básicas descritas acima para o registro. Manualmente, você deve escrever código para inserir outras chaves no registro.

##  <a name="declare_registry_appid_resourceid"></a>  DECLARE_REGISTRY_APPID_RESOURCEID

Especifica as informações necessárias para se registrar automaticamente o *appid*.

```
DECLARE_REGISTRY_APPID_RESOURCEID(
    resid,
    appid )
```

### <a name="parameters"></a>Parâmetros

*RESID*<br/>
A id de recurso do arquivo. rgs que contém informações sobre o *appid*.

*AppID*<br/>
Uma GUID.

### <a name="remarks"></a>Comentários

Use DECLARE_REGISTRY_APPID_RESOURCEID em um `CAtlModuleT`-classe derivada.

### <a name="example"></a>Exemplo

Classes adicionadas aos projetos ATL com o Assistente para Adicionar classe código terá um exemplo de como usar essa macro.

##  <a name="declare_registry_resource"></a>  DECLARE_REGISTRY_RESOURCE

Obtém o recurso nomeado que contém o arquivo de registro e executa o script para inserir objetos no registro do sistema ou removê-los do registro do sistema.

```
DECLARE_REGISTRY_RESOURCE( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[in] Identificador do recurso de cadeia de caracteres.

### <a name="remarks"></a>Comentários

Quando você cria um objeto ou controle usando o Assistente de projeto da ATL, o assistente automaticamente implementar o suporte de registro baseado em script e adicione a [DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid) macro, que é semelhante ao DECLARE_REGISTRY_ RECURSOS em seus arquivos.

Você pode vincular estaticamente com o componente de registro ATL (registrador) para acesso ao registro otimizado. Para vincular estaticamente no código do registrador, adicione a seguinte linha ao seu arquivo Stdafx. h:

[!code-cpp[NVC_ATL_COM#56](../../atl/codesnippet/cpp/registry-macros_2.h)]

Se você quiser ATL para substituir valores de substituição em tempo de execução, não especifique a macro DECLARE_REGISTRY_RESOURCE ou DECLARE_REGISTRY_RESOURCEID. Em vez disso, crie uma matriz de `_ATL_REGMAP_ENTRIES` estruturas, onde cada entrada contém um espaço reservado de variável emparelhado com um valor para substituir o espaço reservado em tempo de execução. Em seguida, chame [CAtlModule::UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule::UpdateRegistryFromResourceS](catlmodule-class.md#updateregistryfromresources), passando a matriz. Isso adiciona todos os valores de substituição no `_ATL_REGMAP_ENTRIES` estruturas de mapa de substituição do registrador.

Para obter mais informações sobre parâmetros substituíveis e scripts, consulte o artigo [o componente de registro ATL (registrador)](../../atl/atl-registry-component-registrar.md).

##  <a name="declare_registry_resourceid"></a>  DECLARE_REGISTRY_RESOURCEID

Mesmo que [DECLARE_REGISTRY_RESOURCE](#declare_registry_resource) exceto que ele usa um UINT gerado pelo Assistente para identificar o recurso, em vez de um nome de cadeia de caracteres.

```
DECLARE_REGISTRY_RESOURCEID( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[in] Identificador gerado pelo Assistente do seu recurso.

### <a name="remarks"></a>Comentários

Quando você cria um objeto ou controle usando o Assistente de projeto da ATL, o assistente automaticamente implementar o suporte de registro baseado em script e adicione a macro DECLARE_REGISTRY_RESOURCEID aos arquivos.

Você pode vincular estaticamente com o componente de registro ATL (registrador) para acesso ao registro otimizado. Para vincular estaticamente no código do registrador, adicione a seguinte linha ao seu arquivo Stdafx. h:

[!code-cpp[NVC_ATL_COM#56](../../atl/codesnippet/cpp/registry-macros_2.h)]

Se você quiser ATL para substituir valores de substituição em tempo de execução, não especifique a macro DECLARE_REGISTRY_RESOURCE ou DECLARE_REGISTRY_RESOURCEID. Em vez disso, crie uma matriz de `_ATL_REGMAP_ENTRIES` estruturas, onde cada entrada contém um espaço reservado de variável emparelhado com um valor para substituir o espaço reservado em tempo de execução. Em seguida, chame [CAtlModule::UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule::UpdateRegistryFromResourceS](catlmodule-class.md#updateregistryfromresources), passando a matriz. Isso adiciona todos os valores de substituição no `_ATL_REGMAP_ENTRIES` estruturas de mapa de substituição do registrador.

Para obter mais informações sobre parâmetros substituíveis e scripts, consulte o artigo [o componente de registro ATL (registrador)](../../atl/atl-registry-component-registrar.md).

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
