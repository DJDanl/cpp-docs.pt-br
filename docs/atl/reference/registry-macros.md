---
title: Macros do registro
ms.date: 08/19/2019
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
ms.openlocfilehash: c2a70c15473798ba6eb2ef35e0b7ded395708586
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69630626"
---
# <a name="registry-macros"></a>Macros do registro

Essas macros definem recursos de registro e biblioteca de tipos úteis.

|||
|-|-|
|[_ATL_STATIC_REGISTRY](#_atl_static_registry)|Indica que você deseja que o código de registro do seu objeto esteja no objeto para evitar uma dependência na ATL. DLL.|
|[DECLARE_LIBID](#declare_libid)|Fornece uma maneira para a ATL obter o *LIBID* da biblioteca de tipos.|
|[DECLARE_NO_REGISTRY](#declare_no_registry)|Evita o registro padrão da ATL.|
|[DECLARE_REGISTRY](#declare_registry)|Insere ou remove a entrada do objeto principal no registro do sistema.|
|[DECLARE_REGISTRY_APPID_RESOURCEID](#declare_registry_appid_resourceid)|Especifica as informações necessárias para registrar automaticamente o *AppID*.|
|[DECLARE_REGISTRY_RESOURCE](#declare_registry_resource)|Localiza o recurso nomeado e executa o script de registro dentro dele.|
|[DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid)|Localiza o recurso identificado por um número de ID e executa o script de registro dentro dele.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="_atl_static_registry"></a>  _ATL_STATIC_REGISTRY

Um símbolo que indica que você deseja que o código de registro do seu objeto esteja no objeto para evitar uma dependência na ATL. DLL.

```
#define _ATL_STATIC_REGISTRY
```

### <a name="remarks"></a>Comentários

Ao definir ATL_STATIC_REGISTRY, você deve usar o seguinte código:

[!code-cpp[NVC_ATL_EventHandlingSample#5](../../atl/codesnippet/cpp/registry-macros_1.cpp)]

##  <a name="declare_libid"></a>  DECLARE_LIBID

Fornece uma maneira para a ATL obter o *LIBID* da biblioteca de tipos.

```
DECLARE_LIBID( libid )
```

### <a name="parameters"></a>Parâmetros

*libid*<br/>
O GUID da biblioteca de tipos.

### <a name="remarks"></a>Comentários

Use DECLARE_LIBID em uma `CAtlModuleT`classe derivada.

### <a name="example"></a>Exemplo

Os projetos ATL gerados pelo assistente não atribuído terão um exemplo de como usar essa macro.

##  <a name="declare_no_registry"></a>  DECLARE_NO_REGISTRY

Use DECLARE_NO_REGISTRY se você quiser evitar qualquer registro padrão da ATL para a classe na qual essa macro aparece.

```
DECLARE_NO_REGISTRY()
```

##  <a name="declare_registry"></a>  DECLARE_REGISTRY

Insere o registro de classe padrão no registro do sistema ou o Remove do registro do sistema.

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
no Incluído para compatibilidade com versões anteriores.

*pid*<br/>
no Um LPCTSTR que é um identificador de programa específico da versão.

*vpid*<br/>
no Um LPCTSTR que é um identificador de programa independente de versão.

*nid*<br/>
no Um UINT que é um índice da cadeia de caracteres do recurso no registro a ser usado como a descrição do programa.

*flags*<br/>
no Um DWORD que contém o modelo de Threading do programa no registro. Deve ser um dos seguintes valores: THREADFLAGS_APARTMENT, THREADFLAGS_BOTH ou AUTPRXFLAG.

### <a name="remarks"></a>Comentários

O registro padrão consiste em CLSID, ID do programa, ID do programa independente de versão, Cadeia de caracteres de descrição e modelo de thread.

Quando você cria um objeto ou controle usando o assistente para adicionar classe ATL, o assistente implementa automaticamente o suporte ao registro baseado em script e adiciona a macro [DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid) aos seus arquivos. Se você não quiser suporte ao registro baseado em script, será necessário substituir essa macro por DECLARE_REGISTRY. DECLARE_REGISTRY insere apenas as cinco chaves básicas descritas acima no registro. Você deve escrever manualmente o código para inserir outras chaves no registro.

##  <a name="declare_registry_appid_resourceid"></a>  DECLARE_REGISTRY_APPID_RESOURCEID

Especifica as informações necessárias para registrar automaticamente o *AppID*.

```
DECLARE_REGISTRY_APPID_RESOURCEID(
    resid,
    appid )
```

### <a name="parameters"></a>Parâmetros

*resid*<br/>
A ID de recurso do arquivo. rgs que contém informações sobre o *AppID*.

*appid*<br/>
Uma GUID.

### <a name="remarks"></a>Comentários

Use DECLARE_REGISTRY_APPID_RESOURCEID em uma `CAtlModuleT`classe derivada.

### <a name="example"></a>Exemplo

Classes adicionadas a projetos ATL com o assistente para adicionar código de classe terão um exemplo de como usar essa macro.

##  <a name="declare_registry_resource"></a>  DECLARE_REGISTRY_RESOURCE

Obtém o recurso nomeado que contém o arquivo do registro e executa o script para inserir objetos no registro do sistema ou removê-los do registro do sistema.

```
DECLARE_REGISTRY_RESOURCE( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
no Identificador de cadeia de caracteres do seu recurso.

### <a name="remarks"></a>Comentários

Quando você cria um objeto ou controle usando o assistente de projeto do ATL, o assistente implementará automaticamente o suporte ao registro baseado em script e adicionará a macro [DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid) , que é semelhante a DECLARE_REGISTRY_RESOURCE, aos seus arquivos.

Você pode vincular estaticamente com o componente de registro do ATL (registrador) para acesso otimizado ao registro. Para vincular estaticamente ao código do registrador, adicione a seguinte linha ao seu arquivo *PCH. h* (*stdafx. h* no Visual Studio 2017 e anterior):

[!code-cpp[NVC_ATL_COM#56](../../atl/codesnippet/cpp/registry-macros_2.h)]

Se você quiser que a ATL substitua valores de substituição em tempo de execução, não especifique a macro DECLARE_REGISTRY_RESOURCE ou DECLARE_REGISTRY_RESOURCEID. Em vez disso, crie uma `_ATL_REGMAP_ENTRIES` matriz de estruturas, em que cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado em tempo de execução. Em seguida, chame [CAtlModule:: UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule:: UpdateRegistryFromResourceS](catlmodule-class.md#updateregistryfromresources), passando a matriz. Isso adiciona todos os valores de substituição nas `_ATL_REGMAP_ENTRIES` estruturas ao mapa de substituição do registrador.

Para obter mais informações sobre parâmetros e scripts substituíveis, consulte o artigo [o componente do registro do ATL (registrador)](../../atl/atl-registry-component-registrar.md).

##  <a name="declare_registry_resourceid"></a>  DECLARE_REGISTRY_RESOURCEID

O mesmo que [DECLARE_REGISTRY_RESOURCE](#declare_registry_resource) , exceto que ele usa um UINT gerado por assistente para identificar o recurso, em vez de um nome de cadeia de caracteres.

```
DECLARE_REGISTRY_RESOURCEID( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
no Identificador gerado pelo assistente de seu recurso.

### <a name="remarks"></a>Comentários

Quando você cria um objeto ou controle usando o assistente de projeto do ATL, o assistente implementará automaticamente o suporte ao registro baseado em script e adicionará a macro DECLARE_REGISTRY_RESOURCEID aos seus arquivos.

Você pode vincular estaticamente com o componente de registro do ATL (registrador) para acesso otimizado ao registro. Para vincular estaticamente ao código do registrador, adicione a seguinte linha ao arquivo *stdafx. h* (*PCH. h* no Visual Studio 2019 e posterior):

[!code-cpp[NVC_ATL_COM#56](../../atl/codesnippet/cpp/registry-macros_2.h)]

Se você quiser que a ATL substitua valores de substituição em tempo de execução, não especifique a macro DECLARE_REGISTRY_RESOURCE ou DECLARE_REGISTRY_RESOURCEID. Em vez disso, crie uma `_ATL_REGMAP_ENTRIES` matriz de estruturas, em que cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado em tempo de execução. Em seguida, chame [CAtlModule:: UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule:: UpdateRegistryFromResourceS](catlmodule-class.md#updateregistryfromresources), passando a matriz. Isso adiciona todos os valores de substituição nas `_ATL_REGMAP_ENTRIES` estruturas ao mapa de substituição do registrador.

Para obter mais informações sobre parâmetros e scripts substituíveis, consulte o artigo [o componente do registro do ATL (registrador)](../../atl/atl-registry-component-registrar.md).

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
