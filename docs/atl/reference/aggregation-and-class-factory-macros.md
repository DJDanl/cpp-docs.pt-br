---
title: Macros de agregação e classe de fábrica
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::DECLARE_AGGREGATABLE
- atlcom/ATL::DECLARE_CLASSFACTORY
- atlcom/ATL::DECLARE_CLASSFACTORY_EX
- atlcom/ATL::DECLARE_CLASSFACTORY_AUTO_THREAD
- atlcom/ATL::DECLARE_CLASSFACTORY_SINGLETON
- atlcom/ATL::DECLARE_GET_CONTROLLING_UNKNOWN
- atlcom/ATL::DECLARE_NOT_AGGREGATABLE
- atlcom/ATL::DECLARE_ONLY_AGGREGATABLE
- atlcom/ATL::DECLARE_POLY_AGGREGATABLE
- atlcom/ATL::DECLARE_PROTECT_FINAL_CONSTRUCT
- atlcom/ATL::DECLARE_VIEW_STATUS
helpviewer_keywords:
- class factories, ATL macros
- aggregation [C++], ATL macros
ms.assetid: d99d379a-0eec-481f-8daa-252dac18f163
ms.openlocfilehash: 38239942b99a29b5777deef8000d9f1ab85b10e6
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418226"
---
# <a name="aggregation-and-class-factory-macros"></a>Macros de agregação e classe de fábrica

Essas macros fornecem maneiras de controlar a agregação e declarar fábricas de classes.

|||
|-|-|
|[DECLARE_AGGREGATABLE](#declare_aggregatable)|Declara que o objeto pode ser agregado (o padrão).|
|[DECLARE_CLASSFACTORY](#declare_classfactory)|Declara a fábrica de classes a ser [CComClassFactory](../../atl/reference/ccomclassfactory-class.md), a fábrica de classes padrão da ATL.|
|[DECLARE_CLASSFACTORY_EX](#declare_classfactory_ex)|Declara seu objeto de fábrica de classes para ser a fábrica de classes.|
|[DECLARE_CLASSFACTORY2](#declare_classfactory2)|Declara [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md) para ser a fábrica de classes.|
|[DECLARE_CLASSFACTORY_AUTO_THREAD](#declare_classfactory_auto_thread)|Declara [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) para ser a fábrica de classes.|
|[DECLARE_CLASSFACTORY_SINGLETON](#declare_classfactory_singleton)|Declara [CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md) para ser a fábrica de classes.|
|[DECLARE_GET_CONTROLLING_UNKNOWN](#declare_get_controlling_unknown)|Declara uma função de `GetControllingUnknown` virtual.|
|[DECLARE_NOT_AGGREGATABLE](#declare_not_aggregatable)|Declara que o objeto não pode ser agregado.|
|[DECLARE_ONLY_AGGREGATABLE](#declare_only_aggregatable)|Declara que o objeto deve ser agregado.|
|[DECLARE_POLY_AGGREGATABLE](#declare_poly_aggregatable)|Verifica o valor da externa desconhecida e declara seu objeto agregável ou não agregável, conforme apropriado.|
|[DECLARE_PROTECT_FINAL_CONSTRUCT](#declare_protect_final_construct)|Protege o objeto externo da exclusão durante a construção de um objeto interno.|
|[DECLARE_VIEW_STATUS](#declare_view_status)|Especifica os sinalizadores VIEWSTATUS para o contêiner.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="declare_aggregatable"></a>DECLARE_AGGREGATABLE

Especifica que o objeto pode ser agregado.

```
DECLARE_AGGREGATABLE( x )
```

### <a name="parameters"></a>parâmetros

*x*<br/>
no O nome da classe que você está definindo como agregável.

### <a name="remarks"></a>Comentários

[CComCoClass](../../atl/reference/ccomcoclass-class.md) contém esta macro para especificar o modelo de agregação padrão. Para substituir esse padrão, especifique a macro [DECLARE_NOT_AGGREGATABLE](#declare_not_aggregatable) ou [DECLARE_ONLY_AGGREGATABLE](#declare_only_aggregatable) em sua definição de classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#121](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_1.h)]

##  <a name="declare_classfactory"></a>DECLARE_CLASSFACTORY

Declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) para ser a fábrica de classes.

```
DECLARE_CLASSFACTORY()
```

### <a name="remarks"></a>Comentários

[CComCoClass](../../atl/reference/ccomcoclass-class.md) usa essa macro para declarar a fábrica de classes padrão para seu objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#55](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_2.h)]

##  <a name="ccomclassfactory_class"></a>Classe CComClassFactory

Essa classe implementa a interface [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory) .

```
class CComClassFactory : public IClassFactory,
public CComObjectRootEx<CComGlobalsThreadModel>
```

### <a name="remarks"></a>Comentários

`CComClassFactory` implementa a interface [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory) , que contém métodos para criar um objeto de um CLSID específico, bem como bloquear a fábrica de classes na memória para permitir que novos objetos sejam criados mais rapidamente. `IClassFactory` deve ser implementado para cada classe registrada no registro do sistema e à qual você atribui um CLSID.

Os objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](#declare_classfactory), que declara `CComClassFactory` como a fábrica de classes padrão. Para substituir esse padrão, especifique uma das macros DECLARE_CLASSFACTORY*xxx* em sua definição de classe. Por exemplo, a macro [DECLARE_CLASSFACTORY_EX](#declare_classfactory_ex) usa a classe especificada para a fábrica de classes:

[!code-cpp[NVC_ATL_COM#8](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_3.h)]

A definição de classe acima Especifica que `CMyClassFactory` será usada como a fábrica de classes padrão do objeto. `CMyClassFactory` deve derivar de `CComClassFactory` e substituir `CreateInstance`.

A ATL fornece três outras macros que declaram uma fábrica de classes:

- [DECLARE_CLASSFACTORY2](#declare_classfactory2) Usa [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md), que controla a criação por meio de uma licença.

- [DECLARE_CLASSFACTORY_AUTO_THREAD](#declare_classfactory_auto_thread) Usa [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md), que cria objetos em vários Apartments.

- [DECLARE_CLASSFACTORY_SINGLETON](#declare_classfactory_singleton) Usa [CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md), que constrói um único objeto [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) .

##  <a name="declare_classfactory_ex"></a>DECLARE_CLASSFACTORY_EX

Declara `cf` ser a fábrica de classes.

```
DECLARE_CLASSFACTORY_EX( cf )
```

### <a name="parameters"></a>parâmetros

*CF*<br/>
no O nome da classe que implementa o objeto de fábrica de classe.

### <a name="remarks"></a>Comentários

O parâmetro *CF* deve derivar de [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e substituir o método `CreateInstance`.

[CComCoClass](../../atl/reference/ccomcoclass-class.md) inclui a macro [DECLARE_CLASSFACTORY](#declare_classfactory) , que especifica `CComClassFactory` como a fábrica de classes padrão. No entanto, ao incluir a macro DECLARE_CLASSFACTORY_EX na definição de classe do objeto, você substitui esse padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#8](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_3.h)]

##  <a name="declare_classfactory2"></a>DECLARE_CLASSFACTORY2

Declara [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md) para ser a fábrica de classes.

```
DECLARE_CLASSFACTORY2( lic )
```

### <a name="parameters"></a>parâmetros

*lic.*<br/>
no Uma classe que implementa `VerifyLicenseKey`, `GetLicenseKey`e `IsLicenseValid`.

### <a name="remarks"></a>Comentários

[CComCoClass](../../atl/reference/ccomcoclass-class.md) inclui a macro [DECLARE_CLASSFACTORY](#declare_classfactory) , que especifica [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classes padrão. No entanto, ao incluir a macro DECLARE_CLASSFACTORY2 na definição de classe do objeto, você substitui esse padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#2](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_4.h)]

##  <a name="ccomclassfactory2_class"></a>Classe CComClassFactory2

Essa classe implementa a interface [IClassFactory2](/windows/win32/api/ocidl/nn-ocidl-iclassfactory2) .

```
template <class license>
class  CComClassFactory2 : public IClassFactory2,
    public CComObjectRootEx<CComGlobalsThreadModel>,
    public license
```

### <a name="parameters"></a>parâmetros

*license*<br/>
Uma classe que implementa as seguintes funções estáticas:

- `static BOOL VerifyLicenseKey( BSTR bstr );`

- `static BOOL GetLicenseKey( DWORD dwReserved, BSTR * pBstr );`

- `static BOOL IsLicenseValid( );`

### <a name="remarks"></a>Comentários

`CComClassFactory2` implementa a interface [IClassFactory2](/windows/win32/api/ocidl/nn-ocidl-iclassfactory2) , que é uma extensão de [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory). `IClassFactory2` controla a criação de objetos por meio de uma licença. Uma fábrica de classes em execução em uma máquina licenciada pode fornecer uma chave de licença em tempo de execução. Essa chave de licença permite que um aplicativo crie uma instância de objetos quando uma licença de computador completa não existir.

Os objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](#declare_classfactory), que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classes padrão. Para usar `CComClassFactory2`, especifique a macro [DECLARE_CLASSFACTORY2](#declare_classfactory2) na definição de classe do seu objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#2](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_4.h)]

`CMyLicense`, o parâmetro de modelo para `CComClassFactory2`, deve implementar as funções estáticas `VerifyLicenseKey`, `GetLicenseKey`e `IsLicenseValid`. Veja a seguir um exemplo de uma classe de licença simples:

[!code-cpp[NVC_ATL_COM#3](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_5.h)]

`CComClassFactory2` deriva de `CComClassFactory2Base` e *licença*. `CComClassFactory2Base`, por sua vez, deriva de `IClassFactory2` e **CComObjectRootEx\< CComGlobalsThreadModel >** .

##  <a name="declare_classfactory_auto_thread"></a>DECLARE_CLASSFACTORY_AUTO_THREAD

Declara [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) para ser a fábrica de classes.

```
DECLARE_CLASSFACTORY_AUTO_THREAD()
```

### <a name="remarks"></a>Comentários

[CComCoClass](../../atl/reference/ccomcoclass-class.md) inclui a macro [DECLARE_CLASSFACTORY](#declare_classfactory) , que especifica [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classes padrão. No entanto, ao incluir a macro DECLARE_CLASSFACTORY_AUTO_THREAD na definição de classe do objeto, você substitui esse padrão.

Quando você cria objetos em vários Apartments (em um servidor fora do processo), adicione DECLARE_CLASSFACTORY_AUTO_THREAD à sua classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#9](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_6.h)]

##  <a name="ccomclassfactoryautothread_class"></a>Classe CComClassFactoryAutoThread

Essa classe implementa a interface [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory) e permite que os objetos sejam criados em vários Apartments.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

```
class CComClassFactoryAutoThread : public IClassFactory,
public CComObjectRootEx<CComGlobalsThreadModel>
```

### <a name="remarks"></a>Comentários

`CComClassFactoryAutoThread` é semelhante a [CComClassFactory](../../atl/reference/ccomclassfactory-class.md), mas permite que os objetos sejam criados em vários Apartments. Para aproveitar esse suporte, derive seu módulo EXE de [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).

Os objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](#declare_classfactory), que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classes padrão. Para usar `CComClassFactoryAutoThread`, especifique a macro [DECLARE_CLASSFACTORY_AUTO_THREAD](#declare_classfactory_auto_thread) na definição de classe do seu objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#9](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_6.h)]

##  <a name="declare_classfactory_singleton"></a>DECLARE_CLASSFACTORY_SINGLETON

Declara [CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md) para ser a fábrica de classes.

```
DECLARE_CLASSFACTORY_SINGLETON( obj )
```

### <a name="parameters"></a>parâmetros

*obj*<br/>
no O nome do seu objeto de classe.

### <a name="remarks"></a>Comentários

[CComCoClass](../../atl/reference/ccomcoclass-class.md) inclui a macro [DECLARE_CLASSFACTORY](#declare_classfactory) , que especifica [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classes padrão. No entanto, ao incluir a macro DECLARE_CLASSFACTORY_SINGLETON na definição de classe do objeto, você substitui esse padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#10](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_7.h)]

##  <a name="ccomclassfactorysingleton_class"></a>Classe CComClassFactorySingleton

Essa classe deriva de [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

```
template<class T>
class CComClassFactorySingleton : public CComClassFactory
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Sua classe.

`CComClassFactorySingleton` deriva de [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto. Cada chamada para o método `CreateInstance` simplesmente consulta esse objeto para um ponteiro de interface.

### <a name="remarks"></a>Comentários

Os objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](#declare_classfactory), que declara `CComClassFactory` como a fábrica de classes padrão. Para usar `CComClassFactorySingleton`, especifique a macro [DECLARE_CLASSFACTORY_SINGLETON](#declare_classfactory_singleton) na definição de classe do seu objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#10](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_7.h)]

##  <a name="declare_get_controlling_unknown"></a>DECLARE_GET_CONTROLLING_UNKNOWN

Declara uma função virtual `GetControllingUnknown`.

```
DECLARE_GET_CONTROLLING_UNKNOWN()
```

### <a name="remarks"></a>Comentários

Adicione essa macro ao seu objeto se você receber a mensagem de erro do compilador de que `GetControllingUnknown` é indefinido (por exemplo, em `CComAggregateCreator`).

##  <a name="declare_not_aggregatable"></a>DECLARE_NOT_AGGREGATABLE

Especifica que o objeto não pode ser agregado.

```
DECLARE_NOT_AGGREGATABLE( x )
```

### <a name="parameters"></a>parâmetros

*x*<br/>
no O nome do objeto de classe que você está definindo como não agregável.

### <a name="remarks"></a>Comentários

DECLARE_NOT_AGGREGATABLE faz `CreateInstance` retornar um erro (CLASS_E_NOAGGREGATION) se for feita uma tentativa de agregar em seu objeto.

Por padrão, [CComCoClass](../../atl/reference/ccomcoclass-class.md) contém a macro [DECLARE_AGGREGATABLE](#declare_aggregatable) , que especifica que o objeto pode ser agregado. Para substituir esse comportamento padrão, inclua DECLARE_NOT_AGGREGATABLE em sua definição de classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#121](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_1.h)]

##  <a name="declare_only_aggregatable"></a>DECLARE_ONLY_AGGREGATABLE

Especifica que o objeto deve ser agregado.

```
DECLARE_ONLY_AGGREGATABLE( x )
```

### <a name="parameters"></a>parâmetros

*x*<br/>
no O nome do objeto de classe que você está definindo como somente agregável.

### <a name="remarks"></a>Comentários

DECLARE_ONLY_AGGREGATABLE causará um erro (E_FAIL) se for feita uma tentativa de `CoCreate` seu objeto como objeto não agregado.

Por padrão, [CComCoClass](../../atl/reference/ccomcoclass-class.md) contém a macro [DECLARE_AGGREGATABLE](#declare_aggregatable) , que especifica que o objeto pode ser agregado. Para substituir esse comportamento padrão, inclua DECLARE_ONLY_AGGREGATABLE em sua definição de classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#125](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_8.h)]

##  <a name="declare_poly_aggregatable"></a>DECLARE_POLY_AGGREGATABLE

Especifica que uma instância de **CComPolyObject \<** *x* **>** é criada quando o objeto é criado.

```
DECLARE_POLY_AGGREGATABLE( x )
```

### <a name="parameters"></a>parâmetros

*x*<br/>
no O nome do objeto de classe que você está definindo como agregável ou não agregável.

### <a name="remarks"></a>Comentários

Durante a criação, o valor da externa Unknown é verificado. Se for NULL, `IUnknown` será implementada para um objeto não agregado. Se o desconhecido externo não for nulo, `IUnknown` será implementado para um objeto agregado.

A vantagem de usar o DECLARE_POLY_AGGREGATABLE é que você evita ter `CComAggObject` e `CComObject` em seu módulo para lidar com os casos agregados e não agregados. Um único objeto `CComPolyObject` trata ambos os casos. Isso significa que apenas uma cópia da vtable e uma cópia das funções existem no seu módulo. Se a vtable for grande, isso poderá diminuir substancialmente o tamanho do módulo. No entanto, se a vtable for pequena, o uso de `CComPolyObject` poderá resultar em um tamanho de módulo ligeiramente maior porque ele não é otimizado para um objeto agregado ou não agregado, assim como `CComAggObject` e `CComObject`.

A macro DECLARE_POLY_AGGREGATABLE é declarada automaticamente em seu objeto se você usar o assistente de controle do ATL para criar um controle total.

##  <a name="declare_protect_final_construct"></a>DECLARE_PROTECT_FINAL_CONSTRUCT

Protege seu objeto de ser excluído se (durante [FinalConstruct](ccomobjectrootex-class.md#finalconstruct)) o objeto agregado interno incrementa a contagem de referência e decrementa a contagem para 0.

```
DECLARE_PROTECT_FINAL_CONSTRUCT()
```

##  <a name="declare_view_status"></a>DECLARE_VIEW_STATUS

Coloque essa macro em uma classe de controle do controle ActiveX ATL para especificar os sinalizadores VIEWSTATUS para o contêiner.

```
DECLARE_VIEW_STATUS( statusFlags )
```

### <a name="parameters"></a>parâmetros

*statusFlags*<br/>
no Os sinalizadores VIEWSTATUS. Consulte [VIEWSTATUS](/windows/win32/api/ocidl/ne-ocidl-viewstatus) para obter uma lista de sinalizadores.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#126](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_9.h)]

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
