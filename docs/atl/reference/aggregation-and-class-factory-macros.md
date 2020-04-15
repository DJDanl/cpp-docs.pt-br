---
title: Agregação e Macros de Fábrica de Classe
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
ms.openlocfilehash: 33f33043d1a2c824ada26399365541796178d21d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319332"
---
# <a name="aggregation-and-class-factory-macros"></a>Agregação e Macros de Fábrica de Classe

Essas macros fornecem formas de controlar a agregação e de declarar fábricas de classe.

|||
|-|-|
|[DECLARE_AGGREGATABLE](#declare_aggregatable)|Declara que seu objeto pode ser agregado (o padrão).|
|[DECLARE_CLASSFACTORY](#declare_classfactory)|Declara que a fábrica de classe é [CComClassFactory](../../atl/reference/ccomclassfactory-class.md), a fábrica de classe padrão ATL.|
|[DECLARE_CLASSFACTORY_EX](#declare_classfactory_ex)|Declara que seu objeto de fábrica de classe é a fábrica de classe.|
|[DECLARE_CLASSFACTORY2](#declare_classfactory2)|Declara [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md) como a fábrica de classe.|
|[Declare_classfactory_auto_thread](#declare_classfactory_auto_thread)|Declara [cComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) como a fábrica da classe.|
|[DECLARE_CLASSFACTORY_SINGLETON](#declare_classfactory_singleton)|Declara [ccomClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md) como a fábrica de classes.|
|[DECLARE_GET_CONTROLLING_UNKNOWN](#declare_get_controlling_unknown)|Declara uma `GetControllingUnknown` função virtual.|
|[DECLARE_NOT_AGGREGATABLE](#declare_not_aggregatable)|Declara que seu objeto não pode ser agregado.|
|[Declare_only_aggregatable](#declare_only_aggregatable)|Declara que seu objeto deve ser agregado.|
|[DECLARE_POLY_AGGREGATABLE](#declare_poly_aggregatable)|Verifica o valor do desconhecido externo e declara seu objeto agregado ou não agregavel, conforme apropriado.|
|[DECLARE_PROTECT_FINAL_CONSTRUCT](#declare_protect_final_construct)|Protege o objeto externo da exclusão durante a construção de um objeto interno.|
|[DECLARE_VIEW_STATUS](#declare_view_status)|Especifica as bandeiras VIEWSTATUS para o contêiner.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="declare_aggregatable"></a><a name="declare_aggregatable"></a>DECLARE_AGGREGATABLE

Especifica que seu objeto pode ser agregado.

```
DECLARE_AGGREGATABLE( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome da classe que você está definindo como agregador.

### <a name="remarks"></a>Comentários

[CComCoClass](../../atl/reference/ccomcoclass-class.md) contém essa macro para especificar o modelo de agregação padrão. Para substituir esse padrão, especifique a [DECLARE_NOT_AGGREGATABLE](#declare_not_aggregatable) ou [DECLARE_ONLY_AGGREGATABLE](#declare_only_aggregatable) macro na definição de classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#121](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_1.h)]

## <a name="declare_classfactory"></a><a name="declare_classfactory"></a>DECLARE_CLASSFACTORY

Declara [cComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe.

```
DECLARE_CLASSFACTORY()
```

### <a name="remarks"></a>Comentários

[CComCoClass](../../atl/reference/ccomcoclass-class.md) usa essa macro para declarar a fábrica de classe padrão para o seu objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#55](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_2.h)]

## <a name="ccomclassfactory-class"></a><a name="ccomclassfactory_class"></a>Classe CComClassFactory

Esta classe implementa a interface [IClassFactory.](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory)

```
class CComClassFactory : public IClassFactory,
public CComObjectRootEx<CComGlobalsThreadModel>
```

### <a name="remarks"></a>Comentários

`CComClassFactory`implementa a interface [IClassFactory,](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory) que contém métodos para criar um objeto de um CLSID específico, bem como bloquear a fábrica de classe na memória para permitir que novos objetos sejam criados mais rapidamente. `IClassFactory`deve ser implementado para cada classe que você se registrar no registro do sistema e para o qual você atribui um CLSID.

Os objetos ATL normalmente adquirem uma fábrica de classe derivando do [CComCoClass](../../atl/reference/ccomcoclass-class.md). Esta classe inclui o [DECLARE_CLASSFACTORY](#declare_classfactory)macro `CComClassFactory` , que declara como a fábrica de classe padrão. Para substituir esse padrão, especifique uma das DECLARE_CLASSFACTORY*macros XXX* na definição de classe. Por exemplo, a [macro DECLARE_CLASSFACTORY_EX](#declare_classfactory_ex) usa a classe especificada para a fábrica de classes:

[!code-cpp[NVC_ATL_COM#8](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_3.h)]

A definição de classe `CMyClassFactory` acima especifica que será usada como fábrica de classe padrão do objeto. `CMyClassFactory`deve derivar `CComClassFactory` e `CreateInstance`substituir .

A ATL fornece três outras macros que declaram uma fábrica de classe:

- [DECLARE_CLASSFACTORY2.](#declare_classfactory2) Usa [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md), que controla a criação através de uma licença.

- [DECLARE_CLASSFACTORY_AUTO_THREAD DECLARE_CLASSFACTORY_AUTO_THREAD.](#declare_classfactory_auto_thread) Usa [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md), que cria objetos em vários apartamentos.

- [DECLARE_CLASSFACTORY_SINGLETON](#declare_classfactory_singleton) Usa [CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md), que constrói um único objeto [CComObjectGlobal.](../../atl/reference/ccomobjectglobal-class.md)

## <a name="declare_classfactory_ex"></a><a name="declare_classfactory_ex"></a>DECLARE_CLASSFACTORY_EX

Declara `cf` ser a fábrica de classe.

```
DECLARE_CLASSFACTORY_EX( cf )
```

### <a name="parameters"></a>Parâmetros

*Cf*<br/>
[em] O nome da classe que implementa seu objeto de fábrica de classe.

### <a name="remarks"></a>Comentários

O *parâmetro cf* deve derivar de [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e substituir o `CreateInstance` método.

[CComCoClass](../../atl/reference/ccomcoclass-class.md) inclui a [DECLARE_CLASSFACTORY](#declare_classfactory) macro, `CComClassFactory` que especifica como a fábrica de classe padrão. No entanto, ao incluir a DECLARE_CLASSFACTORY_EX macro na definição de classe do seu objeto, você anula esse padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#8](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_3.h)]

## <a name="declare_classfactory2"></a><a name="declare_classfactory2"></a>DECLARE_CLASSFACTORY2

Declara [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md) como a fábrica de classe.

```
DECLARE_CLASSFACTORY2( lic )
```

### <a name="parameters"></a>Parâmetros

*Lic*<br/>
[em] Uma classe que `VerifyLicenseKey` `GetLicenseKey`implementa, e `IsLicenseValid`.

### <a name="remarks"></a>Comentários

[CComCoClass](../../atl/reference/ccomcoclass-class.md) inclui a [DECLARE_CLASSFACTORY](#declare_classfactory) macro, que especifica [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. No entanto, ao incluir a DECLARE_CLASSFACTORY2 macro na definição de classe do seu objeto, você anula esse padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#2](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_4.h)]

## <a name="ccomclassfactory2-class"></a><a name="ccomclassfactory2_class"></a>Classe CComClassFactory2

Esta classe implementa a interface [IClassFactory2.](/windows/win32/api/ocidl/nn-ocidl-iclassfactory2)

```
template <class license>
class  CComClassFactory2 : public IClassFactory2,
    public CComObjectRootEx<CComGlobalsThreadModel>,
    public license
```

### <a name="parameters"></a>Parâmetros

*Licença*<br/>
Uma classe que implementa as seguintes funções estáticas:

- `static BOOL VerifyLicenseKey( BSTR bstr );`

- `static BOOL GetLicenseKey( DWORD dwReserved, BSTR * pBstr );`

- `static BOOL IsLicenseValid( );`

### <a name="remarks"></a>Comentários

`CComClassFactory2`implementa a interface [IClassFactory2,](/windows/win32/api/ocidl/nn-ocidl-iclassfactory2) que é uma extensão do [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory). `IClassFactory2`controla a criação de objetos através de uma licença. Uma fábrica de classe executando em uma máquina licenciada pode fornecer uma chave de licença em tempo de execução. Esta chave de licença permite que um aplicativo instancia objetos quando uma licença de máquina completa não existe.

Os objetos ATL normalmente adquirem uma fábrica de classe derivando do [CComCoClass](../../atl/reference/ccomcoclass-class.md). Esta classe inclui o [DECLARE_CLASSFACTORY](#declare_classfactory)de macro , que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. Para `CComClassFactory2`usar, especifique a [DECLARE_CLASSFACTORY2](#declare_classfactory2) macro na definição de classe do objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#2](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_4.h)]

`CMyLicense`, o parâmetro `CComClassFactory2`de modelo para , `VerifyLicenseKey` `GetLicenseKey`deve `IsLicenseValid`implementar as funções estáticas, e . A seguir, um exemplo de uma classe de licença simples:

[!code-cpp[NVC_ATL_COM#3](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_5.h)]

`CComClassFactory2`deriva de `CComClassFactory2Base` ambos e *licença*. `CComClassFactory2Base`, por sua vez, deriva de `IClassFactory2` e **CComObjectRootEx\< CComGlobalsThreadModel >**.

## <a name="declare_classfactory_auto_thread"></a><a name="declare_classfactory_auto_thread"></a>Declare_classfactory_auto_thread

Declara [cComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) como a fábrica da classe.

```
DECLARE_CLASSFACTORY_AUTO_THREAD()
```

### <a name="remarks"></a>Comentários

[CComCoClass](../../atl/reference/ccomcoclass-class.md) inclui a [DECLARE_CLASSFACTORY](#declare_classfactory) macro, que especifica [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. No entanto, ao incluir a DECLARE_CLASSFACTORY_AUTO_THREAD macro na definição de classe do seu objeto, você anula esse padrão.

Quando você cria objetos em vários apartamentos (em um servidor fora de proc), adicione DECLARE_CLASSFACTORY_AUTO_THREAD à sua classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#9](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_6.h)]

## <a name="ccomclassfactoryautothread-class"></a><a name="ccomclassfactoryautothread_class"></a>Classe CComClassFactoryAutoThread

Essa classe implementa a interface [IClassFactory](/windows/win32/api/unknwnbase/nn-unknwnbase-iclassfactory) e permite que objetos sejam criados em vários apartamentos.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

```
class CComClassFactoryAutoThread : public IClassFactory,
public CComObjectRootEx<CComGlobalsThreadModel>
```

### <a name="remarks"></a>Comentários

`CComClassFactoryAutoThread`é semelhante ao [CComClassFactory,](../../atl/reference/ccomclassfactory-class.md)mas permite que objetos sejam criados em vários apartamentos. Para aproveitar esse suporte, obtenha seu módulo EXE do [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).

Os objetos ATL normalmente adquirem uma fábrica de classe derivando do [CComCoClass](../../atl/reference/ccomcoclass-class.md). Esta classe inclui o [DECLARE_CLASSFACTORY](#declare_classfactory)de macro , que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. Para `CComClassFactoryAutoThread`usar, especifique a [DECLARE_CLASSFACTORY_AUTO_THREAD](#declare_classfactory_auto_thread) macro na definição de classe do objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#9](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_6.h)]

## <a name="declare_classfactory_singleton"></a><a name="declare_classfactory_singleton"></a>DECLARE_CLASSFACTORY_SINGLETON

Declara [ccomClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md) como a fábrica de classes.

```
DECLARE_CLASSFACTORY_SINGLETON( obj )
```

### <a name="parameters"></a>Parâmetros

*obj*<br/>
[em] O nome do seu objeto de classe.

### <a name="remarks"></a>Comentários

[CComCoClass](../../atl/reference/ccomcoclass-class.md) inclui a [DECLARE_CLASSFACTORY](#declare_classfactory) macro, que especifica [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. No entanto, ao incluir a DECLARE_CLASSFACTORY_SINGLETON macro na definição de classe do seu objeto, você anula esse padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#10](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_7.h)]

## <a name="ccomclassfactorysingleton-class"></a><a name="ccomclassfactorysingleton_class"></a>Classe CComClassFactorySingleton

Esta classe deriva do [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [o CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

```
template<class T>
class CComClassFactorySingleton : public CComClassFactory
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe.

`CComClassFactorySingleton`deriva do [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [o CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto. Cada chamada `CreateInstance` para o método simplesmente consulta este objeto para um ponteiro de interface.

### <a name="remarks"></a>Comentários

Os objetos ATL normalmente adquirem uma fábrica de classe derivando do [CComCoClass](../../atl/reference/ccomcoclass-class.md). Esta classe inclui o [DECLARE_CLASSFACTORY](#declare_classfactory)macro `CComClassFactory` , que declara como a fábrica de classe padrão. Para `CComClassFactorySingleton`usar, especifique a [DECLARE_CLASSFACTORY_SINGLETON](#declare_classfactory_singleton) macro na definição de classe do objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#10](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_7.h)]

## <a name="declare_get_controlling_unknown"></a><a name="declare_get_controlling_unknown"></a>DECLARE_GET_CONTROLLING_UNKNOWN

Declara uma função `GetControllingUnknown`virtual .

```
DECLARE_GET_CONTROLLING_UNKNOWN()
```

### <a name="remarks"></a>Comentários

Adicione essa macro ao seu objeto se você `GetControllingUnknown` receber a mensagem de `CComAggregateCreator`erro do compilador que está indefinida (por exemplo, em ).

## <a name="declare_not_aggregatable"></a><a name="declare_not_aggregatable"></a>DECLARE_NOT_AGGREGATABLE

Especifica que seu objeto não pode ser agregado.

```
DECLARE_NOT_AGGREGATABLE( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome do objeto de classe que você está definindo como não agregavel.

### <a name="remarks"></a>Comentários

DECLARE_NOT_AGGREGATABLE `CreateInstance` causa a devolução de um erro (CLASS_E_NOAGGREGATION) se for feita uma tentativa de agregar ao seu objeto.

Por padrão, [CComCoClass](../../atl/reference/ccomcoclass-class.md) contém a [DECLARE_AGGREGATABLE](#declare_aggregatable) macro, que especifica que seu objeto pode ser agregado. Para substituir esse comportamento padrão, inclua DECLARE_NOT_AGGREGATABLE na definição de classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#121](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_1.h)]

## <a name="declare_only_aggregatable"></a><a name="declare_only_aggregatable"></a>Declare_only_aggregatable

Especifica que seu objeto deve ser agregado.

```
DECLARE_ONLY_AGGREGATABLE( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome do objeto de classe que você está definindo como apenas agregador.

### <a name="remarks"></a>Comentários

DECLARE_ONLY_AGGREGATABLE causa um erro (E_FAIL) se `CoCreate` uma tentativa for feita ao seu objeto como objeto não agregado.

Por padrão, [CComCoClass](../../atl/reference/ccomcoclass-class.md) contém a [DECLARE_AGGREGATABLE](#declare_aggregatable) macro, que especifica que seu objeto pode ser agregado. Para substituir esse comportamento padrão, inclua DECLARE_ONLY_AGGREGATABLE na definição de classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#125](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_8.h)]

## <a name="declare_poly_aggregatable"></a><a name="declare_poly_aggregatable"></a>DECLARE_POLY_AGGREGATABLE

Especifica que uma instância de **CComPolyObject \< ** *x* **>** é criada quando seu objeto é criado.

```
DECLARE_POLY_AGGREGATABLE( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome do objeto de classe que você está definindo como agregavel ou não aggregável.

### <a name="remarks"></a>Comentários

Durante a criação, o valor do desconhecido externo é verificado. Se for NULO, `IUnknown` é implementado para um objeto não agregado. Se o desconhecido externo `IUnknown` não for NULO, é implementado para um objeto agregado.

A vantagem de usar DECLARE_POLY_AGGREGATABLE é `CComAggObject` `CComObject` que você evita ter ambos e em seu módulo para lidar com os casos agregados e não agregados. Um `CComPolyObject` único objeto lida com ambos os casos. Isso significa que apenas uma cópia do vtable e uma cópia das funções existem em seu módulo. Se o seu vtable for grande, isso pode diminuir substancialmente o tamanho do seu módulo. No entanto, se o `CComPolyObject` seu vtable for pequeno, o uso pode resultar em um tamanho de `CComAggObject` módulo `CComObject`ligeiramente maior, porque não é otimizado para um objeto agregado ou não agregado, como são e .

A DECLARE_POLY_AGGREGATABLE macro é automaticamente declarada em seu objeto se você usar o Assistente de Controle ATL para criar um controle total.

## <a name="declare_protect_final_construct"></a><a name="declare_protect_final_construct"></a>DECLARE_PROTECT_FINAL_CONSTRUCT

Protege o objeto de ser excluído se (durante [o FinalConstruct)](ccomobjectrootex-class.md#finalconstruct)o objeto agregado interno incrementar a contagem de referência e, em seguida, diminuir a contagem para 0.

```
DECLARE_PROTECT_FINAL_CONSTRUCT()
```

## <a name="declare_view_status"></a><a name="declare_view_status"></a>DECLARE_VIEW_STATUS

Coloque esta macro na classe de controle atl activeX para especificar os sinalizadores VIEWSTATUS para o contêiner.

```
DECLARE_VIEW_STATUS( statusFlags )
```

### <a name="parameters"></a>Parâmetros

*statusFlags*<br/>
[em] As bandeiras VIEWSTATUS. Consulte [VIEWSTATUS](/windows/win32/api/ocidl/ne-ocidl-viewstatus) para obter uma lista de bandeiras.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#126](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_9.h)]

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
