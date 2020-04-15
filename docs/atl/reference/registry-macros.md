---
title: Macros de registro
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
ms.openlocfilehash: fd012b4300f4cd72cdc9ab363b770ac1dbefa06e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326041"
---
# <a name="registry-macros"></a>Macros de registro

Essas macros definem bibliotecas de tipo úteis e instalações de registro.

|||
|-|-|
|[_ATL_STATIC_REGISTRY](#_atl_static_registry)|Indica que você deseja que o código de registro do seu objeto esteja no objeto para evitar uma dependência do ATL. Dll.|
|[DECLARE_LIBID](#declare_libid)|Fornece uma maneira de a ATL obter a *oferta* da biblioteca do tipo.|
|[DECLARE_NO_REGISTRY](#declare_no_registry)|Evita o registro ATL padrão.|
|[DECLARE_REGISTRY](#declare_registry)|Insere ou remove a entrada do objeto principal no registro do sistema.|
|[DECLARE_REGISTRY_APPID_RESOURCEID](#declare_registry_appid_resourceid)|Especifica as informações necessárias para registrar automaticamente *o apêndice*.|
|[Declare_registry_resource](#declare_registry_resource)|Encontra o recurso nomeado e executa o script de registro dentro dele.|
|[Declare_registry_resourceid](#declare_registry_resourceid)|Encontra o recurso identificado por um número de identificação e executa o script de registro dentro dele.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="_atl_static_registry"></a><a name="_atl_static_registry"></a>_ATL_STATIC_REGISTRY

Um símbolo que indica que você deseja que o código de registro do seu objeto esteja no objeto para evitar uma dependência do ATL. Dll.

```
#define _ATL_STATIC_REGISTRY
```

### <a name="remarks"></a>Comentários

Quando você define ATL_STATIC_REGISTRY, você deve usar o seguinte código:

[!code-cpp[NVC_ATL_EventHandlingSample#5](../../atl/codesnippet/cpp/registry-macros_1.cpp)]

## <a name="declare_libid"></a><a name="declare_libid"></a>DECLARE_LIBID

Fornece uma maneira de a ATL obter a *oferta* da biblioteca do tipo.

```
DECLARE_LIBID( libid )
```

### <a name="parameters"></a>Parâmetros

*Libid*<br/>
O GUID da biblioteca de tipos.

### <a name="remarks"></a>Comentários

Use DECLARE_LIBID `CAtlModuleT`em uma classe derivada.

### <a name="example"></a>Exemplo

Projetos ATL gerados pelo assistente não atribuídoterão uma amostra do uso dessa macro.

## <a name="declare_no_registry"></a><a name="declare_no_registry"></a>DECLARE_NO_REGISTRY

Use DECLARE_NO_REGISTRY se quiser evitar qualquer registro ATL padrão para a classe em que essa macro aparece.

```
DECLARE_NO_REGISTRY()
```

## <a name="declare_registry"></a><a name="declare_registry"></a>DECLARE_REGISTRY

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

*classe*<br/>
[em] Incluído para compatibilidade retrógrada.

*Pid*<br/>
[em] Um LPCTSTR que é um identificador de programa específico da versão.

*vpid*<br/>
[em] Um LPCTSTR que é um identificador de programa independente de versão.

*Nid*<br/>
[em] Um UINT que é um índice da cadeia de recursos no registro para usar como a descrição do programa.

*Sinalizadores*<br/>
[em] Um DWORD contendo o modelo de rosca do programa no registro. Deve ser um dos seguintes valores: THREADFLAGS_APARTMENT, THREADFLAGS_BOTH ou AUTPRXFLAG.

### <a name="remarks"></a>Comentários

O registro padrão consiste no CLSID, ID do programa, ID do programa independente de versão, string de descrição e modelo de rosca.

Quando você cria um objeto ou controle usando o ASSISTENTE DE CLASSE ATL Add, o assistente implementa automaticamente o suporte de registro baseado em script e adiciona a [DECLARE_REGISTRY_RESOURCEID](#declare_registry_resourceid) macro aos seus arquivos. Se você não quiser suporte de registro baseado em script, você precisa substituir essa macro por DECLARE_REGISTRY. DECLARE_REGISTRY só insere as cinco chaves básicas descritas acima no registro. Você deve escrever manualmente código para inserir outras chaves no registro.

## <a name="declare_registry_appid_resourceid"></a><a name="declare_registry_appid_resourceid"></a>DECLARE_REGISTRY_APPID_RESOURCEID

Especifica as informações necessárias para registrar automaticamente *o apêndice*.

```
DECLARE_REGISTRY_APPID_RESOURCEID(
    resid,
    appid )
```

### <a name="parameters"></a>Parâmetros

*Resid*<br/>
O id de recurso do arquivo .rgs que contém informações sobre o *appid*.

*Appid*<br/>
Uma GUID.

### <a name="remarks"></a>Comentários

Use DECLARE_REGISTRY_APPID_RESOURCEID `CAtlModuleT`em uma classe derivada.

### <a name="example"></a>Exemplo

As classes adicionadas aos projetos ATL com o assistente de código Add Class terão uma amostra do uso dessa macro.

## <a name="declare_registry_resource"></a><a name="declare_registry_resource"></a>Declare_registry_resource

Obtém o recurso nomeado contendo o arquivo de registro e executa o script para inserir objetos no registro do sistema ou removê-los do registro do sistema.

```
DECLARE_REGISTRY_RESOURCE( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] Identificador de string saque do seu recurso.

### <a name="remarks"></a>Comentários

Quando você cria um objeto ou controle usando o Assistente de Projeto ATL, o assistente implementará automaticamente [o](#declare_registry_resourceid) suporte de registro baseado em script e adicionará a DECLARE_REGISTRY_RESOURCEID macro, que é semelhante ao DECLARE_REGISTRY_RESOURCE, aos seus arquivos.

Você pode vincular estáticamente com o Registrador (Registro) do ATL para acesso otimizado ao registro. Para vincular estáticamente ao código Registrador, adicione a seguinte linha ao seu arquivo *pch.h* *(stdafx.h* no Visual Studio 2017 e anterior):

[!code-cpp[NVC_ATL_COM#56](../../atl/codesnippet/cpp/registry-macros_2.h)]

Se você quiser que a ATL substitua os valores de substituição no tempo de execução, não especifique a DECLARE_REGISTRY_RESOURCE ou DECLARE_REGISTRY_RESOURCEID macro. Em vez disso, `_ATL_REGMAP_ENTRIES` crie uma matriz de estruturas, onde cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado no tempo de execução. Em seguida, ligue [para CAtlModule::UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule::UpdateRegistryFromResourceS](catlmodule-class.md#updateregistryfromresources), passando o array. Isso adiciona todos os valores de substituição nas `_ATL_REGMAP_ENTRIES` estruturas ao mapa de substituição do Registrador.

Para obter mais informações sobre parâmetros substituíveis e scripting, consulte o artigo [The ATL Registry Component (Register)](../../atl/atl-registry-component-registrar.md).

## <a name="declare_registry_resourceid"></a><a name="declare_registry_resourceid"></a>Declare_registry_resourceid

O mesmo [que DECLARE_REGISTRY_RESOURCE](#declare_registry_resource) exceto que ele usa um UINT gerado pelo assistente para identificar o recurso, em vez de um nome de seqüência.

```
DECLARE_REGISTRY_RESOURCEID( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] Identificador gerado pelo assistente do seu recurso.

### <a name="remarks"></a>Comentários

Quando você cria um objeto ou controle usando o Assistente de Projeto ATL, o assistente implementará automaticamente o suporte de registro baseado em script e adicionará a DECLARE_REGISTRY_RESOURCEID macro aos seus arquivos.

Você pode vincular estáticamente com o Registrador (Registro) do ATL para acesso otimizado ao registro. Para vincular estáticamente ao código Registrador, adicione a seguinte linha ao seu arquivo *stdafx.h* *(pch.h* no Visual Studio 2019 e posterior):

[!code-cpp[NVC_ATL_COM#56](../../atl/codesnippet/cpp/registry-macros_2.h)]

Se você quiser que a ATL substitua os valores de substituição no tempo de execução, não especifique a DECLARE_REGISTRY_RESOURCE ou DECLARE_REGISTRY_RESOURCEID macro. Em vez disso, `_ATL_REGMAP_ENTRIES` crie uma matriz de estruturas, onde cada entrada contém um espaço reservado variável emparelhado com um valor para substituir o espaço reservado no tempo de execução. Em seguida, ligue [para CAtlModule::UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule::UpdateRegistryFromResourceS](catlmodule-class.md#updateregistryfromresources), passando o array. Isso adiciona todos os valores de substituição nas `_ATL_REGMAP_ENTRIES` estruturas ao mapa de substituição do Registrador.

Para obter mais informações sobre parâmetros substituíveis e scripting, consulte o artigo [The ATL Registry Component (Register)](../../atl/atl-registry-component-registrar.md).

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
